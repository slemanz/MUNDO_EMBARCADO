# Hardware Aplicado

Este conteúdo aborda métodos de design eletrônico aplicados a dispositivos do mundo real, focando na criação de sistemas confiáveis e funcionais. É direcionado a engenheiros e designers com conhecimentos em eletrônica e ciência, e explora desde a arquitetura do sistema até a resolução de problemas comuns em dispositivos modernos.

## Conteúdos

[1. Conceitos Essenciais](#1-conceitos-essenciais)

[2. Arquitetando o Hardware](#2-arquitetando-o-hardware)

[3. Comunicando](#3-comunicando)


## 1. Conceitos Essenciais

#### Introdução

Compreender os fundamentos da eletrônica é crucial para o desenvolvimento de hardware em sistemas embarcados. Componentes do mundo real frequentemente exibem comportamentos não ideais que podem impactar significativamente o design e o desempenho. Os projetistas precisam estar cientes dessas limitações para criar soluções robustas de forma eficaz.

#### Simplificações Ideais da Academia
A maioria dos sistemas eletrônicos hoje são digitais, mas desafios analógicos ainda prevalecem. Problemas comuns incluem ruído, problemas de integridade do sinal, instabilidade de energia, interferência eletromagnética (EMI) e impedância de conexão.

Modelos simplificados acadêmicos podem proporcionar um entendimento rápido, mas frequentemente omitem detalhes críticos. Essas omissões, podem impactar profundamente o desempenho do dispositivo. Uma compreensão abrangente desses modelos mais detalhados é necessária para melhorar a qualidade do design.

#### Interconexões
Até mesmo elementos aparentemente insignificantes, como um fio curto, podem ter impedância considerável. Por exemplo, a impedância do fio e sua capacitância podem atuar como um filtro passa-baixas (LPF) acima de 300–400 MHz e ser sensíveis ao movimento. Para placas de circuito impresso (PCBs), surgem problemas semelhantes, onde as trilhas também podem atuar como LPFs devido ao aumento da capacitância.

Um design eficaz deve levar em conta a impedância em cada conexão, considerando sua interação com o ambiente externo. Correntes altas, caminhos de conexão longos e altas frequências exigem um design cuidadoso de interconexões para evitar erros de fase e outras imperfeições.

#### Componentes Básicos

#### Capacitores
Capacitores modernos exibem compensações na capacitância por unidade de volume, tensão de ruptura, temperaturas de operação e mais. Capacitores de Classe 1 (e.g., C0G, NP0) priorizam mínima variação térmica e mudanças de polarização de tensão, enquanto capacitores de Classe 2 (e.g., X5R, X7R) alcançam maior capacitância com menos precisão e estabilidade.

Considerações chave incluem valor nominal, tolerância, tensão de ruptura, tamanho do pacote, tipo de dielétrico, características ESL, e confiabilidade.

#### Resistores
Resistores deveriam idealmente ter uma impedância plana ao longo da frequência, mas altas frequências podem introduzir problemas através da Capacitância Paralela Equivalente (EPC) e da Indutância Série Equivalente (ESL). A maioria dos resistores modernos são à base de filmes, oferecendo menor ruído em comparação aos resistores mais antigos à base de carbono.

Atributos significativos incluem composição do material, classificação de potência, faixa de temperatura, classificação de tensão, e estabilidade ao longo do tempo.

#### Indutores
Indutores são vitais na conversão de energia, processamento de sinal RF e limitação de EMI. Seu ESR afeta a eficiência energética e o desempenho em filtros. Parâmetros importantes incluem valor do componente, SRF, classificação de corrente, faixa de temperatura, e se o indutor é blindado ou não.

#### Fontes de Tensão e Baterias
Nenhuma fonte de tensão ideal existe. Fontes de tensão reais como baterias ou reguladores de tensão têm limitações como variações de capacidade e geração de ruído. Baterias degradam ao longo do tempo e seu desempenho varia com a temperatura e uso.

#### Fontes de Corrente
Fontes de corrente também enfrentam restrições práticas, tipicamente limitadas em faixa de tensão para manter o comportamento de corrente fixa.

#### Interruptores e Relés
Interruptores mecânicos e relés podem introduzir problemas como o bounce de contato, que requer debounce por software para detecção de estado estável em portas lógicas.

#### Amplificadores Operacionais
Um modelo ideal de amplificador operacional sugere ganho e largura de banda infinitos, mas amplificadores operacionais reais têm limitações como requisitos de fonte de alimentação, impedância de saída, limites de ganho, e sensibilidade ao ruído. Características específicas de desempenho dependem do amplificador operacional selecionado.

#### Comparadores de Tensão
Ao contrário dos amplificadores operacionais, comparadores operam fora dos loops de feedback e têm alto ganho sem compensação de frequência interna, tornando sua saída digital.

#### Dispositivos Digitais Não Ideais
Mesmo sistemas digitais não são imunes a comportamentos não ideais. Problemas como geração de estados falsos podem surgir devido a relacionamentos temporais e características analógicas de sinais digitais. Altas taxas de dados, resistência no caminho de transmissão, e carregamento capacitivo contribuem para a degradação do sinal.

A violação de limites de tensão ou temporização inadequada pode levar à falha do sistema. Comunicações de alta frequência frequentemente requerem sinais diferenciais para mitigar problemas de referência de terra.

#### Integridade do Sinal
Sistemas eletrônicos podem produzir ruído eletrônico indesejado, levando a emissões radiadas e crosstalk interno. Órgãos reguladores como a FCC impõem limites de EMI para prevenir interferência entre dispositivos.

O acoplamento de ruído dentro de um sistema, frequentemente chamado de crosstalk, pode ser capacitivo ou magnético e precisa ser gerenciado com cuidado.

#### Resumo e Conclusões
No desenvolvimento de hardware para sistemas embarcados, vários pontos críticos devem ser considerados:

- Modelos acadêmicos simplificam, mas podem omitir detalhes cruciais.
- Todas as conexões têm impedância, afetando a estabilidade e integridade da tensão.
- Erros de fase podem ocorrer mesmo com distribuição comum de sinais.
- Capacitores e resistores têm comportamentos complexos que influenciam o desempenho.
- Indutores, fontes de tensão e corrente, e interruptores têm suas próprias características não ideais.
- Amplificadores operacionais e comparadores têm limitações que influenciam a escolha de design.
- Dispositivos e sistemas digitais devem gerenciar comportamentos não ideais e problemas de integridade do sinal.
- Integridade do sinal é fundamental para prevenir ruído e interferência dentro e entre sistemas.

Compreender essas complexidades ajuda a construir consciência e melhorar estratégias de design, visando mitigar falhas e otimizar o desempenho no desenvolvimento de sistemas embarcados. Enquanto aprender pela experiência é inestimável, abordar proativamente essas questões pode economizar tempo e esforço significativos a longo prazo.

## 2. Arquitetando o Hardware

Quando se trata de desenvolver hardware para sistemas embarcados, é crucial definir as partes principais do sistema no nível da caixa e discutir a implementação do controle digital no núcleo. Também é importante entender os critérios para a seleção de uma unidade de controle digital (DCU) e escolher o microcontrolador (MCU) adequado.

Para garantir uma abordagem bem-sucedida ao desenvolver um produto comercial, algumas ideias preliminares precisam ser esclarecidas.

#### Simular ou Construir

Criar uma simulação completa de um sistema de controle embarcado geralmente não é necessário. O código do controlador digital pode ser simulado dentro do ambiente de design integrado (IDE) para garantir que os sinais de controle funcionem corretamente. No entanto, simular funções periféricas criadas por esses sinais de controle muitas vezes não é necessário. Construir uma PCB de primeira geração é uma maneira de baixo custo e eficiente para depurar rapidamente um produto real. Simular o dispositivo é desnecessário na maioria dos casos. Para MCUs com periféricos simples, uma placa de desenvolvimento/demo também pode ser uma opção viável.

#### Componentes de Montagem PTH (Obsoletos)

Componentes de circuito com pinos ou fios que atravessam buracos na PCB, conhecidos como componentes de montagem PTH, são adequados para montagem manual e projetos hobbyistas. No entanto, esses componentes não são adequados para montagem automatizada ou circuitos de alta frequência. Componentes com pinos geralmente são maiores em comparação com seus equivalentes de montagem em superfície.

#### Lógica Discreta de Portas (Obsoleta)

A série de lógica 7400, desenvolvida na metade dos anos 1960 e ainda em produção hoje, consiste em circuitos integrados com quatro a seis portas lógicas por chip. No entanto, este capítulo foca em métodos modernos que utilizam dispositivos programados e funções lógicas orientadas por código. Dispositivos digitais singulares devem ser vistos como conversores de nível e drivers de buffer.

#### Estratégias Modernas de Design

As estratégias modernas de design visam minimizar o uso de circuitos analógicos sempre que possível. Implementar filtros analógicos passa-faixa, por exemplo, pode apresentar vários problemas, como a necessidade de capacitores de alta qualidade com características precisas e lineares. Amplificadores operacionais (op-amps) não ideais também contribuem com ruído, distorção e offset de sinal DC. Uma solução de baixo custo e repetível envolve usar um conversor analógico-digital (ADC) seguido por um filtro definido por processador de sinal digital (DSP).

Converter sinais analógicos para formato digital oferece benefícios como mitigação de ruído, distorção e preocupações com a integridade do sinal. Fluxos de dados digitais são menos suscetíveis a ruídos ambientais e podem ser facilmente transmitidos por longas distâncias, mesmo em ambientes com interferência eletromagnética (EMI).

Os sistemas de controle também se beneficiam de métodos digitais, uma vez que sistemas modernos de feedback de controle combinam características analógicas com processamento digital. Esses sistemas utilizam processadores de sinal digital (DSP) para alcançar controle óptimo.

#### Design Predominantemente Digital

O conceito de um sistema predominantemente digital envolve converter qualquer sinal analógico em um fluxo de dados digital-equivalente, processar os dados usando métodos digitais e converter de volta para formato analógico somente se necessário. Esta abordagem, muitas vezes referida como abordagem de sinal misto, permite criar várias relações matemáticas e de entrada/saída dentro de um sistema de processamento de sinal digital (DSP).

#### Métodos DSP: Versatilidade e Limites

Melhorar o desempenho de sinal-ruído em DSP requer utilizar conversores analógico-digital (ADCs) com maior resolução, o que permite uma amostragem de sinal mais precisa. No entanto, o design do ADC possui certas limitações, como a compensação entre taxa de conversão, consumo de energia e número de bits. Conseguir um conversor rápido com uma grande contagem de bits e baixo consumo de energia pode ser desafiador.

#### Métodos de Controle Digital: DCU, MCU, MPU, FPGA, CPLD e ASIC

Um sistema embarcado ou sistema de controle embarcado é um sistema eletrônico ou eletromecânico que utiliza um controlador digital para controlar e sentir vários componentes. A unidade de controle digital (DCU) pode assumir a forma de um microcontrolador (MCU) ou unidade de microprocessador (MPU). Além disso, outros métodos digitais especializados, como matrizes de portas programáveis em campo (FPGA), dispositivos lógicos programáveis complexos (CPLD) ou circuitos integrados específicos de aplicação digital (ASIC), podem ser empregados para requisitos de controle específicos.

O controle digital pode ser implementado usando soluções baseadas em hardware, como uma máquina de estados booleanos, ou soluções baseadas em software na forma de código escrito para um computador. O código escrito para um MCU e baixado nele é comumente referido como firmware.

Ao contrário dos computadores multifuncionais, os sistemas embarcados são construídos para um propósito específico e geralmente têm uma programação fixa. No entanto, eles frequentemente requerem capacidades de monitoramento. Por exemplo, uma PCB de controlador de driver de motor pode utilizar um MCU para controlar três motores de passo enquanto também incorpora um sensor para monitorar a velocidade do motor. A comunicação com um gerente remoto pode ser alcançada através de um barramento de porta serial.

#### Terminologia em Especificações de MCU e MPU

Entender a terminologia usada nas especificações de unidades de microcontrolador (MCU) e unidades de microprocessador (MPU) é essencial para selecionar o dispositivo certo:

- **Arquitetura Harvard:** Uma CPU de arquitetura Harvard usa barramentos de endereços de dados separados para memória de instruções e memória de dados. A maioria dos dispositivos MCU utiliza a arquitetura Harvard.

- **Arquitetura Princeton (Arquitetura Von Neumann):** Uma CPU de arquitetura Princeton usa barramentos de endereços de dados comuns para memória de instruções e memória de dados.

- **RISC (Computador com Conjunto de Instruções Reduzido):** CPUs RISC têm um conjunto de instruções limitado, reduzindo a complexidade do design físico. Instruções e dados resultantes são frequentemente encadeados em dispositivos RISC. A maioria dos dispositivos MCU são dispositivos RISC.

- **CISC (Computador com Conjunto de Instruções Complexas):** Um processador CISC executa instruções mais complexas do que um dispositivo RISC. O compilador de um dispositivo RISC divide instruções complexas em mais simples, adequadas para o conjunto de instruções RISC. A maioria dos processadores atuais usa arquitetura RISC, exceto pelos dispositivos X86 da Intel.

- **Processador X86:** A arquitetura X86 inclui os processadores 8086, 80186, 80286, 80386, 80486 e outros da Intel. Geralmente, dispositivos X86 não são usados em MCUs dentro de sistemas embarcados.

- **ARM (Advanced RISC Machine ou Acorn RISC Machine):** ARM é uma série de processadores RISC com dados de 32 bits e endereçamento de 26 ou 32 bits. A ARM Holdings licencia processadores ARM como propriedade intelectual para fabricantes de semicondutores que adicionam dispositivos de suporte periférico para criar MCUs acabados.

- **MIPS (Microprocessador sem Estágios de Pipeline Interlocked):** Um processador MIPS é um processador RISC que usa uma arquitetura pipeline. Dispositivos MIPS são excelentes no processamento de dados em fluxos e são disponíveis por múltiplos fornecedores como MPUs standalone ou integrados por fabricantes de semicondutores em seus chips.

- **PIC, AVR e ATmega:** Estas são diferentes famílias de microcontroladores que começaram como processadores RISC de arquitetura Harvard de 8 bits, mas expandiram suas linhas de produtos para incluir dispositivos de desempenho superior.

#### Controladores de Hardware

Controladores baseados em hardware incluem lógica de array programável (PAL), dispositivo lógico programável (PLD), dispositivo lógico programável complexo (CPLD), matriz de portas programáveis em campo (FPGA) e circuitos integrados específicos de aplicação digital (ASIC).

PAL e PLD são arrays lógicos programáveis, onde dispositivos PAL têm menos pinos (geralmente 28 ou menos) e são compatíveis com interfaces de 5V, muitas vezes usados com montagem PTH. Dispositivos PLD são variantes menores de CPLDs.

CPLDs são dispositivos lógicos programáveis que variam em tamanho de 20 portas de entrada/saída a mais de 200. Eles utilizam uma interconexão programável em um campo de portas ou macrocélulas.

FPGAs são altamente versáteis e podem variar em tamanho de 10 portas de entrada/saída a mais de 1.900. Eles utilizam tabelas de consulta programáveis para criar lógica dedicada, complexa e de grande array.

ASICs digitais não podem ser programados e requerem um design digital funcional para ser desenvolvido usando outra plataforma antes da fabricação. Eles são adequados para produtos de alto volume que requerem lógica rápida.

Controladores baseados em hardware são adequados para cenários onde lógica dedicada rápida é necessária. No entanto, controladores baseados em software, como MCUs e MPUs, são comumente empregados, pois oferecem uma maior variedade de recursos e flexibilidade.

#### Controladores de Software

Controladores baseados em software ou firmware dependem de dispositivos como microcontroladores (MCUs) e unidades de microprocessador (MPUs). A diferenciação entre MCUs e MPUs pode ser confusa, com MCUs geralmente possuindo mais recursos para torná-los autossuficientes, embora possa haver uma significativa sobreposição de recursos entre os dois.

MPUs tendem a ter memória de acesso aleatório (RAM) e memória somente leitura (ROM) externas, enfatizando sua capacidade de interface com memória e periféricos externos. Por outro lado, MCUs incluem todos os recursos necessários para funcionar com suporte externo mínimo. Eles tipicamente têm RAM e ROM internas, interfaces de comunicação serial (UART, SPI, I2C e CAN), bem como capacidades de conversão analógica-digital (ADC) e conversão digital-analógica (DAC).

Controladores baseados em software fornecem maior flexibilidade e podem ser programados para se adaptarem a várias aplicações.

#### Computadores Versus Controladores

Computadores de placa única são projetados para interagir com periféricos típicos de computadores, enquanto placas de MCU são otimizadas para interagir com outros circuitos integrados (ICs) e fornecer estímulo/resposta através de portas individuais. Placas de MCU são construídas para tarefas específicas de controle necessárias.

#### Opções de Arquitetura de Sistema

MCUs e MPUs são incrivelmente versáteis e encontram aplicações em vários cenários. Pode haver sistemas embarcados onde a presença de um MCU não é imediatamente evidente, pois eles controlam e monitoram funções específicas dentro de um dispositivo.

Ao projetar um sistema, é importante determinar todos os periféricos que precisam ser controlados ou detectados. Isso requer uma consideração cuidadosa de todas as interconexões necessárias.

Portas de comunicação serial (SerCom) devem ser configuradas cuidadosamente para evitar gargalos. Por exemplo, uma única interface I2C pode ter vários dispositivos conectados, mas o tráfego geral através da porta deve ser analisado para evitar congestionamento.

Capacidades de acesso direto à memória (DMA) podem aprimorar significativamente a transferência de dados entre blocos de memória ou entre a memória e uma porta externa. Os designers devem considerar os benefícios potenciais ao mover grandes blocos de dados.

Para implementar processamento de sinal digital (DSP), os designers podem escolher entre soluções baseadas em hardware ou software. A escolha depende de fatores como a taxa de amostragem, taxa de clock da DCU e complexidade do algoritmo DSP. Além disso, é importante identificar quaisquer possíveis gargalos de DSP, considerando cenários extremos envolvendo taxas de dados baixas e altas.

Para determinar os recursos internos necessários da DCU, é necessário considerar os requisitos da aplicação específica. Isso pode incluir portas de entrada/saída de propósito geral (GPIO), várias interfaces de comunicação serial, capacidades internas de ADC e DAC, comparadores, relógios em tempo real (RTCs), sistemas de geração de clock, consumo de energia, memória programável (memória flash), tamanho da RAM, capacidade de manipulação de interrupções, capacidade de matemática com ponto flutuante, reset de alimentação e detecção de reset por subvoltagem, capacidade de acesso direto à memória (DMA), temporizadores watchdog (WDT) e circuitos de contador de temporizador (TCC).

#### Considerações sobre o Pacote Físico

Existem várias opções de pacote disponíveis para DCUs, variando desde pacotes tradicionais maiores até formas menores. Os designers precisam considerar as limitações físicas e os requisitos de suas aplicações específicas ao selecionar um pacote apropriado.

#### Escolhendo uma Configuração de DCU e MCU/MPU

Para tomar uma decisão informada ao selecionar uma DCU, os designers devem considerar funções ou recursos nicho especializados, se estão desenvolvendo sistemas multi-MCU ou sistemas de uso geral de MCU. É recomendado escolher um fabricante primeiro e depois selecionar um MCU ou MPU específico dentro da linha de produtos preferida. Facilidade de uso e uma infraestrutura de suporte robusta são frequentemente mais importantes do que selecionar um dispositivo específico. É também aconselhável considerar futuras mudanças de design e recursos desejados do produto, que podem exigir capacidades extras, como portas adicionais, memória e poder de processamento. Optar por um MCU ou MPU com alguma capacidade excedente pode ser uma estratégia sábia para uma construção de primeira geração.

Em resumo, desenvolver hardware para sistemas embarcados envolve adotar estratégias modernas de design, escolher entre controladores de hardware e software, entender a terminologia relevante, considerar opções de arquitetura de sistema e selecionar cuidadosamente as configurações de DCU e dispositivos MCU/MPU. Seguindo essas diretrizes, os designers podem criar sistemas embarcados robustos e eficientes.

## 3. Comunicando

A comunicação digital é a espinha dorsal de qualquer sistema. Transferências de dados de baixa frequência e curta distância através de uma placa de circuito impresso (PCB) são geralmente simples. No entanto, quando os dados se movem fora da placa, percorrem longas distâncias ou enfrentam interferências eletromagnéticas (EMI), surgem desafios. Para assegurar a confiabilidade dos dados em altas velocidades, é necessário um enfoque especial aos métodos de sinalização, linhas de transmissão, manejo de erros e sincronização de clock/dados. Vários sistemas funcionam bem no laboratório, mas falham no campo devido a desafios ambientais. Sistemas bem projetados devem sobreviver a EMI do mundo real, descargas eletrostáticas (ESD), variação de potência e terrenos ruidosos.

Atualmente, comunicação digital em PCBs se divide em duas categorias principais: controle de configuração e setup de chips a baixa taxa de dados, ou pipelines de dados de alta velocidade entre dispositivos.

#### Sinais Digitais, Considerações Físicas e Conexões

Antes de analisar interfaces de dados adequadas, é necessária uma compreensão de como as conexões são feitas, quais tipos de sinais utilizar, quando usar linhas de transmissão terminadas e métodos de distribuição de clock.

##### Limitações dos Sinais Digitais Referenciados ao Terreno

Os dados digitais estão sujeitos a problemas de integridade do sinal. Ruído, perda de amplitude, reflexões em linhas de transmissão, incompatibilidade de impedância e outros problemas contribuem para isso. Estes problemas tendem a aumentar à medida que as conexões se alongam ou as taxas de dados aumentam.

Um sinal digital pode ser corrompido por ruído na potência e no terreno, tanto no lado de transmissão quanto de recepção de uma conexão de dados. Além disso, as limitações de largura de banda da conexão farão com que as partes de alta frequência do sinal sejam degradadas em amplitude e distorcidas em fase. Sinais adjacentes de proximidade próxima contribuem com ruído de diafonia por métodos capacitivos e eletromagnéticos. Adicionalmente, as bordas de subida/descida dos sinais digitais tornam a incompatibilidade de impedância de uma conexão muito visível. Uma conexão com transientes de sinal rápidos e sem linha de transmissão terminada adequadamente cria reflexões no sinal que o corrompem ainda mais.

##### Sinalização Diferencial de Baixa Tensão

Drivers digitais podem ser referenciados ao terreno ou usar sinais diferenciais. Frequentemente, os sinais diferenciais utilizam tensões mais baixas do que a lógica referenciada ao terreno, dando origem à nomenclatura Sinalização Diferencial de Baixa Tensão (LVDS). Um padrão (TIA/EIA-644) adotou o nome LVDS; no entanto, este texto refere-se a toda sinalização diferencial que utiliza sinais não-réus-à-terra como LVDS.

Os sinais LVDS podem ser conectados por meio de uma linha de stripline diferencial (PCB) ou um conjunto de fios trançados (cabo). Sinais são iguais e opostos em polaridade. A recepção do LVDS como a diferença entre os dois sinais oferece várias vantagens, motivo pelo qual a sinalização diferencial e métodos LVDS foram amplamente adotados tanto para conexões digitais de alta velocidade quanto para longas distâncias. Ethernet, USB, PCI Express e barramento CAN, entre outros, utilizam métodos LVDS.

##### Organizando Interconexões para Velocidade e Integridade do Sinal

Com taxas de dados lentas (<10 MB/seg), tempos de subida/descida suaves (>3 ns) e conexões curtas (<25 cm), a transferência de dados digitais através de uma PCB geralmente não é um problema. Redes lentas, suaves e curtas (SSSN) são fáceis de lidar e representam uma grande parte das conexões digitais em uso. Uma abordagem mais cuidadosa para taxas de dados mais rápidas será delineada em breve. Antes disso, o que constitui uma boa conexão de rede precisa ser examinado.

Qualquer conexão elétrica sem impedância controlada e com múltiplas conexões em múltiplas localizações não é amigável para sinais de alta largura de banda. Conexões desorganizadas podem ser vistas como uma rede mista de elementos RLC e linhas de transmissão não terminadas sem impedância consistente. Sinais de alta frequência exibem rapidamente problemas nessas conexões.

Idealmente, a transmissão ponto a ponto é o método preferido.

Uma conexão digital pode ser tratada como uma rede aglomerada ou distribuída. Redes distribuídas precisam de linhas de transmissão e terminações. A seguir, decidiremos qual abordagem usar.

##### Redes Aglomeradas Versus Redes Distribuídas

Leva tempo para que um sinal viaje por um fio ou uma PCB. Em uma rede aglomerada, todos os componentes conectados veem o sinal aplicado praticamente ao mesmo tempo. Em uma rede distribuída, retardos de transmissão causam sinais aplicados a ocorrerem em tempos significativamente diferentes nos dispositivos conectados.

##### Distribuição de Clock

Distribuição de clock de baixa frequência (<1 MHz) deve ser simples. À medida que a frequência aumenta, a distância de conexão aumenta e, adicionando mais destinos, a integridade do sinal, os tremeores de tempo e as distorções temporais entre destinos precisam ser analisados. Uma comparação de dois casos com frequências comuns de clock ilustra os problemas.

Um relógio em tempo real (RTC) funciona a 32.768 KHz. Essa frequência é adequada para a fabricação de cristal e é facilmente dividida para criar um clock de 1 segundo. Utilizar um RTC é uma estratégia comum para muitos sistemas de controle. O período do RTC é de 30,5 us.

A interface padrão PCIe usa um clock de 100 MHz que é distribuído como parte do barramento PCIe. O período do clock PCIe é de 10 ns.

Muitos dispositivos lógicos exibem metastabilidade ao inserir bordas de transição lenta. Portanto, especificações de dispositivos para as bordas de transição mais lentas, ou o uso de dispositivos com histerese, precisam ser investigados. Tempos de subida mais lentos funcionam, mas até certo ponto.

Carregamentos capacitivos excessivos podem degradar sinais. Fornecedores de lógica usam o conceito de saída de driver de ventilador e carga padrão de dispositivo de entrada para simplificar o problema para os projetistas. Para dispositivos CMOS, cargas padrão são um método simples de adicionar a capacitância conectada a um sinal.

#### Comunicação Digital: Portas Paralelas Versus Seriais

Os dados podem ser transferidos entre dispositivos de maneira paralela ou serial. A comunicação paralela requer múltiplos pinos e conexões entre dispositivos. Grande quantidade de área dentro de ambos os ICs é utilizada para fornecer os sinais externos. Devido ao custo do silício e à complexidade das interconexões, as portas paralelas são predominantemente obsoletas.

#### Métodos de Clock para Portas Seriais

Além de transferir dados, algum método de sincronização de clock deve ser usado. Quatro métodos são comumente utilizados: sincronização de borda inicial, clock de caminho paralelo, dados autossincronizados e clock embutido.

##### Sincronização de Borda Inicial

Sincronização de borda inicial requer que o transmissor (TX) e o receptor (RX) tenham uma taxa de dados pré-definida e acesso a um clock de referência. Nesse exemplo, quando o TX cai, o RX reconhece isso como a borda inicial do sinal e usa seu clock de referência para amostrar o meio esperado da janela de dados para uma série curta de bits de dados. Os erros de fase do clock pioram progressivamente após a sincronização, tornando este método adequado apenas para campos de dados lentos e curtos. Esse método é propenso a erros e originalmente utilizado em dispositivos RS-232 e UART, não sendo recomendado para novos projetos.

##### Clock Paralelo

Um clock paralelo é sincronizado no tempo com os dados. A sincronização do clock com os dados precisa estar adequadamente faseada para tempos de set e hold suficientes. As limitações dos sistemas de clock paralelo necessitam de uma segunda conexão e da necessidade de manter uma boa relação de fase entre clock e dados. Sistemas de dados em alta velocidade podem ter problemas em manter essa relação, preferindo métodos de clock embutido.

##### Código Manchester Autossincronizável

Um fluxo de dados autossincronizável é comumente criado com um código Manchester. Dados de retorno a zero (NRZ) são transformados de forma que os dados sejam representados como bordas de subida ou descida. Na versão de borda positiva do código Manchester, um binário 1 torna-se uma borda de subida e um binário 0 uma borda de descida. Esse conjunto de transições pode ser decodificado e sincronizado no receptor sem um clock de referência.

##### Clock Embutido e Códigos Limitados por Comprimento de Run

Sistemas de clock embutido criam um clock baseado no fluxo de dados. Isso é chamado de recuperação de clock e é realizado usando um PLL. O PLL gera um clock alinhado com as bordas transientes dos dados de entrada. Os dados recebidos precisam de bordas transientes frequentes para manter o PLL devidamente alinhado. Isso pode ser um problema com dados NRZ, que podem ter sequências longas do mesmo estado e carecem de bordas transientes para alinhamento de tempo.

Para evitar sequências longas de uns ou zeros, os dados de transmissão NRZ são convertidos para dados limitados por comprimento de run (RLL), que garantem um limite min/max entre bordas transientes, permitindo uma criação de clock alinhada em fase.

A maioria dos sistemas de comunicação de dados em alta velocidade utiliza métodos de clock embutido, mas todos esses métodos de clock são comumente utilizados com diferentes interfaces seriais.

#### Comunicação Digital: Recursos e Definições

Alguns critérios e terminologias comumente usados incluem:

- **Taxa de dados:** 
   Refere-se à quantidade de dados que podem ser transferidos por uma conexão por unidade de tempo, podendo ser medida em bits por segundo, bytes por segundo, baud ou símbolos por segundo. As taxas de dados especificadas pelo fornecedor podem não incluir o tempo suplementar usado para protocolos de comunicação de suporte ou outros processos de overhead.

- **Distância:** 
   Qualquer método de comunicação possui limitações de distância; frequentemente, as taxas de dados precisam diminuir conforme a distância aumenta.

- **Endereçamento:** 
   O propósito de incluir um endereço é definir o destino final dos dados. O número de dispositivos permitidos em uma conexão é limitado pelo endereçamento digital, carregamento capacitivo ou outras especificidades do sistema.

- **Integridade dos dados:** 
   Erros de dados entre dois chips eletronicamente próximos na mesma PCB geralmente não são um problema, mas à medida que a distância aumenta, as taxas de dados aumentam ou o ruído é introduzido, as taxas de erro aumentam e a integridade precisa ser verificada.

- **Protocolo ou estrutura de protocolo:** 
   É o procedimento pré-definido que os dispositivos utilizam para se comunicar. As características do protocolo podem variar bastante dependendo da aplicação. Recursos comuns incluem a definição da sequência e tamanho dos dados, métodos de codificação, métodos de verificação de erros, procedimentos de reconhecimento e handshaking, estrutura de endereçamento, pedidos de início/parada/repetição, entre outros.

- **Pacote de dados:**
   É o bloco de informações digitais que está sendo comunicado, conforme definido pelo protocolo.

- **Preâmbulo:** 
   Usado para preparar o caminho das comunicações para o que está por vir. Os receptores utilizam o preâmbulo para fazer ajustes de processamento de sinal e sincronizar um PLL de recuperação de clock com os dados de entrada.

- **Dados de carga:** 
   Também conhecidos como dados ou campo de dados, contêm as informações reais que estão sendo transmitidas. Dependendo do protocolo, isso pode ter tamanho fixo ou variável.

- **Sistemas simplex:** 
   Comunicam-se em apenas uma direção. Carregar dados em um registrador é um exemplo de um processo simplex se não houver como verificar ou ler de volta os dados.

- **Sistemas half-duplex:** 
   Podem se comunicar em ambas as direções, mas não ao mesmo tempo. O entrelaçamento temporal é uma estratégia comum para implementar um sistema half-duplex.

- **Sistemas duplex ou full-duplex:** 
   Podem se comunicar em ambas as direções ao mesmo tempo. Dependendo do dispositivo, a comunicação bidirecional pode ocorrer no mesmo caminho/canal/fios, ou um segundo caminho pode ser utilizado para a comunicação na outra direção. Dois sistemas simplex podem ser usados juntos para criar um sistema duplex.

#### Dados Seriais: Terreno Compartilhado, Baixa Velocidade

Embora a lógica referenciada ao terreno possa ter problemas de integridade do sinal, é a espinha dorsal da maioria dos sistemas digitais. Um terreno comum de baixa impedância é essencial para tais sistemas funcionarem de maneira confiável. Algumas interfaces digitais não oferecem detecção ou correção de erros, portanto, precisam operar em um ambiente de terreno compartilhado com alta integridade dos dados.

##### Universal Asynchronous Receiver Transmitter (UART)

A estrutura UART usa sincronização de borda inicial e é uma variante simplificada da interface RS-232. O UART tem uma conexão receptor-para-transmissor bidirecional e nada mais. A temporização dos dispositivos é realizada internamente utilizando duas referências de tempo independentes, onde o período de clock (taxa de baud) foi programado em ambos os dispositivos.

A transferência de dados é iniciada pela borda descendente de qualquer saída TX. Esta borda descendente (START) fornece uma referência de fase zero para sincronização do receptor. Conhecendo a taxa de baud dos dados esperados, o clock interno do receptor pode temporizar a amostragem dos dados no meio esperado de cada bit por 9 bits. Um bit de paridade (PB) é adicionado ao final dos dados para determinar se ocorreu um número ímpar de erros. Um número par de erros não seria detectado. O UART é simples, mas de desempenho limitado.

| Parâmetro   | Desempenho |
| ----------- | ----------- |
| Conexão     | Ponto a ponto, full duplex |
| Taxa de dados | 1 Mbit/s máx., único ao dispositivo |
| Endereçamento | Nenhum |
| Validação   | Sem reconhecimento ou verificação de erro de paridade |
| Meio        | Fiação, duas conexões |
| Sinalização | Referenciado ao terreno, drivers push/pull ativos |
| Distância   | Na PCB, precisa de terreno comum |
| Outros      | Obsoleto, sem padrão; muitas variantes existem |

##### Inter-Integrated Circuit (I2C) e System Management Bus (SMBus)

A estrutura do barramento I2C foi definida pela Philips Semiconductor por volta de 1982. I2C é um método simples e de baixa velocidade de comunicação entre chips em uma PCB comum. Muitos fornecedores de semicondutores fornecem uma interface I2C para seus produtos de configuração e controle de registradores internos.

I2C consiste em dois sinais: um clock (SCL) e dados seriais (SDA). Vários dispositivos podem ser conectados aos sinais SDA/SCL, e um par de resistores pull-up (Rpu) também está conectado. Os pinos de conexão (SDA, SCL) de qualquer chip conectado podem puxar o sinal para baixo, enquanto os resistores fornecem um pull-up passivo. Qualquer dispositivo pode iniciar a comunicação e se torna o gerente, que controla a comunicação com dispositivos subordinados.

Um dispositivo gerente inicia uma transferência baixando o SDA e depois baixa o clock serial (SCL). Em seguida, um endereço, bit de leitura/escrita e campo de dados são enviados. Reconhecimento (AK) é uma resposta do dispositivo subordinado.

O clock é especificado para fazer um ciclo completo de subida e descida no meio de cada bit enviado. Com 7 bits de endereçamento, o sistema é limitado a 128 locais, mas uma variante mais moderna permite 10 bits de endereçamento.

O desempenho do I2C é limitado por sua taxa de transferência de dados. Além disso, sem verificação de erros, o dispositivo é limitado a situações onde a integridade do sinal é essencial. Consequentemente, o I2C é limitado a comunicação local onde todos os chips utilizam o mesmo terreno de baixa impedância, como em uma PCB.

| Parâmetro   | Desempenho |
| ----------- | ----------- |
| Conexão     | Multidrop, half duplex; múltiplos gerentes, múltiplos subordinados |
| Taxa de dados | 100 Kbit/s padrão, 400 Kbit/s rápido, 3.4 Mbit/s alta velocidade |
| Endereçamento | 7 bits, 128 locais, leitura/escrita |
| Validação   | Acknowledge recebido, sem verificação de erro |
| Meio        | Fiação, duas conexões |
| Sinalização | Referenciado ao terreno, pull-down ativo, resistor pull-up |
| Distância   | Na PCB, precisa de terreno comum |
| Outros      | Endereçamento de 10 bits opcional |

Esse método preenche uma necessidade importante de comunicação facilmente implementada e goza de uso generalizado, com muitos chips utilizando interfaces I2C.

##### Serial Peripheral Interface (SPI)

O barramento SPI foi definido pela Motorola por volta de 1985. Uma estrutura básica de um único gerente com capacidade de selecionar subordinados individuais para comunicação full-duplex é a estrutura básica. Muitos fornecedores adotaram a interface com algumas variantes para suas necessidades.

O SPI é serial data com velocidades mais altas do que um sistema de pull-up passivo de resistores pode fornecer. Com um pino de seleção de subordinado dedicado, não há informação de endereço no pacote de dados. Muitos fornecedores usam a interface SPI para streaming de dados.

Os sinais SPI incluem um clock (SCLK) e dois caminhos de dados: MOSI (Gerente para Subordinado) e MISO (Gerente para Subordinado). Um dispositivo gerente requer múltiplas linhas de controle para selecionar entre múltiplos subordinados, e dispositivos subordinados requerem uma linha de habilitação conhecida como seleção de subordinado (SS). A menos que um subordinado tenha sido habilitado pelo gerente, o subordinado mantém a linha MISO compartilhada em estado de alta impedância.

Com drivers de switch ativo up/down, dispositivos SPI podem atingir taxas de dados mais altas do que as técnicas de pull-up de resistores, como o I2C. No entanto, sem verificação de erros, o método é limitado a conexões curtas em um terreno comum.

| Parâmetro   | Desempenho |
| ----------- | ----------- |
| Conexão     | Único gerente, múltiplos subordinados, full duplex |
| Taxa de dados | 10 Mbit/s é comum e único ao dispositivo |
| Endereçamento | Nenhum; pino SS ativa o dispositivo |
| Validação   | Sem reconhecimento, sem verificação de erro |
| Meio        | Fiação, quatro conexões |
| Sinalização | Referenciado ao terreno, drivers push/pull ativos |
| Distância   | Na PCB, precisa de terreno comum |
| Outros      | Sem padrão

## 4.
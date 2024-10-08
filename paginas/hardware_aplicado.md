# Hardware Aplicado

Este conteúdo aborda métodos de design eletrônico aplicados a dispositivos do mundo real, focando na criação de sistemas confiáveis e funcionais. É direcionado a engenheiros e designers com conhecimentos em eletrônica e ciência, e explora desde a arquitetura do sistema até a resolução de problemas comuns em dispositivos modernos.

## Conteúdos

[1. Conceitos Essenciais](#1-conceitos-essenciais)

[2. Arquitetando o Hardware](#2-arquitetando-o-hardware)

[3. Comunicando](#3-comunicando)

[4. Sistemas de Energia](#4-sistemas-de-energia)

[5. Energia da Bateria](#5-energia-da-bateria)

[6. EMI e ESD](#6-emi-e-esd)

[7. ADCs e DACs](#7-adcs-e-dacs)

[8. Periféricos](#8-periféricos)


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

A comunicação digital é fundamental em sistemas embarcados, garantindo a transferência perfeita de dados entre vários componentes. Este guia explora aspectos técnicos essenciais e metodologias para estabelecer uma comunicação confiável e eficiente em sistemas embarcados.

#### Sinais digitais referenciados ao terra e suas limitações

Sinais digitais, ao serem referenciados a um terra comum, enfrentam vários desafios. Fatores como ruído, perda de amplitude e desajustes de impedância podem degradar significativamente a integridade do sinal, especialmente à medida que as conexões se alongam ou as taxas de dados aumentam.

#### Sinalização diferencial: Uma solução para os desafios referenciados ao terra

O uso de sinalização diferencial de baixa tensão (LVDS) pode mitigar muitos problemas enfrentados pelos sinais referenciados ao terra. O LVDS, com sua natureza diferencial, oferece resistência contra ruído e melhor integridade em longas distâncias e altas velocidades. Esse método é amplamente adotado em protocolos de comunicação como Ethernet, USB e PCI Express.

#### Organizando as interconexões para um desempenho ótimo

Para transferência de dados em baixa velocidade (<10 MB/s) em curtas distâncias (<25 cm), a organização das conexões com cuidado é essencial, mas geralmente é direta. Fatores-chave incluem garantir a impedância consistente e evitar linhas de transmissão não terminadas.

#### Distribuição de clock

A distribuição de clock se torna mais complexa com frequências mais altas. Garantir jitter e skew mínimos é crucial, especialmente para sistemas de dados em alta velocidade que operam, por exemplo, com uma interface PCIe a 100 MHz. Métodos adequados de distribuição de clock e especificações de dispositivos para transições de borda são necessários para manter a integridade do sinal.

#### Comunicação paralela versus comunicação serial

A comunicação paralela, antes prevalente, foi em grande parte substituída pela comunicação serial devido ao alto número de pinos e à complexidade. A comunicação serial, que requer menos conexões, é mais eficiente e econômica, especialmente em transferências de dados em alta velocidade.

#### Métodos de clock para portas seriais

Para manter a sincronização entre o transmissor (TX) e o receptor (RX), vários métodos de clock são utilizados:

1. **Sincronização pela Borda Inicial:** Adequado para campos lentos e curtos.
2. **Clock Paralelo:** Requer conexões adicionais e manutenção da relação de fase entre o clock e os dados.
3. **Manchester Code Auto-sincronizado:** Usa codificação de transição, útil para manter o sincronismo sem um clock de referência.
4. **Clock Embutido:** Utiliza PLL para recuperação de clock a partir de fluxos de dados, frequentemente utilizado em sistemas de alta velocidade.

Compreendendo os principais termos na comunicação digital

- **Taxa de Dados:** A quantidade de dados transmitidos por unidade de tempo, geralmente medida em bits ou bytes por segundo.
- **Endereçamento:** Define o destino dos dados, sendo crucial em sistemas com vários dispositivos.
- **Integridade dos Dados:** Garante a transmissão de dados sem erros, especialmente à medida que as distâncias e as taxas de dados aumentam.
- **Protocolo:** Regula o formato e a transmissão dos dados, incluindo métodos de verificação de erros, confirmações e sincronização.
- **Simplex, Half-Duplex e Full-Duplex:** Define a direcionalidade da comunicação, sendo simplex unidirecional, half-duplex permitindo comunicação bidirecional, mas não simultânea, e full-duplex suportando fluxo de dados bidirecional simultâneo.

Exemplos de Comunicação de Dados Serial

#### UART (Universal Asynchronous Receiver Transmitter)

UART é um método simplificado para transferência de dados seriais, comumente utilizando sincronização pela borda inicial. É uma conexão full-duplex ponto a ponto com taxa de dados típica de até 1 Mbit/s, mas carece de mecanismos sofisticados de verificação de erros.

| Parâmetro  | Desempenho              |
|------------|-------------------------|
| Conexão    | Full-duplex, ponto a ponto |
| Taxa de Dados  | Até 1 Mbit/s            |
| Endereçamento | Nenhum                   |
| Validação  | Mínima (bit de paridade) |
| Meio       | Com fio                 |
| Distância  | Limitado à PCB           |

#### I2C (Inter-Integrated Circuit)

I2C é um método de comunicação meio-duplex multi-dispositivo que utiliza dois fios: relógio (SCL) e dados (SDA), gerenciados por meio de um protocolo simples. Ideal para configurações em que os dispositivos compartilham um terra comum.

| Parâmetro  | Desempenho                             |
|------------|----------------------------------------|
| Conexão    | Multidrop, meio-duplex                     |
| Taxa de Dados  | Até 3,4 Mbit/s                          |
| Endereçamento | 7 ou 10 bits                             |
| Validação  | Confirmação, mas sem verificação de erros |
| Meio       | Com fio                                |
| Distância  | Limitada à PCB                          |

#### SPI (Serial Peripheral Interface)

SPI permite velocidades mais altas em comparação com o I2C, usando linhas separadas para relógio (SCLK), dados (MOSI/MISO) e seleção de dispositivo (SS), tornando-o uma escolha adequada para aplicativos de streaming de dados.

| Parâmetro | Desempenho                                       |
|-----------|--------------------------------------------------|
| Conexão   | Full-duplex, gerente único com múltiplos subordinados |
| Taxa de Dados | Até 10 Mbit/s                                    |
| Endereçamento | Nenhum (pino SS usado)                          |
| Validação | Sem verificação de erros                       |
| Meio      | Com fio                                         |
| Distância | Limitada à PCB                                   |

Comunicação Serial de Alta Velocidade e SerDes

Interfaces de serialização e desserialização (SerDes) suportam transferências de dados em alta velocidade sem padronização, muitas vezes incorporando sinais de clock para comunicação sincronizada. Adequadas para altas taxas de dados que requerem longa distância sem problemas de referência ao terra.

Comunicação de Dados entre Placas e Sistemas

#### RS-232 e RS-485

Enquanto o RS-232 é obsoleto, ele estabeleceu os fundamentos para padrões de comunicação serial. O RS-485, por outro lado, utiliza sinalização diferencial para melhor imunidade a ruídos e suporta distâncias maiores e taxas de dados mais altas, tornando-o fundamental na automação industrial.

| Parâmetro  | RS-232                | RS-485                           |
|------------|-----------------------|----------------------------------|
| Conexão    | Ponto a ponto         | Multiponto                       |
| Taxa de Dados  | Até 20 Kbit/s         | Até 40 Mbit/s                    |
| Distância  | Até 15 m              | Até 1.200 m                       |
| Validação  | Mínima                 | Dependente do protocolo          |
| Meio       | Cabo                  | Cabo, par trançado               |

#### Barramento CAN (Controller Area Network)

Controller Area Network (CAN bus) é um protocolo robusto inicialmente desenvolvido para aplicações automotivas, agora amplamente utilizado em vários sistemas embarcados e industriais. Ele suporta a comunicação entre vários microcontroladores sem a necessidade de um computador hospedeiro.

O CAN bus utiliza sinalização diferencial (CAN_H e CAN_L), que oferece imunidade a ruídos aprimorada e garante a integridade dos dados, tornando-o adequado para ambientes hostis.

| Parâmetro | Desempenho            |
|-----------|-----------------------|
| Conexão   | Multiponto, meio-duplex |
| Taxa de Dados | Até 1 Mbit/s          |
| Endereçamento | 11 ou 29 bits          |
| Validação | Verificação de erro CRC |
| Meio      | Cabo par trançado      |
| Distância | Até 40 metros          |

Recursos-chave do CAN bus incluem:

- **Comunicação Baseada em Mensagem:** Cada mensagem possui um identificador exclusivo que determina sua prioridade.
- **Detecção de Erros e Isolamento de Falhas:** Utiliza vários tipos de verificações de erros, incluindo CRC.
- **Arbitragem:** A arbitragem de bits não destrutiva garante que a mensagem de maior prioridade seja enviada sem colisões.
- **Capacidade em Tempo Real:** Excelente para sistemas que exigem comunicação em tempo real.

Protocolos Modernos de Comunicação Serial para Sistemas Embarcados

#### USB (Universal Serial Bus)

O USB se tornou onipresente nas conexões periféricas, oferecendo tanto transferência de dados quanto capacidades de fornecimento de energia, com várias versões suportando até 40 Gbit/s.

#### SATA (Serial Advanced Technology Attachment)

O SATA conecta dispositivos de armazenamento em massa com comunicação de meio-duplex em alta velocidade, essencial para soluções de armazenamento interno de computadores.

#### PCI Express (PCIe)

O PCIe oferece comunicação full-duplex em alta velocidade para componentes internos de computadores, utilizando várias pistas para largura de banda escalável.

#### Ethernet

O Ethernet continua sendo essencial para conexões de LAN, suportando altas taxas de dados em longas distâncias com verificação de erros e confirmação incorporadas.

#### Protocolos de Comunicação Sem Fio

#### WiFi e Bluetooth

O WiFi oferece acesso à internet com altas taxas de dados e distâncias moderadas, enquanto o Bluetooth atende a aplicativos de baixa potência e curto alcance. O Bluetooth Low Energy (BLE) estende a vida útil da bateria para dispositivos de baixo ciclo de trabalho.

#### ZigBee e Z-Wave

Esses protocolos permitem a criação de redes em malha para sistemas de comunicação de baixa potência e intermitentes, ideais para IoT e automação residencial.

#### Comunicação por Infravermelho e Fibra Ótica

O infravermelho suporta comunicação de curto alcance, vista direta, comumente usado em controle remoto. A fibra ótica, por outro lado, se destaca na transmissão de dados em alta velocidade e longa distância, sendo a base das redes modernas.

#### JTAG para Testes e Configuração

JTAG fornece acesso crucial para testes e programação de PCBs, permitindo testes de varredura de fronteira e programação in-system para ICs digitais.

#### Conclusão

Em resumo, projetar sistemas de comunicação digital robustos para dispositivos embarcados requer cuidadosa consideração da integridade do sinal, escolha adequada entre comunicação paralela e serial e protocolos específicos adequados ao ambiente de aplicação. Compreender os detalhes dos sinais, a organização da rede e a implementação de mecanismos adequados de verificação de erros são essenciais para garantir uma transferência de dados confiável e eficiente em sistemas embarcados.

O CAN bus se destaca por sua robustez e eficiência em ambientes hostis, tornando-o inestimável em aplicações automotivas e industriais que exigem comunicação confiável em tempo real.

## 4. Sistemas de Energia

#### Segurança na Alimentação CA: Definindo o Problema

A energia CA é um componente crucial quando se trata de sistemas embutidos. No entanto, é essencial garantir a implementação segura da energia CA em um dispositivo para prevenir acidentes e falhas no sistema. A energia CA carrega riscos potenciais como choque elétrico e mau funcionamento do dispositivo se não for manuseada corretamente.

Para garantir a segurança da energia CA, é fundamental considerar a separação entre componentes de alta tensão (HV) e baixa tensão (LV). Na maioria dos países, entradas de energia abaixo de 50 V são classificadas como tensão extra baixa (ELV), simplificando os requisitos de segurança. As medidas de segurança para componentes HV, como conversores AC/DC, são mais rigorosas. Um método comum para garantir a segurança é enclausurar tanto o conversor AC/DC quanto o sistema eletrônico em um invólucro de metal condutivo com um aterramento de segurança ligado de volta ao aterramento de segurança da rede CA. Esta abordagem é amplamente utilizada em computadores pessoais de mesa.

#### Métodos de Falha Segura e Proteção Contra Sobre-corrente

Além da segurança operacional, os sistemas de energia também exigem métodos de falha segura. Em caso de falha, é crucial garantir que o sistema permaneça seguro e proteja o usuário de qualquer perigo potencial. É empregada a conceito de segurança contra falha única, onde qualquer elemento do sistema pode falhar em um estado de circuito aberto ou fechado sem causar danos.

A proteção contra sobrecorrente é outro aspecto vital dos sistemas de energia. Envolve mecanismos para prevenir o fluxo excessivo de corrente que pode levar ao superaquecimento e falha dos componentes. Há vários métodos comumente usados para proteção contra sobrecorrente:

1. Fusíveis: Fusíveis são simples e econômicos, mas têm limitações, como tempo de resposta lento e a necessidade de substituição manual.
2. Disjuntores: Disjuntores oferecem a conveniência de serem resetáveis, mas vêm com custos mais altos e maior tamanho.
3. Fusíveis resetáveis de coeficiente de temperatura positivo polimérico (PTC): Esses dispositivos limitam a corrente mudando de um estado de baixa resistência para alta resistência quando sobrecarregados, proporcionando uma capacidade de reset automático.
4. Proteção ativa de circuito: Esses sistemas usam circuitos de detecção para monitorar corrente e tensão e ativar controles adequados para limitar ou desligar a energia quando necessário. Eles oferecem tempos de resposta mais rápidos e precisão, mas vêm com aumento de complexidade e custo.

Independentemente do método de proteção contra sobrecorrente utilizado, é crucial garantir que o dispositivo de proteção seja o ponto mais fraco do sistema. O projeto adequado considera fatores como as correntes de sustentação máxima e de surto de partida ao definir o ponto de proteção de disparo.

#### Conversão AC/DC

Embora muitos dispositivos eletrônicos operem com energia de corrente contínua (DC), eles frequentemente necessitam de conversão de energia CA. Esta conversão é geralmente realizada por conversores AC/DC. Há diferentes abordagens para conversão AC/DC, cada uma com suas vantagens e desvantagens.

Uma abordagem clássica é o uso de transformadores operando na frequência da rede CA, tipicamente 60 Hz ou 50 Hz. Este método envolve abaixar a tensão CA, retificá-la através de uma ponte de diodos e filtrá-la para obter uma saída DC. No entanto, transformadores que operam em baixas frequências, como 60 Hz, tendem a ser volumosos e pesados. Frequências mais altas, como 400 Hz usadas na indústria da aviação, permitem transformadores menores e mais leves.

Uma alternativa aos transformadores são os comutadores off-line, que usam um método de conversão em modo chaveado. Esses conversores retificam a tensão da linha CA e a comutam rapidamente através do primário de um transformador em uma frequência muito mais alta, como 10 KHz a 1 MHz. Esta abordagem oferece vantagens como transformadores e capacitores de filtro de saída menores. Os comutadores off-line tornaram-se a escolha preferida em eletrônicos de consumo devido à sua eficiência, tamanho compacto e custo-efetividade.

#### Sistemas com Múltiplas Placas de Circuito Impresso: Regulação de Energia Local

Em sistemas com múltiplas placas de circuito impresso (PCBs), é crucial abordar a impedância e a variação de tensão nas conexões de energia e aterramento causadas por cargas de corrente dinâmicas. Para minimizar esses efeitos, a regulação de energia local é necessária.

Muitos sistemas industriais distribuem energia DC bruta em diferentes tensões, dependendo dos requisitos das PCBs satélite. No entanto, usar uma tensão DC diretamente da PCB sem regulação local pode levar a inconsistências, problemas de ruído e falhas durante testes regulatórios. Portanto, é aconselhável regular a fonte de energia na mesma PCB onde ela será utilizada para manter uma energia consistente e livre de ruído.

#### Conversão DC/DC: Linear vs. Comutação

Os reguladores de energia podem ser classificados em reguladores lineares e reguladores de comutação, cada um usando métodos diferentes para fornecer uma saída de tensão consistente.

Reguladores lineares usam divisão de tensão adaptativa para regular a tensão de saída. No entanto, esse método é ineficiente, pois dissipa energia dentro do regulador, resultando em ineficiência energética e possíveis falhas térmicas. Reguladores lineares são conhecidos por sua saída de baixo ruído, mas podem não ser adequados para grandes quedas de tensão entre entrada e saída.

Reguladores de comutação, por outro lado, usam ciclos de trabalho variáveis para regular a tensão de saída. Eles alternam a tensão de entrada em alta frequência e dependem de sistemas de feedback de controle para determinar o tempo de ligar/desligar do comutador. Reguladores de comutação são altamente eficientes e compactos, tornando-os adequados para várias aplicações. Eles incluem conversores buck (redução de tensão), conversores boost (aumento de tensão) e conversores buck-boost (aumentando ou reduzindo a tensão). A escolha entre reguladores lineares e de comutação depende de fatores como eficiência energética, requisitos de tensão e considerações de ruído.

#### Escolhendo Reguladores e Configurando um Sistema de Energia

Ao configurar um sistema de energia, é crucial considerar os requisitos de diferentes componentes e selecionar os reguladores apropriados de acordo. Vamos tomar alguns exemplos para ilustrar esse processo.

Exemplo 1:
- Um dispositivo com um sistema de driver de motor de 12 V, um bloco lógico operando a 2,5 V, um microcontrolador (MCU) principal requerendo 3,3 V e circuitos analógicos necessitando de 5 V.
- Um comutador off-line pode ser usado para conversão AC/DC para alimentar diretamente o driver do motor.
- Conversores buck podem fornecer as fontes de alimentação de 2,5 V e 3,3 V para o bloco lógico e MCU, respectivamente.
- O MCU atua como o controle central, gerenciando as fontes de alimentação e permitindo o desligamento seletivo de dispositivos periféricos para eficiência energética e comportamento seguro do sistema.

Exemplo 2:
- Um sistema de energia com um pacote de baterias consistindo de quatro baterias de lítio em série (4S) e duas em paralelo (2P).
- O sistema deve operar tanto a 18 V (carregamento da bateria) quanto a 10 V (baterias totalmente descarregadas).
- Um conversor buck-boost pode ser usado para fornecer uma saída consistente de 12 V para um circuito que requer essa tensão, alternando entre os modos buck e boost conforme necessário.
- Outros requisitos de energia, como um bloco lógico a 0,9 V ou um MCU a 3,3 V, podem ser cumpridos usando conversores buck apropriados.
- Considerações de filtragem e ruído devem ser levadas em conta para garantir tensões de fornecimento de energia estáveis em circuitos sensíveis ao ruído.

O monitoramento da fonte de energia é uma característica importante a ser considerada, permitindo o monitoramento das tensões em diferentes pontos do sistema. Usando divisores de tensão e conversores analógico-digital (ADCs), pode-se monitorar as fontes de energia e facilitar as sequências adequadas de ligar/desligar a energia.

Capacitores de bypass, desacoplamento e filtragem desempenham um papel crucial em sistemas de energia. Capacitores de bypass no chip diretamente conectados aos pinos de alimentação, capacitância distribuída em toda a camada de energia e filtragem nas saídas de reguladores de tensão contribuem para uma entrega de energia estável e livre de ruído. A seleção dos valores dos capacitores de bypass e sua distribuição deve considerar a resposta de alta frequência, pontos de ressonância e características de impedância dos capacitores usados.

Finalmente, é importante garantir conexões de energia e aterramento de baixa impedância para minimizar variações de tensão causadas por correntes de surto de banda larga geradas pela lógica digital. Camadas dedicadas de energia e aterramento dentro da PCB, combinadas com capacitância de bypass distribuída, ajudam a estabilizar a grade de energia e reduzir o impacto das flutuações de impedância.

Em resumo, desenvolver hardware para sistemas embutidos envolve uma consideração cuidadosa dos sistemas de energia. Isso inclui abordar a segurança da energia CA, implementar métodos de falha segura, selecionar métodos de proteção contra sobrecorrente apropriados e escolher conversores AC/DC e reguladores DC/DC adequados. Além disso, configurar um sistema de energia requer a seleção criteriosa de reguladores, consideração do monitoramento da fonte de energia e a incorporação de capacitores de bypass e conexões estáveis de energia e aterramento para garantir uma operação confiável e livre de ruído.


## 5. Energia da Bateria

A eletrônica moderna depende muito da energia da bateria, desde telefones celulares até ferramentas portáteis. Os dispositivos de hoje são principalmente desconectados, sendo que a energia CA é principalmente utilizada para carregar as baterias. Este capítulo foca no design de sistemas de bateria eficientes que atendam às necessidades de vários sistemas eletrônicos.

#### Principais Componentes de uma Bateria

Uma bateria de célula única é composta por três partes principais:

- **Ânodo:** O terminal negativo que emite elétrons quando a bateria é conectada a um circuito.
- **Cátodo:** O terminal positivo que absorve elétrons durante a operação do circuito.
- **Eletrólito:** Um meio que facilita o movimento de íons entre o ânodo e o cátodo, permitindo o fluxo de elétrons no circuito externo enquanto mantém a separação por meio de um transportador não condutivo chamado de separador.

### Tomada de Decisão: Baterias Descartáveis ​​vs. Recarregáveis

#### Considerações de Preço

Os sistemas recarregáveis ​​são mais caros devido à presença de eletrônicos adicionais, como fontes de CA/CC e as próprias baterias. Por outro lado, as baterias descartáveis oferecem uma solução de baixo custo, adequada para dispositivos de baixa potência, como controles remotos e relógios de parede.

#### Casos de Uso e Aplicações

- **Uso de Baixa Potência:** Ideal para baterias descartáveis geralmente encontradas em dispositivos de baixa potência.
- **Consumo de Alta Potência:** Baterias recarregáveis ​​com pacotes substituíveis são adequadas para aplicações de alta potência, como ferramentas elétricas.
- **Sistemas para Falhas de Energia:** Baterias recarregáveis ​​são preferíveis para dispositivos que precisam funcionar durante quedas de energia, como sistemas de UPS e luzes de emergência.

#### Definição de Requisitos de Energia

A eletrônica varia muito em consumo de energia. Supercomputadores exigem megawatts, enquanto relógios eletrônicos requerem microwatts. Portanto, entender o consumo de energia de um sistema, incluindo correntes de pico, correntes médias de longo prazo (LTAC) e faixas de tensão, é crucial para selecionar a bateria adequada.

#### Descarga da Bateria e Faixa de Tensão

A tensão da bateria diminui de forma não linear à medida que é descarregada. Os sistemas devem idealmente operar em toda a faixa de descarga da bateria. As opções incluem o uso de circuitos de aumento, reguladores de queda de tensão (LDO) ou baterias conectadas em série para manter a tensão operacional.

#### Tipos e Química das Baterias

Os tipos de bateria são categorizados por sua composição química e características de embalagem. É importante escolher a química da bateria certa para atender às necessidades da aplicação.

#### Características de Descarga

Compreender o comportamento da bateria sob diferentes cargas é fundamental. Os fabricantes geralmente fornecem classificações em ampere-hora (Ah) em baixas correntes de descarga para apresentar capacidades mais altas. No entanto, correntes de carga reais mais altas reduzem a capacidade efetiva, exigindo testes detalhados de capacidade.

#### Seleção da Química

Três tipos principais de bateria recarregável incluem:

- **Chumbo-ácido Selada (SLA)**
- **Níquel-Metal Hidreto (NiMH)**
- **Família de Íons de Lítio (Li-ion)**

As considerações de projeto abrangem correntes médias e de pico, tempo de uso, requisitos de tensão, temperaturas ambientais, mudanças na capacidade ao longo do tempo, circuitos de segurança e equilíbrio de carga.

### Métodos de Carregamento

#### Carregamento Específico para Cada Química

Cada química de bateria requer um método de carregamento específico. Circuitos integrados (CIs) ajudam a controlar o processo, com parâmetros ajustáveis ​​por meio de componentes digitais ou externos. Múltiplos CIs atendem a diferentes químicas, como Li-ion, chumbo-ácido e NiMH.

#### Baterias Inteligentes

Baterias inteligentes integram recursos além de células básicas, incluindo equilíbrio de carga e sistemas de monitoramento. Elas utilizam interfaces como I2C/SMB para comunicação, embora se espere uma futura transição para o barramento CAN. Essas baterias ainda exigem carregadores externos projetados para suas configurações específicas.

#### Segurança e Regulamentações

Transportar e vender produtos com baterias de Li-ion requer testes e certificações extensivas. Os altos custos de conformidade podem levar os fabricantes a usar pacotes de bateria pré-certificados. Garantir que as carcaças projetadas permitam a expansão da bateria ajuda a prevenir problemas como os vistos em incêndios de bateria notórios.

### Métodos Alternativos de Armazenamento de Energia

#### Supercapacitores

Embora os supercapacitores sejam frequentemente apresentados como substitutos para baterias, custos e limitações tecnológicas dificultam sua adoção generalizada.

#### Células de Combustível de Hidrogênio

Essas células geram eletricidade por meio de uma reação química entre hidrogênio e oxigênio, geralmente usadas em aplicações em larga escala.

#### Baterias de Fluxo

As baterias de fluxo usam eletrólitos fluidos em um sistema de bomba, adequadas para instalações grandes em vez de eletrônicos pequenos.

#### Energia Sem Fio

A energia sem fio é dividida em carregamento de proximidade, transmissão de energia em distâncias e sistemas sem baterias. Enquanto o carregamento de proximidade é comum em smartphones, aplicações em larga escala enfrentam barreiras de custo e eficiência.

#### Baterias de Estado Sólido

As baterias de estado sólido prometem uma densidade de energia aprimorada, mas desafios práticos como escalonamento de produção e competitividade de custos ainda estão presentes.

#### Resumo e Conclusões

O design de sistemas de bateria para eletrônicos embarcados envolve uma consideração cuidadosa de:

- Especificações de bateria inconsistentes e dados fornecidos pelos fabricantes.
- Custo, frequência de uso e ambiente de aplicação ao escolher entre baterias descartáveis ​​e recarregáveis.
- Necessidades de energia do sistema estimadas por meio de correntes médias de longo prazo (LTAC).
- Compatibilização de perfis de descarga com requisitos do sistema para uso ideal da bateria.

A tecnologia de bateria está em constante evolução e, embora existam alternativas, as baterias tradicionais permanecem como a solução primária de armazenamento de energia em sistemas eletrônicos pequenos. Garantir a segurança e a conformidade regulatória, ao mesmo tempo em que se mantém atualizado com os avanços tecnológicos, é essencial para o sucesso do desenvolvimento de hardware.

## 6. EMI e ESD

O mundo do hardware embarcado envolve lidar com várias formas de ruído eletrônico que podem interferir no funcionamento adequado dos dispositivos. Dois tipos significativos de interferência são a Interferência Eletromagnética (EMI) e a Descarga Eletrostática (ESD). Ambos são considerações cruciais no design e desenvolvimento de sistemas de hardware robustos e confiáveis.

#### EMI Interna e Externa

Qualquer sistema eletrônico digital gera intrinsecamente EMI. Esse ruído é influenciado pelas taxas de relógio, número de portas ativas e outros dispositivos de comutação. Externamente, inúmeras fontes como dispositivos de rádio, ruído solar, redes elétricas e eletrônicos podem introduzir ruído. Internamente, o ruído dentro de um sistema pode degradar o desempenho, reduzir a precisão ou até tornar um dispositivo não funcional.

### Importância do Controle de EMI

Para garantir o desempenho ideal e a conformidade regulatória dos dispositivos eletrônicos, os designers precisam minimizar a EMI gerada por seus produtos e protegê-los do ruído ambiental.

#### EMI Radiada

Refere-se ao ruído emitido que pode afetar outros dispositivos fora do sistema. Se a EMI radiada de um sistema exceder os níveis permitidos, pode perturbar eletrônicos próximos.

#### EMI Conduzida

Trata-se do ruído que é injetado nas linhas de energia CA pelo sistema. Essas correntes transientes ou picos de alta frequência de tensão podem causar interrupções se não forem controladas.

#### Aspectos Regulatórios

Diversas indústrias têm padrões específicos de conformidade para EMI, como os setores médico, aeroespacial e militar. Esses padrões garantem que os dispositivos funcionem de maneira confiável sem causar interferências excessivas.

#### Ruído Intrínseco na Eletrônica

Nem todo o ruído na eletrônica vem da EMI. Algumas fontes de ruído são intrínsecas aos próprios componentes do sistema. Isso inclui:

- **Ruído de Cintilação (Ruído 1/F):** Originário de transistores CMOS.
- **Ruído Térmico:** Devido às atividades térmicas em resistores.
- **Ruído de Torneira e Ruído de Rajada:** Decorrente de transições de carga discretas dentro de condutores e semicondutores.

#### Técnicas de Design e Aterramento

Limitar o ruído em um sistema envolve aterramento adequado, caixas de blindagem e proteção de portas. Técnicas como gaiolas de Faraday podem conter o ruído e atender às restrições regulamentares de maneira eficiente.

#### Requisitos Regulatórios e Testes

Os dispositivos devem passar por testes regulatórios para garantir que operem abaixo dos limites de ruído estabelecidos. Isso geralmente envolve medir emissões radiadas com antenas calibradas e analisadores de espectro.

#### Análise no Domínio da Frequência

Identificar fontes de ruído é melhor feito usando análise no domínio da frequência. Isso envolve observar espectros de sinal para encontrar múltiplos harmônicos e outros padrões de ruído. Entender essas frequências pode ajudar a identificar e mitigar as origens do ruído.

#### Relógios Mais Lentos e Transições Mais Suaves

Reduzir as velocidades de transição de sinais digitais pode diminuir significativamente a EMI. Isso pode ser conseguido ajustando as forças dos drivers ou usando relógios mais lentos.

#### Técnicas de Espectro Espalhado

Isso envolve variar ligeiramente o período do relógio para espalhar a energia espectral ao longo de uma faixa, reduzindo a EMI pico.

#### Blindagem e Resistores para SMPS

Fontes de alimentação comutadas (SMPS) podem ser fontes de ruído. Adicionar resistores RC e usar gaiolas de Faraday pode mitigar isso.

#### Estratégias de Interconexão de Cabos

O ruído conduzido pode viajar por cabos. Usar pares trançados ou núcleos de ferrite reduz isso. Para controles de motor, colocar diodos de retorno diretamente no motor ajuda a reduzir o ruído nos cabos de controle.

#### Acoplamento Capacitivo e Magnético

O ruído pode ser transferido através de capacitância ou indução magnética entre componentes. Espaçar cuidadosamente as conexões e usar sinais diferenciais ajuda a mitigar isso.

#### Estabelecendo um Aterramento de Baixa Impedância

Criar uma rede de aterramento de baixa impedância é crucial. Serve como um caminho de retorno de corrente estável, reduzindo a interferência de ruído. Várias configurações, como múltiplos pontos de aterramento e folhas condutoras sólidas, podem aprimorar isso.

#### Identificando Componentes Ruidosos e Sensíveis

O planejamento de placas envolve separar componentes ruidosos dos sensíveis na PCB. Circuitos analógicos e de sinal misto não devem compartilhar fontes de alimentação com componentes digitais para minimizar a transferência de ruído.

#### Contenção e Proteção

As gaiolas de Faraday efetivamente contêm e protegem sistemas tanto da EMI interna quanto externa. Elas podem ser usadas para blindar sistemas inteiros ou componentes sensíveis selecionados.

#### Entendendo Eventos de ESD

A ESD pode causar danos significativos aos circuitos. Proteger contra a ESD envolve projetar circuitos para tolerar e sobreviver a surtos de tensão. Diodos TVS são comumente usados para limitar esses surtos.

#### Resumo e Melhores Práticas

O gerenciamento eficaz de EMI e ESD envolve reconhecer fontes de ruído, aterramento adequado e técnicas de blindagem. Relógios mais lentos e transições de sinal mais suaves reduzem o ruído, e o planejamento de placas ajuda a isolar componentes sensíveis. Seguir esses princípios garante o desenvolvimento de sistemas embarcados robustos e confiáveis.

## 7. ADCs e DACs

Em sistemas eletrônicos, conversores de dados fazem a ponte entre controles digitais e dispositivos periféricos não digitais. A conversão de sinais analógicos para dados digitais é crucial para a eletrônica moderna, especialmente no domínio dos sistemas embarcados. Esses sistemas requerem conversores digital-para-analógico (DACs) e analógico-para-digital (ADCs) para interface com o mundo externo, permitindo processamento e controle de sinal digital.

#### Tipos de DACs

Os DACs são essenciais na conversão de sinais digitais em analógicos. Existem dois tipos principais:
- **DACs de Taxa Nyquist:** Atualizam sua saída uma vez por ciclo de clock.
- **DACs de Densidade de Pulso:** Precisam de múltiplos ciclos de clock para atingir uma saída estável, utilizando métodos como modulação por largura de pulso (PWM) e delta-sigma ($\Delta \Sigma$).

#### Saídas de DAC

Os DACs podem ter diferentes tipos de saídas:
1. **Saída de Tensão, Referenciada ao Terra:** Esta é a forma mais simples e comum, produzindo uma tensão de saída entre o pino de saída e o terra. No entanto, pode ser ruidosa.
2. **Saída de Tensão, Sinais Diferenciais:** Aqui, duas saídas de tensão definem o sinal como a diferença entre elas. Esta configuração oferece melhor imunidade ao ruído e uma maior razão sinal-ruído.
3. **Saída de Corrente, Sinais Diferenciais:** Esses DACs fornecem velocidades de conversão rápidas e são tipicamente usados com linhas de transmissão diferenciais.

#### Características do DAC

DACs ideais deveriam produzir uma saída suave, em forma de escada, quando carregados com códigos digitais. A resolução de um DAC, variando de 6 a 32 bits, influencia seu desempenho e velocidade de conversão. Características não ideais como offset DC, erros de ganho, não linearidade integral (INL) e não linearidade diferencial (DNL) podem afetar a saída.

#### Características do ADC

Os ADCs convertem sinais analógicos em dados digitais. Eles compartilham critérios de desempenho semelhantes aos dos DACs, como erros de offset, erros de ganho, INL e DNL. A calibração nos sinais de entrada mínimo e máximo pode compensar esses erros.

#### Entradas e Taxas de Amostragem de ADC

A maioria dos ADCs possui entradas diferenciais, e ao lidar com entradas referenciadas ao terra, uma entrada é conectada ao terra. Os ADCs possuem diversas resoluções (4 a 32 bits) e taxas de amostragem (até 16 G amostras/seg). O erro de quantização é inerente a todos os ADCs e depende da resolução. A taxa de amostragem deve ser pelo menos o dobro da maior frequência do sinal de entrada (taxa de Nyquist) para evitar aliasing.

#### Ruído e Erros

Os ADCs são propensos a erros de quantização, abertura e ruído, especialmente com sinais de alta velocidade. A relação entre a taxa de amostragem e o conteúdo de frequência do sinal é crítica para evitar problemas como aliasing.

#### Tipos de Filtros

Para mitigar o aliasing, filtros analógicos como redes RC Passivas, Op-amp (girador) e LC Passivas são usados. Esses filtros ajudam a reduzir o conteúdo de alta frequência antes que o sinal alcance o ADC. Filtros antialiasing integrados também existem para sistemas mais complexos.

#### Projeto de Filtros

Para a maioria das aplicações, um simples filtro passa-baixa (LPF) RC é suficiente. Filtros mais complexos como filtros de três e sete polos podem ser implementados conforme necessário, usando ferramentas como EDA para o design.

#### Conceito e Implementação

Os DACs PWM são populares em sistemas embarcados devido ao seu custo-benefício e simplicidade. Um padrão de controle com um ciclo de trabalho definido digitalmente é alimentado em um LPF, criando uma tensão analógica.

#### Problemas de Desempenho

O principal problema com DACs PWM é a ondulação de saída. Resoluções mais altas e clocks mais rápidos podem ajudar a minimizar a ondulação. Técnicas como o uso de padrões mais curtos e frequências de clock mais altas também podem melhorar o desempenho.

#### Técnicas Avançadas

Combinar sinais PWM com correntes ponderadas ou inversores lógicos pode reduzir ainda mais a ondulação. Filtros de ordem superior ou DACs integrados podem ser necessários para necessidades de alta resolução.

#### Método DDS

Os DACs podem criar formas de onda arbitrárias através da Síntese Digital Direta (DDS). Isso envolve o uso de um clock para incrementar um contador, que endereça uma tabela de consulta digital com dados de amplitude para uma forma de onda amostrada. O DAC então gera a forma de onda desejada.

#### Resumo e Conclusões

Conversores de dados são vitais para sistemas embarcados, conectando controles digitais com o mundo não digital. Os ADCs e DACs devem operar mais rápido que o dobro da maior frequência do sinal de entrada para evitar aliasing. Filtros simples podem prevenir aliasing, e DACs PWM podem ser implementados facilmente com um design cuidadoso para minimizar a ondulação. Técnicas e ferramentas avançadas podem otimizar o desempenho, garantindo uma conversão de sinal de alta qualidade.


## 8. Periféricos

Sistemas embarcados desempenham um papel crucial na conexão do mundo digital com o reino analógico. Para interagir efetivamente com dispositivos analógicos, são empregados **circuitos de acionamento e de sensoriamento**. Os circuitos de acionamento, também conhecidos como circuitos driver, fornecem a tensão e a corrente necessárias para operar dispositivos periféricos, enquanto os circuitos de sensoriamento são responsáveis por monitorar e converter informações analógicas em dados digitais que uma unidade de controle digital (UCD) pode processar.

## Compreendendo os Circuitos de Acionamento

### Fundamentos dos Circuitos Driver

Um circuito driver é essencial para controlar dispositivos que requerem mais potência do que a saída de dispositivos digitais típicos pode fornecer. Por exemplo, ao controlar um **motor**, um circuito driver pode ser utilizado para suprir alta potência, enquanto um circuito de sensoriamento pode monitorar a velocidade de rotação desse motor. Os sistemas podem funcionar sem feedback (em malha aberta) ou com feedback (em malha fechada), onde o desempenho é ajustado com base em dados em tempo real.

### Tipos de Chaveamento

Os circuitos de acionamento podem ser categorizados com base em sua metodologia de chaveamento:

- **Chaveamento de Alto Lado**: A chave está posicionada entre a fonte de alimentação e a carga. Essa disposição protege a carga de mudanças indesejadas nas conexões de terra.

- **Chaveamento de Baixo Lado**: Essa configuração coloca a chave entre a carga e a terra, fornecendo uma solução mais simples para o controle de potência.

Cada método requer transistores de potência e pode precisar de circuitos de interface adicionais para operação eficaz.

## Transistores de Potência em Sistemas Embarcados

Os transistores de potência são componentes vitais nos circuitos de acionamento. A escolha dos transistores afeta a eficiência e o desempenho. **Transistores de Efeito de Campo (FETs)**, particularmente **MOSFETs**, são comumente escolhidos por sua versatilidade e disponibilidade. Compreender os vários tipos de transistores de potência é crucial:

- **Carbeto de Silício (SiC)**: Adequado para aplicações de alta tensão e alta corrente, muitas vezes utilizado em conversão de potência, mas menos comum em sistemas embarcados.
  
- **Nitreto de Gálio (GaN)**: Conhecido por baixa resistência e utilizado em situações de alta corrente.

- **Transistores Bipolares de Porta Isolada (IGBT)**: Normalmente usados em aplicações de conversão de potência.

- **Transistores Bipolares de Junção (BJT)**: Essenciais em muitas aplicações analógicas, adequados para chaveamento também.

- **Transistores de Efeito de Campo por Junção (JFET)**: Ainda utilizados em algumas aplicações, mas ofuscados pelos MOSFETs.

## Estratégias de Sinal de Acionamento

Existem várias estratégias para circuitos de acionamento, cada uma adequada a diferentes aplicações:

1. **Chaveamento de Dois Estados**: Este método de controle on-off é simples e eficaz para muitos dispositivos.

2. **Controle Linear**: Envolve o uso de um sinal analógico para controlar o dispositivo, muitas vezes exigindo um DAC (Conversor Digital para Analógico) de saída de tensão.

3. **Modulação por Largura de Pulso (PWM)**: Essa técnica controla a velocidade de motores e o brilho de LEDs variando o ciclo on-off. A inércia do motor pode ajudar a filtrar os sinais PWM, enquanto a visão humana percebe mudanças no brilho do LED devido ao PWM. É essencial que o ciclo de trabalho seja ajustado para evitar piscadas.

## Gestão Térmica de Transistores de Potência

Um design eficiente deve considerar o desempenho térmico dos dispositivos de potência. Calor excessivo pode levar a falhas transientes. Aspectos-chave incluem:

- **Resistência Térmica**: Influi na forma como o calor se dissipa do dispositivo para o ambiente.

- **Ciclo de Trabalho**: Quanto maior o ciclo de trabalho, mais calor é gerado, o que pode exigir dissipadores de calor ou outras soluções de resfriamento.

Selecionar um transistor com uma **RDS (resistência dreno-fonte)** apropriada pode mitigar a geração de calor e aprimorar o desempenho.

## Acionando Cargas: LEDs e Dispositivos Indutivos

### Acionando LEDs

Os drivers de baixo lado frequentemente energizam LEDs. É vital entender as curvas de polarização associadas a diferentes cores de LEDs para alcançar o brilho desejado. O **controle PWM** fornece um ajuste eficaz de brilho e normalmente é inferior a 2 kHz para evitar o efeito de piscar.

### Acionando Cargas Indutivas

Cargas indutivas como motores e relés podem gerar tensões transientes destrutivas. Implementar **diodos de flyback** ajuda a gerenciar esses picos de tensão, direcionando a corrente de forma segura quando o circuito é desligado.

### Atuação de Solenoides e Relés

Tanto solenoides quanto relés requerem potência para ativação, e a circuitaria necessária é frequentemente semelhante. É crítico incluir proteção, como diodos de flyback, para evitar danos durante o chaveamento.

## Ponte H e Controle de Motores

Para dispositivos que requerem reversão da direção da corrente, são utilizados **circuitos de ponte H**. Esses circuitos são vitais para controlar motores DC com escovas e sem escovas, permitindo uma operação suave e flexibilidade de direção. A ponte H utiliza pares de transistores para gerenciar fluxo de corrente de forma eficaz.

### Tipos de Motores

- **Motores DC com Escovas**: Simples e econômicos, mas podem gerar ruído elétrico e desgastar-se com o tempo.

- **Motores DC Sem Escovas**: Mais confiáveis devido à comutação eletrônica, úteis em muitas aplicações.

- **Motores de Passo**: Oferecem controle preciso com passos distintos, ideais para tarefas que requerem alta precisão e repetibilidade.

## Considerações de Segurança no Controle de Motores

Ao gerenciar motores, a segurança é primordial. Várias estratégias ajudam a prevenir sobrecargas e falhas mecânicas, incluindo:

- **Sensores de Corrente de Resposta Rápida**: Monitoram a ocorrência de paradas ou atolas.

- **Chaves de Limite**: Desligam circuitos quando os limites mecânicos são alcançados.

- **Dispositivos de Corte de Energia**: Fusíveis ou dispositivos resetáveis protegem contra sobrecorrentes sustentadas.

## Conclusão

O desenvolvimento de hardware para sistemas embarcados envolve uma compreensão profunda de vários componentes e suas interações. A seleção de circuitos de acionamento apropriados, transistores e a gestão do desempenho térmico são críticos para criar sistemas eficazes e eficientes. Com um design cuidadoso, os sistemas embarcados podem alcançar um desempenho confiável em aplicações variadas, desde exibições simples de LEDs até sistemas complexos de controle de motores.
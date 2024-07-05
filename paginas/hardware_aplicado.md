# Hardware Aplicado

Este conteúdo aborda métodos de design eletrônico aplicados a dispositivos do mundo real, focando na criação de sistemas confiáveis e funcionais. É direcionado a engenheiros e designers com conhecimentos em eletrônica e ciência, e explora desde a arquitetura do sistema até a resolução de problemas comuns em dispositivos modernos.

## Conteúdos

[1. Conceitos Essenciais](#1-conceitos-essenciais)

[2. Arquitetando o Hardware](#2-arquitetando-o-hardware)

[3. Comunicando](#3-comunicando)


## 1. Conceitos Essenciais

### Introdução

O desenvolvimento de hardware para sistemas embarcados requer uma compreensão aprofundada dos conceitos eletrônicos fundamentais. Neste artigo, discutiremos as diferenças entre componentes eletrônicos ideais e não ideais, explorando como essas diferenças impactam o design de sistemas reais.

### Simplificações Ideais na Academia

Embora a maioria dos sistemas eletrônicos modernos seja digital, muitos problemas de design são de natureza analógica. Entre os desafios comuns estão o ruído, a integridade do sinal, a estabilidade de energia, a interferência eletromagnética (EMI) e a impedância de conexão. Modelos simplificados ajudam a entender rapidamente como algo deve funcionar, mas frequentemente omitem detalhes importantes, levando a possíveis falhas de desempenho.

### Interconexões

Mesmo um curto pedaço de fio pode ter impedância significativa, atuando como um filtro passa-baixa (LPF) acima de 300-400 MHz e sendo sensível a movimento. Em conexões de placas de circuito impresso (PCBs), os traços podem começar a atuar como LPFs em torno de 80-90 MHz devido à capacitância aumentada, resultando em erros de fase nas distribuições de sinal, especialmente em altas frequências.

### Componentes Básicos

#### Capacitores

Capacitores modernos fazem compromissos em termos de capacitância por unidade de volume, tensão máxima aplicada, temperaturas operacionais, variação de temperatura, variação de tensão aplicada, variação com envelhecimento, precisão nominal e vida útil total. Capacitores Classe 1 (C0G e NP0) priorizam estabilidade térmica e precisão, enquanto Capacitores Classe 2 (X5R, X7R, Y5V) sacrificam essas características para aumentar a capacitância.

#### Resistores

Resistores ideais têm impedância plana em frequências variadas. Contudo, resistores modernos, como os de filme metálico, produzem menos ruído e são preferidos em relação aos de carbono. Resistores de potência múltipla comuns são fabricados com métodos de fio enrolado, tendo componentes significativos de ESL e EPC.

#### Indutores

Indutores são usados em conversão de energia, processamento de sinais RF e limitação de EMI. Indutores com alta Q são cruciais para eficiência de fonte, enquanto indutores de EMI, como choques, limitam correntes transitórias. A resistência série equivalente (ESR) define a qualidade de um indutor em filtros, e a eficácia pode ser limitada em conversores de energia comutados.

#### Fontes de Tensão e Baterias

Fontes de tensão ideais não existem no mundo real. Baterias têm limitações de capacidade e variação de tensão durante a descarga. Fontes de alimentação lineares e reguladores otimizam para ruído baixo, enquanto fontes de alimentação chaveadas são mais eficientes energeticamente, criando ruído de comutação.

#### Fontes de Corrente e Amplificadores Operacionais

Fontes de corrente ideais também não existem. Amplificadores operacionais (op-amps) ideais têm infinitas propriedades, mas na prática têm várias limitações, como necessidade de alimentação, ruído, e limitações de ganho e largura de banda. Comparadores de tensão se diferenciam dos op-amps por não terem feedback analógico e serem usados em sinais digitais.

#### Dispositivos Digitais Não Ideais

Dispositivos digitais são resilientes a ruído, mas mesmo sistemas digitais enfrentam problemas como indutância distribuída e "bounces" de estado falso. A integridade do sinal pode ser comprometida por taxas de dados altas, resistência do caminho de transmissão, ou caminhos de transmissão carregados com capacitância.

#### Integridade do Sinal

Efeitos indesejados podem ser causados por ruído radiado externamente ou por circuitos internos interferentes, conhecidos como crosstalk. Emissões de radiação são problemáticas em dispositivos com circuitos digitais de alta frequência, regulados por órgãos como a FCC para minimizar interferências entre dispositivos eletrônicos.

### Conclusões

- As simplificações acadêmicas frequentemente omitem detalhes importantes.
- Todas as conexões têm impedância, afetando a variação de tensão.
- Erros de fase podem existir mesmo em sinais comuns devido à carga capacitiva.
- Capacitores, resistores e indutores têm várias propriedades limitantes.
- Fontes de tensão e corrente têm componentes de impedância e ruído.
- Chaves e relés apresentam problemas de bounce e resistência de contato variável.
- Op-amps têm várias limitações que afetam o desempenho.
- Instabilidade de potência pode corromper lógica.
- Dispositivos digitais criam emissões radiadas e sujeitas a crosstalk.

## 2. Arquitetando o Hardware

O desenvolvimento de hardware para sistemas embarcados envolve a arquitetura do sistema, as estratégias de design moderno, os métodos de controle digital, as especificações de Controladores de Unidade Digital (DCUs), e as opções de controladores de hardware e software.

Em relação à arquitetura do sistema, é importante definir os principais componentes do sistema em nível de placa, considerar a implementação do controle digital no núcleo e examinar os critérios para a escolha de uma unidade de controle digital. Além disso, é fundamental selecionar o microcontrolador (MCU) adequado.

Ao simular ou construir o sistema, normalmente não há necessidade de criar uma simulação completa de todo o sistema de controle embarcado. O código do controlador digital pode ser simulado várias vezes dentro do ambiente de design integrado (IDE) para ajustar os sinais de controle, mas simular as funções periféricas geradas por esses sinais normalmente não é necessário. Construir uma PCB de primeira geração, por outro lado, é rápido e de baixo custo. Isso possibilita que um produto real chegue rapidamente às mãos dos projetistas para depuração, tornando a simulação do dispositivo desnecessária. Para um MCU com um conjunto simples de periféricos, outra opção seria uma placa de desenvolvimento/demonstração.

Componentes de circuito com pinos ou fios que atravessam orifícios na PCB (componentes de orifício passante) são adequados para montaguem manual. No entanto, esses componentes, também chamados de componentes com chumbo, não são adequados para montagem automatizada ou para circuitos de alta frequência. Além disso, os componentes de orifício passante tendem a ser muito maiores do que seus equivalentes de montagem em superfície.

A lógica de portas discretas, como a série lógica 7400, que normalmente possui de quatro a seis portas lógicas por chip (e muitas variantes disponíveis), foi desenvolvida no meio da década de 1960 e ainda é fabricada e amplamente vendida. No entanto, este capítulo se concentra em métodos modernos que utilizam dispositivos programáveis e funções de lógica baseada em código. Dispositivos digitais singulares devem ser vistos apenas como shifters de nível e buffers de saída.

Para minimizar os problemas associados aos circuitos analógicos, uma estratégia moderna é converter rapidamente qualquer sinal analógico em um equivalente digital. Sinais analógicos têm problemas de ruído, distorção e outras preocupações com a integridade do sinal. Fluxos de dados digitais são menos problemáticos para conectar ao longo de distâncias e podem permanecer funcionais em ambientes hostis de interferência eletromagnética (EMI).

Um exemplo é a utilização de um filtro passa-banda com amplificador operacional (op-amp). Nesse caso, os capacitores precisam ser de alta qualidade, com boa precisão absoluta e linearidade. A precisão dos resistores e capacitores afetará a precisão da resposta em frequência. Op-amps não ideais também contribuem para ruídos, distorções e deslocamentos de sinal DC.

No entanto, convertendo o sinal analógico em um formato digital utilizando um conversor analógico-digital (ADC) seguido de um filtro definido por software (SW), é possível obter uma solução de baixo custo e altamente repetível. Frequentemente, um ADC embutido no MCU e um filtro definido por software são suficientes para essa tarefa.

A adoção de métodos digitais é ainda mais relevante em sistemas de controle. Embora um loop de controle analógico clássico possa ser utilizado, os sistemas de controle modernos são de natureza mista, com algumas características analógicas nos blocos driver, unidade de controle digital (DCU) e blocos de sensoriamento. No entanto, a funcionalidade de DSP pode assumir várias formas para alcançar um controle ótimo.

A abordagem principal de um sistema principalmente digital é converter qualquer sinal analógico (voltagem de controle, sons, informações de vídeo, etc.) em um fluxo de dados equivalente digital. Esse fluxo de dados é então processado apenas usando métodos digitais. A conversão para um formato analógico só é necessária se for necessário na saída. A indústria se refere a essa abordagem como abordagem de sinal misto.

A principal diferença entre MCU e MPU é que MCUs tendem a ter mais recursos para operar de forma autônoma, enquanto os MPUs geralmente necessitam de mais suporte externo. Entretanto, há uma sobreposição significativa de recursos entre eles. A maioria das MCUs inclui toda a funcionalidade necessária para o dispositivo funcionar com suporte externo mínimo. Interfaces de comunicação serial com periféricos externos são suportadas por capacidades de UART, SPI, I2C e CAN. Além disso, capacidades de ADC e DAC são recursos comuns.

Em relação aos controladores de hardware, existem várias opções disponíveis. Dispositivos de lógica programável, como PAL (programmable array logic) e PLD (programmable logic device), bem como CPLD (complex programmable logic device) e FPGA (field-programmable gate array), são amplamente utilizados. ASICs digitais (application-specific integrated circuits) também são uma opção quando se busca alta velocidade para lógica dedicada.

Já em relação aos controladores de software, podemos utilizar os dispositivos MCU e MPU. Enquanto MCU é mais voltado para dispositivos embutidos e possui todos os recursos necessários para o dispositivo funcionar com suporte mínimo, os MPs geralmente mantêm a RAM e a ROM fora do chip, com destaque para a interface com a memória externa e periféricos.

No caso dos computadores, eles são configurados para se conectar aos periféricos de computador comuns, enquanto uma MCU é configurada para se relacionar com outros circuitos integrados e fornecer estímulo/resposta por meio de portas individuais.

Em relação à seleção de um Controlador de Unidade Digital (DCU), é importante determinar todos os elementos que precisam ser controlados ou monitorados. Isso inclui tanto os componentes óbvios quanto os que podem ser esquecidos em uma primeira contagem dos interconectes periféricos.

Além disso, é fundamental evitar gargalos de comunicação serial (portas SerCom), que ocorrem frequentemente quando várias unidades periféricas estão conectadas a uma única interface. Para evitar esses gargalos, é necessário fazer uma estimativa do tráfego máximo que cada porta pode suportar.

Também é possível usar o recurso de Acesso Direto à Memória (DMA) para mover grandes blocos de dados dentro e fora do sistema sem envolver a CPU. Isso pode acelerar o processo de transferência de dados e economizar recursos de processamento.

Ao aplicar métodos de processamento digital de sinal (DSP), é necessário levar em consideração a taxa de amostragem e os requisitos de clock do DCU, bem como a complexidade do algoritmo de DSP. É importante verificar se o DCU tem o poder de processamento necessário para lidar com as taxas de dados esperadas.

A seleção de um MCU ou MPU requer uma análise cuidadosa dos recursos internos necessários. Isso inclui portas de entrada/saída (GPIO), capacidade de comunicação serial, recursos internos de ADC e DAC, comparadores de tensão, relógio em tempo real, sistema de geração de clock, consumo de energia, memória programável, tamanho da memória RAM, capacidade de manipulação de interrupções, capacidade de cálculo de ponto flutuante, reset de energia e detecção de interrupção, contrôle de timer e considerações de tamanho físico.

A decisão final sobre o controlador adequado deve ser baseada em considerações específicas do projeto, levando em conta fatores como funções especializadas, sistemas com vários MCU, sistemas de MCU de uso geral, especificações do controlador, recursos internos necessários, capacidade de manipulação interrompções, e recursos de clock e memória.

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
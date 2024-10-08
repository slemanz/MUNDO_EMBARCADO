# Desvendando Sistemas Embarcados

Este conteúdo oferece uma visão abrangente sobre o desenvolvimento de software para sistemas embarcados, abordando padrões de design, integração hardware/software e otimização em ambientes com recursos limitados.

## Conteúdos

[1. Desafios e Princípios](#1-desafios-e-princípios)

[2. Estruturando a Complexidade](#2-estruturando-a-complexidade)

[3. Trabalhando com o Hardware](#3-trabalhando-com-o-hardware)

[4. Entradas, Saídas e Temporizadores](#4-entradas-saídas-e-temporizadores)


## 1. Desafios e Princípios

**Introdução**

Sistemas embarcados são sistemas computadorizados criados para uma aplicação específica. Eles podem variam conforme o contexto: para um desenvolvedor de servidores, um aplicativo de telefone é um sistema embarcado, enquanto para um programador de microprocessadores de 8 bits, qualquer coisa com sistema operacional não parece muito embarcada. Exemplos comuns são micro-ondas e carros que executam softwares, mas não são considerados computadores.

**Desenvolvimento de Sistemas Embarcados**

Sistemas embarcados oferecem desafios únicos aos desenvolvedores. Esses desafios levam os engenheiros a desenvolver uma série de ferramentas para lidar com as restrições envolvidas.

**Compiladores e Linguagens**

Sistemas embarcados utilizam compiladores cruzados (cross-compilers) que rodam em um computador de desenvolvimento, mas produzem um código que será executado em um sistema alvo embarcado. O processador embarcado, muitas vezes, depende de compiladores fornecidos pelo fabricante ou de compiladores amplamente utilizados, como aqueles da família GNU (GCC).

Os princípios de design orientado a objetos, como encapsulamento, modularidade e abstração de dados, são valiosos para manter o design robusto e flexível. No entanto, é crucial reconhecer e equilibrar os trade-offs necessários entre os objetivos do design de software e os objetivos do sistema.

**Depuração**

Diferente de sistemas convencionais, onde se pode compilar e depurar no mesmo computador, em sistemas embarcados o depurador se comunica com o processador alvo via interface especial (muitas vezes chamada de JTAG). Essa interface permite que o depurador intercepte as operações do processador, o que consome recursos adicionais e pode aumentar os custos do processador.

Para evitar esses custos, muitos sistemas embarcados utilizam métodos mais simples de depuração, como logs via printf. Embora úteis, essas abordagens podem alterar a temporização do sistema, escondendo certos bugs que só aparecem depois que a depuração é desativada.

**Restrições de Recursos**

Sistemas embarcados são projetados para realizar tarefas específicas, eliminando recursos desnecessários. Considerações incluem:

- Memória (RAM)
- Espaço para código (ROM ou flash)
- Ciclos de processamento ou velocidade
- Consumo de energia (impactando a vida útil da bateria)
- Periféricos do processador

Trabalhar com hardware pode ser desafiador, especialmente quando se lida com bugs que podem estar tanto no hardware quanto no software. Além disso, o software deve evitar causar danos ao hardware, o que requer bom entendimento das capacidades do hardware.

Uma vez desenvolvidos e testados, os sistemas devem ser fabricados a custos razoáveis. Erros podem ser catastróficos em produtos críticos como na área médica ou aviação. E os produtos devem poder se adaptar a mudanças ao longo do seu ciclo de vida, exigindo flexibilidade no design.

**Princípios para Enfrentar os Desafios**

O desenvolvimento de sistemas embarcados deve levar em conta uma série de princípios para lidar com os desafios de flexibilidade e restrições de recursos:

- Modularidade: Dividir funcionalidades em subsistemas e ocultar dados que cada um utiliza.
- Encapsulamento: Criar interfaces claras entre os subsistemas, permitindo que sejam alterados sem impactar outras partes do sistema.
- Qualidade e Testes: Escrever testes para o código melhora a qualidade e fornece documentação. Testes ajudam a identificar e corrigir bugs mais cedo.
- Documentação: Comentários no código são essenciais para manutenção futura.
- Otimização: Implementar as funcionalidades primeiro e só depois otimizar, conforme necessário.

**Prototipagem e Placas de Desenvolvimento**

Prototipagem com placas de desenvolvimento facilita o início do projeto, mas essas placas têm limitações e não substituem o produto final. É fundamental considerar como o firmware será atualizado, a necessidade de modos de baixo consumo de energia, watchdog timers para erros catastróficos, e previsões para futuras correções e melhorias.

À medida que se demanda por dispositivos menores, mais rápidos ou mais baratos, pode ser necessário um hardware customizado e usar camadas de abstração fornecidas pelo fabricante do microprocessador. Isso permite criar sistemas determinísticos e em tempo real, além de utilizar RTOS (sistemas operacionais de tempo real).

**Conclusão**

Desenvolver sistemas embarcados requer um equilíbrio entre as necessidades do sistema e as restrições do hardware. Flexibilidade, modularidade, testes rigorosos e documentação são essenciais para enfrentar os desafios do ciclo de vida do produto e garantir um sistema robusto e adaptável às mudanças.

## 2. Estruturando a Complexidade

**Criação da Arquitetura de Sistemas**

Mesmo sistemas embarcados pequenos têm muitos detalhes, dificultando a identificação de padrões aplicáveis. Uma visão abrangente do sistema é essencial para entender quais partes têm soluções simples e quais têm dependências ocultas. Um bom design começa com um design razoável e vai melhorando, preferencialmente antes da implementação. Diagramas de arquitetura são uma forma eficaz de visualizar e iniciar o design de software.

A definição de um produto raramente é fixa desde o início, então é comum revisar e refinar ideias continuamente. Uma vez esboçadas as funções do produto, pode-se começar a pensar na arquitetura de software, em conjunto com os engenheiros de hardware, entretanto, o foco de cada um pode ser diferente.

**Início do Processo**

Existem duas abordagens para arquitetar sistemas: criar do zero ou decompor um produto existente. Ambas envolvem a criação de diagramas para entender o sistema; esses diagramas ajudam a visualizar a estrutura geral e manter a qualidade do código durante o desenvolvimento.

À medida que a compreensão do sistema se aprofunda, os diagramas tornam-se mais complexos. Simplificar esse processo agrupando funcionalidades em caixas maiores e detalhando-as em outros desenhos auxilia na gestão da complexidade.

**Criando Diagramas de Sistema**

Assim como os engenheiros de hardware criam esquemas, os desenvolvedores de software devem criar diagramas que mostrem as relações entre as várias partes do software. Estes diagramas ajudam a identificar dependências e a projetar novas funcionalidades. São recomendados quatro tipos de diagramas: de contexto, de blocos, organigramas e de camadas.

**Diagrama de Contexto**

Este diagrama oferece uma visão de alto nível de como o sistema será usado pelo cliente, focando nas relações entre o dispositivo, usuários, servidores e outros dispositivos. Ajuda a definir requisitos do sistema e visualizar possíveis mudanças.

Exemplo:

- Quais problemas o sistema resolve?
- Quais são as entradas e saídas do sistema e dos usuários?

**Diagrama de Blocos**

Este diagrama modela o software em torno dos elementos físicos do sistema. Cada chip conectado ao processador é representado como um objeto. Por exemplo, o uso de memória flash conectada via SPI é ilustrado com uma caixa de memória flash fora do processador e uma caixa SPI dentro do processador.


Ao adicionar funcionalidades de alto nível, como armazenamento de bitmaps para uma tela, o diagrama evolui para incluir esses elementos, identificando objetos de comunicação e componentes externos.


**Organigramas**

Este diagrama funciona como um organograma de empresa, mostrando hierarquias onde componentes de alto nível controlam os de baixo nível, que fornecem informação e notificam erros. Ele ajuda a entender o controle e as dependências no sistema.

Por exemplo, ao integrar números de série em produção, considera-se o uso da memória flash existente em vez de adicionar um novo chip, evitando complexidade de hardware adicional.


**Diagrama de Camadas**

Representa objetos por tamanho estimado, agrupando recursos usados juntos. Cria-se uma abstração de hardware que facilita a gestão de camadas e dependências.


**Projetando para Mudança**

Tendo diferentes desenhos de arquitetura, é importante considerar quais partes do sistema mudarão com o tempo. A encapsulação de módulos ajuda a isolar dependências para facilitar alterações futuras. Alguns pontos incluem:

- Agrupar objetos usados juntos (e.g., diagramas de camadas).
- Verificar interdependências e simplificar ou juntar dependências.
- Manter interfaces simples para facilitar a reutilização.

**Padrões de Projeto e Delegação de Tarefas**

Usar padrões de projeto, como Adapter, facilita mudanças na interface de drivers sem alterar o software de alto nível. Isso é essencial para a manutenabilidade e portabilidade. Diálogos claros nos diagramas ajudam a delegar tarefas específicas a desenvolvedores, permitindo divisões de trabalho eficientes.


**Interfaces e Logging**

A criação de boas interfaces e sistemas de logging robustos é crucial. A interface de Logging deve ser flexível para diferentes implementações, permitir níveis de prioridade para depuração e ser encapsulada para não depender da implementação subjacente.

Exemplo de interface de logging:

```c
void Log(enum eLogSubSystem sys, enum eLogLevel level, char *msg);
void LogWithNum(enum eLogSubSystem sys, enum eLogLevel level, char *msg, int number);
void LogSetOutputLevel(enum eLogSubSystem sys, enum eLogLevel level);
```

**Projeto Orientado a Objetos**

Mesmo em C, é possível adotar conceitos de programação orientada a objetos para encapsular dados. Variáveis globais são desencorajadas, preferindo-se estruturas estáticas para simular variáveis privadas.

**Singleton Pattern**

O padrão Singleton garante uma única instância de uma classe, útil para recursos compartilhados como portas seriais, evitando conflitos ao acessar o mesmo recurso.

```c
static struct sLogStruct gLogData;
struct sLogStruct* LogInternalState() {
    return &gLogData;
}
```

**Sandbox e MVC**

Usar o padrão Model-View-Controller (MVC) permite isolar a lógica do algoritmo da interface de usuário e hardware, facilitando o desenvolvimento independente e testes.

**Revisando os Diagramas**

Os quatro tipos de diagramas ajudam na compreensão e comunicação do sistema:

- Contexto: Visão geral e requisitos do sistema.
- Blocos: Peças do hardware e software.
- Organigramas: Controle e conflitos de acesso aos recursos.
- Camadas: Interfaces e abstração de hardware.

Cada diagrama deve manter uma visão de alto nível e detalhes específicos podem ser detalhados em páginas separadas para evitar complexidade excessiva.

Essa abordagem modular e documentada ajuda a navegar pelos desafios do desenvolvimento de sistemas embarcados, tornando o design mais robusto e flexível para mudanças futuras.

## 3. Trabalhando com o Hardware

**Integração Hardware/Software**

Iniciar no desenvolvimento de sistemas embarcados pode ser um desafio. Engenheiros de software geralmente precisam aprender noções básicas de engenharia elétrica, e vice-versa. Colaborar estreitamente com profissionais da outra área facilita a transição. Projetos começam como ideias ou necessidades que, ao serem desenvolvidas, resultam em um design de produto baseado em funcionalidades, custo e tempo de mercado. Um cronograma define marcos e atividades principais.


**Projeto Ideal**

Cronogramas baseiam-se em estimativas de líderes técnicos sobre tempo e recursos necessários. No entanto, imprevistos e revisão de planos são comuns. A função dos cronogramas é identificar dependências e preparar para possíveis obstáculos.

**Design de Hardware**

A equipe de hardware escolhe componentes após revisar datasheets e referências, frequentemente consultando a equipe de software. Kits de desenvolvimento são adquiridos para as partes mais arriscadas. Enquanto a equipe de hardware cria esquemáticos, a de software trabalha em ferramentas, debuggers e sandbox para testes.

Uma vez completo o esquemático (e verificando-se a adequação dos componentes), a placa é projetada e enviada para fabricação. Durante esse período, a equipe de software define e escreve testes de hardware, prioritizando componentes mais críticos conforme indicado pelos engenheiros eletrônicos.

**Inicialização da Placa**

Receber a placa pode revelar inúmeros bugs, pois ao contrário do software, as placas não permitem muitas iterações de testes. Encontrar bugs cedo é crucial; a colaboração e a habilidade de programação são essenciais para resolver problemas. Não se envergonhe ao receber feedback, agradeça-o, pois isso evita que bugs cheguem aos clientes.

Para facilitar a inicialização, cada componente deve ser testado individualmente. Testes independentes são críticos, permitindo que qualquer membro da equipe reproduza problemas e proponha soluções.

**Lendo um Datasheet**

Datasheets são manuais de API para periféricos, essenciais para entender os componentes. Eles não são escritos para você, mas para engenheiros elétricos experientes. Comece pelas descrições funcionais e diagramas, depois passe para seções relevantes como informações de aplicação e operação teórica. Evite seções como condições operacionais recomendadas e características elétricas inicialmente.


Seções como pinout e descrições de pinos são úteis posteriormente para depurar problemas específicos. Características de desempenho e esquemáticos de amostra também são importantes quando o componente não funciona como esperado.

**Avaliando Componentes com o Datasheet**

Quando for escolher componentes, verifique critérios de projeto, como limites máximos e características elétricas. Se o componente não atender a seus critérios, descarte-o rapidamente.

**Processador: A Linguagem do Software**

O processador é o componente mais importante, com diferentes fornecedores oferecendo variados periféricos. A mudança entre diversos processadores pode ser complexa, mas exemplos de código e manuais de usuário ajudam na transição.

**Leitura de Esquemáticos**

Esquemáticos podem parecer complexos, mas concentre-se nos maiores componentes e suas conexões. Isso ajuda a localizar periféricos importantes.

**Manutenção da Placa**

Manusear hardware incorretamente pode causar danos; use materiais antiestáticos e peça sempre placas sobressalentes. Uma placa reserva ajuda em testes e evita que você fique sem uma placa para continuar o desenvolvimento.

**Ferramentas de Depuração**

Ter um conjunto de ferramentas de depuração no seu espaço de trabalho dá independência e segurança ao manejar a placa. Essas ferramentas incluem alicates de bico fino, cabos jumper e analisadores lógicos.

**Testando Hardware e Software**

Existem três tipos comuns de testes para sistemas embarcados: Power-On Self-Test (POST), testes de unidade e testes de inicialização. O POST verifica componentes principais durante a inicialização. Testes de unidade automatizam a verificação de funcionalidades, enquanto testes de inicialização são mais específicos a subsistemas particulares.

**Construindo Testes**

Testes de hardware frequentemente são escritos enquanto o esquemático está sendo completado. Considere parâmetros como endereços de memória, ponteiros e comprimentos ao criar testes.

**Exemplo de Teste de Memória Flash**

Memória flash, um tipo de memória não volátil, funciona de maneira particular e requer sequências específicas de leitura e escrita para ser testada corretamente:

Exemplos de funções em C:

```C
int FlashTest(uint32_t address, uint8_t *memory, uint16_t memLength);
uint16_t FlashRead(uint32_t addr, uint8_t *data, uint16_t dataLen);
uint16_t FlashWrite(uint32_t addr, uint8_t *data, uint16_t dataLen);
```

Teste 1: Ler Dados Existentes

```C
dataLen = FlashRead(startAddress, memory, memLength);

if (dataLen != memLength) {
  Log(LogUnitTest, LogLevelError, "Flash test: truncation on byte read");
  memLength = dataLen;
  error++;
}
```

Teste 2: Acesso a Byte

```C
FlashEraseSector(startAddress);
addValue = 0x55;
for (i = 0; i < memLength; i++) {
  value = i + addValue;
  dataLen = FlashWrite(startAddress + i, &value, 1);
  if (dataLen != 1) {
    Log(LogUnitTest, LogLevelError, "Flash test: byte write error.");
    error++;
  }
}
```

Teste 3: Acesso a Bloco

```C
FlashEraseSector(startAddress);
dataLen = FlashWrite(startAddress, memory, memLength);
if (dataLen != memLength) {
  LogWithNum(LogUnitTest, LogLevelError, "Flash test: block write error", dataLen);
  error++;
}
```

**Conclusão dos Testes**

Se a placa passa nesses testes, a confiança no hardware e software aumenta, satisfazendo a necessidade de testes de inicialização e unidade.

**Padrões de Projeto e Testes de Software**

Usar o padrão de comando facilita implementar testes repetitivos durante a inicialização. Crie comandos como "versão do código", "teste de flash" e "piscar LED" para testar funcionalidades sem recompilar constantemente.

**Interface de Comandos**

Um exemplo de estrutura de comando em C pode ser:

```C
typedef void(*functionPointerType)(void);
struct commandStruct {
  char const *name;
  functionPointerType execute;
  char const *help;
};
```

Tabela de comandos:

```C
const struct commandStruct commands[] = {
  {"ver", CmdVersion, "Display firmware version"},
  {"flashTest", CmdFlashTest, "Runs the flash unit test, prints number of errors upon completion"},
  {"blinkLed", CmdBlinkLed, "Sets the LED to blink at a desired rate (parameter: frequency (Hz))"},
  {"help", CmdHelp, "Prints out help messages"},
  {"", 0, ""} // End of table indicator. MUST BE LAST!!!
};
```

**Manipulação de Erros**

Erros devem ser tratados de modo seguro, seja degradando a funcionalidade ou falhando de forma clara e imediata. Funções devem lidar com erros corrigindo valores fora do intervalo e retornando códigos de erro. Uso do assert() e instruções de ponto de quebra (BKPT) ajudam na depuração.

Exemplo de macro BKPT:

```C
#define BKPT() __asm__("BKPT")
```

**Biblioteca de Manipulação de Erros**

Uma biblioteca de erros pode ser útil:

```C
void ErrorSet(int *errorCode, int error);
```

Uso em sequência de chamadas:

```C
ErrorSet(&globalErrorCode, FunctionFoo());
```

**Depuração de Erros de Temporização**

Erros de temporização podem ser difíceis de detectar e depurar devido à alteração da temporização por saídas seriais ou pontos de interrupção. O uso de buffers circulares ajuda a capturar eventos importantes sem prejudicar a temporização.

Com esses conceitos e técnicas, o engajamento com hardware e software em sistemas embarcados torna-se mais eficiente e gerenciável, contribuindo para o desenvolvimento de produtos de alta qualidade e confiança.

## 4. Entradas, Saídas e Temporizadores

Os sistemas embarcados operam principalmente com entradas, saídas e temporizadores. Compreender esses elementos é essencial para o desenvolvimento eficiente de sistemas. Vamos explorar desde um sistema simples de piscar luzes até conceitos mais complexos como debouncing de botões e controle de brilho de LEDs, destacando o papel crucial dos temporizadores.

#### Lidando com Registradores

Para interagir com uma linha de I/O, é necessário manipular registradores. Esses registradores funcionam como a interface de programação de aplicativos (API) do hardware descrita no manual do chip. São mapeados na memória, permitindo a leitura e escrita de endereços específicos para modificar registradores específicos. Como cada bit no registrador representa uma função distinta, a capacidade de manipular números binários e hexadecimais é fundamental. Por exemplo, números hexadecimais são frequentemente usados por serem mais fáceis de visualizar em memória e mais simples para representar múltiplos bits.

**Operações Bit a Bit**

Manipular registradores exige operações bit a bit, como AND, OR, NOT e XOR. Cada operação bit a bit manipula bits específicos, possibilitando testes, configurações, limpezas ou alternâncias de bits de maneira eficiente:

- **AND** ajuda a testar se um bit está definido.
- **OR** permite definir um bit.
- **NOT** é usado para limpar um bit.
- **XOR** alterna o estado de um bit.

Por exemplo, para verificar se um bit específico em um registrador está definido, utilizamos a operação AND bit a bit. Para definir um bit, utilizamos a operação OR, enquanto a operação NOT combinada com AND é usada para limpar um bit específico. A operação XOR pode alternar o estado de um bit, uma funcionalidade útil em diversas aplicações, como gráficos de computador e detecção de overflow em cálculos.

**Operações nos Pinos**

Para fazer um LED piscar, é necessário definir o pino correspondente como saída e ativá-lo. Isso envolve a configuração da direção do pino e, em seguida, definir seu estado alto ou baixo. A alterantiva simples seria configurar o pino:

```c
*((int*)0x0070C1) |= (1 << 2);
```

No entanto, a prática recomendada é utilizar bibliotecas e cabeçalhos fornecidos pelo fabricante do processador para abstrair esse mapeamento de memória. Isso facilita a manutenção e a portabilidade do código entre diferentes arquiteturas e versões do hardware.

**Temporizadores e Precisão**

Os temporizadores são contadores que medem o tempo por meio de ticks de clock. Eles operam independentemente do software, permitindo precisões temporais sem sobrecarregar a CPU. A configuração dos temporizadores requer ajustar registradores como contadores, comparadores, prescalers e ações específicas, como interrupções. Configurar um temporizador envolve:

- **Counter register (contador):** Armazena o valor corrente do temporizador.
- **Compare register:** Define quando uma ação é realizada, como gerar uma interrupção.
- **Prescaler register:** Ajusta a velocidade do clock.
- **Control register:** Inicializa e controla o temporizador.
  
Um exemplo prático é configurar um temporizador para gerar uma interrupção a cada 0,1 segundos (10 Hz), o que pode ser obtido ajustando o prescaler e o comparador adequados.

**Debouncing de Botões**

Botões físicos podem gerar múltiplos sinais digitais devido a efeitos mecânicos ou elétricos. O debouncing é a técnica usada para eliminar esses sinais espúrios, criando leituras consistentes dos estados dos botões. Isso pode ser feito tanto por hardware quanto por software. Em software, o debouncing envolve a leitura repetida do estado do botão várias vezes em intervalos curtos e só considerar o estado modificado se todas as leituras consecutivas forem consistentes. O objetivo é garantir que a leitura do botão represente uma ação de pressionar ou soltar genuína, não ruídos de contatos.

**Modulação por Largura de Pulso (PWM)**

PWM controla a duração em que um pino permanece alto ou baixo, influenciando o brilho de LEDs ou a velocidade de motores. Utiliza temporizadores e registradores de comparação para ajustar a frequência e o ciclo de trabalho (duty cycle).

**Configuração e Utilização de PWM**

A configuração de PWM envolve definir registradores de comparação para controlar a frequência de chaveamento e a duração do sinal alto ou baixo. Com PWM, o processador pode ajustar a quantidade de energia que um dispositivo (como um LED) recebe ao variar a duração do estado ligado e desligado em um ciclo.

**Configuração de GPIO**

Exemplo:

```c
typedef struct
{
__IO uint32_t CRL; // Configuração do porta (baixo)
__IO uint32_t CRH; // Configuração do porta (alto)
__IO uint32_t IDR; // Registrador de dados de entrada
__IO uint32_t ODR; // Registrador de dados de saída
__IO uint32_t BSRR; // Registrador de set/reset de bits
__IO uint32_t BRR; // Registrador de reset de bits
__IO uint32_t LCKR; // Configuração de lock do porta
} GPIO_TypeDef;
```

**Separando o Hardware da Ação**

Modificações em projetos de hardware podem requerer alterações nos pinos utilizados. Para facilitar essas mudanças, é útil abstrair a configuração dos pinos num arquivo de cabeçalho específico do board, evitando hardcoding e mantendo a flexibilidade do código.

```c
#define LED_SET_DIRECTION (P1DIR)
#define LED_REGISTER (P1OUT)
#define LED_BIT (1 << 3)
```

Essa prática facilita a adaptação a novas versões do hardware sem a necessidade de modificações extensivas no código. Além disso, usar uma camada de abstração (HAL) permite que o código principal seja mais genérico e reutilizável.

**Injeção de Dependência e Padrão Facade**

A injeção de dependência remove a dependência do código de hardware específico, permitindo que as variáveis sejam passadas em tempo de execução. O padrão Facade, por outro lado, esconde detalhes de implementação, proporcionando uma interface simplificada.

Por exemplo, um módulo de LED pode depender de um manipulador de pinos I/O que é passado como parâmetro. Isso torna o código do LED mais genérico e reutilizável em diferentes contextos, sem conhecimento dos pinos específicos que está manipulando.

```c
typedef struct
{
  void (*setPinHigh)();
  void (*setPinLow)();
} IO_Handler;

void initLED(IO_Handler* handler) {
  handler->setPinHigh();
}
```

**Conclusão: Otimização e Flexibilidade**

Desenvolver um produto final requer várias iterações e a exclusão de funcionalidades prototípicas. Embora a flexibilidade inicial do código (como injeção de dependência) seja útil, a simplificação e a clareza são essenciais para a manutenção a longo prazo. A experiência e o aprendizado adquiridos durante o desenvolvimento são valiosos, mesmo que partes do código sejam descartadas. Dessa forma, equilibrar flexibilidade e manutenibilidade do código é crucial para o sucesso de sistemas embarcados, garantindo que o produto final seja eficiente, sustentável e adaptável a futuras necessidades.
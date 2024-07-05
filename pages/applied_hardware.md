# Applied Hardware

## Contents

[1. Essential Concepts](#1-essential-concepts)

[2. Architecting the Hardware](#2-architecting-the-hardware)

[3. Communicating](#3-communicating)

## 1. Essential Concepts

#### Introduction to Electronics
Understanding the basics of electronics is crucial for hardware development in embedded systems. Real-world components often exhibit non-ideal behaviors that can significantly impact design and performance. Designers must be aware of these limitations to craft robust solutions effectively.

#### Ideal Simplifications of Academia
Most electronic systems today are digital, but analog challenges still prevail. Common problems include noise, signal integrity issues, power instability, electromagnetic interference (EMI), and connection impedance.

Simplified academic models can provide a quick understanding but often leave out critical details. These omissions, can profoundly affect the device's performance. A comprehensive understanding of these more detailed models is necessary to enhance design quality.

#### Interconnections
Even seemingly insignificant elements, like a short wire, can have considerable impedance. For instance, wire impedance and its capacitance can act as a low-pass filter (LPF) above 300–400 MHz and be sensitive to motion. For printed circuit boards (PCBs), similar issues arise, where traces can also act as LPFs due to increased capacitance.

An effective design must account for impedance in every connection, considering its interaction with the external environment. High currents, long connection paths, and high frequencies necessitate careful interconnection design to avoid phase errors and other imperfections.

#### Basic Components

#### Capacitors
Modern capacitors exhibit trade-offs in capacitance per unit volume, breakdown voltage, operating temperatures, and more. Class 1 capacitors (e.g., C0G, NP0) prioritize minimal thermal variance and voltage bias changes, whereas Class 2 capacitors (e.g., X5R, X7R) achieve higher capacitance with less accuracy and stability. 

Key considerations include nominal value, tolerance, breakdown voltage, package size, dielectric type, ESL characteristics, and reliability.

#### Resistors
Resistors should ideally have a flat impedance over frequency, but high frequencies can introduce issues via Equivalent Parallel Capacitance (EPC) and Equivalent Series Inductance (ESL). Most modern resistors are film-based, offering lower noise compared to older carbon-based resistors.

Significant attributes include material composition, power rating, temperature range, voltage rating, and stability over time.

#### Inductors
Inductors are vital in power conversion, RF signal processing, and EMI limiting. Their ESR affects power efficiency and performance in filters. Important parameters include component value, SRF, current rating, temperature range, and whether the inductor is shielded or unshielded.

#### Voltage Sources and Batteries
No ideal voltage source exists. Real voltage sources like batteries or voltage regulators have limitations such as capacity variations and noise generation. Batteries degrade over time and their performance varies with temperature and usage.

#### Current Sources
Current sources also face practical restrictions, typically limited in voltage range to maintain fixed current behavior.

#### Switches and Relays
Mechanical switches and relays can introduce problems like contact bounce, which requires software debouncing for stable state detection in logic ports.

#### Operational Amplifiers
An ideal op-amp model suggests infinite gain and bandwidth, but real op-amps have limitations like power supply requirements, output impedance, gain limits, and sensitivity to noise. Specific performance characteristics depend on the selected op-amp.

#### Voltage Comparators
Unlike op-amps, comparators operate outside feedback loops and have high gain with no internal frequency compensation, making their output digital.

#### Nonideal Digital Devices
Even digital systems aren't immune to nonideal behaviors. Issues such as false state generation can arise due to timing relationships and analog characteristics of digital signals. High data rates, transmission path resistance, and capacitance loading contribute to signal degradation.

Violation of voltage limits or improper timing can lead to system failure. High-frequency communications often require differential signals to mitigate ground reference issues.

#### Signal Integrity
Electronic systems can produce unwanted electronic noise, leading to radiated emissions and internal crosstalk. Regulatory bodies like the FCC impose limits on EMI to prevent interference between devices.

Noise coupling within a system, often called crosstalk, can be capacitive or magnetic and needs to be carefully managed.

#### Summary and Conclusions
In hardware development for embedded systems, several critical points must be considered:

- Academic models simplify but may omit crucial details.
- All connections have impedance, affecting voltage stability and integrity.
- Phase errors can occur even with common signal distribution.
- Capacitors and resistors have complex behaviors influencing performance.
- Inductors, voltage and current sources, and switches have their own nonideal characteristics.
- Op-amps and comparators come with limitations that influence design choices.
- Digital devices and systems must manage nonideal behaviors and signal integrity issues.
- Signal integrity is paramount to prevent noise and interference within and between systems.

Understanding these complexities helps build awareness and improve design strategies, aiming to mitigate failures and optimize performance in embedded systems development. While learning from experience is invaluable, proactively addressing these issues can save significant time and effort in the long run.


## 2. Architecting the Hardware

When it comes to developing hardware for embedded systems, it is crucial to define the key parts of the system at the box level and discuss the implementation of digital control at the core. It is also important to understand the criteria for selecting a digital control unit (DCU) and choosing the right microcontroller (MCU).

To ensure a successful approach to developing a commercial product, there are certain preliminary ideas that need to be clarified.

#### Simulate or Build

Creating a full simulation of an entire embedded controller system is generally unnecessary. The digital controller code can be simulated within the integrated design environment (IDE) to ensure the control signals function correctly. However, simulating peripheral functions created by those control signals is often not needed. Building a first-generation PCB is a low-cost and efficient way to quickly debug a real product. Simulating the device is unnecessary in most cases. For MCUs with simple peripherals, a development/demo board can also be a viable option.

#### Through-Hole/Leaded Components (Obsolete)

Circuit components with pins or wires that go through holes in the PCB, known as through-hole or leaded components, are suitable for manual assembly and hobbyist projects. However, these components are not suitable for automated assembly or high-frequency circuits. Leaded components are generally larger compared to their surface mount counterparts.

#### Discrete Gate Logic (Obsolete)

The 7400 logic series, developed in the mid-1960s and still in production today, consists of integrated circuits with four to six logic gates per chip. However, this chapter focuses on modern methods that utilize programmed devices and code-driven logic functions. Singular digital devices should be seen as level shifters and buffer drivers.

#### Modern Design Strategies

Modern design strategies aim to minimize the use of analog circuitry whenever possible. Implementing analog band-pass filters, for example, can present several issues such as the need for high-quality capacitors with accurate and linear characteristics. Nonideal operational amplifiers (op-amps) also contribute noise, distortion, and DC signal offset. A low-cost and repeatable solution involves using an analog-to-digital converter (ADC) followed by a digital signal processor (DSP)-defined filter.

Converting analog signals into digital format offers benefits such as mitigating noise, distortion, and signal integrity concerns. Digital data streams are less susceptible to environmental noise and can be easily transmitted over long distances, even in electromagnetic interference (EMI) environments.

Control systems also benefit from digital methods, as modern control feedback systems combine analog characteristics with digital processing. These systems utilize digital signal processors (DSP) to achieve optimal control.

#### Mostly Digital Design

The concept of a mostly digital system involves converting any analog signal into a digital-equivalent data stream, processing the data using digital methods, and converting it back to analog format only if necessary. This approach, often referred to as a mixed-signal approach, allows for the creation of various mathematical and input/output relationships within a digital signal processing (DSP) system.

#### DSP Methods: Versatility and Limits

Improving signal-to-noise performance in DSP requires utilizing analog-to-digital converters (ADCs) with higher resolution, which allows for more accurate signal sampling. However, ADC design has certain limitations, such as the trade-off between conversion rate, power consumption, and number of bits. Achieving a fast converter with a large bit count and low power consumption can be challenging.

#### Digital Control Methods: DCU, MCU, MPU, FPGA, CPLD, and ASIC

An embedded system or embedded controller system is an electronic or electromechanical system that utilizes a digital controller to control and sense various components. The digital control unit (DCU) can take the form of a microcontroller (MCU) or microprocessor unit (MPU). Additionally, other specialized digital methods, such as field-programmable gate arrays (FPGA), complex programmable logic devices (CPLD), or digital application-specific integrated circuits (ASIC), can be employed for specific control requirements.

Digital control can be implemented using either hardware-based solutions, such as a Boolean state machine, or software-based solutions in the form of code written for a computer. Code written for and downloaded into an MCU is commonly referred to as firmware.

Unlike multipurpose computers, embedded systems are purpose-built and typically have a fixed programming. However, they often require monitoring capabilities. For example, a motor driver controller PCB may utilize an MCU to control three stepper motors while also incorporating a sensor for monitoring motor speed. Communication with a remote manager can be achieved through a serial port bus.

#### Terminology in MCU and MPU Specifications

Understanding the terminology used in microcontroller unit (MCU) and microprocessor unit (MPU) specifications is essential for selecting the right device:

- **Harvard Architecture:** A Harvard architecture CPU uses separate data-address buses for instruction memory and data memory. Most MCU devices utilize the Harvard architecture.

- **Princeton Architecture (Von Neumann Architecture):** A Princeton architecture CPU uses common address-data buses for both instruction memory and data memory.

- **RISC (Reduced Instruction Set Computer):** RISC CPUs have a limited instruction set, reducing the complexity of the physical design. Instructions and resulting data are often pipelined in RISC devices. Most MCU devices are RISC devices.

- **CISC (Complex Instruction Set Computer):** A CISC processor executes more complex instructions than a RISC device. The compiler for a RISC device breaks down complex instructions into simpler ones suitable for the RISC instruction set. Most present-day processors use RISC architecture, except for Intel's X86 devices.

- **X86 Processor:** The X86 architecture includes Intel's 8086, 80186, 80286, 80386, 80486, and other processors. Generally, X86 devices are not used in MCUs within embedded systems.

- **ARM (Advanced RISC Machine or Acorn RISC Machine):** ARM is a series of RISC processors with 32-bit data and 26 or 32-bit addressing. ARM Holdings licenses ARM processors as intellectual property to semiconductor manufacturers who add peripheral support devices to create finished MCUs.

- **MIPS (Microprocessor without Interlocked Pipeline Stages):** A MIPS processor is a RISC processor that uses a pipelined architecture. MIPS devices excel at streaming data processing and are available from multiple vendors as standalone MPUs or integrated by semiconductor manufacturers into their chips.

- **PIC, AVR, and ATmega:** These are different families of microcontrollers that started as 8-bit Harvard architecture RISC processors but have expanded their product lines to include higher-performance devices.

#### Hardware Controllers

Hardware-based controllers include programmable array logic (PAL), programmable logic device (PLD), complex programmable logic device (CPLD), field-programmable gate array (FPGA), and digital application-specific integrated circuits (ASIC).

PAL and PLD are programmable logic arrays, where PAL devices have fewer pins (usually 28 or less) and are compatible with 5V interfaces, often used with through-hole mounting. PLD devices are smaller variants of CPLDs.

CPLDs are programmable logic devices that range in size from 20 input/output ports to over 200. They utilize a programmable interconnect on a field of gates or macrocells.

FPGAs are highly versatile and can range in size from 10 input/output ports to over 1,900. They utilize programmable lookup tables to create complex, large array, dedicated logic.

Digital ASICs cannot be programmed and require a functional digital design to be worked out using another platform before fabrication. They are suitable for high-volume products that require fast logic.

Hardware-based controllers are suitable for scenarios where fast dedicated logic is required. However, software-based controllers, such as MCUs and MPUs, are commonly employed as they offer a wider range of features and flexibility.

#### Software Controllers

Software or firmware-based controllers rely on devices such as microcontrollers (MCUs) and microprocessor units (MPUs). The differentiation between MCUs and MPUs can be blurred, with MCUs often having more features to make them self-sufficient, although there can be significant feature overlap between the two.

MPUs tend to have external random-access memory (RAM) and read-only memory (ROM), emphasizing their ability to interface with external memory and peripherals. On the other hand, MCUs include all the necessary features to function with minimal external support. They typically have internal RAM and ROM, serial communication interfaces (UART, SPI, I2C, and CAN), as well as analog-to-digital converter (ADC) and digital-to-analog converter (DAC) capabilities.

Software-based controllers provide greater flexibility and can be programmed to adapt to various applications.

#### Computers Versus Controllers

Single-board computers are designed to interface with typical computer peripherals, while MCU boards are optimized to interface with other integrated circuits (ICs) and provide stimulus/response through individual ports. MCU boards are purpose-built for the specific control tasks required.

#### System Architecture Options

MCUs and MPUs are incredibly versatile and find applications in various scenarios. There may be embedded systems where the presence of an MCU is not immediately evident, as they control and monitor specific functions within a device.

When designing a system, it is important to determine all the peripherals that need to be controlled or sensed. This requires careful consideration of all the necessary interconnects.

Serial communication ports (SerCom) should be carefully configured to avoid bottlenecks. For example, a single I2C interface can have multiple devices attached, but the overall traffic through the port should be analyzed to prevent congestion.

Direct memory access (DMA) capabilities can significantly enhance data transfer between memory blocks or memory and an external port. Designers should consider the potential benefits when moving large blocks of data.

For implementing digital signal processing (DSP), designers can choose between hardware-based or software-based solutions. The choice depends on factors such as the sampling rate, clock rate of the DCU, and complexity of the DSP algorithm. Additionally, it is important to identify any potential DSP bottlenecks, considering extreme scenarios involving low and high data rates.

To determine the needed internal features of the DCU, it is necessary to consider the requirements of the specific application. This may include general-purpose input/output (GPIO) ports, various serial communication interfaces, internal ADC and DAC capabilities, comparators, real-time clocks (RTCs), clock generation systems, power consumption, programmable memory (flash memory), RAM size, interrupt handling capability, floating-point math capability, power-on reset and brownout detection reset, direct memory access capability, watchdog timers (WDT), and timer counter circuits (TCC).

#### Physical Package Considerations

There are various package options available for DCUs, ranging from traditional larger packages to smaller form factors. Designers need to consider the physical constraints and requirements of their specific applications when selecting an appropriate package.

#### Picking a DCU Configuration and MCU/MPU

To make an informed decision when selecting a DCU, designers should consider specialized niche functions or features, whether they are developing multi-MCU systems or general-use MCU systems. It is recommended to pick a manufacturer first and then select a specific MCU or MPU within the preferred product line. Ease of use and a robust support infrastructure are often more important than selecting a specific device. It is also advisable to consider future design changes and desired product features, which may necessitate extra capabilities such as additional ports, memory, and processing power. Opting for an MCU or MPU with some excess capability can be a wise strategy for a first-generation build.

In summary, developing hardware for embedded systems involves adopting modern design strategies, choosing between hardware and software controllers, understanding the relevant terminologies, considering system architecture options, and carefully selecting DCU configurations and MCU/MPU devices. By following these guidelines, designers can create robust and efficient embedded systems.

## 3. Communicating

Digital communication is foundational in embedded systems, ensuring the seamless transfer of data across various components. This guide delves into essential technical aspects and methodologies for establishing reliable and efficient communication in embedded systems.

#### Ground-Referenced Digital Signals and Their Limitations

Digital signals, when referencing a common ground, face several challenges. Factors like noise, amplitude loss, and impedance mismatches can significantly degrade signal integrity, especially as connections lengthen or data rates increase. 

#### Differential Signaling: A Solution to Ground-Referenced Challenges

Using low-voltage differential signaling (LVDS) can mitigate many issues faced by ground-referenced signals. LVDS, with its differential nature, offers resilience against noise and better integrity over long distances and high speeds. This method is widely adopted in communication protocols like Ethernet, USB, and PCI Express.

#### Organizing Interconnects for Optimal Performance

For low-speed data transfer (<10 MB/sec) over short distances (<25 cm), organizing connections with careful consideration is essential but generally straightforward. Key factors include ensuring consistent impedance and avoiding unterminated transmission lines.

#### Clock Distribution

Clock distribution becomes more complex with higher frequencies. Ensuring minimal jitter and skew is crucial, especially for high-speed data systems operating, for example, with a PCIe interface at 100 MHz. Proper clock distribution methods and device specifications for edge transitions are necessary for maintaining signal integrity.

#### Parallel vs. Serial Communication

Parallel communication, once prevalent, has largely been replaced by serial communication due to the high pin count and complexity. Serial communication, requiring fewer connections, is more efficient and cost-effective, particularly in high-speed data transfers.

#### Clocking Methods for Serial Ports

To maintain synchronization between the transmitter (TX) and receiver (RX), various clocking methods are used:

1. **Starting Edge Synchronization:** Suitable for slow and short fields.
2. **Parallel Clock:** Requires additional connections and maintaining the clock/data phase relationship.
3. **Manchester Code Self-Clocking:** Uses transition encoding, helpful in maintaining timing without a reference clock.
4. **Embedded Clocking:** Utilizes PLL for clock recovery from data streams, often employed in high-speed systems.

#### Understanding Key Terminologies in Digital Communication

- **Data Rate:** The amount of data transmitted per unit time, often measured in bits or bytes per second.
- **Addressing:** Defines the destination of data, critical in multi-device systems.
- **Data Integrity:** Ensures error-free data transmission, particularly as distances and data rates increase.
- **Protocol:** Governs how data is formatted and transmitted, including methods for error checking, acknowledgments, and handshaking.
- **Simplex, Half-Duplex, and Full-Duplex:** Defines the directionality of communication, with simplex being one-way, half-duplex allowing bidirectional but not simultaneous communication, and full-duplex supporting simultaneous bidirectional data flow.

#### Serial Data Communication Examples

#### UART (Universal Asynchronous Receiver Transmitter)

UART is a simplified method for serial data transfer, commonly utilizing start edge synchronization. It’s a full-duplex, point-to-point connection with a typical data rate up to 1 Mbit/s but lacks sophisticated error checking mechanisms.

| Parameter  | Performance               |
|------------|----------------------------|
| Connection | Full-duplex, point-to-point |
| Data rate  | Up to 1 Mbit/s             |
| Addressing | None                      |
| Validation | Minimal (parity bit)      |
| Medium     | Wired                     |
| Distance   | Limited to PCB            |

#### I2C (Inter-Integrated Circuit)

I2C is a multi-device, half-duplex communication method using two wires: clock (SCL) and data (SDA), managed through a simple protocol. Ideal for settings where devices share a common ground.

| Parameter  | Performance                     |
|------------|----------------------------------|
| Connection | Multidrop, half-duplex           |
| Data rate  | Up to 3.4 Mbit/s                 |
| Addressing | 7 or 10-bit                      |
| Validation | Acknowledgment but no error checking |
| Medium     | Wired (PCB)                      |
| Distance   | Limited to PCB                   |

#### SPI (Serial Peripheral Interface)

SPI allows higher speeds compared to I2C by using separate lines for clock (SCLK), data (MOSI/MISO), and device selection (SS), making it a suitable choice for streaming data applications.

| Parameter | Performance                         |
|-----------|--------------------------------------|
| Connection | Full-duplex, single manager with multiple subordinates |
| Data rate  | Up to 10 Mbit/s                     |
| Addressing | None (SS pin used)                  |
| Validation | No error check                      |
| Medium     | Wired                               |
| Distance   | Limited to PCB                      |

#### High-Speed Serial Communication and SerDes

Serializer and deserializer (SerDes) interfaces support high-speed data transfers without standardization, often embedding clock signals for synchronized communication. Suitable for high data rates requiring long distance without ground reference issues.

#### Data Communication Between Boards and Systems

#### RS-232 and RS-485

While RS-232 is obsolete, it laid the groundwork for serial communication standards. RS-485, on the other hand, uses differential signaling for better noise immunity and supports longer distances and higher data rates, making it a staple in industrial automation.

| Parameter  | RS-232               | RS-485                          |
|------------|-----------------------|---------------------------------|
| Connection | Point-to-point        | Multipoint                      |
| Data rate  | Up to 20 Kbit/s       | Up to 40 Mbit/s                 |
| Distance   | Up to 15 m            | Up to 1,200 m                   |
| Validation | Minimal               | Protocol dependent              |
| Medium     | Cable                 | Cable, twisted pair             |

#### CAN Bus (Controller Area Network)

Controller Area Network (CAN bus) is a robust protocol initially developed for automotive applications, now widely used in various industrial and embedded systems. It supports communication between multiple microcontrollers without the need for a host computer. 

CAN bus utilizes differential signaling (CAN_H and CAN_L), which provides improved noise immunity and ensures data integrity, making it suitable for harsh environments.

| Parameter | Performance                  |
|-----------|------------------------------|
| Connection | Multipoint, half-duplex      |
| Data rate  | Up to 1 Mbit/s               |
| Addressing | 11 or 29 bits                |
| Validation | CRC error checking           |
| Medium     | Twisted pair cable           |
| Distance   | Up to 40 meters              |

Key features of CAN bus include:

- **Message-Based Communication:** Each message has a unique identifier determining its priority.
- **Error Detection and Fault Confinement:** Employs multiple types of error checks, including CRC.
- **Arbitration:** Non-destructive bitwise arbitration ensures that the highest priority message is sent without collisions.
- **Real-Time Capability:** Excellent for systems requiring real-time communication.

#### Modern Serial Communication Protocols for Embedded Systems

#### USB (Universal Serial Bus)

USB has become ubiquitous in peripheral connections, providing both data transfer and power delivery capabilities, with multiple versions supporting up to 40 Gbit/s.

#### SATA (Serial Advanced Technology Attachment)

SATA connects mass storage devices with high-speed half-duplex communication, essential for internal computer storage solutions.

#### PCI Express (PCIe)

PCIe provides high-speed, full-duplex communication for internal computer components, using multiple lanes for scalable bandwidth.

#### Ethernet

Ethernet remains essential for LAN connections, supporting high data rates over long distances with built-in error checking and acknowledgment.

#### Wireless Communication Protocols

#### WiFi and Bluetooth

WiFi provides internet access at high data rates and moderate distances, while Bluetooth caters to low-power, short-range applications, with Bluetooth Low Energy (BLE) extending battery life for low-duty cycle devices.

#### ZigBee and Z-Wave

These protocols enable mesh networking for low-power, intermittent communication systems, ideal for IoT and home automation.


#### Infrared and Fiber-Optic Communication

Infrared supports short-range, line-of-sight communication, commonly used in remote controls. Fiber-optic, however, excels in high-speed and long-distance data transmission, forming the backbone of modern networks.

#### JTAG for Testing and Configuration

JTAG provides crucial testing and programming access for PCBs, enabling boundary scan testing and in-system programming for digital ICs.

#### Conclusion

In summary, designing robust digital communication systems for embedded devices requires careful consideration of signal integrity, appropriate choice between parallel and serial communication, and specific protocols suited for the application environment. Understanding signal nuances, network organization, and implementing suitable error-checking mechanisms are key to ensuring reliable and efficient data transfer in embedded systems.

The CAN bus stands out for its robustness and efficiency in harsh environments, making it invaluable in automotive and industrial applications where reliable, real-time communication is critical.

## 4. 
# Applied Hardware

## Contents

[1. Essential Concepts](#1-essential-concepts)

[2. Architecting the Hardware](#2-architecting-the-hardware)

[3. Communicating](#3-communicating)

[4. Power Systems](#4-power-systems)

[5. Battery Power](#5-battery-power)

[6. EMI and ESD](#6-emi-and-esd)

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

## 4. Power Systems

#### AC Power Safety: Defining the Problem

AC power is a crucial component when it comes to embedded systems. However, it is essential to ensure the safe implementation of AC power in a device to prevent accidents and system failures. AC power carries potential risks such as electric shock and device malfunction if not handled properly.

To ensure AC power safety, it is essential to consider the partitioning between high-voltage (HV) and low-voltage (LV) components. In most countries, power inlets below 50 V are classified as extra low voltage (ELV), simplifying safety requirements. Safety measures for HV components, such as AC/DC converters, are more stringent. One common method to ensure safety is enclosing both the AC/DC converter and the electronic system in a conductive metal enclosure with a safety ground tied back to the AC mains safety ground. This approach is widely used in desktop personal computers.

#### Safe Failure Methods and Overcurrent Protection

Besides operational safety, power systems also require safe failure methods. In the event of a failure, it is crucial to ensure that the system remains safe and protects the user from any potential danger. The concept of single fault safety is employed, where any element in the system can fail in an open or closed circuit state without causing harm.

Overcurrent protection is another vital aspect of power systems. It involves mechanisms to prevent excessive current flow that can lead to components overheating and failure. There are several commonly used methods for overcurrent protection:

1. Fuses: Fuses are simple and cost-effective but have limitations such as slow response time and the need for manual replacement.
2. Circuit breakers: Circuit breakers offer the convenience of being resettable but come with higher costs and larger size.
3. Polymeric positive temperature coefficient (PTC) resettable fuses: These devices limit the current by changing from a low-resistance to a high-resistance state when overloaded, providing a self-resetting capability.
4. Active circuit protection: These systems use detection circuits to monitor current and voltage and activate suitable controls to limit or shut down the power when necessary. They offer faster response times and accuracy but come with increased complexity and cost.

Regardless of the overcurrent protection method used, it is crucial to ensure that the protection device is the weakest link in the system. Proper design considers factors such as the maximum sustained and startup surge currents when setting the trip protection point.

#### AC/DC Conversion

While many electronic devices operate on direct current (DC) power, they often require AC power conversion. This conversion is typically performed by AC/DC converters. There are different approaches to AC/DC conversion, each with its advantages and disadvantages.

One classic approach is the use of transformers operating at the AC mains frequency, typically 60 Hz or 50 Hz. This method involves stepping down the AC voltage, rectifying it through a diode bridge, and filtering it to obtain a DC output. However, transformers operating at low frequencies like 60 Hz tend to be bulky and heavy. Higher frequencies, such as 400 Hz used in the aviation industry, allow for smaller and lighter transformers.

An alternative to transformers is off-line switchers, which use a switched-mode conversion method. These converters rectify the AC line voltage and rapidly switch it across the primary of a transformer at a much higher frequency, such as 10 KHz to 1 MHz. This approach offers advantages such as smaller transformers and output filter capacitors. Off-line switchers have become the preferred choice in consumer electronics due to their efficiency, compact size, and cost-effectiveness.

#### Multi-PCB Systems: Local Power Regulation

In multi-PCB systems, it is crucial to address the impedance and voltage variance in power and ground connections caused by dynamic current loads. To minimize these effects, local power regulation is necessary.

Many industrial systems distribute raw DC power at different voltages depending on the requirements of satellite PCBs. However, using a DC voltage directly from the PCB without local regulation can lead to inconsistencies, noise issues, and failure during regulatory testing. Therefore, it is advisable to regulate the power supply on the same PCB where it is utilized to maintain consistent and noise-free power.

#### DC/DC Conversion: Linear vs. Switching

Power regulators can be classified into linear regulators and switching regulators, each using different methods to provide a consistent voltage output.

Linear regulators use adaptive voltage division to regulate the output voltage. However, this method is inefficient since it dissipates energy inside the regulator, resulting in power inefficiency and potential thermal failures. Linear regulators are known for their low noise output but may not be suitable for large input-to-output voltage drops.

Switching regulators, on the other hand, use varying duty cycles to regulate the output voltage. They switch the input voltage at a high frequency and rely on control feedback systems to determine the on/off time of the switch. Switching regulators are highly efficient and compact, making them suitable for various applications. They include buck converters (reducing voltage), boost converters (increasing voltage), and buck-boost converters (raising or lowering voltage). The choice between linear and switching regulators depends on factors such as power efficiency, voltage requirements, and noise considerations.

#### Picking Regulators and Configuring a Power System

When configuring a power system, it is crucial to consider the requirements of different components and select appropriate regulators accordingly. Let's take a couple of examples to illustrate this process.

Example 1:
- A device with a 12 V motor driver system, a logic block operating at 2.5 V, a host microcontroller (MCU) requiring 3.3 V, and analog circuitry needing 5 V.
- An off-line switcher can be used for AC/DC conversion to directly power the motor driver.
- Buck converters can provide the 2.5 V and 3.3 V power supplies for the logic block and MCU, respectively.
- The MCU acts as the central control, managing the power supplies and enabling selective shutdown of peripheral devices for energy efficiency and safe system behavior.

Example 2:
- A power system with a battery pack consisting of four lithium batteries in series (4S) and two in parallel (2P).
- The system must operate at both 18 V (battery charging) and 10 V (fully discharged batteries).
- A buck-boost converter can be used to provide a consistent 12 V output for a circuit that requires that voltage, switching between buck and boost modes as needed.
- Other power requirements, such as a logic block at 0.9 V or an MCU at 3.3 V, can be fulfilled using appropriate buck converters.
- Filtering and noise considerations should be taken into account to ensure stable power supply voltages in noise-sensitive circuitry.

Power supply monitoring is an important feature to consider, allowing the monitoring of voltages at different points in the system. By using voltage dividers and analog-to-digital converters (ADCs), one can monitor power sources and facilitate proper power on/off sequences.

Bypass capacitors, decoupling, and filtering play a crucial role in power systems. At-chip bypass capacitors directly connected to power pins, distributed capacitance across the power plane, and filtering at voltage regulator outputs all contribute to stable and noise-free power delivery. The selection of bypass capacitor values and their distribution should consider the high-frequency response, resonance points, and impedance characteristics of the capacitors used.

Finally, it is important to ensure low-impedance power and ground connections to minimize voltage variances caused by wideband surge currents generated by digital logic. Dedicated power and ground layers within the PCB, combined with distributed bypass capacitance, help stabilize the power grid and reduce the impact of impedance fluctuations.

In summary, developing hardware for embedded systems involves careful consideration of power systems. This includes addressing AC power safety, implementing safe failure methods, selecting appropriate overcurrent protection methods, and choosing suitable AC/DC converters and DC/DC regulators. Additionally, configuring a power system requires careful regulator selection, consideration of power supply monitoring, and the incorporation of bypass capacitors and stable power and ground connections to ensure reliable and noise-free operation.

## 5. Battery Power


Modern electronics relies heavily on battery power, from mobile phones to portable tools. Devices today are mostly untethered, with AC power primarily used for charging batteries. This chapter focuses on designing efficient battery systems that meet the needs of various electronic systems.

#### Key Components of a Battery

A single-cell battery comprises three main parts:

- **Anode:** The negative terminal that emits electrons when the battery is connected to a circuit.
- **Cathode:** The positive terminal that absorbs electrons during circuit operation.
- **Electrolyte:** A medium facilitating ion movement between the anode and cathode, enabling electron flow in the external circuit while maintaining separation through a nonconductive carrier called a separator.

### Decision Making: Single-Use vs. Rechargeable Batteries

#### Price Considerations

Rechargeable systems are costlier due to additional electronics like AC/DC sources and the batteries themselves. Conversely, single-use batteries offer a low-cost solution, suitable for low-power devices such as remote controls and wall clocks.

#### Use Cases and Applications

- **Low-Power Usage:** Ideal for single-use batteries typically found in low-power devices.
- **High Power Consumption:** Rechargeable batteries with swappable packs suit high-power applications like power tools.
- **Power Outage Systems:** Rechargeable batteries are preferred for devices needing to function during power outages, such as UPS systems and emergency lights.

#### Defining Power Requirements

Electronics vary widely in power consumption. Supercomputers demand megawatts, whereas electronic watches require microwatts. Thus, understanding a system's power use, including peak currents, long-term average currents (LTAC), and voltage ranges, is crucial for suitable battery selection.

#### Battery Discharge and Voltage Range

Battery voltage decreases non-linearly as it discharges. Systems should ideally operate over the entire battery discharge range. Options include using boost circuits, low-dropout (LDO) regulators, or series-connected batteries to maintain operational voltage.

#### Battery Types and Chemistry

Battery types are categorized by their chemical make-up and packaging characteristics. It's important to choose the right battery chemistry to match the application needs.

##### Discharge Characteristics

Understanding battery behavior under different loads is critical. Manufacturers often provide ampere-hour (Ah) ratings at low discharge currents to present higher capacity figures. However, higher actual load currents reduce the effective capacity, necessitating detailed capacity testing.

### Chemistry Selection

Three primary rechargeable battery types include:

- **Sealed Lead Acid (SLA)**
- **Nickel Metal Hydride (NiMH)**
- **Lithium-Ion (Li-ion) Family**

Design considerations cover average and peak currents, usage time, voltage requirements, environmental temperatures, capacity changes over time, safety circuits, and charge balancing.

### Charging Methods

#### Chemistry-Specific Charging

Each battery chemistry requires a unique charging method. Integrated circuits (ICs) help control the process, with parameters adjustable via digital or external components. Multiple ICs cater to different chemistries like Li-ion, lead-acid, and NiMH.

#### Smart Batteries

Smart batteries integrate features beyond basic cells, including charge balancing and monitoring systems. They utilize interfaces like I2C/SMB for communication, although a future shift to CAN bus is expected. These batteries still require external chargers tailored to their specific configurations.

#### Safety and Regulations

Shipping and selling products with Li-ion batteries entail extensive testing and certifications. High compliance costs may prompt manufacturers to use pre-certified battery packs. Ensuring designed enclosures allow for battery expansion helps prevent issues like those seen in infamous battery fires.

### Alternative Energy Storage Methods

#### Supercapacitors

While supercapacitors are often touted as battery replacements, cost and technological limitations hinder widespread adoption.

#### Hydrogen Fuel Cells

These cells generate electricity through a chemical reaction between hydrogen and oxygen, typically used for larger-scale applications.

#### Flow Batteries

Flow batteries use fluid electrolytes in a pump system, suitable for large installations rather than small electronics.

#### Wireless Power

Wireless power is divided into close-proximity charging, energy transmission over distances, and systems without batteries. While close proximity charging is common in smartphones, large-scale applications face cost and efficiency barriers.

#### Solid State Batteries

Solid state batteries promise improved energy density, but practical challenges like production scaling and cost competitiveness remain.

#### Summary and Conclusions

Designing battery systems for embedded electronics involves careful consideration of:

- Inconsistent battery specifications and vendor-provided data.
- Cost, usage frequency, and application environment when choosing between single-use and rechargeable batteries.
- System's power needs estimated through LTAC.
- Matching discharge profiles with system requirements for optimal battery use.

Battery technology is continually evolving, and while alternatives exist, traditional batteries remain the primary energy storage solution in small electronic systems. Ensuring safety and regulatory compliance whilst keeping abreast of technological advancements is essential for successful hardware development.

## 6. EMI and ESD

The world of embedded hardware involves dealing with various forms of electronic noise that can interfere with the proper functioning of devices. Two significant types of interference are Electromagnetic Interference (EMI) and Electrostatic Discharge (ESD). Both are crucial considerations in the design and development of robust and reliable hardware systems.

#### Internal and External EMI

Any digital electronic system inherently generates EMI. This noise is influenced by the clocking rates, number of active gates, and other switching devices. Externally, numerous sources like radio devices, solar noise, power grids, and electronics can introduce noise. Internally, noise within a system can degrade performance, reduce accuracy, or even render a device nonfunctional.

#### Importance of EMI Control

To ensure the optimal performance and regulatory compliance of electronic devices, designers need to minimize the EMI generated by their products and protect them from environmental noise.

#### Radiated EMI

This refers to noise emitted that can affect other devices outside the system. If a system's radiated EMI exceeds permissible levels, it can disrupt nearby electronics.

#### Conducted EMI

This deals with noise that is injected onto AC power lines by the system. Such transient currents or high-frequency voltage spikes can cause disruptions if not controlled.

#### Regulatory Aspects

Various industries have specific standards for EMI compliance, such as medical, aerospace, and military sectors. These standards ensure that devices perform reliably without causing excessive interference.

#### Intrinsic Noise in Electronics

Not all noise in electronics comes from EMI. Some noise sources are intrinsic to the system components themselves. This includes:

- **Flicker Noise (1/F Noise):** Originating from CMOS transistors.
- **Thermal Noise:** Due to thermal activities in resistors.
- **Shot Noise and Burst Noise:** Arising from discrete charge transitions within conductors and semiconductors.

#### Design and Grounding Techniques

Limiting noise in a system involves proper grounding, shielding enclosures, and protecting ports. Techniques like Faraday cages can contain noise and meet regulatory restrictions efficiently.

#### Regulatory Requirements and Testing

Devices must pass regulatory tests to ensure they operate below set noise thresholds. This often involves measuring radiated emissions with calibrated antennas and spectrum analyzers.

## Frequency Domain Analysis

Identifying noise sources is best done using frequency domain analysis. This involves observing signal spectra to find harmonic multiples and other noise patterns. Understanding these frequencies can help pinpoint and mitigate noise origins.

#### Slower Clocks and Smoother Transitions

Reducing the transition speeds of digital signals can significantly lower EMI. This can often be achieved by adjusting driver strengths or using slower clocks.

#### Spread Spectrum Techniques

This involves slightly varying the clock period to spread the spectral energy over a range, reducing the peak EMI.

#### Shielding and Snubbers for SMPS

Switch-mode power supplies (SMPS) can be noise sources. Adding RC snubbers and using Faraday cages can mitigate this.

#### Cable Interconnect Strategies

Conducted noise can travel via cables. Using twisted pairs or ferrite beads reduces this. For motor controls, placing flyback diodes directly at the motor helps reduce noise in the driver cables.

#### Capacitive and Magnetic Coupling

Noise can transfer through capacitance or magnetic induction between components. Carefully spacing connections and using differential signals helps mitigate this.

#### Establishing a Low-Impedance Ground

Creating a low-impedance ground network is critical. It serves as a stable current return path, reducing noise interference. Various configurations, such as multiple grounding points and solid conductive sheets, can enhance this.

#### Identifying Noisy and Sensitive Components

Floor-planning involves separating noisy components from sensitive ones on the PCB. Analog and mixed-signal circuits should not share power supplies with digital components to minimize noise transfer.

#### Containment and Protection

Faraday cages effectively contain and protect systems from both internal and external EMI. They can be used to shield entire systems or selective sensitive components.

#### Understanding ESD Events

ESD can cause significant damage to circuits. Protecting against ESD involves designing circuits to tolerate and survive voltage surges. TVS diodes are commonly used for clamping these surges.

#### Summary and Best Practices

Effective management of EMI and ESD involves recognizing noise sources, proper grounding, and shielding techniques. Slower clocks and smoother signal transitions reduce noise, and floor-planning helps isolate sensitive components. Adhering to these principles ensures the development of robust and reliable embedded systems.
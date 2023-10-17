I/O Address Space
------------------
x86 architecture has separate address space for up to 65536 I/O Ports

Instructions for accessing I/O Ports
-------------------------------------

IN and OUT transfer data between an I/O device and the microprocessor's accumulator (AL, AX or EAX)

AL - 8-bit I/O
AX - 16-bit I/O
EAX - 32-bit I/O

If a program specifies AL with the IN instruction, the processor transfers 8 bits from the selected port to AL.

If a program specifies AX with the IN instruction, the processor transfers 16 bits from the port to AX.

If a program specifies EAX with the IN instruction, the processor transfers 32 bits from the port to EAX.

The I/O address is stored in dx register.

File: arch/x86/include/asm/io.h

static inline void out##bwl(unsigned type value, int port)      \
{                                   \
    asm volatile("out" #bwl " %" #bw "0, %w1"           \
             : : "a"(value), "Nd"(port));           \
}                                   \
                                    \
static inline unsigned type in##bwl(int port)               \
{                                   \
    unsigned type value;                        \
    asm volatile("in" #bwl " %w1, %" #bw "0"            \
             : "=a"(value) : "Nd"(port));           \
    return value;                           \
}    


static inline void out##bwl##_p(unsigned type value, int port)      \
{                                   \
    out##bwl(value, port);                      \
    slow_down_io();                         \
}                                   \
                                    \
static inline unsigned type in##bwl##_p(int port)           \
{                                   \
    unsigned type value = in##bwl(port);                \
    slow_down_io();                         \
    return value;                           \
}          



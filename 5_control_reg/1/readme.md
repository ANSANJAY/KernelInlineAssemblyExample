Control Register (CR0)
---------------------

The CR0 register is 32 bits long on the 386 and higher processors.

On x86-64 processors in long mode, it (and the other control registers) is 64 bits long

CR0 has various control flags that modify the basic operation of the processor.

Bit 0 is Protection Enable:

When PE = 0, CPU is in real mode

When PE = 1, CPU is in protected mode

lmsw instruction is used to turn on the PE Mode

MSR
---------

A model-specific register (MSR) is any of various control registers in the x86 instruction set used for
        debugging
        program execution tracing
        computer performance monitoring
        toggling certain CPU Features


Instructions:
-------------

	rdmsr and wrmsr are used to read and write MSR registers.

MSRs are 64-bit wide.
Each MSR that is accessed by the rdmsr and wrmsr group of instructions is identified by a 32-bit integer. 
The presence of MSRs on your processor is indicated by CPUID.01h:EDX[bit 5].





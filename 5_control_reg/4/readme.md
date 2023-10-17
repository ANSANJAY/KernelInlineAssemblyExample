

static inline void wrmsr(uint64_t msr, uint64_t value)
{
        uint32_t low = value & 0xFFFFFFFF;
        uint32_t high = value >> 32;
        asm volatile (
                "wrmsr"
                :
                : "c"(msr), "a"(low), "d"(high)
        );
}

static inline uint64_t rdmsr(uint64_t msr)
{
        uint32_t low, high;
        asm volatile (
                "rdmsr"
                : "=a"(low), "=d"(high)
                : "c"(msr)
        );
        return ((uint64_t)high << 32) | low;
}

Example
------------

Local APIC can be enabled/disabled by setting/clearing bit 11 of the IA32_APIC_BASE Model Specific Register (MSR) 

disable_local_APIC is using it 

File: arch/x86/kernel/apic/apic.c

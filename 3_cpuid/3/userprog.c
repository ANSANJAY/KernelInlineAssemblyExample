#include <stdio.h>
#include <string.h>

void cpuid_instruction(unsigned int *eax, unsigned int *ebx,
			unsigned int *ecx, unsigned int *edx)
{

	/* ecx is often an input as well as an output. */
        asm volatile("cpuid"
            : "=a" (*eax),
              "=b" (*ebx),
              "=c" (*ecx),
              "=d" (*edx)
            : "0" (*eax), "2" (*ecx)
            : "memory");

}

int main(void)
{
	unsigned int a = 0x01, b, c, d;
	cpuid_instruction(&a, &b, &c, &d);
	printf("ecx:%02x\n", c);
	printf("edx:%02x\n", d);

	if (d && (1 << 9))
		printf("APIC is present\n");
	else
		printf("APIC is not present\n");

	if (d && (1 << 0))
		printf("FPU present\n");
	else
		printf("FPU not present\n");

        return 0;
}

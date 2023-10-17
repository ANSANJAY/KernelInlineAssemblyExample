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

unsigned int x86_family(unsigned int sig)
{
        unsigned int x86;

        x86 = (sig >> 8) & 0xf;

        if (x86 == 0xf)
                x86 += (sig >> 20) & 0xff;

        return x86;
}



int main(void)
{
	unsigned int a = 0, b, c  = 0, d;
	char vendor[13];

	cpuid_instruction(&a, &b, &c, &d);	
	memset(vendor, 0, sizeof(vendor));
	memcpy(vendor, &b, sizeof(b));
	memcpy(vendor + 4, &d, sizeof(d));
	memcpy(vendor + 8, &c, sizeof(c));
	printf("Vendor:%s\n", vendor); 

	a = 0x01;
	cpuid_instruction(&a, &b, &c, &d);
	printf("eax:%02x\n", a);
	printf("family:%02x\n", x86_family(a));

        return 0;
}

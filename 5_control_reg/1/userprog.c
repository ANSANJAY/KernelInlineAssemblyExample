#include <stdio.h>
#include <string.h>
#include <stdint.h>

static inline unsigned long read_cr0(void)
{
    unsigned long val;
    asm volatile ( "mov %%cr0, %0" : "=r"(val) );
    return val;
}


int main(void)
{
	unsigned long cr0 = read_cr0();
	printf("cr0:%02lx\n", cr0);
        return 0;
}

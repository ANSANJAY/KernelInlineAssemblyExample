#include <stdio.h>
#include <string.h>
#include <stdint.h>

//compile with -m32

static inline uint64_t rdtsc()
{
    uint64_t val;
    asm volatile ("rdtsc" : "=A"(val));
    return val;
}


int main(void)
{
	long long unsigned int time = rdtsc();
	printf("time:%02llx\n", time);
        return 0;
}

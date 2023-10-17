#include <stdio.h>
#include <string.h>
#include <stdint.h>

static inline uint64_t rdtsc()
{
    uint32_t low, high;
    asm volatile ("rdtsc" : "=a"(low), "=d"(high));
    return ((uint64_t)high << 32) | low;
}


int main(void)
{
	long long unsigned int time = rdtsc();
	printf("time:%02llx\n", time);
        return 0;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned int a, b, c, d;
	unsigned operation = 0x00;
	unsigned sub_id = 0x00;
	char vendor[13];
	
	asm volatile ("cpuid"  //assembly instruction
		       :"=a"(a), "=b"(b), "=c"(c), "=d"(d)	//output parameters
			 : "a"(operation), "c"(sub_id)
			 );
	memset(vendor, 0, sizeof(vendor));
	memcpy(vendor, &b, sizeof(b));
	memcpy(vendor + 4, &d, sizeof(d));
	memcpy(vendor + 8, &c, sizeof(c));
	printf("Vendor:%s\n", vendor); 

        return 0;
}

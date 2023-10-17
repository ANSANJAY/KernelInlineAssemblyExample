#include <stdio.h>
#include <sys/io.h>

extern inline unsigned long native_save_fl(void)
{
    unsigned long flags;

    /*
     * "=rm" is safe here, because "pop" adjusts the stack before
     * it evaluates its effective address -- this is part of the
     * documented behavior of the "pop" instruction.
     */
    asm volatile("# __raw_save_flags\n\t"
             "pushf ; pop %0"
             : "=rm" (flags)
             : /* no input */
             : "memory");

    return flags;
}

void disable_interrupts(void)
{
    asm volatile("cli": : :"memory");
}

void enable_interrupts(void)
{
    asm volatile("sti": : :"memory");
}


int main()
{
    unsigned long flags = native_save_fl();

    printf("flags:%04lx\n", flags);
    iopl(3);
    flags = native_save_fl();
    printf("flags:%04lx\n", flags);
    disable_interrupts();
    flags = native_save_fl();
    printf("flags:%04lx\n", flags);
    enable_interrupts();
    flags = native_save_fl();
    printf("flags:%04lx\n", flags);
    return 0;
}

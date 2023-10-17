Saving and Restoring Flags
-----------------------------

local_irq_save() and local_irq_restore() takes care of saving and restoring the interrupt states 

Instructions
---------------
popf    --  Pops 8/16/32/64 bit off the stack into EFLAGS register.                                                  
                 IF will be set or cleared depending on ninth bit on the top of the stack.

pushf   --  Pushes the entire flag register on to the stack.

local_irq_save()
----------------

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

Comments in Assembly starts with #

local_irq_restore()
-----------------------

extern inline void native_restore_fl(unsigned long flags)
{
    asm volatile("push %0 ; popf"
             : /* no output */
             :"g" (flags)
             :"memory", "cc");
}



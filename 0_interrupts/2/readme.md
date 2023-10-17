irqs_disabled()
------------------

    Returns nonzero if local interrupt delivery is disabled
    Returns zero if local interrupt delivery is enabled

 static inline int arch_irqs_disabled_flags(unsigned long flags)
 {
     return !(flags & X86_EFLAGS_IF);
 }
 
 static inline int arch_irqs_disabled(void)
 {
     unsigned long flags = arch_local_save_flags();                                                           
 
     return arch_irqs_disabled_flags(flags);
 }

#define X86_EFLAGS_IF_BIT   9 /* Interrupt Flag */
#define X86_EFLAGS_IF       _BITUL(X86_EFLAGS_IF_BIT) 

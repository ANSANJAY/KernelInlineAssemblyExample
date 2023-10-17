Incrementing counter takes multiple instructions.

So, we need atomic integer operations for incrementing counters.

Protecting a counter with a complex locking scheme(eg. spin_lock) is overkill

Linux kernel provides atomic operations (Data type:atomic_t , operations: atomic_inc/atomic_dec)

atomic_inc
------------

static __always_inline void arch_atomic_inc(atomic_t *v)
{
        asm volatile(LOCK_PREFIX "incl %0"
                     : "+m" (v->counter) :: "memory");
}


atomic_dec
-------------

static __always_inline void arch_atomic_dec(atomic_t *v)
{
        asm volatile(LOCK_PREFIX "decl %0"
                     : "+m" (v->counter) :: "memory");
}


cpu_relax
----------------

/* REP NOP (PAUSE) is a good thing to insert into busy-wait loops. */
static __always_inline void rep_nop(void)
{
        asm volatile("rep; nop" ::: "memory");
}

static __always_inline void cpu_relax(void)
{
        rep_nop();
}

This function is used more than 800 times in the Linux kernel

What is the use of this function?
---------------------------------

rep; nop is indeed the same as the pause instruction (opcode F390)

On previous processors, this simply did nothing, just like nop but in two bytes

On new processors which support hyperthreading, it is used as a hint to the processor that you are executing a spinloop to increase performance

From Intel Manual
-------------------

Improves the performance of spin-wait loops. When executing a “spin-wait loop,” a Pentium 4 or Intel Xeon processor suffers a severe performance penalty when exiting the loop because it detects a possible memory order violation. The PAUSE instruction provides a hint to the processor that the code sequence is a spin-wait loop. The processor uses this hint to avoid the memory order violation in most situations, which greatly improves processor performance. For this reason, it is recommended that a PAUSE instruction be placed in all spin-wait loops.

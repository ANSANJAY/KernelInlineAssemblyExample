What is atomic operation
---------------------------

An atomic operation is an operation that will always be executed without any other process being able to read or change state that is read or changed during the operation. 

Methods for ensuring an operation is atomic
----------------------------------------------

Single processor-single core systems
------------------------------------

On a single processor system, if an operation is implemented in a single CPU instruction, it is always atomic
Ex: xchg, inc

If operation is implemented in multiple CPU instructions, then it can be interrupted in middle of execution.
a) Interrupts
b) Context switch

Techniques for atomicity
--------------------------
    a. spinlock
    b. Disabling interrupts

Multiprocessor or multicore systems
------------------------------------

On multiprocessor systems, ensuring atomicity exists is a little harder.

Disabling interrupts or using a single instruction will  not guarantee atomic access

It is still possible to use a lock (e.g. a spinlock)

Technique
-----------

To ensure that no other processor or core in the system attempts to access the data you are working with, use LOCK signal on the bus, which prevents any other processor in the system from accessing the memory at the same time.

 On x86 processors, 
    some instructions automatically lock the bus (e.g. 'XCHG') 
    while others require you to specify a 'LOCK' prefix to the instruction to achieve this (e.g. 'CMPXCHG', which you should write as 'LOCK CMPXCHG op1, op2').

Note: The lock prefix only works for individual x86 instructions
If you have block of instructions, then you need to use other techniques

Does executing CLI instruction disable interrupts on other processors
------------------------------------------------------------------------
Does executing CLI instruction disable interrupts on other processors
------------------------------------------------------------------------

In multiprocessor systems, executing a CLI instruction does not disable interrupts on other processors

Thus, a driver/interrupt handler race condition can still occur because other processors may service interrupts and execute the offending interrupt handler.

Other synchronization mechanisms such as locks must be used in addition to CLI/STI to prevent all race conditions.

Locking technique for multiple instructions
--------------------------------------------

Assembly:

lock: mv mem(lock), %eax	#load value of lock into eax
      cmp $0, eax		# if 0 store 1
      bnz lock			# else try again
      mv $1, mem(lock)		

unlock: mv 0, mem(lock)		# load 0

Do you see any problem in the above logic?
----------------------------------------------

data race because load-test-store is not atomic!

processor 0 loads address of lock, observes 0
processor 1 loads address of lock, observes 0
processor 0 writes 1 to address lock
processor 1 writes 1 to address lock

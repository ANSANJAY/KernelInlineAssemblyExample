Locking technique for multiple instructions
--------------------------------------------

Simplest Mechanism:
=====================

a lock is a 1-bit variable, a value of

	1 indicates a process is in the critical section

	0 indicates no process is in the critical section


while (lock == 1)	do_nothing; //busy-wait loop
lock = 1;
//critical section
lock = 0;

Assembly:

lock: mv mem(lock), %eax	#load value of lock into eax
      cmp $0, eax		# if 0 store 1
      bnz lock			# else try again
      mv $1, mem(lock)		

unlock: mv 0, mem(lock)		# load 0

Do you see any problem in the above logic?
----------------------------------------------

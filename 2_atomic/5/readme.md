Locking atomically
------------------

We need to make sure no one gets between load and store

Solution: atomic compare and swap

compare and swap operation should be performed atomically.
	compares the contents of a memory location with a given value and, only if they are the same, modifies the contents of that memory location to a new given value.

tmp = *addr ; //load
if (tmp == old)
	*addr = new; //store

The above operation should be performed atomically.

x86 provides instruction cmpxchg. Using lock prefix guarantees atomicity

iopl
---------

Instructions for accessing I/O ports are privileged, so user-space code cannot normally use them

One of the mechanism which allows user process access the I/O ports is to change the IOPL.

The I/O privilege level (IOPL) is a two-bit variable that controls how much privilege a process must have to access I/O ports

It is normally set to zero, meaning that this access is only available when running in kernel mode.

Setting it to three makes I/O-port operations available to ordinary user-space processes.

 Changing the I/O privilege level for a specific process (done with the iopl() system call) can thus make all I/O ports available to that process

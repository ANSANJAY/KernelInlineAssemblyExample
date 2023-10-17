Disabling and Enabling Interrupts from user space
-------------------------------------------------

CLI and STI are privileged instructions, which trigger a general protection fault if an unprivileged application attempts to execute it

The privilege level required to execute a CLI or STI instruction or set IF using POPF  is determined by the IOPL (I/O Privilege Level) in EFLAGS

Most modern operating systems set the IOPL to be 0 so only the kernel can execute CLI/STI.

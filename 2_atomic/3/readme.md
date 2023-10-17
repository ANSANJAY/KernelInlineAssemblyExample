LOCK
--------

Intel 64 and IA-32 processors provide a LOCK# signal that is asserted automatically during certain critical memory operations to lock the system bus.

While this output signal is asserted, requests from other processors or bus agents for control of the bus are blocked

 Software can specify other occasions when the LOCK semantics are to be followed by prepending the LOCK prefix to an instruction



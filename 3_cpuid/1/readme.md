CPUID
-----------

Request for CPU identification

The CPUID instruction can be used to retrieve various amount of information about your cpu,
	vendor string
	model number
	size of internal caches
	the list of CPU features supported

The idea of the CPUID instruction is that you can call it with different values in EAX,it will return different information about the processor

CPU Vendor String
------------------

EAX = 0, ECX = 0
Result of Vendor ID String in: EBX, ECX, EDX

      MSB         LSB
EBX = 'u' 'n' 'e' 'G'
EDX = 'I' 'e' 'n' 'i'
ECX = 'l' 'e' 't' 'n' 

Where, MSB stands for "Most Significant Byte" and LSB is the "Least Significant Byte".



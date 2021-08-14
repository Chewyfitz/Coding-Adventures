# Simple programs
These are the most basic programs imaginable, taking simple inputs and performing simple computations which don't reasonably require parallelisation
### \<loop\_type\>\_loop.c
Best practice for running these programs is to compile with `gcc -fopenmp -o <type>_loop <type>_loop.c` and run as `time ./<type>_loop > /dev/null` to see performance statistics, rather than spamming your console with `printf`s.

/*
Points
- Stack and Stack Frame
- Call by value and call by reference
    Something intresting passing a char array to a function is SORT OF a call by reference
    because we are passing the location as a call by value but no copy of the array is made
- Register variables
    eg: register int x;

    These were mainly supported to appease assembly programmers so these variables
    are stored in registers and not memeory so you cant get the address of this
- Recursion
    Can create a stack overflow
    Basically each call makes a new stack Frame
- C Pre Processor
    This is NOT  a compiler. Its a source code to source code transalator gcc -E test.c

    This allowed C code written on even older machines to run on different systems because your underlying architecure is still
    very different

    the pre processor also lets you write code where you can for example define baced on the architecture to use long o int for variables
    because int can be 16 or 32 in different systems
*/







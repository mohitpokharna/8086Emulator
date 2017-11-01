# 8086Emulator #

This is a microprocessor emulator integrated with 8086 assembler. It will allow users to program in assembly language. An assembler is a program that takes basic computer instructions and converts them into a pattern of bits that the computer's processor can use to perform its basic operations.

Currently the following functionalities are supported:
* mov reg,num
* mov reg,reg
* add reg,num
* add reg,reg
* cmp reg,num
* jc
* int 33  
Both byte sized and word sized registers are allowed.

## Usage ##
  
Compile the codes
   
    $ gcc assm.c
   
    $ gcc sim.c -o sim

Run the emulator and provide assembly language input
   
    $ ./a.out
    
This will generate a txt file with machine codes. Use this as input after the next command
   
    $ ./ex
    
Output will be displayed

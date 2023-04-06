// 4.3 Concepts

/*
Vocabulary
==========
* Datapath element - a unit used to operate on or hold data within a processor; for LEGv8, instruction and data memories, the register
  file, the ALU, and adders are datapath elements
* Program counter (PC) - a register that holds the address of the current instruction being executed
* Arithmetic-logical (or R-type) instructions - a class of instructions where an ALU operation is performed on the register contents
  and the result is written to a register (i.e. ADD, SUB, AND, ORR, etc)
* Register file - a state element containing a set of registers that can be read and written by supplying a register number to be accessed;
  it contains the register state of the computer
* Sign-extend - increase of a data item's size by replicating its high-order sign bit into the high-order bits of the larger, destination
  data item
* Branch target address - the address of a branch, which becomes the new PC if the branch is taken
* Branch taken - A branch with a true branch condition, where the PC becomes the branch target
* 

General
=======
~ In LEGv8 architecture, the branch target is given by the sum of an instruction's offset field and the address of the branch
~ All unconditional branches are taken
~ A branch datapath must compute the branch target address and test the register contents
~ The simplest datapath will attempt to execute all instructions in one clock cycle, where no datapath resource can be used more than once
  (reuse of elements requires duplication and therefore distinct memory for instructions and data)
~ Sharing of datapath elements between instruction classes may require multiple input connections and therefore a multiplexor and control
  signal
~ 
*/

global _main

_main:

    
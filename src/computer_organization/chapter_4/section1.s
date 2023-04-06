// 4.1 Concepts

/*
Vocabulary
==========
* Multiplexor (or data selector) - a logic element that selects data coming from multiple sources to be input for another
  element
* Control unit - takes an instruction as input to determine how to set control lines for the functional units and multiplexors
  of a datapath.

General
=======
~ Instruction classes:
  1) Memory-reference
  2) Arithmetic-logical
  3) Branches
~ The first two steps of any instruction are the same:
  1) Direct the PC to the memory that contains the code and fetch the instruction from that location
  2) Read one or two registers, using fields of the instruction to select the registers to read
~ All instruction classes, except the unconditional branch instruction, use the arithmetic-logical unit (ALU) after reading
  the registers
*/

global _main

_main:

    
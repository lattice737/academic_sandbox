// 3.3 Concepts

/*
Vocabulary
==========

General
=======
~ Multiplication: a (multiplicand) * b (mutliplier) = c (product)
~ The product of an m-bit multiplicand and an n-bit multiplier needs m+n bits to be stored (overflow condition)
~ Original Multiply Algorithm:
  1) Test Multplier0
     a) Multiplier0 == 0: Go to step 2
     b) Multiplier0 == 1: Add multplicand to product and place result in Product register
  2) Shift Multiplicand register left 1 bit
  3) Shift Multiplier register right 1 bit
  4) Repeat for 32 iterations
~ Some compilers replace multiplies by short constants with a series of shifts & adds, and almost every compiler will perform the
  strength reduction optimization of substituting a left shift for a multiply by a power of 2
~ Faster multiplications are possible by essentially providing one 64-bit adder for each bit of the multiplier, one for the
  multiplicand ANDed with a multiplier bit and the other for the output of a prior adder
~ LEGv8 multiply instructions do not set the overflow condition code, so it is up to the software to check to see if the product
  is too big to fit into 64 bits
*/

    
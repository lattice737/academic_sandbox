// 3.2 Concepts

/*
Vocabulary
==========
* Arithmetic Logic Unit (ALU) - Hardware that performs addition, subtraction, and usually logical operations such as AND and OR
* Saturation - An overflow result where the larget positive number or most negative number is set rather than a modulo calculation

General
=======
~ For addition, digits are added bit by bit from right to left, with needed carries
~ Subtraction uses addition, except negating the appropraite operand
~ No overflow can occur when adding positive and negative operands
~ Independent of the representation, the finite word size of computers means that arithmetic operations can create results that
  are too large to fit in this fixed word size
~ Determining the carry into the higher-order bits earlier increases the speed of addition
*/
    
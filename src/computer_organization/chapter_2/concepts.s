// Chapter 2 Concepts

/*
Vocabulary
==========
* Instructions - The words of a computer's language
* ARMv8 assembly language - The original instruction set of ARM Holdings plc
* LEGv8 assembly language - A teaching subset of ARMv8
* MIPS assembly - An example of instruction sets designed since the 1980s
* ARMv7 assembly - An older instruction set that uses 32-bit addresses instead of ARMv8's 64 bit addresses
* Stored-program concept - The idea that instructions and data of many types can be stored in memory as numbers and
  are therefore easy to change, culminating in the stored-program computer
* Registers - Primitives used in hardware design that are also visible to developers when the computer is built
* LEGv8 word - A natural unit of access in a computer, usually a group of 32 bits (4 bytes)
* LEGv8 doubleword - Another natural unit of access in a computer, usually a group of 64 bits (8 bytes); LEGv8 register size
* Data transfer instruction - A register command that moves data between memory and registers
* Address - A value that represents the location of a specific data element within the memory array, made up of a base address
  and an offset
* Load (LDUR) - The data transfer instruction that copies data from memory to a register
* Base address (or base register or index register) - The starting address of an item in the memory array
* Store (STUR) - The data transfer instruction that copies data from a register to memory
* Alignment restriction - A requirement that data be aligned in memory on natural (word or doubleword) boundaries
* Offset - The bits to be added to a base register to represent the location of a specific element in the memory array,
  equal to the element index times 8 and signified in a data transfer instruction as a constant preceded by #
* Register spilling - The process of keeping less frequently used variables (or later in logic) into memory
* Least significant bit - The rightmost bit in a LEGv8 doubleword
* Most significant bit - The leftmost bit in a LEGv8 doubleword
* Overflow - The inability of a byte to properly represent a value with its rightmost bits
* Sign & magnitude representation - Use of a bit to represent a sign to distinguish positive and negative values
* Two's complement representation - Distinction of positive and negative values with leading 0s and leading 1s,
  respectively
* Sign extension - the repeated copying of sign to fill the rest of a value's register
* Signed load - Load instruction that performs sign extension to properly represent a value in a register
* Load byte (LDURB) - Load instruction that treats a byte as an unsigned number and zero-extends the leftmost register bits
* Load byte signed (LDURSB) - Load instruction for signed integers
* One's complement representation - Distinction of negative values as the inverted-bit representation of positive values--
  required an extra step for subtraction and included both positve 0 & negative 0
* Biased representation - The representation of positive and negative values as a range where the most negative value is
  00...000 and the most positive value is 11...111 (zero is conventially 10...000)
* Field - An instruction component that contains a binary value
* Instruction format - A form of instruction representation composed of fields with binary numbers
* Machine language - Binary representation used for communication within a computer system
* Hexadecimal - Base 16 representation, notated as 0xnnnn in C
* Logical operations - Operations used to simplify the packing and unpacking of bits into words
* Shift - A logical operation that moves all the bits in a doubleword to the left or right and filling emptied bits with 0s
* Mask - The result of a logical AND where only some of the operand values remain in the final value, "masking" the others
* Conditional branch (B) - An instruction that tests a value and that allows for a subsequent transfer of control to a new
  address based on the outcome of the test
* Unconditional branch - An instruction that always follows a branch
* Basic block - A sequence of instructions without branches, branch targets, or branch labels
* Condition codes (or flags) - Four extra bits that are dedicated to recording what has occurred during an instruction
* Branch (address) table - An array of doublewords containing addresses that correspond to labels; the program loads the
  appropriate entry from the table into a register, then branches using the address in the register
* Branch register (BR) - A branch toward an unconditional instruction at the address specified in a register
* Procedure (or function) - A stored subroutine that performs a specific task based on the parameters with which it's
  provided
* Return address - A link to the calling site that allows a procedure to return to the proper address
* Caller - the program that calls a function and passes its necessary parameters
* Callee - the procedure called by a program at runtime that executes a series of stored instructions based on parameters
  provided by the caller and then returns control to the caller
* Program counter (PC) - the register containing the address of the instruction in the program being executed
* Stack - a last-in-first-out queue
* Stack pointer (SP) - A value denoting the most recently allocated address in a stack, showing where registers should be
  spilled or where old register values can be found

General
=======
~ ARMv7s are the most popular instruction sets in the world
~ ARMv8s are closer to MIPS than ARMv7s
~ The similarity of instruction sets occurs because all computers are constructed from hardware technologies based on
  similar underlying principles and because all computers must provide a few basic operations
~ Common design goal: create a language that makes it easy to build the hardware and compiler while maximizing
  performance and minimizing cost and energy
~ The operands of arithmetic instructions are restricted and must be stored in a limited number of special locations
  built directly into registers
~ There are a limited number of registers--usually 32 for current computers
~ The three operands of LEGv8 arithmetic instructions must each be chosen from one of the 32 64-bit registers
~ A very large number of registers may increase the clock cycle time simply because electronic signals must travel farther
~ The compiler's purpose is to associate program variables with registers
~ Because processors can only keep a small amount of data in registers, complex data structures are kept in computer memory,
  which contains billions of data elements
~ Arithmetic operations occur only on registers in LEGv8 instructions
~ Memory is just a large, single-dimensional array, with the address acting as the index to that array
~ The address of a doubleword matches the address of the 8 bytes within the doubleword, and addresses of sequential
  doublewords differ by 8
~ Computers are either big-endian, using the address of the leftmost, or "big-end", byte as the doubleword address, or
  little-endian, using the rightmost, or "little-end", byte; order matters only if identical data is accessed both as a
  doubleword and as 8 bytes, so awareness of "endianess" is rarely important
~ Proper addressing requires an offset that is the index * 8
~ Binary sizes (-bibytes) are preferable to decimal sizes (-bytes) since the addresses in loads and stores are binary numbers
~ Loads and stores are used by the compiler to keep the most frequently used variables in registers and place the rest in
  memory
~ Registers take less time to access and have higher throughput than memory, making data in registers both considerably
  faster to access and simpler to use; register access also requires less energy than memory access
~ More than half of the LEGv8 arithmetic instructions have a constant as an operand when running SPEC CPU2006 benchmarks
~ Constant operands occur frequently, so by including constants inside arithmetic instructions, operations are much faster
  and use less energy than if they were loaded from memory
~ LEGv8 dedicates register XZR to the value zero
~ LEGv8 offset plus base register addressing maps well to structures and arrays, since the register can can point to the
  beginning of the structure, and the offset can select the desired element
~ The base register was originally created to hold an array index with the offset used for the starting address in the array
~ The migration from 32-bit addresses to 64-bit addresses introduced the risk of unexpected overflow when converting between
  data types; generally, compilers associated with each OS handle this the same way
~ C99 standard declares variables used as array indexes to be size_t, which guarantees they're the right size no matter how
  large the array
~ In the full ARMv8 instruction set, register 31 is XZR in most instructions but the stack point (SP) in others 
~ The full ARMv8 instruction set does not use the mnemonic ADDI for immediate operands; it just uses ADD and lets the
  assembler pick the proper opcode
~ The first commercial computer offered decimal arithmetic, but because the computer still on and off signals, the decimals
  were simply represented by several bits; decimal proved so inefficient that subsequent computers reverted to solely
  binary, converting to base 10 only for relatively infrequent input/output events
~ Sign & magnitude shortcomings:
  1) Not obvious where to store the sign bit
  2) Adders may need an extra step to set the sign, because the proper sign can't be known in advance
  3) Existence of positive 0 and negative 0
~ Two's complement advantages:
  1) Hardward only needs to test the leftmost bit to evaluate the sign of a two's complement value
  2) Negation requires only inverting every 0 and 1, then adding 1
  3) Values can be represented with more than n bits by extending the most significant bit to fill the new bits
~ Since C programs almost always use bytes to represent characters, rather than consider bytes as very short signed integers,
  LDURB is used practically exclusively for byte loads
~ Two's complement gets its name from the rule that the unsigned sum of an n-bit number and its n-bit negative is 2^n
  (negation relationship)
~ Instructions are kept in the computer as a series of high and low electronic signals and may be represented as numbers, so
  each component of an instruction can be represented as an individual number, where a sequence of these numbers represents
  the instruction
~ For simplicity, all LEGv8 instructions are 32 bits long
~ The compromise chosen by LEGv8 between small instructions and large data is to keep all instructions the same length,
  thereby requiring distinct instruction formats for different kinds of instructions; although multiple formats complicate
  the hardware, complexity is reduced by keeping them similar
~ The 9-bit address of D-type instructions allow a load register instruction to load doublewords as large as 256 bytes (32
  doublewords)
~ Any increase in the number of registers uses up at least one more bit in every register field of the instruction format
~ Today's computers are built on two key principles that also encapsulate the stored-program concept:
  1) Instructions are represented as numbers
  2) Programs are stored in memory to be read or written just like data
~ LEGv8 R-type fields: opcode | Rm | shamt | Rn | Rd
  1) opcode (11 bits) - Instruction operation and format
  2) Rm (5 bits) - Second register source operand
  3) shamt (6 bits) - Shift amount
  4) Rn (5 bits) - First register source operand
  5) Rd (5 bits) - Register destination operand with the opration result
~ LEGv8 D-type fields: opcode | address | op2 | Rn | Rt
  1) opcode (11 bits)
  2) address (9 bits)
  3) op2 (2 bits)
  4) Rn (5 bits)
  5) Rt (5 bits)
~ LEGv8 I-type fields: opcode | immediate | Rn | Rd
  1) opcode (10 bits)
  2) immediate (12 bits)
  3) Rn (5 bits)
  4) Rd (5 bits)
~ The LEGv8 opcode size is a result of the largeness of the full ARMv8 instruction set, on the order of 1000 instructions
~ Logical operations: operation | C | LEGv8
  1) Shift left | << | LSL
  2) Shift right | >> | LSR
  3) Bitwise AND | & | AND, ANDI
  4) Bitwise OR | | | ORR, ORRI
  5) Bitwise NOT | ~ | EOR, EORI
~ Shifting left by N bits gives the identical result as multiplying by 2^N, just as shifting a decimal number by N digits is
  equivalent to multiplying by 10^N
~ In keeping with the three-operand format, the ARMv8 designers included the exclusive OR instruction (EOR) instead of NOT;
  exclusive OR returns 0 when bits are the same and 1 when they're different
~ C allows bit fields or fields to be dfined within doublewords, allowing objects to be packed within a doubleword and to
  match externally enforced interface, such as an I/O device--all fields must fit within a single doubleword
~ The immediate fields for ANDI, ORRI, and EORI of the full ARMv8 instruction set are not simple 12-bit immediate, but they
  are for LEGv8; so some logical operations with small constants are legal for LEGv8 but not ARMv8
~ Compilers frequently create branches and labels where they do not appear in the programming language; avoiding the burden
  of writing explicit labels and branches is one benefit of writing in high-level programming langugaes
~ Branches are also the building blocks for looping in assembly
~ Comparison of bit patterns must deal with the dichotomy of signed/unsigned numbers, where a bit pattern with a 1 in the
  most significant bit can represent a negative number and is less than a positive number for signed values
~ Condition codes:
  1) Negative (N) - The result had a 1 in the most significant bit
  2) Zero (Z) - The result was 0
  3) Overflow (O) - The result overflowed
  4) Carry (C) - The result had a carry, out of the most significant bit, or a borrow, into the most significant bit
~ Universal comparison instructions:
  1)Equal | == | EQ
  2) Not equal | != | NE
~ Signed comparison instructions:
  1) Less than | < | LT
  2) Less than or equal | <= | LE
  3) Greater than | > | GT
  4) Greater than or equal | >= | GE
~ Unsigned comparison instructions:
  1) Lower | < | LO
  2) Lower or same | <= | LS
  3) Higher | > | HI
  4) Higher or same | >= | HS 
~ If many instructions always set condition codes, it creates dependencies that make pipelined execution difficult, so
  LEGv8 limits condition code setting
~ Condition code setters:
  1) ADDS
  2) ADDIS
  3) ANDS
  4) ANDIS
  5) SUBS
  6) SUBIS
~ Treating signed numbers as if they were unsigned is a low-cost approach to checking bounds, exploiting the fact that
  negative two's-complement binary values are large numbers in unsigned notation; unsigned comparison x < y similarly
  checks if x is negative as well as if x is less than y
~ The bedrock statement that implements decisions and loops at the instruction set level is the conditional branch
~ Parameters act as an interface between a procedure and the rest of a program and data, since they can pass values and
  return results
~ Six tasks of a procedure:
  1) Place the parameters where the procedure can access them
  2) Transfer control to the procedure
  3) Acquire the storage resources needed for the procedure
  4) Perform the desired task
  5) Place the result value where the calling program can access it
  6) Return control to the point of origin
~ LEGv8 register allocation for procedure calling:
  1) X0-X7: eight parameter registers for parameter or return values
  2) LR (X30): one return address register to return to the point of origin
~ Branch-and-link instruction: BL ProcedureAddress
~ Any registers needed by the caller must be restored to the values that they contained before the procedure was invoked
~ A stack is the ideal data structure for spilling registers
~ Design principles:
  1) Simplicity favors regularity
  2) Smaller is faster
  3) Good design demands good compromises
*/

global _main

_main:

    // g = h + A[8];
    ldur x9, [x22, #64] // Load unscaled register: load-to register, [base register, offset]
    add  x20, x21, x9
    stur x9, [x22, #96] // Store unscaled register: load-from register, [base register, offset]

    // n = m + 4
    addi x22, x22, #4   // Add immediate with constant 4

    // ADD | x21 | unused | x20 | x9  =  10001011000 | 10101 | 000000 | 10100 | 01001
    add x21, x20, x9

    // A[30] = h + A[30] + 1;
    ldur x9, [x10, #240]    // 11111000010 | 011110000 | 00 | 01010 | 01001
    add  x9, x21, x9        // 10001011000 | 01001 | 000000 | 10101 | 01001
    addi x9, x9, #1         // 1001000100 | 000000000001 | 01001 | 01001
    stur x9, [x10, #240]    // 11111000000 | 011110000 | 00 | 01010 | 01001

    // Logical shift left, moving 4 bits from x19 to x11
    lsl x11, x19, #4        // equivalent to multiplying by 2^4

    // Logical AND, assigning 1 to x9 bits where x10 & x11 bits are both 1
    // x10: ... 00001101 11000000
    // x11: ... 00111100 00000000
    //  x9: ... 00001100 00000000
    //              ^^
    and x9, x10, x11

    // Logical OR, assigning 1 to x9 bits where either a x10 or an x11 bit is 1
    // x10: ... 00001101 11000000
    // x11: ... 00111100 00000000
    //  x9: ... 00111101 11000000
    //            ^^^^ ^ ^^
    orr x9, x10, x11

    // Logical EOR, assigning 1 to x9 bits where x10 & x11 bits are different or 0 when they're the same
    // x10: ... 00001101 11000000
    // x11: ... 00111100 00000000
    //  x9: ... 00110001 11000000
    //            ^^   ^ ^^
    eor x9, x10, x12

    // Compare & branch if zero
    cbz register, l1        // go to statement with label l1 if the value in register is 0

    // Compare & branch if not zero
    cbnz register, l1

    // if (i == j) f = g + h; else f = g - h;
    sub  x9, x2, x23        // x9 = i - j
    cbnz x9, Else           // go to Else if i != j (x9 != 0)
    add  x19, x20, x21      // f = g + h (skipped if i != j)
    b    Exit               // unconditional branch
    Else: SUB x19, x20, x21 // f = g - h (skipped if i == j)
    Exit:

    // while (save[i] == k)
    //     i += 1;
    Loop: lsl x10, x22, #3  // x10 = i * 8
    add  x10, x10, x25
    ldur x9, [x10, #0]
    sub  x11, x9, x24
    cbnz x11, Exit
    addi x22, x22, #1
    b    Loop
    Exit:

    // Check for x20 >= length or x20 < 0
    subs xzr, x20, x11
    b.hs IndexOutOfBounds

    // Conditional branches
    b.mi  // N=1
    b.pl  // N=0
    b.vs  // V=1
    v.vc  // V=0

    // Function call branching
    bl x   // branching to procedure (callee) X
    x:     // procedure logic
    br lr  // unconditional branch to return address - PC + 4 saved in LR, to link the byte address of the following instruction


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
* Branch-and-link (BL) - An instruction that links a calling site LR to a branch procedure X (e.g. BL X) and returns to the
  calling site after the procedure is done (e.g. BR LR), placing the results in the parameter registers
* Return address - A link to the calling site that allows a procedure to return to the proper address
* Caller - the program that calls a function and passes its necessary parameters
* Callee - the procedure called by a program at runtime that executes a series of stored instructions based on parameters
  provided by the caller and then returns control to the caller
* Program counter (PC) - the register containing the address of the current instruction in the program being executed
* Stack - a last-in-first-out queue
* Stack pointer (SP) - A value denoting the most recently allocated address in a stack, showing where registers should be
  spilled or where old register values can be found
* Push - The addition of data onto a stack
* Pop - The removal of data from a stack
* Leaf procedure - A procedure that does not call other procedures
* Global pointer (GP) - A register reserved for static data
* Procedure frame (or activation record) - The segment of a procedure stack that contains saved registers and local variables
* Frame pointer (FP) - A value denoting the location of the saved registers and local variables for a given procedure
* Text segment - The segment of a UNIX object file that contains the machine language code for routines in the source file
* Store byte (STURB) - Store instruction that places a byte from memory in the rightmost 8 bits of a register
* Halfword - representation of a value using 16 bits
* Load half (LDURH) - An instruction that loads a halfword from memory, placing it in the rightmost 16 bits of a register;
  the halfword is treated as a signed number, sign-extending the 48 leftmost register bits
* Store half (STURH) - An instruction that stores a halfword from the rightmost 16 bits of a register into memory
* Move wide with zeros (MOVZ) - An instruction that sets any 16 bits of a constant in a register, zeroing the rest of the
  register bits
* Move wide with keep (MOVK) - An instruction that sets any 16 bits of a constant in a register, unchanging the rest of the
  register bits
* PC-relative addressing - An addressing strategy where an address is expressed as the sum of the program counter (PC) and
  a constant in the instruction; LEGv8 uses this scheme for conditional branches, since the destination of these instructions
  is likely to be close to the branch
* Addressing mode - An addressing regime delimited by its use of operands and/or addresses
* Data race - Simultaneous memory accesses by different threads to the same memory location
* Synchronization mechanism - An implementation that is intended to prevent or reduce data races
* Atomic exchange (or swap) - An operation that interchanges a value in a register for a value in memory
* Load exclusive register (LDXR) - The synchronization instruction that precedes the store exclusive register and is used to
  indicate whether a store exclusive writes a value to memory
* Store exclusive register (STXR) - A synchronization instruction that writes a value to memory if the contents of the
  memory location specified by the load exclusive are not yet changed before the store exclusive accesses the same location;
  it is defined to both store the value of a different register in memory and to change the value of another register to 0
  if it succeeds and to 1 if it fails
* Assembly language - A symbolic language that can be translated into binary machine language
* Pseudoinstructions - A variation of assembly language instructions often treated as if they were distinct instructions
* Symbol table - A table that maps symbols to the addresses of memory words that instructions occupy
* 

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
~ Any registers needed by the caller must be restored to the values that they contained before the procedure was invoked
~ A stack is the ideal data structure for spilling registers
~ Design principles:
  1) Simplicity favors regularity
  2) Smaller is faster
  3) Good design demands good compromises
~ Stacks "grow" from higher addresses to lower addresses--values are pushed by subtracting from the stack pointer, and
  values are popped by adding to the stack pointer
~ LEGv8 Register Conventions:
  1) X0-X7 (arguments/results)
  2) X8 (indirect result location register)
  3) X9-X15 (temporaries) - registers not preserved by the procedure when called
  4) X16 (scratch register or temporary register) [IP0]
  5) X17 (scratch register or temporary register) [IP1]
  6) X18 (platform register or temporary register)
  7) X19-X27 (saved) - registers that must be preserved by a procedure when called--callee saves and restores them
  8) X28 (stack pointer) [SP]
  9) X29 (frame pointer) [FP]
  10) X30 (link register) [LR]
  11) X31 (constant value zero) [XZR]
~ C Storage Classes:
  1) Automatic - characterizes variables local to a procedure and are discarded when the procedure exits
  2) Static - characterizes variables that exist across procedure entries and exits
~ Static variables are declared outside all procedures or using the keyword static
~ An activation record appears on the stack whether or not an explicit frame pointer is used; however, if there are no
  local variables on the stack within a procedure, the compiler will save time by not setting and restoring the frame
  pointer
~ LEGv8 Memory Allocation for Program & Data (top->bottom):
  1) Stack
  2) Dynamic data (or heap)
  3) Static data segment - stores constants & static variables
  4) Text segment - machine language code for source file routines
  5) Reserved
~ The stack and heap grow toward each other, allowing efficient use of memory as the segments wax and wane
~ String representations:
  1) First position reserved for string length
  2) Accompanying variable stores string length
  3) Last position marks the end of a string
~ When a compiler finds a leaf procedure, it exhausts all temporary registers before using registers it must
  save
~ ARMv8 software is required to keep the stack aligned to quadword (16-byte) address to improve performance, so a
  char type variable occupies 16 bytes of a stack, even though it needs less
~ Wide immediate operands load 16-bit fields using `LSL 16` where 16 may be some multiple of 16, depending on the
  quadrant of the 64-bit word desired
~ LEGv8 branch instructions have the simplest addressing, with 6 bits for the op field and 26 bits for the address
~ LEGv8 offers long addresses for procedure calls by using the B-type format for branch and branch-and-link instructions
~ Branch instructions interpret their address field as relative word addresses rather than as relative byte addresses,
  in order to stretch farther
~ Addressing Modes:
  1) Immediate addressing - the operand is a constant within the instruction
  2) Register addressing - the operand is a register
  3) Base (or displacement) addressing - the operand is at the memory location whose address is the sum of a register
     and a constant in the instruction
  4) PC-relative addressing - the branch address is the sum of the PC and a constant in the instruction
~ The critical ability required to implement synchronization in a multiprocessor is a set of hardware primitives with the
  ability to atomically read and modify a memory location, where nothing else can interpose itself between the read and
  write of a given memory location--otheriwse, the cost of building basic synchronization primitives will be high and
  increase prohibitively as processor count increases
~ Generally, architects do not expect users to employ the basic hardware primitives--system programmers will use them to
  build a synchronization library, an often complex and tricky process
~ The key to using the exhange primitive to implement synchronization is that the operation is atomic: the exchange is
  indivisible, and two simultaneous exhanges will be ordered by the hardware, making it impossible for two processors
  trying to set the synchronization variable to both simultaneously return the same result
~ The load/store exclusive mechanism can be used to build other synchronization primitives, such as atomic compare-and-swap
  and atomic fetch-and-increment, which are used in some parallel programming models
~ Synchronization Operation Best Practices:
  1) Only register-register instructions can be safely inserted between LDXR & STXR, to prevent the possibility of
     deadlocking
  2) The number of instructions between LDXR & STXR should be minimized to reduce the probability of frequent failures
     due to unrelated events or competing processor operations
~ Uses for synchronization operators:
  1) Cooperating threads of a parallel program need to synchronize for proper reading and writing of shared data
  2) Cooperating processes on a single processor need to synchronize for reading and writing shared data
~ Translation Hierarchy in C:
  1) A high-level language is compiled into an assembly language program by a compiler
  2) The assembly language program is assembled into an object module by an assembler
  3) An executable is created by combining object modules  with library routines by a linker, to resolve all references
  4) The executable is placed into memory by a loader for execution
~ File extensions:
  1) C source file: program.c (MS-DOS: program.C)
  2) Assembly file: program.s (MS-DOS: program.ASM)
  3) Object file: program.o (MS-DOS: program.OBJ)
  4) Statically linked library routine: routine.a (MS-DOS: routine.LIB)
  5) Dynamically linked library routine: routine.so (MS-DOS: routine.DLL)
  6) Executable file: program.out (MS-DOS: program.EXE)
~ Pseudoinstructions give LEGv8 a richer set of assembly instructions than those implemented by the hardware
~ To produce the binary version of each instruction in the assembly language program, the assembler determines the
  addresses corresponding to all labels using a symbol table
~ UNIX Object File Components:
  1) Object file header - describes the size and position of other object file components
  2) Text segment - contains the machine language code
  3) Static data segment - contains data allocated for the life of the program
  4) Relocation information - identifies instructions and data words that depend on absolute addresses when the
     program is loaded into memory
  5) Symbol table - contains the remaining labels that are not defined, such as external references
  6) Debugging information - contains a concise description of how the modules were compiled so that a debugger can
     associate machine instructions with source files and make data structures readable
~ 
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
    Loop: lsl x10, x22, #3    // x10 = i * 8
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

    // Leaf procedure
    // long long int leaf_example (long long int g, long long int h, long long int i, long long int j) {
    //     long long int f;
    //     f = (g + h) - (i + j);
    //     return f;
    // }
    // NOTE: stur, ldur statements can be omitted since x9, x10 are temporary registers
    leaf_example:
        subi sp, sp, #24    // adjust stack to make room for 3 items
        stur x10, [sp, #16] // save register x10
        stur x9, [sp, #8]   // save register x9
        stur x19, [sp, #0]  // save register x19
        add  x9, x0, x1     // register x9 contains g + h
        add  x10, x2, X30   // register x10 contains i + j
        sub  x19, x9, x10   // f = x9 - x10, which is (g+h)-(i+j)
        add  x0, x19, xzr   // returns f (x0 = x19 + 0) by copying to a parameter register
        ldur x19, [sp, #0]  // restore register x19 for caller
        ldur x9, [sp, #8]   // restore register x9 for caller
        ldur x10, [sp, #16] // restore register x10 for caller
        addi sp, sp, #24    // adjust stack to delete 3 items
        br lr               // branch back to calling routine

    // Nested procedures
    // long long int factorial (long long int n) {
    //     if (n < 1) return (1); // base case
    //         else return (n * factorial(n - 1));
    // }
    factorial:

        // body logic
        subi  sp, sp, #16   // adjust stack for 2 items
        stur  lr, [sp, #8]  // save return address -- characteristic for nested procedure
        stur  x0, [sp, #0]  // save argument n
        subis zxr, x0, #1   // test for n < 1
        b.ge  l1            // if n >= 1, go to l1
        addi  x1, xzr, #1   // return 1 if n < 1 (b.ge skipped)
        addi  sp, sp, #16   // pop 2 items off stack
        br    lr            // return to caller
        l1: subi x0, x0, #1 // n >= 1: arg gets (n-1)
            bl   factorial  // call factorial with (n-1) -- recursive
    
        // return logic
        ldur x0, [sp, #0] // return from BL: restore argument n
        ldur lr, [sp, #8] // restore return address
        addi sp, sp, #16  // adjust stack pointer to pop 2 items
        mul  x1, x0, x1   // return n * factorial (n-1)
        br   lr           // return to the caller

    // Recursive sum
    // long long int sum (long long int n, long long int acc) {
    //     if (n > 0)
    //         return sum(n - 1, acc + n);
    //     else
    //         return acc;
    // }
    sum: subs xzr, x0, xzr  // compare n to 0
         b.le sum_exit      // go to sum_exit if n <= 0
         add  x1, x1, x0    // add n to acc
         subi x0, x0, #1    // subtract 1 from n
         b    sum           // call sum procedure (again)
    sum_exit:
         add x2, x1, xzr    // return value acc
         br  lr             // return to caller

    // Reading & writing bytes
    ldurb x9, [x0, #0]  // Read byte from source
    sturb x9, [x1, #0]  // Write byte to source

    // String copying procedure
    // void copy_str (char x[], char y[]) {
    //     size t i;
    //     i = 0;
    //     while ((x[i] = y[i]) != '\0') // copy & test byte
    //     i += 1;
    // }
    copy_str:

        // body before while loop
        subi sp, sp, #8           // adjust stack for 1 more item
        stur x19, [sp, #0]        // save x19
        add  x19, xzr, xzr        // i = 0 + 0

        // while loop
        l1: add   x10, x19, x1    // address of y[i] in x10
            ldurb x11, [x10, #0]  // x11 = y[i]
            add   x12, x19, x0    // address of x[i] in x12
            sturb x11, [x12, #0]  // x[i] = y[i]
            cbz   x11, l2         // if y[i] == 0, go to l2
            addi  x19, x19, #1    // i = i + 1
            b     l1

        // body after while loop
        l2: ldur x19, [sp, #0]    // y[i] == 0: end of string--restore old x19
            addi sp, sp, #8       // pop 1 doubleword off stack
            br   lr               // return

    // Reading & writing halfwords
    ldurh x19, [x0, #0]   // Read halfword (16 bits) from source
    sturh x19, [x1, #0]   // Write halfword (16 bits) to destination

    // Wide immediate operations

    // MOVZ instruction: 110100101 | 01 | 0000000011111111 | 01001
    movz x9, 255, lsl 16   // x9 result: 0000000000000000 | 0000000000000000 | 0000000011111111 | 0000000000000000

    // MOVK instruction: 111100101 | 00 | 0000000011111111 | 01001
    movk x9, 255, lsl 0    // x9 result: 0000000000000000 | 0000000000000000 | 0000000011111111 | 0000000011111111

    // Load 64-bit constant into x19
    // Constant: 00000000 00000000 00000000 00000000 00000000 00111101 00001001 00000000
    movz x19, 61, lsl 16  // first, load bits 16-31; 61 = 0000 0000 0011 1101
    movk x19, 2304, lsl 0 // then, load the lowest 16 bits; 2304 = 00001001 00000000

    // Synchronization operations
    again: ldxr x10, [x20, #0]    // load exclusive
           stxr x23, x9, [x20]    // store exclusive; result will be stored in x9
           cbnz x9, again         // branch if store fails (result is 1)
           add  x23, xzr, x10     // assign loaded value to x23

    // Acquire lock at memory location
           addi x11, xzr, #1      // copy locked value
    again: ldxr x10, [x20, #0]    // load exclusive to read lock
           cbnz x10, again        // check if lock is free yet
           stxr x11, x9, [x20]    // attempt to store new value
           bnez x9, again         // branch if store fails

    // Release lock at memory location
    stur xzr, [x20, #0]   // free lock by writing 0
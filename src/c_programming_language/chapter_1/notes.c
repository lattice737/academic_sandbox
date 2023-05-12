#include <stdio.h>

// FIXME add C build task

/*
Vocabulary
----------
* Character string (or string constant) - a sequence of characters in double quotes
* Escape sequence - a character that provides a general and extensible mechanism for representing hard-to-type or
  invisible characters
* Declaration - a statement announcing the properties of variables, made up of a name and a list of variables
* Symbolic name (or symbolic constant) - a string of characters defined with `#define`, conventionally written in
  all upper case
* Text stream - a sequence of characters divided into lines, where each line consists of zero or more characters
  followed by a newline character
* Null statement - a statement made up of only a semicolon, simply to satisfy syntax requirements
* Character constant - the integral representation of a character in a machine's character set
* Parameter (or formal argument or actual argument) - a variable named in the paranthesized list in a function
* 

General
-------
~ Integer division truncates (e.g. 5 / 7)
~ If an arithmetic operator has one floating-point operand and one integer operand, the integer will be converted
  to floating point before the operation is evaluated
~ `%x.yf`: print float x chars wide with y places after decimal (no decimal when y=0)
~ printf specifications: %o (octal), %h (hexadecimal), %c (character), %s (string), %% (percent sign)
~ Any instance where it is permissible to use the value of some type, you can use a more complicated expression of
  that type
~ The for loop is a generalization of the while loop
~ A for loop is usually appropriate for loops in which the initialization and increment are single statements and
  logically related, since it is more compact than while and keeps the loop control statements together in one
  place
~ Variables assigned stream values must be large enough to hold any returned value (e.g. char is not big enough
  to hold a character and EOF [an int defined in the standard library] together--use int when streaming chars)
~ while and for both test at the top of a loop, before proceeding to the body; if there is nothing to do, nothing
  is done, enforcing boundary conditions
~ `==` (C) : `=` (Pascal) : `.EQ.` (Fortran)
~ Character variables and constants are identical to integers in arithmetic expressions
~ With properly designed functions, it is possible to ignore how a job is done, and knowing what is done is
  sufficient
~ The biggest change between ANSI C and earlier versions is how functions are declared and defined
~ In C, all function arguments are passed by value, leading to more compact programs with fewer extraneous
  variables, because parameters can be treated as conveniently initialized local variables in the called routine
~ Zero is an acceptable end-of-file return because it is never a valid line length (a blank line has length 1
  with a newline character)
~ 
*/

#define LOWER   0     /* lower limit of the table */
#define UPPER   300   /* upper limit of the table */
#define STEP    20    /* step size */
#define IN      1     /* inside a word */
#define OUT     0     /* outside a word */
#define MAXLINE 1000  /* maximum input line length */

int power(int m, int n);  /* parameter names are optional and do not have to match function header */
int getline(char line[], int maxline);
void copy(char to[], char from[]);

main() {
    
    /* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;    /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    /* print Fahrenheit-Celsius table using for loop */

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

    /* copy input to output */

    int c;
    
    while ((c = getchar()) != EOF) {  /* c = getchar() != EOF -> c = (getchar() != EOF)*/
        putchar(c);
        c = getchar();
    }

    /* count characters in input */

    long nc; /* 32 bits (int: 16 bits) */

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);

    /* count characters in input using for loop */

    double nc;

    for (nc = 0; getchar() != EOF; ++nc)  /* all the work is done in the test, increment parts */
        ;  /* null statement; on a separate line for visibility */
    printf("%.0f\n", nc);

    /* count lines in input */

    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);

    /* count lines, words, and characters in input */

    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;  /* equivalent to nl = (nw = (nc = 0)) */
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c = '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    /* count digits, white space, others */

    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

    /* test power function */

    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2,i), power(-3,i));

    /* print the longest input line */
    
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
              max = len;
              copy(longest, line);
        }
    if (max > 0)  /* there was a line */
        printf("%s", longest);

    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
}
# Genome-Fractal
The "Chaos Game" is a popular algorithm for generating fractal patterns using numeric or discrete input sequences. By inputting a genomic sequence, a "chaos game representation" (CGR) of that sequence can be generated. This CGR can be used to study the characteristics of the genomic sequence.

The objective of this project is to develop a C program that can produce CGRs for genomic sequences. The program takes a single argument, a non-negative integer that is a power of 2. This value determines the size of the output CGR plot, which is N x N characters in size. The output is a text-based plot produced on the standard output. The program uses rational numbers to represent coordinates within the plot, and includes safeguards to prevent overflow during calculations.

To use the program, the user provides a genomic sequence on the standard input. The program then produces a CGR plot of the sequence, with each point (x,y) scaled to an integer value between 0 and N. The scaled coordinates for a point (x,y) are then recorded in an N x N character array, with the corresponding element set to an asterisk character ('*'). Once all points have been plotted, the contents of the array are output on the standard output, along with additional demarcation and labeling. The program is able to handle upper- and lower-case characters in the input sequence.

This project demonstrates my skills in C programming, including working with arrays, functions, and rational numbers. It also shows my ability to implement algorithms and prevent potential overflow in calculations. Additionally, the program has potential applications in bioinformatics for analyzing genomic sequences.

Overall, this C program provides a useful tool for studying the characteristics of genomic sequences using CGR plots.

## Intructions for Running the Application

* make
* /cgr Scale <"input sequence">output.pbm (Scale is an power of 2 integer in between 64 and 4096)
Have to have lnetpbm library in your system.


# Genome-Fractal
This project is a simple C program that produces Chaos Game Representations (CGRs) for genomic sequences. The program takes a genetic sequence as input and outputs a text-based plot of the CGR of the sequence. The program takes a single argument, a non-negative integer that is a power of 2, which determines the size of the text-based plot. The program uses rational numbers to represent CGR coordinates and prevents potential overflow during its calculations. The output is a demarcated and labelled plot of the CGR for the input sequence.

The program operates by initializing a character array representing the text-based plot, with all elements set to the space character. The input sequence is then used to determine the scaled coordinates for points in the CGR, which are then plotted in the character array by setting the corresponding elements to the asterisk character. Once all the points have been plotted, the contents of the array are output to the standard output with additional demarcation and labelling.

This project demonstrates my skills in C programming, including working with arrays, functions, and rational numbers. It also shows my ability to implement algorithms and prevent potential overflow in calculations. Additionally, the program has potential applications in bioinformatics for analyzing genomic sequences.

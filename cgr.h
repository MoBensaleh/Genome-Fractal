/**
 * Mohamed Bensaleh
 * Mob127
 * 11254030
 */
#ifndef CGR_H
#define CGR_H

/**
 * Minimum allowed value of Scale.
 */
#define MIN_SCALE 32

/**
 * Maximum allowed value of Scale.
 */
#define MAX_SCALE 4096

/**
 * The size of one dimension of the text-based plot area. It must be 
 * a power of 2, and be in the range 16 to 64, inclusive. 
 * The global variable Plot is of dimension Scale?—Scale.
 */
extern int Scale;


#endif
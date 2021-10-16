/**
 * Mohamed Bensaleh
 * Mob127
 * 11254030
 */
#ifndef CGR_AUX_H
#define CGR_AUX_H

#include <stdint.h>
#include <stdbool.h>

/**
 * The number of legal symbols (characters) in the input alphabet.
 */
#define NUM_NTIDES 4 

/**
 * Structure for a pair of values n,q representing the rational number n/q.
 */
typedef struct {
    uint64_t n, q;
} coord_t;

/**
 * The structure for a CGR plot point that is a pair of coordinates, 
 * each between 0 and 1 inclusive.
 */
typedef struct {
    coord_t x;
    coord_t y;
} point_t;

/**
 * The structure for representing nucleotides 
 * (i.e. the characters A, C, G, and T).
 */
typedef struct {
    char letter;
    point_t vertex;
} ntide_t;

/**
 * reduce_coord:
 *   If the denominator of the coordinate has its high-order bit set,
 *   then divides n and d by 2, else the result is the same as argument.
 * In:
 *   old_coord - coordinate to reduce.
 * Out:
 *   Returns reduced coordinate if needed, else returns the argument unchanged.
 * Assumes:
 *   No assumptions made.
 */ 
coord_t reduce_coord(coord_t old_coord);

/**
 * reduce_point:
 *   If either coordinate of point needs reducing, does it.
 * In:
 *   old_point - point which coordinates would be reduced if needed.
 * Out:
 *   Returns point with coordinates reduced (if needed).
 * Assumes:
 *   No assumptions made.
 */
point_t reduce_point(point_t old_point);

/**
 * determine_midpoint:
 *   Determines the midpoint between two points.
 *   The function is written so as to avoid overflow.
 * In:
 *   pnt1 - first point's coordinates.
 *   pnt2 - second point's coordinates.
 * Out:
 *   Returns the new point which is exactly between two given points.
 * Assumes:
 *   Denominators in the coordinates of the input points are powers of 2.
 *   Second point is going to have only 0/1 or 1/1 as possible coordinates.
 */
point_t determine_midpoint(point_t pnt1, point_t pnt2);

/**
 * cgr:
 *   If the input character is one of {A,C,G,T}, calculates midpoint of the
 *   reduced given point and the vertex corresponding to the input character,
 *   and plots it on the Plot array.
 * In:
 *   in_point - point to use.
 * Out:
 *   If the input char is {A,C,G,T}, character which corresponds to 
 *   the midpoint is set to '*'.
 *   Returns midpoint if the char is {A,C,G,T}, or input point otherwise.
 */
point_t cgr(point_t in_point, char in_char);

/**
 * is_power_of_2:
 *   Checks if the argument is a power of 2.
 * In:
 *   val - number to check.
 * Out:
 *   Returns true if the val is a power of 2, false otherwise.
 * Assumes:
 *   val is a positive integer.
 */
_Bool is_power_of_2(int val);

#endif
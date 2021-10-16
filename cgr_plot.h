/**
 * Mohamed Bensaleh
 * Mob127
 * 11254030
 */
#ifndef CGR_PLOT_H
#define CGR_PLOT_H
#include <netpbm/pbm.h>
#include "cgr_aux.h"

/**
 * The two-dimensional array of characters with the plot text-based image.
 * When created, has size Scale x Scale.
 */
extern bit **Plot;

/**
 * initialize_plot:
 *   Initialase an image using netPBM library.
 * In:
 *   No input arguments.
 * Out:
 *   A variable Plot is initialized.
 *   No return value.
 * Assumes:
 *   Presence of global variables Plot and Scale.
 */
void initialize_plot(void);


/**
 * output_plot:
 *   Outputs the plot stored in the globabl Plot array to a pmb-file.
 * In:
 *   No input arguments.
 * Out:
 *   No return value.
 * Assumes:
 *   Presence of global variables Plot and Scale.
 *   Plot is of type char** and of dimension Scale X Scale.
 */
void output_plot(void);

/**
 * scale_coord:
 *   Given that coord represents a rational number n/d, returns the 
 *   integer portion of (Scale*n/d). 
 *   A fractional result is rounded down to the nearest integer. 
 *   The function is written so as to avoid overflow.
 * In:
 *   coord - rational number to return the scale for.
 * Out:
 *   Returns the integer portion of (Scale*n/d) rounded down.
 * Assumes:
 *   Presence of global variable Scale.
 *   coord.d is not 0.
 */
unsigned scale_coord(coord_t coord);

/**
 * plot_point:
 *   Puts a scaled point onto the Plot with '*' character.
 * In:
 *   point - coordinates of the point to plot.
 * Out:
 *   Character in the Plot array which corresponds to the scaled point is 
 *   set to '*'.
 *   No return value.
 * Assumes:
 *   Presence of global variables Plot and Scale.
 *   Plot is of type char** and of dimension Scale X Scale.
 */
void plot_point(point_t point);

/**
 * clean_plot:
 *   Clean all memory used by netPBM library
 * In:
 *   No input arguments.
 * Out:
 *   No return value.
 * Assumes:
 *   Presence of global variables Plot and Scale.
 */
void clean_plot(void);

#endif
/**
 * Mohamed Bensaleh
 * Mob127
 * 11254030
 */
#include <stdlib.h>
#include <stdio.h>
#include "cgr_plot.h"
#include "cgr.h"

bit **Plot;

void initialize_plot(void) {
    Plot = pbm_allocarray(Scale, Scale);
    if (!Plot) {
        fprintf(stderr, "Error allocated memory for Plot\n");
        exit(EXIT_FAILURE);
    }
}


void output_plot(void) {
    int row;

    pbm_writepbminit(stdout, Scale, Scale, false);

    /* Output rows in reverse order */
    for (row=Scale-1; row >=0; row--)
         pbm_writepbmrow(stdout, Plot[row], Scale, false);
}

unsigned scale_coord(coord_t coord) {
    /* Shift n and d simultaniously until d == Scale */
    while (coord.q > (uint64_t) Scale) {
        coord.q >>= 1;
        coord.n >>= 1;
    }
    while (coord.q < (uint64_t) Scale) {
        coord.q <<= 1;
        coord.n <<= 1;
    }

    /* Finally, result will be in n*/
    return coord.n;
}

void plot_point(point_t point) {
    int row, col;

    /* Scale both coordinates to get where to put '*' */
    row = scale_coord(point.y);
    col = scale_coord(point.x);

    /* Put the asterisk */
    Plot[row][col] = PBM_BLACK;    
}

void clean_plot(void) {
   pbm_freearray(Plot, Scale);
}

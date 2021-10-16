/**
 * Mohamed Bensaleh
 * Mob127
 * 11254030
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "cgr.h"
#include "cgr_plot.h"

int Scale;

int main(int argc, char *argv[]) {
    point_t curr_point;
    int i, c;

    /* Check and that scale argument is present */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Parse scale argument and verify it's valid */
    Scale = atoi(argv[1]);
    if (Scale < MIN_SCALE) {
        fprintf(stderr, "Scale too small\n");
        return EXIT_FAILURE;
    }
    if (Scale > MAX_SCALE) {
        fprintf(stderr, "Scale too large\n");
        return EXIT_FAILURE;
    }
    if (!is_power_of_2(Scale)) {
        fprintf(stderr, "Scale must be a power of 2\n");
        return EXIT_FAILURE;
    }
    /* Init netPBM library */
    pm_init("cgr", 0);

    /* Initialize the Plot array */
    initialize_plot();

    /* Initialize starting CGR point in the middle of the plot */
    curr_point.x.n = 1;
    curr_point.x.q = 2;
    curr_point.y.n = 1;
    curr_point.y.q = 2;

    /* Update current point for each character read */
    while ((c = getc(stdin)) != EOF) {
        curr_point = cgr(curr_point, (char) c);
    }

    /* Print out the plot */
    output_plot();

    /* Cleanup the Plot array memory */
    clean_plot();

    /* Exit successfully */
    return EXIT_SUCCESS;
}
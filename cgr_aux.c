/**
 * Mohamed Bensaleh
 * Mob127
 * 11254030
 */
#include <ctype.h>
#include "cgr_aux.h"
#include "cgr_plot.h"

coord_t reduce_coord(coord_t old_coord) {
    /* Check if the denominator has high-order bit set */
    if (old_coord.q & (1ULL << 63)) {
        /* If so, divide nominator and denominator by 2 */
        old_coord.n >>= 1;
        old_coord.q >>= 1;
    }

    /* Return modified (or unmodified) coordinates */
    return old_coord;
}

point_t reduce_point(point_t old_point) {
    /* Reduce does nothing if not needed, so just reduce both coordinates */
    old_point.x = reduce_coord(old_point.x);
    old_point.y = reduce_coord(old_point.y);

    /* Return modified (or unmodified) point */
    return old_point;
}

point_t determine_midpoint(point_t pnt1, point_t pnt2) {
    /* If the second point's X is 1, then add denominator to nominator */
    if (pnt2.x.n == 1) {
        pnt1.x.n += pnt1.x.q;
    }

    /* And 'divide' x by 2 */
    pnt1.x.q <<= 1;

    /* If the second point's Y is 1, then add denominator to nominator */
    if (pnt2.y.n == 1) {
        pnt1.y.n += pnt1.y.q;
    }

    /* And 'divide' y by 2 */
    pnt1.y.q <<= 1;

    /* Return modified point */
    return pnt1;
}

point_t cgr(point_t in_point, char in_char) {
    ntide_t nucleotide;
    point_t midpoint;

    /* Convert character to uppercase in case it wasn't already */
    in_char = toupper(in_char);

    /* Recognise which nucleotide we're processing */
    nucleotide.letter = in_char;
    nucleotide.vertex.x.q = 1;
    nucleotide.vertex.y.q = 1;
    switch (in_char) {
        case 'A':
            nucleotide.vertex.x.n = 0;
            nucleotide.vertex.y.n = 0;
            break;
        case 'C':
            nucleotide.vertex.x.n = 0;
            nucleotide.vertex.y.n = 1;
            break;
        case 'T':
            nucleotide.vertex.x.n = 1;
            nucleotide.vertex.y.n = 0;
            break;
        case 'G':
            nucleotide.vertex.x.n = 1;
            nucleotide.vertex.y.n = 1;
            break;
        default:
            /* Just skip doing anything if character is not {A, C, G, T} */
            return in_point;
    }

    /* Reduce the current point if necessary */
    in_point = reduce_point(in_point);

    /* Calculate midpoint between starting point and nucleotide vertex point */
    midpoint = determine_midpoint(in_point, nucleotide.vertex);

    /* Plot the point with '*' */
    plot_point(midpoint);

    /* Return calculated midpoint */
    return midpoint;
}

_Bool is_power_of_2(int val) {
    /* As the val is > 0, we can check if only 1 bit is set */
    return (val & (val - 1)) == 0;
}

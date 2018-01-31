#include <stdio.h>
#include <stdlib.h>

#include "djs.h"

int main() {
    djs *g = newdjs();
    for (int i = 0; i < 51; i++)
        makeset(g, NULL);
    printf("Finding 4: %d\n", find(g, 4));
    printf("Finding 8: %d\n", find(g, 8));
    printf("Finding 7: %d\n", find(g, 7));
    printf("Finding 9: %d\n", find(g, 9));
    printf("\nUnioning 4 and 8, 7 and 9\n\n");
    setunion(g, 4, 8);
    setunion(g, 7, 9);
    printf("Finding 4: %d\n", find(g, 4));
    printf("Finding 8: %d\n", find(g, 8));
    printf("Finding 7: %d\n", find(g, 7));
    printf("Finding 9: %d\n", find(g, 9));
    printf("Same 4 and 9: %d\n", same(g, 4, 9));
    printf("Same 7 and 9: %d\n", same(g, 7, 9));
    printf("\nUnioning 4 and 7\n\n");
    setunion(g, 9, 8);
    printf("Finding 4: %d\n", find(g, 4));
    printf("Finding 8: %d\n", find(g, 8));
    printf("Finding 7: %d\n", find(g, 7));
    printf("Finding 9: %d\n", find(g, 9));
    printf("Same 4 and 9: %d\n", same(g, 4, 9));
    printf("Same 7 and 9: %d\n", same(g, 7, 9));
    freedjs(g);
    return 0;
}

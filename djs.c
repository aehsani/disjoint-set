#include <stdio.h>
#include <stdlib.h>

#include "djs.h"

//Returns a new disjoint set
djs *newdjs() {
    djs *g;
    g = (djs *) malloc(sizeof(djs));
    if (!g) {
        printf("Error allocating memory\n");
        return NULL;
    }
    g->avail = 0;
    return g;
}

//Frees information container stored in each element
void freewrapper(wrapper *w) {
    if (!w)
        return;
    //free all content stored in the wrapper
    free(w);
}

//Frees individual element
void freeelement(elem *x) {
    freewrapper(x->info);
    free(x);
}

//Frees memory associated with disjoint set
void freedjs(djs *g) {
    for (int i = 0; i < g->avail; i++)
        freeelement(*(g->elements + i));
    free(g);
}

//Adds element into a disjoint set
void makeset(djs *g, wrapper *w) {
    if (g->avail >= MAX_ELEMS) {
        printf("Disjoint set is already full\n");
        return;
    }
    elem *x = (elem *) malloc(sizeof(elem));
    x->key = g->avail;
    x->p_key = x->key;
    x->rank = 0;
    x->info = w;
    *(g->elements + g->avail) = x;
    g->avail += 1;
}

//Returns element at a given index in disjoint set
elem *getelem(djs *g, int k) {
    if (k < 0 || k >= g->avail) {
        return NULL;
    }
    return *(g->elements + k);
}

//Returns information wrapper from an element
wrapper *getinfo(djs *g, int k) {
    elem *x;
    x = getelem(g, k);
    if (x)
        return x->info;
    return NULL;
}

//Recursively finds parent and uses path compression
int find(djs *g, int k) {
    int p;
    elem *x;
    x = getelem(g, k);
    if (!x)
        return -1;
    if (x->p_key == x->key)
        return x->key;
    p = find(g, x->p_key);
    x->p_key = p;
    return p;
}

//Tests if two elements are in the same set
int same(djs *g, int i, int j) {
    int x, y;
    x = find(g, i);
    y = find(g, j);
    if (x < 0 || y < 0)
        return 0;
    return find(g, i) == find(g, j);
}

//Unites two sets with given elements (union-rank)
void setunion(djs *g, int i, int j) {
    i = find(g, i);
    j = find(g, j);
    if (i == j || i < 0 || j < 0)
        return;
    elem *x, *y;
    x = getelem(g, i);
    y = getelem(g, j);
    if (x->rank == y->rank) {
        x->rank += 1;
        y->p_key = x->key;
    }
    else if (x->rank > y->rank)
        y->p_key = x->key;
    else
        x->p_key = y->key;
}

#ifndef DJS_H
#define DJS_H

#include "elem.h" 

#define MAX_ELEMS 50

typedef struct {
    elem *elements[MAX_ELEMS];
    int avail;
} djs;

djs *newdjs();
void freewrapper(wrapper *w);
void freeelement(elem *x);
void freedjs(djs *g);
void makeset(djs *g, wrapper *w);
elem *getelem(djs *g, int k);
wrapper *getinfo(djs *g, int k);
int find(djs *g, int k);
int same(djs *g, int i, int j);
void setunion(djs *g, int i, int j);


#endif

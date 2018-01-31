#ifndef ELEM_H
#define ELEM_H

typedef struct {
    //Insert contained info here
} wrapper;

typedef struct {
    int key;
    int p_key;
    int rank;
    wrapper *info;
} elem;

#endif

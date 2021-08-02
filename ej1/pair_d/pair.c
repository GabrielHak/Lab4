#include <stdlib.h>

#include "pair.h"

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(elem x, elem y){
    pair_t newPair;
    newPair = malloc(sizeof(struct s_pair_t));
    newPair->fst = x;
    newPair->snd = y;
    return newPair;
}

elem pair_first(pair_t p){
    return p->fst;
}

elem pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    return pair_new(p->snd, p->fst);
}

pair_t pair_destroy(pair_t p){
    free(p);
    p = NULL;
    return p;
}

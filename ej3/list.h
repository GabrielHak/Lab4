#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct _list * list;
typedef int list_elem;

list empty();

list addl(list l, list_elem e);

list destroy(list l);

bool is_empty(list l);

list_elem head(list l);

list tail(list l);

list addr(list l, list_elem e);

unsigned int length(list l);

list concat(list l, list m);

list_elem index(list l, unsigned int i);

list take(list l, unsigned int t);

list drop(list l, unsigned int d);

list copy(list l);

#endif
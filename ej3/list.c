#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#include "list.h"

struct _list{
    list_elem e;
    list next;
};

list empty(){
    list new = NULL;
    return new;
}

list addl(list l, list_elem e){
    list aux;
    aux = malloc(sizeof(struct _list));
    aux->e = e;
    aux->next = l;
    l = aux;
    aux = NULL;
    return l;
}

list destroy(list l){
    while(!is_empty(l)){
        l = tail(l);
    }
    return l;
}

bool is_empty(list l){
    return l == NULL;
}

list_elem head(list l){
    assert(!is_empty(l));
    return l->e;
}

list tail(list l){
    assert(!is_empty(l));
    list aux = l;
    l = l->next;
    aux->next = NULL;
    free(aux);
    return l;
}

list addr(list l, list_elem e){

    list aux2 = empty();
    aux2 = malloc(sizeof(struct _list));
    aux2->e = e;
    aux2->next = NULL;

    list aux = l;
    
    if(!is_empty(aux)){
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = aux2;
    }else {
        l = aux2;
    }
    aux = NULL;
    aux2 = NULL;
    return l;
}

unsigned int length(list l){
    unsigned int cont = 0;
    list aux = l;
    
    if(!is_empty(l)){
        cont++;
        while(aux->next != NULL){
            aux = aux->next;
            cont++;
        }
    }

    return cont;
}

list concat(list l, list m){
    list aux = l;
    
    if(!is_empty(l)){
        while(aux->next != NULL){
            aux = aux->next;
        }
    }
    aux->next = m;
    return l;
}

list_elem index(list l, unsigned int i){
    assert(length(l) > i);
    list aux = l;
    unsigned int n = 0;
    while(n < i){
        aux = aux->next;
        n++;
    }
    return aux->e;
}

list take(list l, unsigned int t){
    if(is_empty(l) || length(l) < t){
        return l;
    }

    list aux = l;
    unsigned int c = 1;
    while(c < t){
        aux = aux->next;
        c++;
    }
    list aux2 = aux->next;
    aux->next = NULL;
    aux2 = destroy(aux2);
    aux = NULL;
    return l;
}

list drop(list l, unsigned int d){
    unsigned int c = d;
    while(c > 0u && !is_empty(l)){
        l = tail(l);
        c--;
    }
    return l;
}

list copy(list l){
    list copy = empty();
    list aux = l;
    while(aux->next != NULL){
        copy = addr(copy, aux->e);
        aux = aux->next;
    }
    copy = addr(copy, aux->e);
    aux = NULL;
    return copy;
}
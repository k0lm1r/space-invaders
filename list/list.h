#pragma once
#include "libraries.h"

typedef struct linkedList {
    void *data;
    struct linkedList *next;
    struct linkedList *prev;
} LinkedList;

typedef struct list {
    int count;
    LinkedList *list;
}List;

List append(List ls, void *data);
void* delete(List *ls, int index);
void* take(List ls, int index);
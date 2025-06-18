#include "list.h"

List append(List ls, void *data) {
    LinkedList *newElement = (LinkedList*)malloc(sizeof(LinkedList));
    newElement->data = data;
    if (!ls.list) {
        ls.list = newElement;
        ls.list->next = ls.list->prev = NULL;
    } else {
        newElement->next = ls.list;
        if (ls.count == 1) {
            newElement->prev = ls.list;
            ls.list->next = newElement;
        } else {
            newElement->prev = ls.list->prev;
            ls.list->prev->next = newElement;
        }
        ls.list->prev = newElement;
    }
    ls.count++;
    return ls;
}

void *delete(List *ls, int index) {
    LinkedList *deletedNode = ls->list;
    void *data;
    if (ls->count == 1) {
        ls->count = 0;
        data = ls->list->data;
        free(ls->list);
        ls->list = NULL; 
        return data;
    }
    if (index == 0 || ls->count + index == 0) {
        ls->list = ls->list->next;
    } else if (index > 0) {
        for (int i = 1; i <= index && deletedNode; deletedNode = deletedNode->next, ++i);
    } else 
        for (int i = -1; i >= index && deletedNode; deletedNode = deletedNode->prev, --i);
    
    deletedNode->prev->next = deletedNode->next;
    deletedNode->next->prev = deletedNode->prev;
    data = deletedNode->data;
    free(deletedNode);
    ls->count--;
    return data;
}

void *take(List ls, int index) {
    if (index > 0)
        for (int i = 1; i <= index; ls.list = ls.list->next, ++i);
    else if (index < 0)
        for (int i = -1; i >= index; ls.list = ls.list->prev, --i);
    return ls.list->data;
}
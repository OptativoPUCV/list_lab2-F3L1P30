#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode( const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
//Ejercicio 1
List * createList() {
     List *ll = (List*)malloc(sizeof(List));
     ll->current = NULL;
     ll->head = NULL;
     ll->tail = NULL;
     return ll;
}

//Ejercicio 2
void * firstList(List * list) {
  
  if(list == NULL ) return NULL;
  list->current = list->head;
  return (void*)(list->current->data);
}

void * nextList(List * list) {

  if(list->current == NULL) return NULL;
  if(list->current->next == NULL) return NULL;
  list->current = list->current->next;
  return (void*)list->current->data;

}

//Ejercicio 3
void * lastList(List * list) {
    list->current = list->tail;
    return (void*)list->current->data;
}

void * prevList(List * list) {

  if(list->current == NULL) return NULL;
  if(list->current->prev == NULL) return NULL;
  list->current = list->current->prev;
  return (void*)list->current->data;
}

//Ejercicio 4
void pushFront(List * list,  const void * data) {
    Node *n = createNode(data);
    //list->head = n;
    n->next = list->head;
    list->head = n;
    list->tail = n;
  
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

//Ejercicio 5
void pushCurrent(List * list, const void * data) {
 
  Node *n = createNode(data);
  list->current->next = n;
  n->prev = list->head;
  list->tail = n;
  list->tail->prev = list->current;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

//Ejercicio 6
void * popCurrent(List * list) {
  Node *n = createNode(list->current);

    list->head = list->current;
  if(list->current->prev != NULL) 
    list->current->prev = n->next;
  if(list->current->next != NULL)
    list->current->prev = n->prev;
  
  free(n);

  return (void*) list->current->data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
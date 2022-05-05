#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq->size == 0 || pq == NULL) return NULL;

  if (pq->heapArray == NULL) return NULL;
  
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){
  if (pq->size == 0 || pq == NULL) return;

  if (pq->heapArray == NULL) return;

  pq->heapArray[0].data = pq->heapArray[pq->size-1].data;
  pq->heapArray[0].priority = pq->heapArray[pq->size-1].priority;
  pq->heapArray[pq->size-1].data = NULL;
  pq->size--;

  if (pq->heapArray[1].priority > pq->heapArray[2].priority){

    if (pq->heapArray[0].priority > pq->heapArray[1].priority) return;

    void* data = pq->heapArray[0].data;
    int prioridad = pq->heapArray[0].priority;

    pq->heapArray[0].priority = pq->heapArray[1].priority;
    pq->heapArray[0].data = pq->heapArray[1].data;

    pq->heapArray[1].priority = prioridad;
    pq->heapArray[1].data = data;
  }
  else{

    if (pq->heapArray[0].priority > pq->heapArray[2].priority) return;
    
    void* data = pq->heapArray[0].data;
    int prioridad = pq->heapArray[0].priority;

    pq->heapArray[0].priority = pq->heapArray[2].priority;
    pq->heapArray[0].data = pq->heapArray[2].data;

    pq->heapArray[2].priority = prioridad;
    pq->heapArray[2].data = data;
  }
}

Heap* createHeap(){
  Heap* kurisu = (Heap*) malloc (sizeof(Heap));

  if (kurisu == NULL) return NULL;

  kurisu->size = 0;
  kurisu->capac = 3;
  kurisu->heapArray = (heapElem *) malloc (sizeof(heapElem)*(kurisu->capac));

  if (kurisu->heapArray == NULL) return NULL;

   return kurisu;
}

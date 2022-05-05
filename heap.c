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

void Intercambia(Heap h, int i1, int i2) {
    int aux = h->heapArray[i1].priority;
    void* data = h->heapArray[i1].data;
  
    h->heapArray[i1].priority = h->heapArray[i2].priority;
   h->heapArray[i1].data = h->heapArray[i2].data;
  
    h->heapArray[i2].priority = aux;
  h->heapArray[i2].data = data;
}

int father(Heap h, int i) {
    return (i-1)/2;
}

void Subir(Heap h, int i) {
    int padre;

    while(i > 0 && h->heapArray[i].priority > h->heapArray[padre=father(h, i)].priority) {
        Intercambia(h, i, padre);
        i = padre;
    }
}

void resizeHeap(Heap* pq){
  pq->capac = (pq->capac*2)+1;
  pq->heapArray = realloc(pq->heapArray, pq->capac);
}

void* heap_top(Heap* pq){
  if (pq->size == 0 || pq == NULL) return NULL;

  if (pq->heapArray == NULL) return NULL;
  
  return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
  if (pq->size == pq->capac){
    resizeHeap (pq);
  }

  pq->heapArray[pq->size].priority = priority;
  subir (pq, priority);
}

void heap_pop(Heap* pq){
  if (pq->size == 0 || pq == NULL) return;

  if (pq->heapArray == NULL) return;

  pq->heapArray[0].data = pq->heapArray[pq->size-1].data;
  pq->heapArray[0].priority = pq->heapArray[pq->size-1].priority;
  pq->heapArray[pq->size-1].data = NULL;
  pq->heapArray[pq->size-1].data = 0;
  pq->size--;

  if (pq->heapArray[1].priority > pq->heapArray[2].priority){
    void* data = pq->heapArray[0].data;
    int prioridad = pq->heapArray[0].priority;

    pq->heapArray[0].priority = pq->heapArray[1].priority;
    pq->heapArray[0].data = pq->heapArray[1].data;

    pq->heapArray[1].priority = prioridad;
    pq->heapArray[1].data = data;
  }
  else{   
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

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

void intercambia(Heap* h, int i1, int i2) {
  int aux = h->heapArray[i1].priority;
  void* data = h->heapArray[i1].data;   
  
  h->heapArray[i1].priority = h->heapArray[i2].priority;
  h->heapArray[i1].data = h->heapArray[i2].data;
  
  h->heapArray[i2].priority = aux;
  h->heapArray[i2].data = data;
}

int left(Heap* h, int i) {
    return 2*i+1;
}

int right(Heap* h, int i) {
    return 2*i+2;
}

int father(Heap* h, int i) {
    return (i-1)/2;
}

void down(Heap* h, int i){
    int iIzq, iDer, maximo;
    heapElem* arreglo = h->heapArray;

    maximo = i;
    do{
        i = maximo;
        iIzq=left(h, i);
        iDer=right(h, i);
        if(arreglo[i].priority < arreglo[iIzq].priority && arreglo[iDer].priority < arreglo[iIzq].priority) maximo = iIzq;
        //if(arreglo[i].priority < arreglo[iDer].priority && arreglo[iIzq].priority < arreglo[iDer].priority) maximo = iDer;
        if(i != maximo) intercambia(h, i, maximo);
    } while (i != maximo && maximo < h->size/2);
}

void up(Heap* h, int i) {
    int padre;
    heapElem* arreglo = h->heapArray;

    while(i > 0) 
    {
      if (arreglo[i].priority > arreglo[padre=father(h, i)].priority){
        intercambia(h, i, padre);
        i = padre;
      }
      else{
        break;
      }
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
  pq->heapArray[pq->size].data = data;
  up (pq, pq->size);
  pq->size++;
}

void heap_pop(Heap* pq){
  pq->heapArray[0].data = pq->heapArray[pq->size-1].data;
  pq->heapArray[0].priority = pq->heapArray[pq->size-1].priority;
  pq->heapArray[pq->size-1].data = NULL;
  pq->heapArray[pq->size-1].data = 0;
  down(pq, 0);
  pq->size--;
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

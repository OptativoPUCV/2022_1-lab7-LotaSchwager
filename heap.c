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
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* kurisu = (Heap*) malloc (sizeof(Heap));

  if (kurisu == NULL) return NULL;

  kurisu->heapArray = (heapElem *) malloc (sizeof(heapElem));
  kurisu->size = 0;
  kurisu->capac = 0;

   return kurisu;
}

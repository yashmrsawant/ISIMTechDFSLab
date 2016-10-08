/***********************************************************************************************
Name : Yash M Sawant
Roll : MTC - 1614
Date : 5th October, 2016
Desc : Prims Algorithm
Acks : Using Heap [Book : CLRS] 
***********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include "prims.h"


/*******
**
*	a) Given unordered array, convert to heap
*	b) Insert into heap
*	c) Delete Min/Max
*	d) Merge K sorted list
*	e) Find K largest values in an array
*	f) 
*******/



int main(int argc, char* argv[]) {
	
	int i;
	int nodeId, weight;
	struct aList** adjacencyList; 	
	if(argc != 2) {
		printf("Usage : ./a.out {|V|}\n");
		exit(-1);
	}
	
	adjacencyList = (struct aList** )(malloc(sizeof(struct aList*) * atoi(argv[1]))); // Adjacency List allocated to size of {|V|}
	for(i = 0 ; i < atoi(argv[1]) ; i ++) {
		adjacencyList[0] = (struct aList*)(malloc(sizeof(struct aList)));
		while(TRUE) {
			scanf("%d", &nodeId);
			pNode = adjacencyList[0];
			if(nodeId > 0) {
				// If <code>nodeId</code> is gt 0 then Insert into adjacencyList[0]
				scanf("%d", &weight);
				pNode -> next = (struct aList*)(malloc(sizeof(struct aList)));

				pNode -> next -> vId = nodeId;
				pNode -> next -> weight = weight;
				pNode = pNode -> next;
			} else {
				break;	
			}
		} 
	}	
			
	
	return 0;	
}

/******************************************************
*	@src : src 
*	@i : ith byte of src
*	@j : jth byte of dest
*	@sizeInBytes : bytes to copied
******************************************************/
void copy(void* src, int i, void* dest, int j, int sizeInBytes) {
	void * modifiedSrc = ((char *)(src) + i * sizeInBytes);
	void * modifiedDest = ((char *)(src) + i * sizeInBytes);
	memcpy(modifiedSrc, modifiedDest, sizeInBytes);
}
void buildHeap(void* arr, int n, int elementSize, int (*sortCmp)(void*, void* ), int maxMinFlag) {	
	for(i = n / 2 - 1; i >= 0 ; i --) {
		heapify(arr, i, 
	}
}
void heapify(void* arr, int i, int elementSize, int n, int maxMinFlag, int (*sortCmp)(void *, void*)) {
		void* temp = (void*)(malloc(elementSize));		
		if((2 * i + 1) < (n - 1)) {
			if((*sortCmp)(((char*)(arr) + i * elementSize), (char) == (maxMinFlag)) {
				copy(arr, 2 * i + 1, temp, 0, elementSize);
`				k = 2 * i + 1;
			}
		}
		if((2 * i + 2) < (n - 1)) {
			if((*sortCmp)(arr[i], arr[2 * i + 2]) == (maxMinFlag)) {
				copy(arr, 2 * i + 1, temp, 0, elementSize);
				k = 2 * i + 2;
			}
		}
		if((*sortCmp)((char*)(arr) + (, temp) != 0) {
			copy(arr, i, arr, k, sizeInBytes);
			copy(temp, 0, arr, i, 0, sizeInBytes);
			heapify(arr, k, elementSize, sizep, maxMinFlag, sortCmp);
		}
		free(temp);
}
void insert(void* arr, int p, int* sizep, int* maxSize, void* elementToBeInserted, 
				int elementSize, int (*sortCmp)(void*, void*), int maxMinFlag) {
	
	if(p > 0) {
		void* temp = (void*)(malloc(elementSize));
		int parent = 0;
		if((*maxSize) <= (*sizep + 1)) {
			// If Maximum Size of arr exceeded, reallocate arr to maxSize * 2
			*maxSize = *maxSize * 2;
			arr = realloc(arr, (*maxSize));
		}
		copy(arr, n, elementToBeInserted, 0, elementSize);
		*sizep = *sizep + 1;
		if(p % 2 == 0) 
			parent = p / 2 - 1;
		else
			parent = p / 2;
		if((*sortCmp)(arr[p / 2], arr[p]) == maxMinFlag) {
			// Exchange arr[p / 2] and arr[p]
			copy(arr, p, temp, 0, elementSize		
			copy(arr, parent, arr, p, elementSize);
			copy(temp, 0, arr, parent, elementSize);
		}
		insert(arr, parent, sizep, maxSize, elementToBeInserted, elementSize, sortCmp);
		free(temp);	
	}
	
}
void delete(void* arr, int 
void heapSort(void* arr, int* n, int sizeInBytes, int (*sortCmp)(void *, void *)) {
		buildHeap(arr, n, sortCmp, -1); // -1 for Max Heap
		
}

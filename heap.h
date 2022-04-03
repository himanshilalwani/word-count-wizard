#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<exception>
#include<math.h>
#include<iomanip>
#include<unistd.h>
#include<sstream>
#include "hashnode.h"

using namespace std;

class Heap
{
	private:
		HashNode **array; // an array consisting of pointers to hash nodes
		int capacity;
		int size;
		friend class HashTable;
	public:
		Heap();
		// ~Heap();
		void insert(HashNode* key); // insert hashnode in the heap
		HashNode* removeMax(); // removes the hash node with maximum value from the heap
		HashNode* getMax(); // returns the hash node with maximum value
		int parent(int k); // returns the index to the parent of the current node
		int left(int k); // returns the index to the left child
		int right(int k); // returns the index to the right child
		void siftup(int k); // function that helps maintain the max heap property when inserting
		void siftdown(int k); // function that helps maintain the max heap property when removing
		void print(int k=-1);
	private:
		void adjustSize(); // adjusting size of the array
};

#endif
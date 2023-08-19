#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "hashnode.h"
#include "vector.h"
#include "heap.h"
#include<iostream>
#include<string>

using namespace std;
class HashTable
{
	private:
		MyVector *buckets; // Array of vectors of type Hash Nodes
		int size;					    // Total unique words in the hashtable
		int capacity;				    // Total Capacity of HashTable
		int collisions;					// Total Number of Collisions
		int total_size;                 // Total words in the hashtable
		Heap myHeap;                    // Heap for finding the word with maximum frequency
		
	public:
		HashTable(int capacity); // constructor
		unsigned long hashCode2(string key); // polynomial hash
		unsigned long hashCode1(string key); // Cycle Shift Hash Function (Compression Method -> Division)
		unsigned long hashCode5(string key); // Polynomial Hash Function 2
		unsigned long hashCode3(string key); // Summation Hash Function
		unsigned long hashCode4(string key); // Cycle Shift Hash Function (Compression Method -> MAD)
		void insert(string key, int a); // Inserts a key into the hash function, the second argument refers to the number of the hash function
		int find_freq(string key, int a); // finds frequency of the given key, the second argument refers to the number of the hash function
		int count_unique_words(); // returns the number of unique words in the text
		int count_collisions(); // returns the number of collisions
		int count_words(); // returns the total number of words in the text
		void commands(); // displays the available commands
		void insert_heap(); // inserts the nodes into the heap
		string find_max(); // finds the word with maximum freq
		int select_hashFun(); // allows the user to select from the available hash functions

};

#endif
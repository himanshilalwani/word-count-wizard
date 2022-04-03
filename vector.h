#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include <stdexcept>
#include<sstream>
#include "hashnode.h"
using namespace std;
// template <typename T>
class MyVector
{
	private:
		HashNode **data;						//pointer to (array) to store elements
		int v_size;						//current size of vector (number of elements in vector)
		int v_capacity;					//capacity of vector
		friend class HashTable;
	public:
		MyVector();						//No argument constructor
		MyVector(int cap);				//One Argument Constructor
		~MyVector();					//Destructor
		void push_back(HashNode* element);		//Add an element at the end of vector
		void insert(int index, HashNode* element); //Add an element at the index 
		void erase(int index);			//Removes an element from the index
		HashNode* operator[](int index);		//return reference of the element at index
		HashNode* at(int index); 				//return reference of the element at index
		const HashNode* front();				//Returns reference of the first element in the vector
		const HashNode* back();				//Returns reference of the Last element in the vector
		int size() const;				//Return current size of vector
		int capacity() const;			//Return capacity of vector
		bool empty() const; 			//Rturn true if the vector is empty, False otherwise
		void shrink_to_fit();			//Reduce vector capacity to fit its size
		void display();

};

#endif
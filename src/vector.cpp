#include<iostream>
#include<cstdlib>
#include<iomanip>
#include <stdexcept>
#include<sstream>
#include "vector.h"
//======================================
void MyVector::display()
{
	cout<<"╔════";
	for(int i=0; i<v_capacity-1; i++)
		cout<<"╦════";	
	cout<<"╗ size = "<<v_size<<endl;
	
	for(int i=0; i<v_capacity; i++)
	{
		if(i<v_size)
			cout<<"║"<<setw(4)<<data[i];
		else
			cout<<"║"<<setw(4)<<" ";		
	}
	if(v_size==0) cout<<"║    ";
	cout<<"║"<<endl<<"╚════";
	for(int i=0; i<v_capacity-1; i++)
		cout<<"╩════";
	cout<<"╝ capacity = "<<v_capacity<<endl;	
}
//======================================
MyVector::MyVector() // constructor
{
	v_size = 0;
	v_capacity = 20;
	data = new HashNode*[v_capacity];
}
//======================================
MyVector::MyVector(int cap) // constructor with an argument
{
	v_size = 0;
	v_capacity = cap;
	data = new HashNode*[v_capacity];
}
//======================================
MyVector::~MyVector() // destructor
{
	delete [] data;
}
//======================================
int MyVector::size() const //Return current size of vector
{
	return v_size;
}
//======================================
int MyVector::capacity() const //Return capacity of vector
{
	return v_capacity;
}
//======================================
bool MyVector::empty() const //Rturn true if the vector is empty, False otherwise
{
	return v_size == 0;
}
//======================================
void MyVector::push_back(HashNode* element) // inserts a hashnode at the end of the vector
{
	if (v_size >= v_capacity)
	{
		HashNode** arr;
		if (v_capacity==0)
		{
			arr = new HashNode*[1];
			v_capacity = 1;
		}
		else
		{
			arr = new HashNode*[v_capacity*2];
			v_capacity = v_capacity*2;
		}


		for (int i = 0; i < v_size; i++)
		{
			arr[i] = data[i];
		}

		if (data!=NULL) delete [] data;

		data = arr;
	}

	data[v_size] = element;
	v_size = v_size + 1;

}
//======================================
void MyVector::erase(int index) //Removes an element from the index
{
	if (0<=index && index<v_size)
	{
		for(int j = index+1;j<v_size;j++)
		{
			data[j-1] = data[j];
		}
		v_size = v_size-1;
	}
	else
	{
		throw(out_of_range("Index out of range"));
		// cout<<"Index out of range"<<endl; //error
	}
}
//======================================
HashNode* MyVector::operator[](int index) //return reference of the element at index
{
	return data[index];
}
//======================================
HashNode* MyVector::at(int index) //return reference of the element at index
{
	if (0<=index && index<v_size)
	{
		return data[index];
	}
	else
	{
		throw(out_of_range("Index out of range"));
	}	
}
//======================================
const HashNode* MyVector::front() //Returns reference of the first element in the vector
{
	if (empty()) throw(out_of_range("Empty Vector"));
	return data[0]; 
}
//======================================
const HashNode* MyVector::back() //Returns reference of the Last element in the vector
{
	if (empty()) throw(out_of_range("Empty Vector"));
	return data[v_size-1]; 
}
//======================================
void MyVector::insert(int index, HashNode* element) //Add an element at the index 
{
	if (index < 0 || index > v_size) throw (out_of_range("Index out of range"));
	if (v_size == v_capacity)
	{
		HashNode** arr;
		if (v_capacity==0)
		{
			arr = new HashNode*[1];
			v_capacity = 1;
		}
		else
		{
			arr = new HashNode*[v_capacity*2];
			v_capacity = v_capacity*2;
		}


		for (int i = 0; i < v_size; i++)
		{
			arr[i] = data[i];
		}

		if (data!=NULL) delete [] data;

		data = arr;
	}

	for (int j = v_size-1; j>=index; j--)
	{
		data[j+1] = data[j];
	}

	data[index] = element;
	v_size++;
}
//======================================
void MyVector::shrink_to_fit() //Reduce vector capacity to fit its size
{
	if (v_size < v_capacity)
	{
		HashNode** arr = new HashNode*[v_size];

		for (int i = 0; i < v_size; i++)
		{
			arr[i] = data[i];
		}

		delete [] data;

		data = arr;
		v_capacity = v_size; 
	}
}
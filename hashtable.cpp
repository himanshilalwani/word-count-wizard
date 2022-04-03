#include "hashtable.h"
#include<math.h>
// ================================
HashTable::HashTable(int capacity)
{
	buckets = new MyVector[capacity];			// Array of vectors of Hash Nodes
	this->capacity = capacity;
	this->size = 0; // unique words
	this->collisions = 0; // collisions
	this->total_size = 0; // total words
}
// ================================
// Polynomial Hash Function
unsigned long HashTable::hashCode2(string key)
{
	//TODO
	long h = 0;
	for (int i = 0; i < key.size(); i++)
	{
		h += key[i] * pow(33,i);
	}
	return h;
}
// ================================
// Cycle Shift Hash Function (Compression Method -> Division)
unsigned long HashTable::hashCode1(string key)
{
	long h = 0;
	for (int i = 0; i < key.size(); i++)
	{
		h = (h<<5) | (h>>27);
		h += (unsigned long) key[i];
	}
	return h;
}
// ================================
// Polynomial Hash Function 2
unsigned long HashTable::hashCode5(string key)
{
	unsigned long a = 378517;
	unsigned long b = 63613;
	long h = 0;
	int i = 0;
	while (i < key.size())
	{
		h = h * b + (key[i]);
		b *= a;
		i++;
	}
	return h;
}
// ================================
// Summation Hash Function
unsigned long HashTable::hashCode3(string key)
{
	long h;

	for (int i = 0; i < key.length(); i++)
	{
		h += key[i];
	}

	return h;
}
// ================================
// Cycle Shift Hash Function (Compression Method -> MAD)
unsigned long HashTable::hashCode4(string key)
{
	long h = 0;
	long c = 0;
	int N = 114641;
	int a = 27;
	int b = 33;
	for (int i = 0; i < key.size(); i++)
	{
		h = (h<<6) | (h>>32);
		h += (unsigned long) key[i];
	}
	c = abs((a*h)+b);
	return c;
}
// ================================
int HashTable::select_hashFun()
{
	int x;

	cout<<"--------------------------------------"<<endl;
	cout<<"Available Hash Functions:"<<endl;
	cout<<"1. Cycle Shift Hash Function (Compression Method -> Division)"<<endl;
	cout<<"2. Polynomial Hash Function"<<endl;
	cout<<"3. Summation Hash Function"<<endl;
	cout<<"4. Cycle Shift Hash Function (Compression Method -> MAD)"<<endl;
	cout<<"5. Polynomial Hash Function 2"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"Please enter the number corresponsing to the hash function you wish to implement. This is optional. If you don't enter anything, the drfault hash function will be chosen. :"<<endl;

	string num;
	// getting the number from the user
	while (getline(cin,num))
	{
		if (num == "1")
		{
			x = 1;
			break;
		}
		else if (num == "2")
		{
		
			x = 2;
			break;
		}
		else if (num == "3")
		{
			x = 3;
			break;
		}
		else if (num == "4")
		{
			x = 4;
			break;
		}
		else if (num == "5")
		{
			x = 5;
			break;
		}
		else if (num == "") // if enter, using the default hash function
		{
			x = 5;
			break;
		}
		else if (num == "exit" || num == "Exit")
		{
			exit(-1);
		}
		else
		{
			cout<<"Invalid Input. Try Again."<<endl;
		}
	}

	// reseting the values
	this->collisions = 0;
	this->size = 0;
	this->total_size = 0;
	this->buckets = new MyVector[capacity];
	return x;
}
// ================================
void HashTable::insert(string key, int a)
{
	HashNode* x = new HashNode(key);
	
	int idx;

	// finding the hash code based on the number corresponding to the hash function
	if (a == 1)
	{
		idx = hashCode1(key) % capacity;
	}
	else if (a == 2)
	{
		idx = hashCode2(key) % capacity;
	}
	else if (a == 3)
	{
		idx = hashCode3(key) % capacity;
	}
	else if (a == 4)
	{
		idx = hashCode4(key) % capacity;
	}
	else
	{
		idx = hashCode5(key) % capacity;
	}

	idx = abs(idx);
	bool flag = false;
	for (int i = 0; i < buckets[idx].size(); i++)
	{
		if (buckets[idx][i]->key == key) // if the key exists, update its value
		{
			buckets[idx][i]->value += 1;
			flag = true;
			break;
		}
	}

	if (flag == false)
	{
		if (buckets[idx].empty() == false)
		{
			collisions++; // since the bucket is not empty, there is a collision
		}
		buckets[idx].push_back(x); // if the key does not exist, add the hash node
		size++;	// increasing the number of unique words
	}
	total_size++; // increasing the total number of words
}
// ================================
int HashTable::find_freq(string key, int a)
{
	int idx;
	// finding the hash code for the key based on the number corresponding to the hash function
	if (a == 1)
	{
		idx = hashCode1(key) % capacity;
	}
	else if (a == 2)
	{
		idx = hashCode2(key) % capacity;
	}
	else if (a == 3)
	{
		idx = hashCode3(key) % capacity;
	}
	else if (a == 4)
	{
		idx = hashCode4(key) % capacity;
	}
	else
	{
		idx = hashCode5(key) % capacity;
	}
	idx = abs(idx);
	for (int i = 0; i < buckets[idx].size(); i++)
	{
		if (buckets[idx][i]->key == key) // if the key is present, return its value
		{
			return buckets[idx][i]->value;
		}
	}
	return 0; // if not present, return 0
}
// ================================
void HashTable::insert_heap()
{
	int a = count_unique_words() - count_collisions();
	MyVector *arr = new MyVector[a]; // creating a new array of vectors
	int j = 0;
	int i = 0;
	for (i = 0; i < capacity; i++)
	{
		if (buckets[i].empty() == false)
		{
			arr[j] = buckets[i]; // copying values from the previous array
			j++;
			
		}
	}

	// inserting each hash node in all vectors into the heap
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < arr[i].v_size; j++)
		{
			HashNode* x = arr[i][j];
			myHeap.insert(x);
		}
	}
}
// ================================
string HashTable::find_max()
{
	HashNode* x =  myHeap.getMax(); // returning the max from the heap
	return x->key;
}
// ================================
int HashTable::count_unique_words()
{
	return this->size;
}
// ================================
int HashTable::count_collisions()
{
	return this->collisions;
}
// ================================
int HashTable::count_words()
{
	return this->total_size;
}
// ================================
void HashTable::commands()
{
	cout<<"--------------------------------------"<<endl;
	cout<<"Available Commands:"<<endl;
	cout<<"count_collisions:                       Returns the number of collisions caused by the hash function."<<endl;
	cout<<"count_unique_words:                     Returns the number of unique words in the text."<<endl;
	cout<<"count_words:                            Returns the total number of words in the text."<<endl;
	cout<<"find_freq <word>:                       Returns the frequency of a word, if it is present in the text. 0 otherwise."<<endl;
	cout<<"find_max:                               Returns the word with maximun frequency."<<endl;
	cout<<"select_hashFun:                         Allows user to switch the hash function."<<endl;
	cout<<"Help:                                   Displays the list of available commands."<<endl;
	cout<<"Exit:                                   Exits the program."<<endl;
	cout<<"--------------------------------------"<<endl;
}
// ================================
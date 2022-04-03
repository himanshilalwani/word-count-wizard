#ifndef HASHNODE_H
#define HASHNODE_H

#include <string>
using namespace std;
class HashNode
{
	private:
		string key; // key which is a word
		int value; // value which is the frequency
	public:
		HashNode(string key); // constructor
		friend class HashTable;
		friend class Heap;
};

#endif
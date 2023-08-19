#include "hashnode.h"
#include <string>
using namespace std;

// ================================
HashNode::HashNode(string key) // constructor
{
	this->key = key;
	this->value = 1;
}
// ================================
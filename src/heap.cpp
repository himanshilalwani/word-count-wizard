#include "heap.h"
//=====================================
Heap::Heap() // constructor
{
	//todo
	this->size = 0;
	this->capacity = 1;
	this->array = new HashNode*[capacity];
}
// Insert an element in Heap keeping the Heap property intact 
//=====================================
void Heap::insert(HashNode* key)
{
	//todo

	if (size >= capacity)
	{
		adjustSize();
	}
	array[size] = key;
	size = size + 1;
	if (size != 1)
	{
		siftup(size-1);
	}
}
//=====================================
// Remove the maximum value from Heap keeping the Heap property intact
HashNode* Heap::removeMax()
{
	//todo
	HashNode* min = array[0];
	array[0] = array[size - 1];
	size = size - 1;
	siftdown(0);
	return min;
	
}
//=====================================
// Return (but don't remove) the maximum value from the Heap
HashNode* Heap::getMax()
{
	//todo
	return array[0];
}
//=====================================
// Returns the index of the parent of the node i
int Heap::parent(int k)
{
	//todo
	if ((k-1)/2 >= 0)
	{
		return (k-1)/2;
	}
	return -1;
}
//=====================================
// Returns the index of the left child of the node i
int Heap::left(int k)
{
	//todo
	if ((2*k)+1 < size)
	{
		return ((2*k)+1);
	}
	return -1;
}
//=====================================
// Returns the index of the right child of the node i
int Heap::right(int k)
{
	//todo
	if ((2*k)+2 < size)
	{
		return ((2*k)+2);
	}
	return -1;
}
//=====================================
// Sift-up an element at index k
void Heap::siftup(int k)
{
	//todo

	if (k <= 0)
	{
		return;
	}
	int x = parent(k);

	if (array[k]->value < array[x]->value)
	{
		return;
	}
	else
	{
		HashNode* temp = array[k];
		array[k] = array[x];
		array[x] = temp;
		k = x;
	}

	siftup(k);

}
//=====================================
// Sift-down an element at index k
void Heap::siftdown(int k)
{
	
	//todo
	if (left(k) == -1 && right(k) == -1)
	{
		return;
	}
	else if (right(k) == -1)
	{
		int x = left(k);
		if (array[k]->value <= array[x]->value)
		{
			HashNode* temp = array[k];
			array[k] = array[x];
			array[x] = temp;
			k = x;
			siftdown(k);
		}
	}
	else
	{
		int x = left(k);
		int y = right(k);
		if (array[k]->value <= array[x]->value || array[k]->value <= array[y]->value)
		{
			if (array[x]->value <= array[y]->value)
			{
				HashNode* temp = array[k];
				array[k] = array[y];
				array[y] =  temp;
				k = y;
				siftdown(k);
			}
			else
			{
				HashNode* temp = array[k];
				array[k] = array[x];
				array[x] = temp;
				k = x;
				siftdown(k);
			}
		}
	}
	
}

//==================================================================
// This method prints a Heap in 2D format. 
//Optional argument k is the index of element which will be printed in red color
//if not argument provided, the entire array/tree will be printed in white color.
void Heap::print(int k)
{
	//cout << "\033[1;31mbold red text\033[0m\n";
	if(size >0)
	{
		int levels = int(log2(size));

		int spaces[levels+1];
		spaces[levels]=0;

		for(int j=levels-1; j>=0; j--)
		{
				spaces[j]=2*spaces[j+1]+1;
		}
		
		int level=0;
		for (int i=0; i<size; i++)
		{
			if(i == (pow(2,level)-1))
			{
				cout<<endl<<endl;
			
				for(int k=0; k<spaces[level]; k++)
				cout<<"   ";
				level++;
		
			}
			if(i==k)
				cout<<std::left<<"\033[1;31m"<<setw(3)<<array[i]<<"\033[0m";
			else
				cout<<std::left<<setw(3)<<array[i];
			
			if(level>1)
			{
				for(int k=0; k<spaces[level-2]; k++)
					cout<<"   ";
			}
			
		}

		cout<<endl;
		for(int i=0; i<spaces[0]*log2(size/2)+4; i++)
		cout<<"__";
		cout<<endl;
	}

}
//=====================================
void Heap::adjustSize()
{
	HashNode **newArray = new HashNode*[capacity*2];
	for(int i=0; i<capacity; i++)
		newArray[i] = array[i];
	array = newArray;
	capacity = capacity*2;	
}
//=============================================
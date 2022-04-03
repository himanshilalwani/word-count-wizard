#include "hashnode.h"
#include "vector.h"
#include "hashtable.h"
#include "heap.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

// ================================ Function to check whether a number is prime or not ================================
bool isPrime(int number)
{
	int half = number/2;

	for (int i = 2; i < half; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

// ================================ Checks whether a given number is prime or not. If not, returns the next closest prime number ================================
int findPrime(int n)
{
	while (isPrime(n) == false)
	{
		n++;
	}
	return n;
}

// ================================ Checks whether a string is whitespace or not ================================
bool iswhitespace(string str)
{
	if(str.find_first_not_of(' ') != std::string::npos)
    {
    	return false; // non-space
    }
    return true; // all white space
}
// ================================
int main()
{
	
	ifstream fin;
	string path;
	cout<<"Welcome to Word Count Wizard. Please enter the full path of the file you wish to load: ";
	cin>>path; // taking absolute path from the user
	fin.open(path);
	
	while (!fin && path != "exit") // checking if the path does not esixt
	{
		cout<<"Cannot open the file. Enter a valid path: "<<endl;
		cin>>path;
		fin.open(path);
	}
	if (path == "exit") // shutting the program if the user input exit
	{
		exit(-1);
	}
	string word;
	
	
	cout<<"--------------------------------------"<<endl;
	cout<<"Available Hash Functions:"<<endl;
	cout<<"1. Cycle Shift Hash Function (Compression Method -> Division)"<<endl;
	cout<<"2. Polynomial Hash Function"<<endl;
	cout<<"3. Summation Hash Function"<<endl;
	cout<<"4. Cycle Shift Hash Function (Compression Method -> MAD)"<<endl;
	cout<<"5. Polynomial Hash Function 2"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"Please enter the number corresponsing to the hash function you wish to implement. This is optional. If you don't enter anything, the drfault hash function will be chosen. :"<<endl;
	
	int x;
	int counter = 0;

	string num;
	// getting the number of the hash function from the user
	while (getline(cin,num))
	{
		counter++;
		if (num == "" && counter == 1)
		{
			continue;
		}
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
		else if (num == "")
		{
			x = 5;
			// cout<<"true"<<endl;
			break;
		}
		else if (num == "exit" || num == "Exit")
		{
			exit(-1);
		}
		else if (counter != 1)
		{
			cout<<"Invalid Input. Try Again."<<endl;
		}
	}
	int count = 0;

	// finding total words in the file
	while(fin>>word)
	{
		count++;
	}
	
	count = count*1.333;
	int hs = findPrime(count);
	
	// creating a hash table based on total words
	HashTable myHashTable(hs);
	fin.close();

	fin.open(path);

	// inserting words into the hash table
	while (fin>>word)
	{
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		while (word.back() == '.' || word.back() == ',' || word.back() == '\\' || word.back() == '?' || word.back() == ';' || word.back() == ':' || word.back() == '!' || word.back() == '"' || word.back() == '#' || word.back() == '$' || word.back() == '%' || word.back() == '&' || word.back() == '(' || word.back() == ')' || word.back() == '*' || word.back() == '+' || word.back() == '-' || word.back() == '_' || word.back() == '<' || word.back() == '=' || word.back() == '>' || word.back() == '@' || word.back() == '[' || word.back() == ']' || word.back() == '/' || word.back() == '^' || word.back() == '`' || word.back() == '{' || word.back() == '}' || word.back() == '~')
		{
			word = word.substr(0,word.size()-1);
		}
		while (word.front() == '.' || word.front() == ',' || word.front() == '\\' || word.front() == '?' || word.front() == ';' || word.front() == ':' || word.front() == '!' || word.front() == '"' || word.front() == '#' || word.front() == '$' || word.front() == '%' || word.front() == '&' || word.front() == '(' || word.front() == ')' || word.front() == '*' || word.front() == '+' || word.front() == '-' || word.front() == '_' || word.front() == '<' || word.front() == '=' || word.front() == '>' || word.front() == '@' || word.front() == '[' || word.front() == ']' || word.front() == '/' || word.front() == '^' || word.front() == '`' || word.front() == '{' || word.front() == '}' || word.front() == '~')
		{
			word = word.substr(1,word.size()-1);
		}
		myHashTable.insert(word, x);
	}
	fin.close();

	// creating a heap if the file is not empty
	if (myHashTable.count_words() > 0)
	{
		myHashTable.insert_heap();
	}
	
	// Analysis
	cout<<"--------------------------------------"<<endl;
	cout<<"Total number of words in the text = "<<myHashTable.count_words()<<endl;
	cout<<"Number of unique words in the text = "<<myHashTable.count_unique_words()<<endl;
	cout<<"Number of collisions caused by the hash function "<<x<<" = "<<myHashTable.count_collisions()<<endl;
	cout<<"Average number of collisions per unique entry caused by the hash function "<<x<<" = "<<float(myHashTable.count_collisions())/myHashTable.count_unique_words()<<endl;

	myHashTable.commands();

	
	// terminal interface
	while(true)
	{
		string user_input, command, argument1;
		cout<<">";
		getline(cin,user_input);

		stringstream sstr(user_input);
		getline(sstr,command,' ');
		getline(sstr,argument1);

		if (command == "select_hashFun" || command == "s")
		{
			int w = myHashTable.select_hashFun();
			fin.open(path);
			// creating a new hash table based on the hash function
			while (fin>>word)
			{
				transform(word.begin(), word.end(), word.begin(), ::tolower);
				while (word.back() == '.' || word.back() == ',' || word.back() == '\\' || word.back() == '?' || word.back() == ';' || word.back() == ':' || word.back() == '!' || word.back() == '"' || word.back() == '#' || word.back() == '$' || word.back() == '%' || word.back() == '&' || word.back() == '(' || word.back() == ')' || word.back() == '*' || word.back() == '+' || word.back() == '-' || word.back() == '_' || word.back() == '<' || word.back() == '=' || word.back() == '>' || word.back() == '@' || word.back() == '[' || word.back() == ']' || word.back() == '/' || word.back() == '^' || word.back() == '`' || word.back() == '{' || word.back() == '}' || word.back() == '~')
				{
					word = word.substr(0,word.size()-1);
				}
				while (word.front() == '.' || word.front() == ',' || word.front() == '\\' || word.front() == '?' || word.front() == ';' || word.front() == ':' || word.front() == '!' || word.front() == '"' || word.front() == '#' || word.front() == '$' || word.front() == '%' || word.front() == '&' || word.front() == '(' || word.front() == ')' || word.front() == '*' || word.front() == '+' || word.front() == '-' || word.front() == '_' || word.front() == '<' || word.front() == '=' || word.front() == '>' || word.front() == '@' || word.front() == '[' || word.front() == ']' || word.front() == '/' || word.front() == '^' || word.front() == '`' || word.front() == '{' || word.front() == '}' || word.front() == '~')
				{
					word = word.substr(1,word.size()-1);
				}
				
				myHashTable.insert(word, w);
			}
			x = w;
			fin.close();

			if (myHashTable.count_words() > 0)
			{
				myHashTable.insert_heap();
			}
			cout<<"--------------------------------------"<<endl;
			cout<<"Total number of words in the text = "<<myHashTable.count_words()<<endl;
			cout<<"Number of unique words in the text = "<<myHashTable.count_unique_words()<<endl;
			cout<<"Number of collisions caused by the hash function "<<x<<" = "<<myHashTable.count_collisions()<<endl;
			cout<<"Average number of collisions per unique entry caused by the hash function "<<x<<" = "<<float(myHashTable.count_collisions())/myHashTable.count_unique_words()<<endl;
			myHashTable.commands();
		}

		else if(command == "find_freq")
		{
				if (argument1.empty() == false && iswhitespace(argument1) == false) // checking whether the arguments are valid
				{
					string arg = argument1;
					transform(arg.begin(),arg.end(),arg.begin(),::tolower);

					int y = myHashTable.find_freq(arg, x);
					if (y != 0)
					{
						cout<<"Frequency of "<<argument1<<": "<<y<<endl;
					}
					else
					{
						cout<<"Word Not Found"<<endl;
					}
				}
				else
				{
					cout<<"Please enter a valid argument with the command."<<endl;
				}
				
		}
		else if(command == "count_collisions") 
		{
			int z = myHashTable.count_collisions(); // returning total collisions
			cout<<"Number of collisions caused by the hash function = "<<z<<endl;
		}
		
		else if(command == "count_unique_words")
		{	
			int b = myHashTable.count_unique_words(); // returning the number of unique words
			cout<<"Number of unique words in the text = "<<b<<endl;
		}	  
		else if(command == "count_words")
		{
			int d = myHashTable.count_words(); // returning total number of words
			cout<<"Total number of words in the text = "<<d<<endl;
		}
		else if (command == "help" || command == "Help")
		{
			myHashTable.commands(); // listing available commands
		}
		else if (command == "find_max")
		{
			if (myHashTable.count_words() > 0)
			{
				string e = myHashTable.find_max(); // returning the max from the heap
				cout<<"Word with maximum frequency = "<<e<<endl;
			}
			else
			{
				cout<<"The file is empty"<<endl;
			}
		}
		else if(command == "Exit" || command == "e")	  break;
		else if ((command.empty() == true || iswhitespace(command) == true) && (argument1.empty() == false)) // checking for invalid commands and arguments
		{	
			if (iswhitespace(argument1) == false)
			{
				cout<<"Invalid command !!!"<<endl; 
			}
			else
			{
				continue;
			}
			
		}
		else if ((command.empty() == true || iswhitespace(command) == true) && (argument1.empty() == true || iswhitespace(argument1) == true)) // checking for invalid commands and arguments
		{
			continue;
		}
		else {
				cout<<"Invalid command !!!"<<endl;
			}
	}

	return 0;

}
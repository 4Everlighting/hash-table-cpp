// Hash hashT 
//using chains
#include<iostream> 
#include <list> 
using namespace std;
class HT
{
	int numIndexes;
	list<int>* hashT;

public:
	HT(int V); // Constructor 

	void insertItem(int x);

	void deleteItem(int key);

	int hash(int x) {
		return (x % 2);
	}

	void displayHash();
};

HT::HT(int b)
{
	this->numIndexes = b;
	hashT = new list<int>[numIndexes];
}

void HT::insertItem(int key)
{
	int index = hash(key);
	hashT[index].push_back(key);
}

void HT::deleteItem(int key)
{
	// get the hash index of key 
	int index = hash(key);

	// find the key in (inex)th list 
	list <int> ::iterator i;
	for (i = hashT[index].begin();
		i != hashT[index].end(); i++) {
		if (*i == key)
			break;
	}


	if (i != hashT[index].end())
		hashT[index].erase(i);
}


void HT::displayHash() {
	for (int i = 0; i < numIndexes; i++) {
		cout << i;
		for (auto x : hashT[i])
			cout << " --> " << x;
		cout << endl;
	}
}

// Driver program 
int main()
{
	int values[] = { 1, 7, 14, 15, 9 };
	int n = sizeof(values) / sizeof(values[0]);



	HT h(7);
	for (int i = 0; i < n; i++)
	{
		h.insertItem(values[i]);
	}

	h.displayHash();
	h.deleteItem(7);

	// display the Hash hashT 
	h.displayHash();

	return 0;
}

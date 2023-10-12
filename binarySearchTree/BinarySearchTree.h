#pragma once

/**
 * array based BinarySearchTree Template class
 * @author : Hawon Oh
 * @version: 1.0
 */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std; 

template<typename T> 
class BinarySearchTree
{
    private:
	
    public:
	int size, level;
	T *array;
	
	const T NULLVALUE {};
	
    // constructor
    BinarySearchTree<T>();
	// constructor
    BinarySearchTree<T>(int l);
    // copy constructor
    BinarySearchTree<T>(const BinarySearchTree<T> *obj);
    // destructor to release allocated memory
    ~BinarySearchTree();
    // inserts an element T in the binary search tree 
    void insert(T data);
    // deletes an element T from the binary search tree
    void deleteItem(T data);
    // displays the elements of the binary search tree in order
	void inOrder();
    void inOrder(int currentIndex); 
    // displays the elements of the binary search tree pre order 
    void preOrder();
	void preOrder(int currentIndex); 
    // displays the elements of the binary search tree post order 
    void postOrder();
	void postOrder(int currentIndex);
    //  searches the binary search tree for the element T and returns true/false accordingly 
    bool search(T searchVal);
    // returns the number of nodes in the binary search tree
    int countNode();
	int countNode(int currentIndex);
    // returns the maximum value of the binary search tree 
    bool maximum(T&val); 
    // returns the minimum value of the binary search tree
    bool minimum(T&val);
    // returns the successor of the node at index position 
    bool predecessor(int index);
    // reverse the contents of the doubly linked list
    bool successor(int index);
    // returns the current size (array size) of the binary search tree
    int getSize();
    // returns true/false to indicate whether the binary search tree is empty methods in the class
    bool isEmpty(); 
	// returns 2^(level + 1) - 1
	int extendSize(int l);
};





// constructor
template<typename T> 
BinarySearchTree<T>::BinarySearchTree()
{
	size = 0;
	level = 0;
}


// constructor
template<typename T> 
BinarySearchTree<T>::BinarySearchTree(int l)
{
	this->level = l;
	this->size = extendSize(l); // 2^(level+1) - 1
	// this->array = new T[this->size];
	this->array =(T*)malloc(sizeof(T)*this->size);
	
	for(int x = 0; x < this->size; x++)
	{
		array[x] = NULLVALUE;
	}
}

// destructor
template<typename T> 
BinarySearchTree<T>::~BinarySearchTree()
{
	delete[] array;
}

// copy constructor (deep copy)
template<typename T> 
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> *obj)
{
	this->level = obj.level;
	this->size = obj.size; // expected: 2^(level+1) - 1
	this->array =(T*)malloc(sizeof(T)*this->size);
	
	for(int x = 0; x < size; x++)
	{
		this->array[x] = obj.array[x];
	}
}

	
// inserts an element T in the binary search tree
template<typename T> 
void BinarySearchTree<T>::insert(T data)
{
	int currentIndex = 0;
	
	while(true)
	{
		// if the current index is beyond the array size, reallocate
		if(currentIndex >= size)
		{
			this->level += 1;
			this->size = extendSize(level); // 2^(level+1) - 1
			this->array =(T*)realloc(array,sizeof(T)*this->size);
		}
		
		// if empty
		if(array[currentIndex] == NULLVALUE)
		{
			array[currentIndex] = data;
			
			break;
		}
		// repeating value
		else if(array[currentIndex] == data)
		{
			break;
		}
		// right
		else if(array[currentIndex] < data)
		{
			currentIndex = (2 * currentIndex + 2);
		}
		// left
		else if(array[currentIndex] > data)
		{
			currentIndex = (2 * currentIndex + 1);
		}
		
	}
	
}
	
// deletes an element T from the binary search tree
template<typename T> 
void BinarySearchTree<T>::deleteItem(T data)
{
	
}
	
// displays the elements of the binary search tree in order
template<typename T>
void BinarySearchTree<T>::inOrder()
{
	inOrder(0);
}
template<typename T> 
void BinarySearchTree<T>::inOrder(int currentIndex)
{
	// check if the index position is beyond the array size
 	if(currentIndex >= size)
		return;
 
 	if (array[currentIndex] != NULLVALUE)
 	{
		inOrder(2 * currentIndex + 1);
		cout << array[currentIndex] << endl;
 		inOrder(2 * currentIndex + 2);
 	}
}
	
// displays the elements of the binary search tree pre order 
template<typename T> 
void BinarySearchTree<T>::preOrder()
{
	preOrder(0);
}
template<typename T> 
void BinarySearchTree<T>::preOrder(int currentIndex)
{
	// check if the index position is beyond the array size
 	if(currentIndex >= size)
		return;
 
 	if (array[currentIndex] != NULLVALUE)
 	{
		cout << array[currentIndex] << endl;
		inOrder(2 * currentIndex + 1);
 		inOrder(2 * currentIndex + 2);
 	}
}

// displays the elements of the binary search tree post order
template<typename T> 
void BinarySearchTree<T>::postOrder()
{
	postOrder(0);
}
template<typename T> 
void BinarySearchTree<T>::postOrder(int currentIndex)
{
	// check if the index position is beyond the array size
 	if(currentIndex >= size)
		return;
 
 	if (array[currentIndex] != NULLVALUE)
 	{
		inOrder(2 * currentIndex + 1);
 		inOrder(2 * currentIndex + 2);
		cout << array[currentIndex] << endl;
 	}
}
	
//  searches the binary search tree for the element T and returns true/false accordingly 
template<typename T> 
bool BinarySearchTree<T>::search(T searchVal)
{
	int currentIndex = 0;
 	
	while (true){
 		// not found
 		if (currentIndex >= size || array[currentIndex] == NULLVALUE)
 		{
 			return false;
 		}
		// found
 		if (array[currentIndex] == searchVal)
 		{
 			return true;
 		}
		// general case
 		else if (array[currentIndex] < searchVal)
 		{
 			currentIndex = (2 * currentIndex + 2);
		}
 		else if (array[currentIndex] > searchVal)
 		{
 			currentIndex = (2 * currentIndex + 1);
 		}
	}
}

template<typename T> 
// returns the number of nodes in the binary search tree
int BinarySearchTree<T>::countNode()
{
	return countNode(0);
}
template<typename T> 
int BinarySearchTree<T>::countNode(int currentIndex)
{
	if(currentIndex == NULLVALUE)
	{
		return 0;
	}
	
	// find each number of left and right nodes
	int l_count = countNode(2 * currentIndex + 1);
	int r_count = countNode(2 * currentIndex + 2);
	
	// add number of root
	return l_count + r_count + 1;
}
	
	
// returns the maximum value of the binary search tree 
template<typename T> 
bool BinarySearchTree<T>::maximum(T&val)
{
	if(isEmpty()){
		return false;
	}
	
	int currentIndex = 0;
	int temp;
	while(currentIndex != NULLVALUE)
	{
		temp = currentIndex;
		currentIndex = 2 * currentIndex + 2;
	}
	val = array[temp];
	
	return true;
}
	
// returns the minimum value of the binary search tree
template<typename T> 
bool BinarySearchTree<T>::minimum(T&val)
{
	if(isEmpty()){
		return false;
	}
	
	int currentIndex = 0;
	int temp;
	while(currentIndex != NULLVALUE)
	{
		temp = currentIndex;
		currentIndex = 2 * currentIndex + 1;
	}
	val = array[temp];
	
	return true;
}
	
// returns the successor of the node at index position 
template<typename T> 
bool BinarySearchTree<T>::predecessor(int index)
{
	return true;
}
	
// reverse the contents of the doubly linked list
template<typename T> 
bool BinarySearchTree<T>::successor(int index)
{
	return true;
}
	
// returns the current size (array size) of the binary search tree
template<typename T> 
int BinarySearchTree<T>::getSize()
{
	return size;
}
	
// returns true/false to indicate whether the binary search tree is empty methods in the class
template<typename T> 
bool BinarySearchTree<T>::isEmpty()
{
	if(size == 0)
		return true;
	return false;
}

// 2^(level+1) - 1
template<typename T> 
int BinarySearchTree<T>::extendSize(int l)
{
	int temp = pow(2, l + 1);
	return temp - 1;
}
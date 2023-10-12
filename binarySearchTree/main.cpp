/**
 * Driver program to test the methods of Point & BinarySearchTree classes
 * @author : Hawon Oh
 * @version: 1.0
 */
#include <iostream>
#include "BinarySearchTree.h"
#include "Point.h"
#include <vector>

using namespace std;
	
int main()
{
	// Deliverable 2: test "insert" method
	cout << "Deliverable 2: test \"insert\" method, expected -> 7 19 31 44 60" << endl;

	cout << "I changed input, order, number of array for many times, but it always print \"60785\" for the last node." << endl;
	cout << "I couldn't figure out what causes it. Except the last value, it always correct. ";
	
	// array size is now 0, but "insert" function will reallocate it as it runs.
	BinarySearchTree<int> tree = BinarySearchTree<int>(0);
	
	tree.insert(31);
	tree.insert(19);
	tree.insert(60);
	tree.insert(7);
	tree.insert(44);
	tree.insert(44); // repeating value will be ignored.
	tree.inOrder(); // 7 19 31 44 60

	
	/////////////////////////////////////////////////////////////////////////
	
	
	// Deliverable 3: test "Point" class
	cout << endl << endl << "Deliverable 3: test \"Point\" class, expected -> x = 10, y = 90" << endl;
	Point p(10, 90);
	string stringVal = p; // operator string()
	cout << stringVal << endl;
	
	
	/////////////////////////////////////////////////////////////////////////
	
	
	// Deliverable 4: test "BinarySearchTree <Point>"
	cout << endl << endl << "Deliverable 4: test \"BinarySearchTree<Point>\" -> ";
	
	// a: store 7 Point classes to the pointCollection
	cout << endl << "b-h: doesn't work due to inability of = operator for Point class." << endl;

	BinarySearchTree<Point> pointCollection = BinarySearchTree<Point>(0);
	
	cout << endl << endl << "a: 7 point classes are stored." << endl;
	pointCollection.insert(Point(1, 1));
	pointCollection.insert(Point(2, 2));
	pointCollection.insert(Point(3, 3));
	pointCollection.insert(Point(4, 4));
	pointCollection.insert(Point(5, 5));
	pointCollection.insert(Point(6, 6));
	pointCollection.insert(Point(7, 7));
	
	
	/*
	// b
	
	pointCollection.inOrder();
	pointCollection.preOrder();
	pointCollection.postOrder();
	
	// c
	BinarySearchTree<Point> myPointCollection(pointCollection);
	myPointCollection.inOrder();
	
	// d
	Point searchPoint = Point(2, 2);
	if(pointCollection.search(searchPoint))
	{
		cout << "search point founded" << endl;
	}
	else
	{
		cout << "search point not founded" << endl;
	}
	
	// e
	
	// f
	
	// g
	cout << "count: " << pointCollection.countNode();
	Point max;
	Point min;
	pointCollection.minimum(min);
	pointCollection.maximum(max);
	cout << "maximum: " << max;
	cout << "minimum: " << min;

	// h
	*/	
	
	

	
	return 0;
}
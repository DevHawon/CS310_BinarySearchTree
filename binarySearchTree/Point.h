#pragma once

/**
 * Point class
 * @author : Hawon Oh
 * @version: 1.0
 */
#include<iostream>

using namespace std;

class Point
{
	int x, y;
	
	public:
	// constructor
	Point()
	{
		
	}
	// constructor
	Point(int a, int b)
	{
		x = a; y = b;
	}
	// copy constructor
	Point(const Point &obj);
	// overload assignment operator
	Point& operator =(const Point &obj)
	{
		x = obj.x;
		y = obj.y;
		return *this;
	}
	
	// overload boolean operator
	bool operator <(const Point &obj)
	{
		if(x < obj.x)
			return true;
		else if(x == obj.x)
			return y < obj.y;
		else
			return false;
	}
	
	// overload boolean operator
	bool operator >(const Point &obj)
	{
		if(x > obj.x)
			return true;
		else if(x == obj.x)
			return y > obj.y;
		else
			return false;
	}
	
	// overload boolean operator
	bool operator ==(const Point &obj)
	{
		if(x == obj.x && y == obj.y)
			return true;
		
		return false;
	}
	
	// overload boolean operator
	bool operator !=(const Point &obj)
	{
		if(x == obj.x || y == obj.y)
			return false;
		
		return true;
	}
	
	// overload toString operator
	operator string()
	{
		string str = "x = " + to_string(x) + 
                 	 ", y = " + to_string(y); 
		
    	return str;
	}
	
	friend ostream & operator << (ostream &out, const Point &p);
};


// overloading cout<< in order to display Point object
ostream& operator << (ostream &out, const Point &p)
{
    out << "x = " + to_string(p.x) + ", y = " + to_string(p.y); 
	
	return out;
};
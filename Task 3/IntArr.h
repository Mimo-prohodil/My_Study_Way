#pragma once

class IntArr {
	int arr[3]{ 1,2,3 };

public:
	class Iterator {
		int * ptr;

	public:
		Iterator(int* ptr);
		Iterator& operator++ ();
		Iterator& operator++ (int);
		Iterator& operator-- ();
		Iterator& operator-- (int);
		int& operator* ();
		int* operator-> ();
		bool operator== (const Iterator& other);
		bool operator!= (const Iterator& other);
	};

	Iterator begin();
	Iterator end();	
};


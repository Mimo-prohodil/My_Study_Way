#include "IntArr.h"

IntArr::Iterator::Iterator(int* ptr) : ptr(ptr) {}

IntArr::Iterator& IntArr::Iterator::operator++ () {
	++ptr;
	return *this;
}

IntArr::Iterator& IntArr::Iterator::operator++ (int) {
	Iterator it{ *this };
	++ptr;
	return it;
}

IntArr::Iterator& IntArr::Iterator::operator-- () {
	--ptr;
	return *this;
}

IntArr::Iterator& IntArr::Iterator::operator-- (int) {
	Iterator it{ *this };
	--ptr;
	return it;
}

int& IntArr::Iterator::operator* () {	
	return *ptr;
}

int* IntArr::Iterator::operator-> () {	
	return ptr;
}

bool IntArr::Iterator::operator== (const Iterator& other) {	
	return ptr == other.ptr;
}

bool IntArr::Iterator::operator!= (const Iterator& other) {
	return ptr != other.ptr;
}

IntArr::Iterator IntArr::begin() {
	return Iterator(arr);
}

IntArr::Iterator IntArr::end() {
	return Iterator(arr + 3);
}

#ifndef LISTDIET_H
#define LISTDIET_H

#include <string>
#include <iostream>
#include "ListNodeDiet.h"

using std::string;

class ListDiet {
public:
	ListDiet();
	~ListDiet();

	bool isEmpty();

private:
	ListNodeDiet* pHead;
	ListNodeDiet* pTail;
};
#endif
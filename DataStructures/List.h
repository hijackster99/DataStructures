#pragma once

#include <initializer_list>

template <typename T> class List
{
public:
	virtual List(size_t capacity = 5);
	virtual List(std::initializer_list<T> items);
	virtual ~List();
	virtual List(const List& list);
	virtual List<T>& operator=(const List& list);
protected:
	virtual void resize(size_t inc = 5);
	T* data;
	size_t capacity;
	size_t size;
};

#include "List_template.h"
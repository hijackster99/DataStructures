#pragma once
#include <initializer_list>
#include "List.h"

template <typename T> class ArrayList : List<T>
{
public:
	T operator[](size_t index);
	T* operator*();
	T get(size_t index);
	size_t index_of(T item);
	void add(T item);
	void add_all(std::initializer_list<T> items);
	void fill(T item);
	T remove(size_t index);
	void remove(T item);
	void remove_all(size_t begin, size_t end);
	void remove_all(T item);
	T set(T item, size_t index);
	void set(T item, size_t begin, size_t end);
	void set_all(T item, std::initializer_list<size_t> indices);
};

#include "ArrayList_template.h"
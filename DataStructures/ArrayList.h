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

template<typename T>
T ArrayList<T>::operator[](size_t index)
{
	return data[index];
}

template<typename T>
T* ArrayList<T>::operator*()
{
	return data;
}

template<typename T>
T ArrayList<T>::get(size_t index)
{
	return data[index];
}

template<typename T>
size_t ArrayList<T>::index_of(T item)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == item) return i;
	}

	return (size_t)-1;
}

template<typename T>
void ArrayList<T>::add(T item)
{
	if (size == capacity) resize();
	data[size] = item;
	++size;
}

template<typename T>
void ArrayList<T>::add_all(std::initializer_list<T> items)
{
	for (T item : items)
	{
		add(item);
	}
}

template<typename T>
void ArrayList<T>::fill(T item)
{
	for (int i = 0; i < capacity; i++)
	{
		data[i] = item;
	}
	size = capacity;
}

template<typename T>
T ArrayList<T>::remove(size_t index)
{
	T tmp = data[index];
	for (int i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}
	--size;
	return tmp;
}

template<typename T>
void ArrayList<T>::remove(T item)
{
	if (index_of(item) != (size_t)-1) remove(index_of(item));
}

template<typename T>
void ArrayList<T>::remove_all(size_t begin, size_t end)
{
	if (begin > size || begin >= end) return;
	if (end > size) end = size;
	diff = end - begin;
	for (int i = begin; i < size - diff; i++)
	{
		data[i] = data[i + diff];
	}
	size -= diff;
}

template<typename T>
void ArrayList<T>::remove_all(T item)
{
	size_t index = index_of(item);
	while (index != (size_t)-1)
	{
		remove(index);
		index = index_of(item);
	}
}

template<typename T>
T ArrayList<T>::set(T item, size_t index)
{
	T tmp = data[index];
	data[index] = item;
	return tmp;
}

template<typename T>
void ArrayList<T>::set(T item, size_t begin, size_t end)
{
	for (int i = begin; i < end; i++)
	{
		data[i] = item;
	}
}

template<typename T>
void ArrayList<T>::set_all(T item, std::initializer_list<size_t> indices)
{
	for (auto i : indices)
	{
		data[i] = item;
	}
}
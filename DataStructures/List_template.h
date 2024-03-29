#pragma once

template <typename T>
List<T>::List(size_t capacity)
{
	data = new List<T>[capacity];
	this->capacity = capacity;
}

template <typename T>
List<T>::List(std::initializer_list<T> items)
{
	size = items.size;
	capacity = size + 5;
	data = new List<T>[capacity];

	for (int i = 0; i < size; i++)
	{
		data[i] = items[i];
	}
}

template <typename T>
List<T>::~List()
{
	delete[] data;
}

template <typename T>
List<T>::List(const List& list)
{
	size = list.size;
	capacity = list.capacity;
	data = new List<T>[capacity];

	for (int i = 0; i < size; i++)
	{
		data[i] = list.data[i];
	}
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& list)
{
	if (&list == this) return this;

	size = list.size;
	capacity = list.capacity;
	List<T> tmp = new List<T>[capacity];

	for (int i = 0; i < size; i++)
	{
		tmp[i] = list.data[i];
	}

	delete[] data;
	data = tmp;

	return data;
}

template <typename T>
void List<T>::resize(size_t inc)
{
	capacity += inc;

	List<T> tmp = new List<T>[capacity];

	for (int i = 0; i < size; i++)
	{
		tmp[i] = data[i];
	}

	delete[] data;
	data = tmp;
}
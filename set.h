#pragma once
#include <iostream>
#include <string>

template <class T>
class Set {
	T* data;
	int size;

	int Contain(T number) const
	{
		int index = 0;
		while (data[index] != number)
		{
			index++;
			if (index > size - 1) throw "Element does not exist!";
		}
		return index;
	}

	int GetSize() const
	{
		return size;
	}


public:
	Set()
	{
		data = NULL;
		size = 0;
	}

	Set(const Set<T>& a)
	{
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
	}

	Set(const int right) //показывает что функция rand используется только с числами
	{
		size = right;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = rand() % 10;
		}
	}

	~Set()
	{
		delete[] data;
	}


};
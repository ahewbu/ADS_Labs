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

	Set(const size_t right)
	{
		size = right;
		data = new T[size];
		//for (size_t i = 0; i < size; i++)
		//{
		//	data[i] = rand() % 10;
		//}
	}

	~Set()
	{
		delete[] data;
	}

	Set<T>& operator=(const Set<T>& a)
	{
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
		return *this;
	}
	int Get_Size() {
		return size;
	}
	void operator+(T number)
	{
		//for (int i = 0; i < size; i++)
		//{
		//	if (data[i] == number) throw "Element already exist!";
		//}
		T* tmp = new T[size + 1];
		for (int i = 0; i < size; i++) { tmp[i] = data[i]; }
		tmp[size] = number;
		delete[] data;
		data = tmp;
		size++;
	}

	Set<T> operator+(const Set<T>& a) const
	{
		Set<T> ResultSet = *this;
		for (int i = 0; i < a.size; i++) {
			//bool flag = true;
			//for (int j = 0; j < size; j++)
			//{
			//	if (a.data[i] == data[j])
			//	{
			//		flag = false;
			//		break;
			//	}
			//}
			//if (flag)
			//{
				ResultSet + a.data[i];
			//}
		}
		return ResultSet;
	}

	Set<T> Intersection(const Set<T>& set) const
	{
		Set<T> ResultSet;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < set.size; j++)
			{
				if (data[i] == set.data[j]) ResultSet + data[i];
			}
		}
		return ResultSet;
	}

	T operator[](int index) const
	{
		if ((index > size - 1) || (index < 0) || (size == 0)) throw "Incorrect index!";
		return data[index];
	}

	void operator-(T number)
	{
		if (size == 0) throw "No elements exist!";
		T* tmp = new T[size - 1];
		int index = Contain(number);
		size--;
		for (int i = 0; i < index; i++) { tmp[i] = data[i]; }
		for (int i = index + 1; i < size + 1; i++) { tmp[i - 1] = data[i]; }
		delete[] data;
		data = tmp;
	}

	Set<T> operator-(const Set<T>& set) const
	{
		Set<T> ResultSet;
		ResultSet = *this;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < set.size; j++)
			{
				if (data[i] == set.data[j])
				{
					ResultSet - set.data[j];
					break;
				}
			}
		}
		return ResultSet;
	}

	void Add_value(T value) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++) { temp[i] = data[i]; }
		temp[size] = value;
		delete[] data;
		data = temp;
		size++;
	}

	bool Check_Value(T value) {
		bool f = false;
		for (int i = 0; i < size; i++)
		{
			if (data[i] == value)
				f = true;
		}
		return f;
	}

	friend std::ostream& operator << (std::ostream& out, const Set<T>& set)
	{
		int size = set.GetSize();
		if (size == 0)
		{
			out << "Empty set";
			return out;
		}
		out << "{";
		for (int i = 0; i < size - 1; i++)
		{
			out << set[i] << ", ";
		}
		out << set[size - 1];
		out << "}";
		return out;
	}

	void Find_Equal_Elems() {
		Set<T> ResultSet;
		Set<T> Result;
		for (int i = 0; i < size; i++) {
			if (ResultSet.Check_Value(data[i]) && !Result.Check_Value(data[i])) {
				//Acontinue;
				Result.Add_value(data[i]);
			}
			else {
				ResultSet.Add_value(data[i]);
			}
		}
		for (int i = 0; i < Result.Get_Size(); i++) {
			std::cout << Result.data[i] << " ";
		}
		std::cout << std::endl;
		//return ResultSet;
	}

	Set<T> Make_Set() {
		Set<T> ResultSet;
		for (int i = 0; i < size; i++) {
			if (!ResultSet.Check_Value(data[i])) {
				ResultSet.Add_value(data[i]);
			}
		}
		return ResultSet;
	}
};

std::ostream& operator << (std::ostream& out, const std::pair<int, double>& set)
{
	out << "{" << set.first << ";" << set.second << "}";
	return out;
}

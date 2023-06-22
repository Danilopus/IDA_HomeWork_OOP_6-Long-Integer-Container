#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Service functions.h"
#include <conio.h>
#include <iomanip>
#include <cassert>

class Long_Integer_Container
{
	size_t _size = 0;
	size_t _capacity = 0;
	long long* _long_values = nullptr;

	static std::map <int, std::string> codes_of_operation;

	void Add_capacity(size_t capacity_to_add = 0)
	{
		size_t new_capacity = _capacity + capacity_to_add;
		if (!capacity_to_add) 
			new_capacity += (_capacity > 5 ? _capacity / 2 : 5);

		long long* new_list = new long long[new_capacity];
		for (int i = 0; i < _size; i++)
			new_list[i] = _long_values[i];
		delete[] _long_values;
		_long_values = new_list;
		_capacity = new_capacity;
		//return *this;
	}
	void Shrink_capacity()
	{
		size_t new_capacity = _size + _size/2;
		long long* new_list = new long long[new_capacity];
		for (int i = 0; i < _size; i++)
			new_list[i] = _long_values[i];
		delete[] _long_values;
		_long_values = new_list;
		//return *this;
	}

public:

	// Constructors // Initialisation // Destructors // Memory Manage -------
	Long_Integer_Container();
	Long_Integer_Container(const Long_Integer_Container& Long_Integer_Container_obj)	{ *this = Long_Integer_Container_obj; }

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q8 как сделать универсальныю инициализацию Long_Integer_Container_obj {5, 7, 9}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		
	
	~Long_Integer_Container()
	{
		//for (int i = 0; i < _size; i++)
			delete[] _long_values;
	}
	//static void Initialisation(int provided_at_startup_money_holders_quantity);
	//static void Memory_Clean();


	// Setters // Getters --------------------------------------------------

	// Data manage ---------------------------------------------------------
	
	Long_Integer_Container& pushfront(long long new_value) 
	{
		if ( _size >= _capacity) Add_capacity();
		for (int i = _size; i > 0; i--)
			_long_values[i] = _long_values[i - 1];
		_long_values[0] = new_value;
		_size++;
		return *this;
	} 
	Long_Integer_Container& popfront()
	{
		_size--;
		if (_size == 0) { clear(); return *this ; } //throw exception:"container is empty
		if (_size < _capacity / 2) Shrink_capacity();
		for (int i = 0; i < _size; i++)
			_long_values[i] = _long_values[i + 1];
		return *this;
	}	
	Long_Integer_Container& pushback(long long new_value)
	{
		if ( _size >= _capacity) Add_capacity();
		_long_values[_size] = new_value;
		_size++;
		return *this;
	}
	Long_Integer_Container& popback()
	{
		_size--;
		if (_size == 0) { clear(); return  *this; }
		if (_size < _capacity / 2) Shrink_capacity();
		return *this;
	}
	Long_Integer_Container& insert(size_t pos, long long  new_value)
	{
		if (_size >= _capacity) Add_capacity();
		for (int i = _size; i > pos; i--)
			_long_values[i] = _long_values[i - 1];
		_long_values[pos] = new_value;
		_size++;
		return *this;
	}

	size_t size() { return _size; }

	long long int* begin()
	{
		return _long_values;
	}
	long long int* end()
	{
		return &_long_values[_size - 1];
	}	

	Long_Integer_Container& clear()
	{
		delete[] _long_values;
		_size = 0;
		_capacity = 0;
		_long_values = nullptr;
		return *this;
	}

	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << this; }

	//Overload operators - reference returned -----------------------------------------	
	
	Long_Integer_Container& operator + (const Long_Integer_Container& Long_Integer_Container_obj) const
	{
		Long_Integer_Container& new_container = *new Long_Integer_Container;
		for (size_t i = 0; i < _size; i++)		
			new_container.pushback(_long_values[i]);

		for (size_t i = 0; i < Long_Integer_Container_obj._size; i++)
			new_container.pushback(Long_Integer_Container_obj._long_values[i]);

		return new_container;
	}
	Long_Integer_Container& operator = (const Long_Integer_Container& Long_Integer_Container_obj)
	{
		if (_size >= Long_Integer_Container_obj._size)
		{
			for (size_t i = 0; i < Long_Integer_Container_obj._size; i++)
				_long_values[i] = Long_Integer_Container_obj[i];
			_size = Long_Integer_Container_obj._size;
			if (_size < _capacity / 2) Shrink_capacity();
		}
		else
		{
			long long* new_list_for_copie = new long long[Long_Integer_Container_obj._capacity];
			for (size_t i = 0; i < Long_Integer_Container_obj._size; i++)
				new_list_for_copie[i] = Long_Integer_Container_obj[i];
			delete[] _long_values;
			_long_values = new_list_for_copie;
			_size = Long_Integer_Container_obj._size;
			_capacity = Long_Integer_Container_obj._capacity;
		}
		return *this;
	}

	long long& operator [ ] (size_t index)	{ return *(_long_values + index); }
	long long& operator [ ] (size_t index) const { return *(_long_values + index); }

	friend std::ostream& operator << (std::ostream& out, Long_Integer_Container* Long_Integer_Container_obj);
	friend std::ostream& operator << (std::ostream& out, Long_Integer_Container& Long_Integer_Container_obj);
	friend std::istream& operator >> (std::istream& in, Long_Integer_Container& Long_Integer_Container_obj)
	{
		Long_Integer_Container_obj.pushback(Get_Int_SA());
		return in;
	}

};

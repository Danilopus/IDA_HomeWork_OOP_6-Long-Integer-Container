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

	void Add_capacity(size_t capacity_to_add = 0);
	void Shrink_capacity();

public:

	// Constructors // Initialisation // Destructors // Memory Manage -------
	Long_Integer_Container();
	Long_Integer_Container(const Long_Integer_Container& Long_Integer_Container_obj);

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q8 как сделать универсальныю инициализацию Long_Integer_Container_obj {5, 7, 9}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::		
	
	~Long_Integer_Container();

	// Setters // Getters --------------------------------------------------

	// Data manage ---------------------------------------------------------
	
	Long_Integer_Container& pushfront(long long new_value);
	Long_Integer_Container& popfront();
	Long_Integer_Container& pushback(long long new_value);
	Long_Integer_Container& popback();
	Long_Integer_Container& insert(size_t pos, long long  new_value);

	size_t size() { return _size; }

	long long int* begin();
	long long int* end();

	Long_Integer_Container& clear();

	// Shows ---------------------------------------------------------------
	void ShowValues();

	//Overload operators - reference returned -----------------------------------------	
	
	Long_Integer_Container& operator + (const Long_Integer_Container& Long_Integer_Container_obj) const;
	Long_Integer_Container& operator = (const Long_Integer_Container& Long_Integer_Container_obj);

	long long& operator [ ] (size_t index);
	long long& operator [ ] (size_t index) const;

	friend std::ostream& operator << (std::ostream& out, Long_Integer_Container* Long_Integer_Container_obj);
	friend std::ostream& operator << (std::ostream& out, Long_Integer_Container& Long_Integer_Container_obj);
	friend std::istream& operator >> (std::istream& in, Long_Integer_Container& Long_Integer_Container_obj);

};

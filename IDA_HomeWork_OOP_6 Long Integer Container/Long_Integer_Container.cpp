#include "Long_Integer_Container.h"

void Long_Integer_Container::Add_capacity(size_t capacity_to_add)
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

void Long_Integer_Container::Shrink_capacity()
{
	size_t new_capacity = _size + _size / 2;
	long long* new_list = new long long[new_capacity];
	for (int i = 0; i < _size; i++)
		new_list[i] = _long_values[i];
	delete[] _long_values;
	_long_values = new_list;
	//return *this;
}

Long_Integer_Container::Long_Integer_Container()
{ 
	_size = 0;
	_capacity = 0;
	_long_values = nullptr;
}

Long_Integer_Container::Long_Integer_Container(const Long_Integer_Container& Long_Integer_Container_obj) { *this = Long_Integer_Container_obj; }

Long_Integer_Container::~Long_Integer_Container()
{
	//for (int i = 0; i < _size; i++)
	delete[] _long_values;
}

Long_Integer_Container& Long_Integer_Container::pushfront(long long new_value)
{
	if (_size >= _capacity) Add_capacity();
	for (int i = _size; i > 0; i--)
		_long_values[i] = _long_values[i - 1];
	_long_values[0] = new_value;
	_size++;
	return *this;
}

Long_Integer_Container& Long_Integer_Container::popfront()
{
	_size--;
	if (_size == 0) { clear(); return *this; }
	if (_size < _capacity / 2) Shrink_capacity();
	for (int i = 0; i < _size; i++)
		_long_values[i] = _long_values[i + 1];
	return *this;
}

Long_Integer_Container& Long_Integer_Container::pushback(long long new_value)
{
	if (_size >= _capacity) Add_capacity();
	_long_values[_size] = new_value;
	_size++;
	return *this;
}

Long_Integer_Container& Long_Integer_Container::popback()
{
	_size--;
	if (_size == 0) { clear(); return  *this; }
	if (_size < _capacity / 2) Shrink_capacity();
	return *this;
}

Long_Integer_Container& Long_Integer_Container::insert(size_t pos, long long new_value)
{
	if (_size >= _capacity) Add_capacity();
	for (int i = _size; i > pos; i--)
		_long_values[i] = _long_values[i - 1];
	_long_values[pos] = new_value;
	_size++;
	return *this;
}

long long int* Long_Integer_Container::begin()
{
	return _long_values;
}

long long int* Long_Integer_Container::end()
{
	return _long_values+_size - 1;
}

Long_Integer_Container& Long_Integer_Container::clear()
{
	delete[] _long_values;
	_size = 0;
	_capacity = 0;
	_long_values = nullptr;
	return *this;
}

void Long_Integer_Container::ShowValues() { std::cout << this; }

Long_Integer_Container& Long_Integer_Container::operator+(const Long_Integer_Container& Long_Integer_Container_obj) const
{
	Long_Integer_Container& new_container = *new Long_Integer_Container;
	for (size_t i = 0; i < _size; i++)
		new_container.pushback(_long_values[i]);

	for (size_t i = 0; i < Long_Integer_Container_obj._size; i++)
		new_container.pushback(Long_Integer_Container_obj._long_values[i]);

	return new_container;
}

Long_Integer_Container& Long_Integer_Container::operator=(const Long_Integer_Container& Long_Integer_Container_obj)
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

long long& Long_Integer_Container::operator[](size_t index) { return *(_long_values + index); }

long long& Long_Integer_Container::operator[](size_t index) const { return *(_long_values + index); }

std::ostream& operator<<(std::ostream& out, Long_Integer_Container* Long_Integer_Container_obj)
{
	if (Long_Integer_Container_obj->_long_values == nullptr) 
		return out << "[no data]";
	
	out << "[ ";
	for (int i=0; i < Long_Integer_Container_obj->_size; i++)
	//out << Long_Integer_Container_obj->_long_values[i] << " | ";
	out << (*Long_Integer_Container_obj)[i] << " | ";
	out << "\b\b]";
	return out;
}
std::ostream& operator<<(std::ostream& out, Long_Integer_Container& Long_Integer_Container_obj)
{
	if (Long_Integer_Container_obj._long_values == nullptr)
		return out << "[no data]";

	out << "[ ";
	for (int i = 0; i < Long_Integer_Container_obj._size; i++)
//		out << Long_Integer_Container_obj._long_values[i] << " | ";
		out << Long_Integer_Container_obj[i] << " | ";
	out << "\b\b]";
	return out;
}
std::istream& operator>>(std::istream& in, Long_Integer_Container& Long_Integer_Container_obj)
{
	Long_Integer_Container_obj.pushback(Get_LL_SA());
	return in;
}

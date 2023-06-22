#include "Long_Integer_Container.h"


std::map <int, std::string> keycodes{ {27, "Esc"}, {13, "Enter"}, {48, "0"}, {57, "9"} };
std::string console_clear = "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
std::string big_space = "                                                           ";
std::map <int, int> codes_of_digits{ {49, 0}, {50, 1}, {51, 2},{52, 3},{53, 4},{54, 5},{55, 6},{56, 7},{57, 8} };
// Операции с дробями 
//std::map <int, std::string> Fraction::codes_of_operation{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, "++"}, {6,"++"}, {7, "--"}, {8,"--"},{9,"+"}, {0, "-"} };
std::map <int, std::string> Long_Integer_Container::codes_of_operation{ {1," + "}, {2," - "}, {3," * "}, {4, " / "}, {5, " * "}, {6," / "}, {7, " > "}, {8," < "},{9," = "}, {0, "=="} };


Long_Integer_Container::Long_Integer_Container() 
{ 
	_size = 0;
	_capacity = 0;
	_long_values = nullptr;
}

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

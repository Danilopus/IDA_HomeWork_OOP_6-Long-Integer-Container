#pragma once
#include "Long_Integer_Container.h"

class UnitTest
{
	//std::string _test_report;
public:
	std::string Long_Integer_Container_test()
	{
		std::string test_report;
		Long_Integer_Container test_obj;
		
		test_report += "\nData manage methods test_1: " + Long_Integer_Container_test_methods_1(test_obj) ? "Îê" : "failed";
		test_report += "\nData manage methods test_2: " + Long_Integer_Container_test_methods_2(test_obj) ? "Îê" : "failed";

        
	}
	bool Long_Integer_Container_test_methods_1(Long_Integer_Container& test_obj)
	{
		std::cout << "\nTesting data manage methods\nLong_Integer_Container_obj_1.pushback(3).pushback(5).pushfront(2).pushfront(1).insert(3, 4).ShowValues()";
		test_obj.pushback(3).pushback(5).pushfront(2).pushfront(1).insert(3, 4).ShowValues();

		if (Summ(test_obj) == 20) { return true; }
		return false;
	}
	bool Long_Integer_Container_test_methods_2(Long_Integer_Container& test_obj)
	{
		std::cout << "\nTesting data manage methods\ntest_obj.popback().popfront();";
		std::cout << test_obj.popback().popfront();

		if (Summ(test_obj) == 15) { return true; }
		return false;
	}

	long long Summ(Long_Integer_Container Long_Integer_Container_obj)
	{
		long long Summ{};
		for (size_t i = 0; i < Long_Integer_Container_obj.size(); i++)
			Summ += Long_Integer_Container_obj[i];
		return Summ;
	}
};


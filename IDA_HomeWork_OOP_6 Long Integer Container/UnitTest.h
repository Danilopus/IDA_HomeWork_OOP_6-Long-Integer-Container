#pragma once
#include "Long_Integer_Container.h"

class UnitTest
{
public:
	static std::string Long_Integer_Container_test()
	{
		std::string test_report = "\n\n*** Tests status\n";
		Long_Integer_Container test_obj;
		
		test_report += "\nData manage methods test_1: ";
		test_report += Long_Integer_Container_test_methods_1(test_obj) ? "Ok" : "failed";
		test_report += "\nData manage methods test_2: ";
		test_report += Long_Integer_Container_test_methods_2(test_obj) ? "Ok" : "failed";
		test_report += "\nPointers test: ";
		test_report += Long_Integer_Container_test_pointers(test_obj) ? "Ok" : "failed";
		test_report += "\nClear test: ";
		test_report += Long_Integer_Container_test_4(test_obj) ? "Ok" : "failed";
		test_report += "\nOperator test: ";
		test_report += Long_Integer_Container_test_5(test_obj) ? "Ok" : "failed";
		test_report += "\nOperator << cin test: ";
		test_report += Long_Integer_Container_test_6(test_obj) ? "Ok" : "failed";

		
		return test_report;
	}
	static bool Long_Integer_Container_test_methods_1(Long_Integer_Container& test_obj)
	{
		std::cout << "\nData manage methods test_1\ntest_obj.pushback(3).pushback(5).pushfront(2).pushfront(1).insert(3, 4).ShowValues()\n";
		test_obj.pushback(3).pushback(5).pushfront(2).pushfront(1).insert(3, 4).ShowValues();

		if (Summ(test_obj) == 15) { return true; }
		return false;
	}
	static bool Long_Integer_Container_test_methods_2(Long_Integer_Container& test_obj)
	{
		std::cout << "\n" << "\nData manage methods test_2\ntest_obj.popback().popfront()\n";
		std::cout << test_obj.popback().popfront();

		if (Summ(test_obj) == 9) { return true; }
		return false;
	}
	static bool Long_Integer_Container_test_pointers(Long_Integer_Container& test_obj)
	{
		bool result=1;
		std::cout << "\n\nPointers test:" << "\n*test_obj.begin() == test_obj[0]";
		if (*test_obj.begin() == test_obj[0]) std::cout << " true";
		else { std::cout << " false"; result = 0; }

		std::cout << "\n" << "*test_obj.end() == test_obj[test_obj.size()-1])";
		if (*test_obj.end() == test_obj[test_obj.size() - 1]) std::cout << " true";
		else { std::cout << " false"; result = 0; }

		return result;
	}
	static bool Long_Integer_Container_test_4(Long_Integer_Container& test_obj)
	{
		std::cout << "\n\nClear test" << "\n" << "test_obj.clear().ShowValues()\n";
		test_obj.clear().ShowValues();

		if (test_obj.size() == 0) { return true; }
		return false;
	}
	static bool Long_Integer_Container_test_5(Long_Integer_Container& test_obj)
	{
		Long_Integer_Container test_obj_2, test_obj_3;
		std::cout << "\n\nOperator test" << "\n" << "test_obj.pushfront(3).pushfront(2).pushfront(1)\ntest_obj_3 = test_obj_2 = test_obj\ntest_obj_3.ShowValues()\n";
		test_obj.pushfront(3).pushfront(2).pushfront(1);
		test_obj_3 = test_obj_2 = test_obj;
		test_obj_3.ShowValues();

		std::cout << "\n " << "\n" << "test_obj_2.insert(0, 555)\ntest_obj_3 = test_obj + test_obj_2\ntest_obj_3.ShowValues()\n";
		test_obj_2.insert(0, 555);
		test_obj_3 = test_obj + test_obj_2;
		test_obj_3.ShowValues();

		if (Summ(test_obj_3) == 567) { return true; }
		return false;
	}
	static bool Long_Integer_Container_test_6(Long_Integer_Container& test_obj)
	{
		std::cout << "\n\nOperator << cin test" << "\n" 
			<< "std::cin >> test_obj\n";
		std::cin >> test_obj;
		
		std::cout << "\n " << "test_obj.ShowValues()\n";
		test_obj.ShowValues();
		
		if (test_obj.size()) { return true; }
		return false;
	}

	static long long Summ(Long_Integer_Container Long_Integer_Container_obj)
	{
		long long Summ{};
		for (size_t i = 0; i < Long_Integer_Container_obj.size(); i++)
			Summ += Long_Integer_Container_obj[i];
		return Summ;
	}
};


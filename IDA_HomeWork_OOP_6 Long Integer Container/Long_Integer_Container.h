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

	void Add_capacity(size_t capacity_to_add = 5)
	{

	}

public:

	// Constructors // Initialisation // Destructors // Memory Manage -------
	Long_Integer_Container();

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
	Long_Integer_Container& Set_roubles(long long rubles);
	Long_Integer_Container& Set_coins(long long coins);
	long long Get_roubles() { return _roubles; }
	int Get_coins() { return _coins; }

	// Data manage ---------------------------------------------------------
	
	Long_Integer_Container& pushback(long long new_value)
	{
		if (_capacity == _size) Add_capacity();
		_long_values[_size] = new_value;
		_size++;
	}
	long long& popback()
	{
		_size--;
		return _long_values[_size];

	}



	// Shows ---------------------------------------------------------------
	void ShowValues() { std::cout << *this; }
	//void ShowValues() { std::cout << this; }
	static void ShowMethods();
	static void ShowAvailableMoneyObjects();

	// Inputs handle -------------------------------------------------------	
		
	// getch модификация - удобный интерфейс ввода без нажатия Enter и с обработкой Esc, пока только для списков 0..9 (надо придумать как принимать одно- и двух-циферные значения в одном интерфейсе через _getch
	// getline модификация - c вводом произвольных чисел и конторолем ввода через функцию Get_Int_Positive(), ввод необходимо подтверждать Enter

	//for (;;)
	//{
	//	cout << "You are playing for:" << playtime << "seconds." << endl;
	//	cout << "You have " << bytes << " bytes." << endl;
	//	cout << "You are compiling " << bps << " bytes per second." << endl;
	//	cout << "Press a to buy assembler monkey (produces 1 byte per second)/(cost 10 bytes)" << endl;
	//	if (kbhit()) {  //is true when a key was pressed
	//		char c = getch();   //capture the key code and insert into c

	//		switch (c)
	//		{
	//		case 'a': bytes = bytes - 10; bps++; break;
	//		}
	//	}
	//	bytes = bytes + bps;
	//	playtime++;
	//	Sleep(1000);
	//	system("cls");
	//}

	static int UserChoiceHandle_getch();
	static int UserChoiceHandle_getline();

	static Long_Integer_Container* Get_Operand_getch(int Operand_number);
	static Long_Integer_Container& Get_Operand_getline(int Operand_number);
	static Long_Integer_Container& New_money_holder_input();

	static int Check_method_input_getch();
	static int Check_action_input_getline();

	static void Operation_module(int action, Long_Integer_Container& Operand_1, Long_Integer_Container& Operand_2);
	static void Operation_module(int action, Long_Integer_Container& Operand_1, double Operand_2);

	//Overload operators - reference returned -----------------------------------------

	//Long_Integer_Container* operator+(Long_Integer_Container & another_Money);
	Long_Integer_Container& operator+(const Long_Integer_Container& another_Money) const;
	Long_Integer_Container& operator-(const Long_Integer_Container& another_Money) const;
	Long_Integer_Container& operator*(const Long_Integer_Container& another_Money) const;
	Long_Integer_Container& operator*(double multiplier) const;
	Long_Integer_Container& operator/(double divider) const;
	double operator/(const Long_Integer_Container& another_Money) const;
	bool operator>(const Long_Integer_Container& another_Money) const;
	bool operator<(const Long_Integer_Container& another_Money) const;
	bool operator==(const Long_Integer_Container& another_Money) const;

	friend std::ostream& operator << (std::ostream& out, Long_Integer_Container* just_a_Money);
	friend std::ostream& operator << (std::ostream& out, Long_Integer_Container& Money_holder);
};
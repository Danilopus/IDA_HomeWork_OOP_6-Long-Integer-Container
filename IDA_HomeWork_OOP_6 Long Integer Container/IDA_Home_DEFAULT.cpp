﻿// HomeWork template project v 5.0 // 22.06.2023 //

/*

Задание

Необходимо реализовать контейнер для хранения больших целых чисел, 
с поддержкой техники ввода/вывода данных аля поток ввода/вывода

*/

#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <conio.h>
//#include <array>
//My own headers
#include "Service functions.h"
#include "MainMenu.h"
#include "Long_Integer_Container.h"



// Homework OOP 6 ----------------------------------------------------	


//Task 1 Money class demo with overloaded operators:\n\t + | - | / | * | > | < | =
void Task_1(std::string name_of_task)
{
	std::cout << "Enter provided_at_startup_money_holders_quantity -> ";
	//int provided_at_startup_money_holders_quantity = Get_Int_Positive(0, 10, "it's too much, reasonable limit is 10 -> ");
	//Money::Initialisation(provided_at_startup_money_holders_quantity);
	Money::Initialisation(Get_Int_Positive(0, 10, "it's too much, reasonable limit is 10 -> "));

	do
	{
		system("cls");
		std::cout << "***\t" << name_of_task << "\n";
		Money::ShowAvailableMoneyObjects();
		Money::ShowMethods();
		if (Money::UserChoiceHandle_getch()) break;

		std::cout << "\n\nEsc - exit | any key to continue";
	} while (_getch() != 27);
	Money::Memory_Clean();
}

//Task 2
void Task_2(){}

//Task 3 
void Task_3() {}

//Task 4
void Task_4() {}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
	srand(time(NULL));
	//setlocale(LC_CTYPE, "Russian");
	//system("mode con cols=60 lines=40"); 
	Main_menu MainMenu;	
	MainMenu.AddElement("OOP Home Work 06:  Long Integer Container class");	// Homework name
	MainMenu.AddElement("Long Integer Container class demo with overloaded operators:\n\t << | >> ");
	//MainMenu.AddElement("XXX");
	do 
	{		
		MainMenu.Show_menu();
		if (!MainMenu.User_Choice_Handle(_getch()))	break;
	} while (true);
	return 0;
}


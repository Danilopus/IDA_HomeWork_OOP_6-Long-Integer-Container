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

void Long_Integer_Container::Initialisation(int provided_at_startup_money_holders_quantity)
{
	for (int i = 0; i < provided_at_startup_money_holders_quantity; i++)
		new Long_Integer_Container(Get_Random(0, 100), Get_Random(0, 100));
}

void Long_Integer_Container::Memory_Clean() {}

Long_Integer_Container& Long_Integer_Container::Set_roubles(long long rubles) { _roubles = rubles; return *this; }

Long_Integer_Container& Long_Integer_Container::Set_coins(long long coins)
{
	_coins = coins % 100;
	Set_roubles(_roubles += (coins / 100));
	return *this;
}

void Long_Integer_Container::ShowMethods()
{
	std::cout << "\n\n -------- Available methods: --------\n";
	std::cout << "Summation [+] -> [1]" << "\t\t" << "Multyply by [real] -> [5]" << '\n';
	std::cout << "Substract [-] -> [2]" << "\t\t" << "Divide   by [real] -> [6]" << '\n';
	std::cout << "Multiply  [*] -> [3]" << "\t\t" << "is_more     [>]    -> [7]" << '\n';
	std::cout << "Divide    [/] -> [4]" << "\t\t" << "is_less     [<]    -> [8]" << '\n';
	std::cout <<     "                                is_equal    [=]    -> [9]" << '\n';


	// Вариант от дробей	
	/*std::cout << "\nAvailable methods:\n\nBinary:\t\t\t\t" << "Unary:\n";
	std::cout << "Summation [+] -> [1]" << "\t\t" << "Prefix increment  [++v] -> [5]" << '\n';
	std::cout << "Substract [-] -> [2]" << "\t\t" << "Postfix increment [v++] -> [6]" << '\n';
	std::cout << "Multiply  [*] -> [3]" << "\t\t" << "Prefix decrement  [--v] -> [7]" << '\n';
	std::cout << "Divide    [/] -> [4]" << "\t\t" << "Postfix decrement [v--] -> [8]" << '\n';
	std::cout << "\t\t\t\tUnary plus        [+v]  -> [9]" << '\n';
	std::cout << "\t\t\t\tUnary minus       [-v]  -> [0]" << '\n';*/

}

void Long_Integer_Container::ShowAvailableMoneyObjects()
{
	for (int i = 0; i < _money_list.size(); i++)
		std::cout << "\nMoney holder [" << i + 1 << "] -> " << _money_list[i];
	//_money_list[i].ShowValues();
}

int Long_Integer_Container::UserChoiceHandle_getch()
{
	std::cout << "Choose method: ";
	int method_choice = Check_method_input_getch();
	if (method_choice == -1) return 1;
	std::cout << "-------->  " << codes_of_operation[method_choice] << big_space;


	if (method_choice < 5 || method_choice > 6)//разделеям бинарные операции между объектами и числами
	{
		Long_Integer_Container& Operand_1 = *Get_Operand_getch(1);
		if (&Operand_1 == nullptr) return 0;
		std::cout << "\n   " << codes_of_operation[method_choice];
		Long_Integer_Container& Operand_2 = *Get_Operand_getch(2);
		if (&Operand_2 == nullptr) return 0;

		Operation_module(method_choice, Operand_1, Operand_2);

	}
	else
	{
		Long_Integer_Container& Operand_1 = *Get_Operand_getch(1);
		if (&Operand_1 == nullptr) return 0;
		std::cout << "\nEnter a [real] -> ";
		double Operand_2 = Get_Dbl_Positive();
		if (Operand_2 == 0) { std::cout << "Division by zero"; return 0; }


		Operation_module(method_choice, Operand_1, Operand_2);
	}


	return 0;
}

int Long_Integer_Container::UserChoiceHandle_getline()
{
	int action = Check_action_input_getline();
	if (action == -1) return 1;
	std::cout << "-------->  " << codes_of_operation[action] << big_space;


	Long_Integer_Container& Operand_1 = Get_Operand_getline(1);
	if (&Operand_1 == nullptr) return 1;
	std::cout << "\n   " << codes_of_operation[action];
	Long_Integer_Container& Operand_2 = Get_Operand_getline(2);
	if (&Operand_2 == nullptr) return 1;

	Operation_module(action, Operand_1, Operand_2);
}

Long_Integer_Container* Long_Integer_Container::Get_Operand_getch(int Operand_number)
//static Long_Integer_Container& Get_Operand_getch(int Operand_number)
{
	if (Operand_number)
		std::cout << "\nOperand_" << Operand_number << ": Choose operand from list [press number] or enter new [press Enter]";
	else std::cout << "\nOperand" << ": Choose operand from list [press number] or enter new [press Enter]";

	do
	{
		int input = _getch();
		//std::cout << console_clear;
		if (keycodes[input] == "Enter")
			//if (input == 27)
		{
			std::cout << console_clear;
			return &New_money_holder_input();
		}
		else if (keycodes[input] == "Esc") return nullptr;
		//else if (input == 27) return;
		/*else if (input == 0 || input == 224) // обработка KeyPad + NumLock [off] и всякие другие двойные кнопки [стрелочки, Del, End, PageDown итп]
		{
			_getch();
			std::cout << "\nTurn NumLock On";
			return nullptr;
		}*/
		else if (49 <= input && input <= 57)
		{
			//_getch(); придумать 2х значный ввод
			std::cout << console_clear;
			if (codes_of_digits[input] >= _money_list.size())
			{
				std::cout << console_clear << "index out of range" << big_space;
				return nullptr;
			}
			std::cout << "  [" << codes_of_digits[input] + 1 << "]                                                        ";
			return &_money_list[codes_of_digits[input]];
		}
	} while (true);
}

Long_Integer_Container& Long_Integer_Container::Get_Operand_getline(int Operand_number) {

	if (Operand_number)	std::cout << "\nchoose operand " << Operand_number << ": ";
	else std::cout << "\nchoose operand: ";
	std::string comment = "index out of range ";
	comment += "[1.." + std::to_string(_money_list.size()) + "] ";
	int Money_index = Get_Int_Positive(1, _money_list.size(), comment);
	--Money_index; //transform number to index

	return _money_list[Money_index];
}

Long_Integer_Container& Long_Integer_Container::New_money_holder_input()
{
	std::cout << big_space;
	std::cout << "\nEnter roubles -> ";
	long long roubles = Get_Int_Positive();
	std::cout << "Enter coins   -> ";
	int coins = Get_Int_Positive();

	return *new Long_Integer_Container(coins, roubles);
}

int Long_Integer_Container::Check_method_input_getch()
{
	int keycode = _getch();
	std::cout << console_clear;
	if (keycode == 27) return -1;
	if (keycode >= 48 && keycode <= 57)
		return (keycode - 48);
	//std::cout << "\nkeycode " << keycode;
	std::cout << "Press a number of operation [1..9]";
	Check_method_input_getch();
}

int Long_Integer_Container::Check_action_input_getline()
{
	int keycode = Get_Int_Positive(1, 9, "Choose a number of operation [1..9] ");
	std::cout << console_clear;
	//if (keycode == 27) return -1;
	//std::cout << "\nkeycode " << keycode;
	//std::cout << "Press a number of operation [0..9]";
	return keycode;
}

void Long_Integer_Container::Operation_module(int action, Long_Integer_Container& Operand_1, Long_Integer_Container& Operand_2)
{
	std::cout << "\n\n" << Operand_1 << codes_of_operation[action] << Operand_2 << " = ";
	bool logical_statement = 0;
	double percent = 100;
	switch (action)
	{
	case 1: Operand_1 + Operand_2; break;
	case 2: Operand_1 - Operand_2; break;
	case 3: Operand_1 * Operand_2; break;
	case 4: percent = (Operand_1 / Operand_2); break;
		//case 5: ++Operand; break;
		//case 6: Operand++; break;
	case 7: logical_statement = (Operand_1 > Operand_2); break;
	case 8: logical_statement = (Operand_1 < Operand_2); break;
	case 9: logical_statement = (Operand_1 == Operand_2); break;
		//case 0: -Operand; break;
	}
	if (action >= 7)
		if (logical_statement) std::cout << "true";
		else	std::cout << "false";
	else if (action == 4)
		std::cout << percent << "%";
	else
		std::cout << _money_list[_money_list.size() - 1];
}

void Long_Integer_Container::Operation_module(int action, Long_Integer_Container& Operand_1, double Operand_2)
{
	std::cout << "\n\n" << Operand_1 << codes_of_operation[action] << Operand_2 << " = ";
	switch (action)
	{
	case 5: Operand_1 * Operand_2; break;
	case 6: Operand_1 / Operand_2; break;
		//case 0: -Operand; break;
	}
	std::cout << _money_list[_money_list.size() - 1];
}

Long_Integer_Container& Long_Integer_Container::operator+(const Long_Integer_Container& another_Money) const
{
	return *new Long_Integer_Container((_coins + another_Money._coins), (_roubles + another_Money._roubles));
}

Long_Integer_Container& Long_Integer_Container::operator-(const Long_Integer_Container& another_Money) const
{
	long long full_coin_amount = (_roubles * 100 + _coins) - (another_Money._roubles * 100 + another_Money._coins);
	assert((full_coin_amount >= 0) && "Debt");
	return *new Long_Integer_Container(full_coin_amount);
}

Long_Integer_Container& Long_Integer_Container::operator*(const Long_Integer_Container& another_Money) const
{
	return *new Long_Integer_Container((_coins * another_Money._coins), (_roubles * another_Money._roubles));
}

Long_Integer_Container& Long_Integer_Container::operator*(double multiplier) const
{
	return *new Long_Integer_Container(long long((_coins + _roubles * 100) * multiplier));
}

Long_Integer_Container& Long_Integer_Container::operator/(double divider) const
{
	return *new Long_Integer_Container((_coins + _roubles * 100) / divider);
}

double Long_Integer_Container::operator/(const Long_Integer_Container& another_Money) const //процент какая первая сумма от второй
{
	double coefficient = double((_roubles * 100 + _coins)) / double((another_Money._roubles * 100 + another_Money._coins));
	return coefficient * 100;
}

bool Long_Integer_Container::operator>(const Long_Integer_Container& another_Money) const
{
	long long full_coin_amount = (_roubles * 100 + _coins) - (another_Money._roubles * 100 + another_Money._coins);
	return (full_coin_amount < 0 ? 0 : 1);
}

bool Long_Integer_Container::operator<(const Long_Integer_Container& another_Money) const
{
	long long full_coin_amount = (_roubles * 100 + _coins) - (another_Money._roubles * 100 + another_Money._coins);
	return (full_coin_amount < 0 ? 1 : 0);
}

bool Long_Integer_Container::operator==(const Long_Integer_Container& another_Money) const
{
	long long full_coin_amount = (_roubles * 100 + _coins) - (another_Money._roubles * 100 + another_Money._coins);
	return (full_coin_amount == 0 ? 1 : 0);
}

std::ostream& operator<<(std::ostream& out, Long_Integer_Container* Long_Integer_Container_obj)
{
	out << "[";
	for (int i=0; i < (*Long_Integer_Container_obj)._size; i++)
	out << Long_Integer_Container_obj->_long_values[i] << " | ";
	return out;
}

std::ostream& operator<<(std::ostream& out, Long_Integer_Container& Money_holder)
{
	//out << Money_holder.Get_roubles() << ", " << Money_holder.Get_coins();
	out << Money_holder.Get_roubles() << " roubles " << Money_holder.Get_coins() << " coins ";
	return out;
}
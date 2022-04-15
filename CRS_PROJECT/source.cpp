#include "our_Function.h"
int main()
{
	read_from_index_file();
	read_from_car_file();
	read_from_customer_file();
	read_from_admin_file();
	char x;
	do
	{
		cout << "if you want to add new car enter 1\n";
		cout << "if you want to add new customer enter 2\n";
		int u;
		cin >> u;
		if (u == 1)
		{
			add_new_car_to_array();
		}
		else if (u == 2)
		{
			add_new_customer_to_array();
		}
		else
		{
			cout << "Invalid choise\n";
		}
		cout << "do yo want to continue (y / n)\n";
		cin >> x;
	} while (x == 'y');
	cout << "Thanks to deal with CRC\n";
	write_in_car_file();
	write_in_customer_file();
	write_in_index_file();

	return 0;
}
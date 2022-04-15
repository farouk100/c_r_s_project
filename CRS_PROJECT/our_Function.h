#pragma once
#include "Our_Variables.h"


void read_from_index_file()
{
	index_file.open("index.txt", ios::in);
	index_file >> check_st;
	i = stoi(check_st);
	index_file >> check_st;
	j = stoi(check_st);
	index_file.close();
}

void read_from_car_file()
{
	my_file.open("car.txt", ios::in);
	my_file >> check_st;
	my_file.close();
	if (check_st != "\0")
	{
		my_file.open("car.txt", ios::in);
		for (int j = 0; j < i; j++)
		{
			getline(my_file, car[j].type, '#');
			getline(my_file, car[j].L_P_N, '#');
			getline(my_file, check_st, '#');	car[j].cost.hour = stoi(check_st);
			getline(my_file, check_st, '#');	car[j].cost.day = stoi(check_st);
			getline(my_file, check_st, '#');	car[j].cost.week = stoi(check_st);
			getline(my_file, car[j].current_branch, '#');
			getline(my_file, check_st, '#');	car[j].status = stoi(check_st);
			getline(my_file, check_st, '#');	car[j].date.start_day = stoi(check_st);
			getline(my_file, check_st, '#');	car[j].date.start_month = stoi(check_st);
			getline(my_file, check_st, '#');	car[j].date.start_year = stoi(check_st);
			getline(my_file, check_st, '#');	car[j].date.end_day = stoi(check_st);
			getline(my_file, check_st, '#');	car[j].date.end_month = stoi(check_st);
			getline(my_file, check_st, '#');	car[j].date.end_year = stoi(check_st);
			getline(my_file, car[j].return_branch);
		}
		my_file.close();
	}
}

void read_from_customer_file()
{
	my_customer_file.open("customer.txt", ios::in);
	my_customer_file >> check_st;
	my_customer_file.close();
	if (check_st != "\0")
	{
		my_customer_file.open("customer.txt", ios::in);
		for (int a = 0; a < j; a++)
		{
			getline(my_customer_file, customer[a].first_name, '#');
			getline(my_customer_file, customer[a].last_name, '#');
			getline(my_customer_file, check_st, '#'); customer[a].age = stoi(check_st);
			getline(my_customer_file, customer[a].id, '#');
			getline(my_customer_file, customer[a].phone, '#');
			getline(my_customer_file, customer[a].C_C_N, '#');
			getline(my_customer_file, customer[a].username, '#');
			getline(my_customer_file, customer[a].password, '#');
			for (int t = 0; t < the_allowed_rentals_for_customer; t++)
			{
				getline(my_customer_file, check_st, '#');
				customer[a].cusromer_rental[t].current_or_previous = stoi(check_st);
				getline(my_customer_file, customer[a].cusromer_rental[t].rental, '#');
			}
		}
		my_customer_file.close();
	}
}

void read_from_admin_file()
{
	my_admin_file.open("admin.txt", ios::in);
		for (int a = 0; a < num_of_admin; a++)
		{
			getline(my_admin_file, admin[a].username,'#');
			getline(my_admin_file,admin[a].password,'#');
		}
		my_admin_file.close();
}


void add_new_car_to_array()
{
	char choise;
	do
	{
		if (i == car_Array_Size)
		{
			cout << "You can't add more than " << car_Array_Size << " cars.\n";
			break;
		}
		cout << "Enter the car type:\n";	              cin >> car[i].type;
		cout << "Enter the car licence plat number:\n";	  cin >> car[i].L_P_N;
		cout << "Enter the cost of the hour:\n";          cin >> car[i].cost.hour;
		cout << "Enter the cost of the day:\n";           cin >> car[i].cost.day;
		cout << "Enter the cost of the week:\n";          cin >> car[i].cost.week;
		cout << "Enter the current branch:\n";            cin >> car[i].current_branch;
		cout << "Is the car free to rental (1/0):\n";     cin >> car[i].status;
		if (car[i].status == 0)
		{
			cout << "Enter the start date of the rental:\n";
			cin >> car[i].date.start_day >> car[i].date.start_month >> car[i].date.start_year;
			cout << "Enter the end date of the rental:\n";
			cin >> car[i].date.end_day >> car[i].date.end_month >> car[i].date.end_year;
			cout << "Enter the return branch:\n";         cin >> car[i].return_branch;
		}
		cout << "The car is succesfuly added\n";
		i++;
		cout << "Do you want to add another car? (y/n)\n";
		cin >> choise;
	} while (choise == 'y');
}

void add_new_customer_to_array()
{
	char choise;
	do
	{
		if (j == customer_array_size)
		{
			cout << "You can't add more than " << customer_array_size << " customers.\n";
			break;
		}
		cout << "Enter the customer first name:\n";	              cin >> customer[j].first_name;
		cout << "Enter the customer last name:\n";	  cin >> customer[j].last_name;
		cout << "Enter the customer age:\n";          cin >> customer[j].age;
		cout << "Enter the customer national id:\n";           cin >> customer[j].id;
		cout << "Enter the customer phone number:\n";          cin >> customer[j].phone;
		cout << "Enter the customer credit card number:\n";            cin >> customer[j].C_C_N;
		cout << "Is the customer username:\n";     cin >> customer[j].username;
		cout << "Is the customer password:\n";     cin >> customer[j].password;
		cout << "The customer is succesfuly added\n";
		j++;
		cout << "Do you want to add another car? (y/n)\n";
		cin >> choise;
	} while (choise == 'y');
}

void write_in_car_file()
{
	my_file.open("car.txt", ios::out);
	for (int j = 0; j < i; j++)
	{
		my_file << car[j].type << "#" << car[j].L_P_N << "#" << car[j].cost.hour << "#" << car[j].cost.day << "#" << car[j].cost.week << "#" <<
			car[j].current_branch << "#" << car[j].status << "#" << car[j].date.start_day << "#" << car[j].date.start_month << "#" <<
			car[j].date.start_year << "#" << car[j].date.end_day << "#" << car[j].date.end_month << "#" << car[j].date.end_year <<"#" << 
			car[j].return_branch << "\n";
	}
	my_file.close();
}

void write_in_customer_file()
{
	my_customer_file.open("customer.txt", ios::out);
	for (int a = 0; a < j; a++)
	{
		my_customer_file << customer[a].first_name << "#" << customer[a].last_name << "#" << customer[a].age << "#" << customer[a].id << "#" << customer[a].phone << "#" <<
			customer[a].C_C_N << "#" << customer[a].username << "#" << customer[a].password << "#";
		for (int b = 0; b < the_allowed_rentals_for_customer; b++)
		{
			my_customer_file << customer[a].cusromer_rental[b].current_or_previous << "#" << customer[a].cusromer_rental[b].rental << "#";
		}
		my_customer_file << "\n";
	}
	my_customer_file.close();
}

void write_in_index_file()
{
	index_file.open("index.txt", ios::out);
	index_file << i << "\n";
	index_file << j;
	index_file.close();
}
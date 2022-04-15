#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Cost
{
	int hour, day, week;
};
struct Date
{
	int start_day, start_month, start_year, end_day, end_month, end_year;
};
struct Car
{
	string type, L_P_N, return_branch, current_branch;
	bool status;
	Cost cost;
	Date date;
};


struct rentals
{
	bool current_or_previous;
	string rental;
};
#define the_allowed_rentals_for_customer 10
struct Customer
{
	string first_name, last_name, id, phone, C_C_N , username , password;
	int age;
	rentals cusromer_rental[the_allowed_rentals_for_customer];
};

struct Admin
{
	string username, password;
};
fstream index_file;
fstream my_file;
fstream my_customer_file;
fstream my_admin_file;
string check_st;
int i, j;
#define car_Array_Size 10
Car car[car_Array_Size] = {};
#define customer_array_size 10
Customer customer[customer_array_size] = {};

#define num_of_admin 6
Admin admin[num_of_admin] = {};
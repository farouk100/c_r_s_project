#pragma once
# include "variables.h"
//reading the index file 
void idx_read()
{
	index.open("index.txt", ios::in);
	index >> sti;
	i = stoi(sti);
	index.close();
}
//reading from car file
void c_read()
{
	for (int ctr = 0; ctr < i; ctr++)
	{
		f_car.open("car.txt", ios::in);
		string check;
		f_car >> check;
		if(check!="\0")
		{
		   getline (f_car,arr_car[i].type, '#');
		   getline(f_car, arr_car[i].L_P_N, '#');

		   getline(f_car, sti, '#');  arr_car[i].cost.c_hour = stoi(sti);
		   getline(f_car, sti, '#');  arr_car[i].cost.c_day = stoi(sti);
		   getline(f_car, sti, '#');  arr_car[i].cost.c_week = stoi(sti);
		   getline(f_car, sti, '#');  arr_car[i].statue = stoi(sti);

		   getline(f_car, arr_car[i].cr_branch, '#');

		   getline(f_car, sti, '#');  arr_car[i].date.s_day = stoi(sti);
		   getline(f_car, sti, '#');  arr_car[i].date.s_month = stoi(sti);
		   getline(f_car, sti, '#');  arr_car[i].date.s_year = stoi(sti);
		   getline(f_car, sti, '#');  arr_car[i].date.e_day = stoi(sti);
		   getline(f_car, sti, '#');  arr_car[i].date.e_month = stoi(sti);
		   getline(f_car, sti, '#');  arr_car[i].date.e_year = stoi(sti);

		   getline(f_car, arr_car[i].rtn_branch);

		  
		   
		   
		}
		f_car.close();
	}
}
// Function of adding new car 
void add_car()
{
	string choice;
	do
	{
		cout << "******************************************\n";
		cout << "enter type of the car  :   ";
		cin >> arr_car[i].type;
		cout << "\nenter the licence plat number              :    ";
		cin >> arr_car[i].L_P_N;
		cout << "enter the cost off hiring  for an hour       :    ";
		cin >> arr_car[i].cost.c_hour;
		cout << "\nenter the cost of hiring for a day         :    ";
		cin >> arr_car[i].cost.c_day;
		cout << "\nenter the cost of hiring for a week        :    ";
		cin >> arr_car[i].cost.c_week;
		cout << "\nis the car frree or not ? (1/0)            :    ";
		cin >> arr_car[i].statue;
		if (arr_car[i].statue == 0)
		{
			cout << "\nenter the start day of hiring          :    ";
			cin>>arr_car[i].date.s_day;
			cout << "\nenter the start month of hiring        :    ";
			cin>>arr_car[i].date.s_month;
			cout << "\nenter the start year of the hiring     :    ";
			cin>>arr_car[i].date.s_year;
			cout << "\nenter the end day of hiring            :    ";
			cin>>arr_car[i].date.e_day;
			cout << "\nenter the end month of hiring          :    ";
			cin>>arr_car[i].date.e_month;
			cout << "\nenter the end year of the hiring       :    ";
			cin>>arr_car[i].date.e_year;
			cout << "enter the branch of return the car       :    ";
			cin >> arr_car[i].rtn_branch;
			i++;
		}
		else
		{
			cout << "\nenter the cuurent branch               :    ";
			cin >> arr_car->cr_branch;
			i++;
		}
		cout << "do you want to add new car ? (y/n)           :    ";
		cin >> choice;
	} while (choice == "y" || choice == "Y");
}
//the function of writing in the file of the cars 
void c_write()
{
	f_car.open("car.txt" ,ios::out);
	for (int ctr = 0; ctr < i; ctr++)
	{
		f_car << arr_car[i].type << "#" << arr_car[i].L_P_N << "#" << arr_car[i].cost.c_hour << "#" << arr_car[i].cost.c_day << "#" << arr_car[i].cost.c_week << "#" << arr_car[i].statue<<"#"<< arr_car[i].cr_branch << "#" << arr_car[i].date.s_day << "#" << arr_car[i].date.s_month << "#" << arr_car[i].date.s_year << "#"
			<< arr_car[i].date.e_day << "#" << arr_car[i].date.e_month << "#" << arr_car[i].date.e_year << "#" << arr_car[i].rtn_branch<<endl;
	}
	f_car.close();
}
// wiritn in the index file 
void idx_write()
{
	index.open("index.txt", ios::out);
		index << i;
		index.close();
}
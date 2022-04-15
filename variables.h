#pragma once
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
#define arr_siz 100 ;
//structs 
//structs of car
struct  cst
{
	int c_hour, c_day, c_week;
};
struct  dat
{
	int s_day, s_month, s_year, e_day, e_month, e_year;
};
struct cars
{
	string type, L_P_N, cr_branch, rtn_branch;
	bool statue;
	dat date;
	cst cost;

}car;
//arrays of struct
cars arr_car[100]={};
//files
fstream f_car ,index;
int i, j;
string sti;
#include"Functions.h"
int main()
{
//calling the functions of reading from files
	void idx_read();
	void c_read();
	string choice, num;
	do
	{
		
		cout << "*************** Add New Car*******************\n ";
		cout << " if you want to add new car enter 1  :  ";
		cin >> num;
		if (num == "1")
			 add_car();
		cout << " do you want to continue ? (y/n)   :   ";
		cin >> choice;
		
	} while (choice == "y" || choice == "Y");
	void c_write();
	void idx_write();
	cout << arr_car[0].type << " h " << arr_car[1].rtn_branch<<" h ";
//calling the function of writing on  files
	
}
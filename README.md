# CIS22B-project

#include <iostream>
#include <string>
#include "Report.h"
using namespace std;

int main()
{
	Report testing;
	int decide = 0;
	cout << "enter the number of the report you would like? \n" << "1.list of all books	2.Inventory whole sale value\n3.Inventory Retail Value	4.List by Quantity\n5.List by Cost	6.List by Age	7.to exit \n";
	cin >> decide;
	while (decide != 7)
	{
		if (decide == 1){
			testing.getList();
			decide = 0;
			cout << "enter the number of the enxt report you want \n" << "1.list of all books	2.Inventory whole sale value\n3.Inventory Retail Value	4.List by Quantity\n5.List by Cost	6.List by Age	7.to exit \n";
			cin >> decide;
		}
		if (decide == 2){
			cout << testing.getWholeSaleValue() << endl;
			decide = 0;
			cout << "enter the number of the enxt report you want \n" << "1.list of all books	2.Inventory whole sale value\n3.Inventory Retail Value	4.List by Quantity\n5.List by Cost	6.List by Age	7.to exit \n";
			cin >> decide;
		}
		if (decide == 3){
			cout << testing.getRetailValue();
			decide = 0;
			cout << "enter the number of the enxt report you want \n" << "1.list of all books	2.Inventory whole sale value\n3.Inventory Retail Value	4.List by Quantity\n5.List by Cost	6.List by Age	7.to exit \n";
			cin >> decide;
		}
		if (decide == 4){
			testing.sortQuan();
			decide = 0;
			cout << "enter the number of the enxt report you want \n" << "1.list of all books	2.Inventory whole sale value\n3.Inventory Retail Value	4.List by Quantity\n5.List by Cost	6.List by Age	7.to exit \n";
			cin >> decide;
		}
		if (decide == 5){
			testing.sortCost();
			decide = 0;
			cout << "enter the number of the enxt report you want \n" << "1.list of all books	2.Inventory whole sale value\n3.Inventory Retail Value	4.List by Quantity\n5.List by Cost	6.List by Age	7.to exit \n";
			cin >> decide;
		}
		if (decide == 6){
			testing.sortAge();
			decide = 0;
			cout << "enter the number of the enxt report you want \n" << "1.list of all books	2.Inventory whole sale value\n3.Inventory Retail Value	4.List by Quantity\n5.List by Cost	6.List by Age	7.to exit \n";
			cin >> decide;
		}
	}
	return 0;

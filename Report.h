
#pragma once

#ifndef Report_H
#define Report_H

#include <string>
#include <fstream>

class Report
{
	
	struct Inven
	{
		std::string isbn, title, author, publisher, date;
		double wholeC, retailP;
		int quantity;
	};
	double wholeV, retailV;					//all of whole sale and all of retail
	int amount;
	std::string useless[8];
	//the total number of books
	//int //we need an array to hold the sorted values for quantity, age and date
	Inven sample[25];
public:
	Report();
	void sortByQuan(Inven array[], int max);
	void sortByPrice(Inven array[], int max);
	int compareDate(std::string a, std::string b);
	void sortByDate(Inven array[], int max);
	void getList();
	void setWholeSaleValue();
	double getWholeSaleValue();
	void setRetailValue();
	double getRetailValue();
	void sortQuan();
	void sortCost();
	void sortAge();
	~Report();
};

#endif

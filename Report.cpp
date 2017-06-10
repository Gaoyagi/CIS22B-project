#include "Report.h"
#include <iostream>
#include <fstream>
#include <string>

std::ifstream test;


Report::Report()
{
	test.open("test.txt");

	std::string stfd;
	getline(test, stfd);
	for (int g = 0; g < 25; g++)
	{
		test >> sample[g].isbn >> sample[g].title >> sample[g].author >> sample[g].publisher >> sample[g].date >> sample[g].quantity >> sample[g].wholeC >> sample[g].retailP;
		//parsing the file and initalizing the structs variables to the file's values
	}	
}

void Report::getList()		//returns the full list of book details
{
	std::cout << "ISBN\tTitle\tAuthor	Publisher	Date		Quantity	Whole Sale Cost	Retail Price" << std::endl;
	for (int x = 0; x < 25; x++)
	{
		std::cout << sample[x].isbn << "	" << sample[x].title << "	" << sample[x].author << "	" << sample[x].publisher << "		" 
			<< sample[x].date << "	" << sample[x].quantity << "		" << sample[x].wholeC << "		" << sample[x].retailP << "		" << std::endl;
	}
}
void Report::setWholeSaleValue()		//adds the value of all the whole sale costs added together
{
	wholeV = 0;
	for (int y = 0; y < 25; y++)
	{
		std::cout << sample[y].title << "	" << "$" << sample[y].wholeC << std::endl;
		wholeV += sample[y].wholeC;
	}
}
double Report::getWholeSaleValue()		// returns a list of all the whole sale cost
{
	setWholeSaleValue();
	std::cout << "the total wholesale value is $";
	return wholeV;
}
void Report::setRetailValue()			//returns the value of all the retail values added up
{
	for (int y = 0; y < 25; y++)
	{
		std::cout << sample[y].title << "	" << "$" << sample[y].retailP << std::endl;
		retailV += sample[y].retailP;
	}
}
double Report::getRetailValue()		//returns a list of all the retail values
{
	setRetailValue();
	std::cout << "the total retail value is $";
	return retailV;
}
void Report::sortQuan()		//prints out the list of all the sorted quantitys
{
	Inven alpha[25];
	for (int g = 0; g < 25; g++)
	{
		alpha[g] = sample[g];
	}
	sortByQuan(alpha, 25);
	for (int i = 0; i < 25; i++)
	{
		std::cout << alpha[i].quantity << " of " << alpha[i].title << std::endl;
	}
}

void Report::sortByQuan(Inven array[], int max)			//sorts all the books by quantitys
{
	for (int x = 0; x < max; x++)
	{
	
		double min = array[x].quantity;
		int index = x;
		for (int y = x; y < max; y++)
		{
			if (array[y].quantity < min)
			{
				min = array[y].quantity;
				index = y;
			}
		}
		Inven temp = array[x];
		array[x] = array[index];
		array[index] = temp;
	}
}

void Report::sortCost()							//prints out all the sorted whole sale prices
{
	Inven beta[25];
	for (int g = 0; g < 25; g++)
	{
		beta[g] = sample[g];
	}
	sortByPrice(beta, 25);
	for (int i = 0; i < 25; i++)
	{
		std::cout << beta[i].title << " $" <<beta[i].wholeC << std::endl;
	}
}
void Report::sortByPrice(Inven array[], int max)		//sorts all the books by whole sale price
{
	for (int x = 0; x < max; x++)
	{
		double min = array[x].wholeC;
		int index = x;
		for (int y = x; y < max; y++)
		{
			if (array[y].wholeC < min)
			{
				min = array[y].wholeC;
				index = y;
			}
		}
		Inven temp = array[x];
		array[x] = array[index];
		array[index] = temp;
	}
}

int Report::compareDate(std::string a, std::string b)		//compares 2 years then if the 2nd is bigger than the 1st it compares the 2 months, if the 2nd month is bigger than the first, it compares the 2 days
{
	std::string aYear = a.substr(7, 4);						//mm/dd/yyyy
	std::string aMonth = a.substr(2);
	std::string aDay = a.substr(4, 2);
	std::string bYear = b.substr(7, 4);
	std::string bMonth = b.substr(2);
	std::string bDay = b.substr(4, 2);
	if (aYear < bYear)
	{
		return 1;
	}
	else if (bYear < aYear)
	{
		return -1;
	}
	else
	{
		if (aMonth < bMonth)
		{
			return 1;
		}
		else if (bMonth < aMonth)
		{
			return -1;
		}
		else
		{
			if (aDay < bDay)
			{
				return 1;
			}
			else if (bDay < aDay)
			{
				return -1;
			}
		}
	}
	return 0;
}


void Report::sortByDate(Inven array[], int max)		//sorts the dates using the compareDate
{
	for (int x = 0; x < max; x++)
	{
		std::string curr = array[x].date;
		int index = x; 
		for (int y = x+1; y < max; y++)
		{
			if(compareDate(curr, array[y].date) == -1)
			{
				curr = array[y].date;
				index = y;
			}
		}
		Inven temp = array[x];
		array[x] = array[index];
		array[index] = temp;
	}
}
void Report::sortAge()			//prints out all the sorted books by age in inventory
{
	Inven omega[25];
	for (int g = 0; g < 25; g++)
	{
		omega[g] = sample[g];
	}
	sortByDate(omega, 25);
	for (int i = 0; i < 25; i++)
	{
		std::cout << omega[i].title << " purchased on " << omega[i].date << std::endl;
	}

}


Report::~Report()
{
}

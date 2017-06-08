#include "Report.h"
#include <iostream>
#include <fstream>
#include <string>

Inven sample[10];	//10 will later bechanged to amount variable
std::ifstream test("test.txt");
Report::Report()
{
	test >> sample.isbn >> sample.title >> sample.author >> sample.publisher >> sample.date >> sample.quantity >> sample.wholeC >> sample.retailP;
	//parsing the file and initalizing the structs variables to the file's values
}

void Report::sort(int a[], int size)					//next 2 is the selection sort we need for the getQuan,Cost, Age
{
	int minIndex;
	for (int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(a[i], a[minIndex]);
		}
		std::cout << "$" << minIndex << endl;
	}
}

void Report::swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void Report::getList()
{
	for (int x = 0; x < 10; x++)
	{
		std::cout << sample.isbn << sample.title << sample.author << sample.publisher << sample.date << sample.quantity << sample.wholeC << sample.retailP;
	}
}
void Report::setWholeSaleValue()
{
	for (int y = 0; y < 10; y++)
	{
		wholeV += sample[y].wholeC;
	}
}
double Report::getWholeSaleValue()
{
	return wholeV;
}
void Report::setRetailValue()
{
	for (int y = 0; y < 10; y++)
	{
		retailV += sample[y].retailC;
	}
}
double Report::getRtailValue()
{
	return retailV;
}
void Report::sortQuan()
{
	sort(sample[].quantity, 10);

}
void Report::sortCost()
{
	sort(sample[].Cost, 10);
}
void Report::sortAge()
{
	sort(sample[].Age, 10);
}


Report::~Report()
{
}


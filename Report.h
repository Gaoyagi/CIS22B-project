
#define Report_H

#include <string>
#include <fstream>

class Report
{
	struct Inven
	{
		std::string isbn, title, author, publisher, date, quantity;
		double wholeC, retailP;
	};
	double wholeV, retailV;					//all of whole sale and all of retail
	int amount;								//the total number of books
public:
	Report();
	void getList();
	void setWholeSaleValue();
	double getWholeSaleValue();
	void setRetailValue();
	double getRtailValue();
	void sortQuan();
	void sortCost();
	void sortAge();
	~Report();
};

#endif

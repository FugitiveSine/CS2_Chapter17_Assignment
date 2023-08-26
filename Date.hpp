/*
 * Date.hpp
 *
 *  Created on: Apr 15, 2023
 *      Author: henry
 */

#ifndef DATE_HPP_
#define DATE_HPP_
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Date {
public:
	Date();
	virtual ~Date();
	int getDay();
	int getMonth();
	int getYear();

		void setDay(int aDay);
		void setMonth(int aMonth);
		void setYear(int aYear);
		int numOfDays();
		string getDate();




private:
	int day;
	int month;
	int year;
};


#endif /* DATE_HPP_ */

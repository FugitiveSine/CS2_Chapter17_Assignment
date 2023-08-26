/*
 * Date.cpp
 *
 *  Created on: Apr 15, 2023
 *      Author: henry
 */

#include "Date.hpp"

Date::Date() {
	// TODO Auto-generated constructor stub
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}
int Date::getDay(){
return this->day;
}
int Date::getMonth(){
return this->month;
}
int Date::getYear(){
return this->year;
}

void Date::setDay(int aDay){
if(aDay < 1 || aDay > numOfDays()){
	throw "Day must be 1 to the max number of days in that month";
}else if(aDay >= 1 && aDay <= numOfDays() ){
	this->day = aDay;
}
}

void Date::setMonth(int aMonth){
if(aMonth < 1 || aMonth > 12){
	throw "Month has to be 1-12";
}else{
	this->month = aMonth;
}
}

void Date::setYear(int aYear){
if(aYear < 1 || aYear > 9999){
	throw "Year must be 1-9999";
}else{
	this->year = aYear;
}

}

int Date::numOfDays(){//when called returns the number of days in the set month
	int arrayDays[12];
	arrayDays[0] = 31;
	arrayDays[1] = 29;
	arrayDays[2] = 31;
	arrayDays[3] = 30;
	arrayDays[4] = 31;
	arrayDays[5] = 30;
	arrayDays[6] = 31;
	arrayDays[7] = 31;
	arrayDays[8] = 30;
	arrayDays[9] = 31;
	arrayDays[10] = 30;
	arrayDays[11] = 31;
	return arrayDays[this->month - 1];
}
string Date::getDate(){
			int year = this->year;
			int month = this->month;
			int day = this->day;
			stringstream sy;
			stringstream sm;
			stringstream sd;
			sy << year;
			sm << month;
			sd << day;
			string str = sm.str() + "/" + sd.str() + "/" + sy.str();
			return str;
		}


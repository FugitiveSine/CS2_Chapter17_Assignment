/*
 * SMUser.cpp
 *
 *  Created on: May 15, 2023
 *      Author: henry
 */

#include "SMUser.hpp"

SMUser::SMUser() {
	this->userFirstName = "Unkown";
	this->userLastName = "Unkown";
	this->userID = "Unkown";

}

SMUser::~SMUser() {
	// TODO Auto-generated destructor stub
}

string SMUser::getDateOfMembership() {

	return getDate();
}

void SMUser::setDateOfMembership(int year, int month, int day) {
	this->setYear(year);
	this->setMonth(month);
	this->setDay(day);
}

const std::string& SMUser::getUserFirstName() const {
	return userFirstName;
}

void SMUser::setUserFirstName(const std::string &userFirstName) {
	if(userFirstName == ""){
		throw "First name must not be blank";
	}else{
		this->userFirstName = userFirstName;
	}

}

std::string SMUser::getUserId() {
	return this->userID;
}

void SMUser::setUserId(std::string userId) {
	if(userId == ""){
		throw "User ID must not be blank";
	}else{
		this->userID = userId;
	}

}

const std::string& SMUser::getUserLastName() const {
	return userLastName;
}

void SMUser::setUserLastName(const std::string &userLastName) {
	if(userLastName == ""){
			throw "Last name must not be blank";
		}else{
			this->userLastName = userLastName;
		}

}

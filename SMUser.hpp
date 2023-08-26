/*
 * SMUser.hpp
 *
 *  Created on: May 15, 2023
 *      Author: henry
 */

#ifndef SMUSER_HPP_
#define SMUSER_HPP_
#include "Date.hpp"
#include <vector>

class SMUser : public Date {
public:
	SMUser();
	virtual ~SMUser();
	string getDateOfMembership();
	void setDateOfMembership(int year, int month, int day);
	const std::string& getUserFirstName() const;
	void setUserFirstName(const std::string &userFirstName);
	std::string getUserId();
	void setUserId(std::string userId);
	const std::string& getUserLastName() const;
	void setUserLastName(const std::string &userLastName);
	string getUserName(){
		return (this->userFirstName + this->userLastName);
	}


private:
	std::string userID;
	std::string userFirstName;
	std::string userLastName;
	Date dateOfMembership;
};


#endif /* SMUSER_HPP_ */

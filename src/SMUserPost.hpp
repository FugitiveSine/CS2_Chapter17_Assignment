/*
 * SMUserPost.hpp
 *
 *  Created on: May 15, 2023
 *      Author: henry
 */

#ifndef SMUSERPOST_HPP_
#define SMUSERPOST_HPP_
#include "Date.hpp"

class SMUserPost : public Date{
public:
	SMUserPost();
	virtual ~SMUserPost();
	string getDateOfPost(void);
	void setDateOfPost(int year, int month, int day);
	int getHour() const;
	void setHour(int hour);
	int getMinute() const;
	void setMinute(int minute);
	const string& getPostText() const;
	void setPostText(const string &postText);
	int getSecond() const;
	void setSecond(int second);
	string getUserId() const;
	void setUserId(std::string userId);
	string getTime();


private:
	std::string userID;
	Date dateOfPost;
	struct PostTime{
		int hour;
		int minute;
		int second;
	};
	PostTime time;
	std::string postText;
};


#endif /* SMUSERPOST_HPP_ */

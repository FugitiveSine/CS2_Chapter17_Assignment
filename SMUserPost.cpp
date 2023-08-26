/*
 * SMUserPost.cpp
 *
 *  Created on: May 15, 2023
 *      Author: henry
 */

#include "SMUserPost.hpp"

SMUserPost::SMUserPost() {
	this->postText = "";
	this->time.hour = 0;
	this->time.minute = 0;
	this->time.second = 0;
	this->userID = "Unkown";

}

SMUserPost::~SMUserPost() {
	// TODO Auto-generated destructor stub
}

string SMUserPost::getDateOfPost(void) {
	return this->dateOfPost.getDate();
}

void SMUserPost::setDateOfPost(int year, int month, int day) {
	this->dateOfPost.setYear(year);
	this->dateOfPost.setMonth(month);
	this->dateOfPost.setDay(day);

}

int SMUserPost::getHour() const {
	return this->time.hour;
}

void SMUserPost::setHour(int hour) {
	if(hour >= 0 && hour <= 24){
			this->time.hour = hour;
		}else{
			throw "Hour must be between 0 and 24";
		}
}

int SMUserPost::getMinute() const {
	return this->time.minute;
}

void SMUserPost::setMinute(int minute) {
	if(minute >= 0 && minute <= 60){
			this->time.minute = minute;
		}else{
			throw "Minute must be between 0 and 60";
		}
}

const std::string& SMUserPost::getPostText() const {
	return postText;
}

void SMUserPost::setPostText(const std::string &postText) {
	if(postText != ""){
		this->postText = postText;
	}else{
		throw "Post text must not be empty";
	}


}

int SMUserPost::getSecond() const {
	return this->time.second;
}

void SMUserPost::setSecond(int second) {
	if(second >= 0 && second <= 60){
		this->time.second = second;
	}else{
		throw "Second must be between 0 and 60";
	}

}

std::string SMUserPost::getUserId()const {
	return this->userID;
}

void SMUserPost::setUserId(std::string userId) {
	if(userId != ""){
		this->userID = userId;
	}else{
		throw "User ID cannot be blank";
	}

}
string SMUserPost::getTime(){
	int hour = this->time.hour;
	int minute = this->time.minute;
	int second = this->time.second;
	stringstream sh;
	stringstream sm;
	stringstream ss;
	sh << hour;
	sm << minute;
	ss << second;
	string str = sh.str() + ":" + sm.str() + ":" + ss.str();
	return str;
}

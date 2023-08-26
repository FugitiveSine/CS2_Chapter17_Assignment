//============================================================================
// Name        : HenryT_FinalExamProject_Chapter17.cpp
// Author      : Henry Timmons
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "SMUser.hpp"
#include "SMUserPost.hpp"
#include "sstream"
#include "fstream"
#include <map>
#include <utility>
#include <climits>
#include <iomanip>
void clearCin(void){
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
ostream& operator<<(ostream& stream, Date& aDate){
			stream << aDate.getMonth() << "/" << aDate.getDay() << "/" << aDate.getYear();
			return stream;
}


int main() {
	map<string, SMUser*> userMap;
	map<string, SMUser*>::iterator userIT;
	multimap<string, SMUserPost*> userPost;
	multimap<string, SMUserPost*>::iterator userPostIT;
	SMUser userClass;
	SMUserPost postClass;
	string fileName;
	ifstream inputFile;
	ifstream inputFilePost;
	ifstream inputFileUserErrors;
	ifstream inputFilePostErrors;
	ofstream outputFile;
	ofstream outputPostFile;
	string inputRecord, inputRecord2;
	string userIDSearch, stringErrorMsg;
	string stringUserID, stringFirstName, stringLastName, stringYear, stringMonth, stringDay, stringHour, stringMinute, stringSecond, stringPostText;
	int menuOption = 0;

	cout << "Welcome to the social media network!" << endl;
	cout << "Please enter the name of the user file to read: ";
	getline(cin, fileName);

inputFile.open(fileName);
outputFile.open("UserErrors.txt");
outputPostFile.open("PostErrors.txt");

	if(inputFile.fail()){
		cout << "Input File open failed" << endl;
		return 0;
	}
	while(!inputFile.eof()){


		getline(inputFile, inputRecord);
		stringstream inputStream(inputRecord);
		getline(inputStream, stringUserID, ',');
		getline(inputStream, stringLastName, ',');
		getline(inputStream, stringFirstName, ',');
		getline(inputStream, stringYear, ',');
		getline(inputStream, stringMonth, ',');
		getline(inputStream, stringDay, ',');


			if(userMap.count(stringUserID) != 0){
				outputFile << stringUserID << ", " << stringLastName << ", " << stringFirstName << ", " <<
						 stringYear << ", " << stringMonth << ", " << stringDay << ", " << "*Error, key duplicate:[ " << endl;

			}else{
			try {
				//SMUsers
				userClass.setUserFirstName(stringFirstName);
				userClass.setUserLastName(stringLastName);
				userClass.setUserId(stringUserID);
				userClass.setDateOfMembership(stoi(stringYear),stoi(stringMonth), stoi(stringDay));

				userMap.insert(pair<string, SMUser*>(stringUserID, new SMUser(userClass)));

			} catch (char const *&e) {
				outputFile << stringUserID << ", " << stringLastName << ", " << stringFirstName << ", " <<
				stringYear << ", " << stringMonth << ", " << stringDay << ", " << "*Error, " << e << ":[ " << endl;
			}//catch

			}//else

	}

	//USER POSTS READ
	cout << "Please enter the name of the user posts file to read: ";
	getline(cin, fileName);
	inputFilePost.open(fileName);
	if(inputFilePost.fail()){
		cout << "**Error opening user posts file" << endl;
		return 0;
	}else{
		while(!inputFilePost.eof()){


				getline(inputFilePost, inputRecord2);
				stringstream inputStream(inputRecord2);
				getline(inputStream, stringUserID, ',');
				getline(inputStream, stringYear, ',');
				getline(inputStream, stringMonth, ',');
				getline(inputStream, stringDay, ',');

				getline(inputStream, stringHour, ',');
				getline(inputStream, stringMinute, ',');
				getline(inputStream, stringSecond, ',');
				getline(inputStream, stringPostText, ',');


					if(userMap.count(stringUserID) == 0){
						outputPostFile << stringUserID << ", " << stringYear << ", " << stringMonth << ", " <<
						stringDay << ", " << stringHour << ", " << stringMinute << ", " << stringSecond << ", " << stringPostText << ", " << "*Error, post has no valid user:[ " << endl;

					}else{
					try {
						//SMUserPost

						postClass.setUserId(stringUserID);
						postClass.setDateOfPost(stoi(stringYear), stoi(stringMonth), stoi(stringDay));

						postClass.setHour(stoi(stringHour));
						postClass.setMinute(stoi(stringMinute));
						postClass.setSecond(stoi(stringSecond));
						postClass.setPostText(stringPostText);


						userPost.insert(pair<string, SMUserPost*>(stringUserID, new SMUserPost(postClass)));

					} catch (char const *&e) {
						outputPostFile << stringUserID << ", " << stringYear << ", " << stringMonth << ", " <<
						stringDay << ", " << stringHour << ", " << stringMinute << ", " << stringSecond << ", " << stringPostText << ", " << "*Error, " << e << ":[ " << endl;
					}//catch


					}//else

			}//while


	}//else


	while(menuOption != 5){
		cout << "\nMain Menu" << endl;
			cout << "=========" << endl;
			cout <<"1. Display all users" << endl;
			cout <<"2. Display a specific user" << endl;
			cout <<"3. Display all posts" << endl;
			cout <<"4. Display posts from a specific user" << endl;
			cout <<"5. Exit the program" << endl;
			cin >> menuOption;
			clearCin();
			switch(menuOption){
			case 1:
				cout << left << setw(10) << "UserID" << setw(27) << "User Name (first, last)" << setw(22) << "Date of Membership" << setw(25) << "Number of Posts" << endl;
				cout << left << setw(10) << "======" << setw(27) << "=======================" << setw(22) << "==================" << setw(25) << "===============" << endl;
				for(const auto& i : userMap){
						cout << left << setw(9) << i.second->getUserId() << setw(28) << i.second->getUserName() << setw(22)  << i.second->getDateOfMembership() << userPost.count(i.second->getUserId()) << endl;

				}
				break;

			case 2:
				cout << "Please enter the user that you would like to display:";
				getline(cin, userIDSearch);
				if(userMap.count(userIDSearch) != 0){
					cout << left << setw(10) << "UserID" << setw(27) << "User Name (first, last)" << setw(22) << "Date of Membership" << setw(25) << "Number of Posts" << endl;
					cout << left << setw(10) << "======" << setw(27) << "=======================" << setw(22) << "==================" << setw(25) << "===============" << endl;
					auto range = userMap.equal_range(userIDSearch);
					for(userIT = range.first; userIT != range.second; userIT++){
						cout << left << setw(9) << (*userIT).second->getUserId() << setw(28) << (*userIT).second->getUserName() << setw(22) << (*userIT).second->getDateOfMembership() << userPost.count(userIDSearch) << endl;
					}

				}else{
					cout << "**Error could not find that user please try again" << endl;
				}

				break;

			case 3:
				cout << left << setw(10) << "UserID" << setw(16) << "Date of Post" << setw(16) << "Time of Post" << "Post Text" << endl;
				cout << left << setw(10) << "======" << setw(16) << "============" << setw(16) <<"============" << "=========" << endl;
			for (const auto &i : userPost ) {
				userPostIT = userPost.find(i.second->getUserId());
				if((*userPostIT).second->getPostText() != " "){
					cout << left << setw(10) << i.second->getUserId()<< setw(16) << i.second->getDateOfPost()<< setw(16) << i.second->getTime()<< setw(12) << i.second->getPostText() << endl;
				}else{}

			}

				break;

			case 4:
			cout << "Please enter the user that you would like to display:";
			getline(cin, userIDSearch);
			if (userPost.count(userIDSearch) != 0) {

				auto range = userPost.equal_range(userIDSearch);
				userIT = userMap.find(userIDSearch);
				userPostIT = userPost.find(userIDSearch);
				if((*userPostIT).second->getPostText() == " "){
					cout << "No Posts Found" << endl;
				}else{
					cout << left << setw(10) << "UserID" << setw(27)
							<< "User Name (first, last)" << setw(27)
							<< "Total Number of Posts" << endl;
					cout << left << setw(10) << "======" << setw(27)
							<< "=======================" << setw(27)
							<< "=====================" << endl;

					cout << left << setw(9) << (*userPostIT).second->getUserId()
							<< setw(28) << (*userIT).second->getUserName()
							<< setw(22) << userPost.count(userIDSearch) << endl;
					cout << left << setw(15) << "Date Posted" << setw(100)
							<< "Posts" << endl;
					cout << left << setw(15) << "===========" << setw(100)
							<< "=====" << endl;
					for (userPostIT = range.first; userPostIT != range.second;
							userPostIT++) {

						cout << left << setw(14)
								<< (*userPostIT).second->getDateOfPost()
								<< setw(100)
								<< (*userPostIT).second->getPostText() << endl;
					}
				}


			} else {
				cout << "**Error could not find that user please try again"
						<< endl;
			}

				break;

			case 5:

			for (userPostIT = userPost.begin(); userPostIT != userPost.end();userPostIT++) {
				delete userPostIT->second;

			}
			for (userIT = userMap.begin(); userIT != userMap.end();userIT++) {
				delete userIT->second;

			}

			userPost.clear();
			userMap.clear();
			//user error
			inputFileUserErrors.open("UserErrors.txt");
				if(inputFileUserErrors.fail()){
					cout << "**Error opening user error file" << endl;
					return 0;
				}else{
					cout << left << "User Error Log" << endl;
					cout << left << "==============" << endl;
					while(!inputFileUserErrors.eof()){


							getline(inputFileUserErrors, inputRecord2);
							stringstream inputStream(inputRecord2);

							getline(inputStream, stringUserID, ',');
							getline(inputStream, stringFirstName, '*');
							getline(inputStream, stringErrorMsg, '[');
							if(stringUserID == "")continue;

						cout << stringErrorMsg << stringUserID << endl;
					}//while
				}//else
				//post error
				inputFilePostErrors.open("PostErrors.txt");
					if(inputFilePostErrors.fail()){
						cout << "**Error opening post error file" << endl;
						return 0;
					}else{
						cout << left << "Post Error Log" << endl;
						cout << left << "==============" << endl;
						while(!inputFilePostErrors.eof()){
								getline(inputFilePostErrors, inputRecord2);
								stringstream inputStream(inputRecord2);

								getline(inputStream, stringUserID, ',');
								getline(inputStream, stringFirstName, '*');
								getline(inputStream, stringErrorMsg, '[');
								if(stringUserID == "")continue;

							cout << stringErrorMsg << stringUserID << endl;
						}//while
					}//else

				break;

			default :
				cout << "**Error invalid menu option please try again" << endl;
				break;


			}//switch
	}//while


	inputFile.close();
	inputFilePost.close();
	inputFileUserErrors.close();
	inputFilePostErrors.close();
	outputFile.close();
	outputPostFile.close();
	cout << "Program ending, have a nice day!" << endl; // prints Program ending, have a nice day!
	return 0;
}//main


#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <list>

class User;
class USocial {
private:
	std::map<unsigned long, User*> users;

public:
	~USocial();
	User* registerUser(std::string, bool checkUser = false);
	void removeUser(User*);
	User* getUserById(unsigned long);
	unsigned long getAvailableID();
};

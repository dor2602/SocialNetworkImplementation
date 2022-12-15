#include "USocial.h"
#include "User.h"

//find available id for new user in the socail media
unsigned long USocial::getAvailableID() {
	unsigned long found_id = 0;
	while (1) {
		if (!users.count(found_id)) {
			/* It means that we've found an unused id */
			return found_id;
		}
		found_id += 1;
	}
}

//register a new user to the socail media
User* USocial::registerUser(std::string name, bool checkUser) {
	User* newUser;
	unsigned long newId = getAvailableID();
	if (checkUser) newUser = new BusinessUser();
	else newUser = new User();

	//configure user
	newUser->us = this;
	newUser->name = name;
	newUser->id = newId;

	//add user to list
	users[newId] = newUser;

	return newUser;
}

//remove user from social media
void USocial::removeUser(User* user)
{
	//if user doesnt exist in the social media, logic error will be throw
	if (users.find(user->getId()) == users.end())
		throw std::logic_error("The user is not part of the social media");

	for (auto iter = users.begin(); iter != users.end(); ++iter)
	{
		if (iter->second == user)
		{
			for (auto secondIter = users.begin(); secondIter != users.end(); ++secondIter)
			{
				if (secondIter->second->friendOf(iter->second))
					secondIter->second->removeFriend(iter->second);
			}
			users.erase(iter);
			break;
		}
	}
}

//find user by id
User* USocial::getUserById(unsigned long userId) {
	/*if user not exist in the list of users in the socail media, logic error will be throw*/
	if (users.find(userId) == users.end())
		throw std::logic_error(userId + " is not a legal id in our social media");
	else
		return users[userId];
}

//USocial destructor
USocial::~USocial() {
	for (auto iter = users.begin(); iter != users.end(); ++iter)
		delete iter->second;
}
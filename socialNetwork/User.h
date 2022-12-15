#pragma once

#include "USocial.h"
#include "Post.h"
#include "Message.h"


class User {
	friend class USocial;
protected:
	USocial* us;
	unsigned long id;
	std::string name;
	std::list<unsigned long> friends;
	std::list<Post*> posts;
	std::list<Message*> receivedMsgs;

protected:
	User();
	virtual ~User();
	void _sendMessage(User* target, Message* message);

public:
	unsigned long getId() { return id; }
	std::string getName() { return name; }
	std::list<Post*> getPosts() { return posts; }
	void addFriend(User*);
	void removeFriend(User*);
	void post(std::string);
	void post(std::string, Media*);
	void viewFriendsPosts();
	void receiveMessage(Message*);
	virtual void sendMessage(User*, Message*);//virtual for the use of businessUsers
	void viewReceivedMessages();
	bool friendOf(User* checkIfFriend);
};


class BusinessUser : public User {
	friend class USocial;
protected:
	BusinessUser();

public:
	void sendMessage(User*, Message*);
};



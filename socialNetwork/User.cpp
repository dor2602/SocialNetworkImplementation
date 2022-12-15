#include "User.h"
#include "Post.h"
#include "Message.h"

//User default constructor
User::User() {}

//checks whether two people on the social media are friends of each other
bool User::friendOf(User* checkIfFriend) {
	return count(friends.begin(), friends.end(), checkIfFriend->getId());
}

//remove friend from the friend list
void User::removeFriend(User* exFriend) {

	/*If we try to delete a person who is not on the friends list, logic error will be throw*/
	if (!friendOf(exFriend))
		throw std::logic_error(exFriend->name + " is not in the friends list");

	friends.remove(exFriend->getId());
}

//add friend to the friend list
void User::addFriend(User* myFriend) {

	/*if the person is already in the friend list, logic error will be throw*/
	if (friendOf(myFriend)) {
		throw std::logic_error(myFriend->name + " is already in the friends list");
	}

	/*if the id of the person identical to my Id, logic error will be throw*/
	if (myFriend->id == id) {
		throw std::logic_error("A user cannot be a friend of himself");
	}
	friends.push_back(myFriend->id);
}

//create and add the post (without any media inside of him) to the list posts
void User::post(std::string post) {

	Post* newPost = new Post(post);
	posts.push_back(newPost);
}

//create and add the post (with media inside of him) to the list posts
void User::post(std::string post, Media* media) {
	Post* newPost = new Post(post, media);
	posts.push_back(newPost);
}

//User destructor
User::~User() {
	/* Delete own posts */
	for (auto posts_it = posts.begin(); posts_it != posts.end(); ++posts_it)
		delete* posts_it;

	/* Delete received messages */
	for (auto msgs_it = receivedMsgs.begin(); msgs_it != receivedMsgs.end(); ++msgs_it)
		delete* msgs_it;
}

//receive message from friend
void User::receiveMessage(Message* message) {
	receivedMsgs.push_back(message);
}

//view all the friends posts that uploaded to the social media
void User::viewFriendsPosts() {
	std::cout << name << " friend's posts:" << std::endl;
	User* friend_user;
	std::list<Post*> friend_posts;
	for (auto iter = friends.begin(); iter != friends.end(); ++iter) {
		friend_user = us->getUserById(*iter);
		friend_posts = friend_user->getPosts();
		for (auto second_it = friend_posts.begin(); second_it != friend_posts.end(); ++second_it) {
			std::cout << friend_user->name << " post: " << (*(*second_it));
		}
	}
	std::cout << "\n";
}

//sends a message to a user without checking wether he is in the friends list
void User::sendMessage(User* target, Message* message) {

	/*that means that we try send message to a friend that are not in our friend list, we throw logic error*/
	if (!friendOf(target)) {
		throw std::logic_error("Regular user cannot send a message to a none friend user");
	}
	_sendMessage(target, message);
}

//send message to friend without any validation
void User::_sendMessage(User* target, Message* message) {
	message->add_author(name);
	target->receiveMessage(message);
}

//view all received message of a user
void User::viewReceivedMessages() {
	std::cout << "messages of " << name << ":" << std::endl;
	for (auto iter = receivedMsgs.begin(); iter != receivedMsgs.end(); ++iter)
		std::cout << (*iter)->getText() << std::endl;
	std::cout << "\n";
}

//Business user constructor
BusinessUser::BusinessUser() {}

void BusinessUser::sendMessage(User* target, Message* message) {
	/*Business User sends Message without any validation*/
	_sendMessage(target, message);
}
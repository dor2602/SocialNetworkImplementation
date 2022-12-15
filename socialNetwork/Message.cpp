#include "Message.h"

//add author name to the message that was received
void Message::add_author(std::string author) {
	_text.insert(0, author + ": ");
}

//constructor for Message
Message::Message(std::string message) : _text(message) {}
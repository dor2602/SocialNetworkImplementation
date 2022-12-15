#pragma once
#include <iostream>

class Message {
private:
	std::string _text;

public:
	Message(std::string);
	std::string getText() { return _text; };
	void add_author(std::string author);
};

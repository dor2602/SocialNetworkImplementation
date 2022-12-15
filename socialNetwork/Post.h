#pragma once
#include "Media.h"

class Post {
private:
	std::string _text;
	Media* _media;

public:
	Post(std::string);
	Post(std::string, Media*);
	~Post();
	std::string getText() { return _text; }
	Media* getMedia() { return _media; }

	// Overloads << operation for post object
	friend std::ostream& operator << (std::ostream& os, Post& post);
};

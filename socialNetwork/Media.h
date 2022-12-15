#pragma once
#include <iostream>

class Media {
public:
	virtual void display() = 0;
};

class Photo : public Media {
public:
	void display();
};

class Audio : public Media {
public:
	void display();
};

class Video : public Media {
public:
	void display();
};

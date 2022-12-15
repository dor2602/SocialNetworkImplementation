#include "Post.h"

//Post distructor
Post::~Post() {
	/*delete media if the post exist media inside of him*/
	if (!_media)
	{
		delete _media;
		_media = nullptr;
	}
}

//Post constructor for post without media
Post::Post(std::string post) : _text(post), _media(nullptr) {}

//Post constructor for post that included media
Post::Post(std::string post, Media* media) : _text(post), _media(media) {}

/* << opearator overloading for print the post */
std::ostream& operator<<(std::ostream& os, Post& post) {
	os << post.getText();
	if (post.getMedia() != nullptr) {
		os << " [";
		post.getMedia()->display();
		os << "]\n";
	};
	return os;
}
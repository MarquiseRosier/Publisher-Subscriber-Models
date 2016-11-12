#include <note.h>

Note::Note()
{
	message = "default";
}

Note::Note(const std::string& note, const std::string& publisher)
{
	message = note;
	pub = publisher;
}

std::string Note::getNote()
{
	return message;
}

std::string Note::getPublisher()
{
	return pub;
}

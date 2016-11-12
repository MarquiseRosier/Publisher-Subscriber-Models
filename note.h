#include <string>

#ifndef _NOTE_H
#define _NOTE_H

class Note
{
public:
	Note();
	Note(const std::string& note, const std::string& publisher);
	std::string getNote();
	std::string getPublisher();
	
private:
	std::string message, pub;
};

#endif

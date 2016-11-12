#include <string>
#include <list>
#include <iostream>
#include <topic.h>

#ifndef _PUBLISHER_H
#define _PUBLISHER_H

class Publisher
{
public:
	Publisher(); 
	~Publisher(); 
	void Register(const std::string& topic);
	void Unregister(const std::string& topic);
	void Publish(const std::string&, Topic);
	/*
	Don't worry about Proper Types
	Publisher(Publisher&); 
	Publisher& operator =(const Publisher&);
	*/
private:
	friend class Topic;
	static int pubCount_; 
	static std::list<Topic> *totalTopicList;
	static std::list<Note> *noteList;
	std::list<Topic> *myTopicList;
	std::string title = "Default Name"; 
};

#endif

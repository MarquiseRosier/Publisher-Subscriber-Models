#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <note.h>
#include <topic.h>

class Subscriber
{
	public:
		Subscriber();
		~Subscriber();
		void Register(const std::string&);
		void Unregister(const std::string&);

	private:
		std::string subName;
		std::list<Topic> *subscriberTopicList; 
		std::list<Note> *subscriberPublishedNotes;

		std::list<Note>& noteUpdate();

		static int subCount_; 
		static std::vector<Subscriber> *subVec;  
		friend class Topic; 
};	

#endif

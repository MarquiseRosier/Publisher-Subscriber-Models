#ifndef _TOPIC_H
#define _TOPIC_H

#include <note.h>
#include <map>
#include <list>
#include <string>
#include <iostream>

class Topic
{
private:
//tight couplings so Publisher and Subcriber can access elements
	friend class Publisher;
	friend class Subscriber;

public:
	Topic() : topic("Default"){}
	Topic(const std::string& top) : topic(top){}
	std::string getTopic();
	void getAvailableTopics();
	bool publisher(const Topic&, std::list<Note>*);
  template <typename some>
	bool topicExists(const some&);

private:
	std::string topic;
	static std::map<Topic, std::list<Note> > *publishedNotes; 
	static std::list<Topic> topList; 
	std::list<Topic>& setTopicList(){return topList;}
	std::list<Note> getNote(const std::string&); 

public:
	friend bool operator==(const Topic& t1, const Topic& t2){
		return (t1.topic == t2.topic);
	}

	friend bool operator <(const Topic& t1, const Topic& t2){
		return (t1.topic < t2.topic);
	}
};

#endif

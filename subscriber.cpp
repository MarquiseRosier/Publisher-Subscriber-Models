#include <subscriber.h>

Subscriber::Subscriber(){
	subVec->push_back(*this);
	++subCount_; 
	subName = "Subscriber " + subCount_;
}


void Subscriber::Register(const std::string& topic)
{
	Topic top(topic); 
	if(!top.topicExists(this))
		std::cout << "You Are Already Registered To Topic" << std::endl;
	else
		subscriberTopicList->push_front(top);
}

void Subscriber::Unregister(const std::string& topic)
{
	Topic top(topic);

	for(auto i = subscriberTopicList->begin(); i != subscriberTopicList->end(); ++i)
	{
		if(top == (*i))
			subscriberTopicList->remove(top);
	}
}

std::list<Note>& Subscriber::noteUpdate()
{
	return *subscriberPublishedNotes; 
}


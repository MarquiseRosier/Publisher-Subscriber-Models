#include <topic.h>

std::string Topic::getTopic()
{
	return topic;
}

std::list<Note> Topic::getNote(const std::string& s)
{
	std::map<Topic, std::list<Note>>::iterator iter = publishedNotes->find(s);
	if(iter != publishedNotes->end())
		return (*publishedNotes)[s];
	else{
		std::list<Note> *noteList = nullptr; 
		Topic top(s);
		publishedNotes->insert(std::pair<Topic, std::list<Note>>(s,*noteList));
	}
}

/*
const Topic& Topic::createTopic(const std::string s)
{
	Topic *top = new Topic(s);
	return *top; 
}
*/

void Topic::getAvailableTopics()
{
	for(auto i = publishedNotes->begin(); i != publishedNotes->end(); ++i){
		std::cout << "TOPIC: " << (*i).first.topic << std::endl;
	}
}

bool Topic::publisher(const Topic& top, std::list<Note> *nList)
{
	auto x = publishedNotes->insert(std::pair<Topic, std::list<Note> >(top, *nList));
	return x.second;
}

template <typename some>
bool Topic::topicExists(const some& pPoint)
{
	for(auto index : topList){
		if(*this == index){
			if(pPoint != nullptr)
			pPoint->noteUpdate() = (*publishedNotes)[*this];
		}
	}
}


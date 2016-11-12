#include <publisher.h>

Publisher::Publisher()
{
	std::string name; 

	std::cout << "Please Enter A Publisher Name" << std::endl;
	std::cin >> name;

	++pubCount_;
}	

Publisher::~Publisher()
{

	/*for(auto top : *myTopicList)
	{
		for(auto i = listOfPublishers->begin(); i != listOfPublishers->end(); ++i){
			if((*i).myTopicList->find(top) == true){
				sharedTopic = true;
				break;
			}
		}
		if(sharedTopic == true)
			break;
	}
	*/
	delete myTopicList; 
	--pubCount_; 
}

void Publisher::Publish(const std::string& cont_, Topic top)
{
	Note note(cont_, title);
	noteList->push_front(note);

	if(top.publisher(top, noteList)){
		std::cout << "Your Note Has Been Published to the Topic " << top.getTopic() << std::endl;
	}
	else
		std::cout << "Your Note Was Already Published, No Plagiarism" << std::endl;
}

void Publisher::Register(const std::string& topic)
{
	Topic top(topic);
	top.getAvailableTopics();

	for(auto i : *myTopicList)
	{
		if(i == top){
			std::cout << "Topic Already Registered To This Publisher" << std::endl;
			return;
		}
	}

	myTopicList->push_front(top);
	totalTopicList->push_front(top);
	top.setTopicList() = *totalTopicList;
}

void Publisher::Unregister(const std::string& topic)
{
	Topic top(topic); 

	for(auto i : *myTopicList)
	{
		if(i == top)
		{
			myTopicList->remove(top);
			return;
		}
	}
	std::cout << "You Never Registered To this Topic My Friend" << std::endl;
}
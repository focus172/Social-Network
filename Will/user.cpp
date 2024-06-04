#include "user.h"
#include <algorithm>
#include <typeinfo>

// CONSTRUCTORS
User::User()
	: id_(0),
	name_(""),
	year_(0),
	zip_(0),
	friends_({})
{
}

User::User(int id, const std::string& name, int year, int zip, const std::set<int>& friends)
	: id_(id),
	  name_(name),
	  year_(year),
	  zip_(zip),
	  friends_(friends)
{
}

// MODIFICATION MEMBER FUNCTIONS
void User::addFriend(int id)
{
	friends_.insert(id);
}

void User::deleteFriend(int id)
{
	friends_.erase(id);
}

// ACCESSOR FUNCTIONS
int User::getId() const
{
	return id_;
}

std::string User::getName() const
{
	return name_;
}

int User::getYear() const
{
	return year_;
}

int User::getZip() const
{
	return zip_;
}

std::set<int>& User::getFriends()
{
	return friends_;
}

void User::addPost(Post* post)
{
	messages_.push_back(post);
}

std::vector<Post*> User::getPosts()
{
	return messages_;
}

std::string User::getPostsString(int howMany, bool showOnlyPublic)
{
	howMany = std::min(howMany, (int) messages_.size());
	std::string ans;
	for (int i = howMany - 1; i >= 0; --i)
	{
		Post* post = messages_[i];
		
		if (showOnlyPublic)
		{
			bool isPublic = post->getIsPublic();
			if (isPublic)
			{
				ans += post->toString();
				if (i != 0)
				{
					ans += "\n\n";
				}
			}
		}
		else
		{
			ans += post->toString();
			if (i != 0)
			{
				ans += "\n\n";
			}
		}
	}

	return ans;
}

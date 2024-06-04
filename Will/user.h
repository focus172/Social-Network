#ifndef USER_H
#define USER_H

#include "post.h"
#include <string>
#include <set>
#include <vector>

class User
{
public:
	// CONSTRUCTORS

    // pre: none
    // post: initializes a user
	User();

    // pre: id, year, zip should be nonnegative
    // post: initializes a user with specified parameters
	User(int id, const std::string& name, int year, int zip, const std::set<int>& friends);

    // ACCESSOR FUNCTIONS

    // pre: none
    // post: gets id of user
    int getId() const;

    // pre: none
    // post: gets name of user
    std::string getName() const;

    // pre: none
    // post: gets birth year of user
    int getYear() const;

    // pre: none
    // post: gets zip code of user
    int getZip() const;

    // pre: none
    // post: gets the friend of the user
    std::set<int>& getFriends();

	// MODIFICATION MEMBER FUNCTIONS

    // pre: id needs to be a valid id
    // post: adds the friend(with given id) to the friend list of user
	void addFriend(int id);

    // pre: id needs to be a valid id
    // post: deletes the friend(with given id) from the friend list of user
	void deleteFriend(int id);

    // pre: none
    // post: adds the post to the posts of the user
    void addPost(Post* post);

    // pre: none
    // post: gets all the posts of the user
    std::vector<Post*> getPosts();

    // pre: none
    // post: gets the strings containing specified number of posts, depending on private posts should be added
    std::string getPostsString(int howMany, bool showOnlyPublic);

private:
	int id_;
	std::string name_;
	int year_;
	int zip_;
	std::set<int> friends_;
	std::vector<Post*> messages_;
};
#endif

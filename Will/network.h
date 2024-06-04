#ifndef NETWORK_H
#define NETWORK_H

#include "user.h"
#include <string>
#include <vector>

class Network
{
public:
    // CONSTRUCTOR

    // pre: none
    // post: creates a network
    Network();

    // MODIFICATION MEMBER FUNCTIONS

    // pre: valid user passed in
    // post: adds the user to the network
    void addUser(User *u);

    // pre: none
    // post: creates a connection between the two users with specified names, returns -1 if any error
    int addConnection(const std::string &s1, const std::string &s2);

    // pre: none
    // post: delets existing connection between two users with given names, returns -1 if any error
    int deleteConnection(const std::string &s1, const std::string &s2);

    // pre: none
    // post: returns the id of the user when their name is specificed. returns -1 if no name found
    int getId(const std::string &name);

    // pre: fname must be formatted correctly
    // post: constructs a network based on the users txt file passed in. returns -1 if error
    int readUsers(const char *fname);

    // pre: none
    // post: writes formatted users to a specified file name. returns -1 if error
    int writeUsers(const char *fname);

    // pre: none
    // post: returns number of users in the network
    int numUsers();

    // pre: none
    // post: returns the user of specified id, or nullptr if user not found
    User *getUser(int id);

    // pre: none
    // post: returns the shortest path expressed as a vector between two users specified by their ids.
    //       returns an empty vector if no connection found
    std::vector<int> shortestPath(int from, int to);

    // pre: none
    // post: returns a vector of the path from the orginal user to a user a given distance away
    //       returns an empty vector if nothing found
    std::vector<int> distanceUser(int from, int &to, int distance);

    // pre: none
    // post: returns all ids of people who are friends of the user's friends
    std::vector<int> suggestFriends(int who, int &score);

    // pre: none
    // post: gives all the "clusters" within the network
    std::vector<std::vector<int>> groups();

    // pre: none
    // post: adds a post to the posts file and network
    void addPost(int ownerId, std::string message, int likes, bool isIncoming, std::string authorName, bool isPublic);

    // pre: none
    // post: gets a string of given amount of posts from a certain user(specified by id), and displays
    //       based on whether private posts should or shouldn't be shown
    std::string getPostsString(int ownerId, int howMany, bool showOnlyPublic);

    // pre: fname must be formatted correctly
    // post: reads from a text file and constructs connections between all posts in the network
    int readPosts(const char *fname);

    // pre: none
    // post: writes all posts in the network to a specified text file
    int writePosts(const char *fname);

    // pre: none
    // post: gets the post given an id of a user
    Post *getPost(int messageId)
    {
        for (User *user : users_)
        {
            for (Post *post : user->getPosts())
            {
                if (post->getMessageId() == messageId)
                {
                    return post;
                }
            }
        }

        return nullptr; // return null if no post with the given messageId is found
    }

private:
    std::vector<User *> users_;

    // pre: none
    // post: finds a cluster involving the given user(specified by id)
    std::vector<int> findCluster(int source, std::vector<bool> &visited);
};

#endif

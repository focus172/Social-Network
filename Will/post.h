#pragma once

#include <string>
#include <set>

class Post
{
public:
    // CONSTRUCTORS

    // pre: none
    // post: initializes a post object
    Post();

    // pre: messageId, ownerId, and likes must be nonnegative
    // post: initializes a post object with parameters
    Post(int messageId, int ownerId, std::string message, int likes);

    // ACCESSOR FUNCTIONS

    // pre: none
    // post: gets the messaged id
    int getMessageId();

    // pre: none
    // post: gets the owner id
    int getOwnerId();

    // pre: none
    // post: gets the message of the post
    std::string getMessage();

    // pre: none
    // post: gets the number of likes
    int getLikes();

    // pre: none
    // post: gets the author
    virtual std::string getAuthor();

    // pre: none
    // post: gets if private posts should be displayed
    virtual bool getIsPublic();

    // MODIFICATION MEMBER FUNCTIONS

    // pre: none
    // post: returns a message containing information about the post
    virtual std::string toString();

    // pre: none
    // post: increases number of likes by one if user hasn't already liked the post
    void like(int userId)
    {
        // Only increase likes if the user hasn't liked this post yet
        if (usersLiked_.find(userId) == usersLiked_.end())
        {
            ++likes_;
            usersLiked_.insert(userId);
        }
    }

private:
    int messageId_;
    int ownerId_;
    std::string message_;
    int likes_;
    std::set<int> usersLiked_;
};

class IncomingPost : public Post
{
public:
    // CONSTRUCTORS

    // pre: none
    // post: initializes an incomingpost object
    IncomingPost();

    // pre: messageId, ownerId, and likes must be nonnegative
    // post: initializes an incomingpost object with parameters
    IncomingPost(int messageId, int ownerId, std::string message, int likes, bool isPublic, std::string author);

    // ACCESSOR FUNCTIONS

    // pre: none
    // post: gets the author of the incoming post
    virtual std::string getAuthor();

    // pre: none
    // post: gets if incoming post should be public or not
    virtual bool getIsPublic();

    // MODIFICATION MEMBER FUNCTIONS

    // pre: none
    // post: returns a message containing information about the incoming post
    virtual std::string toString();

private:
    std::string author_;
    bool isPublic_;
};

#include "network.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

// HELPER FUNCTIONS
template <class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator intersection(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                OutputIterator result)
{
    while (first1 != last1 && first2 != last2)
    {
        if (*first1 < *first2)
        {
            ++first1;
        }
        else if (*first2 < *first1)
        {
            ++first2;
        }
        else
        {
            *result = *first1;
            ++result;
            ++first1;
            ++first2;
        }
    }

    return result;
}

// CONSTRUCTOR
Network::Network()
    : users_({})
{
}

// MODIFICATION MEMBER FUNCTIONS
void Network::addUser(User* u)
{
    users_.push_back(u);
}

int Network::addConnection(const std::string& s1, const std::string& s2)
{
    // no self assignment
    if (s1 == s2)
    {
        return -1;
    }

    // if both strings are valid (u1 and u2 are the respective users)
    int u1ID = getId(s1);
    int u2ID = getId(s2);

    if (u1ID != -1 && u2ID != -1)
    {
        User* u1 = getUser(u1ID);
        User* u2 = getUser(u2ID);

        // add friends
        u1->addFriend(u2ID);
        u2->addFriend(u1ID);

        return 0;
    }

    // else one of them is invalid and we return -1
    return -1;
}

int Network::deleteConnection(const std::string& s1, const std::string& s2)
{
    // no self assignment
    if (s1 == s2)
    {
        return -1;
    }

    // if both strings are valid (u1 and u2 are the respective users)
    int u1ID = getId(s1);
    int u2ID = getId(s2);

    if (u1ID != -1 && u2ID != -1)
    {
        User* u1 = getUser(u1ID);
        User* u2 = getUser(u2ID);

        // delete friends
        u1->deleteFriend(u2ID);
        u2->deleteFriend(u1ID);

        return 0;
    }

    // else one of them is invalid and we return -1
    return -1;
}

int Network::getId(const std::string& name)
{
    int usersSize = users_.size();
    for (int i = 0; i < usersSize; ++i)
    {
        if (users_[i]->getName() == name)
        {
            return users_[i]->getId();
        }
    }

    return -1;
}

int Network::readUsers(const char* fname)
{
    std::ifstream inFile;
    inFile.open(fname);

    if (!inFile.is_open())
    {
        return -1;
    }

    // read the first line and convert to integer
    std::string line;
    std::getline(inFile, line);
    int numIterations = std::stoi(line);

    for (int i = 0; i < numIterations; ++i)
    {
        // read id
        std::getline(inFile, line);
        int id = std::stoi(line);

        // read name, skip leading whitespace
        std::getline(inFile >> std::ws, line);
        std::string name = line;

        // read birth year
        std::getline(inFile >> std::ws, line);
        int birthYear = std::stoi(line);

        // read zip code
        std::getline(inFile >> std::ws, line);
        int zipCode = std::stoi(line);

        // read friends, separate by delimiter " "
        std::set<int> friends;
        std::getline(inFile, line);
        char* token = strtok(const_cast<char*>(line.c_str()), " \t");
        while (token != nullptr)
        {
            friends.insert(std::stoi(token));
            token = strtok(nullptr, " ");
        }

        // define new user and push into users_
        User* u = new User(id, name, birthYear, zipCode, friends);
        users_.push_back(u);
    }

    return 0;
}

int Network::writeUsers(const char* fname)
{
    // make file stuff
    std::ofstream outFile(fname);

    if (!outFile.is_open())
    {
        return -1;
    }

    // write the number of users to file
    int usersSize = users_.size();
    outFile << usersSize << "\n";

    // iterate through users_
    for (int i = 0; i < usersSize; ++i)
    {
        outFile << users_[i]->getId() << "\n";
        outFile << "\t" << users_[i]->getName() << "\n";
        outFile << "\t" << users_[i]->getYear() << "\n";
        outFile << "\t" << users_[i]->getZip() << "\n";

        // iterate through friends
        outFile << "\t";
        std::set<int> friends = users_[i]->getFriends();
        for (auto itr = friends.begin(); itr != friends.end(); ++itr)
        {
            outFile << *itr << " ";
        }
        outFile << "\n";
    }

    return 0;
}

int Network::numUsers()
{
    return users_.size();
}

User* Network::getUser(int id)
{
    int usersSize = users_.size();
    for (int i = 0; i < usersSize; ++i)
    {
        if (users_[i]->getId() == id)
        {
            return users_[i];
        }
    }

    return nullptr;
}

std::vector<int> Network::shortestPath(int from, int to)
{
    std::vector<int> ans;
    std::queue<int> q;
    std::vector<bool> visited(users_.size(), false);
    std::vector<int> prev(users_.size(), -1);
    visited[from] = true;
    q.push(from);

    // BFS traversal
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // visit all neighbors of the current node
        for (int neighbor : users_[current]->getFriends())
        {
            if (!visited[neighbor])
            {
                // mark neighbor as visited, enqueue, update prev
                visited[neighbor] = true;
                q.push(neighbor);
                prev[neighbor] = current;
            }
        }
    }

    // check if connection is there
    bool hasConnection = false;
    for (int i = 0; i < prev.size(); ++i)
    {
        if (prev[i] == from)
        {
            hasConnection = true;
        }
    }
    if (!hasConnection)
    {
        std::cout << "None" << std::endl;
        return ans;
    }

    // backtrack while adding values to vector
    int backtrack = to;
    while (backtrack != from)
    {
        ans.insert(ans.begin(), backtrack);
        backtrack = prev[backtrack];
    }
    ans.insert(ans.begin(), from);

    return ans;
}

std::vector<int> Network::distanceUser(int from, int& to, int distance)
{
    // iterate through all users, try to find a shortest path with specified distance
    for (User* u : users_)
    {
        to = u->getId();
        std::vector<int> ans = shortestPath(from, to);
        if (ans.size() - 1 == distance)
        {
            return ans;
        }
    }

    // set "to" to -1 and return an empty vector
    to = -1;
    return std::vector<int>();
}

std::vector<int> Network::suggestFriends(int who, int& score)
{
    std::vector<int> candidates;

    // get ids of people that have a distance 2 away from User "who"
    for (User* u : users_)
    {
        int to = u->getId();
        std::vector<int> ans = shortestPath(who, to);
        int distance = ans.size() - 1;
        if (distance == 2)
        {
            candidates.push_back(to);
        }
    }

    // if no candidates
    if (candidates.empty())
    {
        score = 0;
        std::cout << "None" << std::endl;
        return std::vector<int>();
    }

    // create two sets of friends, find intersection
    std::map<int, int> scores;
    User* u = getUser(who);
    std::set<int> whoFriends = u->getFriends();

    // store all scores in a map
    for (int i = 0; i < candidates.size(); ++i)
    {
        int candidateId = candidates[i];
        User* v = getUser(candidateId);
        std::set<int> candidateFriends = v->getFriends();

        // find the number of common friends
        std::set<int> common;
        intersection(whoFriends.begin(), whoFriends.end(),
                     candidateFriends.begin(), candidateFriends.end(),
                     std::inserter(common, common.begin()));
        scores[candidateId] = common.size();

        // finding the max score
        if (score < common.size())
        {
            score = common.size();
        }
    }

    // find all max scores and return them
    std::vector<int> ans;
    for (auto element : scores)
    {
        if (element.second == score)
        {
            ans.push_back(element.first);
        }
    }

    return ans;
}

std::vector<int> Network::findCluster(int source, std::vector<bool>& visited)
{
    std::vector<int> ans;
    std::stack<int> stck;
    visited[source] = true;
    stck.push(source);
    ans.push_back(source);

    // DFS traversal
    while (!stck.empty())
    {
        int current = stck.top();
        stck.pop();

        // visit all neighbors of the current node
        for (int neighbor : users_[current]->getFriends())
        {
            if (!visited[neighbor])
            {
                // mark neighbor as visited, push back, add to ans
                visited[neighbor] = true;
                stck.push(neighbor);
                ans.push_back(neighbor);
            }
        }
    }

    return ans;
}

std::vector<std::vector<int>> Network::groups()
{
    std::vector<std::vector<int>> ans;
    std::vector<bool> visited(users_.size(), false);

    for (int i = 0; i < users_.size(); ++i)
    {
        if (!visited[i])
        {
            std::vector<int> cluster = findCluster(i, visited);
            ans.push_back(cluster);
        }
    }

    return ans;
}

//addPost should add the new post to the messages vector of the user whose id is ownerId
void Network::addPost(int ownerId, std::string message, int likes, bool isIncoming, std::string authorName, bool isPublic)
{
    User* u = getUser(ownerId);

    // get the total number of posts as the messageId
    int messageId = 0;
    for (auto u : users_)
    {
        messageId += u->getPosts().size();
    }

    if (isIncoming)
    {
        // number of posts total
        IncomingPost* post = new IncomingPost(messageId, ownerId, message, likes, isPublic, authorName);
        u->addPost(post);
    }
    else
    {
        Post* post = new Post(messageId, ownerId, message, likes);
        u->addPost(post);
    }
}

std::string Network::getPostsString(int ownerId, int howMany, bool showOnlyPublic)
{
    User* u = getUser(ownerId);

    if (u != nullptr)
    {
        return u->getPostsString(howMany, showOnlyPublic);
    }
    return "";
}

int Network::readPosts(const char* fname)
{
    std::ifstream inFile;
    inFile.open(fname);

    if (!inFile.is_open())
    {
        return -1;
    }

    // read the first line and convert to integer
    std::string line;
    std::getline(inFile, line);
    int numPosts = std::stoi(line);

    for (int i = 0; i < numPosts; ++i)
    {
        // read messageId
        std::getline(inFile, line);
        int messageId = std::stoi(line);

        // read message text, skip leading whitespace
        std::getline(inFile >> std::ws, line);
        std::string messageText = line;

        // read ownerId
        std::getline(inFile >> std::ws, line);
        int ownerId = std::stoi(line);

        // read likes
        std::getline(inFile >> std::ws, line);
        int likes = std::stoi(line);

        // read for empty(as in only tab), "public", or "private"
        std::getline(inFile, line);
        bool isIncomingPost = false;
        bool isPublic = true;
        if (line == "\tpublic")
        {
            isIncomingPost = true;
        }
        else if (line == "\tprivate")
        {
            isIncomingPost = true;
            isPublic = false;
        }
        
        // read in the author
        std::getline(inFile, line);
        std::string author;
        if (!line.empty())
        {
            author = line.substr(1, line.size() - 1);
        }

        // construct object according to its type
        Post* post = nullptr;
        if (isIncomingPost)
        {
            post = new IncomingPost(messageId, ownerId, messageText, likes, isPublic, author);
        }
        else
        {
            post = new Post(messageId, ownerId, messageText, likes);
        }
        User* u = getUser(ownerId);
        if (u != nullptr)
        {
            u->addPost(post);
        }
    }

    return 0;
}

int Network::writePosts(const char* fname)
{
    // make file stuff
    std::ofstream outFile(fname);

    if (!outFile.is_open())
    {
        return -1;
    }

    // get all posts from all users into a single vector of Post pointers
    std::vector<Post*> allPosts;
    for (User* user : users_)
    {
        for (Post* post : user->getPosts())
        {
            allPosts.push_back(post);
        }
    }

    // sorting allPosts with custom comparison
    struct
    {
        bool operator() (Post* post1, Post* post2) const
        {
            return post1->getMessageId() < post2->getMessageId();
        }
    } customLess;
    std::sort(allPosts.begin(), allPosts.end(), customLess);

    // write the number of posts to file
    int numPosts = allPosts.size();
    outFile << numPosts << "\n";

    // iterate through users_
    for (int i = 0; i < numPosts; ++i)
    {
        Post* post = allPosts[i];
        outFile << i << "\n";
        outFile << "\t" << post->getMessage() << "\n";
        outFile << "\t" << post->getOwnerId() << "\n";
        outFile << "\t" << post->getLikes() << "\n";
        outFile << "\t" ;

        std::set<int> temp = post->getLikedUsers();
        for (auto x : temp)
        {
            outFile << x << " ";
        }

        outFile << "\n" << "\t";
        
        // if it is an incoming post, author will NOT be empty
        if (post->getAuthor() != "")
        {
            bool isPublic = post->getIsPublic();
            if (isPublic)
            {
                outFile << "public";
            }
            else
            {
                outFile << "private";
            }
        }
        outFile << "\n";

        // output author
        outFile << "\t" << post->getAuthor() << "\n";
    }

    return 0;
}

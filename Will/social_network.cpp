#include "network.h"
#include "user.h"
#include <iostream>

// 1
static void addUser(Network& n)
{
    std::string name = "";
    std::string firstName = "";
    std::string lastName = "";
    std::set<int> friends = {};
    int birthYear = 0;
    int zipCode = 0;

    // read in everything
    std::cin >> firstName >> lastName >> birthYear >> zipCode;
    name = firstName + " " + lastName;
    int id = n.numUsers();

    // create new user, and add to network
    User* u = new User(id, name, birthYear, zipCode, friends);
    n.addUser(u);
}

// 2
static void addFriend(Network& n)
{
    std::string person1name = "";
    std::string person1firstName = "";
    std::string person1lastName = "";
    std::string person2name = "";
    std::string person2firstName = "";
    std::string person2lastName = "";

    // read in names
    std::cin >> person1firstName >> person1lastName >> person2firstName >> person2lastName;
    person1name = person1firstName + " " + person1lastName;
    person2name = person2firstName + " " + person2lastName;

    // make them friends
    int connection = n.addConnection(person1name, person2name);
    if (connection < 0)
    {
        std::cout << "Error: could not find a person." << std::endl;
    }
}

// 3
static void deleteFriend(Network& n)
{
    std::string person1name = "";
    std::string person1firstName = "";
    std::string person1lastName = "";
    std::string person2name = "";
    std::string person2firstName = "";
    std::string person2lastName = "";

    // read in names
    std::cin >> person1firstName >> person1lastName >> person2firstName >> person2lastName;
    person1name = person1firstName + " " + person1lastName;
    person2name = person2firstName + " " + person2lastName;

    // delete the connection
    int connection = n.deleteConnection(person1name, person2name);
    if (connection < 0)
    {
        std::cout << "Error: could not find a person." << std::endl;
    }
}

// 4
static void printUsers(Network& n)
{
    int num = n.numUsers();
    for (int i = 0; i < num; ++i)
    {
        User* u = n.getUser(i);
        std::string s = u->getName();
        std::cout << i << " " << s << std::endl;
    }
}

// 5
static void printFriends(Network& n)
{
    std::string name = "";
    std::string firstName = "";
    std::string lastName = "";

    // get the name
    std::cin >> firstName >> lastName;
    name = firstName + " " + lastName;

    // get id, then user, then list of friends. print error if person not found
    int id = n.getId(name);
    if (id < 0)
    {
        std::cout << "Error, no found person." << std::endl;
        return;
    }

    User* u = n.getUser(id);
    std::set<int> s = u->getFriends();

    for (auto itr = s.begin(); itr != s.end(); ++itr)
    {
        // getting id and pointer to friend
        int friendID = *itr;
        User* uFriend = n.getUser(friendID);
        std::string friendName = uFriend->getName();

        // print
        std::cout << friendID << " " << friendName << std::endl;
    }
}

// 6
static void writeFile(Network& n)
{
    std::string fname;
    std::cin >> fname;
    n.writeUsers((char*) fname.c_str());
}

// 7
static void findShortestPath(Network& n)
{
    std::string person1name = "";
    std::string person1firstName = "";
    std::string person1lastName = "";
    std::string person2name = "";
    std::string person2firstName = "";
    std::string person2lastName = "";

    // read in names
    std::cin >> person1firstName >> person1lastName >> person2firstName >> person2lastName;
    person1name = person1firstName + " " + person1lastName;
    person2name = person2firstName + " " + person2lastName;
    int from = n.getId(person1name);
    int to = n.getId(person2name);

    // check if users are there
    if (from == -1 || to == -1)
    {
        std::cout << "None" << std::endl;
        return;
    }

    // print a path and distance
    std::vector<int> ans = n.shortestPath(from, to);
    std::cout << "Distance: " << ans.size() - 1 << std::endl;

    for (int i = 0; i < ans.size(); ++i)
    {
        User* u = n.getUser(ans[i]);
        std::string name = u->getName();

        std::cout << name;
        if (i != ans.size() - 1)
        {
            std::cout << " -> ";
        }
    }

    std::cout << std::endl;
}

// 8
static void findUserAtGivenDistance(Network& n)
{
    std::string name = "";
    std::string firstName = "";
    std::string lastName = "";

    // get the name
    std::cin >> firstName >> lastName;
    name = firstName + " " + lastName;

    // get distance
    int distance;
    std::cin >> distance;

    // get user id
    int from = n.getId(name);
    int to = -1;
    if (from == -1)
    {
        std::cout << "None" << std::endl;
        return;
    }

    // get path
    std::vector<int> ans = n.distanceUser(from, to, distance);

    // if no path exists
    if (to == -1)
    {
        std::cout << "None" << std::endl;
        return;
    }

    // print out path
    User* u = n.getUser(ans[ans.size() - 1]);
    std::string nameOfFoundUser = u->getName();
    std::cout << nameOfFoundUser << ": ";

    for (int i = 0; i < ans.size(); ++i)
    {
        User* u = n.getUser(ans[i]);
        std::string uname = u->getName();

        std::cout << uname;
        if (i != ans.size() - 1)
        {
            std::cout << " -> ";
        }
    }

    std::cout << std::endl;
}

// 9
static void friendSuggestions(Network& n)
{
    std::string name = "";
    std::string firstName = "";
    std::string lastName = "";

    // get the name
    std::cin >> firstName >> lastName;
    name = firstName + " " + lastName;
    int who = n.getId(name);
    int score = 0;

    // get all friend suggestions
    std::vector<int> ans = n.suggestFriends(who, score);

    // print out
    if (!ans.empty())
    {
        std::cout << "The suggested friend(s) is/are:" << std::endl;
        for (int i = 0; i < ans.size(); ++i)
        {
            User* u = n.getUser(ans[i]);
            std::string uname = u->getName();
            std::cout << uname << " Score: " << score << std::endl;
        }
    }
}

// 10
static void connectedComponents(Network& n)
{
    std::vector<std::vector<int>> groups = n.groups();
    for (int i = 0; i < groups.size(); ++i)
    {
        std::cout << "Set " << i << " => ";
        for (int j = 0; j < groups[i].size(); ++j)
        {
            User* u = n.getUser(groups[i][j]);
            std::string name = u->getName();

            std::cout << name;
            if (j != groups[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

// 11
static void displayPosts(Network n)
{
    std::string name = "";
    std::string firstName = "";
    std::string lastName = "";

    // get the name
    std::cin >> firstName >> lastName;
    name = firstName + " " + lastName;
    int who = n.getId(name);
    
    // number of posts
    int numPosts;
    std::cin >> numPosts;

    // says in hw description to display both public and private
    std::string posts = n.getPostsString(who, numPosts, false);
    std::cout << posts << std::endl;
}




// // MAIN
// int main(int argc, char* argv[])
// {
//     // read in users
//     Network n;
//     char* f1name = argv[1];
//     n.readUsers(f1name);

//     // read in posts
//     char* f2name = argv[2];
//     n.readPosts(f2name);

//     while (true)
//     {
//         std::cout << "> ";

//         int x;
//         std::cin >> x;
//         switch (x)
//         {
//             // Add a user
//             case 1:
//                 addUser(n);
//                 break;

//             // Add friend connection
//             case 2:
//                 addFriend(n);
//                 break;

//             // Delete friend connection
//             case 3:
//                 deleteFriend(n);
//                 break;

//             // Print users
//             case 4:
//                 printUsers(n);
//                 break;

//             // Print Friends
//             case 5:
//                 printFriends(n);
//                 break;

//             // Write to file
//             case 6:
//                 writeFile(n);
//                 break;

//             // Find shortest path between two people
//             case 7:
//                 findShortestPath(n);
//                 break;

//             // Find someone who is a certain distance away
//             case 8:
//                 findUserAtGivenDistance(n);
//                 break;

//             // Give friend suggestions
//             case 9:
//                 friendSuggestions(n);
//                 break;

//             // Give the "clusters" that a person belongs to
//             case 10:
//                 connectedComponents(n);
//                 break;

//             // Displays the posts of a certain person
//             case 11:
//                 displayPosts(n);
//                 break;

//             // End the loop
//             default:
//                 return 0;
//         }
//     }

//     return 0;
// }



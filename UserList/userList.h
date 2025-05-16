
#ifndef USERLIST_H
#define USERLIST_H
#include "../User/User.h"
class userList
{
private:
    User* users;
    int capacity;
    int usersCount;
public:
    userList();
    userList(int );
    void addUser(User &);
    User* searchUser(string );
    User* searchUser(int );
    void deleteUser(int );
    friend ostream &operator<<( ostream& ,const userList&);
    ~userList();
};
#endif //USERLIST_H

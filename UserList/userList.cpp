 #include "../userList/userList.h"
#include "../User/User.h"
#include <iostream>
using namespace std ;

userList::userList() {
 capacity = 0 ;
 usersCount = 0 ;
}

userList::userList(int capacity ) {
 this->capacity = capacity ;
 users = new User [capacity];
 usersCount = 0 ;
}

void userList::addUser(User & newUser) {
 if(usersCount >= capacity) {
  cout<<"Sorry , the user list is full "<<endl;
  return ;
 }
 newUser.setId(usersCount+1);
 users[usersCount] = newUser ;
 usersCount++;

}


User* userList::searchUser(string userName ) {
 for(int i=0 ; i<usersCount ; i++) {
       if(users[i].getName() == userName) {
         return &users[i];
       }
 }
       return NULL ;
}

User* userList::searchUser(int id ) {
 for(int i=0 ; i<usersCount ; i++) {
         if(users[i].getId() == id) {
            return &users[i];
         }
   }
         return NULL ;
}


void userList::deleteUser(int id ) {

 int startPoint ;
bool found = false  ;
 for(int i=0 ; i<usersCount ; i++) {
         if(users[i].getId() == id ) {
          startPoint = i ;
          found = true ;
          break ;
          }
 }

 if(!found) return ;

 for(int i=startPoint ; i<usersCount-1 ; i++) {
    users[i] = users[i+1];
    users[i].setId(i+1);
 }
 usersCount--;

}

ostream &operator<<( ostream& output ,const userList& userList )   {
 for(int i=0 ; i<userList.usersCount ; i++ ) {
    output<<userList.users[i]<<endl;
 }
    return output ;
}

userList::~userList() {
 delete []users ;
}
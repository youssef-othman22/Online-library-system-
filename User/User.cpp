#include "User.h"
#include <iostream>
int User::count = 0 ;

User::User() {
    name = "";
    age = 0 ;
    count++;
    id = count ;
    password =  "";
    email = "";
}

User::User(string name  , int age , string password , string email ) {
    this->name = name ;
    this->age = age ;
    this->password = password ;
    this->email = email ;
    count++;
    id = count ;
}

User::User(const User &user) { // this is a copy constructor
    this->name = user.name ;
    this->age = user.age ;
    this->password = user.password ;
    this->email = user.email ;
    this->id = user.id ;
}



bool User::operator==(const User& user  ) {
    if((this->name == user.name)&&(this->email == email )&&(this->age == age)&&(this->id  == user.id )&&(this->password == user.password))
        return true ;
    else
        return false ;
}
void User::setName(string name ) {
    this->name = name ;
}
string User::getName() const {
    return name ;
}
void User::setPassword(string password ) {
this->password = password ;
}
string User::getPassword()const {
    return password ;
}
void User::setEmail(string email ) {
    this->email = email ;
}
string User::getEmail()const {
    return email ;
}
void User::setAge(int age ) {
    this->age = age ;
}
int User::getAge()const {
    return age ;
}
void User::setId(int id ) {
    this->id = id ;
}
int User::getId()const {
    return id ;
}
void User::Display () {
    cout<<"name : "<<name<<"\n";
    cout<<"age : "<<age<<"\n";
    cout<<"ID : "<<id<<"\n";
    cout<<"email : "<<email<<"\n";

}

    istream &operator>>(istream &input ,   User &user){
    cout<<"Enter user's name : "<<"\n";
    input>>user.name;
    cout<<"Enter user's age : "<<"\n";
    input>>user.age;
    cout<<"Enter user's password : "<<"\n";
    input>>user.password ;
    cout<<"Enter user's email : "<<"\n";
    input>>user.email;
    return input ;
}

ostream &operator<<(ostream &output , const  User &user ) {
    output<<"===================="<<"User "<<user.getId()<<" Info ===================="<<"\n";
    output<<"name | "<<user.getName()<<"\n";
    output<<"Age | "<<user.getAge()<<"\n";
    output<<"ID | "<<user.getId()<<"\n";
    output<<"email | "<<user.getEmail()<<"\n";
    output<<"========================================================================="<<"\n";
    return output ;
}

#ifndef USER_H
#define USER_H
using namespace std;
#include <string>

class User{
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count;
    User();
    User(string  , int  , string  , string  );
    User(const User& );
    bool operator==(const User&  );
    void setName(string );
    string getName() const; // here i used const to prevent errors when invoking the function using const object
    void setPassword(string );
    string getPassword()const;
    void setEmail(string );
    string getEmail()const ;
    void setAge(int );
    int getAge()const;
    void setId(int );
    int getId()const;
    void Display ();
    friend ostream &operator<<(ostream & , const User &);
    friend istream &operator>>( istream & ,  User &);







};




















#endif //USER_H

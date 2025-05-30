#pragma once
#include <iostream>
#include <string>
#include "../User/User.h"
using namespace std ;

class Book
{
private:
    string title;
    string isbn;
    int id;
    string category;
    double averageRating;
    User   author;
    static int Count;
    int numberOfRates ;
    int rates ;
public:

    Book( );
    Book(string , string , string );
    Book(const Book& );
    void setTitle(string );
    string getTitle() const ;
    void setIsbn(string );
    string getIsbn() const;
    void setId(int);
    int getId() const;
    void setCategory(string );
    string getCategory()const;
    void setAuthor( const  User & );
    User getAuthor() const;
    void rateBook(int);
    int getAverageRating () const;
    bool operator==(const Book&);
    friend ostream &operator<<(ostream &, const Book &);
    friend istream &operator>>( istream &, Book &);

};
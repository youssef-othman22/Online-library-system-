

#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "../User/User.h"
#include "../Book/Book.h"
class BookList {
private:
    Book*books;
    int capacity;
    int booksCount;
public:
    BookList();
    BookList(int );
    void addBook(const Book& ); // at the end of the array.
    Book* searchBook(string);
    Book* searchBook(int );
    void deleteBook(int ); //delete a book
    Book getTheHighestRatedBook();
    void getBooksForUser(const User &); // get all books of this author
    Book& operator[] (int );
    friend ostream&operator<<(ostream &,const BookList & ); //to display all books
    ~BookList();
};
#endif //BOOKLIST_H

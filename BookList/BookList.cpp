 #include "../User/User.h"
#include "BookList.h"

#include <algorithm>
#include <iostream>

using namespace std ;

BookList::BookList() {
 int capacity = 0 ;
 int booksCount = 0 ;
}

BookList::BookList(int capacity ) {
this->capacity = capacity ;
 books = new Book [capacity];
 booksCount = 0 ;
}


void BookList::addBook(const Book& newBook ) {
   if (booksCount>=capacity) {
          cout<<"Sorry , the Book list is full ! "<<endl;
          return ;
   }

   books[booksCount] = newBook ;
 books[booksCount].setId(booksCount+1);
   booksCount++;

}


Book* BookList::searchBook(string title ) {
 for(int i=0 ; i<booksCount ; i++) {
    if(books[i].getTitle() == title) {
        return &books[i];
    }
 }
        return NULL ;
}


Book* BookList::searchBook(int id ) {
 for(int i=0 ; i<booksCount ; i++) {
  if(books[i].getId() == id) {
   return &books[i];
  }
 }
 return NULL ;
}



void BookList::deleteBook(int id ) {
 int startPoint ;
 bool found = false  ;
 for(int i=0 ; i<booksCount ; i++) {
  if(books[i].getId() == id ) {
   startPoint = i ;
   found = true ;
   break ;
  }
 }

 if(!found) return ;

 for(int i=startPoint ; i<booksCount-1 ; i++) {
  books[i] = books[i+1];
  books[i].setId(i+1);
 }
 booksCount--;

}


Book BookList::getTheHighestRatedBook() {
 int m = -1 ;
 int index = -1 ;
 for(int i=0 ; i<booksCount ; i++) {
  if(books[i].getAverageRating() > m ) {
   m = books[i].getAverageRating() ;
   index = i ;
  }
 }
 return books[index];
}

void BookList::getBooksForUser(const User & user) {
 bool found = false ;
 for(int i=0 ; i<booksCount ; i++) {
  if(books[i].getAuthor() == user) {
   found = true ;
   cout<<books[i].getAuthor();
  }
 }
 if(!found) cout<<"This author doesn't have current books !" <<endl;
}

Book& BookList::operator[] (int pos ) {
 if(pos<0 || pos>=booksCount) {
  cout<<"Error"<<endl;
  exit(1);
 }
 return books[pos];
}

ostream& operator<< (ostream& output , const BookList & bookList ) {
 for(int i=0 ; i<bookList.booksCount ; i++ ) {
     output<<bookList.books[i]<<endl;
 }
     return output ;
}

BookList::~BookList() {
 delete [] books ;
}

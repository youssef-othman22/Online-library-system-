 #include "Book.h"
#include "../User/User.h"
 using namespace std ;

int Book::Count = 0 ;

Book::Book( ) {
 title = "";
 isbn = "";
 Count++;
 id = Count ;
 category = "";
 averageRating = 0 ;
 User author ;
 numberOfRates = 0 ;
 rates = 0 ;
}

Book::Book (string title , string isbn , string category ) : title(title) , isbn(isbn) , category(category) {
User author ;
 Count++;
 averageRating = 0.0 ;
 id = Count ;
 numberOfRates = 0 ;
 rates = 0 ;
}

Book::Book(const Book& book) {
 this->title = book.title ;
 this->isbn = book.isbn ;
 this->id = book.id ;
 this->category = book.category ;
 this->averageRating = book.averageRating ;
 this->numberOfRates = book.numberOfRates;
 this->rates = book.rates ;
 author = book.author ;
}


void Book :: setTitle(string title ) { this->title = title;}

string Book::getTitle() const {return title ;}

void Book::setIsbn(string isbn ){this->isbn;}

string Book::getIsbn() const {return isbn;}

void Book::setId(int id ){this->id = id ;}

int Book::getId() const{return id ;}

void Book::setCategory(string category ){this->category = category ;}

string Book::getCategory()const{return category ;}

void Book::setAuthor( const  User &user ){ author =  user ;}

User Book::getAuthor() const {return author ;}

int Book::getAverageRating () const{return averageRating ;}

void Book::rateBook(int newRate ) {
 while(newRate<0 || newRate>5) {
  cout<<"Please , Enter a valid rate from 0 to 5 "<<endl;
  cin >> newRate ;
 }
this->numberOfRates++;
 this->rates += newRate ;
 averageRating = rates/numberOfRates ;
}

bool Book::operator==(const Book& book ) {return (this->title == book.title && this->id == book.id && this->averageRating == book.averageRating && this->author == book.author );}

 istream &operator>>( istream &input , Book &book) {
  cout<<"Enter the information of the book \n";
  cout<<"Title : "<<endl;
  input>>book.title;
  cout<<"Isbn : "<<endl;
  input>>book.isbn;
  cout<<"Category : "<<endl;
  input>>book.category;
  // cout<<"Rate : "<<endl;
  // int rate ;
  // cin >> rate ;
  // book.rateBook(rate);
  return input ;
}

 ostream &operator<<(ostream &output, const Book & book ) {
 output<<"===================="<<" Book "<<book.id<<" Info ========================================"<<"\n";
 output<<"Title | "<<book.title<<"\n";
 output<<"Isbn | "<<book.isbn<<"\n";
 output<<"ID | "<<book.id<<"\n";
 output<<"Category | "<<book.category<<"\n";
 output<<"Average Rating | "<<book.getAverageRating()<<"\n";
 cout<<endl;
 if(book.author.getName()  != "") cout<<book.getAuthor();
 output<<"========================================================================="<<"\n";
 return output ;
}


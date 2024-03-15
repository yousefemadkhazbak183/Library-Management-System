//
//  main.cpp
//  library-system-management
//
//  Created by Yousef Emad on 15/03/2024.
//

#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int Book::id_Helper = 0;
int Library:: bookCount = 0;


int main(){
    
    Library library("Alex");
    
    Author author1("John Smith", "john@gmail.com");
    author1.print();
    Author author2("Thoms", "thoms@gmail.com");
    author2.print();
    Book book1("Introduction to C++", author1, "Available");
    Book book2("Head First Object Orinted Design", author2, "Available");
   
    library.addBook(book1);
    library.addBook(book2);
    library.borrowBook(2);
    library.returnBook(2);
    library.removeBook(1);
    library.displayBook();
    try {
           Book foundBook = library.searchBook(1);
           cout << "Book Found - ID: " << foundBook.getBookID() << ", Title: " << foundBook.getBookTiltle() << ", Author: " << foundBook.getBookWriterName() << ", Status: " << foundBook.getBookStatus() << endl;
       } catch (int e) {
           cout << "Book Not Found. " << endl;
       }

       return 0;
    

    

    
}


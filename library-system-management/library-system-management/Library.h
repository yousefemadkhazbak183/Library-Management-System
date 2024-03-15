//
//  Library.h
//  library-system-management
//
//  Created by Yousef Emad on 15/03/2024.
//

#ifndef Library_h
#define Library_h
#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;

class Library{
    // Attribu
private:
    string name;
    vector<Book> books;
    static int bookCount;
    
public:
    // Cons
    Library(string name): name(name){}
    
    // Add Book
    void addBook(Book b){
        books.push_back(b);
        cout << "Book added Successfully. "<< endl;
        bookCount++;
    }
    
    // Remove Book
    void removeBook(int iD){
        for(int i = 0; i < books.size(); i++){
            if(books[i].getBookID() == iD){
                books[i].setBook_Status("Removed");
                cout << "Book removed Successfully: "<< ", ID: "<< books[i].getBookID()<<", Title: "<< books[i].getBookTiltle() << ", Status:  "<< books[i].getBookStatus()<< endl;
                books.erase(books.begin() + i);
                bookCount--;
                return;
            }
        }
    }
    // BroowBook
    void borrowBook(int iD){
        for(int i = 0; i < books.size(); i++){
            if(books[i].getBookID() == iD && books[i].getBookStatus() == "Available"){
                books[i].setBook_Status("Borrowed");
                cout << "Book borrowed successfully" << endl;
                return;
            }
        }
        cout << "Book with ID " << iD << " is either not available or does not exist." << endl;
    }
    void returnBook(int iD) {
        bool bookFound = false; // Flag to indicate if the book is found
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getBookID() == iD && books[i].getBookStatus() == "Borrowed") {
                books[i].setBook_Status("Available");
                cout << "Book returned successfully" << endl;
                bookFound = true; // Mark book as found
                break; // Exit the loop once book is found and updated
            }
        }
        
        if (!bookFound) {
            cout << "Book with ID " << iD << " not found or is not borrowed." << endl;
        }
    }
    
    // Display
    void displayBook(){
        cout << "Book in "<< name << "Library: "<<endl;
        for(Book&b : books){
            cout << "ID: "<< b.getBookID() << ", Title: "<< b.getBookTiltle() << ", Author: "<< b.getBookWriterName() <<  ", Status: "<<b.getBookStatus() << endl;
        }
    }
    
    // Search Book
    Book searchBook(int iD){
        for(Book& b : books){
            if(b.getBookID() == iD){
                return b;
            }
        }
        throw 1;
    }
};


#endif /* Library_h */

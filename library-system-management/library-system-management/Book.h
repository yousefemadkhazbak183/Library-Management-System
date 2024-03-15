//
//  Book.h
//  library-system-management
//
//  Created by Yousef Emad on 15/03/2024.
//

#ifndef Book_h
#define Book_h
#include <iostream>
#include <string>
using namespace std;

class Author{
    // Attributes
private:
    string email;
    string name;
    
public:
    // Constr
    Author(string name, string email) : name(name), email(email){}
    
    // Get
    string getAuthorEmail(){
        return email;
    }
    string getAuthorName(){
        return name;
    }
    // Set
    void setEmail(string email){
        this -> email = email;
    }
    void print(){
        cout  << "Name: "<< name << ", Email: "<< email << endl;
        cout << "================================================\n";
    }
};

class Book{
    // Attributes
private:
    int iD;
    static int id_Helper;
    Author writer;
    string status;
    string title;
    
public:
    // Cons
    Book(string title, Author writer, string status): iD(++id_Helper), title(title), writer(writer), status(status){
    }
    
    //Get
    int getBookID(){
        return iD;
    }
    string getBookTiltle(){
        return title;
    }
    string getBookStatus(){
        return status;
    }
    string getBookWriterName(){
        return writer.getAuthorName();
    }
    void setBook_Status(string status){
        this-> status = status;
    }
    
};

#endif /* Book_h */

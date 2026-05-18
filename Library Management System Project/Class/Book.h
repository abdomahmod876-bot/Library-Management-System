#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;
#pragma once

class Book
{
    private:
    string title;
    string author;
    int ISBN;
    bool available;
public:
    Book()
    {
        title = "";
        author = "";
        ISBN = 0;
        available = true;
    }
    ~Book()
    {

    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setISBN(int ISBN)
    {
        this->ISBN = ISBN;
    }
    void setAvailable(bool available)
    {
        this->available = available;
    }
    string getTitle() 
       {
        return title;
    }
    string getAuthor() 
      {
        return author;
    }
    int getISBN()  
     {
        return ISBN;
    }
    bool isAvailable()  
     {
        return available;
    }
   void print()
    {
        cout << "Enter book title: ";
        cin >> title;
        cout << "Enter book author: ";
        cin >> author;
        cout << "Enter book ISBN: ";
        cin >> ISBN;
        cout << "Enter availability (1 for yes, 0 for no): ";
        cin >> available;
    }
    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }
};


#endif
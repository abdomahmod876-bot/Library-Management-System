#ifndef MEMBER_H
#define MEMBER_H
#include "Book.h"
#include <iostream>
#include <vector>
using namespace std;
#pragma once

class Member
{
    private:
    string name;
    int memberID;
    vector<Book> borrowedBooks;
public:
    Member()
    {
        name = "";
        memberID = 0;
    }
    ~Member()
    {

    }
    void setName(string name)
    {
        this->name = name;
    }
    void setMemberID(int memberID)
    {
        this->memberID = memberID;
    }
    string getName() 
       {
        return name;
    }
    int getMemberID() 
     {
        return memberID;
    }
    void borrowBook(Book book)
    {
        borrowedBooks.push_back(book);
    }
    int getBorrowedBooksCount()
    {
        return borrowedBooks.size();
    }
    void returnBook(int ISBN)
    {
        for (size_t i = 0; i < borrowedBooks.size(); i++)
        {

            if (borrowedBooks[i].getISBN() == ISBN)
            {
                borrowedBooks.erase(borrowedBooks.begin() + i);
                break;
            }

        }
    }
    bool canBorrow()
    {
        return borrowedBooks.size() < 3; // Limit to 3 books
    }
    void print()
    {
        cout << "Enter member name: ";
        cin >> name;
        cout << "Enter member ID: ";
        cin >> memberID;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Member ID: " << memberID << endl;
        cout << "Borrowed Books: " <<endl;
        for (size_t i = 0; i < borrowedBooks.size(); i++)
        {
            borrowedBooks[i].display();
        }
    }

};

#endif
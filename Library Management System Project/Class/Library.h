#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Member.h"
#include <iostream>
#include <vector>
using namespace std;
#pragma once

class Library
{
    private:
    vector<Book> books;
    vector<Member> members;
public:
    Library()
    {
        books.clear();
        members.clear();
    }
    ~Library()
    {

    }
    void addBook(Book book)
    {
        for (size_t i = 0; i < books.size(); i++)
        {
            if (books[i].getISBN() == book.getISBN())
            {
                cout << "Book with this ISBN already exists!" << endl;
                return;
            }
        }
        books.push_back(book);
        cout << "Book added successfully!" << endl;
    }
    void addMember(Member member)
    {
        for (size_t i = 0; i < members.size(); i++)
        {
            if (members[i].getMemberID() == member.getMemberID())
            {
                cout << "Member with this ID already exists!" << endl;
                return;
            }
        }
        members.push_back(member);
        cout << "Member added successfully!" << endl;
    }
    void displayBooks()
    {
        for (size_t i = 0; i < books.size(); i++)
        {
            books[i].display();
            cout << "-------------------" << endl;
        }
    }
    void displayMembers()
    {
        for (size_t i = 0; i < members.size(); i++)
        {
            cout << "Name: " << members[i].getName() << endl;
            cout << "Member ID: " << members[i].getMemberID() << endl;
            cout << "Borrowed Books: " << members[i].getBorrowedBooksCount() << endl;
            cout << "-------------------" << endl;
        }
    }
 void borrowBook(int memberID, int ISBN)
    {
        for (size_t i = 0; i < members.size(); i++)
        {
            if (members[i].getMemberID() == memberID)
            {
                for (size_t j = 0; j < books.size(); j++)
                {
                    if (!members[i].canBorrow())
                    {
                        cout << "Member has reached the maximum borrowing limit." << endl;
                        return;
                    }
                    if (books[j].getISBN() == ISBN && books[j].isAvailable())
                    {
                        members[i].borrowBook(books[j]);
                        books[j].setAvailable(false);
                        cout << "Book borrowed successfully!" << endl;
                        return;
                    }
                }
                cout << "Book not available." << endl;
                return;
            }
        }
        cout << "Member not found." << endl;
    }
    void returnBook(int memberID, int ISBN)
    {
        for (size_t i = 0; i < members.size(); i++)
        {
            if (members[i].getMemberID() == memberID)
            {
                members[i].returnBook(ISBN);
                for (size_t j = 0; j < books.size(); j++)
                {
                    if (books[j].getISBN() == ISBN)
                    {
                        books[j].setAvailable(true);
                        cout << "Book returned successfully!" << endl;
                        return;
                    }
                }
            }
        }
        cout << "Member not found." << endl;
    }


};

#endif
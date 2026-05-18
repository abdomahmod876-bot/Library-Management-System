#include <iostream>
#include "Class/Library.h"
#include "Class/Book.h"
#include "Class/Member.h"
using namespace std;
// Main function to run the Library Management System
int main() 
{
    cout << "Welcome to the Library Management System!" << endl;
    Library library;
    int choice = -1;
        while (choice != 0) 
        // Display menu options
        {
            cout << "\n===== Library Management System =====\n";
    cout << "1. Add Book" << endl;
    cout << "2. Add Member" << endl;
    cout << "3. Display Books" << endl;
    cout << "4. Display Members" << endl;
    cout << "5. Borrow Book" << endl;
    cout << "6. Return Book" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    
    cin >> choice;
      
   
      if (choice == 1)
        {
            // Create a new book and add it to the library
            Book book;
            book.print();
            library.addBook(book);
        }
        else if (choice == 2)
        {
            // Create a new member and add it to the library
            Member member;
            member.print();
            library.addMember(member);
        }
        else if (choice == 3)
        {
            // Display all books in the library
            library.displayBooks();
        }
        else if (choice == 4)
        {
            // Display all members of the library
            library.displayMembers();
        }
        else if (choice == 0)
        {
            // Exit the system
            cout << "Exiting the system. Goodbye!" << endl;
        }
        else if (choice == 5)
        {
            // Borrow a book for a member
             int memberID, ISBN;
            
            cout << "Enter member ID: ";
            cin >> memberID;
            cout << "Enter book ISBN: ";
            cin >> ISBN;
            library.borrowBook(memberID, ISBN);
        }
        else if (choice == 6)
        {
            // Return a book for a member
            int memberID, ISBN;
            cout << "Enter member ID: ";
            cin >> memberID;
            cout << "Enter book ISBN: ";
            cin >> ISBN;
            library.returnBook(memberID, ISBN);
        }
      
        else
        {
            // Handle invalid menu choices
            cout << "Invalid choice. Please try again." << endl;
        }
       
   }
    return 0;
}
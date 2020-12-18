//
//  main.cpp
//  Library
//
//  Created by Nick Rosas on 12/5/20.
//  Copyright © 2020 Nick Rosas. All rights reserved.
//

#include <iostream>
#include "Book.hpp"
#include "Inventory.hpp"
#include "checkResult.h"


using namespace std;

Inventory _inventory;

void addNewBook()
{
    cout << "Title: ";
    string title;
    getline(cin, title);
    
    cout << "Author: ";
    string author;
    getline(cin, author);
    cout << endl;
    
    Book newBook(title, author); // create newBook object
    _inventory.addBook(newBook); // add newBook to inventory
}//END addNewBook

void listInventory()
{
    _inventory.displayAllBookInfo();
}//END listInventory

void checkBook(bool checkOut)
{
    string checkCommand;
    if(checkOut)
    {
        checkCommand = "out";
    }//END if
    else
    {
        checkCommand = "in";
    }//END else
    
    cout << "Enter a book title to check " + checkCommand + ": ";
    string title;
    getline(cin, title);
    cout << endl;

    checkResults result = _inventory.checkBook(title, checkOut);
    if(result == checkResults::BookNotFound)
    {
        cout << "Book not found";
    }
    else if (result == checkResults::Success)
    {
        cout << "Book checked " + checkCommand + "!" << endl;
    }
    else
    {
        cout << "Book failed checking " + checkCommand + "!" << endl;
    }
}

//void checkOutBook()
//{
//    cout << "Enter a book title to check out: ";
//    string title;
//    getline(cin, title);
//    cout << endl;
//
//    int foundBookIndx =_inventory.searchByTitle(title);
//
//    if(foundBookIndx >=0) // if book found
//    {
//        Book* foundBook = _inventory.getBookByIndex(foundBookIndx); // get pointer to found book
//
//        if(foundBook->CheckedOut) // if book is already checked out
//        {
//            cout << "Book already checked out" << endl;
//            return;
//        }//END inner if
//
//        _inventory.checkOutBook(foundBook); // Check out book
//        cout << "Book checked out" << endl;
//    }//END if
//    else
//    {
//        cout << "Book not found" << endl;
//    }//END else
//}//END checkOutBook
//
//void checkInBook()
//{
//    cout << "Enter a book title to check in: ";
//    string title;
//    getline(cin, title);
//    cout << endl;
//
//    int foundBookIndx =_inventory.searchByTitle(title); // Get book index
//
//    if(foundBookIndx >=0)
//    {
//        Book *foundBook = _inventory.getBookByIndex(foundBookIndx); // Get pointer to book
//
//        if(!foundBook->CheckedOut)
//        {
//            cout << "Book already checked in" << endl;
//            return;
//        }//END inner if
//        _inventory.checkInBook(foundBook);
//        cout << "Book checked in" << endl;
//    }//END outer if
//    else
//    {
//        cout << "Book not found" << endl;
//    }//END else
//}//END checkInBook

void removeBook()
{
    cout << "Title: ";
    string title;
    getline(cin, title);
    cin.ignore();
    cout << endl;
    
    _inventory.removeBook(title); // add newBook to inventory
    cout << title << "removed" << endl;
}//END removeBook

void viewCheckedOutBooks()
{
    _inventory.displayCheckedOutBooks();
}//END viewCheckedOutBooks

int main(int argc, const char * argv[])
{
    while (true)
    {
        // show input option
        cout << "Choose an option:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Inventory" << endl;
        cout << "3. Check Out Book" << endl;
        cout << "4. Check In Book" << endl;
        cout << "5. Remove Book from Inventory" << endl;
        cout << "6. View Checked Out Books" << endl;
        
        cout << "0. Exit" << endl << endl;
        
        // get input from user
        int input;
        cin >> input;
        cin.ignore(); // ignore end of buffer
        
        // handle input from user
        switch(input)
        {
            case 0:
                cout << "Exiting Program, Goodbye"  << endl;
                return 0;
            case 1:
                addNewBook();
                break;
            case 2:
                listInventory();
                break;
            case 3:
                checkBook(false);
                break;
            case 4:
                checkBook(true);
                break;
            case 5:
                removeBook();
                break;
            case 6:
                viewCheckedOutBooks();
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }//END switch
    }//END while
}//END main


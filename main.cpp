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
#include "User.hpp"

using namespace std;

Inventory _inventory;
vector<User> _users;
User _loggedInUser;


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
    else if(result == checkResults::BookAlreadyCheckedIn ||
            result == checkResults::BookAlreadyCheckedOut  )
    {
        cout << "Book already checked " + checkCommand << endl;
    }
    else
    {
        cout << "Book failed checking " + checkCommand + "!" << endl;
    }
}//END checkBook()

void createAccount()
{
    User newUser;
    
    cout << "First name: " << endl;
    string firstName;
    getline(cin, newUser.firstName);
    
    cout << "Last name: " << endl;
    string lastNAme;
    getline(cin, newUser.lastName);
    
    cout << "Username: " << endl;
    string userName;
    getline(cin, newUser.userName);
    
    cout << "Select a role:" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Employee" << endl;
    cout << "3. Member" << endl;
    
    int roleOption;
    cin >> roleOption;
    cin.ignore();
    
    if(roleOption == 1)
        newUser.Role = Role::Admin;
    else if(roleOption == 2)
        newUser.Role = Role::Employee;
    else if(roleOption == 3)
        newUser.Role = Role::Member;
    
    _users.push_back(newUser);
    
}//END createAccount()

void login()
{
    cout << "Choose an option:" << endl;
    cout << "1. Log In" << endl;
    cout << "2. Create an account" << endl;
    
    int option;
    cin >> option;
    cin.ignore();

    if(option == 2)
    {
        createAccount();
    }//END if
    
    
    cout << "Enter username: ";
    string userName;
    getline(cin,userName);

    User user;
    user.userName = userName;
    
    vector<User>::iterator it = find(_users.begin(), _users.end(), user);
    
    if (it != _users.end())
    {
        _loggedInUser = _users[it - _users.begin()];
        
    }//END if
    
}//END login()

void removeBook()
{
    cout << "Title: ";
    string title;
    getline(cin, title);
    cin.ignore();
    cout << endl;
    
    _inventory.removeBook(title); // add newBook to inventory
    cout << title << "removed" << endl;
}//END removeBook()

void viewCheckedOutBooks()
{
    _inventory.displayCheckedOutBooks();
}//END viewCheckedOutBooks()

int main(int argc, const char * argv[])
{
    login();
    while (true)
    {
        // show input option
        cout << endl;
        cout << "Choose an option:" << endl;
        
        if(_loggedInUser.Role == Role::Admin ||
           _loggedInUser.Role == Role::Employee)
        {
            cout << "1. Add Book" << endl;
            cout << "5. Remove Book from Inventory" << endl;
            cout << "6. View Checked Out Books" << endl;
        }
        
        cout << "2. View Inventory" << endl;
        cout << "3. Check Out Book" << endl;
        cout << "4. Check In Book" << endl;
        
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
                checkBook(true);
                break;
            case 4:
                checkBook(false);
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
}//END main()


//
//  Inventory.cpp
//  Library
//
//  Created by Nick Rosas on 12/5/20.
//  Copyright © 2020 Nick Rosas. All rights reserved.
//

#include "Inventory.hpp"
#include <vector>

Inventory::Inventory()
{
    Inventory::maxBookID = 0;
}

int Inventory::getInventorySize()
{
    return Inventory::Books.size();
}

Book Inventory::getBookByIndex(int index)
{
    return Inventory::Books[index];
}

void Inventory::addBook(Book book)
{
    Inventory::maxBookID++;
    book.setBookID(maxBookID);
    Inventory::Books.push_back(book);
    
}//END addBook()

void Inventory::removeBook(std::string title)
{
    // Create iterator obj for vector
    std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(title, ""));
    
    if( it != Inventory::Books.end())
    {
        Inventory::Books.erase(it);
    }
    
}//END addBook()

int Inventory::searchByTitle(std::string title)
{
    //TODO Handle maxBookID when removing
    
    
    // Create iterator obj for vector
    std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(title, ""));
    
    if( it == Inventory::Books.end())
    {
        return -1; // return -1 if not found
    }
    
    int index = it - Inventory::Books.begin(); // get index of book in vector
    
    return index;
}//END searchByTitle()

checkResults Inventory::checkBook(std::string title, bool checkOut)
{
    int bookIndex = searchByTitle(title); // find book index by title
    
    if(bookIndex < 0)
    {
        return checkResults::BookNotFound;
    }//END if(bookIndex < 0)
    else if(checkOut == Books[bookIndex].isCheckedOut())
    {
        if(checkOut)
        {
            return checkResults::BookAlreadyCheckedOut;
        }//END if(checkOut)
        else
        {
            return checkResults::BookAlreadyCheckedIn;
        }//END inner else
    }//END else if
    
    Books[bookIndex].checkInOrOut(checkOut); // check out or in book
    return checkResults::Success;
}//END checkBook


void Inventory::displayAllBookInfo()
{
    std::cout << "ID\tTitle\tAuthor" << std::endl;
    for (int i=0; i < getInventorySize(); i++) // iterate through inventory
    {
        Books[i].displayBookInfo();
    }//END for
    std::cout << std::endl;
}//displayAllBookInfo()

void Inventory::displayCheckedOutBooks()
{
    std::cout << "ID\tTitle\tAuthor" << std::endl;
    for (int i=0; i < getInventorySize(); i++) // iterate through inventory
    {
        if(getBookByIndex(i).isCheckedOut())
        {
            Books[i].displayBookInfo();
        }//END if
    }//END for
    std::cout << std::endl;
}//END displayCheckedOutBooks()

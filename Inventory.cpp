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

Book* Inventory::getBookByIndex(int index)
{
    return &Inventory::Books[index];
}

void Inventory::addBook(Book book)
{
    Inventory::maxBookID++;
    book.ID = maxBookID;
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

void Inventory::checkOutBook(Book *book)
{
    book->CheckedOut = true;
}//END checkOutBook

void Inventory::checkInBook(Book *book)
{
    book->CheckedOut = false;
}//END checkOutBook


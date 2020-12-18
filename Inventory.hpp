//
//  Inventory.hpp
//  Library
//
//  Created by Nick Rosas on 12/5/20.
//  Copyright © 2020 Nick Rosas. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include "Book.hpp"
#include "checkResult.h"
#include <vector>

class Inventory
{
private:
    std::vector<Book> Books; // vector to hold book inventory
    int maxBookID;
    int getNextBookID();
public:
    Inventory();
    
    void displayAllBookInfo();
    void displayCheckedOutBooks();
    int getInventorySize();
    Book getBookByIndex(int index);
    void addBook(Book book); // function to add book to inventory
    void removeBook(std::string title); // function to remove book from inventory
    int searchByTitle(std::string title); // funciton to look for book by title
    checkResults checkBook(std::string title, bool checkOut); // function to check books in or out
}; //END Inventory


#endif /* Inventory_hpp */

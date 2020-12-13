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
#include <vector>

class Inventory
{
private:
    std::vector<Book> Books; // vector to hold book inventory
    int maxBookID;
    int getNextBookID();
public:
    Inventory();
    
    int getInventorySize();
    Book* getBookByIndex(int index);
    void addBook(Book book); // function to add book to inventory
    void removeBook(std::string title); // function to remove book from inventory
    int searchByTitle(std::string title); // funciton to look for book by title
    void checkOutBook(Book *book); // function to check out book
    void checkInBook(Book *book); // function to check in book
}; //END Inventory


#endif /* Inventory_hpp */

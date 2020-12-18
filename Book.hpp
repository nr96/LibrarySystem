//
//  Book.hpp
//  Library
//
//  Created by Nick Rosas on 12/5/20.
//  Copyright © 2020 Nick Rosas. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <iostream>

class Book
{
private:
    //Define Book properties
    int ID; // ID of book
    std::string Title; //Title of Book
    std::string Author; // Author of Book
    bool CheckedOut; // Checkout status of Book
    
public:
    //Define constructors
    Book();
    Book(std::string title, std::string author);
    
    void checkInOrOut(bool checkOut);
    void displayBookInfo();
    bool isCheckedOut();
    void setBookID(int id);
    
    // Overload "=" operator so books can be compared
    bool operator==(const Book &book) const
    {
        if(Title.compare(book.Title) == 0 )
            return true;
        else
            return false;
    }//END operator==
    
};//END Book

#endif /* Book_hpp */



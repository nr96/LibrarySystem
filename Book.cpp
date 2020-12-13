//
//  Book.cpp
//  Library
//
//  Created by Nick Rosas on 12/5/20.
//  Copyright © 2020 Nick Rosas. All rights reserved.
//

#include "Book.hpp"


Book::Book() { }//END Book()

Book::Book(std::string title, std::string author)
{
    Book::Title = title; // init book title
    Book::Author = author; //init book author
    Book::CheckedOut = false;
}//END Book(id, string title, string author)

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

void Book::checkInOrOut(bool checkOut)
{
    CheckedOut = checkOut;
}//END checkInOrOut()

void Book::displayBookInfo()
{
    std::cout << ID << "\t" << Title << "\t" << Author << std::endl;
}//END displayBookInfo()

bool Book::isCheckedOut()
{
    return CheckedOut;
}//END isCheckedOut

void Book::setBookID(int id)
{
    ID = id;
}//END setBookID

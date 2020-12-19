//
//  User.hpp
//  Library
//
//  Created by Nick Rosas on 12/19/20.
//  Copyright © 2020 Nick Rosas. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>
#include "Role.hpp"
class User
{
public:
    int ID;
    std::string userName;
    std::string firstName;
    std::string lastName;
    Role Role;
    
    // Overload "=" operator so usernames can be compared
    bool operator==(const User &user) const
    {
        if(userName.compare(user.userName) == 0 )
            return true;
        else
            return false;
    }//END operator==
    
};//END class User
#endif /* User_hpp */

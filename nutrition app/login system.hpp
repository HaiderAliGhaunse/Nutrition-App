//
//  login system.hpp
//  nutrition app
//
//  Created by Haider Ghaunse on 28/02/2022.
//
#include <string>
#ifndef login_system_hpp
#define login_system_hpp

#include <stdio.h>

int login();
bool IsLoggedIn();

struct user{
    int age;
    float weight;
    float height;
    float daily_calories;

};
extern user a;

void bmi (std::string username);
void update(std::string username);

#endif /* login_system_hpp */


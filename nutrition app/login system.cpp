//
//  login system.cpp
//  nutrition app
//
//  Created by Haider Ghaunse on 28/02/2022.
//

#include "login system.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "main.hpp"

using namespace std;
/*
 user class using username
 weight
 height
 age
 goal
  */
user a;
void bmi (string username){
    string x;
    int option;
    int bmi = a.weight / (a.height*a.height);
    if(bmi < 18.5){
        x = "You are underweight";
    }
    else if (bmi >= 18.5 && bmi < 25){
        x = "You are in the normal range";
    }
    else if (bmi >=25 && bmi <30){
        x = "You are overweight";
    }
    else if(bmi >= 30){
        x = "You are obese";
    }
    cout << "your bmi is "<<bmi<<" " << x <<endl;
    cout<<"Type a number to continue ";
    cin >> option;
    
    menu(username);
    
    
};
int track_calories(string username,int calories){
    ofstream file;
    file.open ("calories " + username + ".txt");
    file << calories;
    file.close();
    return 0;
};
void goal(string username,float weight);
int details(string username){
    int age;
    float weight;
    float height;
    cout << "enter your age ";
    cin >> age;
    cout << "enter your weight in kg ";
    cin >>  weight;
    cout << "enter your height in m ";
    cin >>  height;
    
    ofstream file;
    file.open ("data_reg\\" + username + ".txt");
    file << age << endl << weight <<endl <<height<<endl ;
    file.close();
    goal(username,weight);
    return 0;

}
void redetails(string username,int age, float weight,float height,float daily){
    ofstream file;
    file.open ("data_reg\\" + username + ".txt");
    file << age << endl << weight <<endl <<height<<endl <<daily <<endl ;
    file.close();
    menu(username);
};

void update(string username){
    int option;
    int age = a.age;;
    float weight = a.weight;
    float height = a.height;
    float daily = a.daily_calories;
    cout << " 1 - update your age \n\n 2 - update your weight \n\n 3 - update your height \n\n 4 - change your goals "<<endl;
    cin >> option;
    if(option == 1){
        cout << "What is your age ?"<<endl;
        cin >> age;
        a.age = age;
        redetails(username, age, weight, height, daily);
    }
    else if (option == 2 ){
        cout << "What is your weight in kg ?"<<endl;
        cin >> weight;
        a.weight = weight;
        redetails(username, age, weight, height, daily);
    }
    else if (option == 3 ){
        cout << "What is your height in m ?"<<endl;
        cin >> height;
        a.height = height;
        redetails(username, age, weight, height, daily);
    }
    else if (option == 4 ){
        ofstream file;
        file.open ("data_reg\\" + username + ".txt");
        file << age << endl << weight <<endl <<height<<endl ;
        file.close();
        goal (username,weight);
        menu(username);
    }
    
}

void rep_det(string username){
    ifstream fin("data_reg\\" + username + ".txt");

        int age;
        float weight;
        float height;
        int calories;
            while (fin >> age >> weight >> height >>calories) //did this with help as written //in the decloration
        {
            
            a.age = age;
            a.weight = weight;
            a.height = height;
            a.daily_calories = calories;
        }
}
void goal(string username,float weight){
    
    int daily_calories;
    float maintenance = (weight * 2.20462) * 15;
    int gain;
    int lose;
    int goal_weight;
    cout << endl << "type 1 if you want to gain weight"<<endl<<"type 2 if you want to lose weight"<<endl<<"type 3 if you want to maintain weight"<<endl;
    cin >>  goal_weight ;
    if(goal_weight == 1){
        cout << "type 1 if you want to gain 1 pound every week "<<endl<<"type 2 if you want to gain  1 pound every 2 weeks " <<endl;
        cin >> gain ;
        if(gain == 1){
            daily_calories = maintenance + 500 ;
            fstream myfile;
            myfile.open("data_reg\\" + username + ".txt",ios::app);
                myfile<< daily_calories<< endl;
            track_calories(username,daily_calories);
        }
        else if(gain == 2){
            daily_calories = maintenance + 250 ;
            fstream myfile;
            myfile.open("data_reg\\" + username + ".txt",ios::app);
                myfile<< daily_calories<< endl;
            track_calories(username,daily_calories);
        }
    }
    if(goal_weight ==2){
        cout << "type 1 if you want to lose 1 pound every week"<<endl  <<"type 2 if you want to lose  1 pound every 2 weeks "<<endl;
        cin >> lose ;
        if(lose == 1){
            daily_calories = maintenance - 500 ;
            fstream myfile;
            myfile.open("data_reg\\" + username + ".txt",ios::app);
                myfile<< daily_calories<< endl;
            track_calories(username,daily_calories);
        }
        else if(lose == 2){
            daily_calories = maintenance - 250 ;
            fstream myfile;
            myfile.open("data_reg\\" + username + ".txt",ios::app);
                myfile<< daily_calories<< endl;
            track_calories(username,daily_calories);
        }
    }
    if(goal_weight == 3){
        cout << "your calories goal have been changed to maintain your weight";
            daily_calories = maintenance;
        fstream myfile;
        myfile.open("data_reg\\" + username + ".txt",ios::app);
            myfile<< daily_calories<< endl;
        track_calories(username,daily_calories);
    }
    
};



bool IsLoggedIn(){ //did this with help as written in the decloration
    string username, password, un, pw;
    cout << "Enter username ";
    cin >> username;
    cout << "Enter password ";
    cin >> password;
    ifstream read ("data\\" + username + ".txt");
    getline(read,un);
    getline(read,pw);
    
    if (un == username && pw == password){
        rep_det(username);
        menu(username);
        return true;
    }
    else{
        return false;
    }
}
int login(){ //did this with help as written in the decloration
    int choice;
    cout <<endl<<"1:register"<<endl << "2:login"<<endl;
    choice = wrong_data();
    if (choice == 1){
        string username,password;
        cout << "select a username ";
        cin >> username;
        cout << "select a password ";
        cin >> password;
        ofstream file;
        file.open ("data\\" + username + ".txt");
        file << username << endl << password ;
                file.close();
        details(username);
        login();
    }
    if (choice == 2){
        bool status = IsLoggedIn();
        if (!status){
            cout << "an error has occured"<<endl;
            system("PAUSE");
            return 0;
            ;
        }
        else{
            cout << "Successful login"<<endl;
            system("PAUSE");
            return 1;
            ;
        }
    }
    return 0;
}






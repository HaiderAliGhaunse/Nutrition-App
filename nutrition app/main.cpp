//
//  main.cpp
//  nutrition app
//
//  Created by Haider Ghaunse on 08/02/2022.
//
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include "login system.hpp"
#include "main.hpp"

void food(string food_time, string username , int opt);

void menu(string username);

int wrong_data(){//did this with help as written in the decloration
    int option =0;
    while (std::cout << "Enter a number " && !(std::cin >> option)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid input; please re-enter.\n";
    }
    return option ;
}

void reset(string username){
    ifstream fin("data_reg\\" + username + ".txt");

        int age;
        float weight;
        float height;
        int calories;
            while (fin >> age >> weight >> height >>calories)
        {
            
            ofstream file;
            file.open ("calories " + username + ".txt");
            file << calories;
            file.close();
            fstream myfile;
            myfile.open("calories" + username + ".txt" ,ios::app);
            if(myfile.is_open()){
                time_t tt; //did this with help as written in the decloration
                struct tm * ti;
                time (&tt);
                ti = localtime(&tt);
                
                myfile << asctime(ti)<< "You have resetted your calories back to " <<calories<< " calories" <<"\n\n";
                myfile.close();
            }
        }
    menu(username);
    
}
    

void add(string username);

void history(string username){
    string option;
    fstream myfile;
    myfile.open("calories" + username + ".txt", ios::in);
    if(myfile.is_open()){
        string line;
        while(getline(myfile,line)){
            cout << line << endl;
        }
    }
    
    myfile.close();
    cout << "Type something to go back to menu " ;
    cin >> option;
    menu(username);
}

void menu(string username){
    int option = 0;
    cout <<endl<<" 1 - Calculate bmi \n 2 - add calories \n 3 - history \n 4 - reset calories \n 5 - add excercise \n 6 - update details \n 7 - log out \n 8 - exit program "<<endl ;
    option = wrong_data();
    
    if(option == 1){
        bmi(username);
    }
    else if (option == 2){
        add(username);
    }
    else if (option == 3){
        history(username);
    }
    else if (option ==4 ){
        reset(username);
    }
    else if(option == 5){
        food("excercise", username, 2);
    }
    else if(option == 6){
        update(username);
    }
    
    else if (option == 7){
        int valid = 0;
        while (valid != 1){
            valid = login();
        }
        }
    }
int print_Cal(string username){
    ifstream fin("calories " + username + ".txt");
 
        int calories;
            while (fin >> calories )
        {
            return calories;
        }
    return 0;
}

int add_Cal(string username, int cal){
    int calories;
    calories = print_Cal(username);
    calories -= cal;
    ofstream file;
    file.open ("calories " + username + ".txt");
    file << calories;
    file.close();
    return calories;
}

void food(string food_time, string username , int opt){
    string food;
    int cal = 0;
    int calories;
    string option;
    string activity;
    if(opt ==1){
        cout << "what food did you eat for "<< food_time << " ";
                cin >>  food;
                cout<< "How many calories was in "<< food<< " " ;
                cin >> cal;
    }
    if(opt == 2){
        cout << "What excercise did you do ";
        cin >> activity ;
        cout << "How many calories did you burn ";
        cin >> cal;
        cal = -cal;
        food = activity;
    }
    calories = add_Cal(username, cal);
    
            cout << "You have "<< calories << " calories remaining " <<endl;
    if (calories<0){
        cout << "You have passed your daily calories intake by "<<calories<<" calories";
    }
                cout << "\nType something to proceed ";
                cin >> option;
    
            time_t tt;
            struct tm * ti;
            time (&tt);
            ti = localtime(&tt);
            
            fstream myfile;
            myfile.open("calories" + username + ".txt" ,ios::app);
            if(myfile.is_open()){
                myfile << asctime(ti)<< food_time << " "<< food << " "<< cal<< " \n" <<calories<< " remaining" <<"\n\n";
                myfile.close();
            }

            menu(username);
        }


void add(string username){
    
    int choice;
    cout << " 1 - Breakfast \n 2 - Lunch \n 3 - Dinner \n 4 - Snacks \n 5 - Back to menu"<<endl;
    choice = wrong_data();
    if (choice == 1){
        food ("breakfast" , username,1);
    }
    else if (choice == 2){
        food("Lunch", username,1);
    }
    else if (choice == 3){
        food("Dinner" , username,1);
    }
    else if (choice == 4){
        food("snacks" , username,1);
}
    else if (choice ==5){
        menu(username);
    }
}

int main(int argc, const char * argv[]) {
    int valid = 0;
    while (valid != 1){
        valid = login();
    }
    }



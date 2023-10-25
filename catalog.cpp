#include <iostream>  //includes the given library
#include <fstream>
#include <ctime>  //includes the given library
#include <cmath>  //includes the given library
#include <cstdlib>  //includes the given library
#include <string>  //includes the given library
#include <string.h> //includes the given library
#include <stdlib.h> //includes the given library
#include <typeinfo>
#include "catalog.h"
using namespace std;


//returns a 1 if the code detects an effect of death or poison in the spell struct for any spell
int hide_bad_spells(spell * spells, int num_spells){
    for (int i = 0; i < num_spells; i++){
        if((spells[i].effect == "death" ) || (spells[i].effect == "poison")){
              return 1;
        }
    }
    return 0;
}

//
int get__int_input (string prompt) {
  bool error;
  string s;
  do {
    error = false;
    cout << prompt;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (!(s.at(i) >= '0' && s.at(i) <= '9')) {
        cout <<"\nError: invalid input, please enter an integer value" << endl;
        error = true;
        break;
      }
    }
  } while(error);
  return atoi(s.c_str());
}


int is_student(wizard * wizards, int wiz_idx){
    if (wizards[wiz_idx].position_title == "Student"){
        cout << "\nStudent Login, restrictions applied" << endl;
        return 1;
    }
    else{
        return 2;
    }
}


float get_avg_success_spells(spell * spells, int num_of_spells){
    float x = 0.0;
    for (int i = 0; i < num_of_spells; ++i){
		    x +=  spells[i].success_rate;
        //cout << x << endl;
        //cout << endl << spells[i].name << endl << spells[i].success_rate << endl << spells[i].effect << endl;
    }
    return (x / num_of_spells);
}

void assign_avg_success(spellbook * books, int num_of_books){
    for (int i = 0; i < num_of_books; i++){
        books[i].avg_success_rate = get_avg_success_spells(books[i].s, books[i].num_spells);
    }
}


void swap(spellbook *x_inx, spellbook *y_inx){
    spellbook t = *x_inx;
    *x_inx = *y_inx;
    *y_inx = t;
}


void sort_avg_success(spellbook* books, int length, int position){
    assign_avg_success(books, length);
    ofstream filestream;
    if(position == 2){
        int new_length;
        int i, j;
        for (i = 0; i < length-1; i++){
            for (j = 0; j < length-i-1; j++) {
                if (books[j].avg_success_rate < books[j+1].avg_success_rate){
                    swap(&books[j], &books[j+1]);
                }
            }
        }
        string filename;
        int error = 1;
        int choice;
        while(error){
            choice = get__int_input("print (1) or file(2) output? ");
            switch (choice){
                case 1:
                    for (i = 0; i < length; i++){
                        cout << books[i].title  << " " << books[i].avg_success_rate << endl;
                    }
                    error = 0;
                    break;
                case 2:
                    cout << "name of file? " << endl;
                    cin >> filename;
                    filestream.open(filename.c_str());
                    for (i = 0; i < length; i++){
                        filestream << books[i].title << " " << books[i].avg_success_rate << endl;
                    }
                    error = 0;
                    filestream.close();
                    break;
                default:
                    cout << "try again.  wrong input." << endl;
            }
        }
    }
    if(position == 1){
        int new_length;
        int i, j;
        for (i = 0; i < length-1; i++){
            for (j = 0; j < length-i-1; j++) {
                if (books[j].avg_success_rate < books[j+1].avg_success_rate){
                    swap(&books[j], &books[j+1]);
                }
            }
        }
        string filename;
        int error = 1;
        int choice;
        while(error){
            choice = get__int_input("print (1) or file(2) output? ");
            switch (choice){
                case 1:
                    for (i = 0; i < length; i++){
                        if((hide_bad_spells(books[i].s, books[i].num_spells)) != 1){
                            cout << books[i].title  << " " << books[i].avg_success_rate << endl;
                        }
                    }
                    error = 0;
                    break;
                case 2:
                    cout << "name of file? " << endl;
                    cin >> filename;
                    filestream.open(filename.c_str());
                    for (i = 0; i < length; i++){
                      if((hide_bad_spells(books[i].s, books[i].num_spells)) != 1){
                            filestream << books[i].title << " " << books[i].avg_success_rate << endl;
                      }
                    }
                    error = 0;
                    filestream.close();
                    break;
                default:
                    cout << "try again.  wrong input." << endl;
            }
        }
    }
}


void sort_page_numbers(spellbook* books, int length, int position){
    ofstream filestream;
    if(position == 1){
        int i, j;
        for (i = 0; i < length-1; i++){
            for (j = 0; j < length-i-1; j++) {
                if (books[j].num_pages > books[j+1].num_pages){
                swap(&books[j], &books[j+1]);
                }
            }
        }
        string filename;
        int error = 1;
        int choice;
        while(error){
            choice = get__int_input("print (1) or file(2) output? ");
            switch (choice){
                case 1:
                    for (i = 0; i < length; i++){
                        if((hide_bad_spells(books[i].s, books[i].num_spells)) != 1){
                            cout << books[i].title  << " " << books[i].num_pages << endl;
                        }
                    }
                    error = 0;
                    break;
                case 2:
                    cout << "name of file? " << endl;
                    cin >> filename;
                    filestream.open(filename.c_str());
                    for (i = 0; i < length; i++){
                        if((hide_bad_spells(books[i].s, books[i].num_spells)) != 1){
                            filestream << books[i].title << " " << books[i].num_pages << endl;
                        }
                    }
                    error = 0;
                    filestream.close();
                    break;
                default:
                    cout << "try again.  wrong input." << endl;
            }
        }
    }
    if(position == 2){
        int i, j;
        for (i = 0; i < length-1; i++){
            for (j = 0; j < length-i-1; j++) {
                if (books[j].num_pages > books[j+1].num_pages){
                swap(&books[j], &books[j+1]);
                }
            }
        }
        string filename;
        int error = 1;
        int choice;
        while(error){
            choice = get__int_input("print (1) or file(2) output? ");
            switch (choice){
                case 1:
                    for (i = 0; i < length; i++){
                        cout << books[i].title  << " " << books[i].num_pages << endl;
                    }
                    error = 0;
                    break;
                case 2:
                    cout << "name of file? " << endl;
                    cin >> filename;
                    filestream.open(filename.c_str());
                    for (i = 0; i < length; i++){
                        filestream << books[i].title << " " << books[i].num_pages << endl;
                    }
                    error = 0;
                    filestream.close();
                    break;
                default:
                    cout << "try again.  wrong input." << endl;
            }
        }
    }
}


void sort_by_effect(spellbook* books, int length, int position){
    ofstream filestream;
    if(position == 1){
        int i, j;
        for (i = 0; i < length-1; i++){
            for (j = 0; j < length-i-1; j++) {
                if (books[j].num_pages > books[j+1].num_pages){
                swap(&books[j], &books[j+1]);
                }
            }
        }
        string filename;
        int error = 1;
        int choice;
        while(error){
            choice = get__int_input("print (1) or file(2) output? ");
            switch (choice){
                case 1:
                    for (i = 0; i < length; i++){
                        if((hide_bad_spells(books[i].s, books[i].num_spells)) != 1){
                            cout << books[i].title  << " " << books[i].num_pages << endl;
                        }
                    }
                    error = 0;
                    break;
                case 2:
                    cout << "name of file? " << endl;
                    cin >> filename;
                    filestream.open(filename.c_str());
                    for (i = 0; i < length; i++){
                        if((hide_bad_spells(books[i].s, books[i].num_spells)) != 1){
                            filestream << books[i].title << " " << books[i].num_pages << endl;
                        }
                    }
                    error = 0;
                    filestream.close();
                    break;
                default:
                    cout << "try again.  wrong input." << endl;
            }
        }
    }
    if(position == 2){
        int i, j;
        for (i = 0; i < length-1; i++){
            for (j = 0; j < length-i-1; j++) {
                if (books[j].num_pages > books[j+1].num_pages){
                swap(&books[j], &books[j+1]);
                }
            }
        }
        string filename;
        int error = 1;
        int choice;
        while(error){
            choice = get__int_input("print (1) or file(2) output? ");
            switch (choice){
                case 1:
                    for (i = 0; i < length; i++){
                        cout << books[i].title  << " " << books[i].num_pages << endl;
                    }
                    error = 0;
                    break;
                case 2:
                    cout << "name of file? " << endl;
                    cin >> filename;
                    filestream.open(filename.c_str());
                    for (i = 0; i < length; i++){
                        filestream << books[i].title << " " << books[i].num_pages << endl;
                    }
                    error = 0;
                    filestream.close();
                    break;
                default:
                    cout << "try again.  wrong input." << endl;
            }
        }
    }
}


int wizard_login(wizard * wizards, int num_wizards){
    int wiz_id, wiz_idx;
    string wiz_pass;
    int error = 1, error2 = 1;
    while(error){
        wiz_id = get__int_input ("\nPlease enter your id: ");
        for (int i = 0; i < num_wizards; ++i){
		          if(wizards[i].id == wiz_id){
                  wiz_idx = i;
                  //cout << "\nWizard found, hello: " << wizards[wiz_idx].name << endl;
                  error = 0;
                  break;
              }
        }
        if(error){
          cout << "\nThere is no wizard with that ID.";
        }
    }
    while(error2 != 4){
        cout << "Please enter your password: " ;
        cin >> wiz_pass;
        if(wiz_pass == wizards[wiz_idx].password){
            cout << "Password is correct" << endl;
            error2 = 4;
            cout << "\n\nWizard found, hello: " << wizards[wiz_idx].name << endl << "ID: " << wizards[wiz_idx].id << "\nStatus: " << wizards[wiz_idx].position_title << "\nBeard Length: " << wizards[wiz_idx].beard_length << endl;
            return wiz_idx;
            break;
        }
        else{
            error2 ++;
            cout << error2 << endl;
            cout << "\nYou have entered an incorrect passord, you have " << 4 - error2 << " attempts left" << endl;
            if(error2 == 4){
                 cout << R"(

      /b_,dM\__,_
    _/MMMMMMMMMMMm,
   _YMMMMMMMMMMMM(
  `MMMMMM/   /   \   _   ,
   MMM|  _z_ / __/  ( |_|
   YMM/_/# \__/# \    | |_)arry
   (.   \__/  \__/     ___
     )       _,  |    '_|_)
_____/\     _   /       | otter
    \  `._____,'
     `..___(__
              ``-.
                  \           your ran out of attempts....
                   )

            )";
                return 69696969;
                //error2 = 4;
                //break;
            }
        }
    }
}


int get_int(string prompt){
    int x = 0;
    for (int i = 0; i < prompt.size(); i++){
        x += (prompt[i] - 48) * pow(10, (prompt.size() - i - 1));; //prompt.length() -
    }
        return x;
}


bool argc_error_handle(int argc){
    //cout << argc << endl;
    if (argc == 3){
        return 1;
    }
    else{
        cout << "\nError: you have provided the wrong amount off arguments\n" << endl;
        return 0;
    }
}


wizard* create_wizards(int num_wizards){
    wizard *wizards = new wizard[num_wizards];
    return wizards;
}


spell* create_spells(int num_of_spells){
    spell *spells = new spell[num_of_spells];
    return spells;
}


void populate_wizard_data(wizard * wizards, int num_wizards, ifstream & finw){
    for (int i = 0; i < num_wizards; ++i){
		    finw >> wizards[i].name >> wizards[i].id >> wizards[i].password >> wizards[i].position_title >> wizards[i].beard_length; //allocate memory for string array for each book obj
        //cout << endl << wizards[i].name << endl << wizards[i].id << endl << wizards[i].password << endl << wizards[i].position_title << endl << wizards[i].beard_length << endl;
    }
}

void populate_spell_data(spell * spells, int num_of_spells, ifstream & fins){
    for (int i = 0; i < num_of_spells; ++i){
		    fins >> spells[i].name >> spells[i].success_rate >> spells[i].effect; //allocate memory for string array for each book obj
        //cout << endl << spells[i].name << endl << spells[i].success_rate << endl << spells[i].effect << endl;
    }
}


spellbook* create_spellbooks(int num_of_books){
    spellbook *books = new spellbook[num_of_books];
    return books;
}


void populate_spellbook_data(spellbook * books, int num_of_books, ifstream & fins){
    for (int i = 0; i < num_of_books; i++){
		    fins >> books[i].title >> books[i].author >> books[i].num_pages >> books[i].edition >> books[i].num_spells;
		    //books[i].s = new spell [books[i].num_spells]; //allocate memory for string array for each book obj
        //spell* spells = create_spells(books[i].num_spells);
        books[i].s = create_spells(books[i].num_spells);
        //cout << endl << books[i].title << endl << books[i].author << endl << books[i].num_pages << endl << books[i].edition << endl << books[i].num_spells << endl;
			  populate_spell_data(books[i].s, books[i].num_spells, fins);
      //  cout << endl << books[i].title << endl << books[i].author << endl << books[i].num_pages << endl << books[i].edition << endl << books[i].num_spells << endl;
	  }
}


void delete_info(wizard **wizards, spellbook ** books, int num_of_books){

  for (int i = 0; i < num_of_books; i++){

    delete [] (*books)[i].s;
    (*books)[i].s = NULL;
  }
  delete [] *books;
  *books = NULL;

  delete [] *wizards;
  *wizards = NULL;
}

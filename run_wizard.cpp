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

int main(int argc, char**argv){ //main function taking in two arguments
    char* wizards = argv[1]; //argument one is a string of some kind
    char* spellbooks = argv[2]; //argument two is a string of some kind
    int not_end = 1; //variable to potential kill the program
        if(argc_error_handle(argc) == 0){ //conditional that runs a function that checks for errors in the arguments that were inputted
            return 0; //if the error check passes, return a zero which lets the program continue
        }
        else{
            ifstream fins, finw; //creates two file in-out streams, one for the wizard file and one for the spellbooks file
          	fins.open(spellbooks); //opens a file stream based on the name of the string that was inputted as the second argument
            finw.open(wizards); //opens a file stream based on the name of the string that was inputted as ghe first argument
            if (!fins.is_open() || !finw.is_open()){ //tests to see if either of the files arent open
                cout << "Error opening the file to read!" << endl;
          		  return 1; //if they arent open then it also kills the program
          	} //if both files are open then the following code can proceed to run
            string temp_num_books;
          	getline(fins, temp_num_books); //takes the first line of spellbooks.txt and sets that as the string temp_num_books
            int num_of_books = get_int(temp_num_books); //sets the integer value of num_of_books as the converted string->integer value of temp_num_books by using that function
            string temp_num_wizs;
          	getline(finw, temp_num_wizs); //takes the first line of spellbooks.txt and sets that as the string temp_num_wizs
            int num_wizards = get_int(temp_num_wizs);  //sets the integer value of num_wizards as the converted string->integer value of temp_num_wizs by using that function
            //cout << num_of_books << endl;
            spellbook * books = create_spellbooks(num_of_books); //creates a 1D pointer array called books that copies data from the array that is created from the function specified
            populate_spellbook_data(books, num_of_books, fins); //initializes the function that populates the data members of the struct known as spellbooks
            wizard * wizards = create_wizards(num_wizards); //creates a 1D pointer array called wizards that copies data from the array that is created from the function specified
            populate_wizard_data(wizards, num_wizards, finw); //initializes the function that populates the data members of the struct known as wizards
            int wiz_idx = wizard_login(wizards, num_wizards); // creates a variable that stores the return value of the function that checks if the wizard successfully logs into to his/her account
            int not_quit = 1, error = 1;
            int choice;
            if (wiz_idx != 69696969){ //if the wizard_login returns 69696969, that means that the login was unsuccessful, thus not allowing the program to continue, any other reurned value means the login was successful
              int position = is_student(wizards, wiz_idx); //this function checks and returns whether the wizard is a student or a teacher and stores it as int position
                while(not_quit){ //loops until not_quit is set to zero
                    while(error){ //loops until a correct input is made (1, 2, 3, or 4)
                        choice = get__int_input("\nWhich option would you like to choose?\n1. Sort spellbooks by number of pages \n2. Group spells by their effect \n3. Sort spellbooks by average success rate \n4. Quit\n "); //takes in an input for the 4 optionss and checks for errors through the function
                        switch (choice){
                            case 1:
                                sort_page_numbers(books, num_of_books, position);
                                break;
                            case 2:
                                sort_by_effect(books, num_of_books, position);
                                break;
                            case 3:
                                sort_avg_success(books, num_of_books, position);
                                break;
                            case 4: //option 4 ends the program by setting no_quit = 0 and erro = 0 and runs the free memory function
                                not_quit = 0;
                                error = 0;
                                delete_info(&wizards, &books, num_of_books);
                                cout << "Quitting..." << endl;
                                break;
                            default:
                                cout << "try again.  wrong input." << endl;
                        }
                    }
                }
          }
          else{
            delete_info(&wizards, &books, num_of_books);
          }
      }
}

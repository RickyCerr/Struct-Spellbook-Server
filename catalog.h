#include <iostream>  //includes the given library
#include <fstream>
#include <ctime>  //includes the given library
#include <cmath>  //includes the given library
#include <cstdlib>  //includes the given library
#include <string>  //includes the given library
#include <string.h> //includes the given library
#include <stdlib.h> //includes the given library
#include <typeinfo>

using namespace std;

struct wizard {
 string name;
 int id;
 string password;
 string position_title;
 float beard_length;
};


struct spellbook {
 string title;
 string author;
 int num_pages;
 int edition;
 int num_spells;
 float avg_success_rate;
 struct spell *s;
};


struct spell {
 string name;
 float success_rate;
 string effect;
};


int get__int_input (string prompt);
int is_student(wizard * wizards, int wiz_idx);
int get_int(string prompt);
int wizard_login(wizard * wizards, int num_wizards);
float get_avg_success_spells(spell * spells, int num_of_spells);
bool argc_error_handle(int argc);
wizard* create_wizards(int num_wizards);
spellbook* create_spellbooks(int num_of_books);
spell* create_spells(int num_spells);
void populate_wizard_data(wizard * wizards, int num_wizards, ifstream & finw);
void populate_spellbook_data(spellbook * books, int num_of_books, ifstream & fins);
void populate_spell_data(spell *spells, int num_spells, ifstream & fins);
void sort_page_numbers(spellbook books);
void swap(int *x_inx, int *y_inx);
void sort_page_numbers(spellbook* books, int length, int position);
void sort_avg_success(spellbook* books, int length, int position);
void assign_avg_success(spellbook* books, int length);
void delete_info(wizard **, spellbook **, int);
void sort_by_effect(spellbook* books, int length, int position);

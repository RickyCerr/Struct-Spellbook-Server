Name: Richard J Cerrato
ONID: 933 448 473
Section: CS 162-001
Assignment 1, due 6/4/2020

Description:

Welcome to Wizardry Library!  In this program you will be able to log in to your wizardry account using your ID and password. With that you will be given the option to either 

1. Sort spellbooks by number of pages
2. Group spells by their effect
3. Sort spellbooks by average success rate
4. Quit 

This is assuming you enter your user information in correctly. Watch out students! With our awesome system we will be able to detect whether you are a student and deny access to any spells we deem restricted. As for any other wizards, full access to otherwise prohibited spell books will be allowed. 

Instructions:

1) Compile the program with

make clean

make

2) Run the program with

./run_wizard wizards.txt spellbooks.txt

3) You start by entering your ID, should be an integer value. If not, it will reprompt.

4) You then enter your password, if incorrect you will get 2 more chances to enter it before the program quits.

5) The choices before you are:

1. Sort spellbooks by number of pages
2. Group spells by their effect
3. Sort spellbooks by average success rate
4. Quit 


If you select option ONE:

it will prompt you whether you want to have the sorted items printed on the screen 
or if you want it printed on a .txt file

if you chose to have it printed on the .txt file it will prompt you to enter a name for the file

If you select option TWO:

it will prompt you whether you want to have the sorted items printed on the screen 
or if you want it printed on a .txt file

if you chose to have it printed on the .txt file it will prompt you to enter a name for the file

If you select option THREE:

it will prompt you whether you want to have the sorted items printed on the screen 
or if you want it printed on a .txt file

if you chose to have it printed on the .txt file it will prompt you to enter a name for the file

If you select option FOUR:

it will prompt you whether you want to have the sorted items printed on the screen 
or if you want it printed on a .txt file

if you chose to have it printed on the .txt file it will prompt you to enter a name for the file

Limitations:
- You can only see the title and the item sorted, instead of being able to see all the information with it (this is just a simple cout << adjustment but I was following instructions 


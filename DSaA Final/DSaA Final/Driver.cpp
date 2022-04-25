/*
* Ethan Heinlein CIS.2207.502
* Topic 8 Assignment

* Write a program that maintains a database containing data, Name and Birthday of your friends and relatives.
* You will be able to enter, remove, modify or search this data.
* Initially, you can assume that the names are unique.
* The program will be able to save and load the data in a file for use later.

Also, you will need to implement the following functions:

    Enter -- Add a new person to you list.
    Modify -- Change the name or birthday of a person.
    Remove -- Remove a person from your list.
    Search -- Display the information about a given person (unique name).
    Query -- Run a query that displays the people by asking the user to enter a month.
    Print -- List everyone in the database.

*/

#include <iostream>
#include <string>

#include "BinaryNodeTree.h"
#include "Person.h"
using namespace std;

// Method Declarations
void printEntries(Person &item);

int main()
{
    BinaryNodeTree tree;
    //Menu Control Variables
    int menuSelection = -1;
    //Display Menu
    do
    {
        // Print Welcome
        cout << "Welcome to the Family & Friends Birthday Database" << endl;
        cout << "Enter the number by the option to make your selection." << endl;
        // Print Menu
        cout << "| 1  | -- Add person to list" << endl;
        cout << "| 2  | -- Change a person in the list" << endl;
        cout << "| 3  | -- Remove a person in the list" << endl;
        cout << "| 4  | -- Search for a person in the list" << endl;
        cout << "| 5  | -- Find all birthdays in month" << endl;
        cout << "| 6  | -- Print all people in the list" << endl;
        cout << "| 0  | -- Save / Load a list file" << endl;
        cout << "| -1 | -- Quit" << endl;

        //Get Input
        cout << "Enter menu selection: ";
        cin >> menuSelection;
        
        //Process input
        switch (menuSelection)
        {
            case 1: // Add person to list
            {
                //Get person's data
                string newName = "";
                int month = 1; 
                int day = 1;
                int year = 1;
                // -- Name
                cout << "Enter the new person's first name: ";
                cin >> newName;
                // -- Month
                cout << "Enter the persons's birth month number (1-12): ";
                cin >> month;
                if (month > 12 || month < 1) // Only check month, day and year don't matter that much
                {
                    cout << "ERROR: Month not valid" << endl;
                    break;
                }
                month--; // Actually use 0-11 for the Enum, won't make user do confusing stuff
                // -- Day
                cout << "Enter the new person's day of birth: ";
                cin >> day;
                // -- Year
                cout << "Enter the new person's birth year: ";
                cin >> year;

                //Process input to be split later
                string date = to_string(month) + "-" + to_string(day) + "-" + to_string(year);
                Person nPerson = Person(newName, date);
                tree.add(nPerson);
                break;
            }

            case 2: // Change person -- by name
            {
                string toChange = "";
                cout << "Enter the name of the person to change: ";
                cin >> toChange;
                
                break;
            }

            case 3: // Remove person -- by name
            {
                string toRemove = "";
                cout << "Enter the name of a person to remove: ";
                cin >> toRemove;
                try
                {

                }
                catch (NotFoundException e)
                {
                    cout << "ERROR: Entry not found" << endl;
                }
                break;
            }

            case 4: // Search for person -- by name
            {
                string name = "";
                cout << "Enter first name of person to search for: ";
                cin >> name;
                break;
            }

            case 5: // Find all people in a month
            {
                break;
            }

            case 6: // Print everyone in list
            {
                tree.preorderTraverse(printEntries);
                system("pause");
                break;
            }
        }
        //Clear menu
       system("cls");
    } while (menuSelection != -1);

    return 0;
}

void printEntries(Person& item)
{
    cout << item.getName() << " " << item.getBirthday() << endl;
}
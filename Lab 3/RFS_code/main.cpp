
#include "RFS.h"
#include "Student.h"
#include <iostream>
#include "School.h"
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
// Functions header
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
void CleanScreen(void);

int ShowMenu(void);

char againYON();

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
int main() {
    CSchool School("School.db");
    char again; //a flag to indicate do selected option again
    int choice; //user selected option
    bool exit = false; // flag to terminate execution
    while (true) //loop forever
    {
        CleanScreen();
        choice = ShowMenu();
        //show menu and get user option
        switch (choice) //handling user input
        {
            case 1: // Adding a new student to the school
                again = 'Y';
                while (again == 'Y')
                    //loop as user wants to continue
                {
                    if (School.AddNewStudent()) {
                        cout << "a New Student has been"
                             << " successfully added\n";
                        cout << "Do you want to add another"
                             << " (y/n)?";
                        again = againYON();
                    } else //failed to add a student to library
                    {
                        again = 'N';
                        cout << "couldn't add a New Student\n";
                        cout << "Press any key to continue";
                        int ii;
                        cin >> ii;
                    }
                }
                break;
            case 2: //remove a student from the school
                again = 'Y';
                while (again == 'Y') {
                    if (School.RemoveStudent()) {
                        cout << "a Student has been"
                             << " successfully removed\n";
                        cout << "Do you want to remove another"
                             << "(y/n)?";
                        again = againYON();
                    } else // failed to remove a student from school
                    {
                        again = 'N';
                        cout << "couldn't remove a Student\n";
                        cout << "Press any key to continue";
                        int ii;
                        cin >> ii;
                    }
                }
                break;
            case 3: // modify student data
                again = 'Y';
                while (again == 'Y') {
                    if (School.ModifyStudent()) {
                        cout << "a Student has been"
                             << " successfully modified\n";
                        cout << "Do you want to modify another"
                             << " (y/n)?";
                        again = againYON();
                    } else // failed to modify student data
                    {
                        again = 'N';
                        cout << "couldn't modify a Student\n";
                        cout << "Press any key to continue";
                        int ii;
                        cin >> ii;
                    }
                }
                break;
            case 4: // search for a student by name
                //(the first matched will be displayed)
                again = 'Y';
                while (again == 'Y') {
                    if (School.SearchForStudent()) {
                        cout << "Do you want to search"
                             << " for another (y/n)?";
                        again = againYON();
                    } else // failed to find a matching student name
                    {
                        again = 'N';
                        cout << "couldn't find specified student\n";
                        cout << "Press any key to continue";
                        int ii;
                        cin >> ii;
                    }
                }
                break;
            case 5: // Sort student according to a certain subject
                // results and display students data
                again = 'Y';
                while (again == 'Y') {
                    if (School.Sort()) {
                        cout << "Do you want to do another Sort"
                             << "(y/n)?";
                        again = againYON();
                    } else // failed to sort students
                    {
                        again = 'N';
                        cout << "couldn't do Sort\n";
                        cout << "Press any key to continue";
                        int ii;
                        cin >> ii;
                    }
                }
                break;
            case 6: // terminate execution
                exit = true; //set exit flag
                break;
        }
        // break infinite loop to terminate execution
        if (exit)
            break;
    }
}

/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
char againYON() {
    char again = 0;
    while ((again != 'Y') && (again != 'N')) {
        cin >> again;
        again = toupper(again);
    }
    return again;
}




/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
// Clean Screen Function
// print an empty 25 lines
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
void CleanScreen(void) {
    cin.ignore();
    cout.flush();
    for (int i = 0; i < 25; i++)
        cout << endl;
}
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
// Show Menu Function
// print the menu options and get user input
// return user input to calling function for processing
/*/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*/
int ShowMenu(void) {
    int choice;
    cout << "\t\t\t\t MainMenu\n\n";
    cout << "\t\t\t (1) Add New Student.\n";
    cout << "\t\t\t (2) Remove Student.\n";
    cout << "\t\t\t (3) Modify Student Data.\n";
    cout << "\t\t\t (4) Search for a Student.\n";
    cout << "\t\t\t (5) Sort by Subject Results.\n";
    cout << "\t\t\t (6) Exit.\n\n";
    cout << "\t\t Enter your choice (1...6) : ";
    cin >> choice;
    return choice;
}

#include <iostream>
#include <thread>
#include "password_condition.h"
#include "generator.h"
#include "string_playground.h"

using namespace std;

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    cout << "Password Generator Chrono I" << "\n";
    //Pointer to password storage
    char* pwStorageP = nullptr;
    //tester
    //int setSize = 0;

    int pwLength = 0;
    bool specialCharState = false;
    bool numState = false;
    bool upperState = false;
    bool lowerState = true;

    //Menu variables
    int choice;
    bool quit = false;

    while (!quit) {
        bool input = true;
        
        cout << "Your password length is now: " << pwLength << "\n\n";
        cout << "1. Set password length" << "\n";
        cout << "2. Toggle special characters" << "\n";
        cout << "3. Toggle numbers" << "\n";
        cout << "4. Toggle uppercase letters" << "\n";
        cout << "5. Toggle lowercase letters" << "\n";
        cout << "6. Generate password" << "\n";
        cout << "7. Help" << "\n";
        cout << "8. Quit" << "\n\n";

        while (input) {
            cout << "Choice: ";
            cin >> choice;
            cout << "\n";

            switch (choice) {
            case 1:
                cout << "Password Length: ";
                cin >> pwLength;
                cout << '\n';
                system("cls");
                setPwLength(pwLength, &pwStorageP);
                
                //Menu management
                input = false;
                break;
            case 2:
                system("cls");
                specialCharToggle(&specialCharState);
                displayToggle(specialCharState, numState, upperState, lowerState);
                input = false;
                break;
            case 3:
                system("cls");
                numToggle(&numState);
                displayToggle(specialCharState, numState, upperState, lowerState);
                input = false;
                break;
            case 4:
                system("cls");
                uppercaseToggle(&upperState);
                displayToggle(specialCharState, numState, upperState, lowerState);
                input = false;
                break;
            case 5:
                system("cls");
                lowercaseToggle(&lowerState);
                displayToggle(specialCharState, numState, upperState, lowerState);
                input = false;
                break;
            case 6:
                if (pwLength <= 0) {
                    cout << "Password length must be at least one.\n\n";
                    input = false;
                    break;
                }
                system("cls");
                //cout << "Please wait for " << pwLength / 2 << " seconds.\n";
                //this_thread::sleep_for(chrono::seconds(pwLength / 2));
                generate(pwLength, specialCharState, numState, upperState, lowerState, pwStorageP);
                system("cls");
                cout << "Here is your newly generated password: ";
                str_display(pwStorageP);
                cout << '\n';
                input = false;
                break;
            case 7:
                system("cls");
                //Testing purposes
                //gen_set(specialCharState, numState, upperState, lowerState, &setSize);
                cout << "Special characters: !\"#$ % &'()*+,-./:;<=>?@[\]^_`{|}~" << "\n";
                cout << "Numbers: 0123456789" << '\n';
                cout << "Uppercase letters: ABCDEFGHIJKLMNOPQRSTUVWXYZ" << "\n";
                cout << "Lowercase letters: abcdefghijklmnopqrstuvwxyz" << "\n\n";
                cout << "How to use:\n";
                cout << "1. Set the length of the password\n" << "   If you want to generate a password with four characters, e.g. aB3*, then input 4.\n";
                cout << "2. Toggle the types of characters for your password, lowercase is enabled by default.\n";
                cout << "3. Once you are done, choose \"Generate password\". Your password will then be generated.\n\n";
                
                input = false;
                break;
            case 8:
                quit = true;
                input = false;
                free(pwStorageP);
                break;
            default:
                cout << "Invalid choice, choose again." << "\n\n";
            }
        }
    }
    return 0;
}
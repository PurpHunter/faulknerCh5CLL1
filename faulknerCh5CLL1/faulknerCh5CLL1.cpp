
/*************************************
* B. Faulkner
* 12/17/24
* V 1.0.0
**************************************/

#include <iostream>
#include <random>
#include <limits>  
#include <cctype>  
using namespace std;

int main() {
    random_device rand_dev;
    mt19937 gen(rand_dev());
    uniform_int_distribution<short> dist1(1, 13);
    bool userRestart = true;
    int menuChoice;
    string horseName;
    bool isUnderWeight = false;
    bool isOverWeight = false;
    int horseClassification;
    int horseWeight;
    cout << "Welcome to the C++ Comprehensive Loop Lab 1.\n";
    do {
        do {
            cout << "Please enter a number from the menu.\n1) Feed Calculator.\n2) Exit.\n";
            while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 2) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error in your Input\n";
                cout << "Please enter your number (1 or 2):\n";
            }
            switch (menuChoice)
            {
            case 1:
                cout << "Please enter your horse's name.\n";
                cin >> horseName;
                cout << "Please enter " << horseName << "'s classification (Ex. Light, Large, Draft)\n1) Light Riding Horse.\n2) Large Riding Horse. \n3) Draft Horse.\n";
                while (!(cin >> horseClassification) || cin.fail() || horseClassification < 1 || horseClassification > 3) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.sync();
                    cout << "Error in your Input\n";
                    cout << "Please enter your number\n1) Light Riding Horse.\n2) Large Riding Horse. \n3) Draft Horse.\n";
                }
                cout << "Please enter " << horseName << "'s weight. (lbs.)\n";
                while (!(cin >> horseWeight) || cin.fail() || horseWeight < 700 || horseWeight > 3500) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.sync();
                    cout << "Error in your Input\n";
                    cout << "Please enter a number. (The horse weight must be 700 - 3500 lbs.)\n";
                }
                isUnderWeight = false;
                isOverWeight = false;
                if (horseClassification == 1) {  // Light Riding Horse
                    if (horseWeight < 840) {
                        isUnderWeight = true;
                    }
                    else if (horseWeight > 1200) {
                        isOverWeight = true;
                    }
                }
                else if (horseClassification == 2) {  // Large Riding Horse
                    if (horseWeight < 1110) {
                        isUnderWeight = true;
                    }
                    else if (horseWeight > 1300) {
                        isOverWeight = true;
                    }
                }
                else if (horseClassification == 3) {  // Draft Horse
                    if (horseWeight < 1500) {
                        isUnderWeight = true;
                    }
                    else if (horseWeight > 2200) {
                        isOverWeight = true;
                    }
                }
                if (isUnderWeight) {
                    cout << "Under Weight for your classification.\nWe at Horse Co. say, to feed your horse 3.5 Pounds of feed.\n";
                }
                else if (isOverWeight) {
                    cout << "Over Weight for your classification.\nWe at Horse Co. say, to feed your horse 2.5 Pounds of feed.\n";
                }
                else {
                    cout << "Perfection for your classification.\nWe at Horse Co. say, to feed your horse 3.0 Pounds of feed.\n";
                }
                break;
            case 2:
                break;
            }
        } while (menuChoice != 1 && menuChoice != 2);

        //End Of Program A.k.a Restart
        do {
            cout << "Please enter 1 to start the program again or 0 to exit: ";
            cin >> userRestart;

            while (cin.fail() || (userRestart != 1 && userRestart != 0)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter 1 to start the program again or 0 to exit: ";
                cin >> userRestart;
            }
        } while (userRestart != 1 && userRestart != 0);

    } while (userRestart == 1);

    cout << "\nPress enter to close program.";
    cin.ignore();
    cin.get();

    return 0;
}

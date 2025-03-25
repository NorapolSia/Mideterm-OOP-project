#include <iostream>
using namespace std;
#include "Hospital.h"

int main(){
    srand(time(0));

    Hospital hospital;

    int selection = 0;

    while (selection != 5){
        cout<<"*********************************"<<endl;
        cout << "Hospital Management System" << endl;
        cout<<"*********************************"<<endl;
        cout << "What would you like to do?" << endl;
        cout<<"*********************************"<<endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. View Existing Patients" << endl;
        cout << "3. Treat Patient" << endl;
        cout << "4. Remove Patient" <<endl;
        cout << "5. End Program" << endl;
        
            
        while(true){
            cout << "Selection: ";
            cin >> selection;
            if (cin.fail() || selection < 1 || selection > 5) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid input..." << endl;
            } else {
                break;
            }
        }

        switch (selection) {

        case 1: hospital.addPatient(); break;
        case 2: hospital.displayAll(); break;
        case 3: hospital.treatPatient(); break;
        case 4: hospital.removePatient(); break;
        case 5: cout<<"Exiting program..."<<endl; break;
        default: cout << "Sorry, no matching selection."<<endl;
        }
    }

    return 0;

}

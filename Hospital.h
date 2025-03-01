//#ifndef HOSPITAL_H
//#define HOSPITAL_H
#include <iostream>
#include "Patient.h"
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX 100

class Hospital {

    private:

        Patient patients[MAX];
        int count = 0;

    public:

        void displayPatient(const Patient& p) {
            cout<<"---------------------------------"<<endl;
            cout << "Name: " << p.getName() << endl;
            cout << "Age: " << p.getAge() << endl;
            cout << "Blood Type: " << p.getBlood() << endl;
            cout << "Diagnosis: " << p.getDisease() << endl;
            cout << "Severity level: " << p.getSeverity() << endl;
            cout << "Doctor's Name: " << p.getDoctorName() << endl;
            cout << "Pescription: " << p.getMedicine() << endl;
            cout<<"---------------------------------"<<endl;
        }

        void addPatient() {
            
            if (count >= MAX) {
                
                cout << "Hospital Full!" << endl;
                return;

            }

            Patient* newPatient = new Patient();
            string tempName, tempDisease, tempDoctor, tempMedicine, tempBlood;
            int tempAge, tempSeverity;
            char confirmation;

            cout << "Patient's Name: ";
            cin >> tempName;
            newPatient->setName(tempName);

            validateInt(tempAge, "Patient's Age: ", 150, 0);
            newPatient->setAge(tempAge);

            cout << "Patient's Blood Type: ";
            cin >> tempBlood;
            newPatient->setBlood(tempBlood);

            cout << "Patient's Disease: ";
            cin >> tempDisease;
            newPatient->setDisease(tempDisease);

            validateInt(tempSeverity, "Severity of the Disease (1-100): ", 100, 1);
            newPatient->setSeverity(tempSeverity);

            cout << "Doctor's Name: ";
            cin >> tempDoctor;
            newPatient->setDoctorName(tempDoctor);

            cout << "Pescription: ";
            cin >> tempMedicine;
            newPatient->setMedicine(tempMedicine);
            cout<<endl;

            do {
                cout << "Confirmation: Do you want to save this patient's information? (y/n) " << endl;
                cin >> confirmation;

                if (confirmation == 'y' || confirmation == 'Y') {
                    
                    patients[count] = *newPatient;
                    count++;
                    cout << "Patient's information added successfully!"<<endl;
                    break;

                } else if (confirmation == 'n' || confirmation == 'N'){

                    cout << "Patient's information rejected successfully!"<<endl;
                    break;

                } else {
                    cout<<"Invalid input..."<<endl;
                }
            } while(confirmation != 'y' && confirmation != 'Y' && confirmation != 'n' && confirmation != 'N');
            
            delete newPatient;
        }

        void sortPatient() {

            if (count <= 1) return;

            int i,j;
            int sorted;
            Patient temp;

            for(j=count; j>0; j--){

                sorted=1;

                for(i=0; i<j-1; i++){
                    
                    if (patients[i] < patients[i+1]) {

                        temp = patients[i];
                        patients[i] = patients [i+1];
                        patients[i+1] = temp;

                        sorted = 0;

                    }

                } 
            
                if (sorted == 1)break;
            
            }
        }

        void displayAll() {

            int i;

            sortPatient();
            if (count>0){
                for(i = 0; i < count; i++) {

                    displayPatient(patients[i]);

                }
            } else {
                cout<<"No patient in the Hospital..."<<endl;
            }
        }

        void deletePatient(){
            int i;
            for(i=0; i<count-1; i++){
                patients[i] = patients[i+1];
            }
            count--;
        }
        

        void treatPatient(){
            srand(time(0));
            if(count>0){
                sortPatient();
                int chance = 100 - patients[0].getSeverity();
                int Rchance = rand() % 100 + 1;
                
                if(Rchance <= chance){

                    cout<<patients[0].getName()<<" was sucessfully cured from "<<patients[0].getDisease()<<endl;

                } else {

                    cout<<patients[0].getName()<<" was not sucessfully cured from "<<patients[0].getDisease()<<endl;

                }
                deletePatient();
            } else {
                cout<<"No Patient available..."<<endl;
            }
        }

        void validateInt(int& input, const string& text, int max, int min){
            bool valid = false;
            while(valid == false){
                cout<<text;
                cin>>input;

                if (cin.fail() || input > max || input < min){
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout<<"Invalid input..."<<endl;
                } else {
                    valid = true;
                }
            }

        }

};
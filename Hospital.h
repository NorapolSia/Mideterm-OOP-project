#include <iostream>
 
#include "Patient.h"
 
#include <cstdlib>
 
#include <ctime>

 
using namespace std;
 
class Hospital {
    private: 
        Patient data;
        Patient * head;
        Patient * tail;
        int count;
 
    public: 
        Hospital(){
            head = NULL;
            tail = NULL;
            count = 0;
        }
        ~Hospital() {
            while (head) {
                Patient * temp = head;
                head = head->getNext();
                delete temp;
            }
        }
 
    void displayPatient(const Patient &p) {
        cout << "---------------------------------" << endl;
        cout << "Name: " << p.getName() << endl;
        cout << "Age: " << p.getAge() << endl;
        cout << "Blood Type: " << p.getBlood() << endl;
        cout << "Diagnosis: " << p.getDisease() << endl;
        cout << "Severity level: " << p.getSeverity() << endl;
        cout << "Doctor's Name: " << p.getDoctorName() << endl;
        cout << "Prescription: " << p.getMedicine() << endl;
        cout << "---------------------------------" << endl;
    }
 
    void addPatient() {
        Patient * newPatient = new Patient();
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
 
        cout << "Prescription: ";
        cin >> tempMedicine;
        newPatient->setMedicine(tempMedicine);
 
        cout << "Confirmation: Do you want to save this patient's information? (y/n) ";
        cin >> confirmation;
 
        if (confirmation == 'y' || confirmation == 'Y') {
            if (!head) {
                head = tail = newPatient;
                head->setPrev(NULL);
                head->setNext(NULL);
            } else {
                
                tail->setNext(newPatient);
                newPatient->setPrev(tail);
                newPatient->setNext(NULL);
                tail = newPatient;
            }
            count++;
            cout << "Patient's information added successfully!" << endl;
        } else {
            delete newPatient;
            cout << "Patient's information rejected successfully!" << endl;
        }
    }
 
    void displayAll() {
        if (!head) {
            cout << "No patient in the Hospital..." << endl;
            return;
        }
        sortPatients();
        Patient * temp = head;
        while (temp) {
            displayPatient(*temp);
            temp = temp -> getNext();
        }
    }
 
    void sortPatients(){
        if (!head || !head -> getNext()) return;
        bool sorted;
        do {
            sorted = true;
            Patient * temp = head;
            while (temp->getNext()) {
                if (*temp < *(temp ->getNext())) {
                    swapPatient(temp, temp -> getNext());
                    sorted = false;
                }
                temp = temp -> getNext();
            }
        } while (!sorted);
    }
 
    void deletePatient(string name) {
        if (!head) {
            cout<< "No Patient available..." << endl;
            return;
        }
        Patient * temp = head;
        while (name != temp->getName() && temp){
            temp = temp -> getNext();
        }
        if(!temp){
            cout<<"Patient not found..."<<endl;
            return;
        }
        if (temp == head) {
            head = head->getNext();
            if (head) {
                head->setPrev(NULL);
            } else {
                tail = NULL;
            }
        } else if (temp == tail) {
            tail = tail->getPrev();
            tail->setNext(NULL);
        } else {
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
        }
        delete temp;
        count--;
    }
 
    void treatPatient(){
        
        if (!head) {
            cout << "No Patient available..." << endl;
            return;
        }
        
        sortPatients();
        displayAll();
        string toCure;
        Patient* t = head;

        
        cout<<"Enter Patient name to cure (C/c to cancle): ";
        cin>>toCure;
        if (toCure == "C"||toCure == "c"){
            cout<<"Cancle treatment."<<endl;
            return;
        }
        while (t) {
            if (t->getName() == toCure) {
                int chance = 100 - t->getSeverity();
                int Rchance = rand() % 100 + 1;
                if (Rchance <= chance) {
                    cout<<"<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>"<<endl;
                    cout << t->getName() << " was successfully cured from " << t->getDisease() << endl;
                    cout<<"<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>"<<endl;
                } else {
                    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                    cout << t->getName() << " did not survive " << t->getDisease() << endl;
                    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                }
                deletePatient(toCure);
                return;
            }
            t = t->getNext();
        }
        cout<<"No patient name: "<<toCure<<endl;
    }
        
    
 
    void validateInt(int & input,
        const string & text, int max, int min) {
        bool valid = false;
        while (!valid) {
            cout << text;
            cin >> input;
            if (cin.fail() || input > max || input < min) {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid input..." << endl;
            } else {
                valid = true;
            }
        }
    }



    void swapPatient(Patient * a, Patient * b){
        Patient t;
        t = *a;
        *a = *b;
        *b = t;
    }

    void removePatient(){
        string toRemove;
        if (!head) {
            cout << "No Patient available..." << endl;
            return;
        }
        
        sortPatients();
        displayAll();

        
        cout<<"Enter Patient name to be removed (C/c to cancle): ";
        cin>>toRemove;
        if (toRemove == "C"||toRemove == "c"){
            cout<<"Cancle removal."<<endl;
            return;
        }

        Patient* t = head;
        while (t) {
            if (t->getName() == toRemove) {
                cout<<"##############################################"<<endl;
                cout<<t->getName()<<" was removed from the system..."<<endl;
                cout<<"##############################################"<<endl;
                deletePatient(toRemove);
                return;
            }
            t = t->getNext();
        }
        cout<<"No patient name: "<<toRemove<<endl;
    }



};
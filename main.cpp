#include <iostream>
using namespace std;

#define MAX 100

class Patient {

    private:

        string name;
        int age;
        string disease;
        int severity;
        string doctorName;
        string medicine;
    
    public:
        
        Patient() { //default constructor
        
            name = "N/A";
            age = 0;
            disease = "N/A";
            severity = 0;
            doctorName = "N/A";
            medicine = "N/A";

        }
        
        bool operator<(const Patient& other) { //comparator function for sorting
            if (severity < other.severity) return true;
            else if (severity == other.severity && age < other.age) return true;
            else return false;
        }
        
        //getter functions
        string getName() const { return name; }
        int getAge() const { return age; }
        string getDisease() const { return disease; }
        int getSeverity() const { return severity; }
        string getDoctorName() const { return doctorName; }
        string getMedicine() const { return medicine; }

        //setter functions
        void setName(const string& n) { name = n; }
        void setAge(int a) { age = a; }
        void setDisease(const string& d) { disease = d; }
        void setSeverity(int s) { severity = s; }
        void setDoctorName(const string& doc) { doctorName = doc; }
        void setMedicine(const string& med) { medicine = med; }
};

class Hospital {

    private:

        Patient patients[MAX];
        int count = 0;

    public:

        void displayPatient(const Patient& p) {
            cout << "Name: " << p.getName() << endl;
            cout << "Age: " << p.getAge() << endl;
            cout << "Diagnosis: " << p.getDisease() << endl;
            cout << "Severity level: " << p.getSeverity() << endl;
            cout << "Doctor's Name: " << p.getDoctorName() << endl;
            cout << "Pescription: " << p.getMedicine() << endl;
        }

        void addPatient() {
            
            if (count >= MAX) {
                
                cout << "Hospital Full!" << endl;
                return;

            }

            Patient* newPatient = new Patient();
            string tempName, tempDisease, tempDoctor, tempMedicine;
            int tempAge, tempSeverity;
            char confirmation;

            cout << "Patient's Name: ";
            cin >> tempName;
            newPatient->setName(tempName);

            cout << "Patient's Age: ";
            cin >> tempAge;
            newPatient->setAge(tempAge);

            cout << "Patient's Disease: ";
            cin >> tempDisease;
            newPatient->setDisease(tempDisease);

            cout << "Severity of the Disease (1-100): ";
            cin >> tempSeverity;
            newPatient->setSeverity(tempSeverity);

            cout << "Doctor's Name: ";
            cin >> tempDoctor;
            newPatient->setDoctorName(tempDoctor);

            cout << "Pescription: ";
            cin >> tempMedicine;
            newPatient->setMedicine(tempMedicine);

            displayPatient(*newPatient);

            cout << "Confirmation: Do you want to save this patient's information? (y/n) " << endl;
            cin >> confirmation;

            if (confirmation == 'y' || confirmation == 'Y') {
                
                patients[count] = *newPatient;
                count++;
                cout << "Patient's information added successfully!";

            }
            
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

            for(i = 0; i < count; i++) displayPatient(patients[i]);

        }
};


int main(){

    Hospital hospital;

    int selection, end;

    while (selection != 3){

        cout << "Hospital Management System" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. View Existing Patients" << endl;
        cout << "3. End Program" << endl;
        cout << "Selection: ";
        end = 0;

        do {
            
            cin.ignore(); 
            cin >> selection;

                switch (selection) {

                case 1: hospital.addPatient(); break;
                case 2: hospital.displayAll(); break;
                case 3: break;
                default: {
                    
                    cout << "Input error, please try again: ";
                    end = 1;
                }
            }
        } while (end == 1);
    }

    return 0;

}

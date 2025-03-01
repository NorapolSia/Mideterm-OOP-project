//#ifndef PATIENT_H
//#define PATIENT_H
#include <iostream>
using namespace std;

class Patient {

    private:

        string name;
        int age;
        string disease;
        int severity;
        string doctorName;
        string medicine;
        string bloodType;
    
    public:
        
        Patient() { //default constructor
        
            name = "N/A";
            age = 0;
            disease = "N/A";
            severity = 0;
            doctorName = "N/A";
            medicine = "N/A";
            bloodType = "N/A";

        }
        
        bool operator<(const Patient& other) { //comparator function for sorting
            if (severity < other.severity) return true;
            else if (severity == other.severity && age < other.age) return true;
            else return false;
        }
        Patient& operator=(const Patient& other){
            this->name = other.name;
            this->age = other.age;
            this->disease = other.disease;
            this->severity = other.severity;
            this->doctorName = other.doctorName;
            this->medicine = other.medicine;
            this->bloodType = other.bloodType;

            return *this;
        }
        
        //getter functions
        string getName() const { return name; }
        int getAge() const { return age; }
        string getDisease() const { return disease; }
        int getSeverity() const { return severity; }
        string getDoctorName() const { return doctorName; }
        string getMedicine() const { return medicine; }
        string getBlood() const { return bloodType; }

        //setter functions
        void setName(const string& n) { name = n; }
        void setAge(int a) { age = a; }
        void setDisease(const string& d) { disease = d; }
        void setSeverity(int s) { severity = s; }
        void setDoctorName(const string& doc) { doctorName = doc; }
        void setMedicine(const string& med) { medicine = med; }
        void setBlood(const string& blood) { bloodType = blood; }
};
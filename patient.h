/*
 * patient.h
 *
 *  Created on: May 14, 2021
 *      Author: ANUSHKA
 */

#ifndef PATIENT_H_
#define PATIENT_H_

#include <iostream>
#include<string>
using namespace std;
#define MAX 3

class patient                           //class patient
{
public:
    string name;
    int region;
    int age;
    long int contact;
    int ctscore;
    int o2level;
    int comorbidity;                    //having any other health issues like BP or sugar etc

    friend class hospital;              //class hospital can access members of class patient
    patient()                          //default constructor
    {
        name = "";
        region = 0;
        age=ctscore=o2level=comorbidity=0;
        contact=0;

    }
    void display();
    void accept();
    int IsCritical();                  //to decide whether to allocate ICU or ward
    void erase();                      //erases data and makes them to null/""/0 as required
};



void patient::accept()                  //function definition for accepting details of patient
{
    cout << "Enter details" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter name: ";
    getchar();
    getline(cin,name);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter Contact number : ";
    cin >> contact;
    cout << "Enter CT SCORE: ";
    cin >> ctscore;
    cout << "Enter O2level: ";
    cin >> o2level;
    cout << "Comorbidity (1-yes/0-no): ";
    cin >> comorbidity;
    cout << "--------------------------------------------------" << endl;

}
void patient::display()                   //display details of patient
{
    cout << "------------------------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "--------------------------------------------------" << endl;
}
int patient::IsCritical()           //function to decide home quarantine / hospitalization required wrt accepted conditions
{

    if (ctscore > 9 && o2level < 85 && age>45 || comorbidity == 1)          //hospitalization
    {
        return 1;
    }
    else{
      //home quarantine
        cout << "Taking your factors into consideration,we suggest you to be home quarantined\nPlease consult doctor and take medicines" << endl;
        cout << "Have proper diet and eat lot of fruits\nDo yoga and meditation it helps in fast recovery" << endl;
        cout << "If any sort of pain increases consult your doctor immediately" << endl;
        cout << "Take care!!!!" << endl;
    }
}

void patient::erase() {
    name = "";
    region = 0;
    age = 0;
    contact = 0;
    ctscore = 0;
    o2level = 0;
    comorbidity = 0;
}





#endif /* PATIENT_H_ */



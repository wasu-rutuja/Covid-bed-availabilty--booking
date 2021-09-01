/*
 * hospital.h
 *
 *  Created on: May 14, 2021
 *      Author: ANUSHKA
 */

#ifndef HOSPITAL_H_
#define HOSPITAL_H_

#include <iostream>
#include<string>
#include "patient.h"
using namespace std;
#define MAX 3

class hospital                       //class hospital
{
public:
hospital* next;
    int HId;
    string Hname;
    long int Hphone;
    string address;
    /*-------------*/
    int bedNos;
    int bedsAvailable;
    patient Array[3];               //Array of patient type in a hospital

public:
    hospital()                      //default constructor
    {
        next = NULL;
        bedNos=3;
        bedsAvailable=3;
        HId=Hphone=0;
    }

    int countBed();
    int AVAILhosp();
    void display();
    friend class LinkedList;            //LinkedList class able to access members of hospital class
};


void hospital::display()                //displays details of 1 hospital
{

    cout<<"Hospital name: "<<Hname<<"\tContact no:"<<Hphone<<"\tHospital address"<<address<<endl<<endl;

};


int hospital::countBed(){           //counts available beds in a hospital
    int cnt=0;
    for(int i=0;i<3;i++)
    {
        if(Array[i].name!="")
           cnt++;
    }
    return cnt;
}


/*int hospital::AVAILhosp()  ////check
{
    return bedsAvailable;
}*/





#endif /* HOSPITAL_H_ */

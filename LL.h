/*
 * LL.h
 *
 *  Created on: May 14, 2021
 *      Author: ANUSHKA
 */

#ifndef LL_H_
#define LL_H_

#include <iostream>
#include<string>
#include "hospital.h"
using namespace std;
#define MAX 3

class LinkedList
{                                           //class LinkedList
public:
    hospital* head;
    int totalbed_list;

public:
    LinkedList()
    {                                       //DEFAULT CONSTRUCTOR
        head= NULL;
        totalbed_list=9;
    }
    void create();                          //Creates Linked List of hospitals for Mumbai city
    void create2();                         //Creates Linked List of hospitals for Pune city
    void create3();                         //Creates Linked List of hospitals for Nashik city
    void addhosp();                         //adds hospital to city linked list
    void deletehosp();                      //deletes hospital from city linked list
    int Length();                           //total hosp in list
    void displayList();                     //displays hospital in linked list
    int overall_bedAVAIL();                 // bed availability in entire city linked list
    int checkbedavailable(patient p);       //checks bed availability in a hospital
    int displayHospAvail();
    void display_patient();                 //displays patients in linked list

};


void LinkedList::displayList()              //displays hospital in linked list
{
    hospital* ptr=head;
        while(ptr!=NULL)
        {
          ptr->display();                  //calls display of hospital
          ptr=ptr->next;
        }
}


void LinkedList::display_patient()          //displays patients in linked list
{
    hospital *ptr=head;
    while(ptr!=NULL)
    {
        for(int i=0;i<3;i++)
        {
         ptr->Array[i].display();           //calls display of Patient
        }
        ptr=ptr->next;
    }
}


int LinkedList::overall_bedAVAIL()
{                                                   // bed available in all hospitals in a city linked list
    hospital *ptr=head;
    int total=0;
    while(ptr!=NULL)
    {
        total=total+ptr->bedsAvailable;
        ptr=ptr->next;
    }
  return total;
}


void LinkedList::create()
{                                                   //hardcoded create for mumbai city
    hospital* temp=new hospital();
    temp->Hname="Mumbai Hospital 1";
    temp->HId = 1;
    temp->Hphone = 945678323;
    temp->address = " City Hospital, SaiNath Nagar,Mumbai.";
    temp->bedNos = 3;
    temp->bedsAvailable = 3;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    hospital* temp1=new hospital();
    temp1->Hname="Mumbai Hospital 2";
    temp1->HId = 2;
    temp1->Hphone = 9456783235;
    temp1->address = " City Hospital,Thane,Mumbai.";
    temp1->bedNos = 3;
    temp1->bedsAvailable = 3;

    if (head == NULL)
    {
        head = temp1;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp1;
    }
    hospital* temp3=new hospital();
    temp3->Hname="Mumbai Hospital 3";
    temp3->HId = 4;
    temp3->Hphone = 9456789234;
    temp3->address = " City Hospital, Powai,Mumbai.";
    temp3->bedNos = 3;
    temp3->bedsAvailable = 3;

    if (head == NULL)
    {
        head = temp3;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp3;
    }

}


void LinkedList::create2()
{                                                               //hardcoded create for Pune city
    hospital* temp=new hospital();
    temp->Hname="Pune Hospital 1";
    temp->HId = 1;
    temp->Hphone = 9456783234;
    temp->address = " City Hospital, SaiNath Nagar,pune.";
    temp->bedNos = 3;
    temp->bedsAvailable = 3;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    hospital* temp1=new hospital();
    temp1->Hname="Pune Hospital 2";
    temp1->HId = 2;
    temp1->Hphone = 9456783235;
    temp1->address = " City Hospital,KarveNagar,pune.";
    temp1->bedNos = 3;
    temp1->bedsAvailable = 3;

    if (head == NULL)
    {
        head = temp1;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp1;
    }
    hospital* temp3=new hospital();
    temp3->Hname="Pune Hospital 3";
    temp3->HId = 4;
    temp3->Hphone = 9456789234;
    temp3->address = " City Hospital, kothrud,pune.";
    temp3->bedNos = 3;
    temp3->bedsAvailable = 3;

    if (head == NULL)
    {
        head = temp3;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp3;
    }

}


void LinkedList::create3()
{                                                           //hardcoded create for Nashik city
    hospital* temp=new hospital();
    temp->Hname="Nashik Hospital 1";
    temp->HId = 1;
    temp->Hphone = 9456783234;
    temp->address = " City Hospital, College road,Nashik";
    temp->bedNos = 3;
    temp->bedsAvailable = 3;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    hospital* temp1=new hospital();
    temp1->Hname="Nashik Hospital 2";
    temp1->HId = 2;
    temp1->Hphone = 9456783235;
    temp1->address = " City Hospital,Gangapur road,Nashik";
    temp1->bedNos = 3;
    temp1->bedsAvailable = 3;

    if (head == NULL)
    {
        head = temp1;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp1;
    }
    hospital* temp3=new hospital();
    temp3->Hname="Nashik Hospital 3";
    temp3->HId = 4;
    temp3->Hphone = 9456789234;
    temp3->address = " City Hospital,DGP Nagar,Nashik";
    temp3->bedNos = 3;
    temp3->bedsAvailable = 3;
    if (head == NULL)
    {
        head = temp3;
    }
    else
    {
        hospital* ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp3;
    }
}


void LinkedList::addhosp()
{                                                        //function to add hospital in city hospital list

    totalbed_list=totalbed_list+3;
    hospital* temp = new hospital();
    cout << "enter hospital name : ";
    getchar();
    getline(cin,temp->Hname);
    cout << "enter hospital Id : ";
    cin >> temp->HId;
    cout << "enter phone number : ";
    cin >> temp->Hphone;
    cout << "enter address : ";
    getchar();
    getline(cin,temp->address);
    temp->bedNos = 3;
    temp->bedsAvailable = 3;
    hospital* ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}


void LinkedList::deletehosp()                   //deletes hospital(node) from city(LinkedList)
{
    totalbed_list=totalbed_list-3;
    hospital* ptr = head;
    hospital* prev = ptr;
    int id, flag = 0;
    cout << "Enter the hospital ID to be deleted:" << endl;
    cin >> id;
    if (head == NULL)
    {
        cout << "There is no hospital in the list" << endl;
    }
    else {
        while (ptr != NULL)
        {

            if (ptr->HId == id)
            {

                if (ptr == head)
                {
                    head = head->next;
                    delete ptr;
                }
                else
                {
                    prev->next = ptr->next;
                    ptr->next = NULL;
                    delete ptr;
                }
                flag = 1;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        cout<<"hospital deleted"<<endl;
    }

    if (flag == 0)
    {
        cout << "hospital to be deleted not found"<<endl;
        return;
    }
}


int  LinkedList::checkbedavailable(patient p)               //if available beds in city returns 1
{

        if (overall_bedAVAIL())
        return 1;

        return 0;
}


int LinkedList::displayHospAvail()                      //displaying all the hospitals(nodes) in city(LinkedList) where beds are available
{
    hospital* ptr = head;
    while (ptr != NULL)
    {
        if (ptr->bedsAvailable)
        {
            cout << "Hospital ID is: " << ptr->HId << "   Hospital Phone No is: " << ptr->Hphone << "    Hospital address is: " << ptr->address <<endl;
        }
        ptr = ptr->next;
    }
    cout << endl;
}


int LinkedList::Length() {                              //calculates total number of hospitals(nodes) in city(LinkedList)
    int count = 0;
    hospital* ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    cout << "Total No of hospital are:" << " " << count << endl;
    return count;
}



#endif /* LL_H_ */

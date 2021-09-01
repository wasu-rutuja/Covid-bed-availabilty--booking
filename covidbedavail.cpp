//============================================================================
// Name        : covidbedavail.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include "LL.h"
#include "Queue.h"
using namespace std;
#define MAX 3

void update(queue *waiting,LinkedList *city)                      //update function to discharge and update a patient from waiting list and allocate bed
{
    if(waiting->isempty()==1)
    {
        cout<<"No patient in waiting list"<<endl;
    }
    else if(city->overall_bedAVAIL()==0)
    {
        cout<<"All beds are full."<<endl;
    }
    else if(city->overall_bedAVAIL()>0)
    {
        patient p=waiting->dequeue();
        hospital *ptr=city->head;
        while(ptr!=NULL)
        {
            for(int i=0;i<3;i++)
            {
                if(ptr->Array[i].name=="")
                {
                    ptr->Array[i]=p;
                    cout<<"Update and bed allocated confirmation send to :: "<<ptr->Array[i].name<<endl;
                    ptr->bedsAvailable--;
                    break;
                }
            }ptr=ptr->next;
        }
    }
}


void dischargePatient(queue *waiting,patient p,LinkedList *city)            //patient to discharge patient from hospital and make bed available
{

    int flag=0;
    if(city->overall_bedAVAIL()==city->totalbed_list)
    {
            cout<<"No patient hospitalized"<<endl;
    }
     else
        {
         patient *pt;
        hospital* ptr=city->head;
         while(ptr!=NULL)
         {
            for(int i=0;i<3;i++)
            {
                pt=&(ptr->Array[i]);
                if(pt->name==p.name)
                {
                    pt->erase();
                    ptr->bedsAvailable++;
                    flag=1;
                    cout<<"Patient is discharged"<<endl;
                    update(waiting,city);
                    break;
                }

            }
            ptr=ptr->next;
         }
            if(flag==0)
            {
                cout<<"Patient not found"<<endl;
            }

     }
}


 void bookingbed(LinkedList *city,patient Pt,queue* q1)          //function to book a bed in hospital(node) in city(LinkedList)
 {

      char book;
      cout<<" Do you want to book bed?(Y/N)";
      cin>>book;
       if(book=='Y')
       {
            if(!q1->isempty() && !q1->isfull())
            {
             q1->enqueue(Pt);                                       //if bed not available but waiting list is empty , add patient to waiting list(queue) of the city
            }
            else if(q1->isfull()==1)
            {
             cout<<"Sorry all beds are occupied and waiting list is full"<<endl;       //No bed available , waiting list(queue) of the city also full

            }
            else
            {
                                                               //if bed available no need to go to waiting list(queue)

            hospital*ptr =city->head;
                if(city->overall_bedAVAIL()<=0)
                {
                    q1->enqueue(Pt);                        //if overall beds available=0 -> add patient of waiting list(queue)

                }
                while(ptr!=NULL)
                {

                    if(ptr->bedsAvailable!=0)
                    {

                         ptr->bedsAvailable=ptr->bedsAvailable-1;

                         cout<<ptr->bedsAvailable<<endl;

                        for(int i=0;i<3;i++)
                        {
                            if(ptr->Array[i].name=="")
                            {
                                ptr->Array[i]=Pt;
                                break;
                            }
                        }
                            cout<<"Bed is being allocated to you"<<endl;
                            ptr->display();                                 //display hospital details
                            break;

                    }
                    ptr=ptr->next;
                }
            }
       }
 }

/*-----------------------------------------------------------------------------------*/

void cityzone(patient P,LinkedList *city,queue* wait_list1)
{
     cout<<"Display hospitals with beds available: "<<endl;
     city->displayHospAvail();
     if (P.IsCritical()== 1)
     {
       cout<<"Checking your criticality.............................You require a bed!"<<endl;
       cout<<"Checking for bed availability: "<<endl;                                         //display availability of beds
       cout<<"Total no of beds available in the city are: "<<city->overall_bedAVAIL()<<endl;

       bookingbed(city,P,wait_list1);

     }

   else
   {
       cout << "You need to be Home Quarantine"<<endl;
   }
}

/*------------------------------------------------------------------------------*/

void citizen(LinkedList* city,LinkedList* city2,LinkedList* city3,queue* wait_list1,queue* wait_list2,queue* wait_list3,patient P)      //citizen function
{
    cout << "================================================================================================ " << endl;
    cout << "|  HOPING TO FULLFILL YOUR REQUIREMENT , WE WILL SURELY TRY OUR BEST!                          | " << endl;
    cout << "|  Please consult doctor and take medicines.                                                   |" << endl;
    cout << "|  Have proper diet and eat lots of fruits.                                                    |" << endl;
    cout << "|  Do Yoga and meditation , it helps in fast recovery by creating positive environment .       |" << endl;
    cout << "|  If you find any sort of symptoms consult your doctor immediately.                           |" << endl;
    cout << "|  Take care!!!!                                                                               |" << endl;
    cout << "================================================================================================" << endl;
    cout << endl << endl;

    cout << "Don't worry we'll surely arrange a bed for you.Kindly complete the further procedure" << endl;

    int reply;
    do{
        P.accept();
        cout<<"Enter your region\n1.Mumbai\n2.Pune\n3.Nashik"<<endl;
        cin>>P.region;
        switch (P.region)
        {
        case 1:cityzone(P,city,wait_list1);                     //direct to cityzone function for Mumbai
            break;
        case 2:cityzone(P,city2,wait_list2);                    //direct to cityzone function for Pune
            break;
        case 3:cityzone(P,city3,wait_list3);                    //direct to cityzone function for Nashik
            break;
        default:cout << "Our Services are currently available only in Mumbai ,Pune and Nashik.\nSorry for the inconvenience!" << endl;
            break;

        }
        cout<<"Continue?(citizen)\n1.Yes\t0.No"<<endl;
        cin>>reply;
    } while(reply!=0);
}


void admin(LinkedList* city1,LinkedList* city2,LinkedList* city3,queue* wait_list1,queue* wait_list2,queue* wait_list3,patient P)           //admin function
{
    int area;
    cout<<"Enter your region\n1.Mumbai\n2.Pune\n3.Nashik"<<endl;
    cin>>area;
    LinkedList *city;
    queue* wait;
    if(area==1)
    {
        wait = wait_list1;
        city=city1;
    }
    else if(area==2)
    {
        wait = wait_list2;
        city=city2;
    }
    else if(area==3)
    {
        wait = wait_list3;
        city=city3;
    }
    string auhority_name;
    cout<<"Enter Authority Name: "<<endl;
    cin>>auhority_name;
    string password;
    cout<<"Enter password: "<<endl;
    cin>>password;
    if(password=="doctor")
    {
        int choice;
        do
        {
            int doctor_right;
             cout<<"\n1.Add hospital\n2.Delete hospital\n3.Display patient\n4.List of all hospitals in city\n5.Discharge patient\n0.Exit"<<endl;
             cin>>doctor_right;
            switch(doctor_right){
            case 1:city->addhosp();
                   break;
            case 2:city->deletehosp();
                   break;
            case 3:city->display_patient();
                   break;
            case 4:city->displayList();
                  break;
            case 5:patient dis_patient;
                   cout<<"Enter patient name to Discharge: "<<endl;
                   cin>>dis_patient.name;
                   dischargePatient(wait,dis_patient,city);
                   break;

            }
            cout<<"Continue?(admin) \n1.Yes\t0.No"<<endl;
            cin>>choice;
        }while(choice==1);
    }
    else
    {
        cout<<"Incorrect username or password"<<endl;
    }

}
/*--------------------------------------------------------------------*/
int main()
{
    patient P;
    LinkedList* city=new LinkedList();
    city->create();
    LinkedList* city2=new LinkedList();
    city2->create2();
    LinkedList* city3=new LinkedList();
    city3->create3();
    queue* wait_list1 =new queue();
    queue* wait_list2 =new queue();
    queue* wait_list3 =new queue();
    int in;
    int identity;
    cout << "***********************************************************************************************" << endl;
    cout << "\t\t\t COVID BED AVAILABILITY AND BOOKING SYSTEM\t\t\t" << endl;
    cout << "***********************************************************************************************" << endl;
    do
    {
        cout<<"Enter you identity: \n1.Authority\n2.Citizen\n0.Exit"<<endl;
        cin>>identity;
        switch(identity)
        {
            case 1:cout<<"This is for Admins"<<endl;
                   admin(city,city2,city3,wait_list1,wait_list2,wait_list3,P);
                   break;
            case 2:cout<<"This is for Citizens"<<endl;
                   citizen(city,city2,city3,wait_list1,wait_list2,wait_list3,P);
                   break;
            case 0:cout<<"EXIT!!";
                   break;

        }
        cout<<"Do you want to continue?(main)\n1.Yes\t0.No"<<endl;
        cin>>in;
    }while(in!=0);
    return 0;

}



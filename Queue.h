/*
 * Queue.h
 *
 *  Created on: May 14, 2021
 *      Author: ANUSHKA
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include<string>
#include "patient.h"
using namespace std;
#define MAX 3

class queue                       //class circular queue
{
public:
    patient waitlist[MAX];          // queue using array
    int front;
    int rear;
    queue() {                       //default constructor
        front = -1;
        rear = -1;
    }
    int isfull();
    int isempty();
    void enqueue(patient);
    patient dequeue();
    //void displaywaitlist();

};

int queue::isfull()                     //function definition of isfull
{
    if ((rear+1)% MAX ==front)
        return 1;
    else
        return 0;
}
int queue::isempty()                     //function definition of isempty
{

    if (front==-1 && rear==-1)
        return 1;
    else
        return 0;
}


void queue::enqueue(patient p) {              // adds elements to waiting list queue
    if (isfull() == 1) {
        cout << "SORRY :(  | BEDS AS WELL AS WAITING LIST OCCUPIED|"<<endl;
    }
    else if(isempty()==1)
    {
        front=0;
        rear=0;
        waitlist[rear]=p;
        cout <<endl<< "You are added to waiting list " << endl;
        cout << "-------------------------------------------";
    }
    else
    {
        rear=(rear+1)%MAX;
        waitlist[rear]=p;
        cout << "You are added to waiting list " << endl;
        cout << "-------------------------------------------";

    }
}


patient queue::dequeue()                       // removes elements from waiting list queue
{
    patient ptemp;
    if (isempty() == 1)
        cout << "No patient in waiting list" << endl;
    else if(front==rear)
    {
        ptemp=waitlist[front];
        front=-1;
        rear=-1;
        return ptemp;
    }
    else
    {
        ptemp = waitlist[front];
        front=(front+1)%MAX;
        return ptemp;
    }
}



#endif /* QUEUE_H_ */

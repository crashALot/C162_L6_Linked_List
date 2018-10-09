/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/07/18
** Description: This file contains the associated prototypes required
*               to use circularList.cpp functions and methods.
*********************************************************************/
#ifndef CIRCULARLIST_HPP
#define CIRCULARLIST_HPP
#include <iostream>

class CircularList
{
private:

protected:

    struct QueueNode
    {
        int val;
        QueueNode* next;
        QueueNode* prev;
        QueueNode(int val1, QueueNode* prev1=NULL, QueueNode* next1=NULL)
        {
            val=val1;
            next=next1;
            prev=prev1;
        }
    };
    QueueNode* head;
    
public:

    CircularList();
    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();
    ~CircularList();

};

#endif
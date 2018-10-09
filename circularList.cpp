/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/07/18
** Description: This file contains the methods and functions required
*               to create, edit, and destroy a circular linked list
*********************************************************************/
#include <iostream>
#include <iomanip>
#include "circularList.hpp"

/********************************************************************* 
** Description: CircularList::CircularList()
*               CircularList class default constructor.
*********************************************************************/
CircularList::CircularList()
{
    head=NULL;
}

/********************************************************************* 
** Description: bool CircularList::isEmpty()
*               Checks if the queue is empty. If so, returns true; 
*               otherwise, return false.
*********************************************************************/
bool CircularList::isEmpty()
{
    // if "head" pointr is NULL the list is empty
    if(!head)
    {
        return true;
    }
    // Else if the "head" pointer is not empty there is at least one node in list
    else
    {
        return false;
    }
}

/********************************************************************* 
** Description: void CircularList::addBack(int val)
*               Takes a user-inputted integer, creates a QueueNode 
*               with user-inputted integer, and appends it to the 
*               back of the list.
*********************************************************************/
void CircularList::addBack(int val)
{
    // Determine if list is empty or has node elements
    if (isEmpty())
    {
        // If it's empty, place node in head location
        // Make sure the new node "next" and "prev" pointers reference itself
        head = new QueueNode(val);
        head->next=head;
        head->prev=head;
    }
    // If list is not empty we can add circularly double linked nodes
    else
    {
        QueueNode* tempPtr;
        // Prototype info:
        //      QueueNode(val, head, head->next)
        //                 ^    ^         ^
        //              value  prev      next
        tempPtr=new QueueNode(val, head, head->next); // "head" points to previous node, and "head->next"
                                                        // points to first object in list
        head->next=tempPtr; // "head->next" in previous node must be moved from start of circular list to new object
                            // in front of it
        head=tempPtr; // "head" is pointed at new node
    }
}

/********************************************************************* 
** Description: int CircularList::getFront()
*               Returns the value of the node at the front of the queue.
*********************************************************************/
int CircularList::getFront()
{
    if (isEmpty())
    {
        std::cout << "     ***** The list is empty! Add a number or two! *****" << std::endl;
        std::cout<<std::endl;
        return 0;
    }
    else
    {
        // We need to find the last node added and move one node forward, which will be the start of the circular list
        QueueNode* tempPtr;
        // The big move to the first node in the circular list
        tempPtr=head->next;
        std::cout << "**   Front value is: ";
        return tempPtr->val;
    }
}

/********************************************************************* 
** Description: void CircularList::removeFront()
*               Removes the front QueueNode of the queue and free the 
*               memory.
*********************************************************************/
void CircularList::removeFront()
{
    if (isEmpty())
    {
        std::cout << "     ***** The list is empty! Add a number or two! *****" << std::endl;
        std::cout<<std::endl;
    }
    else
    {
        QueueNode* frontPtr, *secondPtr;
        // We need a pointer to the first node in the list
        frontPtr=head->next;
        // We also need a pointer to the second node in the list, which will soon be first
        secondPtr=frontPtr->next;
        // The second node in the list will no longer have variable "prev" point to the first node, 
        //  instead, it must point to the end of the list
        secondPtr->prev=head;
        // The last element in the list can no longer use variable "next" to point to the first node
        //  now it must point to the second node 
        head->next=secondPtr;
        // What if the first node is the same as the second node? That means there's only one node left
        if(frontPtr==secondPtr)
        {
            // Variable "head" must be set to NULL to inform other functions that no more nodes remain in the list
            head=NULL;
        }
        // Regardless, the first node in the list is deleted
        delete frontPtr;
    }
}

/********************************************************************* 
** Description: void CircularList::printQueue()
*               Traverses through the queue from head using next 
*               pointers, and prints the values of each QueueNode in 
*               the queue.
*********************************************************************/
void CircularList::printQueue()
{
    if (isEmpty())
    {
        std::cout << "     ***** The list is empty! Add a number or two! *****" << std::endl;
        std::cout<<std::endl;
    }
    else
    {
        int counts=1;
        QueueNode* ptrNode=head;
        while (ptrNode->next)
        {
            if (ptrNode->next==head)
            {
                ptrNode=ptrNode->next;
                std::cout << "    " << std::setw(counts) << std::right << ptrNode->val << std::endl << std::endl;
                break;
            }
            else
            {
                ptrNode=ptrNode->next;
                std::cout << "    " << std::setw(counts) << std::right << ptrNode->val << std::endl;
            }
            counts++;
        }
    }
}

/********************************************************************* 
** Description: CircularList::~CircularList()
*               CircularList class destructor. Iterates through 
*               circular list and deletes each node. 
*********************************************************************/
CircularList::~CircularList()
{
    QueueNode* nodePtr = head->next;
    while (nodePtr != head)
    {
        QueueNode* garbage=nodePtr;
        nodePtr=nodePtr->next;
        delete garbage;
    }
    delete head;
}
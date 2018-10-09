/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/07/18
** Description: This file contains the main menu required to 
*               interact with the program.
*********************************************************************/
#include "listMenu.hpp"
#include <iostream>
#include <iomanip>

/********************************************************************* 
** Description: ListMenu::ListMenu()
*               ListMenu class default cnostructor
*********************************************************************/
ListMenu::ListMenu()
{
    std::cout << std::endl << "     ******* Welcome to my queue! *******" << std::endl << std::endl;
    selectionMenu();
}

/********************************************************************* 
** Description: void ListMenu::selectionMenu()
*               Prompts user to enter which function they'd like to
*               execute
*********************************************************************/
void ListMenu::selectionMenu()
{
    int go=1, userSelection;
    while(go)
    {        
        std::cout << "  Please choose from an option below:" << std::endl << std::endl;
        std::cout << "          1. Add a value to the back of queue" << std::endl;
        std::cout << "           2. Display the front value" << std::endl;
        std::cout << "            3. Remove the front node" << std::endl;
        std::cout << "             4. Display the queue's content" << std::endl;
        std::cout << "              5. Exit" << std::endl << std::endl;    
        userSelection=selectionMenuValidate();
        std::cout << std::endl;
        switch (userSelection)
        {
            case 1:
                int userIn;
                std::cout << "**  Please enter a positive integer: " << std::endl << std::endl;
                std::cout << "         > ";
                userIn=validateNumberInput(); 
                std::cout << std::endl;
                list.addBack(userIn);
                break;

            case 2:
                std::cout << list.getFront() << std::endl << std::endl;
                break;
            
            case 3:
                list.removeFront();
                break;
            
            case 4:
                list.printQueue();
                break;
            
            case 5:
                go=exitMenu();
                break;
        }
    }
}

/********************************************************************* 
** Description: void ListMenu::exitMenu()
*               Exit message left to user upon quitting the 
*               program
*********************************************************************/
int ListMenu::exitMenu()
{
    std::cout << std::endl << "    ************ See you again soon! ************" << std::endl << std::endl;
    return 0;
}

/********************************************************************* 
** Description: ListMenu::~ListMenu()
*               ListMenu class destructor
*********************************************************************/
ListMenu::~ListMenu()
{
}
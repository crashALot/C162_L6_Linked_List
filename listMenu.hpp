/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/07/18
** Description: This file contains the associated prototypes required
*               to use listMenu.cpp functions and methods.
*********************************************************************/
#ifndef LISTMENU_HPP
#define LISTMENU_HPP
#include "menuValidate.hpp"
#include "circularList.hpp"

class ListMenu
{
private:
    
    CircularList list;
    
public:
    
    ListMenu();
    void selectionMenu();
    int exitMenu();
    ~ListMenu();

};
#endif
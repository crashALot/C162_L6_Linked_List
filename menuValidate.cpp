/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/07/18
** Description: This file validates user input for a variety of 
*               scenarios
*********************************************************************/
#include "menuValidate.hpp"
#include <string>
#include <iostream>
#include <cmath>

/********************************************************************* 
** Description: int selectionMenuValidate()
*               Limits user input to between 1 and 5
*********************************************************************/
int selectionMenuValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        //std::getline(std::cin, userIn);
        std::cin >> userIn;
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]-'0')>5 || (userIn[0]-'0')<1)
        {
            std::cout << "Please re-enter your choice as an integer less than 6 but greater than 0:" << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int validateNumberInput()
*               Acts as a barrier to incorrect user inputs. Prompts
*               the user for new input if entered value is not a 
*               positive integer
*********************************************************************/
int validateNumberInput()
{
 int runTotal=0, go=1, length;
    do
    {
        std::string userIn;
        std::getline(std::cin, userIn);
        length=userIn.length();
        for (int i=0; i<length; i++)
        {
            if (isdigit(userIn[i]) && !(ispunct(userIn[i])) && !(isspace(userIn[i])))
            {
                // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                runTotal+=pow(10,length-1-i)*(userIn[i]-'0'); // Converts char back to int
                if ((i+1)==length)
                    go=0;
                if (!runTotal)
                {
                    std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 0: " << std::endl;
                    runTotal=0;
                    go=1;
                }
            }
            else
            {
                std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 0: " << std::endl;
                runTotal=0;
                break;
            }   
        }
    } while (go);
    return runTotal;
}
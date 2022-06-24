/*
MIT License

Copyright (c) 2022 m!haly4

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "functionality.hpp"

int main()
{
    int choise;
    std::string strForChoise;
    std::string delimiter = "|____________________________________________________________|\n\n";

    //enum type for better code readability
    enum{ exit, login, noPassword, registerSys };

    mainMenu(strForChoise, choise);
    std::cout << delimiter;

    //all the options
    while(choise > exit)
    {
        if(choise == login)
        {
            //implement the login logic
            mainMenu(strForChoise, choise);
            std::cout << delimiter;
        }
        else if(choise == noPassword)
        {
            //implement the password recovery mode
            mainMenu(strForChoise, choise);
            std::cout << delimiter;
        }
        else if(choise == registerSys)
        {
            //implement the logic of registration
            mainMenu(strForChoise, choise);
            std::cout << delimiter;
        }
        else
        {
            std::cout   << " ____________________________________________________________" << std::endl
                        << "|                                                            |" << std::endl
                        << "|                       Invalid Input                        |" << std::endl
                        << "|____________________________________________________________|" << std::endl;

            mainMenu(strForChoise, choise);
            std::cout << delimiter;
        }
    }


    std::cout   << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "|                   The program is stopped                   |" << std::endl
                << "|____________________________________________________________|" << std::endl;

    return  0;
}

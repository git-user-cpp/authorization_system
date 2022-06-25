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
    std::vector<std::string> dbcon;
    std::string strForChoise;
    std::string email, passwd, bufer;
    std::string delimiter = "|____________________________________________________________|\n\n";

    //enum type for better code readability
    enum{ exit, login, registerSys, noPassword };

    //The username and password can also be read from the file
#ifdef test
    std::cout   << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "|                   Connect to the database                  |" << std::endl
                << "|____________________________________________________________|" << std::endl;
    for(int i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            std::cout   << " ____________________________________________________________" << std::endl
                        << "|                                                            |" << std::endl
                        << "| Enter user's name to connect: ";
        }
        else if(i == 1)
        {
            std::cout   << " ____________________________________________________________" << std::endl
                        << "|                                                            |" << std::endl
                        << "| Enter the password: ";
        }
        else
        {
            std::cout   << " ____________________________________________________________" << std::endl
                        << "|                                                            |" << std::endl
                        << "|              ERROR: Invalid name or password               |" << std::endl
                        << "|____________________________________________________________|" << std::endl;
            break;
        }

        bufer = "";
        getline(std::cin, bufer);
        dbcon.push_back(bufer);
        
        std::cout << delimiter;
    }
#endif

    mainMenu(strForChoise, choise);
    std::cout << delimiter;

    //all the options
    while(choise > exit)
    {
        if(choise == login)
        {
            loginMenu(email, passwd);

            //implement database connection and password hashing (postgresql)
#ifdef test
            connectDB(dbcon);
#endif

            mainMenu(strForChoise, choise);
            std::cout << delimiter;
        }
        else if(choise == registerSys)
        {
            registerMenu(email, passwd);

            //implement database connection and password hashing (postgresql)

            mainMenu(strForChoise, choise);
            std::cout << delimiter;
        }
        else if(choise == noPassword)
        {
            //implement password reset logic
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

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

    std::string email, passwd;

//variables for testing mode
#ifdef test
    std::string dbUserName, dbUserPass;
#endif

    std::string delimiter = "|____________________________________________________________|\n\n";

    //enum type for better code readability
    enum{ exit, login, registerSys, noPassword };

    //The username and password can also be read from the file
    //TESTING MODE MENU
#ifdef test
    std::cout   << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "|                   Connect to the database                  |" << std::endl
                << "|____________________________________________________________|" << std::endl;

    std::cout   << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "| Enter user's name to connect: ";
    getline(std::cin, dbUserName);
    std::cout   << delimiter;

    std::cout   << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "| Enter the password: ";
    getline(std::cin, dbUserPass);
    std::cout   << delimiter;
#endif

//reading login data in user mode
#ifndef test
    std::vector<std::string> log;
    std::fstream input;
    input.open("login.txt", std::ios::in);

    if(!input)
    {
        std::cout << "Can't open the login file" << std::endl;
        return -1;
    }
    else
    {
        std::string bufer;

        //reading the data
        while(!input.eof())
        {
            getline(input, bufer);
            log.push_back(bufer);
        }
        log.shrink_to_fit();

        input.close();
    }

    //string to connect to the database in user mode
    std::string connection_string("host=localhost port=5432 dbname=mydb user=" + log[0] + " password=" + log[1]);
#endif

//string to connect to the database in testing mode
#ifdef test
    std::string connection_string("host=localhost port=5432 dbname=mydb user=" + dbUserName + " password=" + dbUserPass);
#endif

//outputting table in the test mode
#ifdef test
    printDbTable(connection_string);
#endif

    mainMenu(strForChoise, choise);
    std::cout << delimiter;

    //all the options
    while(choise > exit)
    {
        //login functionality
        if(choise == login)
        {
            loginMenu(email, passwd);

            logInFun(connection_string, email, passwd);

            mainMenu(strForChoise, choise);
            std::cout << delimiter;
        }
        //register functionality
        else if(choise == registerSys)
        {
            registerMenu(email, passwd);

            registerFun(connection_string, email, toHex(hashing(passwd)));

            mainMenu(strForChoise, choise);
            std::cout << delimiter;
        }
        //passwword recovering functionality
        else if(choise == noPassword)
        {
            recoverMenu(email, passwd);

            recoverFun(connection_string, email, toHex(hashing(passwd)));

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

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

#include "menu.hpp"

//main menu function
void mainMenu(std::string &str, int &choise)
{
    std::cout   << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "|                         [1] Login                          |" << std::endl
                << "|____________________________________________________________|" << std::endl
                << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "|                        [2] Register                        |" << std::endl
                << "|____________________________________________________________|" << std::endl
                << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "|                  [3] Forgot the password?                  |" << std::endl
                << "|____________________________________________________________|" << std::endl
                << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "|                          [0] Exit                          |" << std::endl
                << "|____________________________________________________________|" << std::endl
                << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "|                       Your choise: ";

    getline(std::cin, str);
    std::stringstream(str) >> choise;
}


//login menu function
void loginMenu(std::string &email, std::string &passwd)
{

    std::cout << "Enter your email: ";
    std::cin >> email;

    std::cout << "Enter your password:";
    std::cin >> passwd;
}
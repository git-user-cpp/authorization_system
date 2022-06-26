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

//function to print the table
void printDbTable(std::string connection_string)
{
    pqxx::connection con(connection_string.c_str());
    pqxx::work wrk(con);
    pqxx::result res = wrk.exec("SELECT * FROM users;");

    if(res.size() < 1)
    {
        std::cout << "An empty table or an error" << std::endl;
    }
    else
    {
        std::cout   << " ____________________________________________________________" << std::endl
                    << "|                                                            |" << std::endl
                    << "| User id |      User email       |       User passwd        |" << std::endl;
        for(int i = 0; i < res.size(); i++)
        {
            std::cout   << "|____________________________________________________________|" << std::endl
                        << "|                                                            " << std::endl
                        << "|    " << res[i][0] << "    |  " << res[i][1] << "  |  " << res[i][2] << std::endl;
        }
        std::cout << "|____________________________________________________________" << std::endl;
    }
}
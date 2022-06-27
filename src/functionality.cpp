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

//function for hashing the password
unsigned int hashing(std::string &password)
{
    unsigned int mult = 4963785;
    unsigned int hashCode;

    //hashing
    for(int i = 0; i < password.length(); i++)
    {
        hashCode = hashCode ^ (password[i]);
        hashCode *= mult;
    }

    return hashCode;
}

//function for converting the hash code into HEX
std::string toHex(unsigned int hashCode)
{
    std::stringstream hash;
    hash << std::hex << hashCode;

    std::string hexHashCode = hash.str();
    for(auto &el : hexHashCode)
    {
        el = toupper(el);
    }

    return hexHashCode;
}

#ifdef test
    //function to print the table in the testing mode
    void printDbTable(std::string &connection_string)
    {
        pqxx::connection con(connection_string.c_str());
        pqxx::work wrk(con);
        pqxx::result res = wrk.exec("SELECT * FROM users;");

        if(res.size() < 1)
        {
            std::cout   << " ____________________________________________________________" << std::endl
                        << "|                                                            |" << std::endl
                        << "|                 An empty table or an error                 |" << std::endl
                        << "|____________________________________________________________|" << std::endl;
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
#endif

//function for reading the data
void logInFun(std::string &connection_string, std::string &email, std::string &passwd)
{
    pqxx::connection con(connection_string.c_str());
    pqxx::work wrk(con);
    
    //check if the user is in the database
    pqxx::result res = wrk.exec("SELECT * FROM users WHERE(usr_email='" + email + "');");

    if(res.size() < 1)
    {
        std::cout   << " ____________________________________________________________" << std::endl
                    << "|                                                            |" << std::endl
                    << "|              Please, register in the main menu             |" << std::endl
                    << "|____________________________________________________________|" << std::endl;
    }
    else
    {
        //password verification
        if(to_string(res[0][2]) == passwd)
        {
            std::cout   << " ____________________________________________________________" << std::endl
                        << "|                                                            |" << std::endl
                        << "|                     You are logged in!                     |" << std::endl
                        << "|____________________________________________________________|" << std::endl;
        }
        else
        {
            std::cout   << " ____________________________________________________________" << std::endl
                        << "|                                                            |" << std::endl
                        << "|                    ERROR: wrong password                   |" << std::endl
                        << "|____________________________________________________________|" << std::endl;
        }
    }
}

//function for input the data into the DB
void registerFun(std::string &connection_string, std::string &email, std::string passwd)
{
    pqxx::connection con(connection_string.c_str());
    pqxx::work wrk(con);

    pqxx::result res = wrk.exec("SELECT * FROM users;");
    int counter = res.size() + 1;   //setting the ID

    std::string id;
    std::stringstream(std::to_string(counter)) >> id;   //converting the ID to a string type

    //writing into the table
    wrk.exec("INSERT INTO users(usr_id, usr_email, usr_passwd) VALUES(" + id + ", '" + email + "', '" + passwd + "');");
    wrk.commit();   //saving changes to the database

    std::cout   << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "| Your password, please save it: " << passwd                    << std::endl
                << "|____________________________________________________________|" << std::endl;
}

//function for recovering passwords
void recoverFun(std::string &connection_string, std::string &email, std::string passwd)
{
    pqxx::connection con(connection_string.c_str());
    pqxx::work wrk(con);

    //changing the password in the database
    wrk.exec("UPDATE users SET usr_passwd = '" + passwd + "' WHERE(usr_email = '" + email + "');");
    wrk.commit();   //saving changes to the database

    std::cout   << " ____________________________________________________________" << std::endl
                << "|                                                            |" << std::endl
                << "| Your password, please save it: " << passwd                    << std::endl
                << "|____________________________________________________________|" << std::endl;
}
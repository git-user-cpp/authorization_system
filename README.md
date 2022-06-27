# Authorization system
:100: This authorization system is implemented in C++ programming language for Linux systems. Created to gain experience with PostgreSql, CMake and password hashing :100:

## ⚠️ LICENSE ⚠️
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

## 💻 How to use this app 💻

1) ⚠️ **The application is designed for Linux, so avoid using other systems or remake the program to avoid bugs.** ⚠️

2) 🗂️ Download *all* files and put them in a one directory.

3) :elephant: Install the latest PostgreSql version and CMake.
    ```
    sudo su
    ```
    ```
    apt-get update
    ```
    ```
    apt-get install postgresql
    ```
    ```
    apt-get install cmake
    ```
    
    - To turn on the PostgreSql
    ```
    service postgresql start
    ```
    
4) :inbox_tray: Install the pqxx library to connect PostgreSql with C++.
    ```
    apt-get install libpqxx-dev
    ```
    
5) :octocat: Create a new PostgreSql user.
    ```
    sudo su - postgres
    ```
    
    - Then type:
    ```
    psql
    ```
    
    - First, set a password for the superuser:
    ```
    ALTER USER postgres WITH PASSWORD 'your password';
    ```
    
    - Create a new user:
    ```
    CREATE USER newuser;
    ```
    ```
    ALTER USER newuser WITH PASSWORD 'your new user password';
    ```
    ```
    ALTER USER newuser WITH SUPERUSER;
    ```
    
    - To check all users:
    ```
    \du
    ```
    
6) :bar_chart: Create the database and the table in it.
    ```
    CREATE DATABASE mydb WITH OWNER newuser;
    ```
    
    - Connect to the DB:
    ```
    \c mydb
    ```
    
    - Create the table:
    ```
    CREATE TABLE users(usr_id INT PRIMARY KEY, usr_email VARCHAR(240) NOT NULL, usr_passwd VARCHAR(240) NOT NULL);
    ```
    
    - Command to check all databases:
    ```
    \l+
    ```
    
    - Query to print the table:
    ```
    SELECT * FROM users;
    ```
    
7) :back: Exit the postgres user.
    - Press `Ctrl+d` few times
    
    - Or type few times:
    ```
    exit
    ```
    
8) :open_file_folder: Create `build` directory near `src`.
    ```
    mkdir build
    ```
    ```
    cd build
    ```
    
9) :spiral_notepad: Create a login.txt file in `build` directory and write the database username and password in separate lines
    - Create:
    ```
    touch login.txt
    ```
    
    - Write via Vim:
    ```
    vim login.txt
    ```
    
    - Press `i` to insert the data into file.
    
    - This is what it should look like:
    ```
    newuser
    newuserpasswd
    ```
    
    - Exit the vim: press `esc` few times then type `:wq` and after that press `Enter`.
    
10) ⚒️ Build the program with CMake in the `build` directory.
    ```
    cmake --build .
    ```
    
11) 💥 Then, in current directory will appear file *"Authorisation"*.
    - If you want to check files in current directory
    ```
    ls -alR
    ```
    
    - Or
    ```
    ls -a -l -R
    ```
    
12) 🌠 Execute the program with command:
    ```
    ./Authorisation
    ```
    
13) 👷 Select the desired function by pressing **1** or **2** or **3** + **Enter**. If you want to close the app, press **0** + **Enter** in main menu.

14) :no_entry: After using the program you can turn off PostgreSql.
    ```
    sudo su
    ```
    ```
    sudo service postgresql stop
    ```

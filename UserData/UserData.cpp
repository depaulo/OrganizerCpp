//************************************************************************
/*file used to create the user and control database, database controls necessary are,
beginDatabase (create user table), endDatabase (close database and save user if requested).
User class have the power to create the necessary tables, and manage the tables by itself.
The class have get methods only, set methods are in the edit functions.
*/

#include "UserData.h"

/*
*****************************************************************************************************
user class
*/
User::User(){
    //Inicialization values for user
	name="";
	password="";
	money=0;
	birthday="";
    financeHorizon=0;
    finances="";
    todo="";
    calendar="";
    completed="";
    db;//create database
    createUsersTable();
    createCalendarTable();
    createFinanceTable();
    createTodoList();
}

void User::closeDatabase(){
    //call user save, pass an argument for saving user or not.
    db.close();
}

void User::createUsersTable(){
    std::ostringstream os;
    os<<"CREATE TABLE USERS( NAME TEXT UNIQUE NOT NULL, ID INTEGER PRIMARY KEY AUTOINCREMENT, PASSWORD TEXT, MONEY REAL, BIRTHDAY NUMERIC, FINANCEHORIZON NUMERIC, DATE NUMERIC NOT NULL );";
    db.createTable(os.str());
}

void User::createFinanceTable(){
    std::ostringstream os;
    os<<"CREATE TABLE FINANCES( ENTVALUE REAL, ENTDATE NUMERIC, ENTPERIOD NUMERIC , ENTDESCRIPTION TEXT, EXPVALUE REAL, EXPDATE NUMERIC, EXPPERIOD NUMERIC, EXPDESCRIPTION TEXT );";//TESTING THE UNIQUE FEATURE ON DATE
    db.createTable(os.str());
}

void User::createTodoList(){
    std::ostringstream os;
    os<<"CREATE TABLE TODOLIST( LISTID INTEGER PRIMARY KEY AUTOINCREMENT, DATEADDED NUMERIC, DATE NUMERIC, STATUS TEXT, DESCRIPTION TEXT, PERIOCITY NUMERIC, PERSON TEXT, IMPORTANCE NUMERIC, TAG TEXT );";//TESTING THE UNIQUE FEATURE ON DATE
    db.createTable(os.str());
}

void User::createCalendarTable(){
    std::ostringstream os;
    os<<"CREATE TABLE CALENDAR( DATE NUMERIC, DESCRIPTION TEXT, WEIGHT NUMERIC, PERIOD NUMERIC, PERSON TEXT, TAG TEXT );";//TESTING THE UNIQUE FEATURE ON DATE
    db.createTable(os.str());

}
void User::editUserData(const char* n, const char* p,double m, const char* b, int f){
    //edit makes all the get and set methods useless.
	name=n;
	password=p;
	money=m;
	birthday=b;
    financeHorizon=f;

}
const char* User::get_name(){
	return name.c_str();
}
const char* User::get_password(){
	return password.c_str();
}
float User::get_money(){
	return money;
}
const char* User::get_birthday(){
	return birthday.c_str();
}
int User::get_financeHorizon(){
	return financeHorizon;
}

const char* User::get_finances(){
    return finances.c_str();
}
const char* User::get_calendar(){
    return calendar.c_str();
}
const char* User::get_todo(){
	return todo.c_str();
}
const char* User::get_completed(){
	return completed.c_str();
}
void User::set_finances(char f){
    finances=f;
}
void User::set_calendar(char c){
    calendar=c;
}
void User::set_todo(char t){
    todo=t;
}
void User::set_completed(char c){
    completed=c;
}

void User::saveToDo(int option,const char* datet, const char* statustemp, const char* descriptiont, const char* periocitytemp, const char* tagt, const char* persont, const char* importancetemp){
    switch(option){
        case 0:{
            std::ostringstream os;
            os<<"INSERT INTO USERS( NAME, PASSWORD, MONEY, BIRTHDAY, FINANCEHORIZON, DATE) VALUES ( '"<<name<<"', '"<<password<<"', "<<money<<", "<<birthday<<", "<<financeHorizon<<", DATETIME('now'));";
            db.addDataRow(os.str());
            }
        break;

        case 1:{
            string datetemp=datet;
            string descriptiontemp=descriptiont;
            string tagtemp=tagt;
            string persontemp=persont;
            std::ostringstream os;
            os<<"INSERT INTO TODOLIST( DATE, STATUS, DESCRIPTION, PERIOCITY, TAG, PERSON, IMPORTANCE, DATEADDED) VALUES ( '"<<datetemp<<"', '"<<statustemp<<"', "<<descriptiontemp<<", "<<periocitytemp<<", "<<tagtemp<<","<<importancetemp<<", DATETIME('now'));";
            db.addDataRow(os.str());
        }
        break;

        case 2:{
            std::ostringstream os;
            os<<"INSERT INTO CALENDAR( DESCRIPTION, WEIGHT, PERIOD, PERSON, TAG, DATE ) VALUES ( '"<<name<<"', '"<<password<<"', "<<money<<", "<<financeHorizon<<", "<<financeHorizon<<", DATETIME('now'));";
            db.addDataRow(os.str());
        }
        break;

        case 3:{
            std::ostringstream os;
            os<<"INSERT INTO FINANCES( ENTVALUE, ENTDATE, ENTPERIOD, ENTDESCRIPTION, EXPVALUE, EXPDATE NUMERIC, EXPPERIOD, EXPDESCRIPTION) VALUES ( '"<<name<<"', '"<<password<<"', "<<money<<", "<<financeHorizon<<", "<<financeHorizon<<","<<financeHorizon<<","<<financeHorizon<<", DATETIME('now'));";
            db.addDataRow(os.str());
        }
        break;

        default:
        break;
    }
}
void User::loadData(int option=0){
     switch (option){
        case 0:{
            std::ostringstream os;
            os<<"SELECT * from USERS;";
            db.getTableData(os.str());
            break;
        }
        case 1:{
            std::ostringstream os;
            os<<"SELECT * from TODOLIST;";
            db.getTableData(os.str());
            break;
        }
        case 2:{
            std::ostringstream os;
            os<<"SELECT * from CALENDAR;";
            db.getTableData(os.str());
            break;
        }
        case 3:{
            std::ostringstream os;
            os<<"SELECT * from FINANCES;";
            db.getTableData(os.str());
            break;
        }
        default:{
            break;
        }
    }
}
User::~User(){
db.close();
}

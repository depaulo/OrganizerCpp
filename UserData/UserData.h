#ifndef __PESSOA_H__
#define __PESSOA_H__
#include "../DataBase/Database.cpp"

class User
{

private:
	float money;
	string name,password,birthday,finances,todo,calendar,completed;
	int financeHorizon;
	Database db;
    void createUsersTable();

public:
    User();
    void closeDatabase();
	void editUserData(const char* n, const char* p,double m, const char* b, int f);
	void createFinanceTable();
    void createTodoList();
    void createCalendarTable();
	const char* get_name();
	const char* get_password();
	float get_money();
	const char* get_birthday();
	int get_financeHorizon();
	const char* get_finances();
	const char* get_calendar();
	const char* get_todo();
	const char* get_completed();
	void set_finances(char f);
	void set_calendar(char c);
	void set_todo(char t);
	void set_completed(char c);
	void saveToDo(int option, const char* datet, const char* statustemp, const char* descriptiont, const char* periocitytemp, const char* tagt, const char* persont, const char* importancetemp);
	void loadData(int option);
	~User();

};
#endif

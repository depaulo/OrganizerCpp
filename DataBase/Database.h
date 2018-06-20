#ifndef __DATABASE_H__
#define __DATABASE_H
#include "../sqlite3.h"
#include <sstream>
using std::string;

 static int callback(void *datas, int argc, char **argv, char **azColName);

class Database
{
public:
	Database(const char* filename);//there are problems on casting, doesnt work
	Database();
    bool open(const char* filename);
    void createTable(string oss);
    void close();
    void addDataRow(string oss);
    void getTableData(string oss);
    void save();
    void load();
    ~Database();
private:
    sqlite3 *database;
    char *zErrMsg;
    sqlite3_stmt * stmt;
	int rc;
	char *sql;
	const char* data;
};



#endif


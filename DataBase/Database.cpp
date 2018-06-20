/*basic database class for my organizer app, open, closes, saves all the files
recovers all the files on opening.8*/
#include "Database.h"



Database::Database(const char* filename){
    sqlite3 *database=NULL;
    const char *zErrMsg = 0;
    sqlite3_stmt *stmt=0;
	int rc=0;
	char *sql = (char *)"";
	open(filename);
}

Database::Database(){
    sqlite3 *database=NULL;
    const char *zErrMsg = 0;
    sqlite3_stmt *stmt=0;
	int rc=0;
	char *sql = (char *)"";
	open("Myorganizer.apf");
}


bool Database::open(const char* filename)
{
	rc = sqlite3_open(filename, &database);
    if( rc )
	{
    	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
    	return false;
    }
    else
	{
    	fprintf(stderr, "Opened database successfully\n");
    	return true;
    }
}
void Database::createTable(string oss){
        const char* statement(oss.c_str());
        rc = sqlite3_exec(database, statement, callback, (void*)data, &zErrMsg);
            if( rc != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                printf("error number: %i check the meaning on sqlite documents. Create Table\n",rc);
                sqlite3_free(zErrMsg);
            }
            else{
                fprintf(stdout, "Table data created successfully\n");
            }
	}

void Database::close(){
	sqlite3_close(database);
	fprintf(stderr, "Database closed successfully\n");
}
void Database::addDataRow(string oss){
	const char* statement(oss.c_str());
   	rc = sqlite3_exec(database, statement, callback, (void*)data, &zErrMsg);
   	if( rc != SQLITE_OK ){
   		fprintf(stderr, "SQL error: %s\n", zErrMsg);
   		printf("error number: %i check the meaning on sqlite documents. Add data\n",rc);
   		sqlite3_free(zErrMsg);
   	}
	else{
   		fprintf(stdout, "Records saved successfully\n");
   	}
}
void Database::getTableData(string oss){
	const char* statement(oss.c_str());
    rc = sqlite3_exec(database, statement, callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){
    	fprintf(stderr, "SQL error: %s\n", zErrMsg);
    	printf("error number: %i check the meaning on sqlite documents. Get Data\n",rc);
    	sqlite3_free(zErrMsg);
    }
	else{
    	fprintf(stdout, "Operation done successfully\n");
    }
}
Database::~Database(){
}




#include "basis.h"
#include "etrdef.h"

bool ConnectMysql(const string & username, const string & password)
{
    mysql_init(&mysql);//

    if (
            !(mysql_real_connect(&mysql,"localhost",username.c_str(),
             password.c_str(),"aams",3306,NULL, 0))
            )
    {
        cout << "Error connecting to database:" + (string) mysql_error(&mysql) << endl;
        return false;
    }
    else
    {
        return true;

    }
}
bool mysql_login(string userlogin,string passlogin)
{
    if( ConnectMysql(userlogin,passlogin)   )
    {
        return true;
    }
    else
    {
        return false;
    }

}
#include "basis.h"
#include "func.h"

MYSQL mysql;
MYSQL_RES *res;//使用资源1
MYSQL_ROW column;//使用资源2
int main()
{
    gettxt();
    menu_aams();
    mysql_close(&mysql);
    return  0;
}
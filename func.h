#ifndef AAMS_FUNC_H
#define AAMS_FUNC_H

#endif //AAMS_FUNC_H

int main();
void menu_aams();
bool ConnectMysql( const string & username, const string & password);
bool mysql_login(string username,string password);
void secgetpasseord(std::string& password);
int getwhichmenu(string username);
void menu_aams_display_1();
void menu_aams_display_2();
void menu_aams_display_3();
void menu_root();
void menu_student(const string& username);
void menu_teacher(const string& username);
int usermessget();
void getstruct(int num);
void showstu(MYSQL &mysql,string username);   //�鿴ѧ��������Ϣ
void showcourse(MYSQL &mysql,string username);
void selectclass (MYSQL &mysql,string username);
void dropclass(MYSQL &mysql, string username);
void showSelectedCourses(MYSQL &mysql, string username);
void showtea(MYSQL &mysql,string username);
void showSelectedstu(MYSQL &mysql, string username);
void addstu(MYSQL &mysql, string username);
void deletestu(MYSQL &mysql, string username);
void addTeacher(MYSQL &mysql);
void deleteTeacher(MYSQL &mysql);
void setCharset(MYSQL &mysql);
int gettxt();
bool startsWith(const std::string& str, const std::string& prefix);
void addStudent(MYSQL &mysql);
void deleteStudent(MYSQL &mysql) ;
void assignCourse(MYSQL &mysql) ;
void updateGrade(MYSQL &mysql, string username);
void showClassmates(MYSQL &mysql, std::string username);

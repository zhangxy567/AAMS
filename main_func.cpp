#include "basis.h"
#include "func.h"
#include "etrdef.h"
char arr1[1000][1000] = { 0 };

struct username_type
{
    char name_arr[20];
    int user_type;
}arr2[1000]={0};


void menu_aams()
{
    menu_aams_display_1();


    int minput =0;
    cin>>minput;
    if(minput == 0 )
    {
        menu_aams_display_2();

        return ;
    }
    else if(minput==1)
    {
        string username="test";
        string password ="test";
        cout<<"********************************"<<endl;
        cout<<"please cin your count message"<<endl;
        cout<<"enter your username "<<endl;
        cin>>username;
        cout<<"********************************"<<endl;

        secgetpasseord(password);
        // cout<<"realpass:"<<password;//Test kink good
        //system("pause");
        cout<<endl;


        if( mysql_login(username, password) )

        {
            // printf("test.");//test point
            // system("pause");
            int swinum =getwhichmenu(username);
            // cout<<"swinum :"<<swinum;//test point
            // system("pause");
            switch (swinum)//此时mysql仍在链接,进入菜单不许重复链接,故不传密码
            {
                case 1:menu_root();break;
                case 2:menu_student(username);break;
                case 3:menu_teacher(username);break;
                default : printf("Program error");break;
            }
        }
        else
        {
            menu_aams_display_3();
            main();

        }

    }
    else
    {
        system("cls");

        cout<<"***  error input         *******"<<endl;
        cout<<"***  please input again  *******"<<endl;

        menu_aams();
    }
}



int getwhichmenu(string testname)
{
    int usernum ;
    usernum = usermessget() + 1;//user number
    getstruct(usernum);
    int i = 0;
    for(;i<=usernum;i++)
    {
        if(testname == arr2[i].name_arr)
        {
            break;
        }
    }
    // cout<<"name"<<arr2[i].name_arr<<endl<<"type:"<<arr2[i].user_type<<endl;//test point
    return arr2[i].user_type;

}



void menu_root() {
    system("cls");
    cout << "Hello ";
    cout << "Welecome to root menu!!!"
         << endl;
    system("pause");
    system("cls");
    while (1) {
        int stuop;
        cout << "请选择功能（1）增加老师信息 （2）删除老师信息  （3）增加学生信息   "<<endl<<"\t"<<"  "<<"（4）删除学生信息  (5)为教师安排课程 (6)退出登录 (7)退出系统" << endl;
        cout << "请输入值 :> ";
        cin >> stuop;
        switch (stuop) {
            case 1: {
                addTeacher(mysql);
                break;
            }
            case 2: {
                deleteTeacher(mysql);
                break;
            }
            case 3:{
                addStudent( mysql);
                break;
            }
            case 4:{
                deleteStudent(mysql);
                break;
            }
            case 5:{
                assignCourse(mysql);
                break;
            }
            case 6:{
                mysql_close(&mysql);
                system("cls");
                main();
                break;
            }
            case 7:{
                system("cls");
                cout<<"********************************"<<endl<<endl;
                cout<<"Successfully exited the system"<<endl<<endl;
                cout<<"********************************"<<endl<<endl;

                system("pause");
                exit(0);
            }
        }
    }
}
void menu_student(const string& username)
{
    system("cls");
    cout<<"Hello student "<<username<<endl;
    cout<<"Welecome to student menu!!!"<<endl;
    system("pause");
    system("cls");
    while(1) {
        int stuop;
        cout << "请选择功能（1）查看个人信息以及本学期你所选课程  "<<endl<<"\t"<<"  "<<"（2）查看本学期所有课程   (3)查看你的班级信息 （4）选课  （5）退课  "
             << endl<<"\t"<<"   "<<"(6) 退出登录 " <<" (7) 退出系统"<<endl;
        cout << "请输入值 :> ";
        cin >> stuop;
        switch (stuop) {
            case 1: {
                showstu(mysql,username);
                break;
            }
            case 2: {
                showcourse(mysql,username);
                break;
            }
            case 4:{
                selectclass( mysql, username);
                break;
            }
            case 5:{
                dropclass(mysql,username);
                break;
            }
            case 6:{
                mysql_close(&mysql);
                system("cls");
                main();
                break;
            }
            case 7:{
                system("cls");
                cout<<"********************************"<<endl<<endl;
                cout<<"Successfully exited the system"<<endl<<endl;
                cout<<"********************************"<<endl<<endl;

                system("pause");
                exit(0);
            }
            case 3:{
                showClassmates(mysql, username);
                break;
            }

        }
    }

}
void menu_teacher(const string& username)
{
    system("cls");
    cout<<"Hello teacher "<<username<<endl;
    cout<<"Welecome to teacher menu!!!"<<endl;
    system("pause");
    system("cls");
    while(1) {
        int stuop;
        cout << "请选择功能（1）查看个人信息  （2）查看本学期你所教的课程信息以及所选你课的学生信息 "<<endl<<"\t"<<" "<<" （3）增加你的课程选课学生信息（4）删除你的你的课程选课学生信息  (5) 修改学生成绩  "<<endl<<"\t"<<"   "<<"(6) 退出登录 (7) 退出系统 " << endl;
        cout << "请输入值 :> ";
        cin >> stuop;
        switch (stuop) {
            case 1: {
                showtea(mysql,username);
                break;
            }
            case 2:{
                showSelectedstu(mysql, username);
                break;
            }
            case 3:{
                addstu( mysql, username);
                break;
            }
            case 4:{
                deletestu(mysql, username);
                break;
            }
            case 5:{
                updateGrade(mysql, username);
                break;
            }
            case 6:{
                mysql_close(&mysql);
                system("cls");
                main();
                break;
            }
            case 7:{
                system("cls");
                cout<<"********************************"<<endl<<endl;
                cout<<"Successfully exited the system"<<endl<<endl;
                cout<<"********************************"<<endl<<endl;

                system("pause");
                exit(0);
            }
        }
    }
}


//another func
void getstruct(int num)
{
    int i = 0;
    for (; i < num; i++)
    {
        sscanf(arr1[i], "%s %d", arr2[i].name_arr, &arr2[i].user_type);
    }

}
int usermessget()
{
    int k ;
    FILE* fp = fopen("user.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
        return 4;
    }

    {
        int i = 0;
        int j = 0;
        {
            char ch;
            while ((ch = (char)fgetc(fp)) != EOF)
            {
                if (ch == '\n')
                {
                    arr1[i][j] = '\0';
                    i++;
                    j = 0;
                }
                else
                {
                    arr1[i][j] = ch;
                    j++;
                }

            }
            arr1[i][j] = '\0';
        }
        k = i;
        //test
        //for (int m = 0; m <= k; m++)
        //{
        //    printf("%s\n", arr1[m]);
        //}
    }
    fclose(fp);
    return k;//杩??琛??-1
}

void menu_aams_display_1()
{

    cout<<"You are using the academic management system!!!"<<endl;
    cout<<"********************************"<<endl;
    cout<<"********** 1  :  login   *******"<<endl;
    cout<<"********** 0  :   exit   *******"<<endl;
    cout<<"********************************"<<endl;
    cout<<" 1 / 0 ->";
}
void menu_aams_display_2()
{
    system("cls");
    cout<<"********************************"<<endl;
    cout<<" AAMS System has closed!!!"<<endl;
    cout<<"********************************"<<endl;
    system("pause");
}
void menu_aams_display_3()
{
    cout<<"********************************"<<endl;
    cout<<" Account or password error!!!"<<endl;
    cout<<"********************************"<<endl;
}


void showstu(MYSQL &mysql, std::string username) {
    setCharset(mysql);
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"); // 防止在命令行中中文乱码

    // 构建查询语句
    std::string query = "SELECT stu.*, sc.* FROM stu JOIN sc ON stu.sno = sc.sno WHERE stu.sno = '" + username + "'";

    // 执行查询
    if (mysql_query(&mysql, query.c_str())) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        mysql_close(&mysql);
        return;
    }

    // 获取查询结果
    res = mysql_use_result(&mysql);
    int num = mysql_num_fields(res);

    // 得到所有列的名字，并且输出
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(15) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // 遍历结果集中所有的行
    while ((row = mysql_fetch_row(res)) != NULL) {
        // 将当前行中的每一列信息读出
        for (int i = 0; i < num; ++i) {
            std::cout << std::left << std::setw(15) << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);
}

void showcourse(MYSQL &mysql, std::string username) {
    setCharset(mysql);
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"); // 防止在命令行中中文乱码

    // 构建查询语句
    std::string query = "SELECT course.* FROM course";

    // 执行查询
    if (mysql_query(&mysql, query.c_str())) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        mysql_close(&mysql);
        return;
    }

    // 获取查询结果
    res = mysql_use_result(&mysql);
    int num = mysql_num_fields(res);

    // 得到所有列的名字，并且输出
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // 打印分隔线
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << std::string(20, '-') << "\t";
    }
    std::cout << std::endl;

    // 遍历结果集中所有的行
    while ((row = mysql_fetch_row(res)) != NULL) {
        // 将当前行中的每一列信息读出
        for (int i = 0; i < num; ++i) {
            std::cout << std::left << std::setw(20) << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);
}

void selectclass(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    int course_con;
    setCharset(mysql);
    std::cout << "请输入你要选修的课程号: ";
    std::cin >> course_con;

    int sno = std::stoi(username); // 将用户名（学生学号）转换为 int

    // 构建插入语句
    //sprintf(sql, "INSERT INTO sc VALUES(%d, %d, NULL)", sno, course_con);
    sprintf(sql, "CALL stu_getmessage(%d, %d)", sno, course_con);

    // 执行查询
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    std::cout << "插入成功" << std::endl;
    std::cout << "你的课表如下：" << std::endl;

    showSelectedCourses(mysql, username); // 调用显示课程表的函数
}

void dropclass(MYSQL &mysql, string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    int course_con;
    setCharset(mysql);
    cout << "请输入你要退选的课程号: ";
    cin >> course_con;

    int sno = stoi(username); // 将用户名（学生学号）转换为 int

    // 构建删除语句
    //sprintf(sql, "DELETE FROM sc WHERE sno = %d AND cno = %d", sno, course_con);
    sprintf(sql, "CALL stu_giveupsc(%d, %d)", sno, course_con);

    // 执行查询
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    cout << "退课成功" << endl;
    cout<<"你的课表如下："<<endl;

    showSelectedCourses(mysql, username); // 如果有显示学生信息的函数，可以在这里调用
}

void showSelectedCourses(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    setCharset(mysql);
    int sno = std::stoi(username); // 将用户名（学生学号）转换为 int

    // 构建查询语句，使用视图简化查询
    sprintf(sql,
            "SELECT sno, sname, cno, cname, grade FROM View_StudentCourses WHERE sno = %d",
            sno);

    // 执行查询
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 获取查询结果
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    int num = mysql_num_fields(res);

    // 输出列名
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // 打印分隔线
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << std::string(20, '-') << "\t";
    }
    std::cout << std::endl;

    // 遍历结果集中所有的行
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < num; ++i) {
            if (row[i] == NULL) {
                std::cout << std::left << std::setw(20) << "未评分" << "\t";
            } else {
                std::cout << std::left << std::setw(20) << row[i] << "\t";
            }
        }
        std::cout << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);
}


void showtea(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    setCharset(mysql);
    int tno = std::stoi(username); // 将用户名（教师号）转换为 int

    // 构建查询语句
    sprintf(sql,
            "SELECT * "
            "FROM teacher "
            "WHERE tno = %d",
            tno);

    // 执行查询
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 获取查询结果
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    int num = mysql_num_fields(res);

    // 输出列名
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // 打印分隔线
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(20) << std::string(20, '-') << "\t";
    }
    std::cout << std::endl;

    // 遍历结果集中所有的行
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < num; ++i) {
            if (row[i] == NULL) {
                std::cout << std::left << std::setw(20) << "NULL" << "\t";
            } else {
                std::cout << std::left << std::setw(20) << row[i] << "\t";
            }
        }
        std::cout << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);
}


void deletestu(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[2000];
    int tno = std::stoi(username); // 将用户名（教师号）转换为 int
    setCharset(mysql);

    // 构建查询语句，获取教师所教授的课程号
    sprintf(sql,
            "SELECT teaching.cno, course.cname "
            "FROM teaching "
            "JOIN course ON teaching.cno = course.cno "
            "WHERE teaching.tno = %d",
            tno);

    // 执行查询
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 获取查询结果
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 检查是否有教授的课程
    if (mysql_num_rows(res) == 0) {
        std::cout << "你没有教授任何课程，无法删除学生选课信息。" << std::endl;
        mysql_free_result(res);
        return;
    }

    // 输出教师所教授的课程号和课程名
    std::cout << "你教授的课程如下：" << std::endl;
    while ((row = mysql_fetch_row(res)) != NULL) {
        std::cout << std::left << std::setw(10) << "课程号: " << std::left << std::setw(10) << row[0] << ", 课程名: " << row[1] << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);

    int cno;
    std::cout << "请输入要删除学生信息的课程号: ";
    std::cin >> cno;

    // 再次查询验证输入的课程号是否是该教师教授的课程号
    sprintf(sql,
            "SELECT * "
            "FROM teaching "
            "WHERE tno = %d AND cno = %d",
            tno, cno);

    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    res = mysql_store_result(&mysql);
    if (res == NULL || mysql_num_rows(res) == 0) {
        std::cout << "输入的课程号不是你教授的课程，无法删除学生选课信息。" << std::endl;
        mysql_free_result(res);
        return;
    }

    // 释放结果集
    mysql_free_result(res);

    int sno;
    std::cout << "请输入要删除的学生号: ";
    std::cin >> sno;

    // 构建删除语句
    sprintf(sql, "DELETE FROM sc WHERE sno = %d AND cno = %d", sno, cno);

    // 执行删除操作
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    std::cout << "学生选课信息删除成功。" << std::endl;
}

void updateGrade(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[2000];
    int tno = std::stoi(username);  // 将用户名（教师号）转换为 int
    setCharset(mysql);

    // 构建查询语句，使用创建的视图简化查询
    snprintf(sql, sizeof(sql),
             "SELECT sno, sname, cno, cname, grade FROM View_TeacherCourses WHERE tno = %d",
             tno);

    // 执行查询
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 获取查询结果
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 输出教师所教授课程的学生信息和成绩
    std::cout << "你教授的课程的学生信息如下：" << std::endl;
    int num_fields = mysql_num_fields(res);
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num_fields; ++i) {
        std::cout << std::left << std::setw(15) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // 显示分隔线
    for (int i = 0; i < num_fields; ++i) {
        std::cout << std::left << std::setw(15) << std::string(15, '-') << "\t";
    }
    std::cout << std::endl;

    // 显示数据行
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < num_fields; ++i) {
            std::cout << std::left << std::setw(15) << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);

    // 收集要修改的成绩信息
    int sno, cno;
    std::string grade;
    std::cout << "请输入要修改成绩的学生号: ";
    std::cin >> sno;
    std::cout << "请输入该学生的课程号: ";
    std::cin >> cno;
    std::cout << "请输入新的成绩（可以为空）: ";
    std::cin >> grade;

    // 构建更新语句
    if (grade.empty()) {
        snprintf(sql, sizeof(sql), "UPDATE sc SET grade = NULL WHERE sno = %d AND cno = %d", sno, cno);
    } else {
        snprintf(sql, sizeof(sql), "UPDATE sc SET grade = '%s' WHERE sno = %d AND cno = %d", grade.c_str(), sno, cno);
    }

    // 执行更新操作
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing update: " << mysql_error(&mysql) << std::endl;
        return;
    }

    std::cout << "学生成绩更新成功。" << std::endl;
}

void setCharset(MYSQL &mysql) {
    if (mysql_set_character_set(&mysql, "gbk")) {
        std::cout << "Error setting character set: " << mysql_error(&mysql) << std::endl;
        exit(1);
    }
}


void addTeacher(MYSQL &mysql)
{

    int flagnum=0;
    int num = 0;
    char sql[2000];
    struct teacher
    {

        int tno, age;
        string tname, sex, degree, password, title, teachYear;
    } teacher_arr[100] = {0};
    goto_error:
    cout<<endl;
    cout << "请输入待录入教师个数:>";
    cin >> num;
    if (num < 1)
    {
        cout << "error input " << endl << "input again:" << endl;
        goto goto_error;
    }

    // char sql[2000];
    // int tno, age;
    // string tname, sex, degree, password,title,teachYear ;

    // cout << "请输入教师号: ";
    // cin >> tno;
    // cout << "请输入教师名: ";
    // cin >> tname;
    // cout << "请输入性别: ";
    // cin >> sex;
    // cout << "请输入年龄: ";
    // cin >> age;
    // cout << "请输入学位: ";
    // cin >> degree;
    // cout << "请输入密码: ";
    // cin >> password;
    // cout<<"请输入头衔： ";
    // cin>>title;
    // cout << "请输入教学日期: ";
    // cin >> teachYear;
    cout<<"输入的教师号以 1 开头";
    cout << "请输入:  " << endl << "教师号 | " << "教师名 | " << "性别 | " << "年龄 | " << "学位 | " << "密码 | "
         << "头衔 | " << "教学日期 | " << endl;

    for (int i = 1; i <= num; i++)
    {

        cin >> teacher_arr[i].tno >> teacher_arr[i].tname >> teacher_arr[i].sex >> teacher_arr[i].age
            >> teacher_arr[i].degree >> teacher_arr[i].password >> teacher_arr[i].title >> teacher_arr[i].teachYear;
        // 设置字符编码
        if(     0 == teacher_arr[i].tno  or  0 == teacher_arr[i].age  or "" == teacher_arr[i].tname or "" == teacher_arr[i].sex
                or "" == teacher_arr[i].degree or "" == teacher_arr[i].title or "" == teacher_arr[i].teachYear or "" == teacher_arr[i].password)
        {
            cout<<"the "<<num<<" line has error"<<num-1<<"lines have been inserted into aams"<<endl;
            break;
        }

        setCharset(mysql);

        // 构建插入语句，向teacher表添加教师信息
        sprintf(sql,
                "INSERT INTO teacher (tno, tname, sex, age, degree,title,teachYear ) VALUES (%d, '%s', '%s', %d, '%s','%s','%s')",
                teacher_arr[i].tno, teacher_arr[i].tname.c_str(),
                teacher_arr[i].sex.c_str(), teacher_arr[i].age, teacher_arr[i].degree.c_str(),
                teacher_arr[i].title.c_str(), teacher_arr[i].teachYear.c_str());
        if (mysql_query(&mysql, sql)) {
            std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
            cout<<"insert into teacher table error"<<endl;
            continue;
        }

        // 向mysql系统数据库的user表添加登录信息
        sprintf(sql, "CREATE USER '%d'@'localhost' IDENTIFIED BY '%s'", teacher_arr[i].tno,
                teacher_arr[i].password.c_str());
        if (mysql_query(&mysql, sql)) {
            std::cout << "Error creating user: " << mysql_error(&mysql) << std::endl;
            cout<<"insert into teacher user error"<<endl;
            continue;
        }

        // 授予教师连接aams数据库的权限
        sprintf(sql, "GRANT ALL PRIVILEGES ON aams.* TO '%d'@'localhost'", teacher_arr[i].tno);
        if (mysql_query(&mysql, sql))
        {
            std::cout << "Error granting privileges: " << mysql_error(&mysql) << std::endl;
            cout<<"grant teacher right error"<<endl;
            continue;
        }
        flagnum++;

    }

    cout << num<<"位老师中有 "<<flagnum<<"位教师信息添加成功并授予登录权限。" << endl<<endl<<endl;


    system("pause");
}

void deleteTeacher(MYSQL &mysql) {
    char sql[2000];
    int tno;

    cout << "请输入要删除的教师号: ";
    cin >> tno;

    // 设置字符编码
    setCharset(mysql);

    // 构建删除语句，删除teacher表中的教师信息
    sprintf(sql, "DELETE FROM teacher WHERE tno = %d", tno);
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 从mysql系统数据库的user表删除登录信息
    sprintf(sql, "DROP USER '%d'@'localhost'", tno);
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error dropping user: " << mysql_error(&mysql) << std::endl;
        return;
    }

    cout << "教师信息删除成功并删除登录权限。" << endl;
}

void addStudent(MYSQL &mysql)
{
    char sql[2000];
    char sql2[2000];
    int num;
    int flagnum =0;

    struct student
    {

        int sno, age ,classid;
        string sname, sex, password, mrkyer;
    } studengt_arr[100] = {0};
    goto_error:
    cout<<endl;
    cout << "请输入待录入学生个数:>";
    cin >> num;
    if (num < 1)
    {
        cout << "error input " << endl << "input again:" << endl;
        goto goto_error;
    }

    // int sno, age,classid;
    // string sname, sex,  password,mrkyer;

    // cout << "请输入学生号: ";
    // cin >> sno;
    // cout << "请输入学生名: ";
    // cin >> sname;
    // cout << "请输入性别: ";
    // cin >> sex;
    // cout << "请输入年龄: ";
    // cin>> age;
    // cout << "请输入学日期: ";
    // cin >> mrkyer;
    // cout << "请输入班号: ";
    // cin >> classid;
    // cout << "请输入密码: ";
    // cin >> password;

    cout<<"输入的学生号以 2 开头";
    cout << "请输入:  "<<endl<<"学生号 | "<< "姓名 | "<< "性别 | "<< "年龄 | "<< "入学日期 | "<< "班号 | "<< "密码 | "<<endl;

    for (int i = 1; i <= num; i++)
    {


        cin >> studengt_arr[i].sno>> studengt_arr[i].sname>> studengt_arr[i].sex>> studengt_arr[i].age>>
            studengt_arr[i]. mrkyer>>studengt_arr[i].classid>> studengt_arr[i].password;
        if(     0 == studengt_arr[i].sno  or  0 == studengt_arr[i].age  or  0 == studengt_arr[i].classid or
                "" == studengt_arr[i].sname or "" == studengt_arr[i].sex or "" == studengt_arr[i]. mrkyer or "" == studengt_arr[i].password)
        {
            cout<<"the "<<num<<" line has error"<<num-1<<"lines have been inserted into aams"<<endl;
            break;
        }
        // 设置字符编码
        setCharset(mysql);

        // 构建插入语句，向stu表添加学生信息
        sprintf(sql, "INSERT INTO stu (sno, sname, sex, age, mrkyer,classid) VALUES (%d, '%s', '%s', %d, '%s','%d')",
                studengt_arr[i].sno, studengt_arr[i].sname.c_str(), studengt_arr[i].sex.c_str(), studengt_arr[i].age,
                studengt_arr[i].mrkyer.c_str(),studengt_arr[i].classid);
        if (mysql_query(&mysql, sql))
        {
            std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
            cout<<"insert into stu table error"<<endl;
            continue;
        }

        // 向mysql系统数据库的user表添加登录信息
        sprintf(sql, "CREATE USER '%d'@'localhost' IDENTIFIED BY '%s'", studengt_arr[i].sno, studengt_arr[i].password.c_str());
        if (mysql_query(&mysql, sql))
        {
            std::cout << "Error creating user: " << mysql_error(&mysql) << std::endl;
            cout<<"insert into student user error"<<endl;
            continue;
        }

        // 授予学生连接aams数据库的权限
        sprintf(sql, "GRANT ALL PRIVILEGES ON aams.* TO '%d'@'localhost'", studengt_arr[i].sno);
        if (mysql_query(&mysql, sql))
        {
            std::cout << "Error granting privileges: " << mysql_error(&mysql) << std::endl;
            cout<<"grant student right error"<<endl;
            continue;
        }

        sprintf(sql2, "GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '%d'@'localhost'", studengt_arr[i].sno);
        if (mysql_query(&mysql, sql2))
        {
            std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
            cout<<"grant student right error on proc1"<<endl;
            continue;
        }
        sprintf(sql2, "GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '%d'@'localhost'",studengt_arr[i].sno);
        if (mysql_query(&mysql, sql2))
        {
            std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
            cout<<"grant student right error on proc2"<<endl;
            continue;
        }
        flagnum++;

    }





    cout <<" 输入的 "<<num<< "个学生中"<<flagnum<<"条学生信息添加成功并授予登录权限。" << endl<<endl<<endl;

}

void deleteStudent(MYSQL &mysql) {
    char sql[2000];
    char sql2[2000];

    int sno;

    cout << "请输入要删除的学生号: ";
    cin >> sno;

    // 设置字符编码
    setCharset(mysql);


    // 构建删除语句，删除stu表中的学生信息
    sprintf(sql, "DELETE FROM stu WHERE sno = %d", sno);
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 从mysql系统数据库的user表删除登录信息
    sprintf(sql, "DROP USER '%d'@'localhost'", sno);
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error dropping user: " << mysql_error(&mysql) << std::endl;
        return;
    }

    cout << "学生信息删除成功并删除登录权限。" << endl;
}

void assignCourse(MYSQL &mysql) {
    char sql[2000];
    int tno, cno;
    string stime, etime;

    cout << "请输入教师号: ";
    cin >> tno;
    cout << "请输入课程号: ";
    cin >> cno;
    cout << "请输入课程开始时间: ";
    cin >> stime;
    cout << "请输入课程结束时间: ";
    cin >> etime;

    // 设置字符编码
    setCharset(mysql);

    // 构建插入语句，向teaching表添加课程安排信息
    sprintf(sql, "INSERT INTO teaching (tno, cno, stime, etime) VALUES (%d, %d, '%s', '%s')", tno, cno, stime.c_str(), etime.c_str());
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    cout << "课程安排成功。" << endl;
}
void showSelectedstu(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[1000];
    setCharset(mysql);
    int tno = std::stoi(username); // 将用户名（教师学号）转换为 int

    // 构建查询语句，连接stu表、course表和sc表
    snprintf(sql, sizeof(sql),
             "SELECT sno, sname, cno, cname, grade FROM View_TeacherCourses WHERE tno = %d",
             tno);

    snprintf(sql, sizeof(sql),
             "SELECT sno, sname, cno, cname, grade FROM View_TeacherCourses WHERE tno = %d",
             tno);
    // 执行查询
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 获取查询结果
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    int num = mysql_num_fields(res);

    // 输出列名
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(15) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // 打印分隔线
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(15) << std::string(15, '-') << "\t";
    }
    std::cout << std::endl;

    // 遍历结果集中所有的行
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (int i = 0; i < num; ++i) {
            if (row[i] == NULL) {
                std::cout << std::left << std::setw(15) << "未评分" << "\t";
            } else {
                std::cout << std::left << std::setw(15) << row[i] << "\t";
            }
        }
        std::cout << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);
}

void addstu(MYSQL &mysql, std::string username) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    char sql[2000];
    int tno = std::stoi(username); // 将用户名（教师号）转换为 int
    setCharset(mysql);

    // 构建查询语句，获取教师所教授的课程号
    /*sprintf(sql,
            "SELECT teaching.cno, course.cname "
            "FROM teaching "
            "JOIN course ON teaching.cno = course.cno "
            "WHERE teaching.tno = %d",
            tno);*/
    snprintf(sql, sizeof(sql),
             "SELECT distinct cno, cname FROM View_TeacherCourses WHERE tno = %d",
             tno);
    // 执行查询
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 获取查询结果
    res = mysql_store_result(&mysql);
    if (res == NULL) {
        std::cout << "Error storing result: " << mysql_error(&mysql) << std::endl;
        return;
    }

    // 检查是否有教授的课程
    if (mysql_num_rows(res) == 0) {
        std::cout << "你没有教授任何课程，无法添加学生选课信息。" << std::endl;
        mysql_free_result(res);
        return;
    }

    // 输出教师所教授的课程号和课程名
    std::cout << "你教授的课程如下：" << std::endl;
    while ((row = mysql_fetch_row(res)) != NULL) {
        std::cout << std::left << std::setw(10) << "课程号: " << std::left << std::setw(10) << row[0] << ", 课程名: " << row[1] << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);

    int cno;
    std::cout << "请输入要加入学生信息的课程号: ";
    std::cin >> cno;

    // 再次查询验证输入的课程号是否是该教师教授的课程号
    sprintf(sql,
            "SELECT * "
            "FROM teaching "
            "WHERE tno = %d AND cno = %d",
            tno, cno);

    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    res = mysql_store_result(&mysql);
    if (res == NULL || mysql_num_rows(res) == 0) {
        std::cout << "输入的课程号不是你教授的课程，无法添加学生选课信息。" << std::endl;
        mysql_free_result(res);
        return;
    }

    // 释放结果集
    mysql_free_result(res);

    int sno;
    std::cout << "请输入要加入的学生号: ";
    std::cin >> sno;

    // 构建插入语句
    sprintf(sql, "INSERT INTO sc(sno, cno) VALUES(%d, %d)", sno, cno);

    // 执行插入操作
    if (mysql_query(&mysql, sql)) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        return;
    }

    std::cout << "学生选课信息添加成功。" << std::endl;
}

void showClassmates(MYSQL &mysql, std::string username) {
    setCharset(mysql);
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"); // 防止在命令行中中文乱码

    // 构建查询语句
    std::string query = "SELECT stu.sno, stu.sname, stu.sex, class.classname "
                        "FROM stu "
                        "JOIN class ON stu.classid = class.classid "
                        "WHERE stu.classid = (SELECT classid FROM stu WHERE sno = '" + username + "')";

    // 执行查询
    if (mysql_query(&mysql, query.c_str())) {
        std::cout << "Error executing query: " << mysql_error(&mysql) << std::endl;
        mysql_close(&mysql);
        return;
    }

    // 获取查询结果
    res = mysql_use_result(&mysql);
    int num = mysql_num_fields(res);

    // 得到所有列的名字，并且输出
    MYSQL_FIELD *fields = mysql_fetch_fields(res);
    for (int i = 0; i < num; ++i) {
        std::cout << std::left << std::setw(15) << fields[i].name << "\t";
    }
    std::cout << std::endl;

    // 遍历结果集中所有的行
    while ((row = mysql_fetch_row(res)) != NULL) {
        // 将当前行中的每一列信息读出
        for (int i = 0; i < num; ++i) {
            std::cout << std::left << std::setw(15) << (row[i] ? row[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
    }

    // 释放结果集
    mysql_free_result(res);
}



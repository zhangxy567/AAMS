#创建数据库
CREATE DATABASE IF NOT EXISTS aams;






#创建数据表并且填入数据
use aams;

CREATE TABLE stu  (
  sno int(11) NOT NULL COMMENT '学号',
  sname varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '姓名',
  sex varchar(1) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '性别',
  age int(2) NOT NULL COMMENT '年龄',
  mrkyer date NOT NULL COMMENT '入学年份',
  classid int(11) NOT NULL COMMENT '班号',
  PRIMARY KEY (sno) USING BTREE,
  INDEX classid(classid) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

INSERT INTO stu VALUES (20190001, '王平', '男', 20, '2019-09-01', 2);
INSERT INTO stu VALUES (20190002, '李勇', '男', 21, '2019-09-01', 9);
INSERT INTO stu VALUES (20190003, '刘晨', '男', 20, '2019-09-01', 1);
INSERT INTO stu VALUES (20190004, '王名', '男', 19, '2019-09-01', 3);
INSERT INTO stu VALUES (20190005, '张立', '男', 20, '2019-09-01', 2);
INSERT INTO stu VALUES (20190006, '李明', '男', 20, '2019-09-01', 10);
INSERT INTO stu VALUES (20190007, '张小梅', '女', 19, '2019-09-01', 1);
INSERT INTO stu VALUES (20190008, '封晓文', '女', 20, '2019-09-01', 3);
INSERT INTO stu VALUES (20190009, '陈冬', '男', 20, '2019-09-01', 4);
INSERT INTO stu VALUES (20190010, '风清扬', '男', 20, '2019-09-01', 4);
INSERT INTO stu VALUES (20190011, '黄明', '男', 19, '2019-09-01', 7);
INSERT INTO stu VALUES (20190012, '张亚', '女', 20, '2019-09-01', 6);
INSERT INTO stu VALUES (20190013, '朱洋', '男', 20, '2019-09-01', 5);
INSERT INTO stu VALUES (20190014, '章维', '男', 20, '2019-09-01', 8);
INSERT INTO stu VALUES (20190015, '赵仪', '女', 21, '2019-09-01', 9);
INSERT INTO stu VALUES (20190016, '刘威', '男', 20, '2019-09-01', 7);
INSERT INTO stu VALUES (20190017, '武岳', '男', 19, '2019-09-01', 11);
INSERT INTO stu VALUES (20190018, '任倩', '女', 20, '2019-09-01', 10);

CREATE TABLE sc  (
  sno int(11) NOT NULL,
  cno int(11) NOT NULL,
  grade char(25) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (sno, cno) USING BTREE,
  INDEX cno(cno) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

INSERT INTO sc VALUES (20190001, 1, '80');
INSERT INTO sc VALUES (20190001, 3, '81');
INSERT INTO sc VALUES (20190002, 4, '90');
INSERT INTO sc VALUES (20190003, 1, '77');
INSERT INTO sc VALUES (20190003, 8, '88');
INSERT INTO sc VALUES (20190004, 1, '85');
INSERT INTO sc VALUES (20190005, 6, '88');
INSERT INTO sc VALUES (20190006, 2, '94');
INSERT INTO sc VALUES (20190007, 3, '91');
INSERT INTO sc VALUES (20190008, 3, '89');
INSERT INTO sc VALUES (20190009, 4, '85');
INSERT INTO sc VALUES (20190010, 5, '88');
INSERT INTO sc VALUES (20190011, 8, '89');
INSERT INTO sc VALUES (20190012, 7, '82');
INSERT INTO sc VALUES (20190012, 8, '77');
INSERT INTO sc VALUES (20190013, 6, '87');
INSERT INTO sc VALUES (20190015, 2, '92');
INSERT INTO sc VALUES (20190016, 4, '86');
INSERT INTO sc VALUES (20190016, 5, '85');
INSERT INTO sc VALUES (20190017, 4, '90');
INSERT INTO sc VALUES (20190018, 6, '75');
INSERT INTO sc VALUES (20190018, 7, '90');

CREATE TABLE course  (
  cno int(11) NOT NULL,
  cname varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  time varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  hours char(4) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  credit char(4) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  tno int(11) NOT NULL,
  PRIMARY KEY (cno) USING BTREE,
  INDEX tno(tno) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

INSERT INTO course VALUES (1, '数据库', '周三6、7、8', '48', '3', 1005);
INSERT INTO course VALUES (2, '高等数学', '周二3、4、5', '64', '4', 1002);
INSERT INTO course VALUES (3, '数据结构', '周二1、2', '64', '3', 1013);
INSERT INTO course VALUES (4, '概论', '周一1、2', '48', '3',  1012);
INSERT INTO course VALUES (5, '英语', '周五3、4', '48', '3',  1008);
INSERT INTO course VALUES (6, '社会实践', '周五8、9', '24', '3',  1014);
INSERT INTO course VALUES (7, '形势与政策', '周三1、2', '8', '2', 1004);
INSERT INTO course VALUES (8, '概率论', '周四3、4、5', '48', '3', 1007);

CREATE TABLE teaching  (
  tno int(11) NOT NULL,
  cno int(11) NOT NULL,
  stime date NOT NULL,
  etime date NOT NULL,
  PRIMARY KEY (tno, cno) USING BTREE,
  INDEX cno(cno) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

INSERT INTO teaching VALUES (1002, 2, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1004, 7, '2021-05-02', '2021-06-13');
INSERT INTO teaching VALUES (1005, 1, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1007, 8, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1008, 5, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1012, 4, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1013, 3, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1014, 6, '2021-05-23', '2021-06-20');

CREATE TABLE teacher  (
  tno int(11) NOT NULL,
  tname varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  sex varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  age varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  degree varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  title varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  teachYear date NOT NULL,
  PRIMARY KEY (tno) USING BTREE,
  INDEX tno(tno) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

INSERT INTO teacher VALUES (1001, '刘文', '女', '40', '硕士', '副教授', '2005-04-08');
INSERT INTO teacher VALUES (1002, '王萍', '女', '45', '博士', '教授', '2004-03-26');
INSERT INTO teacher VALUES (1003, '黄鄂', '男', '39', '硕士', '助教', '2009-07-18');
INSERT INTO teacher VALUES (1004, '陈珂', '女', '35', '本科', '讲师', '2009-03-06');
INSERT INTO teacher VALUES (1005, '赵洋', '男', '42', '硕士', '副教授', '2007-03-23');
INSERT INTO teacher VALUES (1006, '孙逸', '男', '42', '硕士', '副教授', '2008-08-16');
INSERT INTO teacher VALUES (1007, '王品', '男', '36', '本科', '讲师', '2012-03-15');
INSERT INTO teacher VALUES (1008, '彭建国', '男', '40', '硕士', '副教授', '2010-05-22');
INSERT INTO teacher VALUES (1009, '张若克', '男', '32', '硕士', '讲师', '2015-10-17');
INSERT INTO teacher VALUES (1010, '陈玲', '女', '35', '硕士', '助教', '2015-12-24');
INSERT INTO teacher VALUES (1011, '郭赞', '女', '38', '硕士', '副教授', '2011-07-23');
INSERT INTO teacher VALUES (1012, '朱杰', '男', '42', '博士', '教授', '2007-03-08');
INSERT INTO teacher VALUES (1013, '李芮', '女', '40', '博士', '教授', '2006-06-08');
INSERT INTO teacher VALUES (1014, '罗源', '男', '34', '硕士', '讲师', '2011-06-14');
INSERT INTO teacher VALUES (1015, '沈轩', '男', '36', '硕士', '讲师', '2012-10-10');

CREATE TABLE class  (
  classid int(11) NOT NULL,
  classname varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (classid) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

INSERT INTO `class` VALUES (1, '19计算机科学与技术(1)班');
INSERT INTO `class` VALUES (2, '19计算机科学与技术(2)班');
INSERT INTO `class` VALUES (3, '19数字媒体技术(1)班');
INSERT INTO `class` VALUES (4, '19智能科学与技术(1)班');
INSERT INTO `class` VALUES (5, '19应用经济学(1)班');
INSERT INTO `class` VALUES (6, '19工商管理(全英班)');
INSERT INTO `class` VALUES (7, '19金融学(1)');
INSERT INTO `class` VALUES (8, '19金融学(2)');
INSERT INTO `class` VALUES (9, '19服装设计与工程(1)');
INSERT INTO `class` VALUES (10, '19服装设计与工程(1)');
INSERT INTO `class` VALUES (11, '19服装与服饰设计(1)');


#创建一定的约束
use aams;

ALTER TABLE stu ADD CONSTRAINT stu_fk
FOREIGN KEY(classid) REFERENCES class (classid) ON DELETE CASCADE ON UPDATE CASCADE;



#ALTER TABLE sc ADD  CONSTRAINT sc_fk_1
#FOREIGN KEY (sno) REFERENCES stu (sno) ON DELETE CASCADE ON UPDATE CASCADE;

#ALTER TABLE sc ADD  CONSTRAINT sc_fk_2
#FOREIGN KEY (cno) REFERENCES course (cno) ON DELETE CASCADE ON UPDATE CASCADE;
#放弃这两个键来构建更强大的触发器约束


ALTER TABLE course ADD CONSTRAINT course_fk
FOREIGN KEY (tno) REFERENCES teacher (tno) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE teaching ADD CONSTRAINT teaching_fk_1 
FOREIGN KEY (tno) REFERENCES teacher (tno) ON DELETE CASCADE ON UPDATE CASCADE;

ALTER TABLE teaching ADD CONSTRAINT teaching_fk_2 
FOREIGN KEY (cno) REFERENCES course (cno) ON DELETE CASCADE ON UPDATE CASCADE;





#创建存储过程


##GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190002'@'localhost';
#DROP PROCEDURE  IF EXISTS  aams.stu_getmessage ;


#学生选课存储过程
DELIMITER $$
create procedure aams.stu_getmessage ( in getsno int(11),in getcno int(11) )
BEGIN
INSERT INTO sc(sno,cno)
values(getsno,getcno);
END $$
DELIMITER ;


##GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190002'@'localhost';
#学生退课存储过程
DELIMITER $$
create procedure aams.stu_giveupsc ( in getsno int(11),in getcno int(11) )
BEGIN
DELETE FROM sc
WHERE sc.sno = getsno and sc.cno = getcno;
END $$
DELIMITER ;








#创建一定的使用用户
#SELECT User, Host FROM mysql.user;
#DROP USER 'user1'@'host1', 'user2'@'host2';
#FLUSH PRIVILEGES;

use aams;

CREATE USER '1001'@'localhost' IDENTIFIED BY '1001';
CREATE USER '1002'@'localhost' IDENTIFIED BY '1002';
CREATE USER '1003'@'localhost' IDENTIFIED BY '1003';

GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '1001'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '1002'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '1003'@'localhost';


CREATE USER '20190001'@'localhost' IDENTIFIED BY '0001';
CREATE USER '20190002'@'localhost' IDENTIFIED BY '0002';
CREATE USER '20190003'@'localhost' IDENTIFIED BY '0003';
CREATE USER '20190004'@'localhost' IDENTIFIED BY '0004';
CREATE USER '20190005'@'localhost' IDENTIFIED BY '0005';
CREATE USER '20190006'@'localhost' IDENTIFIED BY '0006';
CREATE USER '20190007'@'localhost' IDENTIFIED BY '0007';
CREATE USER '20190008'@'localhost' IDENTIFIED BY '0008';
CREATE USER '20190009'@'localhost' IDENTIFIED BY '0009';
CREATE USER '20190010'@'localhost' IDENTIFIED BY '0010';
#CREATE USER '20190011'@'localhost' IDENTIFIED BY '0011';
#CREATE USER '20190012'@'localhost' IDENTIFIED BY '0012';
#CREATE USER '20190013'@'localhost' IDENTIFIED BY '0013';
#CREATE USER '20190014'@'localhost' IDENTIFIED BY '0014';
#CREATE USER '20190015'@'localhost' IDENTIFIED BY '0015';
#CREATE USER '20190016'@'localhost' IDENTIFIED BY '0016';
#CREATE USER '20190017'@'localhost' IDENTIFIED BY '0017';
#CREATE USER '20190018'@'localhost' IDENTIFIED BY '0018';

#1
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190001'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190002'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190003'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190004'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190005'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190006'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190007'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190008'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190009'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190010'@'localhost';
/*GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190011'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190012'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190013'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190014'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190015'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190016'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190017'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190018'@'localhost';*/
#2
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190001'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190002'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190003'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190004'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190005'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190006'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190007'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190008'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190009'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190010'@'localhost';
/*GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190011'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190012'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190013'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190014'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190015'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190016'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190017'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_getmessage TO '20190018'@'localhost';*/

#3
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190001'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190002'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190003'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190004'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190005'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190006'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190007'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190008'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190009'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190010'@'localhost';
/*GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190011'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190012'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190013'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190014'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190015'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190016'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190017'@'localhost';
GRANT EXECUTE ON PROCEDURE aams.stu_giveupsc TO '20190018'@'localhost';*/



#创建视图

#View_TeacherCourses      /* 这个视图是用来展示老师所教授的课程以及选这些课程的学生*/
use aams;
CREATE VIEW View_TeacherCourses AS
SELECT 
    teaching.tno,
    stu.sno, 
    stu.sname, 
    course.cno, 
    course.cname, 
    sc.grade
FROM 
    teaching
JOIN 
    course ON teaching.cno = course.cno
JOIN 
    sc ON course.cno = sc.cno
JOIN 
    stu ON sc.sno = stu.sno;

#View_StudentCourses     /*这个视图是用来展现学生所选课程的*/
CREATE VIEW View_StudentCourses AS
SELECT 
    stu.sno, 
    stu.sname, 
    sc.cno, 
    course.cname, 
    sc.grade
FROM 
    stu 
JOIN 
    sc ON stu.sno = sc.sno 
JOIN 
    course ON sc.cno = course.cno;




#创建触发器

DELIMITER $$

CREATE TRIGGER sc_add_addstu
BEFORE INSERT 
ON aams.sc
FOR EACH ROW
BEGIN
    DECLARE student_exists INT;
    DECLARE course_exists INT;


    SELECT COUNT(*) INTO student_exists FROM stu WHERE sno = NEW.sno;

    SELECT COUNT(*) INTO course_exists FROM course WHERE cno = NEW.cno;


    IF student_exists = 0 OR course_exists = 0 
	THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Insert error: student or course does not exist.';
    END IF;
END$$

DELIMITER ;

#触发器二,更新成绩不容许小
use aams;
DELIMITER $$

CREATE TRIGGER sc_update_grade
BEFORE UPDATE
ON aams.sc
FOR EACH ROW
BEGIN
    IF NEW.grade <= OLD.grade THEN
        SIGNAL SQLSTATE '45001'
        SET MESSAGE_TEXT = 'Updated score must not be less than the original score.';
    END IF;
END $$

DELIMITER ;


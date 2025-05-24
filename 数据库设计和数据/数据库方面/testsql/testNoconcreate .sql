创建表
1stu
stu(sno,sname,sex,age,mrkyer,classid) pk:sno,fk:classid
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
-- ----------------------------
-- Records of student
-- ----------------------------
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



2sc
sc(sno,cno,grade) pk:(sno,cno),fk1:sno,fk2:cno
CREATE TABLE sc  (
  sno int(11) NOT NULL,
  cno int(11) NOT NULL,
  grade char(25) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (sno, cno) USING BTREE,
  INDEX cno(cno) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;
-- ----------------------------
-- Records of sc
-- ----------------------------
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





3course
course(cno,cname,time,hours,credit,tno)pk:cno,fk:tno
CREATE TABLE course  (
  cno int(11) NOT NULL,
  cname varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  time varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  hours char(4) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  credit char(4) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  tno int(11) NOT NULL,
  PRIMARY KEY (cno) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;
-- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO course VALUES (1, '数据库', '周三6、7、8', '48', '3', 1005);
INSERT INTO course VALUES (2, '高等数学', '周二3、4、5', '64', '4', 1002);
INSERT INTO course VALUES (3, '数据结构', '周二1、2', '64', '3', 1013);
INSERT INTO course VALUES (4, '概论', '周一1、2', '48', '3',  1012);
INSERT INTO course VALUES (5, '英语', '周五3、4', '48', '3',  1008);
INSERT INTO course VALUES (6, '社会实践', '周五8、9', '24', '3',  1014);
INSERT INTO course VALUES (7, '形势与政策', '周三1、2', '8', '2', 1004);
INSERT INTO course VALUES (8, '概率论', '周四3、4、5', '48', '3', 1007);





4teaching(tno,cno,stime,etime) pk:(tno,cno)
CREATE TABLE teaching  (
  tno int(11) NOT NULL,
  cno int(11) NOT NULL,
  stime date NOT NULL,
  etime date NOT NULL,
  PRIMARY KEY (tno, cno) USING BTREE,
  INDEX cno(cno) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;
-- ----------------------------
-- Records of setup
-- ----------------------------
INSERT INTO teaching VALUES (1002, 2, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1004, 7, '2021-05-02', '2021-06-13');
INSERT INTO teaching VALUES (1005, 1, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1007, 8, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1008, 5, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1012, 4, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1013, 3, '2021-02-18', '2021-06-13');
INSERT INTO teaching VALUES (1014, 6, '2021-05-23', '2021-06-20');





5teacher(tno,tname,sex,age,degree,title,teachyear) pk;tno
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
-- ----------------------------
-- Records of teacher
-- ----------------------------
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






6class(classid,classname) pk:classid
CREATE TABLE class  (
  classid int(11) NOT NULL,
  classname varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (classid) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;
-- ----------------------------
-- Records of class
-- ----------------------------
INSERT INTO class VALUES (1, '19计算机科学与技术(1)班');
INSERT INTO class VALUES (2, '19计算机科学与技术(2)班');
INSERT INTO class VALUES (3, '19数字媒体技术(1)班');
INSERT INTO class VALUES (4, '19智能科学与技术(1)班');
INSERT INTO class VALUES (5, '19应用经济学(1)班');
INSERT INTO class VALUES (6, '19工商管理(全英班)');
INSERT INTO class VALUES (7, '19金融学(1)');
INSERT INTO class VALUES (8, '19金融学(2)');
INSERT INTO class VALUES (9, '19服装设计与工程(1)');
INSERT INTO class VALUES (10, '19服装设计与工程(1)');
INSERT INTO class VALUES (11, '19服装与服饰设计(1)');





7
CREATE TABLE user  (
  id int(11) NOT NULL AUTO_INCREMENT,
  uname varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  upass varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  type int(255) NOT NULL,
  PRIMARY KEY (id) USING BTREE,
  UNIQUE INDEX uname(uname) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 16 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO user VALUES (1, 'admin', 'admin', 1);
INSERT INTO user VALUES (2, '李思影', 'lay', 2);
INSERT INTO user VALUES (3, '高原', 'gy', 2);
INSERT INTO user VALUES (4, '肖畅', 'xc', 2);
INSERT INTO user VALUES (5, '佟静林', 'tjl', 2);
INSERT INTO user VALUES (6, '邵永刚', 'syg', 2);
INSERT INTO user VALUES (7, '20190001', '0001', 2);
INSERT INTO user VALUES (8, '20190002', '0002', 2);
INSERT INTO user VALUES (9, '20190003', '0003', 2);
INSERT INTO user VALUES (10, '20190004', '0004', 2);
INSERT INTO user VALUES (11, '20190005', '0005', 2);
INSERT INTO user VALUES (12, '1001', '1001', 3);
INSERT INTO user VALUES (13, '1002', '1002', 3);
INSERT INTO user VALUES (14, '1003', '1003', 3);
INSERT INTO user VALUES (15, '20190006', '0006', 2);
创建角色无果版:
teacher:

CREATE USER '1001'@'localhost' IDENTIFIED BY '1001';
CREATE USER '1002'@'localhost' IDENTIFIED BY '1002';
CREATE USER '1003'@'localhost' IDENTIFIED BY '1003';

GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '1001'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '1002'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '1003'@'localhost';

student:

CREATE USER '20190001'@'localhost' IDENTIFIED BY '0001';
CREATE USER '20190002'@'localhost' IDENTIFIED BY '0002';
CREATE USER '20190003'@'localhost' IDENTIFIED BY '0003';
CREATE USER '20190004'@'localhost' IDENTIFIED BY '0004';
CREATE USER '20190005'@'localhost' IDENTIFIED BY '0005';
CREATE USER '20190006'@'localhost' IDENTIFIED BY '0006';

GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190001'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190002'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190003'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190004'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190005'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO '20190006'@'localhost';

创建角色组版:

teachergroup:

CREATE ROLE 'teachergroup'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON aams.* TO 'tearchergroup'@'localhost';

CREATE USER 'user1'@'localhost' IDENTIFIED BY 'password1';
CREATE USER 'user2'@'localhost' IDENTIFIED BY 'password2';

GRANT teachergroup TO 'user1'@'localhost';
GRANT teachergroup TO 'user2'@'localhost';

SET DEFAULT ROLE 'developer' FOR 'user1'@'localhost';
SET DEFAULT ROLE 'developer' FOR 'user2'@'localhost';
studentgroup:

root:
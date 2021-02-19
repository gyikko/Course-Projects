/* 
This script navigates to the target database and creates the EMPLOYEE table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
USE C4707F20U33;
CREATE TABLE IF NOT EXISTS EMPLOYEE(
    -- 8 bit uuid
    Eid CHAR(8) PRIMARY KEY,
    Ssn CHAR(9) UNIQUE,
    Fname VARCHAR(255),
    Lname VARCHAR(255)
);

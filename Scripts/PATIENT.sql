/* 
This script creates the PATIENT table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS PATIENT(
    -- 8 bit uuid
    Pid CHAR(8) PRIMARY KEY,
    Fname VARCHAR(255),
    Lname VARCHAR(255),
    Address VARCHAR(255),
    -- An emergency phone number
    Emergency_contact CHAR(10),
    Birthdate DATE
);
/* 
This script creates the PHONE table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS PHONE(
    -- 8 bit uuid
    Pid CHAR(8), 
    Phone CHAR(10),
    PRIMARY KEY(Pid, Phone),
    FOREIGN KEY(Pid) REFERENCES PATIENT(Pid)
);
/* 
This script creates the PARENT_GUARDIAN table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS PARENT_GUARDIAN(
    -- 8 bit uuid
    Pid CHAR(8),
    Name CHAR(8),
    PRIMARY KEY (Pid, Name),
    FOREIGN KEY(Pid) REFERENCES PATIENT(Pid)
);
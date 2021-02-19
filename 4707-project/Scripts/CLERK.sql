/* 
This script creates the CLERK table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS CLERK(
    -- 8 bit uuid
    Cid CHAR(8) PRIMARY KEY,
    FOREIGN KEY(Cid) REFERENCES EMPLOYEE(Eid)
);
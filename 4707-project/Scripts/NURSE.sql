/* 
This script creates the NURSE table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS NURSE(
    -- 8 bit uuid
    Nid CHAR(8) PRIMARY KEY,
    FOREIGN KEY(Nid) REFERENCES EMPLOYEE(Eid)
);
/* 
This script creates the INSURANCE_RECORD table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS INSURANCE_RECORD(
    -- 8 bit uuid
    Iid CHAR(8) PRIMARY KEY,
    Cid CHAR(8) NOT NULL,
    FOREIGN KEY(Cid) REFERENCES CLERK(Cid)
);
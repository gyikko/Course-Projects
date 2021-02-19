/* 
This script creates the SERVICE_PROVIDER table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS SERVICE_PROVIDER(
    -- 8 bit uuid
    Sid CHAR(8) PRIMARY KEY,
    FOREIGN KEY(Sid) REFERENCES EMPLOYEE(Eid)
);
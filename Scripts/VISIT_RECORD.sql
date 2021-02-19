/* 
This script creates the VISIT_RECORD table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS VISIT_RECORD(
    -- 8 bit uuid
    Vid CHAR(8) PRIMARY KEY,
    -- 8 bit uuid
    Iid CHAR(8) NOT NULL,
    Aid CHAR(8) NOT NULL,
    Pid CHAR(8) NOT NULL,
    FOREIGN KEY(Iid) REFERENCES INSURANCE_RECORD(Iid),
    FOREIGN KEY(Aid) REFERENCES INITIAL_ASSESSMENT(Aid),
    FOREIGN KEY(Pid) REFERENCES PATIENT(Pid)
);
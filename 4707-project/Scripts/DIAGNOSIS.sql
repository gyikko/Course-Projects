/* 
This script creates the DIAGNOSIS table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS DIAGNOSIS(
    -- 8 bit uuid
    Did CHAR(8),
    `ICD-10-CM_code` VARCHAR(7),
    Name VARCHAR(255),
    Sid CHAR(8) NOT NULL,
    Vid CHAR(8) NOT NULL,
    PRIMARY KEY(`ICD-10-CM_code`, Did),
    FOREIGN KEY(Vid) REFERENCES VISIT_RECORD(Vid),
    FOREIGN KEY(Sid) REFERENCES SERVICE_PROVIDER(Sid)
);
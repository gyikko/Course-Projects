/* 
This script creates the TREATMENT_TEST_PROCEDURE table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS TREATMENT_TEST_PROCEDURE(
    -- 8 bit uuid
    Tid CHAR(8),
    `ICD-10-PCS_code` VARCHAR(7),
    `ICD-10-PCS_name` VARCHAR(255),
    Cost INT,
    Sid CHAR(8) NOT NULL,
    Vid CHAR(8) NOT NULL,
    PRIMARY KEY(`ICD-10-PCS_code`, Tid),
    FOREIGN KEY(Vid) REFERENCES VISIT_RECORD(Vid),
    FOREIGN KEY(Sid) REFERENCES SERVICE_PROVIDER(Sid)
);
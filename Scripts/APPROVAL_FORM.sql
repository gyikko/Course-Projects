/* 
This script creates the APPROVAL_FORM table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS APPROVAL_FORM(
    -- 8 bit uuid
    Fid CHAR(8),
    `ICD-10-PCS_code` VARCHAR(7) NOT NULL,
    -- Is_approved: 0 is false, 1 is true
    Is_approved TINYINT,
    Pid CHAR(8) NOT NULL,
    Name CHAR(8) NOT NULL,
    PRIMARY KEY(`ICD-10-PCS_code`, Fid),
    FOREIGN KEY(Pid, Name) REFERENCES PARENT_GUARDIAN(Pid, Name),
    FOREIGN KEY(`ICD-10-PCS_code`) REFERENCES TREATMENT_TEST_PROCEDURE(`ICD-10-PCS_code`)
);
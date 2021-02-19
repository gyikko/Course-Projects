/* 
This script creates the INSURED_RECORD table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS INSURED_RECORD(
    -- 8 bit uuid
    Iid CHAR(8) PRIMARY KEY,
    Copay_card_number CHAR(10),
    Carrier VARCHAR(255),
    FOREIGN KEY(Iid) REFERENCES INSURANCE_RECORD(Iid)
);
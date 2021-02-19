/* 
This script creates the INITIAL_ASSESSMENT table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS INITIAL_ASSESSMENT(
    -- 8 bit uuid
    Aid CHAR(8) PRIMARY KEY,
    -- height unit: cm
    Height FLOAT(8, 2),
    -- weight unit: kg
    Weight FLOAT(8, 2),
    -- blood pressure unit: mm Hg
    Blood_pressure INT,
    -- Temperature unit: Celsius
    Temperature FLOAT(8, 1),
    -- palse unit: beats per minute
    Pulse INT,
    Nid CHAR(8) NOT NULL,
    FOREIGN KEY(Nid) REFERENCES NURSE(Nid)
);
/* 
This script creates the CURRENT_MEDICATIONS table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS CURRENT_MEDICATIONS(
    Aid CHAR(8),
    Current_medications VARCHAR(255),
    PRIMARY KEY(Aid, Current_medications),
    FOREIGN KEY(Aid) REFERENCES INITIAL_ASSESSMENT(Aid)
);
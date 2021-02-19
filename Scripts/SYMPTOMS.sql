/* 
This script creates the SYMPTOMS table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS SYMPTOMS(
    Aid CHAR(8),
    Symptoms VARCHAR(255),
    PRIMARY KEY(Aid, Symptoms),
    FOREIGN KEY(Aid) REFERENCES INITIAL_ASSESSMENT(Aid)
);
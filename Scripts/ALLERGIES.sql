/* 
This script creates the ALLERGIES table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS ALLERGIES(
    Aid CHAR(8),
    Allergy VARCHAR(255),
    PRIMARY KEY(Aid, Allergy),
    FOREIGN KEY(Aid) REFERENCES INITIAL_ASSESSMENT(Aid)
);
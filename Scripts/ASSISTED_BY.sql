/* 
This script creates the ASSISTED_BY table.
Authors: Zixuan Zhang (zhan7230), John Hendrickson (hend0825), Dmitri Ivanov (ivano033), Jingyi Jin (jinxx679)
*/
CREATE TABLE IF NOT EXISTS ASSISTED_BY(
    Vid CHAR(8),
    Nid CHAR(8),
    PRIMARY KEY(Vid, Nid),
    FOREIGN KEY(Vid) REFERENCES VISIT_RECORD(Vid),
    FOREIGN KEY(Nid) REFERENCES NURSE(Nid)
);
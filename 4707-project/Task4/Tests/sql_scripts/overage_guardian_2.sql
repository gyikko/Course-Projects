INSERT PATIENT VALUE("1ac27f31", "Bruce", "Wayne", "1007 Mountain Drive, Gotham", "7351857301",  "1980-12-17");
INSERT PARENT_GUARDIAN VALUE("1ac27f31", "Thomas Wayne");
SELECT * FROM PATIENT WHERE Pid = "1ac27f31";
SELECT * FROM PARENT_GUARDIAN WHERE Pid = "1ac27f31";
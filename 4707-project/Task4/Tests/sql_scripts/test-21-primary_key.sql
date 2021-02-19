DESC PATIENT;

INSERT INTO PATIENT(`Pid`,`Fname`,`Lname`,`Address`) 
    VALUES(NULL,'John','Smith','742 Evergreen Terrace');

INSERT INTO PATIENT(`Pid`,`Fname`,`Lname`,`Address`) 
    VALUES('98765432','DuplicateJohn','DuplicateSmith','Duplicate 742 Evergreen Terrace');

DESC EMPLOYEE;

INSERT INTO EMPLOYEE(`Eid`,`Ssn`,`Fname`,`Lname`) 
    VALUES(NULL,'11','Amy','ServiceProvider');

INSERT INTO EMPLOYEE(`Eid`,`Ssn`,`Fname`,`Lname`) 
    VALUES('11','1111','DuplicateAmy','DuplicateServiceProvider');
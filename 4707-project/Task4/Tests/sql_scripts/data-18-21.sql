-- Insert 2 patients in PATIENT table
INSERT INTO PATIENT(`Pid`,`Fname`,`Lname`,`Address`,`Emergency_contact`,`Birthdate`) 
    VALUES('98765432','John','Smith','742 Evergreen Terrace',`5673456789`,`1995-07-08`)
    VALUES('9acf4d31','Bruce','Wayne','1007 Mountain Drive, Gotham',`7351857301`,`2010-12-17`)

-- Insert 4 employees in EMPLOYEE table
INSERT INTO EMPLOYEE(`Eid`,`Ssn`,`Fname`,`Lname`) 
    VALUES('11','11','Amy','ServiceProvider')
    VALUES('22','22','Blair','ServiceProvider')
    VALUES('33','33','Charlie','Nurse')
    VALUES('44','44','Dylan','Nurse');

-- Connect Amy ServiceProvider and Blair ServiceProvider 
-- with SERVICE_PROVIDER table
INSERT INTO SERVICE_PROVIDER(`Sid`) 
    VALUES('11')
    VALUES('22');

-- Insert 2 visit records in VISIT_RECORD table
INSERT INTO VISIT_RECORD(`Vid`,`Iid`,`Aid`,`Pid`) 
    VALUES('12345678','12345678','12345678','98765432')
    VALUES('12345679','12345679','12345679','98765432')
    
INSERT INTO INSURANCE_RECORD(`Iid`,`Cid`)
    VALUES('12345678','22222223')   
    VALUES('12345679','22222223')
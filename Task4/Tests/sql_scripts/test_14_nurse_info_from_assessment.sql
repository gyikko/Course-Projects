-- insert employee for nurs to reference

insert into EMPLOYEE
values ('22222222', '333333333', 'jane', 'doe');

-- insert nurse for assessment to reference

insert into NURSE
values ('22222222');

-- insert assessment with associated nurse

insert into INITIAL_ASSESSMENT
values ( '12345678', 200, 75, 145, 98.6, 100, '22222222');

-- insert a second initial asseessment

insert into INITIAL_ASSESSMENT
values ( '12345679', 200, 75, 145, 98.6, 100, '22222222');

-- select nurse informention as assessment id for each assessment

select Eid, Ssn, Fname, Lname, Aid
from EMPLOYEE as E, INITIAL_ASSESSMENT as I
where I.Nid = E.Eid;
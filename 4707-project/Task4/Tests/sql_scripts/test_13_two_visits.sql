-- insert patient into table (he will visit more than once)
insert into PATIENT
values ('98765432', 'John', 'Smith', '742 Evergreen Terrace', '5673456789','1995-07-08' );
-- insert employee for clerk to reference
insert into EMPLOYEE
values ('22222223', '333333330', 'Joe', 'Clerkson');
-- incert clerk for insurance record to reference
insert into CLERK
values ('22222223');
-- insert insurance record for insured recored to reference
insert into INSURANCE_RECORD
values ('12345678','22222223');
-- insert insured record for visit record to reference
insert into INSURED_RECORD
values ('12345678', '1234567890', 'health partners');
-- insert initial assessment for first visit record to reference
insert into INITIAL_ASSESSMENT
values ( '12345678', 200, 75, 145, 98.6, 100, '22222222');
-- insert initial assessment for second visit record to reference
insert into INITIAL_ASSESSMENT
values ( '12345679', 200, 75, 145, 98.6, 100, '22222222');
-- insert firts visit record for 'John Smith'
insert into VISIT_RECORD
values ('12345678', '12345678', '12345678', '98765432');

-- insert second visit record for 'John Smith'
insert into VISIT_RECORD
values ('12345679', '12345678', '12345679', '98765432');




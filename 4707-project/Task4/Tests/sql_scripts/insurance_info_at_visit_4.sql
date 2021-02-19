-- Data Setup
INSERT EMPLOYEE VALUE("997a5826", "3302568897", "David", "Smith");
INSERT NURSE VALUE("997a5826");
INSERT INITIAL_ASSESSMENT VALUE("7928cc65", 180.00, 80.00, 140, 37.00, 100, "997a5826");

-- Inserting a visit record without a foreign key to an insurance record will fail
-- INSERT VISIT_RECORD(Vid, Aid, Pid) VALUE("7cba992d", "7928cc65", "1ac27f31");

INSERT EMPLOYEE VALUE("447a5826", "3302568897", "David", "Smith");
INSERT CLERK VALUE("447a5826");
INSERT INSURANCE_RECORD VALUE("2556cbda", "447a5826");

-- Inserting a vist record with a foreign key to an insurance record will succeed
INSERT VISIT_RECORD(Vid, Iid, Aid, Pid) VALUE("7cba992d", "2556cbda", "7928cc65", "1ac27f31");

SELECT * FROM VISIT_RECORD JOIN INSURANCE_RECORD ON VISIT_RECORD.Iid = INSURANCE_RECORD.Iid
WHERE VISIT_RECORD.Vid = "7cba992d";
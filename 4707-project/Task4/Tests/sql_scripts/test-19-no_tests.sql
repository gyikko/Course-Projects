SELECT TREATMENT_TEST_PROCEDURE.*
    FROM ((VISIT_RECORD
    INNER JOIN TREATMENT_TEST_PROCEDURE ON TREATMENT_TEST_PROCEDURE.Vid = VISIT_RECORD.Vid)
    INNER JOIN PATIENT ON PATIENT.Pid = VISIT_RECORD.Pid);
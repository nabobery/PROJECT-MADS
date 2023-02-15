-- 1527. Patients With a Condition

-- Solution 1
SELECT * FROM Patients WHERE conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%';

-- Solution 2
SELECT * FROM patients WHERE conditions REGEXP '\\bDIAB1';


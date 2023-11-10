-- 1965. Employees With Missing Information

-- Solution 1
(SELECT employee_id FROM Employees WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
UNION SELECT employee_id FROM Salaries WHERE employee_id NOT IN (SELECT employee_id FROM Employees)) ORDER BY employee_id;

-- Solution 2
(SELECT Employees.employee_id FROM Employees LEFT OUTER JOIN Salaries  ON (Employees.employee_id = Salaries.employee_id) WHERE Salaries.employee_id IS NULL
UNION SELECT Salaries.employee_id FROM Salaries LEFT OUTER JOIN Employees ON (Salaries.employee_id = Employees.employee_id) WHERE Employees.employee_id IS NULL) ORDER BY employee_id;
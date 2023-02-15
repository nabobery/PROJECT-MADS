-- 1873. Calculate Special Bonus

-- Solution 1
SELECT employee_id, salary * (employee_id % 2) * (name NOT LIKE 'M%') AS bonus FROM Employees ORDER BY employee_id;

-- Solution 2
SELECT employee_id , 
CASE WHEN employee_id%2 != 0 AND name NOT LIKE 'M%' THEN salary 
ELSE 0 
END 
AS bonus FROM employees ORDER BY employee_id;

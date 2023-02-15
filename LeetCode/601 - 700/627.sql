-- 627. Swap Salary

-- Solution 1
UPDATE Salary
SET sex = CASE sex
WHEN 'm' THEN 'f'
ELSE 'm'
END

-- Solution 2
UPDATE Salary
SET sex = IF (sex = "m", "f", "m");

-- Solution 3
UPDATE Salary
SET sex = CHAR(ASCII('m') + ASCII('f')- ASCII(sex));


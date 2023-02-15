-- 176. Second Highest Salary

SELECT MAX(salary) AS SecondHighestSalary FROM Employee WHERE salary NOT IN (SELECT MAX(salary) FROM Employee);
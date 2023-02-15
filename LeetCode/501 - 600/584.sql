-- 584. Find Customer Referee

-- Solution 1: 
SELECT name FROM Customer WHERE (referee_id IS NULL OR referee_id != 2);

-- Solution 2:
SELECT name FROM Customer WHERE NOT (referee_id IS NOT NULL AND referee_id = 2);
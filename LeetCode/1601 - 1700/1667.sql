-- 1667 Fix Names in a Table

SELECT user_id, CONCAT(UPPER(SUBSTRING(name,1,1)),LOWER(SUBSTRING(name,2,100))) AS name FROM Users ORDER BY user_id;
-- 196. Delete Duplicate Emails

-- delete from person such that id is not the minimum id of the same email
DELETE FROM Person WHERE id NOT IN ( SELECT * FROM (SELECT MIN(id) FROM Person GROUP BY email) AS temp);

-- 1407. Top Travellers

-- Can use IFNULL or COALESCE to get sum as 0 for null columns
SELECT name, COALESCE(SUM(distance),0) AS travelled_distance FROM Users LEFT JOIN Rides ON Users.id = Rides.user_id GROUP by user_id ORDER BY travelled_distance DESC, name;

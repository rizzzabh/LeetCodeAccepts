SELECT 
Users.name as name,
COALESCE(t.total_distance,0) as travelled_distance
FROM
(SELECT 
user_id , 
SUM(distance) as total_distance
FROM Rides
GROUP BY user_id) t
RIGHT JOIN Users
ON Users.id = t.user_id
ORDER BY travelled_distance DESC , Users.name ASC
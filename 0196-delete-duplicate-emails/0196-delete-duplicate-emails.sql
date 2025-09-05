/* Write your T-SQL query statement below */
DELETE p
FROM 
Person p 
JOIN (
    SELECT 
        email , MIN(id) keep_id
    FROM 
        Person 
    GROUP BY
        email
) t 
ON p.email = t.email
WHERE p.id > t.keep_id
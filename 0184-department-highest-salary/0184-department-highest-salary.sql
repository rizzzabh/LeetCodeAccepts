# Write your MySQL query statement below
WITH HighestSalary AS (
    SELECT MAX(salary) AS salary,d.name,d.id
    FROM Employee as e
    JOIN Department as d
    ON (e.departmentId = d.id)
    GROUP BY d.name , d.id
)

SELECT h.name as Department, e.name as Employee, e.salary as Salary
FROM (Employee as e)
JOIN HighestSalary as h
ON (h.id = e.departmentId)
WHERE (e.salary = h.salary AND e.departmentId=h.id)
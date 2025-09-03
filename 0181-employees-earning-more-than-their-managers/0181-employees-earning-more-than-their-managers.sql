/* Write your T-SQL query statement below */
SELECT  
E.name AS Employee
FROM 
Employee as E
JOIN Employee as M
ON E.managerId = M.id
WHERE M.salary < E.salary


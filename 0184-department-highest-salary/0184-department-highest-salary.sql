/* Write your T-SQL query statement below */

SELECT 
departmentName as Department ,
employeeName as Employee , 
salary
 FROM

(SELECT 
RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) as rankOnSalary,
salary ,
Employee.name as employeeName,
departmentId ,
department.name as departmentName
FROM 
Employee
LEFT JOIN Department 
ON Employee.departmentId = Department.id) t
WHERE rankOnSalary = 1


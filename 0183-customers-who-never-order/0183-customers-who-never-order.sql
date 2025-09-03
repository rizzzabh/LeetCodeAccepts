/* Write your T-SQL query statement below */
SELECT 
CC.name as Customers 
FROM 
Customers as CC
WHERE CC.id NOT IN
(
SELECT 
C.id
FROM 
Customers as C
JOIN Orders as O
ON C.id = O.customerId
) ;
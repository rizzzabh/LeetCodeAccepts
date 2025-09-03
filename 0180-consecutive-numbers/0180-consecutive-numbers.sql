/* Write your T-SQL query statement below */
SELECT DISTINCT 
currNum as ConsecutiveNums
FROM
(
SELECT 
LAG (num) OVER (ORDER BY id)AS prevNum , 
num AS currNum , 
LEAD (num) OVER(ORDER BY id) AS nextNum 
FROM 
Logs ) t 
WHERE prevNum = currNum AND currNum = nextNum 

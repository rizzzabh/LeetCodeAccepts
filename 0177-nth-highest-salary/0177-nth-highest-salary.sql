CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    SELECT  DISTINCT salary 
    FROM (
        SELECT DISTINCT
            id , 
            salary , 
            DENSE_RANK () OVER (ORDER BY salary DESC ) AS RankPosition
            
        FROM Employee 
    )t 
    WHERE RankPosition = N
  );
END
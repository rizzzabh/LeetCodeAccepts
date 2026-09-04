WITH DiffTable AS (
    SELECT
    player_id,
    DATEDIFF(event_date , LAG (event_date,1) OVER (PARTITION BY player_id ORDER BY event_date)) as diff,
    RANK() OVER (PARTITION BY player_id ORDER BY event_date) as dayNumber
    FROM Activity
),

PlayerIdWithConsecutiveDaysLogin AS (
SELECT DISTINCT player_id
FROM DiffTable
WHERE (diff=1 AND dayNumber=2))

SELECT
ROUND(COUNT(DISTINCT pwc.player_id)/COUNT(DISTINCT ac.player_id),2)as fraction   
FROM Activity as ac
LEFT JOIN PlayerIdWithConsecutiveDaysLogin as pwc
ON ac.player_id = pwc.player_id

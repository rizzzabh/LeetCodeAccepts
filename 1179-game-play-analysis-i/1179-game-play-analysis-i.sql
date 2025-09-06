/* Write your T-SQL query statement below */

SELECT 
player_id ,
event_date as first_login
FROM 
(SELECT 
device_id , 
games_played ,
player_id , 
ROW_NUMBER () OVER(PARTITION BY player_id ORDER BY event_date ASC) as firstLogin , 
event_date
FROM Activity ) t 
where t.firstLogin = 1
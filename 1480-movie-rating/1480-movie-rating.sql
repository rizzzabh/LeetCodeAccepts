
(SELECT
t.userName as results 
FROM
(SELECT
COUNT(u.user_id) OVER(PARTITION BY u.user_id) as ratingCount,
u.name as userName
FROM
MovieRating as m
JOIN Users as u
ON m.user_id = u.user_id
)t
ORDER BY t.ratingCount DESC,userName ASC
LIMIT 1 )

UNION ALL

(SELECT
f.movieTitle as results
FROM 
(SELECT
AVG(t.rating) OVER (PARTITION BY t.movie_id) as averageRating , 
t.movie_id ,
Movies.title as movieTitle
FROM (
      SELECT * 
      FROM 
      MovieRating
      WHERE
      MONTH(created_at) = 2 AND YEAR(created_at)=2020
)t 
JOIN Movies
ON t.movie_id = Movies.movie_id
)f
ORDER BY averageRating DESC ,movieTitle ASC
LIMIT 1)
;


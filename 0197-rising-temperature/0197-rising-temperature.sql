SELECT Id
FROM (
    SELECT 
        Id,
        Temperature,
        RecordDate,
        LAG(Temperature) OVER (ORDER BY RecordDate) AS PrevTemp,
        LAG(RecordDate) OVER (ORDER BY RecordDate) AS PrevDate
    FROM Weather
) t
WHERE PrevTemp IS NOT NULL
  AND Temperature > PrevTemp
  AND DATEDIFF(DAY, PrevDate, RecordDate) = 1;


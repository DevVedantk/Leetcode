# Write your MySQL query statement below
SELECT today.id from Weather today CROSS JOIN Weather yesterday
WHERE DATEDIFF(today.recordDate,yesterday.recordDate)=1 AND today.temperature>yesterday.temperature;
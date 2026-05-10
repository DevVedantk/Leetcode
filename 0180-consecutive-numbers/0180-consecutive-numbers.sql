# Write your MySQL query statement below
SELECT DISTINCT num as ConsecutiveNums FROM (SELECT num,LAG(num) OVER (order by id) as prev,
           LEAD(num) OVER (order by id) as next from Logs) t where num=t.prev AND num=t.next;
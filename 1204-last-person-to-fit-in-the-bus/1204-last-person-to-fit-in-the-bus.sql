# Write your MySQL query statement below
SELECT person_name FROM (SELECT person_name,SUM(weight) OVER (ORDER BY turn) as running_t FROM Queue) t where t.running_t<=1000 order by running_t desc LIMIT 1;

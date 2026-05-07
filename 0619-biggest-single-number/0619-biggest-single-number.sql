# Write your MySQL query statement below
SELECT  MAX(myn.num) as num FROM (SELECT COUNT(num) as cnt,num FROM MyNumbers group by num) myn WHERE cnt=1;
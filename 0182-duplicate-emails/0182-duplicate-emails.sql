# Write your MySQL query statement below
SELECT dup.email FROM (SELECT email,COUNT(email) as cnt FROM Person group by email) dup where dup.cnt>1;
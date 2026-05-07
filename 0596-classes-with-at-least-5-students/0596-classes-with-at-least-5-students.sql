# Write your MySQL query statement below
select cls.class FROM (SELECT COUNT(DISTINCT student) as cnt,class FROM Courses group by class) cls where cls.cnt>=5;
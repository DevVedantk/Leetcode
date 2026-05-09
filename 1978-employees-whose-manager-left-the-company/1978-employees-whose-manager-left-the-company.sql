# Write your MySQL query statement below
SELECT employee_id FROM Employees where salary<30000 AND manager_id is NOT NULL AND manager_id NOT IN (SELECT employee_id FROM Employees) order by employee_id;
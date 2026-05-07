# Write your MySQL query statement below
SELECT DISTINCT s.product_id,fy.first_year,s.quantity, s.price FROM (SELECT product_id,MIN(year) as first_year FROM Sales GROUP BY product_id) fy LEFT JOIN Sales s on s.year=fy.first_year AND s.product_id=fy.product_id;

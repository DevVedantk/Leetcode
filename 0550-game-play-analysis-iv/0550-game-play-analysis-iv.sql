# Write your MySQL query statement below
SELECT ROUND(COUNT(CASE WHEN ac.event_date=DATE_ADD(st.start, INTERVAL 1 DAY) THEN 1 END)/COUNT(DISTINCT ac.player_id),2) as fraction FROM Activity ac LEFT JOIN (SELECT MIN(event_date) as start,player_id FROM Activity group by player_id) st ON ac.player_id=st.player_id;

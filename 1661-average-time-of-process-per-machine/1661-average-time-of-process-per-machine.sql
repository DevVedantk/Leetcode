# Write your MySQL query statement below
SELECT data.machine_id,ROUND(((data.total_end-data.total_st)/(no_of_mach/2)),3) as processing_time FROM (SELECT  machine_id,COUNT(machine_id) as no_of_mach,
SUM(CASE WHEN activity_type='start' THEN timestamp ELSE 0 END) as total_st,
SUM(CASE WHEN activity_type='end' THEN timestamp ELSE 0 END) as total_end
from Activity group by machine_id) data;
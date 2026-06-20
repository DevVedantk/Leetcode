SELECT pt.patient_id,pt.patient_name,pt.age,DATEDIFF(fres.first_neg,fres.first_pos) as recovery_time FROM patients as pt RIGHT JOIN (SELECT 
    cts.patient_id,
    res.first_pos,
    MIN(cts.test_date) AS first_neg
FROM covid_tests AS cts
LEFT JOIN (
    SELECT patient_id,
           MIN(test_date) AS first_pos
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
) AS res
ON res.patient_id = cts.patient_id
WHERE cts.result = 'Negative' AND cts.test_date >= res.first_pos
GROUP BY cts.patient_id, res.first_pos) as fres ON fres.patient_id=pt.patient_id ORDER BY recovery_time,pt.patient_name;
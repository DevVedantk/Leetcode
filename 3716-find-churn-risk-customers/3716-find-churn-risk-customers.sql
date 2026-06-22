# Write your MySQL query statement below
(SELECT res.user_id,res.plan_name as current_plan,res.monthly_amount as current_monthly_amount,res.max_amt as max_historical_amount,res.days as days_as_subscriber FROM (SELECT user_id,event_date,plan_name,DATEDIFF(
    MAX(event_date) OVER(PARTITION BY user_id),
    MIN(event_date) OVER(PARTITION BY user_id)
) AS days,event_type,ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY event_date desc) as rnk,monthly_amount,MAX(monthly_amount) OVER(PARTITION BY user_id) AS max_amt FROM subscription_events WHERE user_id IN (
    SELECT user_id
    FROM subscription_events
    WHERE event_type = 'downgrade'
)) as res where res.rnk=1 and res.event_type!='cancel' and res.days>=60 and ((res.monthly_amount/res.max_amt)*100)<50 ORDER BY days_as_subscriber DESC,user_id);
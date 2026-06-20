SELECT
    ua.user_id,
    trail.trial_avg_duration,
    ROUND(AVG(ua.activity_duration), 2) AS paid_avg_duration
FROM UserActivity AS ua
RIGHT JOIN (
    SELECT
        user_id,
        activity_type,
        ROUND(AVG(activity_duration), 2) AS trial_avg_duration
    FROM UserActivity
    WHERE activity_type = 'free_trial'
    GROUP BY user_id
) AS trail
    ON trail.user_id = ua.user_id
WHERE ua.activity_type = 'paid'
GROUP BY ua.user_id
ORDER BY ua.user_id;
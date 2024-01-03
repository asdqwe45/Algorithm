-- 코드를 입력하세요
SELECT MONTH(START_DATE) AS MONTH
     , CAR_ID
     , COUNT(HISTORY_ID) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE CAR_ID IN (SELECT CAR_ID
                 FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                 WHERE MONTH(START_DATE) IN (8,9,10)
                 GROUP BY CAR_ID
                 HAVING COUNT(HISTORY_ID) >=5)
      AND MONTH(START_DATE) IN (8,9,10)
GROUP BY 1,2
HAVING COUNT(*) >= 1
ORDER BY 1 ASC, CAR_ID DESC
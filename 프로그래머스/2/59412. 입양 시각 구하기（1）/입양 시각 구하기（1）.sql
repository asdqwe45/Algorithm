-- 코드를 입력하세요
SELECT Extract(Hour FROM DATETIME) AS hour, COUNT(*)
FROM ANIMAL_OUTS
GROUP BY Extract(Hour from DATETIME)
HAVING hour BETWEEN 9 AND 19
ORDER BY Extract(Hour from DATETIME)
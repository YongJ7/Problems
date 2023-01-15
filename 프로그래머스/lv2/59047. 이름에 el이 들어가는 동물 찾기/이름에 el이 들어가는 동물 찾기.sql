-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
FROM ANIMAL_INS
where animal_type = 'dog' and name like '%el%'
order by name
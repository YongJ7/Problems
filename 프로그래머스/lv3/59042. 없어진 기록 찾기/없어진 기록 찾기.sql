-- 코드를 입력하세요
SELECT outs.animal_id, outs.name
from animal_ins as ins
right join animal_outs as outs
on ins.animal_id = outs.animal_id
where ins.animal_id is null

/*select animal_outs.animal_id, animal_outs.name
from animal_ins, animal_outs
where animal_outs.animal_id=animal_ins.animal_id and animal_ins.animal_id is nul
*/
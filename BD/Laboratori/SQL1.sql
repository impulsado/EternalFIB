-- Pregunta 1
select distinct  d.NUM_DPT, d.NOM_DPT
FROM DEPARTAMENTS d INNER JOIN EMPLEATS e ON d.NUM_DPT=e.NUM_DPT
WHERE d.CIUTAT_DPT = 'MADRID' AND e.SOU > 200000

-- Pregunta 2
select d.NOM_DPT, p.NOM_PROJ
from DEPARTAMENTS d 
	inner join EMPLEATS e on d.num_dpt = e.num_dpt
	inner join PROJECTES p on p.num_proj = e.num_proj 
where e.num_empl = 2

-- Pregunta 3
select d.NUM_DPT, d.NOM_DPT, AVG(e.SOU)
from departaments d INNER join empleats e on d.num_dpt = e.num_dpt
where d.ciutat_dpt = 'MADRID'
group by d.num_dpt
-- Pregunta 1
select distinct d.NUM_DPT, d.NOM_DPT
from departaments d
where d.NUM_DPT not in (
	select ee.NUM_DPT
	from empleats ee
	where ee.ciutat_empl = 'MADRID' and ee.NUM_DPT = d.NUM_DPT
);

-- Pregunta 2
select distinct e.CIUTAT_EMPL
from empleats e
where e.ciutat_empl not in (
	select distinct dd.CIUTAT_DPT
	from departaments dd
);

-- Pregunta 3
select d.NUM_DPT, d.NOM_DPT
from departaments d
where 2<= (
	select count(*)
	from empleats ee
	where ee.num_dpt = d.num_dpt and ee.CIUTAT_EMPL not in (
		select eee.CIUTAT_EMPL
		from empleats eee
		where eee.NUM_DPT = d.num_dpt and eee.num_empl != ee.num_empl
	)
);

-- Pregunta 4
CREATE TABLE comandes(
	numComanda INTEGER, 
	instantComanda INTEGER NOT NULL, 
	client CHAR(30), 
	encarregat INTEGER NOT NULL, 
	supervisor INTEGER,

	PRIMARY KEY (numComanda),
	UNIQUE (instantComanda, client),
	FOREIGN KEY (encarregat) REFERENCES EMPLEATS (NUM_EMPL),
	FOREIGN KEY (supervisor) REFERENCES EMPLEATS (NUM_EMPL)
);

CREATE TABLE productesComprats(
	numComanda INTEGER NOT NULL,
	producte CHAR(20),
	quantitat INTEGER NOT NULL DEFAULT 1,
	preu INTEGER,
	PRIMARY KEY (numComanda, producte),
	FOREIGN KEY (numComanda) REFERENCES comandes (numComanda)
);
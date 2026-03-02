USE movies

--1
SELECT * FROM MOVIE
CROSS JOIN MOVIEEXEC

--2
SELECT * FROM MOVIE AS m
INNER JOIN MOVIEEXEC AS me ON m.PRODUCERC#=me.CERT#

--3
SELECT * FROM MOVIESTAR AS ms1, MOVIESTAR AS ms2
WHERE ms1.ADDRESS = ms2.ADDRESS
AND ms1.NAME != ms2.NAME

--q1 UNION q2 INTERSECT q3 -> intersect executes first

SELECT NAME, ADDRESS FROM MOVIESTAR
WHERE GENDER='F'
INTERSECT
SELECT NAME, ADDRESS FROM MOVIEEXEC

-- ===================================================

--1
SELECT ms.NAME FROM MOVIESTAR AS ms
JOIN STARSIN AS s ON ms.NAME = s.STARNAME
WHERE ms.GENDER = 'M' AND s.MOVIETITLE = 'The Usual Suspects'

--2
SELECT ms.NAME FROM MOVIESTAR AS ms
JOIN STARSIN AS s ON ms.NAME = s.STARNAME
JOIN MOVIE AS m ON m.TITLE = s.MOVIETITLE
WHERE m.YEAR = 1995 AND m.STUDIONAME = 'MGM'

--3
SELECT DISTINCT me.NAME FROM MOVIEEXEC AS me
JOIN MOVIE AS m ON me.CERT#=m.PRODUCERC#
WHERE m.STUDIONAME = 'MGM'

--4
SELECT m1.TITLE FROM MOVIE AS m1, MOVIE AS m2
WHERE m2.TITLE = 'Star Wars' AND m1.LENGTH>m2.LENGTH

--5
SELECT me1.NAME FROM MOVIEEXEC AS me1, MOVIEEXEC AS me2
WHERE me2.NAME = 'Stephen Spielberg' AND me1.NETWORTH>me2.NETWORTH

--1
USE pc
SELECT p.maker, l.speed FROM laptop AS l
JOIN product AS p ON p.model = l.model
WHERE l.hd >= 9

--2
SELECT p.model, l.price FROM product AS p
JOIN laptop AS l ON p.model = l.model
WHERE p.maker = 'B'
UNION
SELECT p.model, l.price FROM product AS p
JOIN pc AS l ON p.model = l.model
WHERE p.maker = 'B'
UNION
SELECT p.model, l.price FROM product AS p
JOIN printer AS l ON p.model = l.model
WHERE p.maker = 'B'

--3
SELECT p.maker FROM product AS p
JOIN laptop AS l ON l.model = p.model
EXCEPT
SELECT p.maker FROM product AS p
JOIN pc ON pc.model = p.model

--4
SELECT DISTINCT pc1.hd FROM pc AS pc1, pc AS pc2
WHERE pc1.hd = pc2.hd AND pc1.code != pc2.code

--5
SELECT pc1.model, pc2.model FROM pc AS pc1, pc AS pc2
WHERE pc1.ram = pc2.ram AND pc1.speed = pc2.speed
AND pc1.model > pc2.model

--6 -wrong
SELECT pr.maker FROM product as pr, pc as pc1, pc as pc2
WHERE pc1.speed>=400 AND pc2.speed>400
AND pc1.model>pc2.model
AND pc1.model = pr.model
AND pc2.model = pr.model

--1
USE ships
SELECT s.NAME FROM SHIPS AS s
JOIN CLASSES AS c ON c.CLASS = s.CLASS
WHERE c.DISPLACEMENT>50000

--2
SELECT s.NAME, c.DISPLACEMENT, c.NUMGUNS FROM SHIPS AS s
JOIN CLASSES AS c ON c.CLASS = s.CLASS
JOIN OUTCOMES AS o ON o.SHIP=s.NAME
JOIN BATTLES AS b ON b.NAME=o.BATTLE
WHERE b.NAME='Guadalcanal'

--3
SELECT c1.COUNTRY FROM CLASSES AS c1, CLASSES AS c2
WHERE c1.TYPE ='bb' AND c2.TYPE='bc'
AND c1.COUNTRY=c2.COUNTRY

--4
SELECT s.NAME FROM SHIPS AS s
JOIN OUTCOMES AS o1 ON o1.SHIP=s.NAME
JOIN OUTCOMES AS o2 ON o2.SHIP=s.NAME
WHERE o1.RESULT='damaged' AND o1.BATTLE<>o2.BATTLE
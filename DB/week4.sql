USE movies

SELECT AVG(NETWORTH) FROM MOVIEEXEC

SELECT COUNT(*) FROM STARSIN

SELECT me.NAME AS prodname, SUM(m.LENGTH) as movielensum FROM MOVIE AS m
JOIN MOVIEEXEC AS me ON m.PRODUCERC#=me.CERT#
WHERE me.NETWORTH>1000000
GROUP BY me.NAME
HAVING MIN(YEAR)<1980

--1
USE pc

SELECT CONVERT(decimal(5,2), AVG(speed)) AS AvgSpeed FROM pc

--2
SELECT p.maker, AVG(l.screen) AS AvgScreen  FROM product AS p
JOIN laptop AS l ON l.model = p.model
GROUP BY p.maker

--3
SELECT CONVERT(decimal(5,2), AVG(l.speed)) AS AvgSpeed FROM laptop AS l
WHERE l.price>1000

--4
SELECT p.maker, CONVERT(decimal(5,2), AVG(pc.price)) AS AvgPrice FROM pc
JOIN product AS p ON p.model = pc.model
GROUP BY p.maker
HAVING p.maker = 'A'

--5
SELECT p.maker,  ((SUM(pc.price) + SUM(l.price))/ (COUNT(pc.price)+COUNT(l.price))) AS AvgPrice FROM product AS p
LEFT JOIN pc ON p.model=pc.model
LEFT JOIN laptop AS l ON p.model = l.model
GROUP BY p.maker
HAVING p.maker = 'B'

--6
SELECT speed, AVG(price) AS AvgPrice FROM pc
GROUP BY speed

--7
SELECT p.maker, COUNT(pc.code) AS number_of_pc FROM product AS p
JOIN pc ON pc.model = p.model
GROUP BY p.maker
HAVING COUNT(pc.code)>=3

--8
SELECT p.maker FROM product AS p
JOIN pc ON pc.model = p.model
GROUP BY p.maker
HAVING MAX(pc.price) = (SELECT MAX(pc.price) FROM pc)

--9
SELECT pc.speed, AVG(pc.price) AS AvgPrice FROM pc
GROUP BY pc.speed
HAVING pc.speed>800

--10
SELECT p.maker, CONVERT(decimal(4,2), AVG (pc.hd)) AS AvgHDD FROM product AS p
JOIN pc ON pc.model = p.model
GROUP BY p.maker
HAVING p.maker = ANY(SELECT p2.maker FROM product AS p2
JOIN printer AS pr ON pr.model = p.model)
USE movies

--1
INSERT INTO MOVIESTAR(NAME, BIRTHDATE) VALUES ('Nicole Kidman', '1967-06-20')

--2
DELETE FROM MOVIEEXEC WHERE NETWORTH<30000000

--3
DELETE FROM MOVIESTAR WHERE ADDRESS IN ('A way', 'X path')

--4
USE pc
INSERT INTO pc VALUES ('1100', 2400, 2048, 500, '52x', 299)
INSERT INTO product VALUES ('C', '1100', 'PC')

--5
DELETE FROM pc WHERE model='1100'

--6
DELETE FROM laptop WHERE model IN (SELECT l.model FROM laptop AS l
JOIN product AS p ON p.model = l.model WHERE p.maker NOT IN(SELECT p2.maker FROM product AS p2
WHERE p2.type = 'Printer'
GROUP BY p2.maker))

--7
UPDATE product SET maker = 'A' WHERE maker = 'B'

--8
UPDATE pc SET price=(price/2), hd=(hd+20)

--9
UPDATE laptop SET screen=(screen+1) WHERE model IN (SELECT l.model FROM laptop AS l
JOIN product AS p ON l.model = p.model WHERE p.maker='B')

--10
USE ships
INSERT INTO SHIPS VALUES ('Nelson', 'Nelson', 1927), ('Rodney', 'Nelson', 1927)
INSERT INTO CLASSES(CLASS, BORE, DISPLACEMENT) VALUES ('Nelson', 16, 34000)

--11
DELETE FROM SHIPS WHERE NAME IN (SELECT s.NAME FROM SHIPS AS s JOIN OUTCOMES AS o ON o.SHIP=s.NAME WHERE o.RESULT='sunk')

--12
UPDATE CLASSES SET BORE=(BORE*2.5), DISPLACEMENT=(DISPLACEMENT/1.1)
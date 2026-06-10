CREATE DATABASE FurnitureCompany

USE FurnitureCompany

--1
CREATE TABLE CUSTOMER (
	Customer_ID INT PRIMARY KEY IDENTITY,
	Customer_Name NVARCHAR(50) NOT NULL,
	Customer_Address NVARCHAR(50) NOT NULL,
	Customer_City NVARCHAR(50) NOT NULL,
	City_Code INT CHECK(City_Code BETWEEN 1000 AND 9999)
)

CREATE TABLE PRODUCT (
	Product_ID INT PRIMARY KEY,
	Product_Description NVARCHAR(256) NOT NULL,
	Product_Finish NVARCHAR(50) CHECK
	(Product_Finish IN ( 'череша', 'естествен ясен', 'бял ясен','червен дъб', 'естествен дъб', 'орех')),
	Standard_Price DECIMAL(7,2) NOT NULL,
	Product_Line_ID INT 
)

CREATE TABLE ORDER_T(
	Order_ID INT PRIMARY KEY,
	Order_Date DATE DEFAULT(GETDATE()),
	Customer_ID INT FOREIGN KEY REFERENCES CUSTOMER(Customer_ID)
)

CREATE TABLE ORDER_LINE (
	Order_ID INT FOREIGN KEY REFERENCES ORDER_T(Order_ID),
	Product_ID INT FOREIGN KEY REFERENCES PRODUCT(Product_ID),
	Ordered_Quantity INT CHECK(Ordered_Quantity >= 0)
)

insert into CUSTOMER values
('Иван Петров', 'ул. Лавеле 8', 'София', '1000'),
('Камелия Янева', 'ул. Иван Шишман 3', 'Бургас', '8000'),
('Васил Димитров', 'ул. Абаджийска 87', 'Пловдив', '4000'),
('Ани Милева', 'бул. Владислав Варненчик 56', 'Варна','9000');
insert into PRODUCT values
(1000, 'офис бюро', 'череша', 195, 10),
(1001, 'директорско бюро', 'червен дъб', 250, 10),
(2000, 'офис стол', 'череша', 75, 20),
(2001, 'директорски стол', 'естествен дъб', 129, 20),
(3000, 'етажерка за книги', 'естествен ясен', 85, 30),
(4000, 'настолна лампа', 'естествен ясен', 35, 40);
insert into ORDER_T values
(100, '2013-01-05', 1),
(101, '2013-12-07', 2),
(102, '2014-10-03', 3),
(103, '2014-10-08', 2),
(104, '2015-10-05', 1),
(105, '2015-10-05', 4),
(106, '2015-10-06', 2),
(107, '2016-01-06', 1);
insert into ORDER_LINE values
(100, 4000, 1),
(101, 1000, 2),
(101, 2000, 2),
(102, 3000, 1),
(102, 2000, 1),
(106, 4000, 1),
(103, 4000, 1),
(104, 4000, 1),
(105, 4000, 1),
(107, 4000, 1);

--2
SELECT p.Product_ID, p.Product_Description, COUNT(*) FROM PRODUCT AS p
JOIN ORDER_LINE AS ol ON p.Product_ID = ol.Product_ID
GROUP BY p.Product_ID, p.Product_Description

--3
SELECT p.Product_ID, p.Product_Description, ISNULL(SUM(ol.Ordered_Quantity),0) FROM PRODUCT AS p
LEFT JOIN ORDER_LINE AS ol ON p.Product_ID = ol.Product_ID
GROUP BY p.Product_ID, p.Product_Description

--4
SELECT c.Customer_Name, SUM(p.Standard_Price*ol.Ordered_Quantity) FROM CUSTOMER AS c
JOIN ORDER_T AS ot ON ot.Customer_ID = c.Customer_ID
JOIN ORDER_LINE AS ol ON ot.Order_ID = ol.Order_ID
JOIN PRODUCT AS p ON p.Product_ID = ol.Product_ID
GROUP BY c.Customer_Name

--5
USE pc

SELECT DISTINCT prod.maker FROM product AS prod
WHERE prod.maker IN (
SELECT maker FROM product p2
JOIN printer AS pri ON pri.model = p2.model) AND prod.maker IN (
SELECT maker FROM product p3
JOIN laptop AS l ON l.model = p3.model
)

SELECT DISTINCT p1.maker FROM product p1
JOIN product p2 ON p1.maker = p2.maker
JOIN printer pr ON p2.model = pr.model
JOIN laptop l ON p1.model = l.model

--6
UPDATE pc
SET price = price*0.95
WHERE model IN (
SELECT p1.model FROM pc p1
JOIN product p2 ON p2.model=p1.model
WHERE p2.maker IN (SELECT p3.maker FROM product p3
JOIN printer p4 ON p4.model=p3.model
GROUP BY p3.maker
HAVING AVG(p4.price)>800)
)

--7

SELECT hd, MIN(price) FROM pc
GROUP BY hd
HAVING hd BETWEEN 10 AND 30

--8
USE ships

CREATE VIEW zad8a
AS 
SELECT o.BATTLE FROM OUTCOMES AS o
JOIN SHIPS s ON s.NAME = o.SHIP
GROUP BY o.BATTLE
HAVING COUNT(*) > (SELECT COUNT(*) FROM OUTCOMES o2
JOIN SHIPS s2 ON s2.NAME = o2.SHIP
WHERE o2.BATTLE = 'Guadalcanal')

CREATE VIEW zad8b
AS
SELECT o.BATTLE FROM OUTCOMES AS o
JOIN SHIPS s ON s.NAME = o.SHIP
JOIN CLASSES c ON c.CLASS = s.CLASS
GROUP BY o.BATTLE, c.COUNTRY
HAVING COUNT(*) > (SELECT COUNT(*) FROM OUTCOMES o2
JOIN SHIPS s2 ON s2.NAME = o2.SHIP
JOIN CLASSES c2 ON c2.CLASS = s2.CLASS
WHERE o2.BATTLE = 'Guadalcanal')

--9
DELETE FROM OUTCOMES
WHERE BATTLE IN (SELECT o.BATTLE FROM OUTCOMES o
GROUP BY o.BATTLE
HAVING COUNT(*) = 1)

--10
DELETE FROM OUTCOMES
WHERE SHIP IN (SELECT o.SHIP FROM OUTCOMES o
WHERE o.RESULT = 'sunk'
GROUP BY o.SHIP
HAVING COUNT(*)>=2) AND RESULT = 'sunk'

--11 from hris
GO

CREATE VIEW v_Battles_Countries 
AS
SELECT DISTINCT o.BATTLE, c.COUNTRY
FROM OUTCOMES AS o
JOIN SHIPS AS s ON o.SHIP = s.NAME
JOIN CLASSES AS c ON s.CLASS = c.CLASS

GO

SELECT v.BATTLE
FROM v_Battles_Countries AS v
WHERE v.BATTLE <> 'Guadalcanal'
AND v.COUNTRY IN (
    SELECT v2.COUNTRY
    FROM v_Battles_Countries AS v2
    WHERE v2.BATTLE = 'Guadalcanal'
)
GROUP BY v.BATTLE
HAVING COUNT(v.COUNTRY) = (
    SELECT COUNT(v3.COUNTRY)
    FROM v_Battles_Countries AS v3
    WHERE v3.BATTLE = 'Guadalcanal'
)

--12
SELECT c.COUNTRY, ISNULL(COUNT(o.BATTLE), 0) FROM OUTCOMES o 
JOIN SHIPS s ON s.NAME = o.SHIP
RIGHT JOIN CLASSES c ON c.CLASS = s.CLASS
GROUP BY c.COUNTRY
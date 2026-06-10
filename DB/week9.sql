--1
USE master
CREATE TABLE Product (
	model CHAR(4),
	maker CHAR(1),
	type VARCHAR(7)
)

CREATE TABLE Printer (
	model CHAR(4),
	code INT,
	price DECIMAL(7,2)
)

INSERT INTO Product VALUES('aaaa', 'b', 'ccc')
INSERT INTO Printer VALUES('aaaa', 1234, 1233.94)

ALTER TABLE Printer ADD type VARCHAR(6) CHECK (type IN ('laser', 'matrix', 'jet')),
color CHAR(1) DEFAULT 'n' CHECK (color IN ('y','n'))

ALTER TABLE Printer DROP COLUMN price

DROP TABLE Printer, Product

--2
CREATE TABLE Users (
	id INT PRIMARY KEY IDENTITY,
	email VARCHAR(100) NOT NULL CHECK(email LIKE '%@%.%'),
	password VARCHAR(32) NOT NULL CHECK(LEN(password)>8),
	regDate DATE DEFAULT(GETDATE())
)

CREATE TABLE Friends (
	id1 INT  FOREIGN KEY (id1) REFERENCES Users(id),
	id2 INT FOREIGN KEY (id2) REFERENCES Users(id)
	CONSTRAINT pk_f1 PRIMARY KEY (id1, id2)
)

CREATE TABLE Walls (
	id INT PRIMARY KEY FOREIGN KEY (id) REFERENCES Users(id),
	posterId INT FOREIGN KEY (posterId) REFERENCES Users(id),
	content VARCHAR(256) NOT NULL,
	postDate DATE DEFAULT(GETDATE())
)

CREATE TABLE Groups (
	id INT PRIMARY KEY IDENTITY,
	name VARCHAR(32) UNIQUE NOT NULL,
	description VARCHAR(256) DEFAULT NULL
)

CREATE TABLE GroupMembers (
	id1 INT  FOREIGN KEY (id1) REFERENCES Groups(id),
	id2 INT FOREIGN KEY (id2) REFERENCES Users(id)
	CONSTRAINT pk_f1 PRIMARY KEY (id1, id2)
)
USE foo

DROP TABLE track;

CREATE TABLE track (
	username VARCHAR(8),
	project VARCHAR(8),
	startDate DATE,
	endDate DATE
)


CREATE TABLE ms (
	name VARCHAR(30) PRIMARY KEY,
	address VARCHAR(200),
	gender CHAR(1),
	birthdate DATE DEFAULT GETDATE()
)

INSERT INTO ms(name) VALUES ('Brad Pitt')
INSERT INTO ms(address) VALUES ('22 Acacia Ave')

CREATE TABLE mv(
	title VARCHAR(30),
	year INT,
	length INT,
	color CHAR(1),
	--CONSTRAINT uc_mv1 UNIQUE(title, year)
	CONSTRAINT pk_mv2 PRIMARY KEY(title, year),
	CONSTRAINT ck_mv3 CHECK(color = 'y' OR year < 1930)
)

CREATE TABLE si (
	id INT IDENTITY PRIMARY KEY,
	mtitle VARCHAR(30),
	myear INT,
	sname VARCHAR(30)
)

ALTER TABLE si ADD CONSTRAINT fk_si_16 FOREIGN KEY(sname) REFERENCES ms(name)

ALTER TABLE si DROP CONSTRAINT fk_si_16

---

CREATE TABLE track (
	id INT IDENTITY PRIMARY KEY,
	username VARCHAR(8) NOT NULL,
	project VARCHAR(8) NOT NULL,
	startDate DATE NOT NULL,
	endDate DATE NOT NULL,
	CONSTRAINT u_t1 UNIQUE(username, project, startDate, endDate),
	CONSTRAINT ch_t1 CHECK(startDate <= endDate)
)

---

--− Printer (code, model, price), където:
--− код е цяло число,
--− модел е низ от точно 4 символа,
--− цена с точност до два знака след десетичната запетая;
--б) Добавете кортежи с примерни данни към новосъздадените релации.
--в) Добавете към релацията Printer атрибути:
--− type - низ до 6 символа (забележка: type може да приема стойност
--'laser', 'matrix' или 'jet'),
--− color - низ от точно 1 символ, стойност по подразбиране 'n'
--(забележка: color може да приема стойност 'y' или 'n').
--г) Напишете заявка, която премахва атрибута price от релацията Printer.
--д) Изтрийте релациите, които сте създали в Задача 1.

CREATE TABLE product(
	maker CHAR(1),
	model CHAR(4),
	type VARCHAR(7)
)

CREATE TABLE printer(
	code INT,
	model CHAR(4),
	price DECIMAL(7,2)
)

INSERT INTO product VALUES('a', 'abcd', 'aaaaa')

ALTER TABLE printer ADD laser VARCHAR(6)

ALTER TABLE product
ADD CONSTRAINT ch_prod1 CHECK (type IN ('laser', 'matrix', 'jet'))

ALTER TABLE printer ADD color CHAR(1) DEFAULT 'n'
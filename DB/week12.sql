USE Flights

--1
ALTER TABLE Flight ADD num_pass INT DEFAULT 0

UPDATE f
SET num_pass = (
    SELECT COUNT(*) FROM Booking AS b
    WHERE b.FLIGHT_NUMBER = f.FNUMBER AND b.STATUS = 1
)
FROM Flight AS f

CREATE TRIGGER trg_num_pass
ON Booking
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    UPDATE Flight
    SET num_pass = num_pass - 1
    FROM Flight f
    JOIN deleted d ON f.FNUMBER = d.FLIGHT_NUMBER
    WHERE d.STATUS = 1;

    UPDATE Flight
    SET num_pass = num_pass + 1
    FROM Flight f
    JOIN inserted i ON f.FNUMBER = i.FLIGHT_NUMBER
    WHERE i.STATUS = 1;
END;

--2
ALTER TABLE Agency ADD num_book INT DEFAULT 0

UPDATE a
SET num_book = (
SELECT COUNT(*) FROM Booking AS b
WHERE b.AGENCY = a.NAME)
FROM Agency AS a

CREATE TRIGGER trg_num_book ON Booking
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    UPDATE Agency
    SET num_book = num_book + 1
    FROM Agency a
    JOIN inserted i ON i.AGENCY = a.NAME

    UPDATE Agency
    SET num_book = num_book - 1
    FROM Agency a
    JOIN deleted d ON d.AGENCY = a.NAME
END;

--3
--already done?

--4
--already done?

--5
--already done?
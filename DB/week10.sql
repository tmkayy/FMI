-- Create Database
CREATE DATABASE Flights;
GO
USE Flights;
GO

-- =====================
-- CREATE TABLES
-- =====================

CREATE TABLE Airline (
    CODE        VARCHAR(10)     NOT NULL,
    NAME        VARCHAR(100)    NOT NULL,
    COUNTRY     VARCHAR(50)     NOT NULL,

    CONSTRAINT PK_Airline PRIMARY KEY (CODE),
    CONSTRAINT UQ_Airline_Name UNIQUE (NAME)
);

CREATE TABLE Airport (
    CODE        VARCHAR(10)     NOT NULL,
    NAME        VARCHAR(100)    NOT NULL,
    COUNTRY     VARCHAR(50)     NOT NULL,
    CITY        VARCHAR(50)     NOT NULL,

    CONSTRAINT PK_Airport PRIMARY KEY (CODE),
    CONSTRAINT UQ_Airport_Name_Country UNIQUE (NAME, COUNTRY)
);

CREATE TABLE Airplane (
    CODE        VARCHAR(10)     NOT NULL,
    TYPE        VARCHAR(50)     NOT NULL,
    SEATS       INT             NOT NULL,
    YEAR        INT             NOT NULL,

    CONSTRAINT PK_Airplane PRIMARY KEY (CODE),
    CONSTRAINT CHK_Airplane_Seats CHECK (SEATS > 0)
);

CREATE TABLE Customer (
    ID          INT             NOT NULL,
    FNAME       VARCHAR(50)     NOT NULL,
    LNAME       VARCHAR(50)     NOT NULL,
    EMAIL       VARCHAR(100)    NOT NULL,

    CONSTRAINT PK_Customer PRIMARY KEY (ID),
    CONSTRAINT UQ_Customer_Email UNIQUE (EMAIL),
    CONSTRAINT CHK_Customer_Email CHECK (
        LEN(EMAIL) >= 6
        AND EMAIL LIKE '%@%.%'
        AND CHARINDEX('@', EMAIL) > 1
        AND CHARINDEX('.', EMAIL, CHARINDEX('@', EMAIL)) > CHARINDEX('@', EMAIL) + 1
    )
);

CREATE TABLE Agency (
    NAME        VARCHAR(100)    NOT NULL,
    COUNTRY     VARCHAR(50)     NOT NULL,
    CITY        VARCHAR(50)     NOT NULL,
    PHONE       VARCHAR(20)     NULL,

    CONSTRAINT PK_Agency PRIMARY KEY (NAME)
);

CREATE TABLE Flight (
    FNUMBER             VARCHAR(20)     NOT NULL,
    AIRLINE_OPERATOR    VARCHAR(10)     NOT NULL,
    DEP_AIRPORT         VARCHAR(10)     NOT NULL,
    ARR_AIRPORT         VARCHAR(10)     NOT NULL,
    FLIGHT_TIME         TIME            NOT NULL,
    FLIGHT_DURATION     INT             NOT NULL,
    AIRPLANE            VARCHAR(10)     NOT NULL,

    CONSTRAINT PK_Flight PRIMARY KEY (FNUMBER),
    CONSTRAINT FK_Flight_Airline    FOREIGN KEY (AIRLINE_OPERATOR) REFERENCES Airline(CODE),
    CONSTRAINT FK_Flight_DepAirport FOREIGN KEY (DEP_AIRPORT)      REFERENCES Airport(CODE),
    CONSTRAINT FK_Flight_ArrAirport FOREIGN KEY (ARR_AIRPORT)      REFERENCES Airport(CODE),
    CONSTRAINT FK_Flight_Airplane   FOREIGN KEY (AIRPLANE)         REFERENCES Airplane(CODE),
    CONSTRAINT CHK_Flight_Duration  CHECK (FLIGHT_DURATION > 0)
);

CREATE TABLE Booking (
    CODE            VARCHAR(20)     NOT NULL,
    AGENCY          VARCHAR(100)    NOT NULL,
    AIRLINE_CODE    VARCHAR(10)     NOT NULL,
    FLIGHT_NUMBER   VARCHAR(20)     NOT NULL,
    CUSTOMER_ID     INT             NOT NULL,
    BOOKING_DATE    DATE            NOT NULL,
    FLIGHT_DATE     DATE            NOT NULL,
    PRICE           DECIMAL(10,2)   NOT NULL,
    STATUS          INT             NOT NULL DEFAULT 0,

    CONSTRAINT PK_Booking           PRIMARY KEY (CODE),
    CONSTRAINT FK_Booking_Agency    FOREIGN KEY (AGENCY)        REFERENCES Agency(NAME),
    CONSTRAINT FK_Booking_Airline   FOREIGN KEY (AIRLINE_CODE)  REFERENCES Airline(CODE),
    CONSTRAINT FK_Booking_Flight    FOREIGN KEY (FLIGHT_NUMBER) REFERENCES Flight(FNUMBER),
    CONSTRAINT FK_Booking_Customer  FOREIGN KEY (CUSTOMER_ID)   REFERENCES Customer(ID),
    CONSTRAINT CHK_Booking_Status       CHECK (STATUS = 0 OR STATUS = 1),
    CONSTRAINT CHK_Booking_FlightDate   CHECK (FLIGHT_DATE >= BOOKING_DATE),
    CONSTRAINT CHK_Booking_Price        CHECK (PRICE > 0)
);
GO


-- =====================
-- TESTS
-- =====================

-- Insert valid base data
INSERT INTO Airline   VALUES ('BA',   'British Airways',  'UK');
INSERT INTO Airline   VALUES ('LH',   'Lufthansa',        'Germany');
INSERT INTO Airport   VALUES ('LHR',  'Heathrow',         'UK',       'London');
INSERT INTO Airport   VALUES ('FRA',  'Frankfurt Airport','Germany',  'Frankfurt');
INSERT INTO Airplane  VALUES ('A320', 'Airbus A320',      180,        2010);
INSERT INTO Customer  VALUES (1, 'Ivan', 'Petrov', 'ivan.petrov@gmail.com');
INSERT INTO Agency    VALUES ('TravelBG', 'Bulgaria', 'Sofia', '+35929001122');
INSERT INTO Flight    VALUES ('BA123', 'BA', 'LHR', 'FRA', '10:00', 120, 'A320');
INSERT INTO Booking   VALUES ('B001', 'TravelBG', 'BA', 'BA123', 1, '2025-01-01', '2025-06-15', 350.00, 0);

-- Test UQ_Airline_Name: duplicate airline name (should FAIL)
INSERT INTO Airline VALUES ('XX', 'British Airways', 'USA');

-- Test CHK_Airplane_Seats: zero seats (should FAIL)
INSERT INTO Airplane VALUES ('B737', 'Boeing 737', 0, 2015);

-- Test CHK_Customer_Email: invalid email (should FAIL)
INSERT INTO Customer VALUES (2, 'Ana', 'Ivanova', 'notanemail');

-- Test CHK_Booking_FlightDate: flight date before booking date (should FAIL)
INSERT INTO Booking VALUES ('B002', 'TravelBG', 'BA', 'BA123', 1, '2025-06-20', '2025-06-10', 200.00, 1);

-- Test FK_Flight_Airline: non-existent airline (should FAIL)
INSERT INTO Flight VALUES ('ZZ999', 'XX', 'LHR', 'FRA', '08:00', 90, 'A320');

-- Test UQ_Airport_Name_Country: same name + country (should FAIL)
INSERT INTO Airport VALUES ('LH2', 'Heathrow', 'UK', 'London');

-- Test CHK_Booking_Status: invalid status value (should FAIL)
INSERT INTO Booking VALUES ('B003', 'TravelBG', 'BA', 'BA123', 1, '2025-01-01', '2025-07-01', 400.00, 5);

-- Valid booking with status = 1 (should PASS)
INSERT INTO Booking VALUES ('B004', 'TravelBG', 'BA', 'BA123', 1, '2025-01-01', '2025-07-01', 400.00, 1);
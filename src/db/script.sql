CREATE DATABASE IF NOT EXISTS blackboxDB;
CREATE USER IF NOT EXISTS 'blackbox'@'localhost'
    IDENTIFIED BY '2uwejs45KSdf8!4$';

GRANT SELECT, INSERT, DELETE, UPDATE
    ON blackboxDB.*
    TO 'blackbox'@'localhost';

USE blackboxDB;


CREATE TABLE IF NOT EXISTS Question
(
	Email NVARCHAR(100) NOT NULL, 
    Date DATE NOT NULL, 
    Subject NVARCHAR(200) NOT NULL, 
    Description NVARCHAR(3000) NOT NULL,
    PRIMARY KEY (Email,Date)
);

CREATE TABLE IF NOT EXISTS User
(
    Email NVARCHAR(100) NOT NULL PRIMARY KEY, 
    Name NVARCHAR(100) NOT NULL,
    FirstLastName NVARCHAR(100) NULL,
    SecondLastName NVARCHAR(100) NULL,
    Password VARBINARY(32) NOT NULL,
    Address NVARCHAR(200) NULL,
    Phone NVARCHAR(20) NULL,
    Token NVARCHAR(200) NULL,
    TokenTime NVARCHAR(100) NULL
);

CREATE TABLE IF NOT EXISTS Cart
(
	Id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, 
    PayDate NVARCHAR(15) NULL,
    UserEmail NVARCHAR(100) NOT NULL,
    Amount INT NOT NULL,
    CONSTRAINT `fk_cart_user`
    FOREIGN KEY (UserEmail) REFERENCES User (Email)
);

CREATE TABLE IF NOT EXISTS CreditCard
(
    CartId INT NOT NULL PRIMARY KEY,
    CardNumber NVARCHAR(20) NULL,
    ExpirationDate NVARCHAR(10) NULL,
    CSV VARCHAR(3) NULL,
    CardOwner NVARCHAR(200) NULL,
    FOREIGN KEY (CartId) REFERENCES Cart (Id)
);


CREATE TABLE IF NOT EXISTS Product
(
	Id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, 
    Name NVARCHAR(200) NOT NULL, 
    Price INT NOT NULL,
    Description NVARCHAR(3000) NULL
);

CREATE TABLE IF NOT EXISTS ProductIsINCart
(
	ProductId INT NOT NULL,
    CartId INT NOT NULL,
    PRIMARY KEY (ProductId,CartId),
    Quantity INT NOT NULL,

    CONSTRAINT `fk_product_ID`
    FOREIGN KEY (ProductId) REFERENCES Product (Id),

    CONSTRAINT `fk_cart_id`
    FOREIGN KEY (CartId) REFERENCES Cart (Id)
);

-- CREATE DATABASE IF NOT EXISTS parent_db;
-- CREATE DATABASE IF NOT EXISTS user1_db;
-- CREATE DATABASE IF NOT EXISTS user2_db;

-- DROP TRIGGER IF EXISTS parent_db.trg_employee_vertical;
-- DROP TRIGGER IF EXISTS parent_db.trg_movie_horizontal;
-- DROP TABLE IF EXISTS parent_db.employee;
-- DROP TABLE IF EXISTS parent_db.movietab;
-- DROP TABLE IF EXISTS user1_db.employee_v1;
-- DROP TABLE IF EXISTS user2_db.employee_v2;
-- DROP TABLE IF EXISTS user1_db.movie_short;
-- DROP TABLE IF EXISTS user2_db.movie_long;
-- DROP TABLE IF EXISTS parent_db.movietab_partitioned;

-- CREATE TABLE parent_db.employee (
--  empid INT PRIMARY KEY,
--  ename VARCHAR(50) NOT NULL,
--  address VARCHAR(100),
--  salary DECIMAL(10,2),
--  department VARCHAR(50)
-- );

-- CREATE TABLE user1_db.employee_v1 (
--  empid INT PRIMARY KEY,
--  ename VARCHAR(50) NOT NULL,
--  department VARCHAR(50)
-- );

-- CREATE TABLE user2_db.employee_v2 (
--  empid INT PRIMARY KEY,
--  address VARCHAR(100),
--  salary DECIMAL(10,2)
-- );

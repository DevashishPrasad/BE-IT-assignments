-- MySQL dump 10.13  Distrib 5.7.26, for Linux (x86_64)
--
-- Host: localhost    Database: 33319_airplane
-- ------------------------------------------------------
-- Server version	5.7.26-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `airplane`
--

DROP TABLE IF EXISTS `airplane`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `airplane` (
  `model` decimal(6,0) DEFAULT NULL,
  `reg_name` varchar(20) NOT NULL,
  `company` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`reg_name`),
  KEY `model` (`model`),
  CONSTRAINT `airplane_ibfk_1` FOREIGN KEY (`model`) REFERENCES `model` (`model_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `airplane`
--

LOCK TABLES `airplane` WRITE;
/*!40000 ALTER TABLE `airplane` DISABLE KEYS */;
/*!40000 ALTER TABLE `airplane` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `employee` (
  `name` varchar(20) DEFAULT NULL,
  `phone` decimal(10,0) NOT NULL,
  `aadhar` decimal(12,0) NOT NULL,
  `address` varchar(20) DEFAULT NULL,
  `salary` decimal(7,0) DEFAULT NULL,
  `union_no` decimal(6,0) DEFAULT NULL,
  `union_name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`aadhar`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `model`
--

DROP TABLE IF EXISTS `model`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `model` (
  `model_no` decimal(6,0) NOT NULL,
  `weight` float DEFAULT NULL,
  `capacity` decimal(3,0) DEFAULT NULL,
  PRIMARY KEY (`model_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `model`
--

LOCK TABLES `model` WRITE;
/*!40000 ALTER TABLE `model` DISABLE KEYS */;
/*!40000 ALTER TABLE `model` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `perform_tests`
--

DROP TABLE IF EXISTS `perform_tests`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `perform_tests` (
  `test_id` decimal(5,0) DEFAULT NULL,
  `reg_name` varchar(20) DEFAULT NULL,
  `tech_id` decimal(5,0) DEFAULT NULL,
  `score` decimal(2,0) DEFAULT NULL,
  `no_hrs` decimal(2,0) DEFAULT NULL,
  KEY `test_id` (`test_id`),
  KEY `tech_id` (`tech_id`),
  KEY `reg_name` (`reg_name`),
  CONSTRAINT `perform_tests_ibfk_1` FOREIGN KEY (`test_id`) REFERENCES `tests` (`test_id`),
  CONSTRAINT `perform_tests_ibfk_2` FOREIGN KEY (`tech_id`) REFERENCES `technician` (`tech_id`),
  CONSTRAINT `perform_tests_ibfk_3` FOREIGN KEY (`reg_name`) REFERENCES `airplane` (`reg_name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `perform_tests`
--

LOCK TABLES `perform_tests` WRITE;
/*!40000 ALTER TABLE `perform_tests` DISABLE KEYS */;
/*!40000 ALTER TABLE `perform_tests` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `technician`
--

DROP TABLE IF EXISTS `technician`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `technician` (
  `tech_id` decimal(5,0) NOT NULL,
  `skill` varchar(20) DEFAULT NULL,
  `expertise` varchar(20) DEFAULT NULL,
  `aadhar` decimal(12,0) DEFAULT NULL,
  PRIMARY KEY (`tech_id`),
  KEY `aadhar` (`aadhar`),
  CONSTRAINT `technician_ibfk_1` FOREIGN KEY (`aadhar`) REFERENCES `employee` (`aadhar`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `technician`
--

LOCK TABLES `technician` WRITE;
/*!40000 ALTER TABLE `technician` DISABLE KEYS */;
/*!40000 ALTER TABLE `technician` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tests`
--

DROP TABLE IF EXISTS `tests`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tests` (
  `test_id` decimal(5,0) NOT NULL,
  `test_name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`test_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tests`
--

LOCK TABLES `tests` WRITE;
/*!40000 ALTER TABLE `tests` DISABLE KEYS */;
/*!40000 ALTER TABLE `tests` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `traffic_controller`
--

DROP TABLE IF EXISTS `traffic_controller`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `traffic_controller` (
  `exam_date` date DEFAULT NULL,
  `exam_name` varchar(20) DEFAULT NULL,
  `aadhar` decimal(12,0) DEFAULT NULL,
  KEY `aadhar` (`aadhar`),
  CONSTRAINT `traffic_controller_ibfk_1` FOREIGN KEY (`aadhar`) REFERENCES `employee` (`aadhar`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `traffic_controller`
--

LOCK TABLES `traffic_controller` WRITE;
/*!40000 ALTER TABLE `traffic_controller` DISABLE KEYS */;
/*!40000 ALTER TABLE `traffic_controller` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-07-11 15:51:48

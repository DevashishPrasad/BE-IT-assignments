-- MySQL dump 10.13  Distrib 5.7.26, for Linux (x86_64)
--
-- Host: localhost    Database: Student
-- ------------------------------------------------------
-- Server version	5.7.26-0ubuntu0.18.04.1

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
-- Table structure for table `Department`
--

DROP TABLE IF EXISTS `Department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Department` (
  `dno` decimal(5,0) NOT NULL,
  `dname` varchar(20) DEFAULT NULL,
  `maino` varchar(30) DEFAULT NULL,
  `supervisor` decimal(12,0) DEFAULT NULL,
  PRIMARY KEY (`dno`),
  KEY `supervisor` (`supervisor`),
  CONSTRAINT `Department_ibfk_1` FOREIGN KEY (`supervisor`) REFERENCES `Professor` (`aadhar`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Department`
--

LOCK TABLES `Department` WRITE;
/*!40000 ALTER TABLE `Department` DISABLE KEYS */;
/*!40000 ALTER TABLE `Department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Graduate`
--

DROP TABLE IF EXISTS `Graduate`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Graduate` (
  `aadhar` decimal(12,0) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `degree` varchar(30) DEFAULT NULL,
  `dno` decimal(5,0) DEFAULT NULL,
  `adno` decimal(12,0) DEFAULT NULL,
  PRIMARY KEY (`aadhar`),
  KEY `dno` (`dno`),
  CONSTRAINT `Graduate_ibfk_1` FOREIGN KEY (`dno`) REFERENCES `Department` (`dno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Graduate`
--

LOCK TABLES `Graduate` WRITE;
/*!40000 ALTER TABLE `Graduate` DISABLE KEYS */;
/*!40000 ALTER TABLE `Graduate` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Professor`
--

DROP TABLE IF EXISTS `Professor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Professor` (
  `aadhar` decimal(12,0) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `rank` decimal(2,0) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  `research` varchar(30) DEFAULT NULL,
  `dno` decimal(5,0) DEFAULT NULL,
  PRIMARY KEY (`aadhar`),
  KEY `dno` (`dno`),
  CONSTRAINT `Professor_ibfk_1` FOREIGN KEY (`dno`) REFERENCES `Department` (`dno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Professor`
--

LOCK TABLES `Professor` WRITE;
/*!40000 ALTER TABLE `Professor` DISABLE KEYS */;
/*!40000 ALTER TABLE `Professor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Projects`
--

DROP TABLE IF EXISTS `Projects`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Projects` (
  `pno` decimal(4,0) NOT NULL,
  `sponsorname` varchar(20) DEFAULT NULL,
  `start_date` date DEFAULT NULL,
  `end_date` date DEFAULT NULL,
  `budget` float DEFAULT NULL,
  `professor` decimal(12,0) DEFAULT NULL,
  PRIMARY KEY (`pno`),
  KEY `professor` (`professor`),
  CONSTRAINT `Projects_ibfk_1` FOREIGN KEY (`professor`) REFERENCES `Professor` (`aadhar`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Projects`
--

LOCK TABLES `Projects` WRITE;
/*!40000 ALTER TABLE `Projects` DISABLE KEYS */;
/*!40000 ALTER TABLE `Projects` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `advisor`
--

DROP TABLE IF EXISTS `advisor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `advisor` (
  `adno` decimal(12,0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `advisor`
--

LOCK TABLES `advisor` WRITE;
/*!40000 ALTER TABLE `advisor` DISABLE KEYS */;
/*!40000 ALTER TABLE `advisor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `project_work`
--

DROP TABLE IF EXISTS `project_work`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `project_work` (
  `graduate` decimal(12,0) DEFAULT NULL,
  `project` decimal(4,0) DEFAULT NULL,
  KEY `graduate` (`graduate`),
  KEY `project` (`project`),
  CONSTRAINT `project_work_ibfk_1` FOREIGN KEY (`graduate`) REFERENCES `Graduate` (`aadhar`),
  CONSTRAINT `project_work_ibfk_2` FOREIGN KEY (`project`) REFERENCES `Projects` (`pno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `project_work`
--

LOCK TABLES `project_work` WRITE;
/*!40000 ALTER TABLE `project_work` DISABLE KEYS */;
/*!40000 ALTER TABLE `project_work` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-07-15 13:59:17

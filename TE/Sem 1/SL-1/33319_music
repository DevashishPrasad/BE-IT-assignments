-- MySQL dump 10.13  Distrib 5.7.26, for Linux (x86_64)
--
-- Host: localhost    Database: music
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
-- Table structure for table `Album`
--

DROP TABLE IF EXISTS `Album`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Album` (
  `name` varchar(20) NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Album`
--

LOCK TABLES `Album` WRITE;
/*!40000 ALTER TABLE `Album` DISABLE KEYS */;
/*!40000 ALTER TABLE `Album` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Musician`
--

DROP TABLE IF EXISTS `Musician`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Musician` (
  `phone` decimal(10,0) DEFAULT NULL,
  `aadhar` decimal(12,0) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `address` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`aadhar`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Musician`
--

LOCK TABLES `Musician` WRITE;
/*!40000 ALTER TABLE `Musician` DISABLE KEYS */;
/*!40000 ALTER TABLE `Musician` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Song`
--

DROP TABLE IF EXISTS `Song`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Song` (
  `title` varchar(20) NOT NULL,
  `author` decimal(12,0) DEFAULT NULL,
  `album` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`title`),
  KEY `author` (`author`),
  KEY `album` (`album`),
  CONSTRAINT `Song_ibfk_1` FOREIGN KEY (`author`) REFERENCES `Musician` (`aadhar`),
  CONSTRAINT `Song_ibfk_2` FOREIGN KEY (`album`) REFERENCES `Album` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Song`
--

LOCK TABLES `Song` WRITE;
/*!40000 ALTER TABLE `Song` DISABLE KEYS */;
/*!40000 ALTER TABLE `Song` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `has`
--

DROP TABLE IF EXISTS `has`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `has` (
  `aadhar` decimal(12,0) DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `parent_id` decimal(5,0) DEFAULT NULL,
  KEY `aadhar` (`aadhar`),
  KEY `name` (`name`,`parent_id`),
  CONSTRAINT `has_ibfk_1` FOREIGN KEY (`aadhar`) REFERENCES `Employee` (`aadhar`),
  CONSTRAINT `has_ibfk_2` FOREIGN KEY (`name`, `parent_id`) REFERENCES `Children` (`name`, `parent_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `has`
--

LOCK TABLES `has` WRITE;
/*!40000 ALTER TABLE `has` DISABLE KEYS */;
/*!40000 ALTER TABLE `has` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `instrument`
--

DROP TABLE IF EXISTS `instrument`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `instrument` (
  `uid` decimal(5,0) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  `musical_key` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `instrument`
--

LOCK TABLES `instrument` WRITE;
/*!40000 ALTER TABLE `instrument` DISABLE KEYS */;
/*!40000 ALTER TABLE `instrument` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `performs`
--

DROP TABLE IF EXISTS `performs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `performs` (
  `aadhar` decimal(12,0) DEFAULT NULL,
  `title` varchar(20) DEFAULT NULL,
  KEY `aadhar` (`aadhar`),
  KEY `title` (`title`),
  CONSTRAINT `performs_ibfk_1` FOREIGN KEY (`aadhar`) REFERENCES `Musician` (`aadhar`),
  CONSTRAINT `performs_ibfk_2` FOREIGN KEY (`title`) REFERENCES `Song` (`title`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `performs`
--

LOCK TABLES `performs` WRITE;
/*!40000 ALTER TABLE `performs` DISABLE KEYS */;
/*!40000 ALTER TABLE `performs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `plays`
--

DROP TABLE IF EXISTS `plays`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `plays` (
  `uid` decimal(5,0) DEFAULT NULL,
  `aadhar` decimal(12,0) DEFAULT NULL,
  KEY `uid` (`uid`),
  KEY `aadhar` (`aadhar`),
  CONSTRAINT `plays_ibfk_1` FOREIGN KEY (`uid`) REFERENCES `instrument` (`uid`),
  CONSTRAINT `plays_ibfk_2` FOREIGN KEY (`aadhar`) REFERENCES `Musician` (`aadhar`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `plays`
--

LOCK TABLES `plays` WRITE;
/*!40000 ALTER TABLE `plays` DISABLE KEYS */;
/*!40000 ALTER TABLE `plays` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `produces`
--

DROP TABLE IF EXISTS `produces`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `produces` (
  `name` varchar(20) DEFAULT NULL,
  `aadhar` decimal(12,0) DEFAULT NULL,
  KEY `aadhar` (`aadhar`),
  KEY `name` (`name`),
  CONSTRAINT `produces_ibfk_1` FOREIGN KEY (`aadhar`) REFERENCES `Musician` (`aadhar`),
  CONSTRAINT `produces_ibfk_2` FOREIGN KEY (`name`) REFERENCES `Album` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `produces`
--

LOCK TABLES `produces` WRITE;
/*!40000 ALTER TABLE `produces` DISABLE KEYS */;
/*!40000 ALTER TABLE `produces` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-07-15  8:12:56

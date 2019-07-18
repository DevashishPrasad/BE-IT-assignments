-- MySQL dump 10.13  Distrib 5.7.26, for Linux (x86_64)
--
-- Host: localhost    Database: 33319_Order
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
-- Table structure for table `courier`
--

DROP TABLE IF EXISTS `courier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `courier` (
  `salesman_phone` decimal(10,0) NOT NULL,
  `salesman_id` decimal(5,0) NOT NULL,
  `salesnam_name` varchar(20) NOT NULL,
  `order_id` char(5) DEFAULT NULL,
  PRIMARY KEY (`salesman_id`),
  KEY `fk1` (`order_id`),
  CONSTRAINT `courier_ibfk_1` FOREIGN KEY (`order_id`) REFERENCES `orders` (`order_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `courier`
--

LOCK TABLES `courier` WRITE;
/*!40000 ALTER TABLE `courier` DISABLE KEYS */;
INSERT INTO `courier` VALUES (1111111111,11111,'DTDC','5'),(2323232323,22222,'speedpost','2'),(2323232313,33333,'dhl','3');
/*!40000 ALTER TABLE `courier` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `cust_id` char(5) NOT NULL,
  `phone` decimal(10,0) NOT NULL,
  `name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`cust_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES ('0',2221112222,'j'),('11111',2221112222,'i'),('22222',2222222222,'a'),('33333',3333333333,'b'),('44444',4444444444,'c'),('55555',5555555555,'d'),('66666',2221112221,'e'),('77777',2221112222,'f'),('88888',2221112222,'g'),('99999',2221112222,'h');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `delivers`
--

DROP TABLE IF EXISTS `delivers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `delivers` (
  `order_id` char(5) DEFAULT NULL,
  `cust_id` char(5) DEFAULT NULL,
  `deliver_date` date DEFAULT NULL,
  `status` varchar(12) DEFAULT NULL,
  KEY `order_id` (`order_id`),
  KEY `cust_id` (`cust_id`),
  CONSTRAINT `delivers_ibfk_1` FOREIGN KEY (`order_id`) REFERENCES `orders` (`order_id`),
  CONSTRAINT `delivers_ibfk_2` FOREIGN KEY (`cust_id`) REFERENCES `customer` (`cust_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `delivers`
--

LOCK TABLES `delivers` WRITE;
/*!40000 ALTER TABLE `delivers` DISABLE KEYS */;
/*!40000 ALTER TABLE `delivers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orders` (
  `order_id` char(5) NOT NULL,
  `cust_id` char(5) DEFAULT NULL,
  `prod_id` char(5) NOT NULL,
  `order_date` date DEFAULT NULL,
  PRIMARY KEY (`order_id`,`prod_id`),
  KEY `cust_id` (`cust_id`),
  KEY `prod_id` (`prod_id`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`cust_id`) REFERENCES `customer` (`cust_id`),
  CONSTRAINT `orders_ibfk_2` FOREIGN KEY (`prod_id`) REFERENCES `product` (`product_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES ('1','22222','66666','2019-06-01'),('1','22222','88888','2019-06-01'),('1','22222','99999','2019-06-01'),('2','33333','66666','2019-06-01'),('2','33333','88888','2019-06-01'),('3','33333','66666','2019-06-01'),('3','33333','77777','2019-06-01'),('4','44444','66666','2019-07-18'),('4','44444','77777','2019-07-18'),('4','44444','88888','2019-07-18'),('5','88888','11111','2019-07-18'),('5','11111','22222','2019-07-18'),('5','11111','77777','2019-07-18');
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `product`
--

DROP TABLE IF EXISTS `product`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `product` (
  `price` float DEFAULT NULL,
  `product_id` char(5) NOT NULL,
  `quantity` int(5) DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `store_id` decimal(5,0) DEFAULT NULL,
  PRIMARY KEY (`product_id`),
  KEY `fk` (`store_id`),
  CONSTRAINT `fk` FOREIGN KEY (`store_id`) REFERENCES `store` (`store_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `product`
--

LOCK TABLES `product` WRITE;
/*!40000 ALTER TABLE `product` DISABLE KEYS */;
INSERT INTO `product` VALUES (124.97,'0',7,'book',22222),(344.22,'11111',6,'pen',11111),(664.22,'22222',45,'pencil',22222),(345.98,'33333',14,'football',22222),(235.87,'44444',53,'sharpner',11111),(452.75,'55555',4,'eraser',33333),(230.2,'66666',12,'p2',33333),(399.99,'77777',3,'p3',11111),(120.98,'88888',6,'p1',33333),(620.99,'99999',40,'p4',11111);
/*!40000 ALTER TABLE `product` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `store`
--

DROP TABLE IF EXISTS `store`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `store` (
  `store_phone` decimal(10,0) NOT NULL,
  `store_id` decimal(5,0) NOT NULL,
  `store_name` varchar(20) NOT NULL,
  `store_address` varchar(40) DEFAULT NULL,
  PRIMARY KEY (`store_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `store`
--

LOCK TABLES `store` WRITE;
/*!40000 ALTER TABLE `store` DISABLE KEYS */;
INSERT INTO `store` VALUES (1111111111,11111,'Amazon','somewhere on earth'),(2222222222,22222,'Flipcart','somehwere on this planet'),(3333333333,33333,'Snapdeal','somehwere near the moon'),(4444444444,44444,'ebay','somehwere on the land');
/*!40000 ALTER TABLE `store` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-07-18 16:01:28

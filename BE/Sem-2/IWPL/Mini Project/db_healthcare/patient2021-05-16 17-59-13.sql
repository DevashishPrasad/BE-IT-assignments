CREATE TABLE `patient` (
  `icPatient` bigint(12) NOT NULL auto_increment,
  `password` varchar(20) NOT NULL,
  `patientFirstName` varchar(20) NOT NULL,
  `patientLastName` varchar(20) NOT NULL,
  `patientMaritialStatus` varchar(10) NOT NULL,
  `patientDOB` date NOT NULL,
  `patientGender` varchar(10) NOT NULL,
  `patientAddress` varchar(100) NOT NULL,
  `patientPhone` varchar(15) NOT NULL,
  `patientEmail` varchar(100) NOT NULL,
  `age` varchar(100) NOT NULL,
  `bgroup` varchar(100) NOT NULL,
  PRIMARY KEY  (`icPatient`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`patient`(`icPatient`,`password`,`patientFirstName`,`patientLastName`,`patientMaritialStatus`,`patientDOB`,`patientGender`,`patientAddress`,`patientPhone`,`patientEmail`,`age`,`bgroup`) values (111,'111','Diksha','Prasad','single','2000-10-08','female','B-207, kamal Greenleaf societyKamal Greenleaf society, Kirkitwadi','9112840879','dikshakrishnaprasad@gmail.com','','');
insert into `db_healthcare`.`patient`(`icPatient`,`password`,`patientFirstName`,`patientLastName`,`patientMaritialStatus`,`patientDOB`,`patientGender`,`patientAddress`,`patientPhone`,`patientEmail`,`age`,`bgroup`) values (116,'222','Diksha','Prasad','','2001-11-14','female','','','dikshakrishnaprasad@gmail.com','','');

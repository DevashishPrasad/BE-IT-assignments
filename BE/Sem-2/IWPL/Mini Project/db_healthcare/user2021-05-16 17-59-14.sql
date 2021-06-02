CREATE TABLE `user` (
  `icPatient` bigint(12) NOT NULL auto_increment,
  `password` varchar(20) NOT NULL,
  `patientFirstName` varchar(20) NOT NULL,
  `patientLastName` varchar(20) NOT NULL,
  `patientDOB` date NOT NULL,
  `patientGender` varchar(10) NOT NULL,
  `patientAddress` varchar(100) NOT NULL,
  `patientPhone` varchar(15) NOT NULL,
  `patientEmail` varchar(100) NOT NULL,
  PRIMARY KEY  (`icPatient`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`user`(`icPatient`,`password`,`patientFirstName`,`patientLastName`,`patientDOB`,`patientGender`,`patientAddress`,`patientPhone`,`patientEmail`) values (111154,'dik','Diksha','Prasad','2021-03-01','Male','B-207, kamal Greenleaf societyKamal Greenleaf society, Kirkitwadi','9112840879','dikshakrishnaprasad@gmail.com');
insert into `db_healthcare`.`user`(`icPatient`,`password`,`patientFirstName`,`patientLastName`,`patientDOB`,`patientGender`,`patientAddress`,`patientPhone`,`patientEmail`) values (111155,'o9aKFaKq','Diksha','Prasad','2021-05-16','Male','B-207, kamal Greenleaf societyKamal Greenleaf society, Kirkitwadi','9187979875','dikshakrishnaprasad@gmail.com');

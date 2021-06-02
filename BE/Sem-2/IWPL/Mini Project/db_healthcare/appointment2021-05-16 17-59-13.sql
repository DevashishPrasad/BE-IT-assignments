CREATE TABLE `appointment` (
  `appId` int(3) NOT NULL auto_increment,
  `patientIc` bigint(12) NOT NULL,
  `scheduleId` int(10) NOT NULL,
  `appSymptom` varchar(100) NOT NULL,
  `appComment` varchar(100) NOT NULL,
  `status` varchar(10) NOT NULL default 'process',
  PRIMARY KEY  (`appId`),
  UNIQUE KEY `scheduleId_2` (`scheduleId`),
  KEY `patientIc` (`patientIc`),
  KEY `scheduleId` (`scheduleId`),
  CONSTRAINT `appointment_ibfk_4` FOREIGN KEY (`patientIc`) REFERENCES `patient` (`icPatient`),
  CONSTRAINT `appointment_ibfk_5` FOREIGN KEY (`scheduleId`) REFERENCES `doctorschedule` (`scheduleId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`appointment`(`appId`,`patientIc`,`scheduleId`,`appSymptom`,`appComment`,`status`) values (3,111,63,'cold and cough','dr. Isha preference','done');
insert into `db_healthcare`.`appointment`(`appId`,`patientIc`,`scheduleId`,`appSymptom`,`appComment`,`status`) values (4,111,75,'lkmlk','knkjn','process');

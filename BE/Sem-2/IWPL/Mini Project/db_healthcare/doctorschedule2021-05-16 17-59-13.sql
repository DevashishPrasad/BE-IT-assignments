CREATE TABLE `doctorschedule` (
  `scheduleId` int(11) NOT NULL auto_increment,
  `scheduleDate` date NOT NULL,
  `scheduleDay` varchar(15) NOT NULL,
  `startTime` time NOT NULL,
  `endTime` time NOT NULL,
  `bookAvail` varchar(10) NOT NULL,
  PRIMARY KEY  (`scheduleId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (61,'2020-12-09','Wednesday','12:05:00','03:05:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (62,'2020-12-10','Thursday','12:05:00','03:05:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (63,'2020-12-11','Friday','03:15:00','09:00:00','notavail');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (64,'2020-12-12','Saturday','12:00:00','06:00:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (65,'2020-12-13','Sunday','12:00:00','09:00:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (66,'2020-12-14','Monday','01:00:00','06:00:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (75,'2020-12-15','Tuesday','12:00:00','03:05:00','notavail');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (76,'2020-12-16','Wednesday','01:00:00','06:00:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (77,'2020-12-18','Friday','12:05:00','03:05:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (79,'2020-12-11','Friday','03:30:00','04:00:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (80,'2020-12-11','Friday','03:00:00','03:30:00','available');
insert into `db_healthcare`.`doctorschedule`(`scheduleId`,`scheduleDate`,`scheduleDay`,`startTime`,`endTime`,`bookAvail`) values (81,'2020-12-01','Tuesday','01:00:00','01:30:00','available');

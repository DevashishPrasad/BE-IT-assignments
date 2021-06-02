CREATE TABLE `booking` (
  `booking_id` int(22) NOT NULL auto_increment,
  `dr_id` varchar(22) NOT NULL,
  `ic_patient` varchar(22) NOT NULL,
  `date` date NOT NULL,
  `day` varchar(10) NOT NULL,
  `Time` float NOT NULL,
  PRIMARY KEY  (`booking_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (23,'1001','111139','2021-01-29','Fri',9.75);
insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (29,'1001','111145','2021-02-02','Tue',9);
insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (30,'1001','111145','2021-02-02','Tue',9.25);
insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (31,'1001','111146','2021-02-02','Tue',9.5);
insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (32,'1001','111147','2021-02-15','Mon',9);
insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (33,'1001','111148','2021-02-16','Tue',9.75);
insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (34,'1003','111148','2021-02-26','Fri',8);
insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (35,'1001','111153','2021-04-24','Sat',13);
insert into `db_healthcare`.`booking`(`booking_id`,`dr_id`,`ic_patient`,`date`,`day`,`Time`) values (36,'1001','111154','2021-04-30','Fri',9);

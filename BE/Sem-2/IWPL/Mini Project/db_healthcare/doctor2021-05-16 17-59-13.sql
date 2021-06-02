CREATE TABLE `doctor` (
  `id` int(22) NOT NULL auto_increment,
  `name` varchar(22) NOT NULL,
  `service` varchar(100) NOT NULL,
  `address` varchar(100) NOT NULL,
  `contact` varchar(14) NOT NULL,
  `email` varchar(22) NOT NULL,
  `expertise` varchar(22) NOT NULL,
  `qualify` varchar(22) NOT NULL,
  `cat_id` int(11) NOT NULL,
  `fee` varchar(111) NOT NULL,
  `userid` varchar(22) NOT NULL,
  `password` varchar(22) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (1,'Dr. Abdul Kader','Kothrud','abc colony,zircone clinic,block no-2,Kothrud','9112345674','kader@gmail.com','ENT Specialist','B.U.M.S,M.D',1,'900','1001','1234');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (2,'Dr. Manoj Sehgal','Airport','abc colony,zircone clinic,block no-2,Airport rd.','1734761999','sehgal@gmail.com','Dermatologists','M.D,D.O',2,'700','1002','111');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (3,'Dr. Isha Meheta','Yerwada','abc colony,zircone clinic,block no-2,yerwada','1734761999','isha@gmail.com','Dentist','B.D.S,D.Clin.Dent',3,'900','1003','222');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (4,'Dr. Aditya Shah','Shivajinagar','abc colony,zircone clinic,block no-2,Shivajinagar','1734761999','shah@gmail.com','Pediatricians','M.D,D.O',4,'700','1004','333');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (5,'Dr. Manish Wagh','Swargate','abc colony,zircone clinic,block no-2,Swargate','1734761999','wagh@gmail.com','Cardiologist','M.B.B.S,M.D,D.M',5,'500','1005','444');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (6,'Dr. Shivaji Nigde','Dhankawadi','abc colony,zircone clinic,block no-2,Dhankawadi','1734761999','shivaji@gmail.com','General Surgeon','M.S',6,'1500','1006','555');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (7,'Dr. Rishab Singh','Hadapsar','abc colony,zircone clinic,block no-2,Hadapsar','1734761999','rishab@gmail.com','Orthopedic Surgeon','M.S Ortho',7,'1000','1007','666');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (8,'Dr. Sagi Agarwal','Wakad','abc colony,zircone clinic,block no-2,Wakad','1734761999','sahi@gmail.com','General Physician','M.B.B.S,B.H.M.S',8,'500','1008','777');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (9,'Dr. Manish Rai','Donje','abc colony,zircone clinic,block no-2,Donje','1734761999','rai@gmail.com','Gynecologist','M.D Gynec',9,'900','1009','888');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (10,'Dr. Sanjay Tiwari','Vadgaon Sheri','abc colony,zircone clinic,block no-2,Vadgaon Sheri','1734761999','tiwari@gmail.com','General Surgeon','M.S',6,'1000','1010','999');
insert into `db_healthcare`.`doctor`(`id`,`name`,`service`,`address`,`contact`,`email`,`expertise`,`qualify`,`cat_id`,`fee`,`userid`,`password`) values (20,'Dr. Richa Sharma','khadakwasla','abc colony,xyz clinic,411024','9112840879','sharma@gmail.com','Dentist','B.D.S',3,'500','1050','000');

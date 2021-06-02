CREATE TABLE `category` (
  `id` int(22) NOT NULL auto_increment,
  `cat` varchar(22) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`category`(`id`,`cat`) values (1,'ENT Specialist');
insert into `db_healthcare`.`category`(`id`,`cat`) values (2,'Dermatologists');
insert into `db_healthcare`.`category`(`id`,`cat`) values (3,'Dentist');
insert into `db_healthcare`.`category`(`id`,`cat`) values (4,'Pediatricians');
insert into `db_healthcare`.`category`(`id`,`cat`) values (5,'Cardiologist');
insert into `db_healthcare`.`category`(`id`,`cat`) values (6,'General Surgeon');
insert into `db_healthcare`.`category`(`id`,`cat`) values (7,'Orthopedic Surgeon');
insert into `db_healthcare`.`category`(`id`,`cat`) values (8,'General Physician');
insert into `db_healthcare`.`category`(`id`,`cat`) values (12,' Gynecologist');

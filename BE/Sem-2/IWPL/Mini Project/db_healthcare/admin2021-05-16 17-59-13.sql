CREATE TABLE `admin` (
  `admin_id` int(11) NOT NULL auto_increment,
  `username` varchar(20) NOT NULL,
  `password` varchar(14) NOT NULL,
  PRIMARY KEY  (`admin_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`admin`(`admin_id`,`username`,`password`) values (1,'Admin','admin');

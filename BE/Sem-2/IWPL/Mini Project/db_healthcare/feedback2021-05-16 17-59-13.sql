CREATE TABLE `feedback` (
  `id` int(11) NOT NULL auto_increment,
  `name` varchar(22) NOT NULL,
  `email` varchar(22) NOT NULL,
  `feedback` varchar(22) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`feedback`(`id`,`name`,`email`,`feedback`) values (1,'Mumble Little','mumble@gmail.com','kug');
insert into `db_healthcare`.`feedback`(`id`,`name`,`email`,`feedback`) values (2,'Mumble Little','mumble@gmail.com','kug');
insert into `db_healthcare`.`feedback`(`id`,`name`,`email`,`feedback`) values (3,'diksha prasad','dikshakrishnaprasad@gm','lol');

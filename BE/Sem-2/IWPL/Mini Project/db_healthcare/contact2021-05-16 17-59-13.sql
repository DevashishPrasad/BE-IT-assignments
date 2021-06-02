CREATE TABLE `contact` (
  `contact_id` int(11) NOT NULL auto_increment,
  `fullname` varchar(40) NOT NULL,
  `phone` varchar(14) NOT NULL,
  `email` varchar(15) NOT NULL,
  `subject` varchar(111) NOT NULL,
  `msg` varchar(111) NOT NULL,
  PRIMARY KEY  (`contact_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`contact`(`contact_id`,`fullname`,`phone`,`email`,`subject`,`msg`) values (1,'Azharul Islam','6876876876','azad.ece13@gmai','My comment is getting successful.','abc');
insert into `db_healthcare`.`contact`(`contact_id`,`fullname`,`phone`,`email`,`subject`,`msg`) values (11,'Mumble Little','9112840879','mumble@gmail.co','hgvj','hey there');

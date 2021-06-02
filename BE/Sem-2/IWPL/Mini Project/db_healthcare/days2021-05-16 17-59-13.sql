CREATE TABLE `days` (
  `dr_id` int(22) NOT NULL,
  `mon` varchar(22) default NULL,
  `tue` varchar(22) default NULL,
  `wed` varchar(22) default NULL,
  `thu` varchar(22) default NULL,
  `fri` varchar(22) default NULL,
  `sat` varchar(22) default NULL,
  `sun` varchar(22) default NULL,
  PRIMARY KEY  (`dr_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`days`(`dr_id`,`mon`,`tue`,`wed`,`thu`,`fri`,`sat`,`sun`) values (1001,'available','available','available','available','available','available','available');

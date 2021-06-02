CREATE TABLE `slot_2` (
  `dr_id` float NOT NULL,
  `Mon_s` float default NULL,
  `Mon_e` float default NULL,
  `Mon_p` float default NULL,
  `Mon_a` float default NULL,
  `Tue_s` float default NULL,
  `Tue_e` float default NULL,
  `Tue_p` float default NULL,
  `Tue_a` float default NULL,
  `Wed_s` float default NULL,
  `Wed_e` float default NULL,
  `Wed_p` float default NULL,
  `Wed_a` float default NULL,
  `Thu_s` float default NULL,
  `Thu_e` float default NULL,
  `Thu_p` float default NULL,
  `Thu_a` float default NULL,
  `Fri_s` float default NULL,
  `Fri_e` float default NULL,
  `Fri_p` float default NULL,
  `Fri_a` float default NULL,
  `Sat_s` float default NULL,
  `Sat_e` float default NULL,
  `Sat_p` float default NULL,
  `Sat_a` float default NULL,
  `Sun_s` float default NULL,
  `Sun_e` float default NULL,
  `Sun_p` float default NULL,
  `Sun_a` float default NULL,
  PRIMARY KEY  (`dr_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


insert into `db_healthcare`.`slot_2`(`dr_id`,`Mon_s`,`Mon_e`,`Mon_p`,`Mon_a`,`Tue_s`,`Tue_e`,`Tue_p`,`Tue_a`,`Wed_s`,`Wed_e`,`Wed_p`,`Wed_a`,`Thu_s`,`Thu_e`,`Thu_p`,`Thu_a`,`Fri_s`,`Fri_e`,`Fri_p`,`Fri_a`,`Sat_s`,`Sat_e`,`Sat_p`,`Sat_a`,`Sun_s`,`Sun_e`,`Sun_p`,`Sun_a`) values (1001,13,16,12,12,13,16,12,12,13,16,12,12,13,16,12,12,13,16,12,12,13,16,12,11,0,0,0,0);
insert into `db_healthcare`.`slot_2`(`dr_id`,`Mon_s`,`Mon_e`,`Mon_p`,`Mon_a`,`Tue_s`,`Tue_e`,`Tue_p`,`Tue_a`,`Wed_s`,`Wed_e`,`Wed_p`,`Wed_a`,`Thu_s`,`Thu_e`,`Thu_p`,`Thu_a`,`Fri_s`,`Fri_e`,`Fri_p`,`Fri_a`,`Sat_s`,`Sat_e`,`Sat_p`,`Sat_a`,`Sun_s`,`Sun_e`,`Sun_p`,`Sun_a`) values (1003,13,17,12,12,13,17,12,12,13,17,12,12,13,17,12,12,0,0,0,0,0,0,0,0,13,17,12,12);

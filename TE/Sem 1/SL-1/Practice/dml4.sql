/* ------------------- TABLE STRUCTURES -------------------------
mysql> select * from Catalog;
+------+------+------+
| sid  | pid  | cost |
+------+------+------+
|    1 |    1 |  340 |
|    1 |    2 |  612 |
|    1 |    3 |  110 |
|    1 |    4 |  763 |
|    2 |    4 |  710 |
|    2 |    5 |  110 |
|    2 |    8 |  731 |
|    2 |    9 |  234 |
|    3 |   10 |   13 |
|    3 |    1 |  123 |
|    3 |    6 |  562 |
|    3 |    7 |   52 |
|    3 |   11 |  652 |
|    3 |   12 |  444 |
|    4 |    4 |  562 |
|    4 |    7 |  562 |
|    4 |    9 |   42 |
|    4 |   10 |  428 |
|    4 |   11 |  668 |
|    4 |    2 |  778 |
+------+------+------+
20 rows in set (0.00 sec)

mysql> select * from Parts;
+-----+-------+--------+
| pid | pname | color  |
+-----+-------+--------+
|   1 | P1    | Red    |
|   2 | P2    | Green  |
|   3 | P3    | Red    |
|   4 | P4    | Green  |
|   5 | P5    | Red    |
|   6 | P6    | Red    |
|   7 | P7    | Red    |
|   8 | P8    | Green  |
|   9 | P9    | Yellow |
|  10 | P10   | Blue   |
|  11 | P11   | Black  |
|  12 | P12   | Green  |
+-----+-------+--------+
12 rows in set (0.03 sec)

mysql> select * from Supplier;
+-----+--------+----------------------+
| sid | sname  | address              |
+-----+--------+----------------------+
|   1 | Rakesh | 221 Packer Street    |
|   2 | Rohan  | 321 Huston Street    |
|   3 | Suraj  | 110 Armstrong Street |
|   4 | Vishnu | 23 Collins Street    |
+-----+--------+----------------------+
4 rows in set (0.00 sec)*/


/*========================================================================*/
/* Find the names of suppliers who supply some red part.*/
/*========================================================================*/
select sname from Supplier where sid in (select distinct sid from Catalog 
join Parts on Catalog.pid=Parts.pid where color = 'red');
/*
OUTPUT
+--------+
| sname  |
+--------+
| Rakesh |
| Rohan  |
| Suraj  |
| Vishnu |
+--------+
4 rows in set (0.00 sec)
*/
/*========================================================================*/


/*========================================================================*/
/* Find the sids of suppliers who supply some red or green part.*/
/*========================================================================*/
select distinct sid from Catalog join Parts on Catalog.pid=Parts.pid 
where color in ('red','green');
/*
OUTPUT
+------+
| sid  |
+------+
|    1 |
|    3 |
|    4 |
|    2 |
+------+
4 rows in set (0.00 sec)
*/

/*========================================================================*/
/* Find the sids of suppliers who supply some red part or are at 221 Packer 
	Street.*/
/*========================================================================*/
select distinct Catalog.sid from Catalog join Parts on Catalog.pid=Parts.pid 
join Supplier on Catalog.sid = Supplier.sid where color = 'red' 
and address='221 Packer Street';
/*
OUTPUT
+------+
| sid  |
+------+
|    1 |
+------+
1 row in set (0.00 sec)
*/

/*========================================================================*/
/* Find the sids of suppliers who supply some red part and some green part.*/
/*========================================================================*/
select distinct sid from Catalog join Parts on Catalog.pid=Parts.pid 
where color='red' and color='green';
/*
OUTPUT
Empty set (0.00 sec)
*/

/*========================================================================*/
/* Find the sids of suppliers who supply every part.*/
/*========================================================================*/
select distinct sid from Catalog join Parts on Catalog.pid=Parts.pid 
where Catalog.pid = all(select pid from Parts);
/*
OUTPUT
Empty set (0.00 sec)
*/

/*========================================================================*/
/* Find the sids of suppliers who supply every red part.*/
/*========================================================================*/
select distinct sid from Catalog join Parts on Catalog.pid=Parts.pid 
where Catalog.pid = all(select pid from Parts where color = 'red');
/*
OUTPUT
Empty set (0.00 sec)
*/

/*========================================================================*/
/* Find the sids of suppliers who supply every red or green part.*/
/*========================================================================*/
select distinct sid from Catalog join Parts on Catalog.pid=Parts.pid 
where Catalog.pid = all(select pid from Parts where color in ('red','green'));
/*
OUTPUT
Empty set (0.00 sec)
*/

/*========================================================================*/
/* Find the sids of suppliers who supply every red part or supply every green 
	part.*/
/*========================================================================*/
select distinct sid from Catalog join Parts on Catalog.pid=Parts.pid 
where Catalog.pid = all(select pid from Parts where color='red') or 
Catalog.pid = all(select pid from Parts where color='green');
/*
OUTPUT
Empty set (0.00 sec)
*/

/*========================================================================*/
/* Find pairs of sids such that the supplier with the first sid charges more 
	for some part than the supplier with the second sid.*/
/*========================================================================*/
select a.sid,b.sid,a.cost,b.cost from Catalog  as a , Catalog b 
where a.sid <> b.sid and a.pid = b.pid and a.cost > b.cost;
/*
OUTPUT
+------+------+------+------+
| sid  | sid  | cost | cost |
+------+------+------+------+
|    1 |    3 |  340 |  123 |
|    1 |    2 |  763 |  710 |
|    1 |    4 |  763 |  562 |
|    2 |    4 |  710 |  562 |
|    2 |    4 |  234 |   42 |
|    4 |    3 |  562 |   52 |
|    4 |    3 |  428 |   13 |
|    4 |    3 |  668 |  652 |
|    4 |    1 |  778 |  612 |
+------+------+------+------+
9 rows in set (0.00 sec)*/

/*========================================================================*/
/* Find the pids of parts supplied by at least two different suppliers.*/
/*========================================================================*/
select pid,count(sid) from Catalog group by pid having count(*) > 1;
/*
OUTPUT
+------+------------+
| pid  | count(sid) |
+------+------------+
|    1 |          2 |
|    2 |          2 |
|    4 |          3 |
|    7 |          2 |
|    9 |          2 |
|   10 |          2 |
|   11 |          2 |
+------+------------+
7 rows in set (0.00 sec)
*/

/*========================================================================*/
/* Find the pids of the most expensive parts supplied by suppliers named Rakesh
*/
/*========================================================================*/
select pid from Catalog where cost in (select max(cost) from Catalog c join 
Supplier s on c.sid = s.sid where sname = 'Rakesh' group by c.sid);
/*
OUTPUT
+------+
| pid  |
+------+
|    4 |
+------+
1 row in set (0.00 sec)
*/

/*========================================================================*/
/* Find the pids of parts supplied by every supplier at less than $200 */
/*========================================================================*/
select pid,sid from Catalog where cost < 200;
/*
OUTPUT
+------+------+
| pid  | sid  |
+------+------+
|    3 |    1 |
|    5 |    2 |
|   10 |    3 |
|    1 |    3 |
|    7 |    3 |
|    9 |    4 |
+------+------+
6 rows in set (0.00 sec)

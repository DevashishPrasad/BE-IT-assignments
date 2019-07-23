/* ------------------- TABLE STRUCTURES -------------------------

mysql> select * from customer;
+---------+------------+------+
| cust_id | phone      | name |
+---------+------------+------+
| 0       | 2221112222 | j    |
| 11111   | 2221112222 | i    |
| 22222   | 2222222222 | a    |
| 33333   | 3333333333 | b    |
| 44444   | 4444444444 | c    |
| 55555   | 5555555555 | d    |
| 66666   | 2221112221 | e    |
| 77777   | 2221112222 | f    |
| 88888   | 2221112222 | g    |
| 99999   | 2221112222 | h    |
+---------+------------+------+
10 rows in set (0.00 sec)

mysql> select * from product;
+--------+------------+----------+----------+----------+
| price  | product_id | quantity | name     | store_id |
+--------+------------+----------+----------+----------+
| 124.97 | 0          |        7 | book     |    22222 |
| 344.22 | 11111      |        6 | pen      |    11111 |
| 664.22 | 22222      |       45 | pencil   |    22222 |
| 345.98 | 33333      |       14 | football |    22222 |
| 235.87 | 44444      |       53 | sharpner |    11111 |
| 452.75 | 55555      |        4 | eraser   |    33333 |
|  230.2 | 66666      |       12 | p2       |    33333 |
| 399.99 | 77777      |        3 | p3       |    11111 |
| 120.98 | 88888      |        6 | p1       |    33333 |
| 620.99 | 99999      |       40 | p4       |    11111 |
+--------+------------+----------+----------+----------+
10 rows in set (0.00 sec)

mysql> select * from orders;
+----------+---------+---------+------------+
| order_id | cust_id | prod_id | order_date |
+----------+---------+---------+------------+
| 1        | 22222   | 66666   | 2019-06-01 |
| 1        | 22222   | 88888   | 2019-06-01 |
| 1        | 22222   | 99999   | 2019-06-01 |
| 2        | 33333   | 66666   | 2019-06-01 |
| 2        | 33333   | 88888   | 2019-06-01 |
| 3        | 33333   | 66666   | 2019-06-01 |
| 3        | 33333   | 77777   | 2019-06-01 |
| 4        | 44444   | 66666   | 2019-07-18 |
| 4        | 44444   | 77777   | 2019-07-18 |
| 4        | 44444   | 88888   | 2019-07-18 |
| 5        | 88888   | 11111   | 2019-07-18 |
| 5        | 11111   | 22222   | 2019-07-18 |
| 5        | 11111   | 77777   | 2019-07-18 |
+----------+---------+---------+------------+
13 rows in set (0.01 sec)
*/


/* Display all the Purchase orders of a specific Customer */
select * from orders where cust_id=22222;
/*
OUTPUT
+----------+---------+---------+------------+
| order_id | cust_id | prod_id | order_date |
+----------+---------+---------+------------+
| 1        | 22222   | 66666   | 2019-06-01 |
| 1        | 22222   | 88888   | 2019-06-01 |
| 1        | 22222   | 99999   | 2019-06-01 |
+----------+---------+---------+------------+
*/


/* Get Customer and Data Item Information for a Specific Purchase Order */
select * from orders where order_id=2;
/*
OUTPUT
+----------+---------+---------+------------+
| order_id | cust_id | prod_id | order_date |
+----------+---------+---------+------------+
| 2        | 33333   | 66666   | 2019-06-01 |
| 2        | 33333   | 88888   | 2019-06-01 |
+----------+---------+---------+------------+
*/


/* Get the Total Value of Purchase Orders */
select order_id, sum((select price from product where product_id = prod_id)) from orders group by order_id;
/*
OUTPUT
+----------+-------------------------------------------------------------+
| order_id | sum((select price from product where product_id = prod_id)) |
+----------+-------------------------------------------------------------+
| 1        |                                           972.1699905395508 |
| 2        |                                           351.1800003051758 |
| 3        |                                           630.1899871826172 |
| 4        |                                           751.1699905395508 |
| 5        |                                          1408.4299621582031 |
+----------+-------------------------------------------------------------+
5 rows in set (0.00 sec)
*/


/*  List the Purchase Orders in descending order as per total */
select order_id, sum((select price from product where product_id = prod_id)) as total from orders group by order_id order by total desc;
/*
OUTPUT
+----------+--------------------+
| order_id | total              |
+----------+--------------------+
| 5        | 1408.4299621582031 |
| 1        |  972.1699905395508 |
| 4        |  751.1699905395508 |
| 3        |  630.1899871826172 |
| 2        |  351.1800003051758 |
+----------+--------------------+
5 rows in set (0.00 sec)
*/


/*Display the name of customers whose first name starts with “Rav”. (String matching :Like operator)*/
select name from customer where name like 'rav*';
/*
OUTPUT
Empty set (0.00 sec)
*/


/*Display the name of customer whose order amount is greater than all the customers. (Relational Operator: <, >, <=, >=, = =,!=)*/
select name from customer where cust_id = (select distinct cust_id from orders where order_id=(select distinct order_id from (select order_id, sum((select price from product where product_id = prod_id)) as total from orders group by order_id order by total desc limit 1) as T1));
/*
OUTPUT
+------+
| name |
+------+
| i    |
+------+
1 row in set (0.01 sec)
*/


/*Display order details of customer whose city name is “Pune” and purchase date is “22/08/2016” (Boolean Operators: and, or)*/
select * from orders where cust_id in (select cust_id from customer where city = 'Pune') and order_date='2016-08-22';
/*
OUTPUT
Empty set (0.00 sec)
*/


/* Add discount of 5% to all the customers whose order is more than Rs. 1000/-. (Arithmetic Operators +, -, *, /) */
select cust_id,total+total*(5/100) as with_discount from (select cust_id, sum((select price from product where product_id = prod_id)) as total from orders group by cust_id) as T1 where total >1000;
/*
OUTPUT
+---------+-------------------+
| cust_id | with_discount     |
+---------+-------------------+
| 11111   | 1117.420458984375 |
+---------+-------------------+
1 row in set (0.00 sec)
*/


/*Delete Purchase Order 1001*/
delete from orders where order_id=1001;

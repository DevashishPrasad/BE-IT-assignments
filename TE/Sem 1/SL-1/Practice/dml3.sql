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
| 5        | 11111   | 11111   | 2019-07-18 |
| 5        | 11111   | 22222   | 2019-07-18 |
| 5        | 11111   | 77777   | 2019-07-18 |
+----------+---------+---------+------------+
13 rows in set (0.01 sec)
*/


/*========================================================================*/
/* Get order details of products which are not from electronics and sports category */
/* Get order details of products which are not from amazon and flipcart */
/*========================================================================*/
select * from product where store_id in (select store_id from store where store_name not in ('Amazon','Flipcart'));
/*
OUTPUT
+--------+------------+----------+--------+----------+
| price  | product_id | quantity | name   | store_id |
+--------+------------+----------+--------+----------+
| 452.75 | 55555      |        4 | eraser |    33333 |
|  230.2 | 66666      |       12 | p2     |    33333 |
| 120.98 | 88888      |        6 | p1     |    33333 |
+--------+------------+----------+--------+----------+
3 rows in set (0.01 sec)
/*========================================================================*/


/*========================================================================*/
/* Get the name and quantity of product which have either 10 or 20 or 30 quantities */
/*========================================================================*/
select name,quantity from product where quantity in (10,20,30);
/*
OUTPUT
Empty set (0.00 sec)
*/
/*========================================================================*/


/*========================================================================*/
/*  Get the product details whose product price is more than “sharpner” */
/*========================================================================*/
select * from product where price > (select price from product where name = 'sharpner');
/*
OUTPUT
+--------+------------+----------+----------+----------+
| price  | product_id | quantity | name     | store_id |
+--------+------------+----------+----------+----------+
| 344.22 | 11111      |        6 | pen      |    11111 |
| 664.22 | 22222      |       45 | pencil   |    22222 |
| 345.98 | 33333      |       14 | football |    22222 |
| 452.75 | 55555      |        4 | eraser   |    33333 |
| 399.99 | 77777      |        3 | p3       |    11111 |
| 620.99 | 99999      |       40 | p4       |    11111 |
+--------+------------+----------+----------+----------+
6 rows in set (0.00 sec)
*/
/*========================================================================*/


/*========================================================================*/
/* Find the purchase order whose purchase amount is greater than maximum purchase amount. */
/*========================================================================*/
select order_id, sum((select price from product where product_id = prod_id)) as total from orders group by order_id order by total desc limit 1;
/*
OUTPUT
+----------+-----------------+
| order_id | total           |
+----------+-----------------+
| 5        | 1064.2099609375 |
+----------+-----------------+
1 row in set (0.00 sec)
*/


<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>mms-doctors</title>
	<link rel="stylesheet" href="../patient/css/bootstrap.min.css">
	<link rel="stylesheet" href="../style.css">
	<style>
		.error {color: #FF0000;}
	</style>
</head>
<body>


<?php
		if($_SESSION['adminstatus'] == ""){
			header("location:doctorlogin.php");
		}
		
		   

	 ?>


<div class="container-fluid">
		<div class="header_top">
			
			<span style="font-size:50px;color:#2c2f84;font-weight:bolder;margin-left:15px;">Doctor Appoinment System</span>
		</div>

	<!-- 	this is for menu -->
	<div class="navbar navbar-default nav">
		<nav class="menu">
			<ul>
				
				<li><a href="myAppoinment.php">My Appoinment</a></li>
				<li><a href="myCustomer.php">Customer Details</a></li>
				<li><a href="#">Add Description</a></li>
				<li><a href="myDetails.php">My Details</a></li>
				<li><a href="../patient/logout.php">Logout</a></li>
			</ul>
		</nav>
	</div>
	

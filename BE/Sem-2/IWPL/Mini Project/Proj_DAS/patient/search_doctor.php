<?php if(!isset($_SESSION)){
	session_start();
	}
?>
<!doctype html>
<html>
<head>
<meta charset='utf-8'>
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1">
   <script src="http://code.jquery.com/jquery-latest.min.js" type="text/javascript"></script>
   <script src="script.js"></script>
   <link rel="stylesheet" href="css/bootstrap.min.css">
	 <link rel="stylesheet" href="style.css">
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
<link href="https://cdnjs.cloudflare.com/ajax/libs/bootswatch/3.4.0/paper/bootstrap.min.css" rel="stylesheet">
<script src="https://code.jquery.com/jquery-1.12.4.min.js"></script>
<link href="https://www.jqueryscript.net/css/jquerysctipttop.css" rel="stylesheet" type="text/css">
<link href="filter.css" rel="stylesheet">
<script src="filter.js"></script>
<title>Users</title>
<style>
		th {
			text-align:center;
		}
        .error {color: #FF0000;}

		@import url(http://fonts.googleapis.com/css?family=Raleway);
		#cssmenu,
		#cssmenu ul,
		#cssmenu ul li,
		#cssmenu ul li a {
		margin: 0;
		padding: 0;
		border: 0;
		list-style: none;
		line-height: 1;
		display: block;
		position: relative;
		-webkit-box-sizing: border-box;
		-moz-box-sizing: border-box;
		box-sizing: border-box;
		}
		#cssmenu:after,
		#cssmenu > ul:after {
		content: ".";
		display: block;
		clear: both;
		visibility: hidden;
		line-height: 0;
		height: 0;
		}
		#cssmenu {
		width: auto;
		border-bottom: 3px solid #47c9af;
		font-family: Raleway, sans-serif;
		line-height: 1;
		}
		#cssmenu ul {
		background: #ffffff;
		}
		#cssmenu > ul > li {
		float: left;
		}
		#cssmenu.align-center > ul {
		font-size: 0;
		text-align: center;
		}
		#cssmenu.align-center > ul > li {
		display: inline-block;
		float: none;
		}
		#cssmenu.align-right > ul > li {
		float: right;
		}
		#cssmenu.align-right > ul > li > a {
		margin-right: 0;
		margin-left: -4px;
		}
		#cssmenu > ul > li > a {
		z-index: 2;
		padding: 18px 25px 12px 25px;
		font-size: 15px;
		font-weight: 400;
		text-decoration: none;
		color: #444444;
		-webkit-transition: all .2s ease;
		-moz-transition: all .2s ease;
		-ms-transition: all .2s ease;
		-o-transition: all .2s ease;
		transition: all .2s ease;
		margin-right: -4px;
		}
		#cssmenu > ul > li.active > a,
		#cssmenu > ul > li:hover > a,
		#cssmenu > ul > li > a:hover {
		color: #ffffff;
		}
		#cssmenu > ul > li > a:after {
		position: absolute;
		left: 0;
		bottom: 0;
		right: 0;
		z-index: -1;
		width: 100%;
		height: 120%;
		border-top-left-radius: 8px;
		border-top-right-radius: 8px;
		content: "";
		-webkit-transition: all .2s ease;
		-o-transition: all .2s ease;
		transition: all .2s ease;
		-webkit-transform: perspective(5px) rotateX(2deg);
		-webkit-transform-origin: bottom;
		-moz-transform: perspective(5px) rotateX(2deg);
		-moz-transform-origin: bottom;
		transform: perspective(5px) rotateX(2deg);
		transform-origin: bottom;
		}
		#cssmenu > ul > li.active > a:after,
		#cssmenu > ul > li:hover > a:after,
		#cssmenu > ul > li > a:hover:after {
		background: #47c9af;
		}

			body { background-color: #f7f7f7; }
			table{
				width:100%;
			}
			th td{
				padding:20px;
				width:40%;
				text-align:center;
			}
    </style>
</head>
<body>
<div class="container-fluid">
		<div class="header_top">
			<span style="font-size:50px;color:#40E0D0;font-weight:bolder;margin-left:15px;">Welcome User!</span>
		</div>

		<div id='cssmenu'>
			<ul>
				<li ><a href='dashboard.php'>Home</a></li>
				<li><a href='myDetails.php'>My Details</a></li>
				<li class='active'><a href='search_doctor.php'>Search Doctors</a></li>
				<li><a href='view_booking.php'>View Appointments</a></li>
				<li><a href='changepwd.php'>Change Password</a></li>
				<li><a href='logout.php'>Logout</a></li>
			</ul>
		</div>
	<!-- <?php include('function.php'); ?> -->



	<!-- this is for donor registraton -->
	<div class="search" style="background-color:;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;padding: 5px;">Search Here</h3>
		<center>

		 <div class="formstyle" style="padding:40px;border: 1px solid lightgrey;background-color:#f3f3f8;color:#141313;width:70%;height:190px;">
					<?php 
						if($_GET){
							echo "<p><b>".$_GET['msg']."</b></p>";
						}
					?>

					<form action="search_doctor.php" method="post" class="form-group">

					<label style="float:left;">
						Appointment date : <input name="appdate" type="date" required/>
					</label>

					<label style="float:left;margin-left:20px;">
						Service Area : <select name="service" type="text" >
									<?php 
											include_once 'assets/conn/dbconnect.php';

											$sql = " SELECT DISTINCT(service) FROM doctor";
											$result = mysqli_query($con,$sql);
											$count = mysqli_num_rows($result);

											if($count>=1){
												echo "<option>-Select-</option>";

												while($row=mysqli_fetch_array($result)){
														echo "<option>".$row['service']."</option>";
												}
											}
									?>
												
								</select>

					</label>

					<label style="float:left;margin-left:20px;">
						Expertise : <select name="expertise" type="text">
									<?php 
											include_once 'assets/conn/dbconnect.php';

											$sql = " SELECT DISTINCT(expertise) FROM doctor";
											$result = mysqli_query($con,$sql);
											$count = mysqli_num_rows($result);

											if($count>=1){
												echo "<option>-Select-</option>";

												while($row=mysqli_fetch_array($result)){
														echo "<option>".$row['expertise']."</option>";
												}
											}
											
											// mysqli_close($con);
									?>
												
								</select>

					</label>
					<br>
					<br>
					<br>
					<center>
					<button name="submit" type="submit" style="border-radius: 5px;color:#000;">Search</button>
					</center>
					<br>
					
					</form>

		 	</div>
	</div>
<?php

	if(isset($_POST['submit'])){

		if($_POST['appdate']>= date("Y-m-d")){
			echo "<table style=\"width:80%;\">";
			echo "<thead>";
			echo "<tr>";
			echo "<th>Name</th>";
			echo "<th>Service</th>";
			echo "<th>Address</th>";
			echo "<th>Contact</th>";
			echo "<th>Email</th>";
			echo "<th>Expertise</th>";
			echo "<th>Qualify</th>";
			echo "<th>Fee</th>";
			echo "<th>Book</th>";
			echo "</tr>";
			echo "</thead>";

		include_once 'assets/conn/dbconnect.php';


		$sql = " SELECT name,service,address,contact,email,expertise,qualify,fee,userid FROM doctor WHERE expertise='".$_POST['expertise']."' AND service='".$_POST['service']."'";
		$result = mysqli_query($con,$sql);
		$count = mysqli_num_rows($result);


		if($count>=1){
			while($row=mysqli_fetch_array($result)){
					echo "<tr>";
					echo "<td>".$row['name']."</td>";
					echo "<td>".$row['service']."</td>";
					echo "<td>".$row['address']."</td>";
					echo "<td>".$row['contact']."</td>";
					echo "<td>".$row['email']."</td>";
					echo "<td>".$row['expertise']."</td>";
					echo "<td>".$row['qualify']."</td>";
					echo "<td>".$row['fee']."</td>";
					echo "<td><a href=\"book.php?userid=".$row['userid']."&"
													."dates=".$_POST['appdate']."&"
													."icpatient=".$_SESSION["icPatient"]
													// ."icpatient=101"
													."\">Book</a></td>";
					echo "</tr>";
			}
			echo "</table>";
		}
		else{
			print "<p align='center'>Sorry, No match found for your search result..!!!</p>";
		}


		mysqli_close($con);

		}	else{
			
			echo "<script>alert('Select proper date!');</script>";
		}

	}
?>
	</div><!--  containerFluid Ends -->
	</center>
	<script src="js/bootstrap.min.js"></script>

</body>
</html>
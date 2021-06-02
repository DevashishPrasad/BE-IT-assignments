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
	input{
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
   <li class='active'><a href='myDetails.php'>My Details</a></li>
   <li><a href='search_doctor.php'>Search Doctors</a></li>
   <li><a href='view_booking.php'>View Appointments</a></li>
   <li><a href='changepwd.php'>Change Password</a></li>
   <li><a href='logoutadmin.php'>Logout</a></li>

</ul>
</div>
<!-- this is for donor registraton -->

<!-- for retriving data -->
				<?php 
							include_once 'assets/conn/dbconnect.php';

							$sql="SELECT * FROM user WHERE icPatient='" . $_SESSION["icPatient"] . "'";
							// $sql="SELECT * FROM user WHERE icPatient=";
							$q=mysqli_query($con,$sql);
							// echo $q;
							
							$data=mysqli_fetch_array($q);
							$FirstName=$data[2];
							$LastName=$data[3];
							$DOB=$data[4];
							$Gender=$data[5];
							$Address=$data[6];
							$Phone=$data[7];
							$Email=$data[8];
							// $Age=$data[9];

							mysqli_close($con);
	?>
<!-- for retriving data -->

<div class="login" style="background-color:#f3f3f8;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;">My Details</h3>
			<center>
			<div class="formstyle" style="padding:20px;border: 1px solid lightgrey;background-color:#f3f3f8;color:#141313;width:20%;height:450px">
				<center>
				<form action="" method="post" style="text-align:center;float:left;">					
					<label>
						First Name: <input type="text" name="fname" value="<?php echo $FirstName; ?>" placeholder="First name" required>
					</label><br><br>

					<label>
						Last Name: <input type="text" name="lname"  value="<?php echo $LastName; ?>" placeholder="Last name" required="required"/>
					</label><br><br>
					<label>
						Date of Birth: <input type="date" name="dob" value="<?php echo $DOB; ?>" placeholder="YYYY-MM-DD" required="required"/>
					</label><br><br>
 					
 					<label>
						Address: <input type="text" name="address" value="<?php echo $Address; ?>" placeholder="Address" required>
					</label><br><br>
					<label>
						Gender: &nbsp &nbsp &nbsp &nbsp &nbsp
						Male: <input type="radio" name="gender" value="Male" <?php if($Gender == 'Male') echo 'checked'; ?> required> &nbsp &nbsp
						Female: <input type="radio" name="gender" value="Female" <?php if($Gender == 'Female') echo 'checked'; ?> required>
					</label><br><br>

					<label>
						Email: <input type="email" name="email" value="<?php echo $Email; ?>" placeholder="your@email.com" required>
					</label><br><br>
					
					<label>
						Phone: <input type="number" name="phone" value="<?php echo $Phone; ?>" placeholder="###-###-####" required  pattern="[0-9]{10,11}" title="please enter only numbers between 10 to 11 for mobile no.">
					</label><br><br>					
					
										
					
					<button name="submit" type="submit" style="margin-left:43px;width:108px;border-radius: 3px;">UpdateProfile</button> <br>

					</center>
				</form> 
				</center>
			<br>
			<br>
	</div>
			</center>	
	
	
</div>
<br><br><br>

			<!-- update information -->

				<?php
							include('config.php');
							if(isset($_POST['submit'])){

							// $sql="UPDATE user SET patientFirstName='" .$_POST["fname"]. "', patientLastName='" .$_POST["lname"]. "' patientDOB='" .$_POST["dob"]. "',age='" .$_POST["age"]."' , patientPhone='" .$_POST["phone"]. "', patientAddress='" .$_POST["address"]. "', patientEmail='".$_POST["email"]."', patientGender='" .$_POST["gender"]. "' WHERE icPatient='" .$_SESSION["icPatient"]. "'";
							$sql="UPDATE user SET patientFirstName='" .$_POST["fname"]. "', patientLastName='" .$_POST["lname"]. "', patientDOB='" .$_POST["dob"]. "',  patientPhone='" .$_POST["phone"]. "', patientAddress='" .$_POST["address"]. "', patientEmail='".$_POST["email"]."', patientGender='" .$_POST["gender"]. "' WHERE icPatient='".$_SESSION["icPatient"]. "'";
							
							if (mysqli_query($conn, $sql)) {
						    echo "<script>alert(' Record updated successfully');</script>";
							} else {
							    echo "<script>alert('There was a Error Updating profile');</script>";
							}

						mysqli_close($conn);
													}
					?> 
			<!-- update information End -->




</body>
</html>

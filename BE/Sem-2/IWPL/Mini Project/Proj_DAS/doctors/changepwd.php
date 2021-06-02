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
<title>Doctors</title>
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
    </style>
</head>
<body>
<div class="container-fluid">
		<div class="header_top">
			<span style="font-size:50px;color:#40E0D0;font-weight:bolder;margin-left:15px;">Welcome Doctor!</span>
		</div>


<div id='cssmenu'>
<ul>
<li ><a href='dashboard.php'>Home</a></li>
<li ><a href='myAppoinment.php'>My Appointments</a></li>
   <li ><a href='myCustomer.php'>Patient's Details</a></li>
   <li ><a href='myDetails.php'>My Profile</a></li>
   <li><a href='schedule.php'>My Schedule</a></li>
   <li class='active'><a href='changepwd.php'>Change Password</a></li>
   <li><a href='logout.php'>Logout</a></li>


</ul>
</div>

	<!-- this is for donor registraton -->
	<div class="dashboard" style="background-color:#fff;">
		<h3 class="text-center" style="background-color:#272327;;color: #fff;padding: 5px;">Change Password</h3>
		<div class="formstyle" style="float: right;padding:20px;border: 1px solid lightgrey;margin-right:585px; margin-bottom:30px;background-color:#f3f3f8;color:#141313;">
				<form action="" method="post" class="text-center">
					<label>
						<span style="color: #000">Old Password:</span><input type="password" name="password"  placeholder="Current password" required>
					</label><br><br>
					<label>
						<span style="color: #000">new Password:</span><input type="password" name="newpassword"  placeholder="New password" required>
					</label><br><br>
					<label>
						<span style="color: #000">confirm Password:</span><input type="password" name="confpassword"  placeholder=" confirm password" required>
					</label><br><br>
					<button name="submit" type="submit" style="border-radius: 3px;color:#000;margin-right: -51px;">Update Password</button> <br>

					


					<!-- login validation -->
			<?php 
					
					include_once '../assets/conn/dbconnect.php';

					if(isset($_POST["submit"])){
					

					$sql= "SELECT * FROM doctor WHERE userid= '" . $_SESSION["userid"]."' AND password= '" . $_POST["password"]."'";
					echo $_SESSION["patient"];
					$query=mysqli_query($con,$sql);
					$row=mysqli_num_rows($query);
						
					if($row>0){
						//check the new password
						$newpassword=$_POST["newpassword"];
						$confpassword=$_POST["confpassword"];
						if($newpassword==$confpassword){
						
						$sql1="UPDATE doctor SET password='" . $_POST["newpassword"]  ."' WHERE userid='" .$_SESSION["userid"] ."'";
						mysqli_query($con,$sql1);
						mysqli_close($con);
						echo "<script>alert('Password Has been Updated');</script>";
						
						}else{
							echo "<script>alert('Password did not match');</script>";

						}


					}else{
						echo "<script>alert('Input Correct Password');</script>";
					}
							
								
						
			}
			

 			?>
		<!-- login validation End-->


				</form> <br>&nbsp;&nbsp;&nbsp;
				
				<br>

				
		
				
			
		
	</div>
		
		
			
		
	</div>
	
	

	


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


 
			



	
</body>
</html>

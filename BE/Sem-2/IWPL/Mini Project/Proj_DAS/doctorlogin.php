<?php session_start();  ?>
<!doctype html>
<html lang=''>
<head>
   <meta charset='utf-8'>
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1">
   <script src="http://code.jquery.com/jquery-latest.min.js" type="text/javascript"></script>
   <script src="script.js"></script>
   <link rel="stylesheet" href="css/bootstrap.min.css">
	 <link rel="stylesheet" href="style.css">
   <title>Doctor Login</title>
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

   </style>
</head>
<body>
<div class="container-fluid">
		<div class="header_top"><br><br><br>
			<span style="font-size:50px;color:#207068;text-decoration: underline;text-decoration-color:#78B4AE ;font-weight:bolder;margin-left:35px;margin-top:15px;">Doctor's </span><br>
			<span style="font-size:50px;color:#207068;text-decoration: underline;text-decoration-color:#78B4AE ;font-weight:bolder;margin-left:35px;margin-top:15px;">Appointment<br></span>
			<span style="font-size:50px;color:#207068;text-decoration: underline;text-decoration-color:#78B4AE ;font-weight:bolder;margin-left:35px;margin-top:15px;">System </span>
		</div>


<div id='cssmenu'>
<ul>
   <li><a href='index.php'>Home</a></li>
   <li><a href='signin.php'>Back</a></li>
	
</ul>
</div>

</body>
<html>








	<!-- this is for donor registraton -->
	<div class="login" style="background-color:#fff;">
		<h1 class="text-center" style="background-color:#272327;color: #fff;">Doctors Login</h1>
			<div class="formstyle" style="padding: 10px;border: 1px solid lightgrey;margin-right: 30%;margin-left: 30%; margin-bottom: 25px;background-color:#f3f3f8;color:#141313;">
				<form action="" method="post" class="text-center">
					<label>
						<input type="text" name="userid"  placeholder="userid" required>
					</label><br><br>
					<label>
						<input type="password" name="password"  placeholder="password">
					</label><br><br>
					<button name="submit" type="submit" style="float:left;margin-top:20px;margin-bottom:20px;margin-left:45%;padding: 5px 25px; border-radius: 4px;">Login</button> <br>

					


					<!-- login validation -->
			<?php 
							$_SESSION['adminstatus']="";
							
							include_once 'assets/conn/dbconnect.php';
							if(isset($_POST["submit"])){

							$sql= "SELECT * FROM doctor WHERE userid= '" . $_POST["userid"]."' AND password= '" . $_POST["password"]."'";

							$result = $con->query($sql);

									if ($result->num_rows > 0) {
											$_SESSION["userid"]= $_POST["userid"];
											// $_SESSION["type"]=$result[2];
											$_SESSION['adminstatus']= "yes";
										    echo "<script>location.replace('doctors/dashboard.php');</script>";
												// echo "u are supposed to redirect to ur profile";
										} else {
										    echo "<span style='color:red;'>Invalid username or password</span>";
										}
						$con->close();		
					}
					
 			?>
		<!-- login validation End-->


				</form> <br>&nbsp;&nbsp;&nbsp;
				
				<br>

				
		
				
			
		
	</div>
	
	
</div>
	
<?php include('../footer.php'); ?>

	
</div><!--  containerFluid Ends -->




<script src="../js/bootstrap.min.js"></script>


 
			



	
</body>
</html>


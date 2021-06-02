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
   <title>Patient Registration</title>
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
<li ><a href='index.php'>Home</a></li>
   <li><a href='about.php'>About Us</a></li>
   <li><a href='service areas.php'>Service Areas</a></li>
   <li><a href='cont.php'>Contact Us</a></li>
   <li><a href='feed.php'>Feedback</a></li>
   <li class='active'><a href='signin.php'>Users</a></li>


</ul>
</div>

</body>
<html>






	<!-- this is for donor registraton -->
	
	<div class="login" style="background-color:#fff;">
		<h1 class="text-center" style="background-color:#272327;color: #fff;">Congratulations....!!!</h1><br>
		 		<p style="font-size:20px;" class="text-center">You have been registered!</p><br>
		 		<p style="font-size:20px;" class="text-center">Check Your Email or Phone to know the Login Credentials!</p><br>

			
	</div>
	
	
</div>
	
	

	
 <?php include('footer.php'); ?>


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


	
</body>
</html>

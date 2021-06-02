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
    label{
        text-align:left;
    }
    </style>
</head>
<body>
<div class="container-fluid">
		<div class="header_top">
			<span style="font-size:50px;color:#40E0D0;font-weight:bolder;margin-left:15px;">Welcome Admin!</span>
		</div>


<div id='cssmenu'>
<ul>
   <li><a href='adminpanel.php'>Home</a></li>
   <li><a href='view_user.php'>Users</a></li>
   <li class='active'><a href='view_doctor.php'>Doctors</a></li>
   
   <li ><a href='service_areas.php'>Service Areas</a></li>
   <li><a href='view_feedback.php'>Feedback</a></li>
   <li><a href='logoutadmin.php'>Logout</a></li>

</ul>
</div>
<!-- this is for donor registraton -->
<div class="dashboard" style="background-color:#fff;">
    <h3 class="text-center" style="background-color:#272327;color: #fff;padding: 5px;">Add Doctor</h3>
    
    <div class="formstyle" style="float: right;padding:70px;padding-bottom:0px;border: 1px solid lightgrey;margin-right:515px; margin-bottom:15px;background-color:#47c9af;color:#141313;">
				<form action="new_doc.php" method="post" class="text-center form-group">
					
					

					<label style="text-align:left;font-size:20px;">
						Doctor's Name: <input type="text" name="name" value="" required>
					</label><br><br>
                    
                    <label style="text-align:left;font-size:20px;">
						Expertise: <input type="text" name="expertise" value=""  required>
                    </label><br><br>
                    
                    <label style="text-align:left;font-size:20px;">
						Category ID: <input type="number" name="cat" value=""  required>
					</label><br><br>

                    <label style="text-align:left;font-size:20px;">
						Qualification: <input type="text" name="qualification" value=""  required>
					</label><br><br>

                    <label style="text-align:left;font-size:20px;">
						Service Areas: <input type="text" name="service" value=""  required>
					</label><br><br>

 					<label style="text-align:left;font-size:20px;">
						Address: <input type="text" name="address" value=""  required>
					</label><br><br>

					
					<label style="text-align:left;font-size:20px;">
						Phone No.: <input type="text" name="phone" value=""  required />
					</label><br><br>
 					<label style="text-align:left;font-size:20px;">
						Email: <input type="email" name="email" value=""  required>
					</label><br><br>
					<label style="text-align:left;font-size:20px;">
						Fee: <input type="text" name="fee" value=""  required>
                    </label><br><br><br>
                    
                    <label style="text-align:left;font-size:20px;">
						User ID: <input type="text" name="uid" value=""  required>
                    </label><br><br><br>
                    
                    <label style="text-align:left;font-size:20px;">
						Password: <input type="text" name="pass" value=""  required>
					</label><br><br><br>
					
					
					<button name="submit" type="submit" style="margin-left:30px;width:108px;border-radius: 3px;">Add</button> <br>


			</form> <br><br>

	</div>


</body>
</html>

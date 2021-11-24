
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
<title>Appointments</title>
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
			<span style="font-size:50px;color:#40E0D0;font-weight:bolder;margin-left:15px;">Welcome Admin!</span>
		</div>


<div id='cssmenu'>
<ul>
   <li><a href='adminpanel.php'>Home</a></li>
   <li><a href='view_user.php'>Users</a></li>
   <li><a href='view_doctor.php'>Doctors</a></li>
   <li class='active'><a href='view_appointments.php'>Appointments</a></li>
   <li ><a href='service_areas.php'>Service Areas</a></li>
   <li><a href='view_category.php'>Category</a></li>
   <li><a href='view_feedback.php'>Feedback</a></li>
   <li><a href='logoutadmin.php'>Logout</a></li>

</ul>
</div>

<!-- this is for donor registraton -->
<div class="dashboard" style="background-color:#fff;">
    <h3 class="text-center" style="background-color:#272327;color: #fff;padding: 5px;">All Appointments List</h3>
    
    
</div>
    
<div class="container-fluid">
    <hr>
    <div class="row">
        <div class="panel panel-primary filterable">
            <div  style="background-color:#47c9af;" class="panel-heading">
                <h3 class="panel-title">
			<button class="btn btn-default btn-xs btn-filter"><span class="glyphicon glyphicon-filter"></span>Filter</button>
		</h3>



            </div>
            <?php 
                include_once 'assets/conn/dbconnect.php';

                $sql = " SELECT * FROM booking";
                $result = mysqli_query($con,$sql);
                $count = mysqli_num_rows($result);

                if($count>=1){?>
                 <table style="width:100%" class="table table-bordered table-striped">
                <thead>
                    <tr class="filters">
                    <th><input style="text-align:center;" style="text-align:center;" type="text" class="form-control" placeholder="Booking ID" disabled></th>
                    <th><input style="text-align:center;" style="text-align:center;" type="text" class="form-control" placeholder="Dr. Name" disabled></th>
                    <th><input style="text-align:center;" style="text-align:center;" type="text" class="form-control" placeholder="Dr. ID" disabled></th>
                        <th><input style="text-align:center;" type="text" class="form-control" placeholder="Expertise" disabled></th>
                        <th><input style="text-align:center;" type="text" class="form-control" placeholder="IC Patient" disabled></th>
                        <th><input style="text-align:center;" type="text" class="form-control" placeholder="App. Date" disabled></th>
                        <!-- <th><input style="text-align:center;" type="text" class="form-control" placeholder="App. Time" disabled></th> -->
                        <th><input style="text-align:center;" type="text" class="form-control" placeholder="Action" disabled></th>

                    </tr>
                </thead>
                <tbody>           
                        <?php
                    while($row=mysqli_fetch_array($result)){
                            echo "<tr>";
                            // echo "<td>".$row['doctor_id']."</td>";
                            echo "<td>".$row['booking_id']."</td>";
                            
                            echo "<td>".$row['dname']."</td>";
                            echo "<td>".$row['userid']."</td>";
                            echo "<td>".$row['expertise']."</td>";
                            echo "<td>".$row['icpatient']."</td>";
                            echo "<td>".$row['address']."</td>";
                            echo "<td>".$row['dates']."</td>";
                            
                            echo "<td><button type='submit' name='submit' style='color:#000;'>Delete</button></td>";
                            
                            echo "</tr>";
                    }
                    echo "</table>";
                }
                else{
                    print "<p align='center'>Sorry, No match found for your search result..!!!</p>";
                }

                ?>
       </tbody>
            </table>
            <p style="background-color:#47c9af;color:black;">No.of Rows : <span id="rowcount"></span></p>
        </div>
    </div>
</div>
<script>
try {
  fetch(new Request("https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js", { method: 'HEAD', mode: 'no-cors' })).then(function(response) {
    return true;
  }).catch(function(e) {
    var carbonScript = document.createElement("script");
    carbonScript.src = "//cdn.carbonads.com/carbon.js?serve=CK7DKKQU&placement=wwwjqueryscriptnet";
    carbonScript.id = "_carbonads_js";
    document.getElementById("carbon-block").appendChild(carbonScript);
  });
} catch (error) {
  console.log(error);
}
</script>
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-36251023-1']);
  _gaq.push(['_setDomainName', 'jqueryscript.net']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
</body>
</html>

    
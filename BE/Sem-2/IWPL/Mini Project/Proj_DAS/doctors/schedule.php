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
<title>Doctor</title>
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
			<span style="font-size:50px;color:#40E0D0;font-weight:bolder;margin-left:15px;">Welcome Doctor!</span>
		</div>


<div id='cssmenu'>
<ul>
<li><a href='dashboard.php'>Home</a></li>
<li><a href='myAppoinment.php'>My Appointments</a></li>
   <li ><a href='myCustomer.php'>Patient's Details</a></li>
   <li ><a href='myDetails.php'>My Profile</a></li>
   <li class='active'><a href='schedule.php'>My Schedule</a></li>
   <li ><a href='changepwd.php'>Change Password</a></li>
   <li><a href='logout.php'>Logout</a></li>

</ul>
</div>
<!-- this is for donor registraton -->

<!-- for retriving data -->
				<?php 
							include_once 'assets/conn/dbconnect.php';

							$sql="select a.*, b.*, c.*
							from slot_1 as a
							inner join slot_2 as b on a.dr_id = b.dr_id
							inner join slot_3 as c on a.dr_id = c.dr_id  where a.dr_id= '".$_SESSION['userid']."';";
							$q=mysqli_query($con,$sql);
							// echo $q;
							
							$data=mysqli_fetch_array($q);
                            
                            $mon1_s=$data[1];
							$mon1_e=$data[2];
							$mon1_p=$data[3];
                            
                            $tue1_s=$data[5];
							$tue1_e=$data[6];
                            $tue1_p=$data[7];
                            
                            $wed1_s=$data[9];
							$wed1_e=$data[10];
                            $wed1_p=$data[11];
                            
                            $thu1_s=$data[13];
							$thu1_e=$data[14];
                            $thu1_p=$data[15];
                            
                            $fri1_s=$data[17];
							$fri1_e=$data[18];
                            $fri1_p=$data[19];
                            
                            $sat1_s=$data[21];
							$sat1_e=$data[22];
                            $sat1_p=$data[23];
                            
                            $sun1_s=$data[25];
							$sun1_e=$data[26];
							$sun1_p=$data[27];
                            

                            $mon2_s=$data[30];
							$mon2_e=$data[31];
							$mon2_p=$data[32];
                            
                            $tue2_s=$data[34];
							$tue2_e=$data[35];
                            $tue2_p=$data[36];
                            
                            $wed2_s=$data[38];
							$wed2_e=$data[39];
                            $wed2_p=$data[40];
                            
                            $thu2_s=$data[42];
							$thu2_e=$data[43];
                            $thu2_p=$data[44];
                            
                            $fri2_s=$data[46];
							$fri2_e=$data[47];
                            $fri2_p=$data[48];
                            
                            $sat2_s=$data[50];
							$sat2_e=$data[51];
                            $sat2_p=$data[52];
                            
                            $sun2_s=$data[54];
							$sun2_e=$data[55];
                            $sun2_p=$data[56];
                            

                            $mon3_s=$data[59];
							$mon3_e=$data[60];
							$mon3_p=$data[61];
                            
                            $tue3_s=$data[63];
							$tue3_e=$data[64];
                            $tue3_p=$data[65];
                            
                            $wed3_s=$data[67];
							$wed3_e=$data[68];
                            $wed3_p=$data[69];
                            
                            $thu3_s=$data[71];
							$thu3_e=$data[72];
                            $thu3_p=$data[73];
                            
                            $fri3_s=$data[75];
							$fri3_e=$data[76];
                            $fri3_p=$data[77];
                            
                            $sat3_s=$data[79];
							$sat3_e=$data[80];
                            $sat3_p=$data[81];
                            
                            $sun3_s=$data[83];
							$sun3_e=$data[84];
							$sun3_p=$data[85];
                            mysqli_close($con);
	?>
<!-- for retriving data -->

<div class="login" >
		<h3 class="text-center" style="background-color:#272327;color: #fff;">My Details</h3>
			<center>
		
    <div class="formstyle" style="float:left;padding:20px;margin-top:46.6px;margin-left:65px;border: 1px solid lightgrey;background-color:#f3f3f8;color:#141313;width:30%;height:1090px">
				<center>
				<form action="" method="post" style="text-align:center;float:left;">
                <h3 class="text-center" style="background-color:#40E0D0;color: black;font-size:30px;padding:10px;margin-left:50px;border-radius: 15px;margin-right:15% ;">Morning Slot</h3><br>
                <div style="margin-top:0%;">
					<label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="MONDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="M_hrs1s" value="<?php echo sprintf("%02d",$mon1_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="M_min1s" value="<?php echo ($mon1_s-sprintf("%02d",$mon1_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="M_hrs1e" value="<?php echo sprintf("%02d",$mon1_e);; ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="M_min1e" value="<?php echo ($mon1_e-sprintf("%02d",$mon1_e))*60;?>" placeholder="" required>
                       
                    </label><br>
                   
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="m1p" value="<?php echo $mon1_p; ?>" placeholder="" required>
                    </label>
                    </div>
					<br><br>

					<div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="TUESDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="T_hrs1s" value="<?php echo sprintf("%02d",$tue1_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="T_min1s" value="<?php echo ($tue1_s-sprintf("%02d",$tue1_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="T_hrs1e" value="<?php echo sprintf("%02d",$tue1_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="T_min1e" value="<?php echo ($tue1_e-sprintf("%02d",$tue1_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="t1p" value="<?php echo $tue1_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>

                    <div style="margin-top:13%;">					
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="WEDNESDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="W_hrs1s" value="<?php echo sprintf("%02d",$wed1_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="W_min1s" value="<?php echo ($wed1_s-sprintf("%02d",$wed1_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="W_hrs1e" value="<?php echo sprintf("%02d",$wed1_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="W_min1e" value="<?php echo ($wed1_e-sprintf("%02d",$wed1_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="w1p" value="<?php echo $wed1_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="THURSDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Th_hrs1s" value="<?php echo sprintf("%02d",$thu1_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Th_min1s" value="<?php echo ($thu1_s-sprintf("%02d",$thu1_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Th_hrs1e" value="<?php echo sprintf("%02d",$thu1_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Th_min1e" value="<?php echo ($thu1_e-sprintf("%02d",$thu1_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="th1p" value="<?php echo $thu1_p; ?>" placeholder="" required>
                    </label><br>
                    </div><br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="FRIDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="F_hrs1s" value="<?php echo sprintf("%02d",$fri1_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="F_min1s" value="<?php echo ($fri1_s-sprintf("%02d",$fri1_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="F_hrs1e" value="<?php echo sprintf("%02d",$fri1_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="F_min1e" value="<?php echo ($fri1_e-sprintf("%02d",$fri1_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="f1p" value="<?php echo $fri1_p; ?>" placeholder="" required>
                    </label><br>
					</div><br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="SATURDAY" placeholder="mon" Disabled><br><br>  
                    </label>


                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Sa_hrs1s" value="<?php echo sprintf("%02d",$sat1_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Sa_min1s" value="<?php echo ($sat1_s-sprintf("%02d",$sat1_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Sa_hrs1e" value="<?php echo sprintf("%02d",$sat1_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Sa_min1e" value="<?php echo ($sat1_e-sprintf("%02d",$sat1_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="sa1p" value="<?php echo $sat1_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>
					
                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="SUNDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Su_hrs1s" value="<?php echo sprintf("%02d",$sun1_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Su_min1s" value="<?php echo ($sun1_s-sprintf("%02d",$sun1_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Su_hrs1e" value="<?php echo sprintf("%02d",$sun1_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Su_min1e" value="<?php echo ($sun1_e-sprintf("%02d",$sun1_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="su1p" value="<?php echo $sun1_p; ?>" placeholder="" required>
                    </label><br><br><br>
					</div>

					<button name="slot1_sub" type="submit" style="margin-left:29px;margin-top:50px;width:108px;border-radius: 3px;">UPDATE</button> <br>

					</center>
				</form> 
				</center>
			<br>
			<br>
	</div>
    <div class="formstyle" style="float:left;padding:20px;border: 1px solid lightgrey;background-color:#f3f3f8;color:#141313;width:30%;height:1090px">
    <h3 class="text-center" style="background-color:#40E0D0;color: black;font-size:30px;margin-left:50px;padding:10px;border-radius: 15px;margin-right:50px ;">Afternoon Slot</h3><br>
				<center>
				<form action="" method="post" style="text-align:center;float:left;">					
                
                <div style="margin-top:0%;">
					<label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="MONDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="M_hrs2s" value="<?php echo sprintf("%02d",$mon2_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="M_min2s" value="<?php echo ($mon2_s-sprintf("%02d",$mon2_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="M_hrs2e" value="<?php echo sprintf("%02d",$mon2_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="M_min2e" value="<?php echo ($mon2_e-sprintf("%02d",$mon2_e))*60;?>" placeholder="" required>
                       
                    </label><br>
                   
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="m2p" value="<?php echo $mon2_p; ?>" placeholder="" required>
                    </label>
                    </div>
					<br><br>

					<div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="TUESDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="T_hrs2s" value="<?php echo sprintf("%02d",$tue2_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="T_min2s" value="<?php echo ($tue2_s-sprintf("%02d",$tue2_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="T_hrs2e" value="<?php echo sprintf("%02d",$tue2_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="T_min2e" value="<?php echo ($tue2_e-sprintf("%02d",$tue2_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="t2p" value="<?php echo $tue2_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>

                    <div style="margin-top:13%;">					
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="WEDNESDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="W_hrs2s" value="<?php echo sprintf("%02d",$wed2_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="W_min2s" value="<?php echo ($wed2_s-sprintf("%02d",$wed2_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="W_hrs2e" value="<?php echo sprintf("%02d",$wed2_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="W_min2e" value="<?php echo ($wed2_e-sprintf("%02d",$wed2_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="w2p" value="<?php echo $wed2_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="THURSDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Th_hrs2s" value="<?php echo sprintf("%02d",$thu2_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Th_min2s" value="<?php echo ($thu2_s-sprintf("%02d",$thu2_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Th_hrs2e" value="<?php echo sprintf("%02d",$thu2_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Th_min2e" value="<?php echo ($thu2_e-sprintf("%02d",$thu2_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="th2p" value="<?php echo $thu2_p; ?>" placeholder="" required>
                    </label><br>
                    </div><br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="FRIDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="F_hrs2s" value="<?php echo sprintf("%02d",$fri2_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="F_min2s" value="<?php echo ($fri2_s-sprintf("%02d",$fri2_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="F_hrs2e" value="<?php echo sprintf("%02d",$fri2_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="F_min2s" value="<?php echo ($fri2_e-sprintf("%02d",$fri2_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="f2p" value="<?php echo $fri2_p; ?>" placeholder="" required>
                    </label><br>
					</div><br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="SATURDAY" placeholder="mon" Disabled><br><br>  
                    </label>


                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Sa_hrs2s" value="<?php echo sprintf("%02d",$sat2_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Sa_min2s" value="<?php echo ($sat2_s-sprintf("%02d",$sat2_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Sa_hrs2e" value="<?php echo sprintf("%02d",$sat2_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Sa_min2e" value="<?php echo ($sat2_e-sprintf("%02d",$sat2_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="sa2p" value="<?php echo $sat2_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>
					
                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="SUNDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Su_hrs2s" value="<?php echo sprintf("%02d",$sun2_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Su_min2s" value="<?php echo ($sun2_s-sprintf("%02d",$sun2_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Su_hrs2e" value="<?php echo sprintf("%02d",$sun2_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Su_min2e" value="<?php echo ($sun2_e-sprintf("%02d",$sun2_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="su2p" value="<?php echo $sun2_p; ?>" placeholder="" required>
                    </label><br><br><br>
					</div>

					<button name="slot2_sub" type="submit" style="margin-left:29px;margin-top:50px;width:108px;border-radius: 3px;">UPDATE</button> <br>

					</center>
				</form> 
				</center>
			<br>
			<br>
	</div>
    
    <div class="formstyle" style="float:left;padding:20px;border: 1px solid lightgrey;background-color:#f3f3f8;color:#141313;width:30%;height:1090px">
				<center>
                <h3 class="text-center" style="background-color:#40E0D0;color: black;font-size:30px;padding:10px;border-radius: 15px;margin-left:50px;margin-right:50px ;">Evening Slot</h3><br>
				<form action="" method="post" style="text-align:center;float:left;">					
                <div style="margin-top:0%;">
					<label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="MONDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="M_hrs3s" value="<?php echo sprintf("%02d",$mon3_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="M_min3s" value="<?php echo ($mon3_s-sprintf("%02d",$mon3_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="M_hrs3e" value="<?php echo sprintf("%02d",$mon3_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="M_min3e" value="<?php echo ($mon3_e-sprintf("%02d",$mon3_e))*60;?>" placeholder="" required>
                       
                    </label><br>
                   
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="m3p" value="<?php echo $mon3_p; ?>" placeholder="" required>
                    </label>
                    </div>
					<br><br>

					<div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="TUESDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="T_hrs3s" value="<?php echo sprintf("%02d",$tue3_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="T_min3s" value="<?php echo ($tue3_s-sprintf("%02d",$tue3_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="T_hrs3e" value="<?php echo sprintf("%02d",$tue3_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="T_min3e" value="<?php echo ($tue3_e-sprintf("%02d",$tue3_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="t3p" value="<?php echo $tue3_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>

                    <div style="margin-top:13%;">					
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="WEDNESDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="W_hrs3s" value="<?php echo sprintf("%02d",$wed3_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="W_min3s" value="<?php echo ($wed3_s-sprintf("%02d",$wed3_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="W_hrs3e" value="<?php echo sprintf("%02d",$wed3_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="W_min3e" value="<?php echo ($wed3_e-sprintf("%02d",$wed3_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="w3p" value="<?php echo $wed3_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="THURSDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Th_hrs3s" value="<?php echo sprintf("%02d",$thu3_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Th_min3s" value="<?php echo ($thu3_s-sprintf("%02d",$thu3_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Th_hrs3e" value="<?php echo sprintf("%02d",$thu3_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Th_min3e" value="<?php echo ($thu3_e-sprintf("%02d",$thu3_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="th3p" value="<?php echo $thu3_p; ?>" placeholder="" required>
                    </label><br>
                    </div><br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="FRIDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="F_hrs3s" value="<?php echo sprintf("%02d",$fri3_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="F_min3s" value="<?php echo ($fri3_s-sprintf("%02d",$fri3_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="F_hrs3e" value="<?php echo sprintf("%02d",$fri3_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="F_min3e" value="<?php echo ($fri3_e-sprintf("%02d",$fri3_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="f3p" value="<?php echo $fri3_p; ?>" placeholder="" required>
                    </label><br>
					</div><br><br>

                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="SATURDAY" placeholder="mon" Disabled><br><br>  
                    </label>


                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Sa_hrs3s" value="<?php echo sprintf("%02d",$sat3_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Sa_min3s" value="<?php echo ($sat3_s-sprintf("%02d",$sat3_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Sa_hrs3e" value="<?php echo sprintf("%02d",$sat3_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Sa_min3e" value="<?php echo ($sat3_e-sprintf("%02d",$sat3_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="sa3p" value="<?php echo $sat3_p; ?>" placeholder="" required>
                    </label><br>
                    </div>
                    <br><br>
					
                    <div style="margin-top:13%;">
                    <label style="float:left;">
                    <input  style="width:100px;margin-left:40px;"  type="text" name="mon1" value="SUNDAY" placeholder="mon" Disabled><br><br>  
                    </label>

                    <label style="float:left;">
                        Start-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Su_hrs3s" value="<?php echo sprintf("%02d",$sun3_s); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Su_min3s" value="<?php echo ($sun3_s-sprintf("%02d",$sun3_s))*60;?>" placeholder="" required>
                       
                    </label>
                    
                    <label style="float:left;">
                        End-Time : <input  style="width:30px;margin-right:5px;"  type="text" name="Su_hrs3e" value="<?php echo sprintf("%02d",$sun3_e); ?>" placeholder="" required>:<input  style="width:30px;margin-right:5px;"  type="text" name="Su_min3e" value="<?php echo ($sun3_e-sprintf("%02d",$sun3_e))*60;?>" placeholder="" required>
                       
                    </label>
                    <label style="float:left;margin-left:34.5%;">
                     No. Of Patients : <input  style="width:30px;margin-right:5px;"  type="text" name="su3p" value="<?php echo $sun3_p; ?>" placeholder="" required>
                    </label><br><br><br>
					</div>

					<button name="slot3_sub" type="submit" style="margin-left:29px;margin-top:50px;width:108px;border-radius: 3px;">UPDATE</button> <br>

					</center>
				</form> 
				</center>
			<br>
			<br>
	</div>
			</center>	
	
    </div>
	
</div>

<br><br><br>

			<!-- update information -->

				<?php
							include('config.php');


							if(isset($_POST['slot1_sub'])){

                                $m1s= $_POST['M_hrs1s'] + ($_POST['M_min1s']/60);
                                $m1e= $_POST['M_hrs1e'] + ($_POST['M_min1e']/60);
                                
                                $t1s= $_POST['T_hrs1s'] + ($_POST['T_min1s']/60);
                                $t1e= $_POST['T_hrs1e'] + ($_POST['T_min1e']/60);
                                
                                $w1s= $_POST['W_hrs1s'] + ($_POST['W_min1s']/60);
                                $w1e= $_POST['W_hrs1e'] + ($_POST['W_min1e']/60);
                                
                                $th1s= $_POST['Th_hrs1s'] + ($_POST['Th_min1s']/60);
                                $th1e= $_POST['Th_hrs1e'] + ($_POST['Th_min1e']/60);
                                
                                $f1s= $_POST['F_hrs1s'] + ($_POST['F_min1s']/60);
                                $f1e= $_POST['F_hrs1e'] + ($_POST['F_min1e']/60);
                                
                                $sa1s= $_POST['Sa_hrs1s'] + ($_POST['Sa_min1s']/60);
                                $sa1e= $_POST['Sa_hrs1e'] + ($_POST['Sa_min1e']/60);
                                
                                $su1s= $_POST['Su_hrs1s'] + ($_POST['Su_min1s']/60);
                                $su1e= $_POST['Su_hrs1e'] + ($_POST['Su_min1e']/60);
                                

                            $sql="UPDATE slot_1 SET Mon_s='" .$m1s. "', Mon_e='" .$m1e. "',Mon_p='" .$_POST["m1p"]. "',Mon_a='" .$_POST["m1p"]. "',Tue_s='" .$t1s. "', Tue_e='" .$t1e. "',Tue_p='" .$_POST["t1p"]. "',Tue_p='" .$_POST["t1p"]. "',Wed_s='" .$w1s. "', Wed_e='" .$w1e. "',Wed_p='" .$_POST["w1p"]. "',Wed_a='" .$_POST["w1p"]. "',
                            Thu_s='" .$th1s. "', Thu_e='" .$th1e. "',Thu_p='" .$_POST["th1p"]. "',Thu_a='" .$_POST["th1p"]. "',Fri_s='" .$f1s. "', Fri_e='" .$f1e. "',Fri_p='" .$_POST["f1p"]. "',Fri_a='" .$_POST["f1p"]. "',Sat_s='" .$sa1s. "', Sat_e='" .$sa1e. "',Sat_p='" .$_POST["sa1p"]. "',Sat_a='" .$_POST["sa1p"]. "'
                            ,Sun_s='" .$su1s. "', Sun_e='" .$su1e. "',Sun_p='" .$_POST["su1p"]. "',Sun_a='" .$_POST["su1p"]. "'WHERE dr_id='" .$_SESSION["userid"]. "'";
                            if (mysqli_query($conn,$sql)) {
						    echo "<script>alert(' Record updated successfully');</script>";
							} else {
							    echo "<script>alert('There was a Error Updating profile');</script>";
                            }
                            
                            
						mysqli_close($conn);
													}
					?> 
                    <?php
							include('config.php');

                            
                            if(isset($_POST['slot2_sub'])){

                                $m2s= $_POST['M_hrs2s'] + ($_POST['M_min2s']/60);
                                $m2e= $_POST['M_hrs2e'] + ($_POST['M_min2e']/60);
                                
                                $t2s= $_POST['T_hrs2s'] + ($_POST['T_min2s']/60);
                                $t2e= $_POST['T_hrs2e'] + ($_POST['T_min2e']/60);
                                
                                $w2s= $_POST['W_hrs2s'] + ($_POST['W_min2s']/60);
                                $w2e= $_POST['W_hrs2e'] + ($_POST['W_min2e']/60);
                                
                                $th2s= $_POST['Th_hrs2s'] + ($_POST['Th_min2s']/60);
                                $th2e= $_POST['Th_hrs2e'] + ($_POST['Th_min2e']/60);
                                
                                $f2s= $_POST['F_hrs2s'] + ($_POST['F_min2s']/60);
                                $f2e= $_POST['F_hrs2e'] + ($_POST['F_min2e']/60);
                                
                                $sa2s= $_POST['Sa_hrs2s'] + ($_POST['Sa_min2s']/60);
                                $sa2e= $_POST['Sa_hrs2e'] + ($_POST['Sa_min2e']/60);
                                
                                $su2s= $_POST['Su_hrs2s'] + ($_POST['Su_min2s']/60);
                                $su2e= $_POST['Su_hrs2e'] + ($_POST['Su_min2e']/60);
                                

                                $sql="UPDATE slot_2 SET Mon_s='" .$m2s. "', Mon_e='" .$m2e. "',Mon_p='" .$_POST["m2p"]. "',Mon_a='" .$_POST["m2p"]. "',Tue_s='" .$t2s. "', Tue_e='" .$t2e. "',Tue_p='" .$_POST["t2p"]. "',Tue_a='" .$_POST["t2p"]. "',Wed_s='" .$w2s. "', Wed_e='" .$w2e. "',Wed_p='" .$_POST["w2p"]. "',Wed_a='" .$_POST["w2p"]. "',
                                Thu_s='" .$th2s. "', Thu_e='" .$th2e. "',Thu_p='" .$_POST["th2p"]. "',Thu_a='" .$_POST["th2p"]. "',Fri_s='" .$f2s. "', Fri_e='" .$f2e. "',Fri_p='" .$_POST["f2p"]. "',Fri_a='" .$_POST["f2p"]. "',Sat_s='" .$sa2s. "', Sat_e='" .$sa2e. "',Sat_p='" .$_POST["sa2p"]. "',Sat_a='" .$_POST["sa2p"]. "'
                                ,Sun_s='" .$su2s. "', Sun_e='" .$su2e. "',Sun_p='" .$_POST["su2p"]. "',Sun_a='" .$_POST["su2p"]. "'WHERE dr_id='" .$_SESSION["userid"]. "'";
                                if (mysqli_query($conn,$sql)) {
                                echo "<script>alert(' Record updated successfully');</script>";
                                } else {
                                    echo "<script>alert('There was a Error Updating profile');</script>";
                                }

                                
						mysqli_close($conn);
													}
					?> 
			<!-- update information End -->
            <?php
							include('config.php');

                       
                                if(isset($_POST['slot3_sub'])){

                                    $m3s= $_POST['M_hrs3s'] + ($_POST['M_min3s']/60);
                                    $m3e= $_POST['M_hrs3e'] + ($_POST['M_min3e']/60);
                                    
                                    $t3s= $_POST['T_hrs3s'] + ($_POST['T_min3s']/60);
                                    $t3e= $_POST['T_hrs3e'] + ($_POST['T_min3e']/60);
                                    
                                    $w3s= $_POST['W_hrs3s'] + ($_POST['W_min3s']/60);
                                    $w3e= $_POST['W_hrs3e'] + ($_POST['W_min3e']/60);
                                    
                                    $th3s= $_POST['Th_hrs3s'] + ($_POST['Th_min3s']/60);
                                    $th3e= $_POST['Th_hrs3e'] + ($_POST['Th_min3e']/60);
                                    
                                    $f3s= $_POST['F_hrs3s'] + ($_POST['F_min3s']/60);
                                    $f3e= $_POST['F_hrs3e'] + ($_POST['F_min3e']/60);
                                    
                                    $sa3s= $_POST['Sa_hrs3s'] + ($_POST['Sa_min3s']/60);
                                    $sa3e= $_POST['Sa_hrs3e'] + ($_POST['Sa_min3e']/60);
                                    
                                    $su3s= $_POST['Su_hrs3s'] + ($_POST['Su_min3s']/60);
                                    $su3e= $_POST['Su_hrs3e'] + ($_POST['Su_min3e']/60);
                                   

                                    $sql="UPDATE slot_3 SET Mon_s='" .$m3s. "', Mon_e='" .$m3e. "',Mon_p='" .$_POST["m3p"]. "',Mon_a='" .$_POST["m3p"]. "',Tue_s='" .$t3s. "', Tue_e='" .$t3e. "',Tue_p='" .$_POST["t3p"]. "',Tue_a='" .$_POST["t3p"]. "',Wed_s='" .$w3s. "', Wed_e='" .$w3e. "',Wed_p='" .$_POST["w3p"]. "',Wed_a='" .$_POST["w3p"]. "',
                                    Thu_s='" .$th3s. "', Thu_e='" .$th3e. "',Thu_p='" .$_POST["th3p"]. "',Thu_a='" .$_POST["th3p"]. "',Fri_s='" .$f3s. "', Fri_e='" .$f3e. "',Fri_p='" .$_POST["f3p"]. "',Fri_a='" .$_POST["f3p"]. "',Sat_s='" .$sa3s. "', Sat_e='" .$sa3e. "',Sat_p='" .$_POST["sa3p"]. "',Sat_a='" .$_POST["sa3p"]. "'
                                    ,Sun_s='" .$su3s. "', Sun_e='" .$su3e. "',Sun_p='" .$_POST["su3p"]. "',Sun_a='" .$_POST["su3p"]. "'WHERE dr_id='" .$_SESSION["userid"]. "'";
                                    if (mysqli_query($conn,$sql)) {
                                    echo "<script>alert(' Record updated successfully');</script>";
                                    } else {
                                        echo "<script>alert('There was a Error Updating profile');</script>";
                                    }

						mysqli_close($conn);
													}
					?> 



</body>
</html>

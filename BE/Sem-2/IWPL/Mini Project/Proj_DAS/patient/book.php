<?php
 if(!isset($_SESSION)){
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
		</div><!--  containerFluid Ends -->
	</center>
	<div class="search" style="background-color:;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;padding: 5px;">Book Your Slot</h3>


		<table style="width:100%" class="table table-bordered table-striped">
                <thead>
                    <th style="text-align:center;font-size:20px;" type="text"  placeholder="Slots" >Slots</th>
                        <th style="text-align:center;font-size:20px;" type="text"  placeholder="" >Available Timings</th>
                        <th style="text-align:center; font-size:20px;" type="text"  placeholder="" >Book Now</th>


                    </tr>
                </thead>
				<tbody> 
							<?php
											include_once 'assets/conn/dbconnect.php';

							// echo  $_SESSION['patient'];
							$userid=$_GET['userid'];
							$dates=$_GET['dates'];
							$icpatient= $_SESSION['icPatient'];

							$timestamp = strtotime($dates);

							$day = date('D', $timestamp);

							$sql="select a.*, b.*, c.*
							from slot_1 as a
							inner join slot_2 as b on a.dr_id = b.dr_id
							inner join slot_3 as c on a.dr_id = c.dr_id  where a.dr_id= $userid;";
							$result=mysqli_query($con,$sql);
						
							// $row=mysqli_fetch_array($result);
							// $count= mysqli_num_rows($result);
							// echo $count;

							$day1_s = "";
							$day1_e = "";
							$day1_p = "";
							$day1_a = "";
							$day2_s = "";
							$day2_e = "";
							$day2_p = "";
							$day2_a = "";
							$day3_s = "";
							$day3_e = "";
							$day3_p = "";
							$day3_a = "";								
										
							
							while($row=mysqli_fetch_array($result)){
								
								// echo $row[0];
								if ($day=='Mon'){
										$day1_s = $row[1];
										$day1_e = $row[2];
										$day1_p = $row[3];
										$day1_a = $row[4];
										$day2_s = $row[30];
										$day2_e = $row[31];
										$day2_p = $row[32];
										$day2_a = $row[33];
										$day3_s = $row[59];
										$day3_e = $row[60];
										$day3_p = $row[61];
										$day3_a = $row[62];

												}
												

								else if ($day=='Tue'){
										$day1_s = $row[5];
										$day1_e = $row[6];
										$day1_p = $row[7];
										$day1_a = $row[8];
										$day2_s = $row[34];
										$day2_e = $row[35];
										$day2_p = $row[36];
										$day2_a = $row[37];
										$day3_s = $row[63];
										$day3_e = $row[64];
										$day3_p = $row[65];
										$day3_a = $row[66];
															
												}
								else if ($day=='Wed'){
										$day1_s = $row[9];
										$day1_e = $row[10];
										$day1_p = $row[11];
										$day1_a = $row[12];
										$day2_s = $row[38];
										$day2_e = $row[39];
										$day2_p = $row[40];
										$day2_a = $row[41];
										$day3_s = $row[67];
										$day3_e = $row[68];
										$day3_p = $row[69];
										$day3_a = $row[70];
																		
												}
								else if ($day=='Thu'){
										$day1_s = $row[13];
										$day1_e = $row[14];
										$day1_p = $row[15];
										$day1_a = $row[16];
										$day2_s = $row[42];
										$day2_e = $row[43];
										$day2_p = $row[44];
										$day2_a = $row[45];
										$day3_s = $row[71];
										$day3_e = $row[72];
										$day3_p = $row[73];
										$day3_a = $row[74];
																		
												}					
								else if ($day=='Fri'){
										$day1_s = $row[17];
										$day1_e = $row[18];
										$day1_p = $row[19];
										$day1_a = $row[20];
										$day2_s = $row[46];
										$day2_e = $row[47];
										$day2_p = $row[48];
										$day2_a = $row[49];
										$day3_s = $row[75];
										$day3_e = $row[76];
										$day3_p = $row[77];
										$day3_a = $row[78];
																		
												}
							    else if ($day=='Sat'){
										$day1_s = $row[21];
										$day1_e = $row[22];
										$day1_p = $row[23];
										$day1_a = $row[24];
										$day2_s = $row[50];
										$day2_e = $row[51];
										$day2_p = $row[52];
										$day2_a = $row[53];
										$day3_s = $row[79];
										$day3_e = $row[80];
										$day3_p = $row[81];
										$day3_a = $row[82];
																					
												}
								else if ($day=='Sun'){
										$day1_s = $row[25];
										$day1_e = $row[26];
										$day1_p = $row[27];
										$day1_a = $row[28];
										$day2_s = $row[54];
										$day2_e = $row[55];
										$day2_p = $row[56];
										$day2_a = $row[57];
										$day3_s = $row[83];
										$day3_e = $row[84];
										$day3_p = $row[85];
										$day3_a = $row[86];
														
												}
												

												
							}

							
							if($day1_a>0){
								$p=$day1_p;
								$a=$day1_a;
								$tot = ($day1_e - $day1_s)*60;
								$ppt = $tot/$p ;
								$st = ($day1_s*60);
								$cal = $st + ($ppt*($p-$a));
								$time1_h = $cal/60;
								$time1_m = $cal%60;
							}
							else{
								$time1_h=0;
								$time1_m=0;
							}
							if($day2_a>0){
								$p=$day2_p;
								$a=$day2_a;
								$tot = ($day2_e - $day2_s)*60;
								$ppt = $tot/$p ;
								$st = ($day2_s*60);
								$cal = $st + ($ppt*($p-$a));
								$time2_h = $cal/60;
								$time2_m = $cal%60;
							}
							else{
								$time2_h=0;
								$time2_m=0;
							}
							if($day3_a>0){
								$p=$day3_p;
								$a=$day3_a;
								$tot = ($day3_e - $day3_s)*60;
								$ppt = $tot/$p ;
								$st = ($day3_s*60);
								$cal = $st + ($ppt*($p-$a));
								$time3_h = round($cal/60);
								$time3_m = round($cal%60);
							}
							else{
								$time3_h=0;
								$time3_m=0;
							}
							echo "<tr>";
								echo "<td>".'Morning'."</td>";
								echo "<td>".sprintf("%02d",$time1_h).':'.sprintf("%02d",$time1_m)."</td>";
								if(!$time1_h==0){
								echo "<td><a href=\"book_slot.php?avail=" .$day1_a."&"
								."th=".$time1_h."&"
								."tm=".$time1_m. "&"
								."date=".$dates. "&"
								."dr_id=".$userid. "&"
								."p_id=".$icpatient. "&"
								."slot=slot_1&"
								."day=".$day."\">Book Now</a></td>";
								}else{
									echo "<td>".'Not Available'."</td>";
								}
							echo "<tr>";

							echo "<tr>";
								echo "<td>".'Afternoon'."</td>";
								echo "<td>".sprintf("%02d",$time2_h).':'.sprintf("%02d",$time2_m)."</td>";
								if(!$time2_h==0){
								echo "<td><a href=\"book_slot.php?avail=" .$day2_a."&"
								."th=".$time2_h."&"
								."tm=".$time2_m. "&"
								."date=".$dates. "&"
								."dr_id=".$userid. "&"
								."p_id=".$icpatient. "&"
								."slot=slot_2&"
								."day=".$day."\">Book Now</a></td>";
							}else{
								echo "<td>".'Not Available'."</td>";
							}
							echo "<tr>";

							echo "<tr>";
								echo "<td>".'Evening'."</td>";
								echo "<td>".sprintf("%02d",$time3_h).':'.sprintf("%02d",$time3_m)."</td>";
								if(!$time3_h==0){
								echo "<td><a href=\"book_slot.php?avail=" .$day3_a."&"
								."th=".$time3_h."&"
								."tm=".$time3_m. "&"
								."date=".$dates. "&"
								."dr_id=".$userid. "&"
								."p_id=".$icpatient. "&"
								."slot=slot_3&"
								."day=".$day."\">Book Now</a></td>";
							}else{
								echo "<td>".'Not Available'."</td>";
							}
							echo "<tr>";
							// $dname=$_GET['dname'];
							// $userid=$_GET['userid'];
							// $dcontact=$_GET['dcontact'];
							// $expertise=$_GET['expertise'];
							// $fee=$_GET['fee'];
							// $email=$_GET['email'];
							// $address=$_GET['address'];
							// $dates=$_GET['dates'];
							// $icpatient=$_GET["icpatient"];

							// $sql = "INSERT INTO booking ( dname, userid, dcontact, expertise, fee, email, address, dates, icpatient) VALUES ('".$dname."',".$userid.",'".$dcontact."','".$expertise."','".$fee."','".$email."','".$address."','".$dates."','".$icpatient."')";
							// $result = mysqli_query($con,$sql);

							// header("Location: http://localhost/proj_das/new/patient/search_doctor.php?msg=Your appointment has been booked successfully");
							// exit();
							?>


          

       </tbody>
            </table>

	<script src="js/bootstrap.min.js"></script>



</body>
</html>
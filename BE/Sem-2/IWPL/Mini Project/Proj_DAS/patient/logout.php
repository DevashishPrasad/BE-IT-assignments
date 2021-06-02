<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>Doctors Appointment System</title>
	<link rel="stylesheet" href="css/bootstrap.min.css">
	<link rel="stylesheet" href="style.css">
</head>
<body>


	<?php
		$_SESSION["icPatient"]="";
		$_SESSION["password"]="";

		$_SESSION['userstatus']="";
		      header("location:../index.php");

	 ?>
 <?php include('footer.php'); ?>


</body>
</html>

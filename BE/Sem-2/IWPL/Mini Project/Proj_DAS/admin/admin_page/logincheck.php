<?php
session_start();
include_once 'assets/conn/dbconnect.php';
// include_once 'assets/conn/server.php';

if(isset($_POST['login'])){
	$username = $_POST['uname'];
	$password = $_POST['psw'];

	$sql = " select * from  admin where username='$username' and password='$password' ";
	$query = mysqli_query($con,$sql);

	$row = mysqli_num_rows($query);
		if($row == 1){
			echo "login successful";
			$_SESSION['uname'] = $username;
			header('location:adminpanel.php');
		}else{
			echo "login failed";
			header('location:proj_das/admin.php');
		}

}


?>


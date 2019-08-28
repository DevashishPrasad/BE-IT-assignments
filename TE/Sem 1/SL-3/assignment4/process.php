<?php
	session_start();
	// get all form elements from the file
	$fst = $_GET['first'];
	$mid = $_GET['middle'];
	$lst = $_GET['last'];
	$email = $_GET['email'];
	$url = $_GET['url'];
	
	// check that the elementsd should not be empty
	if(empty($fst)){
		$_SESSION['error'] = "First Name is empty";
		header("Location:index.php");
	}
	else if(empty($mid)){
		$_SESSION['error'] = "Middle Name is empty";
		header("Location:index.php");
	}
	else if(empty($lst)){
		$_SESSION['error'] = "Last Name is empty";
		header("Location:index.php");
	}
	else if(empty($email)){
		$_SESSION['error'] = "Email is empty";
		header("Location:index.php");
	}
	else if(empty($url)){
		$_SESSION['error'] = "URL is empty";
		header("Location:index.php");
	}
	
	// check email validation
	else if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
		$_SESSION['error'] = "$email is not a valid email address";
		header("Location:index.php");
	}
	// check url validation
	else if (!preg_match( '/^(http|https):\\/\\/[a-z0-9_]+([\\-\\.]{1}[a-z_0-9]+)*\\.[_a-z]{2,5}'.'((:[0-9]{1,5})?\\/.*)?$/i',$url)) 
  {
	  $_SESSION['error'] = "$url is not a valid url";
    header("Location:index.php"); 
  }
	else
		header("Location:success.html"); 
?>

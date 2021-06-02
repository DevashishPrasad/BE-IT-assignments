<?php 

	session_start();

	if(isset($_SESSION['admin'])){

		// echo $_SESSION['admin'];
		header('Location: landing.php');
	}

    else{
	
            // Include config file
                    
            include_once 'config.php';

            if(isset($_POST['submit'])){
                $email = $_POST['email'];
                $password = $_POST['password'];
                $question = $_POST['question'];
                $ans = $_POST['answer'];
                                				
                $sql = " INSERT INTO users VALUES ('".$email."','".$password."',".$question.",'".$ans."');";
                if(mysqli_query($con,$sql)){
                         echo 
                        '<script language="javascript" type="text/javascript">
                                alert("Sign up successful! ");
						        window.location = "login.php";
                        </script>';

                    }else{
                        echo '<script language="javascript" type="text/javascript">
                                alert("Sign up unsuccessful!");
                                window.location = "signup.php";
                                </script>';
                }

            }

        }

?>

<!DOCTYPE html>
<html>
   <!-- Required meta tags-->
   <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">


    <!-- Title Page-->
    <title>Sign Up</title>

    <!-- Icons font CSS-->
    <link href="assets/vendor/mdi-font/css/material-design-iconic-font.min.css" rel="stylesheet" media="all">
    <link href="assets/vendor/font-awesome-4.7/css/font-awesome.min.css" rel="stylesheet" media="all">
    <!-- Font special for pages-->
    <link href="https://fonts.googleapis.com/css?family=Poppins:100,100i,200,200i,300,300i,400,400i,500,500i,600,600i,700,700i,800,800i,900,900i" rel="stylesheet">

    <!-- Vendor CSS-->
    <link href="assets/vendor/select2/select2.min.css" rel="stylesheet" media="all">
    <link href="assets/vendor/datepicker/daterangepicker.css" rel="stylesheet" media="all">

    <!-- Main CSS-->
    <link href="assets/css/main.css" rel="stylesheet" media="all">

     <style>
       .title{
        color:white;
       }
      .bg{
      background: url(assets/images/doctor_back.jpg);
      background-repeat: no-repeat;
      background-size: 100% 800px;
      width:100%;
      height:750px;
        }
       label{
         color:white;
       }
       .button {
        font-size:20px;
        padding:8px;
        border-radius:10px;
        background-color: beige;
        border: cadetblue;
        }
        .button:hover {
          background-color:rgba(0,0,0,0.4) ;
          color:white;
        }
       @media (max-width: 767px) {
      .bg{
      background: url(assets/images/doctor_back.jpg);
      background-repeat: no-repeat;
      background-size: 100% 900px;
        }
       }
    </style> 
    </head>
    <body>
    <div class="page-wrapper bg p-t-130 p-b-100 font-poppins">
        <div class="wrapper wrapper--w680">
            <div class="card card-4">
                <div style=" text-align:center; background-color:rgba(0,0,0,0.8);" class="card-body">
                    <h2 > <h1 style="color:white;">SIGN UP</h1></h2>
      
    	<div class="wrapper">
    	    <p style="color:white;">Please fill in your details to sign up.</p><br>
    	    <form action="" method="post"  style="text-align:center;">
		        <div class="form-group ">
		            <label >Email</label><br>
		            <input style="width:280px;height:25px;background-color:grey;border:solid white 1px;" type="email" name="email" class="form-control" required>
		        </div><br>    
		        <div class="form-group ">
		            <label>Password</label><br>
		            <input style="width:280px;height:25px;background-color:grey;border:solid white 1px;" type="password" name="password" class="form-control" required>
		        </div><br>
		        <div class="form-group ">
		            <label>Confirm Password</label><br>
		            <input style="width:280px;height:25px;background-color:grey;border:solid white 1px;" type="password" name="conf_password" class="form-control" required>
		        </div><br>
		        <div class="form-group ">
		            <label>Recovery Question</label><br>
		            <select style="width:280px;height:25px;background-color:grey;border:solid white 1px;" name="question" class="form-control" required>
		            	<option value="1">What is name of your favourite pet?<option>
		            	<option value="2">What is name of your birth city?<option>
		            	<option value="3">What is name of your maternal grandfather?<option>
		            	<option value="4">What is name of your favourite movie?<option>
		            	<option value="5">What is name of your first school?<option>
		            	<option value="6">What is name of your favourite artist?<option>
		            </select>
		        </div><br>
		        <div class="form-group ">
		            <label>Answer</label><br>
		            <input style="width:280px;height:25px;background-color:grey;border:solid white 1px;" type="text" name="answer" class="form-control" required>
		        </div><br>
		        <div style="margin-left:23%;margin-top:10%;" class="form-group">
		            <input style="width:100px;height:25px;background-color:rgba(0,0,0,0.8);color:#1E90FF;border:solid00 #1E90FF 1px;margin-right:28.5%;" type="submit" name="submit" class="btn btn-primary" value="Sign Up">
		        </div><br>
		        <p style="color:#ffffff;"> Go back to <a href="login.php" style="color:#6688ff;">Login</a>.</p>
        	</form>
    	</div>    
</body>
</html>

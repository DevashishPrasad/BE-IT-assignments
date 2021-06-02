<?php
			session_start();
            if(isset($_POST['submit'])){
            			unset($_SESSION['admin']);
			            echo 
                  		        '<script language="javascript" type="text/javascript">
		                            alert("Logout Successful!");
		                            window.location = "login.php";
                                </script>';
            }
            if(isset($_SESSION['admin'])){
            	
            }
            else{
		          echo 
          		        '<script language="javascript" type="text/javascript">
                            alert("Please Login Before Proceeding!");
                            window.location = "login.php";
                        </script>';            
            }
?>

<!DOCTYPE html>
<html>
   <!-- Required meta tags-->
   <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">


    <!-- Title Page-->
    <title>Landing Page</title>

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
      background-repeat: no-repeat;
      background-size: 100% 900px;
        }
        p{
        color:#fff;
       }
    </style> 
    </head>
    <body>
    <div class="page-wrapper bg p-t-130 p-b-100 font-poppins">
        <div class="wrapper wrapper--w680">
            <div class="card card-4">
                <div style=" text-align:center; background-color:rgba(0,0,0,0.8);" class="card-body">
                    <h2 > <h1 style="color:white;">WELCOME </h1></h2>
      
    <div class="wrapper">
			<form action="" method="post"  style="text-align:center;">
				<p style="color:#FFF;"> Welcome user: <?php  echo $_SESSION['admin']?></p>
				<br>
				<br>
				<p style="color:#FFFFFF;" > Go back to login screen?</p> 
				<input style="width:100px;height:25px;background-color:rgba(0,0,0,0.8);color:#1E90FF;border:solid00 #1E90FF 1px;margin-right:28.5%;" type="submit" name="submit" class="btn btn-primary" value="Logout">
			</form>
            <!-- <p>Don't have an account? <a href="register.php">Sign up now</a>.</p> -->
        </form>
    </div>    
</body>
</html>

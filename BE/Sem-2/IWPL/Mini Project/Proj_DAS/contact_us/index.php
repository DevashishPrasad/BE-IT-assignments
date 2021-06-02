<html>
<style>
.alert {
  padding: 5px;
  background-color: #f44336;
  color: white;
  text-align:center;
  border: solid white;
  border-radius: 5px;
  font-size:15px;
}

.try {
  background-color:Black;
  padding:10px;
  font-weight: bold;
  float: left;
  font-size: 15px;
  line-height: 18px;
  cursor: pointer;
  transition: 0.3s;
  margin-left:40%;
  border: solid white;
  border-radius: 5px;
}

a{
    color:white;
}
a:hover {
  color: grey;
}
.msg{
    background-color:rgb(232,232,232);
    height:320px;
    width:30%;
    padding: 3%;
    align:center;
    margin-top:120px;
    margin-left:33%;
    border:solid black;
    border-radius: 25px;
}

.bg{
    background-image: url("assets/img/plus.jpg");
    height: 70%;
  background-position: center;
  background-repeat: no-repeat;
  background-size: cover;
}
</style>
</head>
<body class="bg">

<?php

include_once 'assets/conn/dbconnect.php';

// $patientFirstName=$patientLastName=$patientEmail=$icPatient=$password=$month=$day=$year=$patientDOB=$patientGender=$con_pass="";
// $first_name_err=$last_name_err=$email_err=$username_err=$password_err=$pass_err=$conpass_err="";
$error=false;

if (isset($_POST['submit'])) 
{
		$name = $_POST["userName"];
		$phone = $_POST["phone"];
		$email = $_POST["userEmail"];
		$subject = $_POST["subject"];
		$content = $_POST["content"];
	
		// $conn = mysqli_connect("localhost", "root", "root", "db_healthcare") or die("Connection Error: " . mysqli_error($conn));
		// $result = mysqli_query($conn, "INSERT INTO contact(fullname, phone,email,subject,msg) VALUES ('" . $name. "','" . $phone. "', '" . $email. "','" . $subject. "','" . $content. "')");
		// // $insert_id = mysqli_insert_id($conn);
		echo $result;
	
    
//INSERT
$query = " INSERT INTO contact (fullname, phone,email,subject,msg)
VALUES ( '$name', '$phone', '$email', '$subject', '$content' ) ";
$result = mysqli_query($con, $query);//run the query

// echo $result;

    if( $result )
    {
    ?>
    <script type="text/javascript">
        alert('Thankyou For Contacting Us , We will get back to u soon !');
        window.location.href = "contact-view.php";
    </script>
    <!-- <p class="try"><a href="index.php">Back</a></p> -->
        
    <?php
    }
    else
    {
    ?>
    <script type="text/javascript">
    alert('Error in submitting ');
    window.location.href = "contact-view.php";
    </script>
    <?php
    }
    
}

      

?>
</div>
</body>
</html>

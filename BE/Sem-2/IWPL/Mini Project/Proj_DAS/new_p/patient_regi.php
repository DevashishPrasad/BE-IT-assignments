<!doctype html>
<html lang=''>
<head>
   <meta charset='utf-8'>
   <meta http-equiv="X-UA-Compatible" content="IE=edge">
   <meta name="viewport" content="width=device-width, initial-scale=1">
   <script src="http://code.jquery.com/jquery-latest.min.js" type="text/javascript"></script>
   <script src="script.js"></script>
   <link rel="stylesheet" href="css/bootstrap.min.css">
	 <link rel="stylesheet" href="style.css">
   <title>Patient Registration</title>
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

   </style>
</head>
<body>
<div class="container-fluid">
		<div class="header_top"><br><br><br>
			<span style="font-size:50px;color:#207068;text-decoration: underline;text-decoration-color:#78B4AE ;font-weight:bolder;margin-left:35px;margin-top:15px;">Doctor's </span><br>
			<span style="font-size:50px;color:#207068;text-decoration: underline;text-decoration-color:#78B4AE ;font-weight:bolder;margin-left:35px;margin-top:15px;">Appointment<br></span>
			<span style="font-size:50px;color:#207068;text-decoration: underline;text-decoration-color:#78B4AE ;font-weight:bolder;margin-left:35px;margin-top:15px;">System </span>
		</div>


<div id='cssmenu'>
<ul>
<li ><a href='index.php'>Home</a></li>
   <li><a href='about.php'>About Us</a></li>
   <li><a href='service areas.php'>Service Areas</a></li>
   <li><a href='cont.php'>Contact Us</a></li>
   <li><a href='feed.php'>Feedback</a></li>
   <li class='active'><a href='signin.php'>Users</a></li>


</ul>
</div>

</body>
<html>





	<!-- this is for donor registraton -->
	<div class="recipient_reg" style="background-color:#272327;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;">Patient Registration</h3>

		<div class="formstyle" style="float: right;padding:25px;border: 1px solid lightgrey;margin-right:415px; margin-bottom:30px;background-color:#f3f3f8;color:#141313;">
		<form enctype="multipart/form-data" method="post" onsubmit="return myFunction()" class="text-center">
			 <div class="col-md-12">
				  
			 		<label>
						First Name: <input type="text" name="fname" id="fname" value="" placeholder="Full name" required>
					</label><br><br>

          <label>
						Last Name: <input type="text" name="lname" id="lname" value="" placeholder="Full name" required>
					</label><br><br>
        
          <label>
						Gender: <select name="gender" required>
										<option value="">-select-</option>
										<option value="Male">Male</option>
										<option value="Male">Female</option>
										<option value="Male">Other</option>

									</select>
					</label><br><br>
					<label>
						DOB: <input type="date" name="dob"  placeholder="age"  title="please enter only  numbers between 2 to 2 for age" required/>
					</label><br><br>
          <label>
						Address: <input type="text" name="address" value="" placeholder="address" required>
					</label><br><br>
					<label>
						Contact No: <input type="number" name="phone"  id="phone" placeholder="contact no" required="required" pattern="[0-9]{10,11}" title="please enter only numbers between 10 to 11 for mobile no."/>
					</label><br><br>
 					
 					
					
					<label>
						Email: <input type="email" name="email"  value="" id="email" placeholder="email" required>
					</label><br><br>
					<!-- <label>
						Password: <input type="password" name="password"  value="" placeholder="<=6 (Only Numbers)" required>
					</label><br><br>
					<label>
						Confirm Password: <input type="password" name="password"  value="" placeholder="password" required>
					</label><br><br>
					 -->
					
					<button name="submit" type="submit" style="margin-left:60px;width: 85px;border-radius: 3px;">Register</button> <br>
				
			</div>	<!-- col-md-12 -->


				</form>
			</div>




	</div>
	
	



	
	
 <?php include('footer.php'); ?>


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


	 <!-- validation and insertion -->


				<?php
						include_once '../assets/conn/dbconnect.php';

						if(isset($_POST['submit'])){

						$sql1 = "SELECT * FROM user WHERE patientEmail='".$_POST["email"]."' AND patientPhone='".$_POST["phone"]."' ";
             		    $result = $con->query($sql1);	
             		    if ($result->num_rows > 0) {
			                  echo "<script>alert('Sorry, user already exist!');</script>";
			             }
						else{
              function randomPassword() {
                $alphabet = "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ0123456789";
                $pass = array(); //remember to declare $pass as an array
                $alphaLength = strlen($alphabet) - 1; //put the length -1 in cache
                for ($i = 0; $i < 8; $i++) {
                    $n = rand(0, $alphaLength);
                    $pass[] = $alphabet[$n];
                }
                return implode($pass); //turn the array into a string
            }
            
            $password=randomPassword();
           
							$sql = "INSERT INTO user (password,patientFirstName,patientLastName,patientDOB,patientGender,patientAddress,patientPhone,patientEmail)
							VALUES ('" . $password ."','" . $_POST["fname"] ."','" . $_POST["lname"] . "','" . $_POST["dob"] . "','" . $_POST["gender"] . "','" . $_POST["address"] . "', '" . $_POST["phone"] . "','" . $_POST["email"] . "' )";

							if ($con->query($sql) === TRUE) {

                $sql = "SELECT max(icPatient) from user";
                $result = $con -> query($sql);
                $row = $result -> fetch_array(MYSQLI_NUM);
                $ic = $row[0];
                
                $pass= $password;
                $phone='91'.$_POST["phone"];
                $name=$_POST["fname"].' '.$_POST["lname"];
                $email=$_POST["email"];
              //include ('otp_url.php'); 
                              // create a new cURL resource
              //   $ch = curl_init();

              //   // set URL and other appropriate options
              //    $url_str = 'http://cloud.smsindiahub.in/vendorsms/pushsms.aspx?user=KNEOAutomation&password=kneomapp123&msisdn='.$phone.'&sid=KNMAPP&msg=EVENT%20Dear%20'.$name.',%20Your%20ID%20:%20'.$ic.'%20and%20Password%20is%20'.$pass.'.&fl=0&gwid=2';
              //    echo $url_str;
              // //  echo $url_str;
              //   curl_setopt($ch, CURLOPT_URL, 'http://cloud.smsindiahub.in/vendorsms/pushsms.aspx?user=KNEOAutomation&password=kneomapp123&msisdn='.$phone.'&sid=KNMAPP&msg=EVENT%20Dear%20'.$name.',%20Your%20ID%20:%20'.$ic.'%20and%20Password%20is%20'.$pass.'.&fl=0&gwid=2');
                
              //   curl_setopt($ch,CURLOPT_RETURNTRANSFER,true);
              //   $output=curl_exec($ch);
              //   if(curl_errno($ch))
              //   {
              //       echo 'error:' . curl_error($c);
              //   }
              //   curl_close($ch);
              //   // echo "<script>location.replace('patient_success_msg.php');</script>";
              $url_str = 'http://cloud.smsindiahub.in/vendorsms/pushsms.aspx?user=KNEOAutomation&password=kneomapp123&msisdn='.$phone.'&sid=KNMAPP&msg=EVENT%20Dear%20'.$name.',%20Your%20ID%20:%20'.$ic.'%20and%20Password%20is%20'.$pass.'.&fl=0&gwid=2';
              $url_str = str_replace(" ", "%20", $url_str);
              $output = file($url_str);

              // The response from the gateway is going to look like 
              // this:
              // id: a4c5ad77ad6faf5aa55f66a
              // 
              // In the event of an error, it will look like this:
              // err: invalid login credentials
              $result = explode(":", $output[0]);

              if($result[0] == "id") 
              {
                echo("Message sent\n");
              }
              // else
              // {
               // echo("Error - " . $result[1] . "\n");
              //  require("PHPMailer-master/src/PHPMailer.php");
              //   require("PHPMailer-master/src/SMTP.php");
              //   require("PHPMailer-master/src/Exception.php");
                
            
              //   //$mail = new  PHPMailer();
              // $mail = new   PHPMailer\PHPMailer\PHPMailer();
              //   $mail->IsSMTP(); 

              //   $mail->CharSet="UTF-8";
              //   $mail->Host = "smtp.gmail.com";
              //   $mail->SMTPDebug = 1; 
              //   $mail->Port = 465 ; //465 or 587

              //   $mail->SMTPSecure = 'ssl';  
              //   $mail->SMTPAuth = true; 
              //   $mail->IsHTML(true);

              //   //Authentication
              //   $mail->Username = "kneomapp@gmail.com";
              //   $mail->Password = "KNEO_MAPP123";

              //   //Set Params
              //   $mail->SetFrom("kneomapp@gmail.com");
              //   $mail->AddAddress($email);
              // // $mail->AddAddress("krishna.prasad@kneoautomation.com");
              //   $mail->Subject = "Doctors Appointment System";
              //   $mail->Body = "Hello ".$name." , <br> <br> Your Patient ID is : <b>".$ic."</b> <br><br> Password is : <b>".$pass."</b>";


              //   if(!$mail->Send()) {
              //       echo "Mailer Error: " . $mail->ErrorInfo;
                // } 
                else {
                  echo "<script>location.replace('patient_success_msg.php');</script>";

                }

                
              //  echo "<script>location.replace('patient_success_msg.php');</script>";
              // }


							} else {
							    echo "<script>alert('There was an Error')<script>" . $sql . "<br>" . $con->error;
							}

							$con->close();
						}
					}
				?> 



	<!-- validation and insertion End-->
  <script>
function myFunction() {
  var at = document.getElementById("email").value;
  var lname = document.getElementById("lname").value;
  var fname = document.getElementById("fname").value;
  var phone = document.getElementById("phone").value;

  var regName = /^[a-zA-Z]+$/;
  var phoneno = /^\d{10}$/;
  var mail = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;
  submitOK = "true";
  if(fname.match(regName))
		{
			
      submitOK = "true";
		}
    else{
      alert("First Name must contain only letters and white spaces!");
      return false;
    }
    if(lname.match(regName))
		{
			submitOK = "true";
		}
    else{
      alert("Last Name must contain only letters and white spaces!");
      return false;
    }
    if(phone.match(phoneno))
		{
      submitOK = "true";
		}
    else{
      alert("Phone Number must be  of 10 Digits");
      return false;
    }
    if(at.match(mail))
		{
      submitOK = "true";
		}
    else{
      alert("Invalid Mail Format!");
      return false;
    }
    
  if (submitOK == "false") {
    return false;
  }
}
</script>



</body>
</html>
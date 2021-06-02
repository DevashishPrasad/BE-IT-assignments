<?php
    require("PHPMailer-master/src/PHPMailer.php");
    require("PHPMailer-master/src/SMTP.php");
    require("PHPMailer-master/src/Exception.php");
    
 
    //$mail = new  PHPMailer();
	$mail = new   PHPMailer\PHPMailer\PHPMailer();
    $mail->IsSMTP(); 

    $mail->CharSet="UTF-8";
    $mail->Host = "smtp.gmail.com";
    $mail->SMTPDebug = 1; 
    $mail->Port = 465 ; //465 or 587

     $mail->SMTPSecure = 'ssl';  
    $mail->SMTPAuth = true; 
    $mail->IsHTML(true);

    //Authentication
    $mail->Username = "kneomapp@gmail.com";
    $mail->Password = "KNEO_MAPP123";

    //Set Params
    $mail->SetFrom("kneomapp@gmail.com");
    $mail->AddAddress("dikshakrishnaprasad@gmail.com");
	// $mail->AddAddress("krishna.prasad@kneoautomation.com");
    $mail->Subject = "Clinic System";
    $mail->Body = "Hello Diksha , <br> <br> Your Patient ID is : <b>121212</b> <br><br> Password is : <b>ABCDefGh</b>";


     if(!$mail->Send()) {
        echo "Mailer Error: " . $mail->ErrorInfo;
     } else {
        echo "Message has been sent";
     }
?>
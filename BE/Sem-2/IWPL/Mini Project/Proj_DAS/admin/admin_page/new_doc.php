<html>
    <body>
<?php
        include_once '../assets/conn/dbconnect.php';
        // Get the variables.
        // $err="0";
        // function test_input($data) {
        //     $data = trim($data);
        //     $data = stripslashes($data);
        //     $data = htmlspecialchars($data);
        //     return $data;
        // }

  if (isset($_POST['submit'])) 
    {
        $name=$_POST['name'];
        $expert=$_POST['expertise'];
        $cat=$_POST['cat'];
        $qualifi=$_POST['qualification'];
        $service=$_POST['service'];
        $address=$_POST['address'];
        $phone=$_POST['phone'];
        $email=$_POST['email'];
        $fee=$_POST['fee'];
        $user=$_POST['uid'];
        $pass=$_POST['pass'];


        // $area = test_input($_POST['area']);
        // if (!preg_match("/^[a-zA-Z-' ]*$/",$area)) {
        //     $err=1;
        // }
        // $pin = test_input($_POST['pin']);
        // if (strlen($pin)>6) {
        //     $err=1;
        // }
        // echo $appid;
    
    }
        // if($err="0"){
                        $query = " SELECT *  FROM doctor where trim(userid)='$user'";

                        $result = mysqli_query($con, $query);//run the query
                        
                        $cnt = mysqli_num_rows($result);
                        if( $cnt > 0 )
                        {
                            
                            ?>
                            <script type="text/javascript">
                            alert('UserId already exists!');
                            window.location.href = "add_doctor.php";
                            
                            </script>
                            <?php
                        }
                        else
                        {
                    

                        $query = " INSERT INTO doctor (name,service,address,contact,email,expertise,qualify,cat_id,fee,userid,password)
                        VALUES ( '$name', '$service','$address','$phone','$email','$expert','$qualifi','$cat','$fee','$user','$pass') ";
                        $result = mysqli_query($con, $query);//run the query
                    
                        // $add = mysqli_query($con,"INSERT INTO service (`pin`,`area`) VALUES( $pin,$area);");
                        
                        if( $result )
                        {
                            ?>
                            <script type="text/javascript">
                            alert('Doctor Added successfully.');
                            window.location.href = "add_doctor.php";

                            </script>
                            <?php
                        }
                        else
                        {
                            ?>
                            <script type="text/javascript">
                            alert('Add fail. Please try again.');
                            window.location.href = "add_doctor.php";
                            
                            </script>
                            <?php
                        }
                        }    
?>
                
        
</body>
</html>
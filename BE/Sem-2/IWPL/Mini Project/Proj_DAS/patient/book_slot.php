<html>
<body>
<?php
 if(!isset($_SESSION)){
	session_start();
	}	
	
    include_once 'assets/conn/dbconnect.php';
    
    $th= $_GET['th'];
    $tm= $_GET['tm'];
    $day=$_GET['day'];
    $avail=$_GET['avail'];
    $slot=$_GET['slot'];
    $dr_id=$_GET['dr_id'];
    $date=$_GET['date'];
    $ic=$_GET['p_id'];

    // echo $tm;
    $time=$th;
    // $m=$tm/60;
    
    // $timestamp = strtotime($hr.':'.$m) ;
    // $time = ;
    // echo $time;
    $sql= "insert into booking (`dr_id`,`ic_patient`,`date`,`day`,`Time`) Values ('".$dr_id."','".$ic."','".$date."','".$day."','".$time."')";
    $result = mysqli_query($con,$sql);
    if( $result )
    {   
        $sql= "UPDATE ".$slot."	
        SET ".$day."_a = ".$day."_a-1  
        WHERE dr_id=".$dr_id .";";
        $result = mysqli_query($con,$sql);
        if($result){
                    ?>
                    <script type="text/javascript">
                    alert('Appointment made successfully.');
                    window.location = 'search_doctor.php';
                    </script>
                    <?php
        }
    }
    else
    {
        echo mysqli_error($con);
        ?>
        <script type="text/javascript">
        alert('Appointment booking fail. Please try again.');
        window.location = 'search_doctor.php';
        
        </script>
        <?php
    }
    
    ?>
		<script src="assets/js/jquery.js"></script>
			<script src="assets/js/bootstrap.min.js"></script>
		</body>
        </html>    



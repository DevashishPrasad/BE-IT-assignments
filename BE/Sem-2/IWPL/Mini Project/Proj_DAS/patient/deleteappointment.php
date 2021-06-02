<?php
include_once '../assets/conn/dbconnect.php';
// Get the variables.
$booking_id = $_POST['booking_id'];
// echo $appid;

$delete = mysqli_query($con,"DELETE FROM booking WHERE booking_id=".$booking_id);

// $sql =  "SELECT * from booking WHERE booking_id='".$booking_id."' AND dr_id" ;
// $result = mysqli_query($con,$sql);

// $row=mysqli_fetch_array($result);
// $dr_id=$row['dr_id'];
// $dr_id=$row['dr_id'];





// if(isset($delete)) {
//    echo "YES";
// } else {
//    echo "NO";
// }


mysqli_close($con);

?>


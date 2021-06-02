<?php
include_once '../assets/conn/dbconnect.php';
// Get the variables.
$booking_id = $_POST['booking_id'];
// echo $appid;

$delete = mysqli_query($con,"DELETE FROM booking WHERE booking_id=".$booking_id);
// if(isset($delete)) {
//    echo "YES";
// } else {
//    echo "NO";
// }



?>


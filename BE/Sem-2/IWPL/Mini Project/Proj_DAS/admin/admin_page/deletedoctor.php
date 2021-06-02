<?php
include_once '../assets/conn/dbconnect.php';
// Get the variables.
$uid = $_POST['userid'];
// echo $appid;

$delete = mysqli_query($con,"DELETE FROM doctor WHERE userid=$uid");
// if(isset($delete)) {
//    echo "YES";
// } else {
//    echo "NO";
// }



?>


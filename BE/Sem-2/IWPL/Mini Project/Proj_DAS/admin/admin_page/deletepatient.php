<?php
include_once '../assets/conn/dbconnect.php';
// Get the variables.
$uid = $_POST['icPatient'];
// echo $appid;

$delete = mysqli_query($con,"DELETE FROM patient WHERE icPatient=$uid");
// if(isset($delete)) {
//    echo "YES";
// } else {
//    echo "NO";
// }



?>


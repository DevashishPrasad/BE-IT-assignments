<?php
include_once '../assets/conn/dbconnect.php';
// Get the variables.
$area = $_POST['pin'];
// echo $appid;

$delete = mysqli_query($con,"DELETE FROM service WHERE pin=$area");
// if(isset($delete)) {
//    echo "YES";
// } else {
//    echo "NO";
// }



?>


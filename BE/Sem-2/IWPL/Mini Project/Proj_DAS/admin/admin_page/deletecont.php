<?php
include_once '../assets/conn/dbconnect.php';
// Get the variables.
$id = $_POST['contact_id'];
// echo $appid;

$delete = mysqli_query($con,"DELETE FROM contact WHERE contact_id=$id");
// if(isset($delete)) {
//    echo "YES";
// } else {
//    echo "NO";
// }



?>


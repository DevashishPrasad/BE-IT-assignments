<?php if(!isset($_SESSION)){
	session_start();
	}  
?>

<!-- this is for select option -->
		<?php
			  $db = new mysqli('localhost','root','','projectmms');//set your database handler
			  $query = "SELECT id,cat FROM category";
			  $result = $db->query($query);

			  while($row = $result->fetch_assoc()){
			    $categories[] = array("id" => $row['id'], "val" => $row['cat']);
			  }

			  $query = "SELECT id, doctor_id, name FROM doctor";
			  $result = $db->query($query);

			  while($row = $result->fetch_assoc()){
			    $subcats[$row['doctor_id']][] = array("id" => $row['id'], "val" => $row['name']);
			  }

			  $jsonCats = json_encode($categories);
			  $jsonSubCats = json_encode($subcats);


		?>
<!-- this is for select option -->

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>mms-patient</title>
	<link rel="stylesheet" href="css/bootstrap.min.css">
	<link rel="stylesheet" href="../style.css">

	 <!--  this is for select -->
	<script type='text/javascript'>
      <?php
        echo "var categories = $jsonCats; \n";
        echo "var subcats = $jsonSubCats; \n";
      ?>
      function loadCategories(){
        var select = document.getElementById("categoriesSelect");
        select.onchange = updateSubCats;
        for(var i = 0; i < categories.length; i++){
          select.options[i] = new Option(categories[i].val,categories[i].id);       
        }
      }
      function updateSubCats(){
        var catSelect = this;
        var doctor_id = this.value;
        var subcatSelect = document.getElementById("subcatsSelect");
        subcatSelect.options.length = 0; //delete all options if any present
        for(var i = 0; i < subcats[doctor_id].length; i++){
          subcatSelect.options[i] = new Option(subcats[doctor_id][i].val,subcats[doctor_id][i].id);
        }
      }
    </script>

   <!--  this was for select -->
</head>
<body onload='loadCategories()'>

<?php

if($_SESSION['donorstatus']==""){
	header("location:../patient_login.php");
}

?>

<?php include('uptomenu.php'); ?>



	<!-- this is for donor registraton -->
	<div class="recipient_reg" style="background-color:#272327;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;">Booking Appoinment</h3>

		<div class="formstyle" style="float: right;padding:25px;border: 1px solid lightgrey;margin-right:415px; margin-bottom:30px;background-color:#f3f3f8;color:#141313;">
		<form enctype="multipart/form-data" method="post" class="text-center">
			 <div class="col-md-12">
				  
			 		

					<label>
						<input type="email" name="email" placeholder="Your Registered Email" >	
					</label><br><br>
					<label>
						<input type="number" name="contact"  placeholder="registered contact no" required="required" pattern="[0-9]{10,11}" title="please enter only numbers between 10 to 11 for mobile no."/>
					</label><br><br>
 					
 					
					<label>
						 <select id='categoriesSelect' name="cat" placeholder="choose your Category">
      
   								 </select>
					</label><br><br>
					<label>
						<select id='subcatsSelect' name="name">
      
    							</select>
									
					</label><br><br>
					
					<label>
						<input type="date" name="dates" placeholder="choose your date" >	
					</label><br><br>
					<label>
						<select name="tyme">
									<option value="">-select time-</option>
									<option value="9.00am-10.00am">09.00am-10.00am</option>
									<option value="10.00am-11.00am">10.00am-11.00am</option>
									<option value="11.00am-12.00pm">11.00am-12.00pm</option>
									<option value="12.00pm-01.00pm">12.00pm-01.00pm</option>
									<option value="03.00pm-04.00pm">03.00pm-04.00pm</option>
									<option value="04.00pm-05.00pm">04.00pm-05.00pm</option>
									<option value="05.00pm-06.00pm">05.00pm-06.00pm</option>
									<option value="07.00pm-08.00pm">07.00pm-08.00pm</option>
									<option value="08.00pm-09.00pm">08.00pm-09.00pm</option>
      
    						  </select>
									
					</label><br><br>

					<label>
						<select name="payment">
									<option value="">-Payment Method-</option>
									<option value="DBBL Rocket">DBBL Rocket</option>
									<option value="1bKash">bKash</option>
						
    						  </select>
									
					</label><br><br>
					
					
					<button name="submit" type="submit" style="margin-left:12px;width:115px;border-radius: 3px;">Book</button> <br>
				
			</div>	<!-- col-md-12 -->


				</form>
			</div>




	</div>
	
	



	
	
 <?php include('../footer.php'); ?>


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


	 <!-- validation and insertion -->


					<?php
						
							include('../config.php');
							if(isset($_POST['submit'])){

							$sql = "INSERT INTO booking (email,contact,cat,d_name, dates,tyme)
							VALUES ('" . $_POST["email"] . "','" . $_POST["contact"] . "','" . $_POST["cat"] . "', '" . $_POST["name"] . "','" . $_POST["dates"] . "','". $_POST["tyme"] . "' )";

							if ($conn->query($sql) === TRUE) {
							    echo "<script>alert('Your booking has been accepted!');</script>";
							} else {
							    echo "<script>alert('There was an Error')<script>";
							}

							$conn->close();
						}
					?> 



	<!-- validation and insertion End-->



</body>
</html>


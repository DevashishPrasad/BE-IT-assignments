<?php if(!isset($_SESSION)){
	session_start();
	}  
?>

<?php include('header.php'); ?>




	<!-- this is for donor registraton -->
	<div class="recipient_reg" style="background-color:#272327;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;">Add Doctor</h3>

		<div class="formstyle" style="float: right;padding:25px;border: 1px solid lightgrey;margin-right:320px; margin-bottom:30px;background-color: #101011;color:#d4530d;;">
		<form enctype="multipart/form-data" method="post" class="text-center" style="margin-left: 110px">
			 <div class="col-md-12">
				  
			 		<label>
					    <input type="text" name="doctor_id" value="" placeholder="doctor_id" required>
					</label><br><br>
					<label>
					    <input type="text" name="name" value="" placeholder="Full name" required>
					</label><br><br>
					<label>
						 <input type="text" name="address" value="" placeholder="address" required>
					</label><br><br>
					<label>
						 <input type="text" name="contact" value="" placeholder="contact" required>
					</label><br><br>

					<label>
						 <input type="email" name="email"  value="" placeholder="email" required>
					</label><br><br>
					
					<label>
						 <select name="expertise" required>
										<option>-Expert in-</option>
										<option>Medicine</option>
										<option>Heart</option>
										<option>Bone</option>
										<<option>kedney</option>
										<option>Cardiologist</option>
										<option>Plastic Surgeon</option>
										<option>General Physician</option>
										<option>Neurologist</option>
									</select>
					</label><br><br>
					<label>
					     <input type="text" name="id" value="" placeholder="id" required>
					</label><br><br>
					<label>
					   <input type="text" name="fee" value="" placeholder="Fee" required>
					</label><br><br>
					
					
					<button name="submit" type="submit" style="margin-left:148px;margin-top: 4px;width:95px;border-radius: 3px;height: 30px">Add</button> <br>
				
			</div>	<!-- col-md-12 -->


				</form>
			</div>




	</div>
	
	

 <!-- validation and insertion -->


			<?php
						include('../config.php');
						if(isset($_POST['submit'])){
							

							$sql = "INSERT INTO doctor (doctor_id,name,address,contact,email,expertise,id,fee)
							VALUES ('" . $_POST["doctor_id"] ."','" . $_POST["name"] . "','" . $_POST["address"] . "','" . $_POST["contact"] . "','" . $_POST["email"] . "', '" . $_POST["expertise"] . "','" . $_POST["id"] . "','" . $_POST["fee"] . "' )";

							if ($conn->query($sql) === TRUE) {
							    echo "<script>alert('New Doctor Has been Added Successfully!');</script>";
							} else {
							    echo "<script>alert('There was an Error')<script>";
							}

							$conn->close();
						}
					?> 



	<!-- validation and insertion End-->

	
	
 <?php include('footer.php'); ?>


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


	



</body>
</html>
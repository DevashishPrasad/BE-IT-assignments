<?php if(!isset($_SESSION)){
	session_start();
	}  
?>

<?php include('header.php'); ?>
<?php include('uptomenu.php'); ?>



	<!-- this is for donor registraton -->
	<div class="recipient_reg" style="background-color:#272327;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;">Booking Appoinment</h3>

		<div class="formstyle" style="float: right;padding:25px;border: 1px solid lightgrey;margin-right:415px; margin-bottom:30px;background-color: #101011;color:#d4530d;;">
		<form enctype="multipart/form-data" method="post" class="text-center">
			 <div class="col-md-12">
				  
			 		<label>
					   Name: <input type="text" name="name" value="" placeholder="Full name" required>
					</label><br><br>

					<label>
						Email: <input type="email" name="email"  value="" placeholder="email" required>
					</label><br><br>
					
					<label>
						Phone: <input type="number" name="contact"  placeholder="contact no" required="required" pattern="[0-9]{10,11}" title="please enter only numbers between 10 to 11 for mobile no."/>
					</label><br><br>
 					
 					<label>
						Address: <input type="text" name="address" value="" placeholder="address" required>
					</label><br><br>
					<label>
						Category: <select name="expertise" required>
										<option>-Select-</option>
										<option>Medicine</option>
										<option>Heart</option>
										<option>Bone</option>
										<<option>kedney</option>
										<option>Cardiologist</option>
										<option>Plastic Surgeon</option>
										<option>General Physician</option>
									</select>
					</label><br><br>
					<label>
						Doctor: <select name="doctor" required>
										<option>-Select-</option>
										<option>Medicine Doctors</option>
										<option>Heart Doctors</option>
										<option>Bone Doctors</option>
										<<option>kedney Doctors</option>
										<option>Cardiologist Doctors</option>
										<option>Plastic Surgeon Doctors</option>
										<option>General Physician Doctors</option>
									</select>
					</label><br><br>
					
					<label>
						Date: <input type="date" name="date" placeholder="choose ur date" >	
					</label><br><br>
					
					
					<button name="submit" type="submit" style="margin-left:60px;width: 85px;border-radius: 3px;">Check</button> <br>
				
			</div>	<!-- col-md-12 -->


				</form>
			</div>




	</div>
	
	



	
	
 <?php include('footer.php'); ?>


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


	 <!-- validation and insertion -->


			<?php
						
							include('../config.php');
							if(isset($_POST['submit'])){

							$sql = "INSERT INTO patient (name,age,contact,address,bgroup,email, password)
							VALUES ('" . $_POST["name"] ."','" . $_POST["age"] . "','" . $_POST["contact"] . "','" . $_POST["address"] . "','" . $_POST["bgroup"] . "', '" . $_POST["email"] . "','" . $_POST["password"] . "' )";

							if ($conn->query($sql) === TRUE) {
							    echo "<script>location.replace('patient_success_msg.php');</script>";
							} else {
							    echo "<script>alert('There was an Error')<script>" . $sql . "<br>" . $conn->error;
							}

							$conn->close();
						}
					?> 



	<!-- validation and insertion End-->



</body>
</html>
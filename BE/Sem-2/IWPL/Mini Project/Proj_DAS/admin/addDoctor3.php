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
					    <input type="text" name="doctor_id" value="" placeholder="doctor_id" >
					</label><br><br>
					<label>
					    <input type="text" name="name" value="" placeholder="Full name" >
					</label><br><br>
					<label>
						 <input type="text" name="address" value="" placeholder="address" >
					</label><br><br>
					<label>
						 <input type="text" name="contact" value="" placeholder="contact" >
					</label><br><br>

					<label>
						 <input type="email" name="email"  value="" placeholder="email" >
					</label><br><br>
					
					<label>
						 <select name="expertise" >
										<option>-Expert in-</option>
										<option>Medicine</option>
										<option>Heart</option>
										<option>Bone</option>
										<option>kedney</option>
										<option>Cardiologist</option>
										<option>Plastic Surgeon</option>
										<option>General Physician</option>
										<option>Neurologist</option>
									</select>
					</label><br><br>
					<label>
					     <input type="text" name="userid" value="" placeholder="userid" >
					</label><br><br>
					<label>
					   <input type="text" name="fee" value="" placeholder="Fee" >
					</label><br><br>
					<label>
						 <input type="file" name="t8" value="" id="t8" required>
					</label><br><br>
					
					<button name="submit" type="submit" style="margin-left:148px;margin-top: 4px;width:95px;border-radius: 3px;height: 30px">Add Doctor</button> <br>
				
			</div>	<!-- col-md-12 -->


				</form>
			</div>




	</div>
	
	

 <!-- validation and insertion -->


			<?php
				if(isset($_POST["submit"])) 
				{
				$target_dir = "doner_pic/";
				$target_file = $target_dir . basename($_FILES["t8"]["name"]);
				$uploadOk = 1;
				$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
				// Check if image file is a actual image or fake image

				    $check = getimagesize($_FILES["t8"]["tmp_name"]);
				    if($check !== false) {
				      //  echo "File is an image - " . $check["mime"] . ".";
				        $uploadOk = 1;
				    } else {
				        echo "File is not an image.";
				        $uploadOk = 0;
				    }

				// Check if file already exists
				if (file_exists($target_file)) {
				    echo "Sorry, file already exists.";
				    $uploadOk = 0;
				}
				//aloow certain file formats
					if($imageFileType != "jpg" && $imageFileType !="png" && $imageFileType !="jpeg" && $imageFileType !="gif"){
						echo "sorry, only jpg, jpeg, Png & gif files are allowed.";
						$uploadok=0;
					}else{
						if(move_uploaded_file($_FILES["t8"]["tmp_name"], $target_file)){
					// if (move_uploaded_file ($_FILES['t8']['tmp_name'], "/doner_pic/{$_FILES['t8']['name']}")) {
						include('../config.php');
							$s="INSERT INTO doctor(name,address,contact,email,expertise,userid,fee,pic) VALUES('" . $_POST["name"] . "','" . $_POST["address"] . "','" . $_POST["contact"] . "','" . $_POST["email"] . "', '" . $_POST["expertise"] . "','" . $_POST["userid"] . "','" . $_POST["fee"] . "','" . basename($_FILES["t8"]["name"])  ."')";
							
							mysqli_query($conn,$s);
							mysqli_close($conn);
							if($s>0){
								echo "<script>alert('Record Saved');</script>";
							}else{
								echo "<script>alert('Record did not save');</script>";
							}
						} else{
							echo "sorry there was an error uploading your file.";
						}	
					
					}
				}
				?> 



	<!-- validation and insertion End-->

	



	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


	



</body>
</html>
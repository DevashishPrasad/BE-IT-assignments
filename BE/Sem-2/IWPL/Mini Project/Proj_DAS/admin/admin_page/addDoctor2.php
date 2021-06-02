<?php if(!isset($_SESSION)){
	session_start();
	}  
?>

<?php include('header.php'); ?>




	<!-- this is for donor registraton -->
	<div class="recipient_reg" style="background-color:#272327;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;">Add Doctor</h3>

		<div class="formstyle" style="float: right;padding:25px;border: 1px solid lightgrey;margin-right:320px; margin-bottom:30px;background-color: #101011;color:#d4530d;;">
		<form enctype="multipart/form-data" action=""  method="post" class="text-center" style="margin-left: 110px">
			 <div class="col-md-12">
				  	
			 		
					<label>
					    <input type="text" name="name" value="" placeholder="Full name" autocomplete="on">
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
										</select>
					</label><br><br>
					<label>
					     <input type="text" name="userid" value="" placeholder="userid" >
					</label><br><br>
					<label>
					   <input type="text" name="fee" value="" placeholder="Fee" >
					</label><br><br>
					<label>
					   <input type="password" name="password" value="" placeholder="password" >
					</label><br><br>
					<label>
						 <input type="file" name="pic" value="" id="pic" required>
					</label><br><br>
					
					<button name="submit" type="submit" style="margin-left:148px;margin-top: 4px;width:95px;border-radius: 3px;height: 30px">Add Doctor</button> <br>
				
			</div>	<!-- col-md-12 -->


				</form>
			</div>




	</div>
	
	

					<!-- inserting data -->
					<?php  
						 if(isset($_POST['submit'])){
							$target_dir = "../photo/";
							$target_file = $target_dir . basename($_FILES["pic"]["name"]);
							$uploadOk = 1;
							$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
							// Check if image file is a actual image or fake image

						    $check = getimagesize($_FILES["pic"]["tmp_name"]);
						    if($check !== false) {
						        // echo "File is an image - " . $check["mime"] . ".";
						        $uploadOk = 1;
						    } else {
						        echo "File is not an image.";
						        $uploadOk = 0;
						    }

							// Check if file already exists
							if (file_exists($target_file)) {
							    echo "<script>alert('Sorry, file already exists.');</script>";
							    $uploadOk = 0;
							}
							//aloow certain file formats
							if($imageFileType != "jpg" && $imageFileType !="png" && $imageFileType !="jpeg" && $imageFileType !="gif"){
								echo "sorry, only jpg, jpeg, Png & gif files are allowed.";
								$uploadok=0;
							}	
						else{
							if(move_uploaded_file($_FILES["pic"]["tmp_name"], $target_file)) {
									include('../config.php');
									$sql1 = "SELECT * FROM doctor WHERE userid='".$_POST["userid"]."' OR email= '" . $_POST["email"] . "' ";
	              					$result = $conn->query($sql1);
	              					if($result->num_rows > 0){
	              						 echo "<script>alert('Sorry, Userid or E-mail already exist!');</script>";
	              					}
	              					else{
									$sql = "INSERT INTO doctor (name,address,contact,email,expertise,userid,fee,password,pic)
										VALUES ('" . $_POST["name"] . "','" . $_POST["address"] . "','" . $_POST["contact"] . "','" . $_POST["email"] . "', '" . $_POST["expertise"] . "','" . $_POST["userid"] . "','" . $_POST["fee"] . "','" . $_POST["password"] . "','" . basename($_FILES["pic"]["name"]) ."' )";

										if ($conn->query($sql) === TRUE) {
										    echo "<script>alert('New Doctor Has been Added Successfully!');</script>";
										} else {
										    echo "<script>alert('There was an Error')<script>";
										}
									}

									$conn->close();
							} else {
								echo "<script>alert('sorry there was an error!');</script>";
							}
							
							
						}
				}
				?>
					<!-- inserting data -->

	



	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


	



</body>
</html>
<?php if(!isset($_SESSION)){
	session_start();
	}  
?>
<?php include('header.php'); ?>
<?php include('uptomenu.php'); ?>

	<div class="search form-group"  style="background-color: #7faf81;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;padding: 5px;">Search result</h3>
		
	</div>
<!-- result -->

					<!-- for retriving data -->
				<?php 
							include('../config.php');
							$sql="SELECT * FROM doctor where address='" . $_POST["address"] . "' AND expertise='" . $_POST["expertise"] . "'";
			
							$q=mysqli_query($conn,$sql);
							$row=mysqli_num_rows($q);
							
							$data=mysqli_fetch_array($q);
							$name=$data[2];
							$address=$data[3];
							$contact=$data[4];
							$email=$data[5];
							$userid=$data[9];
							$expertise=$data[6];
							$fee=$data[8];
							$pic = $data[11];

							mysqli_close($conn);
				?>
<!-- for retriving data -->
<?php 
	if ($row>=1) { ?>
		
	
<div class="login" style="background-color:#fff;">
		
			<div class="formstyle" style="float: right;padding:20px;border: 1px solid lightgrey;margin-right:415px; margin-bottom:30px;background-color:#f3f3f8;color:#141313;">
				<form action="" method="post" class="text-center form-group">
					<img src="../photo/<?php echo @$pic; ?>" style="padding-left:40px;width:165px;height:115px;float: left;margin-bottom:10px;margin-left:35px;"/>
					<label>
						 <input type="hidden" name="pic" value="<?php {echo @$pic;} ?>">
					</label><br><br>

					<label>
						Dr. Name: <input type="text" name="name" value="<?php echo $name; ?>" required>
					</label><br><br>

 					<label>
						Address: <input type="text" name="address" value="<?php echo $address; ?>"  required>
					</label><br><br>

					
					<label>
						Contact: <input type="text" name="contact" value="<?php echo $contact; ?>"  required="required" />
					</label><br><br>
 					<label>
						Email: <input type="email" name="email" value="<?php echo $email; ?>" " required>
					</label><br><br>
					
					<label>
						Expert in: <input type="email" name="email" value="<?php echo $expertise; ?>"  disabled>
					</label><br><br>

					<label>
						Fee: <input type="text" name="fee" value="<?php echo $fee; ?>"  disabled>
					</label><br><br>
					<label>

					
			</form> <br><br>

	</div>
	
	
</div>
				<?php 
						while($row=mysqli_fetch_array($q)){
								echo "<tr>";
								echo "<td>".$row['name']."</td>";
								echo "<td>".$row['address']."</td>";
								
								echo "<td>".$row['contact']."</td>";
								echo "<td>".$row['email']."</td>";

								echo "<td>".$row['expertise']."</td>";
								echo "<td>".$row['fee']."</td>";
								
								
								
								echo "</tr>";
						}

				}else{
					echo "NO match Found!";
				}

?>
	<button style="margin-left: 605px;background-color:#332f30;color: antiquewhite;width: 115px;height: 30px;margin-bottom: 5px;">
	<a href="search_doctor.php">Search Again</a></button>
	
 <?php include('footer.php'); ?>


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


 


	
</body>
</html>

<?php if(!isset($_SESSION)){
	session_start();
	}  
?>

<?php include('header.php'); ?>


<!-- this is for donor registraton -->
	<div class="dashboard" style="background-color:#fff;">
		<h3 class="text-center" style="background-color:#272327;color: #fff;padding: 5px;">Who have donated Blood</h3>
		
		
	
		
			<div class="all_user" style="margin-top:0px; margin-left: 40px;">
				<?php 
					include('../config.php');

					$sql = " SELECT * FROM donation";
					$result = mysqli_query($conn,$sql);
					$count = mysqli_num_rows($result);

					if($count>=1){
						echo "<table border='1' align='center' cellpadding='32'>
							<tr>
								<th>Donor ID</th>
								<th>Email</th>
								<th>Whom Donated</th>
								
								<th>Address</th>
								<th>Unit</th>
								<th>Date</th>
								<th>Action</th>
							</tr>";
						while($row=mysqli_fetch_array($result)){
								echo "<tr>";
								echo "<td>".$row['donation_id']."</td>";
								echo "<td>".$row['email']."</td>";
								echo "<td>".$row['name']."</td>";
								
								echo "<td>".$row['address']."</td>";
								echo "<td>".$row['unit']."</td>";
								echo "<td>".$row['dates']."</td>";
								echo "<td><button type='submit' name='submit' style='color:#000;'>Delete</button></td>";
								echo "</tr>";
						}
						echo "</table>";
					}
					else{
						print "<p align='center'>Sorry, No match found for your search result..!!!</p>";
					}

					?>
			</div>
		
	</div>
	
	

	
 <?php include('footer.php'); ?>


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


 
			



	
</body>
</html>

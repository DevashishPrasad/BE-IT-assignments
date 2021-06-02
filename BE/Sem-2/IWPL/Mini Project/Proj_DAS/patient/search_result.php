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

					<?php 
					include('../config.php');
					

					$sql = " SELECT * FROM doctor WHERE address = '" . $_POST["address"]."' AND expertise = '" . $_POST["expertise"]."' ";
					$result = mysqli_query($conn,$sql);
					$count = mysqli_num_rows($result);

					if($count>=1){
						echo "<table border='1' align='center' cellpadding='32'>
							<tr>
								<th>SL.</th>
								<th>Name</th>
								<th>Address</th>
								
								<th>Mobile</th>
								
								<th>Email</th>
								<th>Expertise in</th>
								<th>Fee</th>
								<th>Book</th>
								
							</tr>";
						while($row=mysqli_fetch_array($result)){
								echo "<tr>";
								echo "<td>".$row['doc_id']."</td>";
								echo "<td>".$row['name']."</td>";
								echo "<td>".$row['address']."</td>";
								
								echo "<td>".$row['contact']."</td>";
								echo "<td>".$row['email']."</td>";

								echo "<td>".$row['expertise']."</td>";
								echo "<td>".$row['fee']."</td>";
						?>
							<td><a href="booking.php?doc_id=<?php echo $row['doc_id'] ?>">Book</a></td>;
						<?php 		
								
								echo "</tr>";
						}
						echo "</table>";
					} 
					else{
						print "<p align='center'>Sorry, No match found for your search result..!!!</p>";
					}

					?>
					<!-- result -->


	<button style="margin-left: 605px;background-color:#332f30;color: antiquewhite;width: 115px;height: 30px;margin-bottom: 5px;">
	<a href="search_doctor.php">Search Again</a></button>
	
 <?php include('footer.php'); ?>


	
	</div><!--  containerFluid Ends -->




	<script src="js/bootstrap.min.js"></script>


 


	
</body>
</html>

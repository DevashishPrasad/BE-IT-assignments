				<!-- confirming booking -->
					<?php

						include('../config.php');
						if(isset($_POST['submit'])){
							

						$sql = " INSERT INTO booking (dname,dcontact,expertise,fee, pname,pcontact,address,dates,tyme,payment)
							VALUES ('" . $_POST["dname"] . "','" . $_POST["dcontact"] . "','" . $_POST["expertise"] . "', '" . $_POST["fee"] . "','" . $_POST["pname"] . "','". $_POST["pcontact"] . "','". $_POST["address"] . "','". $_POST["dates"] . "','". $_POST["tyme"] . "','". $_POST["payment"] . "' )";

							if ($conn->query($sql) === TRUE) {
							    echo "<script>alert('Your booking has been accepted!');</script>";
							} else {
							    echo "<script>alert('There was an Error')<script>";
							}

							$conn->close();
						}
					?> 

				<!-- confirming booking -->
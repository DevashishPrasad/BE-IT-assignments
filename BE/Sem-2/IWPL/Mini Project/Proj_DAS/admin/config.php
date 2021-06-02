						<?php	
							$servername = "localhost";
							$username = "Deva";
							$password = "dev123456";
							$dbname = "db_healthcare";

							// Create connection
							$conn = new mysqli($servername, $username, $password, $dbname);
							// Check connection
							if ($conn->connect_error) {
							    die("Connection failed: " . $conn->connect_error);
							}
						?>	

<?php
					
					// if(isset($_POST['submit'])){
							$target_dir = "/photo";
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
							    echo "Sorry, file already exists.";
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
								$sql = "INSERT INTO doctor (name,address,contact,email,expertise,userid,fee,password,pic)
									VALUES ('" . $_POST["name"] . "','" . $_POST["address"] . "','" . $_POST["contact"] . "','" . $_POST["email"] . "', '" . $_POST["expertise"] . "','" . $_POST["userid"] . "','" . $_POST["fee"] . "','" . $_POST["password"] . "','" . basename($_FILES["pic"]["name"]) ."' )";

									if ($conn->query($sql) === TRUE) {
									    echo "<script>alert('New Doctor Has been Added Successfully!');</script>";
									} else {
									    echo "<script>alert('There was an Error')<script>";
									}

									$conn->close();
							} else {
								echo "<script>alert('sorry there was an error uploading your file.');</script>";
							}
							
							
						}
				// }
			?> 
		<!-- validation and insertion End-->
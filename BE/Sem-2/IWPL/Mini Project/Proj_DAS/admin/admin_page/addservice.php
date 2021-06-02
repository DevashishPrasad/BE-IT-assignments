<html>
    <body>
<?php
        include_once '../assets/conn/dbconnect.php';
        // Get the variables.
        $err="0";
        function test_input($data) {
            $data = trim($data);
            $data = stripslashes($data);
            $data = htmlspecialchars($data);
            return $data;
        }

  if (isset($_POST['submit'])) 
    {
        $area = test_input($_POST['area']);
        if (!preg_match("/^[a-zA-Z-' ]*$/",$area)) {
            $err=1;
        }
        $pin = test_input($_POST['pin']);
        if (strlen($pin)>6) {
            $err=1;
        }
    
    }

        if($err=="0"){
                        $query = " SELECT *  FROM service where trim(area)='$area' and pin=$pin";

                        $result = mysqli_query($con, $query);//run the query
                        
                        $cnt = mysqli_num_rows($result);
                        if( $cnt > 0 )
                        {
                            
                            ?>
                            <script type="text/javascript">
                            alert('Area already exists!');
                            window.location.href = "service_areas.php";
                            
                            </script>
                            <?php
                        }
                        else
                        {
                            
                        
                        $query = " INSERT INTO service (pin ,area)VALUES ( '$pin', '$area') ";
                        $result = mysqli_query($con, $query);//run the query
                    
                        
                        if( $result )
                        {
                            ?>
                            <script type="text/javascript">
                            alert('Service Area Added successfully.');
                           window.location.href = "service_areas.php";

                            </script>
                            <?php
                        }
                        else
                        {
                            ?>
                            <script type="text/javascript">
                            alert('Add fail. Please try again.');
                            window.location.href = "service_areas.php";
                            
                            </script>
                            <?php
                        }
                    } 

                }
        else
        {
        ?>
        <script type="text/javascript">
        alert('Input the correct values ');
        window.location.href = "service_areas.php";
        
        </script>
        <?php
        }  
        ?>
</body>
</html>
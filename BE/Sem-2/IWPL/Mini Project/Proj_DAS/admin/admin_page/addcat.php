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
        $cat = test_input($_POST['category']);
        if (!preg_match("/^[a-zA-Z-' ]*$/",$cat)) {
            $err=1;
        }
        // if (strlen($pin)>6) {
        //     $err=1;
        // }
    
    }

        if($err=="0"){  
                        $query = " SELECT *  FROM category where trim(cat)='$cat'";

                        $result = mysqli_query($con, $query);//run the query
                        
                        $cnt = mysqli_num_rows($result);
                        if( $cnt > 0 )
                        {
                            
                            ?>
                            <script type="text/javascript">
                            alert('Category already exists!');
                            window.location.href = "view_category.php";
                            
                            </script>
                            <?php
                        }
                        else
                        {
                            
                        
                                $query = " INSERT INTO category (cat) VALUES (' $cat') ";
                                $result = mysqli_query($con, $query);//run the query
                            
                                
                                if( $result )
                                {
                                    ?>
                                    <script type="text/javascript">
                                    alert('Category Added successfully.');
                                    window.location.href = "view_category.php";

                                    </script>
                                    <?php
                                }
                                else
                                {
                                    ?>
                                    <script type="text/javascript">
                                    alert('Add fail. Please try again.');
                                    window.location.href = "view_category.php";
                                    
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
        // window.location.href = "service_areas.php";
        
        </script>
        <?php
        }  
        ?>
</body>
</html>
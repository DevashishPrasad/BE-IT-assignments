<!doctype html>
<html>
<head>
<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
<link href="https://cdnjs.cloudflare.com/ajax/libs/bootswatch/3.4.0/paper/bootstrap.min.css" rel="stylesheet">
<script src="https://code.jquery.com/jquery-1.12.4.min.js"></script>
<link href="https://www.jqueryscript.net/css/jquerysctipttop.css" rel="stylesheet" type="text/css">
<link href="filter.css" rel="stylesheet">
<script src="filter.js"></script>
<title>jQuery Filter.js Table Column Filters Example</title>
<style>
    body { background-color: #f7f7f7; }
    .container {margin:150px auto;}
    </style>
</head>
<body>
</script>
<script type="text/javascript"
src="https://pagead2.googlesyndication.com/pagead/show_ads.js">
</script></div>
<div class="jquery-script-clear"></div>
</div>
</div>
<div class="container">
    <hr>
    <div class="row">
        <div class="panel panel-primary filterable">
            <div class="panel-heading">
                <h3 class="panel-title">
			<button class="btn btn-default btn-xs btn-filter"><span class="glyphicon glyphicon-filter"></span>Click To Apply Filter</button>
		</h3>

<!-- 
    <th style="padding:5px;"> IC Patient</th>
                            <th style="padding:5px;">Name</th>
                            <th style="padding:5px;">Age</th>
                            <th style="padding:5px;">Gender</th>
                            <th style="padding:5px;">Blood Group </th>
                            <th style="padding:5px;">Phone</th>
                            <th style="padding:5px;">Email</th>
                            <th style="padding:5px;">Action</th> -->


            </div>
            <?php 
                include_once 'assets/conn/dbconnect.php';

                $sql = " SELECT * FROM patient";
                $result = mysqli_query($con,$sql);
                $count = mysqli_num_rows($result);

                if($count>=1){?>

            <table class="table table-bordered table-striped">
                <thead>
                    <tr class="filters">
                        <th><input type="text" class="form-control" placeholder="IC Patient" disabled></th>
                        <th><input type="text" class="form-control" placeholder="Name" disabled></th>
                        <th><input type="text" class="form-control" placeholder="Age" disabled></th>
                        <th><input type="text" class="form-control" placeholder="Gender" disabled></th>
                        <th><input type="text" class="form-control" placeholder="Blood Group" disabled></th>
                        <th><input type="text" class="form-control" placeholder="Phone" disabled></th>
                        <th><input type="text" class="form-control" placeholder="Email" disabled></th>
                        <th><input type="text" class="form-control" placeholder="Action" disabled></th>

                    </tr>
                </thead>
                <tbody>
                <?php
                    while($row=mysqli_fetch_array($result)){
                            echo "<tr>";
                            // echo "<td>".$row['doctor_id']."</td>";
                            echo "<td>".$row['icPatient']."</td>";
                            echo "<td>".$row['patientFirstName'].$row['patientLastName']."</td>";
                            echo "<td>".$row['age']."</td>";
                            echo "<td>".$row['patientGender']."</td>";
                            echo "<td>".$row['bgroup']."</td>";
                            echo "<td>".$row['patientPhone']."</td>";
                            echo "<td>".$row['patientEmail']."</td>";
                            echo "<td><button type='submit' name='submit' style='color:#000;'>Update</button><button type='submit' name='submit' style='color:#000;'>Delete</button></td>";
                            
                            echo "</tr>";
                    }
                    echo "</table>";
                }
                else{
                    print "<p align='center'>Sorry, No match found for your search result..!!!</p>";
                }

                ?>
                    <!-- <tr>
                        <td>1</td>
                        <td>Prakhar</td>
                        <td>Srivastava</td>
                        <td>@Prakhar</td>
                    </tr>
                    <tr>
                        <td>2</td>
                        <td>Rahul</td>
                        <td>Singh</td>
                        <td>@Rahul</td>
                    </tr>
                    <tr>
                        <td>3</td>
                        <td>Ankit</td>
                        <td>Mishra</td>
                        <td>@Ankit</td>
                    </tr> -->
                </tbody>
            </table>
            <p>No.of Rows : <span id="rowcount"></span></p>
        </div>
    </div>
</div>
<script>
try {
  fetch(new Request("https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js", { method: 'HEAD', mode: 'no-cors' })).then(function(response) {
    return true;
  }).catch(function(e) {
    var carbonScript = document.createElement("script");
    carbonScript.src = "//cdn.carbonads.com/carbon.js?serve=CK7DKKQU&placement=wwwjqueryscriptnet";
    carbonScript.id = "_carbonads_js";
    document.getElementById("carbon-block").appendChild(carbonScript);
  });
} catch (error) {
  console.log(error);
}
</script>
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-36251023-1']);
  _gaq.push(['_setDomainName', 'jqueryscript.net']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
</body>
</html>

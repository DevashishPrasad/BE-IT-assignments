<?php
include_once 'assets/conn/dbconnect.php';
// include_once 'assets/conn/server.php';
?>


<!-- login -->
<!-- check session -->
<?php
session_start();
// session_destroy();
if (isset($_SESSION['patientSession']) != "") {
header("Location: patient/patient.php");
}
if (isset($_POST['login']))
{
$icPatient = mysqli_real_escape_string($con,$_POST['icPatient']);
$password  = mysqli_real_escape_string($con,$_POST['password']);

$res = mysqli_query($con,"SELECT * FROM patient WHERE icPatient = '$icPatient'");
$row=mysqli_fetch_array($res,MYSQLI_ASSOC);
if ($row['password'] == $password)
{
$_SESSION['patientSession'] = $row['icPatient'];
?>
<script type="text/javascript">
alert('Login Success');
</script>
<?php
header("Location: patient/patient.php");
} else {
?>
<script>
alert('wrong Username or password');
</script>
<?php
}
}
?>
<!-- register -->


<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->
        <title>Clinic Appointment Application</title>
        <!-- Bootstrap -->
        <!-- <link href="assets/css/bootstrap.min.css" rel="stylesheet"> -->
        <link href="assets/css/style.css" rel="stylesheet">
        <link href="assets/css/style1.css" rel="stylesheet">
        <link href="assets/css/blocks.css" rel="stylesheet">
        <link href="assets/css/date/bootstrap-datepicker.css" rel="stylesheet">
        <link href="assets/css/date/bootstrap-datepicker3.css" rel="stylesheet">
        <!-- Special version of Bootstrap that only affects content wrapped in .bootstrap-iso -->
        <!-- <link rel="stylesheet" href="https://formden.com/static/cdn/bootstrap-iso.css" />  -->

        <!--Font Awesome (added because you use icons in your prepend/append)-->
        <link rel="stylesheet" href="https://formden.com/static/cdn/font-awesome/4.4.0/css/font-awesome.min.css" />
        <link href="assets/css/material.css" rel="stylesheet">
        <style>
        .link_col{
            color:#666666;
        }
        .adm{
            color:blue;
            
        }

.our-team { 
  padding: 30px 0 40px;
  margin-bottom: 30px;
  background-color: #f7f5ec;
  text-align: center;
  overflow: hidden;
  position: relative;
}

.our-team .picture {
  display: inline-block;
  height: 130px;
  width: 130px;
  margin-bottom: 50px;
  z-index: 1;
  position: relative;
}

.our-team .picture::before {
  content: "";
  width: 100%;
  height: 0;
  border-radius: 50%;
  background-color: rgba(182, 9, 3, 0.918);
  position: absolute;
  bottom: 135%;
  right: 0;
  left: 0;
  opacity: 0.9;
  transform: scale(3);
  transition: all 0.3s linear 0s;
}

.our-team:hover .picture::before {
  height: 100%;
}

.our-team .picture::after {
  content: "";
  width: 100%;
  height: 100%;
  border-radius: 50%;
  background-color: rgba(182, 9, 3, 0.918);
  position: absolute;
  top: 0;
  left: 0;
  z-index: -1;
}

.our-team .picture img {
  width: 100%;
  height: auto;
  border-radius: 50%;
  transform: scale(1);
  transition: all 0.9s ease 0s;
}

.our-team:hover .picture img {
  box-shadow: 0 0 0 14px rgba(182, 9, 3, 0.918);
  transform: scale(0.7);
}

.our-team .title {
  display: block;
  font-size: 15px;
  color: #4e5052;
  text-transform: capitalize;
}

.our-team .social {
  width: 100%;
  padding: 0;
  margin: 0;
  background-color: rgba(182, 9, 3, 0.918);
  position: absolute;
  bottom: -100px;
  left: 0;
  transition: all 0.5s ease 0s;
}

.our-team:hover .social {
  bottom: 0;
}

.our-team .social li {
  display: inline-block;
}

.our-team .social li a {
  display: block;
  padding: 10px;
  font-size: 17px;
  color: white;
  transition: all 0.3s ease 0s;
  text-decoration: none;
}

.our-team .social li a:hover {
  color: #1369ce;
  background-color: #f7f5ec;
}

        </style>
    </head>
    <body>
        <!-- navigation -->
        <nav class="navbar navbar-default navbar-fixed-top" role="navigation">
            <div class="container-fluid">
                <!-- Brand and toggle get grouped for better mobile display -->
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
                    <span class="sr-only">Toggle navigation</span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    </button>
                    <a class="navbar-brand" href="index.php"><img style="padding-left:15px;padding-bottom:5px;" alt="Brand" src="assets/img/logo.png" height="75px" width="215px"></a>
                </div>
                <!-- Collect the nav links, forms, and other content for toggling -->
                <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                    
                    
                    <ul style="margin-top:20px" class="nav navbar-nav navbar-right">
                        
                    <li>

                       <li> <p style="margin-top:16px;padding-right:30px;font-size:21px;" ><a class="link_col" href="contact_us/contact-view.php">Contact US</a></p></li>

                        <!-- <li><a href="adminlogin.php" data-toggle="modal" data-target="#myModal">Admin</a></li>
                        </li>
                        <li><a href="adminlogin.php">Admin</a></li> -->
                        <li>
                    <p style="margin-top:16px;padding-right:10px;font-size:21px;" ><a class="link_col" href="adminlogin.php">Doctor</a></p>

                        </li>
                        <li style="font-size:20px;" ><a href="#" data-toggle="modal" data-target="#myModal">Sign Up</a></li>

                        <!-- <li>
                            <p class="navbar-text">Already have an account?</p>
                        </li> -->
                        <li style="font-size:20px;" class="dropdown">
                            <a href="#" class="dropdown-toggle" data-toggle="dropdown"><b>Login</b> <span class="caret"></span></a>
                            <ul id="login-dp" class="dropdown-menu">
                                <li>
                                    <div class="row">
                                        <div class="col-md-12">
                                            
                                            <form class="form" role="form" method="POST" accept-charset="UTF-8" >
                                                <div class="form-group">
                                                    <label class="sr-only" for="icPatient">Email</label>
                                                    <input type="text" class="form-control" name="icPatient" placeholder="IC Number" required>
                                                </div>
                                                <div class="form-group">
                                                    <label class="sr-only" for="password">Password</label>
                                                    <input type="password" class="form-control" name="password" placeholder="Password" required>
                                                </div>
                                                <div class="form-group">
                                                    <button type="submit" name="login" id="login" class="btn btn-primary btn-block">Sign in</button>
                                                </div>
                                            </form>
                                        </div>
                                    </div>
                                </li>
                            </ul>
                        </li>
                        
                    </ul>

                </div>
            </div>
        </nav>
        <!-- navigation -->

        <!-- modal container start -->
        <div class="modal fade" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <!-- modal content -->
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                        <h3 class="modal-title">Sign Up</h3>
                    </div>
                    <!-- modal body start -->
                    <div class="modal-body">
                        
                        <!-- form start -->
                        <div class="container" id="wrap">
                            <div class="row">
                                <div class="col-md-6">
                                    
                                    <form id="frm_display" action="valid.php" method="POST" target="_self" accept-charset="utf-8" class="form" role="form">
                                        <h4>It's free and always will be.</h4>
                                        <div class="row">
                                            <div class="col-xs-6 col-md-6">
                                                <input type="text" name="patientFirstName" value="" class="form-control input-lg" placeholder="First Name" required/>
                                            </div>
                                            <div class="col-xs-6 col-md-6">
                                                <input type="text" name="patientLastName" value="" class="form-control input-lg" placeholder="Last Name" required />
                                            </div>
                                        </div>
                                        
                                        <input type="text" name="patientEmail" value="" class="form-control input-lg" placeholder="Your Email"  required />
                                        <!-- <input type="number" name="icPatient" value="" class="form-control input-lg" placeholder="Your IC Number" required /> -->
                                        
                                        
                                        <input type="password" name="password" value="" class="form-control input-lg" placeholder="Password (Only Numbers < 6)"  required />
                                        
                                        <input type="password" name="confirm_password" value="" class="form-control input-lg" placeholder="Confirm Password"  required/>
                                        <label>Birth Date</label>
                                        <div class="row">
                                            
                                            <div class="col-xs-4 col-md-4">
                                                <select name="month" class = "form-control input-lg" required>
                                                    <option value="">Month</option>
                                                    <option value="01">Jan</option>
                                                    <option value="02">Feb</option>
                                                    <option value="03">Mar</option>
                                                    <option value="04">Apr</option>
                                                    <option value="05">May</option>
                                                    <option value="06">Jun</option>
                                                    <option value="07">Jul</option>
                                                    <option value="08">Aug</option>
                                                    <option value="09">Sep</option>
                                                    <option value="10">Oct</option>
                                                    <option value="11">Nov</option>
                                                    <option value="12">Dec</option>
                                                </select>
                                            </div>
                                            <div class="col-xs-4 col-md-4">
                                                <select name="day" class = "form-control input-lg" required>
                                                    <option value="">Day</option>
                                                    <option value="01">1</option>
                                                    <option value="02">2</option>
                                                    <option value="03">3</option>
                                                    <option value="04">4</option>
                                                    <option value="05">5</option>
                                                    <option value="06">6</option>
                                                    <option value="07">7</option>
                                                    <option value="08">8</option>
                                                    <option value="09">9</option>
                                                    <option value="10">10</option>
                                                    <option value="11">11</option>
                                                    <option value="12">12</option>
                                                    <option value="13">13</option>
                                                    <option value="14">14</option>
                                                    <option value="15">15</option>
                                                    <option value="16">16</option>
                                                    <option value="17">17</option>
                                                    <option value="18">18</option>
                                                    <option value="19">19</option>
                                                    <option value="20">20</option>
                                                    <option value="21">21</option>
                                                    <option value="22">22</option>
                                                    <option value="23">23</option>
                                                    <option value="24">24</option>
                                                    <option value="25">25</option>
                                                    <option value="26">26</option>
                                                    <option value="27">27</option>
                                                    <option value="28">28</option>
                                                    <option value="29">29</option>
                                                    <option value="30">30</option>
                                                    <option value="31">31</option>
                                                </select>
                                            </div>
                                            <div class="col-xs-4 col-md-4">
                                                <select name="year" class = "form-control input-lg" required>
                                                    <option value="">Year</option>
                                                    
                                                    <option value="1981">1981</option>
                                                    <option value="1982">1982</option>
                                                    <option value="1983">1983</option>
                                                    <option value="1984">1984</option>
                                                    <option value="1985">1985</option>
                                                    <option value="1986">1986</option>
                                                    <option value="1987">1987</option>
                                                    <option value="1988">1988</option>
                                                    <option value="1989">1989</option>
                                                    <option value="1990">1990</option>
                                                    <option value="1991">1991</option>
                                                    <option value="1992">1992</option>
                                                    <option value="1993">1993</option>
                                                    <option value="1994">1994</option>
                                                    <option value="1995">1995</option>
                                                    <option value="1996">1996</option>
                                                    <option value="1997">1997</option>
                                                    <option value="1998">1998</option>
                                                    <option value="1999">1999</option>
                                                    <option value="2000">2000</option>
                                                    <option value="2001">2001</option>
                                                    <option value="2002">2002</option>
                                                    <option value="2003">2003</option>
                                                    <option value="2004">2004</option>
                                                    <option value="2005">2005</option>
                                                    <option value="2006">2006</option>
                                                    <option value="2007">2007</option>
                                                    <option value="2008">2008</option>
                                                    <option value="2009">2009</option>
                                                    <option value="2010">2010</option>
                                                    <option value="2011">2011</option>
                                                    <option value="2012">2012</option>
                                                    <option value="2013">2013</option>
                                                </select>
                                            </div>
                                        </div>
                                        <label>Gender : </label>
                                        <label class="radio-inline">
                                            <input type="radio" name="patientGender" value="male" required/>Male
                                        </label>
                                        <label class="radio-inline" >
                                            <input type="radio" name="patientGender" value="female" required/>Female
                                        </label>
                                        <br />
                                        <span class="help-block">By clicking Create my account, you agree to our Terms and that you have read our Data Use Policy, including our Cookie Use.</span>
                                        
                                        <button class="btn btn-lg btn-primary btn-block signup-btn" type="submit" name="signup" id="signup">Create my account</button>
                                    </form>
                                    
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <!-- modal end -->
        <!-- modal container end -->

        <!-- 1st section start -->
        <section id="promo-1" class="content-block promo-1 min-height-600px bg-offwhite">
            <div class="container">
                <div class="row">
                    <div class="col-md-5">
                        <h2 style="text-shadow: 0 0 3px white, 0 0 5px white;color:  #c41b1b;background-color: rgba(74, 77, 77, 0.5);font-family:Impact, fantasy;padding:15px;" >Make appointment today!</h2>
                        <marquee style="font-size:25px;color:black;background-color: rgba(74, 77, 77, 0.5);font-family:Avantgarde, TeX Gyre Adventor, URW Gothic L, sans-serif;padding:15px;"><b>LOGIN to make an appointment !!!</b> </marquee>
                            
                        <!-- date textbox -->
                       
                        <!-- <div class="input-group" style="margin-bottom:10px;">
                            <div class="input-group-addon">
                                <i class="fa fa-calendar">
                                </i>
                            </div>
                            <input class="form-control" id="date" name="date" value="<?php echo date("Y-m-d")?>" onchange="showUser(this.value)"/>
                        </div>
                        -->
                        <!-- date textbox end -->

                        <!-- script start -->
                        <script>

                            function showUser(str) {
                                
                                if (str == "") {
                                    document.getElementById("txtHint").innerHTML = "";
                                    return;
                                } else { 
                                    if (window.XMLHttpRequest) {
                                        // code for IE7+, Firefox, Chrome, Opera, Safari
                                        xmlhttp = new XMLHttpRequest();
                                    } else {
                                        // code for IE6, IE5
                                        xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
                                    }
                                    xmlhttp.onreadystatechange = function() {
                                        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
                                            document.getElementById("txtHint").innerHTML = xmlhttp.responseText;
                                        }
                                    };
                                    xmlhttp.open("GET","getuser.php?q="+str,true);
                                    console.log(str);
                                    xmlhttp.send();
                                }
                            }
                        </script>
                        
                        <!-- script start end -->
                     
                        <!-- table appointment start -->
                        <div id="txtHint"><b> </b></div>
                        
                        <!-- table appointment end -->
                    </div>
                    <!-- /.col -->
                   <!--  <div class="col-md-6 col-md-offset-1">
                        <div class="video-wrapper">
                            <iframe width="560" height="315" src="http://www.youtube.com/embed/FEoQFbzLYhc?rel=0&amp;controls=0&amp;showinfo=0" frameborder="0" allowfullscreen></iframe>
                        </div>
                    </div> -->
                    <!-- /.col -->
                </div>
                <!-- /.row -->
            </div>
        </section>
        <section style="background-color:grey;" id="content-1-9" class="content-1-9 content-block">
        <div class="underlined-title">
                    <h1 style="color:white;" >OUR DOCTORS</h1>
                    <hr>
                    
                </div>
        <div class="container">
  <div class="row">
    <div class="col-12 col-sm-6 col-md-4 col-lg-4">
      <div class="our-team">
        <div class="picture">
          <img class="img-fluid" src="data:image/jpeg;base64,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">
        </div>
        <div class="team-content">
          <h3 class="name">Dr. Isha Sehegal</h3>
          <h4 class="title">MBBS,MD</h4>
        </div>
        <ul class="social">
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-facebook" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-twitter" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-google-plus" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-linkedin" aria-hidden="true"></a></li>
        </ul>
      </div>
    </div>
    <div class="col-12 col-sm-6 col-md-4 col-lg-4">
      <div class="our-team">
        <div class="picture">
          <img class="img-fluid" src="https://assets.caredash.com/image/OASpAJMzz1SXUkqx0M27xCyG9kU=/caredash-serverless-image-handler/caredash/providers/dr-akash-deep-agarwal-profile-e05fd10a.jpg">
        </div>
        <div class="team-content">
          <h3 class="name">Dr. Ravish Meheta</h3>
          <h4 class="title">MBBS,MD(Medicine)</h4>
        </div>
        <ul class="social">
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-facebook" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-twitter" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-google-plus" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-linkedin" aria-hidden="true"></a></li>
        </ul>
      </div>
    </div>
        <div class="col-12 col-sm-6 col-md-4 col-lg-4">
      <div class="our-team">
        <div class="picture">
          <img class="img-fluid" src="https://www.qrghealthcity.com/DataImages/Dr%20Pankaj%20Chhabra%20Photo%20Square%20Flipped.jpg">
        </div>
        <div class="team-content">
          <h3 class="name">Dr.Shivaji Mudic</h3>
          <h4 class="title">MBBS,MD(E.N.T)</h4>
        </div>
        <ul class="social">
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-facebook" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-twitter" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-google-plus" aria-hidden="true"></a></li>
          <li><a href="https://codepen.io/collection/XdWJOQ/" class="fa fa-linkedin" aria-hidden="true"></a></li>
        </ul>
      </div>
    </div>
  </div>
</div>
</section>
        <!-- first section end -->

        
        <!-- second section start -->
        
        <!-- second section end -->
        <!-- third section start -->
        
        <!-- third section end -->
        <!-- forth sections start -->
        <section id="content-1-9" class="content-1-9 content-block">
            <div class="container">
                <div class="underlined-title">
                    <h1 style="color:white;" >ABOUT US</h1>
                    <hr>
                    <h2 style="color:white;font-family:URW Chancery L, cursive;" >Make your Appointment at Ease .... By making it online !</h2>
                </div>
                <div>
                
                <p style="color:rgb(199, 190, 190);font-size:20px;">Mediclinics provides you with Online Doctor appointment ,It 
                     provides registration and login for patients. Admin can login to the system 
                     to check on the appointments made. New patients who are making appointments online for the first time have to sign up . 
                     After successful registration, 
                    the patient can log in by giving username and password. The Admin can view the booking request by patients and 
                    if he/she accepts the patient's request the status will be shown to the patient in their account.The patients must 
                    be registered and log in to book a doctor's appointment by choosing the date according to their preference.If any 
                    Doctor is available on the patient's selected date it would be displayed below ,and if not then there 
                    would be a message regarding it. Admin can accept the requests and if they are available they will send the 
                    confirmation request back to the patient. The patient can view the status if their appointment request is accepted 
                    in the appointment tab. An invoice will be generated and patient can even print the invoice .If necessary Admin can 
                    even delete a patient from the system.</p>
                </div>

                <!-- <div class="row">
                    <div class="col-md-4 col-sm-12 col-xs-12 pad25">
                        <div class="col-xs-2">
                            <span class="fa fa-pencil"></span>
                        </div>
                        <div class="col-xs-10">
                            <h4>Branding</h4>
                            <p>Retro chillwave YOLO four loko photo booth. Brooklyn kale chips, seitan hella 3 wolf moon slow-carb paleo.</p>
                        </div>
                    </div>
                    <div class="col-md-4 col-sm-12 col-xs-12 pad25">
                        <div class="col-xs-2">
                            <span class="fa fa-code"></span>
                        </div>
                        <div class="col-xs-10">
                            <h4>Web Design</h4>
                            <p>Retro chillwave YOLO four loko photo booth. Brooklyn kale chips, seitan hella 3 wolf moon slow-carb paleo.</p>
                        </div>
                    </div>
                    <div class="col-md-4 col-sm-12 col-xs-12 pad25">
                        <div class="col-xs-2">
                            <span class="fa fa-comments-o"></span>
                        </div>
                        <div class="col-xs-10">
                            <h4>Social Marketing</h4>
                            <p>Retro chillwave YOLO four loko photo booth. Brooklyn kale chips, seitan hella 3 wolf moon slow-carb paleo.</p>
                        </div>
                    </div>
                    <div class="col-md-4 col-sm-12 col-xs-12 pad25">
                        <div class="col-xs-2">
                            <span class="fa fa-search"></span>
                        </div>
                        <div class="col-xs-10">
                            <h4>SEO</h4>
                            <p>Retro chillwave YOLO four loko photo booth. Brooklyn kale chips, seitan hella 3 wolf moon slow-carb paleo.</p>
                        </div>
                    </div>
                    <div class="col-md-4 col-sm-12 col-xs-12 pad25">
                        <div class="col-xs-2">
                            <span class="fa fa-mobile"></span>
                        </div>
                        <div class="col-xs-10">
                            <h4>Mobile Apps</h4>
                            <p>Retro chillwave YOLO four loko photo booth. Brooklyn kale chips, seitan hella 3 wolf moon slow-carb paleo.</p>
                        </div>
                    </div>
                    <div class="col-md-4 col-sm-12 col-xs-12 pad25">
                        <div class="col-xs-2">
                            <span class="fa fa-bookmark"></span>
                        </div>
                        <div class="col-xs-10">
                            <h4>Corporate Literture</h4>
                            <p>Retro chillwave YOLO four loko photo booth. Brooklyn kale chips, seitan hella 3 wolf moon slow-carb paleo.</p>
                        </div>
                    </div>
                </div> -->
                <!-- /.row -->
            </div>
            <!-- /.container -->
        </section>
        <!-- forth section end -->
        <!-- footer start -->
        <div class="copyright-bar bg-black">
            <div class="container">
            <p style="color:black;">Address : Medclinics Nr. lakeplaza , Suncity, Sihagad rd., Pune 411024 / 9:00AM - 2:00PM ,6:00PM - 9:00PM. <br>
             Contact : - 9112840879 / 8446915553 -- medclinics@gmail.com   <a class="adm" style="float:right;" class="link_col" href="admin.php"><u>Admin</u></a>
            </p>
                <p style="color:black;font-size:17px;padding:12px;" class="pull-left small">© ~ Diksha Prasad </p>
                <!-- <p class="pull-right small"><a href="adminlogin.php">admin</a></p> -->
            </div>
        </div>
        <!-- footer end -->
    </div>
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="assets/js/jquery.js"></script>
    <script src="assets/js/date/bootstrap-datepicker.js"></script>
    <script src="assets/js/moment.js"></script>
    <script src="assets/js/transition.js"></script>
    <script src="assets/js/collapse.js"></script>
     <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="assets/js/bootstrap.min.js"></script>
    <script type="text/javascript">
    $('#myModal').on('shown.bs.modal', function () {
    $('#myInput').focus()
    })
    </script>
    <!-- date start -->
  
<script>
    $(document).ready(function(){
        var date_input=$('input[name="date"]'); //our date input has the name "date"
        var container=$('.bootstrap-iso form').length>0 ? $('.bootstrap-iso form').parent() : "body";
        date_input.datepicker({
            format: 'yyyy-mm-dd',
            container: container,
            todayHighlight: true,
            autoclose: true,
        })

    })

</script>

    <!-- date end -->


    <script>
    function show()
    {
    document.getElementById('frm_display').style.display="block" ;
    }
    </script>
   
</body>
</html>
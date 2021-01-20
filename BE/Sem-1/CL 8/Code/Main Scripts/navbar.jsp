<html class="loading" lang="en" data-textdirection="ltr">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0, minimal-ui">
    <meta name="description" content="Chameleon Admin is a modern Bootstrap 4 webapp &amp; admin dashboard html template with a large number of components, elegant design, clean and organized code.">
    <meta name="author" content="ThemeSelect">
    <title>PICT Feedback System</title>
    <link rel="apple-touch-icon" href="theme-assets/images/ico/apple-icon-120.png">
    <!-- BEGIN VENDOR CSS-->
    <link rel="stylesheet" type="text/css" href="theme-assets/css/vendors.css">
    <link rel="stylesheet" type="text/css" href="theme-assets/vendors/css/charts/chartist.css">
    <!-- END VENDOR CSS-->
    <!-- BEGIN CHAMELEON  CSS-->
    <link rel="stylesheet" type="text/css" href="theme-assets/css/app-lite.css">
    <!-- END CHAMELEON  CSS-->
    <!-- BEGIN Page Level CSS-->
    <link rel="stylesheet" type="text/css" href="theme-assets/css/core/menu/menu-types/vertical-menu.css">
    <link rel="stylesheet" type="text/css" href="theme-assets/css/core/colors/palette-gradient.css">
    <link rel="stylesheet" type="text/css" href="theme-assets/css/pages/dashboard-ecommerce.css">
    <!-- END Page Level CSS-->
    <!-- BEGIN Custom CSS-->
    <!-- END Custom CSS-->
  </head>
  <script>
  	function fun(){
  		var elements = document.getElementsByClassName("theli");
  		for(i=0;i<elements.length;i++){
  			if(a == i)
  	  	  		elements[i].classList.add("active");
  			else
  	  	  		elements[i].classList.add("nav_item");  			
  		}
  	}
  </script>
  
  <body onload="fun()" class="vertical-layout vertical-menu 2-columns   menu-expanded fixed-navbar" data-open="click" data-menu="vertical-menu" data-color="bg-gradient-x-purple-blue" data-col="2-columns">

    <!-- fixed-top-->
    <nav class="header-navbar navbar-expand-md navbar navbar-with-menu navbar-without-dd-arrow fixed-top navbar-semi-light">
      <div class="navbar-wrapper">
        <div class="navbar-container content">
          <div class="collapse navbar-collapse show" id="navbar-mobile">
            <ul class="nav navbar-nav mr-auto float-left">
              <li class="nav-item d-block d-md-none"><a class="nav-link nav-menu-main menu-toggle hidden-xs" href="#"><i class="ft-menu"></i></a></li>
              <li class="nav-item d-none d-md-block"><a class="nav-link nav-link-expand" href="#"><i class="ficon ft-maximize"></i></a></li>
            </ul>
            <ul class="nav navbar-nav float-right">
              <li class="dropdown dropdown-user nav-item"><a class="dropdown-toggle nav-link dropdown-user-link" href="#" data-toggle="dropdown">             <span class="avatar avatar-online"><img src="theme-assets/images/portrait/small/avatar-s-19.png" alt="avatar"><i></i></span></a>
                <div class="dropdown-menu dropdown-menu-right">
                  <div class="arrow_box_right"><a class="dropdown-item" href="#"><span class="avatar avatar-online"><img src="theme-assets/images/portrait/small/avatar-s-19.png" alt="avatar"><span class="user-name text-bold-700 ml-1">John Doe</span></span></a>
                    <div class="dropdown-divider"></div><a class="dropdown-item" href="#"><i class="ft-user"></i> Edit Profile</a><a class="dropdown-item" href="#"><i class="ft-mail"></i> My Inbox</a><a class="dropdown-item" href="#"><i class="ft-check-square"></i> Task</a><a class="dropdown-item" href="#"><i class="ft-message-square"></i> Chats</a>
                    <div class="dropdown-divider"></div><a class="dropdown-item" href="#"><i class="ft-power"></i> Logout</a>
                  </div>
                </div>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </nav>

    <!-- ////////////////////////////////////////////////////////////////////////////-->


    <div class="main-menu menu-fixed menu-light menu-accordion    menu-shadow " data-scroll-to-active="true" data-img="theme-assets/images/backgrounds/02.jpg">
      <div class="navbar-header">
        <ul class="nav navbar-nav flex-row">       
          <li class="nav-item mr-auto"><a class="navbar-brand" href="index.html"><img class="brand-logo" alt="Chameleon admin logo" src="theme-assets/images/logo/pict.jpg"/>
              <h3 class="brand-text">PICT Feedback</h3></a></li>
          <li class="nav-item d-md-none"><a class="nav-link close-navbar"><i class="ft-x"></i></a></li>
        </ul>
      </div>
      <div class="main-menu-content">
        <ul class="navigation navigation-main" id="main-menu-navigation" data-menu="menu-navigation">
          <li class="theli"><a href="ins.jsp"><i class="ft-home"></i><span class="menu-title" data-i18n="">Home</span></a>
          </li>
          <li class="theli"><a href="add_domain.jsp"><i class="ft-home"></i><span class="menu-title" data-i18n="">Domain</span></a>
          </li>
          <li class="theli"><a href="Class.jsp"><i class="ft-pie-chart"></i><span class="menu-title" data-i18n="">Class</span></a>
          </li>
          <li class="theli"><a href="subject.jsp"><i class="ft-droplet"></i><span class="menu-title" data-i18n="">Subject</span></a>
          </li>
          <li class="theli"><a href="Teachers.jsp"><i class="ft-layers"></i><span class="menu-title" data-i18n="">Teacher</span></a>
          </li>
          <li class="theli"><a href="template.jsp"><i class="ft-layers"></i><span class="menu-title" data-i18n="">Template</span></a>
          </li>
          <li class="theli"><a href="addquestion.jsp"><i class="ft-layers"></i><span class="menu-title" data-i18n="">Questions</span></a>
          </li>                    
          <li class="nav-item"><a ><i class="ft-box"></i><span class="menu-title" data-i18n="">Map</span></a>
		      <ul class="nav-acc">
		      		<li class="theli"><a href="main_stud_teacher.jsp"><i class="ft-box"></i><span class="menu-title" data-i18n="">Student Teacher</span></a><li>
		      		<li class="theli"><a href="Teacher_template.jsp"><i class="ft-box"></i><span class="menu-title" data-i18n="">Teacher Template</span></a><li>
		      		<li class="theli"><a href="Tea_sub_class.jsp"><i class="ft-box"></i><span class="menu-title" data-i18n="">Teacher Class</span></a><li>		  
		      </ul>
          </li>
          <li class="theli"><a href="generate report.jsp"><i class="ft-bold"></i><span class="menu-title" data-i18n="">Feedback Report</span></a>
          </li>
        </ul>
      </div>
      <div class="navigation-background"></div>
    </div>

  <div class="app-content content">
      <div class="content-wrapper">
        <div class="content-wrapper-before"></div>
		    <div class="content-header row">
		      <div class="content-header-left col-md-4 col-12 mb-2">
		        <h3 class="content-header-title"><script>document.write(title_name)</script></h3>
		      </div>
		      <div class="content-header-right col-md-8 col-12">
		        <div class="breadcrumbs-top float-md-right">
		          <div class="breadcrumb-wrapper mr-1">
		            <ol class="breadcrumb">
		              <li class="breadcrumb-item"><a href="index.html">Home</a>
		              </li>
		              <li class="breadcrumb-item active"><script>document.write(title_name)</script>
		              </li>
		            </ol>
		          </div>
		        </div>
		      </div>
		    </div>

	<div class="content-body">
		<div class="row">
			<div class="col-12">
				<div class="card">
					<div class="card-header">
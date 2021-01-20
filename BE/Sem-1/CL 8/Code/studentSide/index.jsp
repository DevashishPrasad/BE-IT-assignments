<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>   
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>    

<%
	// Initialize database connection parameters
	String id = request.getParameter("userid");
	String driver = "com.mysql.jdbc.Driver";
	String connectionUrl = "jdbc:mysql://localhost:3306/";
	String database = "feedback_main";
	String userid = "Deva";
	String password = "dev123456";
	
	try {
		Class.forName(driver);
	} catch (ClassNotFoundException e) {
		e.printStackTrace();
	}
	
	int flag = 0;
	Connection con = null;
	Statement statement = null;
	ResultSet resultSet = null;
	int rollno = Integer.parseInt(request.getParameter("uname"));
	int cat=0,total=0;
	String teacher_id = request.getParameter("name");
	String tname = request.getParameter("tname");
	String sname = request.getParameter("sname");
	String subject_id = request.getParameter("sub");
	Class.forName("com.mysql.jdbc.Driver");
	con = DriverManager.getConnection(connectionUrl+database, userid, password);
%>

<!DOCTYPE html>
<html class="loading" lang="en" data-textdirection="ltr">

<head>
    <title>Feedback</title>
    <link rel="apple-touch-icon" href="theme-assets/images/ico/apple-icon-120.png">
    <link rel="shortcut icon" type="image/x-icon" href="theme-assets/images/ico/favicon.ico">
    <link href="https://fonts.googleapis.com/css?family=Muli:300,300i,400,400i,600,600i,700,700i%7CComfortaa:300,400,700" rel="stylesheet">
    <link href="https://maxcdn.icons8.com/fonts/line-awesome/1.1/css/line-awesome.min.css" rel="stylesheet">
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
<style>
	.question-card
	{
		position:relative;
		width:70%;
		height:20%;
		left:25%;
		margin-top:100px;		
	} 
</style>
<script src="/1st_increment_feedback/js/jquery.js"></script>
<script type="text/javascript">
	<%
		try{
			if(request.getParameter("flag")!=null)
			{
				flag = Integer.parseInt(request.getParameter("flag"));
				Statement st = con.createStatement();
				resultSet = st.executeQuery("select cat_id from teacher_class_subject where tid='"+teacher_id+"' and sid='"+subject_id+"' and cid_year in (select year from student where rollno='"+rollno+"') and cid_div in (select division from student where rollno='"+rollno+"')");
				resultSet.next();
				cat = resultSet.getInt("cat_id");
			}
            Statement st = con.createStatement();
            Statement st2 = con.createStatement();
            
			ResultSet rs = st.executeQuery("select count(*) as num_ques from question where qid in(select qid from temp_ques where temp_id in (select temp_id from teacher_subject_template where tid='"+teacher_id+"'and sid='"+subject_id+"'))");
            rs.next();
            total = rs.getInt("num_ques");
            ResultSet rs2 = st2.executeQuery("select * from question where qid in(select qid from temp_ques where temp_id in (select temp_id from teacher_subject_template where tid='"+teacher_id+"'and sid='"+subject_id+"'))");
            %>
            
            jQuery(document).ready(function(){
            	
            	if(<%=flag%>)
           		{
            		$('#questions').append("<center><h1><%=tname %>_<%=sname %></h1></center>");
           		}
            	 for(var no = 1; no <= <%=rs.getString("num_ques")%>;no++){ 
            	
              	  $('#questions').append('<div class="question-card"><div class="card"><div class="card-block"><div class="card-body"><div id="ques'+ no +'" class="ques" ></div></div></div></div></div>');

            	}
            	
            	if(<%=flag %>)
           		{
            		$('#questions').append('<div style="margin-bottom:100px; margin-left:30%;"><input type="submit" value="submit"/></div>');
            		$('#questions').append('<div style="margin-bottom:100px; margin-left:30%;"><input type="hidden" name="total" value="<%=total%>"/></div>');
            		$('#questions').append('<div style="margin-bottom:100px; margin-left:30%;"><input type="hidden" name="cat" value="<%=cat%>"/></div>');
            		$('#questions').append('<div style="margin-bottom:100px; margin-left:30%;"><input type="hidden" name="subid" value="<%=subject_id%>"/></div>');
            		$('#questions').append('<div style="margin-bottom:100px; margin-left:30%;"><input type="hidden" name="tid" value="<%=teacher_id%>"/></div>');
           		}
            		
            	
            
            	var no = 1;
            	
            	
            	<%while(rs2.next()){%>
            	
            	if(no<=<%=rs.getString("num_ques")%>){
            		
            		$('#ques'+no).append('<p>'+no+'. <%=rs2.getString("question")%></p>');
            		$('#ques'+no).append('<p><input type="radio" value="40" name = "'+no+'"/><%=rs2.getString("option1")%></p>');
            		$('#ques'+no).append('<p><input type="radio" value="30" name = "'+no+'"/><%=rs2.getString("option2")%></p>');
            		$('#ques'+no).append('<p><input type="radio" value="20" name = "'+no+'"/><%=rs2.getString("option3")%></p>');
            		$('#ques'+no).append('<p><input type="radio" value="10" name = "'+no+'"/><%=rs2.getString("option4")%></p>');
            	}
            	no++;
            		
            	<%}%>
            	
            	var $currentElement = $('.question-card').first();

        		//alert($currentElement)

    			$('div.question-card input ').on('click',function () {

    				//alert('Div clicked')

    			    var $nextElement = $currentElement.next('.question-card');
    			     //Check if next element actually exists
    			    	if($nextElement.length) {
    			        // If yes, update:
    			        // 1. $currentElement
    			        // 2. Scroll position
    			        $currentElement = $nextElement;
    			        //alert('lalalal')
    			        $('html, body').animate({
    			            scrollTop: $nextElement.offset().top - 150 
    			        }, 'slow');
    			    }
    			    else{
    			    	$currentElement = $('.question-card').first();
    			    	//alert('ksfhdsjk')
    			    }
    			      
            	});
            });
            
		<%
		}
		catch(Exception e){
			e.printStackTrace();
		}
	%>
</script>

<body class="vertical-layout vertical-menu 2-columns   menu-expanded fixed-navbar" data-open="click" data-menu="vertical-menu" data-color="bg-chartbg" data-col="2-columns">

    <!-- fixed-top-->
    <nav class="header-navbar navbar-expand-md navbar navbar-with-menu navbar-without-dd-arrow fixed-top navbar-semi-light">
        <div class="navbar-wrapper">
            <div class="navbar-container content">
                <div class="collapse navbar-collapse show" id="navbar-mobile">
                    <ul class="nav navbar-nav mr-auto float-left">
                        <li class="nav-item d-block d-md-none"><a class="nav-link nav-menu-main menu-toggle hidden-xs" href="#"><i class="ft-menu"></i></a></li>
                        <li class="nav-item d-none d-md-block"><a class="nav-link nav-link-expand" href="#"><i class="ficon ft-maximize"></i></a></li>
                        <li class="nav-item dropdown navbar-search"><a class="nav-link dropdown-toggle hide" data-toggle="dropdown" href="#"><i class="ficon ft-search"></i></a>
                            <ul class="dropdown-menu">
                                <li class="arrow_box">
                                    <form>
                                        <div class="input-group search-box">
                                            <div class="position-relative has-icon-right full-width">
                                                <input class="form-control" id="search" type="text" placeholder="Search here...">
                                                <div class="form-control-position navbar-search-close"><i class="ft-x">   </i></div>
                                            </div>
                                        </div>
                                    </form>
                                </li>
                            </ul>
                        </li>
                    </ul>
                    <ul class="nav navbar-nav float-right">
                        <li class="dropdown dropdown-language nav-item"><a class="dropdown-toggle nav-link" id="dropdown-flag" href="#" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false"><i class="flag-icon flag-icon-us"></i><span class="selected-language"></span></a>
                            <div class="dropdown-menu" aria-labelledby="dropdown-flag">
                                <div class="arrow_box"><a class="dropdown-item" href="#"><i class="flag-icon flag-icon-us"></i> English</a><a class="dropdown-item" href="#"><i class="flag-icon flag-icon-cn"></i> Chinese</a><a class="dropdown-item" href="#"><i class="flag-icon flag-icon-ru"></i> Russian</a>
                                    <a class="dropdown-item" href="#"><i class="flag-icon flag-icon-fr"></i> French</a><a class="dropdown-item" href="#"><i class="flag-icon flag-icon-es"></i> Spanish</a></div>
                            </div>
                        </li>
                    </ul>
                    <ul class="nav navbar-nav float-right">
                        <li class="dropdown dropdown-notification nav-item"><a class="nav-link nav-link-label" href="#" data-toggle="dropdown"><i class="ficon ft-mail">             </i></a>
                            <div class="dropdown-menu dropdown-menu-right">
                                <div class="arrow_box_right"><a class="dropdown-item" href="#"><i class="ft-book"></i> Read Mail</a><a class="dropdown-item" href="#"><i class="ft-bookmark"></i> Read Later</a><a class="dropdown-item" href="#"><i class="ft-check-square"></i> Mark all Read       </a></div>
                            </div>
                        </li>
                        <li class="dropdown dropdown-user nav-item">
                            <a class="dropdown-toggle nav-link dropdown-user-link" href="#" data-toggle="dropdown"> <span class="avatar avatar-online"><img src="theme-assets/images/portrait/small/avatar-s-19.png" alt="avatar"><i></i></span></a>
                            <div class="dropdown-menu dropdown-menu-right">
                                <div class="arrow_box_right"><a class="dropdown-item" href="#"><span class="avatar avatar-online"><img src="theme-assets/images/portrait/small/avatar-s-19.png" alt="avatar"><span class="user-name text-bold-700 ml-1">John Doe</span></span></a>
                                    <div class="dropdown-divider"></div><a class="dropdown-item" href="#"><i class="ft-user"></i> Edit Profile</a><a class="dropdown-item" href="#"><i class="ft-mail"></i> My Inbox</a><a class="dropdown-item" href="#"><i class="ft-check-square"></i> Task</a>
                                    <a class="dropdown-item" href="#"><i class="ft-message-square"></i> Chats</a>
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
                <li class="nav-item mr-auto">
                    <a class="navbar-brand" href="index.html"><img class="brand-logo" alt="Chameleon admin logo" src="theme-assets/images/logo/logo.png" />
                    	Feedback                        
                    </a>
                </li>
                <li class="nav-item d-md-none"><a class="nav-link close-navbar"><i class="ft-x"></i></a></li>
            </ul>
        </div>
        <div class="main-menu-content">
            <ul class="navigation navigation-main" id="main-menu-navigation" data-menu="menu-navigation">
            	<%
					try{
				    		statement=con.createStatement();
				    		String sql = "select domain_name from domain";
							
				    		resultSet = statement.executeQuery(sql);
				    		while(resultSet.next()){
				    			String t_name = resultSet.getString("domain_name");
				%>
						   		<li class="nav-item"><a href="#"><i class="ft-home"></i><span class="menu-title" data-i18n=""><%=t_name %></span></a>
						   			<ul>
						   				<%
						   					ResultSet rs = null;
						   					Statement statement1=con.createStatement();
						   					if(t_name =="LTL")
						   					{
						   						rs = statement1.executeQuery("select * from student_cat join teachers on tid=id join subject on sid=subject_id where rollno='"+rollno+"' and domain_name='"+t_name+"'");
						   						while(rs.next()){
									    			String name = rs.getString("name");
									    			String sub = rs.getString("subject_name");
									    			String tid = rs.getString("tid");
									    			String subid = rs.getString("subject_id");
									    			
												%>
													<li class="nav-item"><a href="index.jsp?name=<%=tid%>&sub=<%=subid%>&flag=1" ><i class="ft-home"></i><span class="menu-title" data-i18n=""><%=name %>_<%=sub %></span></a></li>
												<%}
						   					}
						   					else 
						   					{
						   						rs = statement1.executeQuery("select * from teacher_class_subject join teachers on tid=id join subject on sid=subject_id where cid_year in (select year from student where rollno='"+rollno+"') and cid_div in (select division from student where rollno='"+rollno+"') and domain_name='"+t_name+"'");
								   				while(rs.next()){
									    			String name = rs.getString("name");
									    			String sub = rs.getString("subject_name");
									    			String tid = rs.getString("tid");
									    			String subid = rs.getString("sid");
									    			
												%>
													<li class="nav-item"><a href="index.jsp?name=<%=tid%>&sub=<%=subid%>&flag=1&tname=<%=name %>&sname=<%=sub %>&uname=<%=rollno %>" ><i class="ft-home"></i><span class="menu-title" data-i18n=""><%=name %>_<%=sub %></span></a></li>
												<%} 
						   					}
												%>
															
						   			</ul>
						   		</li>		    		
				<%
				    		}
			    			con.close(); 
				    	}
			    	 	catch (Exception e) {
			    			e.printStackTrace();
			    		}
				%>
  
            </ul>
	       
        <div class="navigation-background"></div>
    </div>
</div>

    <!-- /////////////////////////////////////////////////////////////////////////////-->
   	<form action ="processanswer.jsp" accept-charset=utf-8  id ="questions"></form>
    <!-- BEGIN VENDOR JS-->
    <script src="theme-assets/vendors/js/vendors.min.js" type="text/javascript"></script>
    <!-- BEGIN VENDOR JS-->
    <!-- BEGIN PAGE VENDOR JS-->
    <script src="theme-assets/vendors/js/charts/chartist.min.js" type="text/javascript"></script>
    <!-- END PAGE VENDOR JS-->
    <!-- BEGIN CHAMELEON  JS-->
    <script src="theme-assets/js/core/app-menu-lite.js" type="text/javascript"></script>
    <script src="theme-assets/js/core/app-lite.js" type="text/javascript"></script>
    <!-- END CHAMELEON  JS-->
    <!-- BEGIN PAGE LEVEL JS-->
    <script src="theme-assets/js/scripts/pages/dashboard-lite.js" type="text/javascript"></script>
    <!-- END PAGE LEVEL JS-->
</body>

</html>
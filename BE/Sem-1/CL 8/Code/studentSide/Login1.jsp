<%@ page language="java" contentType="text/html; charset=UTF-8"
  pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>


<html>

<head>
  <link rel="stylesheet" href="Login.css">
  <link href="https://fonts.googleapis.com/css?family=Ubuntu" rel="stylesheet">
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <link rel="stylesheet" href="path/to/font-awesome/css/font-awesome.min.css">
  <title>Student Evaluation System</title>
  <script>
    
    var error = '<%=session.getAttribute("error")%>';

    if(error.trim().length != 0){
          alert(error);
     <%
        session.setAttribute("error"," ");
        session.setAttribute("user","");
     %> 
   }


  </script>
</head>

<body>
  <div class="main">
    <p class="sign" align="center">Sign in</p>
    <form class="form1" action="login.jsp" method="post"> 
      <input class="un " type="text" align="center" placeholder="Username" name="uname" autocomplete="off" required />
      <input class="pass" type="password" align="center" placeholder="Password" name="passwd" autocomplete="off" required />
      <input type="submit" class="submit" value="Login"  />
      </form>      
                
    </div>
     
</body>

</html>


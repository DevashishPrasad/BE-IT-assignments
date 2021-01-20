<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>
<%
	String uname = request.getParameter("uname");
	String pass = request.getParameter("passwd");
	
	try{
		Class.forName("com.mysql.jdbc.Driver");
		
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main","Deva","dev123456");
		
		String query = "select rollno,pass from student where rollno="+uname;
		Statement st = con.createStatement();
		ResultSet resultSet = st.executeQuery(query);
		
		if(resultSet.next()){
			System.out.println(resultSet.getString("rollno")+" 88888 "+resultSet.getString("pass"));
			if(pass.equals(resultSet.getString("pass"))){
				response.sendRedirect("index.jsp?uname="+uname);
				 
			}else{
				session.setAttribute("error","Password or Username is Wrong");
				response.sendRedirect("Login1.jsp");
			}
		}
		else{
			session.setAttribute("error","No user with user Name "+uname);
			response.sendRedirect("Login1.jsp");
		}
		

		st.close();
		resultSet.close();
		con.close();
	
	}catch(Exception e){
		e.printStackTrace();
	}
%>
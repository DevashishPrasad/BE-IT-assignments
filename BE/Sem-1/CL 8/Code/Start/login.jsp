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
		
		String query = "select pass from accounts where name='"+uname+"'";
		
		Statement st = con.createStatement();
		ResultSet resultSet = st.executeQuery(query);
		
		if(resultSet.next())
			if(pass.equals(resultSet.getString("pass")))
				response.sendRedirect("/1st_increment_feedback/Main Scripts/ins.jsp");
			else
				response.sendRedirect("Login.html?error=Password or Username is Wrong");	
		else
				response.sendRedirect("Login.html?error=No user with user Name");
		
		
		st.close();
		resultSet.close();
		con.close();
	
	}catch(Exception e){
		e.printStackTrace();
	}
%>

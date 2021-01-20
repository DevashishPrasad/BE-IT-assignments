<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>
<%
	String uname = request.getParameter("username");
	String pass = request.getParameter("password");
	/*out.println("Reading Parameters");*/
	boolean flag = false;
	try{
		Class.forName("com.mysql.jdbc.Driver");
		
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/Feedback","Manish","Manny@123");
		
		String query = "insert into accounts(name,pass) values('"+uname+"','"+pass+"')";
		String searchQuery = "select name from accounts";
		Statement st = con.createStatement();
		
		
		
		ResultSet resultSet = st.executeQuery(searchQuery);
		
		while(resultSet.next()){
			if(uname.equals(resultSet.getString("name"))){
				flag = true;
				/* response.sendRedirect(""); */
			}else{
				flag = false;
			}
			
		}
		
		if(flag){
			out.println("This Username is not available");
			st.close();
			resultSet.close();
			con.close();
			
		}else{
			Statement st1 = con.createStatement();
			int i = st.executeUpdate(query);
			if(i < 0){
				out.println("Failed to Register try later");
				response.sendRedirect("Register.html");		
			
			}else{
				out.println("Registered Successfully");
				st1.close();
				con.close();
				
				response.sendRedirect("Login.html");
			}
		}
		
		
	}catch(Exception e){
		e.printStackTrace();
	}
%>

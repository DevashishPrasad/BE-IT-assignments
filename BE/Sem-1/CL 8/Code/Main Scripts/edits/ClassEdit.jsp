<%@page import="java.sql.*"%>
<%@page import="java.sql.*"%>
<%@page import="javax.sql.*"%>
<%@page import="java.util.*" %>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<% 

String odiv=request.getParameter("odiv");
String oyear=request.getParameter("oyear");
String div=request.getParameter("div");
String year=request.getParameter("year");
String ran1=request.getParameter("ran1");
String ran2=request.getParameter("ran2");
String dept=request.getParameter("dept");

try{
	Connection conn = null;
	Class.forName("com.mysql.jdbc.Driver").newInstance();
	conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main","Deva", "dev123456");
	Statement st=null;
	st=conn.createStatement();
	st.executeUpdate("update class set year='"+year+"',dept='"+dept+"',division="+div+",ran1="+ran1+",ran2="+ran2+" where division="+odiv+" and year ='"+ oyear +"';");
	response.sendRedirect("/1st_increment_feedback/Main Scripts/Class.jsp");
}
catch(Exception e){
	System.out.println(e);
	response.sendRedirect("/1st_increment_feedback/Main Scripts/Class.jsp?error=the record was not updated");
}
      
%>



<%@page import="java.sql.*"%>

<%@page import="java.sql.*"%>
<%@page import="java.sql.*"%>
<%@page import="javax.sql.*"%>
<%@page import="java.util.*" %>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
  
<% 
String oid=request.getParameter("oid");
String name=request.getParameter("name");
String dept=request.getParameter("dept");
try{
Connection conn = null;
Class.forName("com.mysql.jdbc.Driver").newInstance();
conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main","Deva", "dev123456");
Statement st=null;
st=conn.createStatement();
st.executeUpdate("update teachers set name='"+name+"',dept='"+dept+"' where id="+oid+"");
response.sendRedirect("http://localhost:8080/1st_increment_feedback/Main%20Scripts/Teachers.jsp");
}
catch(Exception e){
System.out.println(e);
}
      
%>

<%@page import="java.sql.*"%>

<%@page import="java.sql.*"%>
<%@page import="java.sql.*"%>
<%@page import="javax.sql.*"%>
<%@page import="java.util.*" %>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
  
<%
String oqid=request.getParameter("oqid");
String question=request.getParameter("qname");
String option1=request.getParameter("op1");
String option2=request.getParameter("op2");
String option3=request.getParameter("op3");
String option4=request.getParameter("op4");



try{
Connection conn = null;
Class.forName("com.mysql.jdbc.Driver").newInstance();
conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main","Deva", "dev123456");
Statement st=null;
st=conn.createStatement();
st.executeUpdate("update question set question='"+question+"',option1='"+option1+"',option2='"+option2+"',option3='"+option3+"',option4='"+option4+"' where qid="+oqid+";");
response.sendRedirect("/1st_increment_feedback/Main Scripts/addquestion.jsp");
}
catch(Exception e){
System.out.println(e);
}
      
%>

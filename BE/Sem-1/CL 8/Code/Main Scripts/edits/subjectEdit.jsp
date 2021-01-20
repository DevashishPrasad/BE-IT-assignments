<%@page import="java.sql.*"%>

<%@page import="java.sql.*"%>
<%@page import="java.sql.*"%>
<%@page import="javax.sql.*"%>
<%@page import="java.util.*" %>
<% 
String osid=request.getParameter("osid");
String sid=request.getParameter("sid");
String sname=request.getParameter("sname");
String domain=request.getParameter("dname");
String dept=request.getParameter("dept");
String yr=request.getParameter("yr");
try{
	Connection conn = null;
	Class.forName("com.mysql.jdbc.Driver").newInstance();
	conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main","Deva", "dev123456");
	Statement st=null;
	st=conn.createStatement();
	st.executeUpdate("update subject set subject_id="+sid+",subject_name='"+sname+"',dept_id='"+dept+"',domain_name='"+domain+"',yr='"+yr+"' where subject_id="+osid+"");
	response.sendRedirect("/1st_increment_feedback/Main Scripts/subject.jsp");
}
catch(Exception e){
	System.out.println(e);
	response.sendRedirect("/1st_increment_feedback/Main Scripts/subject.jsp?error=the record was not updated");
}
      
%>


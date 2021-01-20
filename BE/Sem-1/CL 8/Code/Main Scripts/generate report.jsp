<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>    
<%@page import="jclass.*" %>

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

Connection connection = null;
Statement statement = null;
ResultSet resultSet = null;

class Report{
	public String year;
	public String div;
	public String teacherorig;
	public String subject;
	Report(){
		
	}
}

Report report = new Report();

report.year=request.getParameter("select_year");
report.div=request.getParameter("select_div");
report.teacherorig=request.getParameter("select_teacher");
report.subject=null;

String tname=" ";
String teacher="1";
if(teacherorig!=null){
	String[] arrOfStr = teacherorig.split("#", 2);
	teacher = (String) arrOfStr[0];
	tname = (String) arrOfStr[1]; 
}
session.setAttribute("select_year",year);
session.setAttribute("select_div",div);
session.setAttribute("select_teacher",teacher);
%>

<script>
	var a = 9
	var title_name = "Teacher Subject Class Mapping"
</script>
<%@ include file = "navbar.jsp" %>
<form method="post" action="#" name='myform' id="tsc" >
<label>Select Year</label>
<select name="select_year" id="select_year" onchange="document.forms['myform'].submit();">
<option> </option>
<%
try{
    connection = DriverManager.getConnection(connectionUrl+database, userid, password);
    statement=connection.createStatement();
    String sql = "select distinct(year) as year1 from class";

    resultSet = statement.executeQuery(sql);
    while(resultSet.next()){
    String year2 = resultSet.getString("year1");
%>
  <option value="<%= year2 %>"><%= year2 %></option>    
<%
  }
    connection.close();
    }catch (Exception e) {
    e.printStackTrace();
    }
%>

      </select>
      <label>Select Division</label>
<select name="select_div" id="select_div" onchange="document.forms['myform'].submit();">
<%
try{
    connection = DriverManager.getConnection(connectionUrl+database, userid, password);
    statement=connection.createStatement();
    String sql = "select division from class where year='"+year+"'";

    resultSet = statement.executeQuery(sql);
    while(resultSet.next()){
     String div2 = resultSet.getString("division");
%>
<option value="<%= div2 %>"><%= div2 %></option>      
<%
  }
    connection.close();
    }catch (Exception e) {
    e.printStackTrace();
    }
%>

      </select>

<label>Select teacher</label>
<select name="select_teacher" id="select_teacher" onchange="document.forms['myform'].submit();">
<%
try{
    connection = DriverManager.getConnection(connectionUrl+database, userid, password);
    statement=connection.createStatement();
    String sql = "select id,name from teachers where dept=(select dept from class where year='"+year+"' and division='"+div+"')";

    resultSet = statement.executeQuery(sql);
    while(resultSet.next()){
    String t_name = resultSet.getString("name");
%>
  <option value="<%= resultSet.getInt("id") %>#<%= t_name %>"><%=t_name %></option>    
<%
  }
    connection.close();
    }catch (Exception e) {
    e.printStackTrace();
    }
%>

      </select>

</form>
<form action="process_report.jsp" target="_blank">     
      <label>Select subject</label>
	<select name="select_subject" >
<%
try{
    connection = DriverManager.getConnection(connectionUrl+database, userid, password);
    statement=connection.createStatement();
    String sql = "select subject_name,subject_id from teacher_class_subject join subject on teacher_class_subject.sid = subject.subject_id where cid_year = '" + year + "' and cid_div = " + div + " and tid = "+teacher;
    //String sql = "select subject_id,subject_name from subject where dept_id=(select dept from class where year='"+year+"'and division='"+div+"') and yr='"+year+"'";

    resultSet = statement.executeQuery(sql);
    while(resultSet.next()){
    String t_name = subject =resultSet.getString("subject_name");
%>
  <option value="<%= resultSet.getString("subject_id") %>"><%=t_name %></option>    
<%
  }
    connection.close();
    }catch (Exception e) {
    e.printStackTrace();
    }
%>

      </select>
      <br>
      <input type="submit" name="gr" value="View Report"/>
</form>

<%@ include file="downbar.jsp" %>

<script src="/1st_increment_feedback/js/jquery.js"></script>
<script>
$(document).ready(function(){
	$("#select_teacher").val("<%=teacherorig%>")
	$("#select_year").val("<%=year%>")
	$("#select_div").val("<%=div%>")
});
</script>
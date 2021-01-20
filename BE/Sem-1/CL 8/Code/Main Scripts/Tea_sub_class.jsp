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
String year=request.getParameter("select_year"),div=request.getParameter("select_div"),teacher=request.getParameter("select_teacher"),subject=null;
%>

<script>
	var a = 9
	var title_name = "Teacher Subject Class Mapping"
</script>
<%@ include file = "navbar.jsp" %>
<form method="post" action="#" name='myform' id="tsc" >
<label>Select Year</label>
<select name="select_year" id="select_year" onchange="document.forms['myform'].submit();">
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
<select name="select_teacher" >
<%
try{
    connection = DriverManager.getConnection(connectionUrl+database, userid, password);
    statement=connection.createStatement();
    String sql = "select id,name from teachers where dept=(select dept from class where year='"+year+"'and division='"+div+"')";
    System.out.println(year+" "+div);

    resultSet = statement.executeQuery(sql);
    while(resultSet.next()){
    String t_name = teacher =resultSet.getString("name");
%>
  <option value="<%= resultSet.getInt("id") %>"><%=t_name %></option>    
<%
  }
    connection.close();
    }catch (Exception e) {
    e.printStackTrace();
    }
%>

      </select>
     
      <label>Select subject</label>
<select name="select_subject" >
<%
try{
    connection = DriverManager.getConnection(connectionUrl+database, userid, password);
    statement=connection.createStatement();
    String sql = "select subject_id,subject_name from subject where dept_id=(select dept from class where year='"+year+"'and division='"+div+"') and yr='"+year+"'";

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
      <input type="submit" name="add" value="Add"/>
     </form>
<%
try{
    connection = DriverManager.getConnection(connectionUrl+database, userid, password);
    statement=connection.createStatement();
    String s = request.getParameter("add");
    String sql=null;
    String year1=request.getParameter("select_year"),div1=request.getParameter("select_div"),tid=request.getParameter("select_teacher"),sid=request.getParameter("select_subject");
    if(s!=null)
    {
        sql = "insert into teacher_class_subject values(null,'"+tid+"','"+year1+"','"+div1+"','"+sid+"')";
        statement.executeUpdate(sql);
        %>
	    <p style="color:#0000FF"><%out.println("MAPPING ADDED");%></p>
	    <% 	
    }
    connection.close();
    }catch (Exception e) {
    e.printStackTrace();
    }
%>

<form action="#" method=post>
<input type="submit" name="delete" value="delete">
<%
		if(request.getParameter("delete")!=null)
		{
			sammdao obj=new sammdao();
			String[] arr=(String[])request.getParameterValues("selected");
			obj.tcsdel(arr);
		}

%>
<div class="table-responsive">
<table class="table">
<tr>
<th>delete</th>
<th>Teacher</th>
<th>Year</th>
<th>Division</th>
<th>Subject</th>
</tr>
<%
try{
    connection = DriverManager.getConnection(connectionUrl+database, userid, password);
    statement=connection.createStatement();
    String sql = "select (select name from teachers where id=tid) as name,cid_year,cid_div,(select subject_name from subject where subject_id=sid) as sub  from teacher_class_subject";

    resultSet = statement.executeQuery(sql);
    while(resultSet.next()){%>
    <tr>
    <td><input type="checkbox" name="selected" value='<%=resultSet.getString("name")%>#<%=resultSet.getString("sub")%>#<%=resultSet.getString("cid_year")%>#<%=resultSet.getString("cid_div")%>'/></td>
<td><%=resultSet.getString("name")%></td>
<td><%=resultSet.getString("cid_year")%></td>
<td><%=resultSet.getString("cid_div")%></td>
<td><%=resultSet.getString("sub")%></td>
</tr>

<%
  }
    connection.close();
    }catch (Exception e){
    e.printStackTrace();
  }
%>
</table>
</div>
</form>

<%@ include file = "downbar.jsp" %>

<script src="/1st_increment_feedback/js/jquery.js"></script>
<script>

$(document).ready(function(){
$("#select_year").val("<%= year%>")
$("#select_div").val("<%= div%>")
});
</script>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="jclass.*" %>    
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>    

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
	}
	catch (ClassNotFoundException e) {
		e.printStackTrace();
	}
	
	Connection connection = null;
	Statement statement = null;
	ResultSet resultSet = null;
	int set = 0;
	
	String year_name = null;
	String dept_name = null;
	
	if (request.getParameter("sel_year") != null) {
	    year_name = request.getParameter("sel_year");
	}
	if (request.getParameter("sel_dept") != null) {
		dept_name = request.getParameter("sel_dept");
	}
	System.out.println(year_name);
	System.out.println(dept_name);
%>
<script>
	var a = 8
	var title_name = "Teacher Template Mapping"
</script>
<%@ include file = "navbar.jsp" %>
	<form action="/1st_increment_feedback/Main Scripts/Teacher_template.jsp" name='myform'>
		<label>Year</label>
		<select name="sel_year" id="sel_year">
		<%
			try{
		    		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
		    		statement=connection.createStatement();
		    		String sql = "select distinct(cid_year) from teacher_class_subject";
					
		    		resultSet = statement.executeQuery(sql);
		    		while(resultSet.next()){
		    			String y_name = resultSet.getString("cid_year");
		%>
				   		<option value="<%= y_name %>"><%= y_name %></option>		    		
		<%
	  	 			}
	    			connection.close(); 
	    	 	}catch (Exception e) {
					e.printStackTrace();
	    		}
		%>
		
      	</select>
      	<br>
      	<label>Dept</label>
		<select name="sel_dept" id="sel_dept" onchange="document.forms['myform'].submit();">
		<%
			try{
		    		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
		    		statement=connection.createStatement();
		    		String sql = "select * from dept";
					
		    		resultSet = statement.executeQuery(sql);
		    		while(resultSet.next()){
		    			String d_name = resultSet.getString("dept_name");
		%>
				   		<option value="<%= d_name %>"><%= d_name %></option>		    		
		<%
	  	 			}
	    			connection.close(); 
	    	 	}catch (Exception e) {
					e.printStackTrace();
	    		}
		%>
      	</select>
      	
   </form>
   <form action="process_teacher_temp.jsp">
   		<label>Category</label>
      	<select name="sel_teach" id="sel_teach">
		<%
			try{
		    		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
		    		statement=connection.createStatement();
		    		String sql = "select tid,(select name from teachers where id=tid) as name,sid,(select subject_name from subject where subject_id=sid) as sname from teacher_class_subject where cid_year='"+ year_name + 
		    						"' and cid_div in (select division from class where dept = '" + dept_name + "' )";
					
		    		resultSet = statement.executeQuery(sql);
		    		while(resultSet.next()){
		    			String tid = resultSet.getString("tid");
		    			String sid = resultSet.getString("sid");
		    			String tname = resultSet.getString("name");
		    			String sname = resultSet.getString("sname");
		%>
				   		<option value="<%= tid %>-<%= sid %>"><%= tname %>-<%= sname %></option>		    		
		<%
	  	 			}
	    			connection.close(); 
	    	 	}catch (Exception e) {
					e.printStackTrace();
	    		}
		%>
      	</select>
      	<br>
      	<label>Template</label>
      	<select name="sel_temp" id="sel_temp">
		<%
			try{
		    		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
		    		statement=connection.createStatement();
		    		String sql = "select * from template";
					
		    		resultSet = statement.executeQuery(sql);
		    		while(resultSet.next()){
		    			String t_name = resultSet.getString("temp_name");
		%>
				   		<option value="<%= t_name %>"><%= t_name %></option>		    		
		<%
	  	 			}
	    			connection.close(); 
	    	 	}catch (Exception e) {
					e.printStackTrace();
	    		}
		%>
      	</select>
      	<input type="submit" value="map"/>
     </form>
     <form action="#" method=post>
     <input type="submit" name="delete" value="delete">
     <%
     	if(request.getParameter("delete")!=null)
     	{
			sammdao obj=new sammdao();
			String[] arr=(String[])request.getParameterValues("selected");
			obj.teachtempdel(arr);
     	}
     	%>
<div class="table-responsive">
	<table class="table">
	    	<tr>
	    	<th>Delete</th>
	    	<th>Teacher Name</th>
	    	<th>Subject Name</th>
	    	<th>Template Name</th>
	    	</tr>	
<%
	    	try{
		    		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
		    		statement=connection.createStatement();
		    		String sql = "select tid,(select name from teachers where id=tid) as name,sid,(select subject_name from subject where subject_id=sid) as sname,temp_id from teacher_subject_template";

		    		if(sql != null){
						resultSet = statement.executeQuery(sql);
		    			while(resultSet.next()){
	%>
	    		<tr>
	    		<td><input type="checkbox" name="selected" value='<%=resultSet.getString("tid")%>#<%=resultSet.getString("sid")%>#<%=resultSet.getString("temp_id")%>' /></td>
	    		<td><%=resultSet.getString("name") %></td>
	    		<td><%=resultSet.getString("sname") %></td>
	    		<td><%=resultSet.getString("temp_id") %></td>
	    		</tr>
	<%
	    				}
	    				connection.close();
	    			} 
	    	 	}catch (Exception e) {
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
		$("#sel_year").val("<%= year_name %>")
		$("#sel_dept").val("<%= dept_name %>")
	});
</script>
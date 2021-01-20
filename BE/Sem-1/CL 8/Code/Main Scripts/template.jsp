<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>    
<%@page import="jclass.*"%>

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

	if (request.getParameter("single") != null) {
	    set = 2;
	} else if (request.getParameter("add") != null) {
	    set = 3;
	} else if (request.getParameter("delete") != null) {
	    set = 4;
	}
%>
<script>
	var a = 5
	var title_name = "Question Template"
</script>
<%@ include file = "navbar.jsp" %>
	<form action="template.jsp" method="post">
		<br>
		<input name="temp_name" type="text" />
		<br>
		<input type="submit" name="single" value="Search template"/>
		<input type="hidden" name="error" value="" />
		<br>
		<input type="submit" name="add" value="Add"/>
	</form>
	<br>
	<form action="#" method=post>
		<input type="submit" name="delete" value="Delete"/>
		<%
					if(set == 4){
						sammdao obj = new sammdao();
						
						String[] arr = (String[]) request.getParameterValues("selected");
						obj.templatedel(arr);
					}
		%>
	<div class="table-responsive">
	<table class="table">
		<thead>
			<tr>
				<th>Delete </th>
				<th>Template Name</th>
				<th>Edit </th>
			</tr>
		</thead>
	
<%
			class Template{
				public String tname;
			}

			Template template = new Template();
			
	    	try{
		    		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
		    		statement=connection.createStatement();
		    		String sql = "select * from template order by temp_name", sql1 = null;

					if(set == 2){
						String name = request.getParameter("temp_name");
						if(name!="")
					 		sql ="select * from template where temp_name = '" + name + "'" ;
						else
							sql ="select * from template";
					}
					else if(set == 3)
					{
						template.tname = request.getParameter("temp_name");
						if(template.tname == "")
				         {
				             %><script>alert("Please Enter the name")</script><%
				         }
				         else
				         {
				            
				        	try{
				        	sql1 = "INSERT INTO template(temp_name) VALUES('"+template.tname+"')";
				            int res = statement.executeUpdate(sql1);
				            
				            %>
						    <p style="color:#0000FF"><%out.println("#TEMPLATE ADDED");%></p>
						    <%
				         	}
				            catch(SQLException e)
				            {
				            	%>
							    <p style="color:#FF0000"><%out.println("INVALID INPUT");%></p>
							    <% 
				            }
				           
				            }
				         
					}
					if(request.getParameter("error")!=null&&request.getParameter("error")!="")
					{
						%>
					    <p style="color:#FF0000"><%out.println("INVALID INPUT");%></p>
					    <% 
					    
					}
					
					if(sql != null){
						resultSet = statement.executeQuery(sql);
		    			while(resultSet.next()){
	%>
	    		<tr>
	    			<td><input type="checkbox" name="selected" value='<%=resultSet.getString("temp_name") %>'/></td>
		    		<td><input type="text" disabled="true" id="<%=resultSet.getString("temp_name") %>" value="<%=resultSet.getString("temp_name") %>"/></td>
		    		<td><input type="button" onclick="fun1(this,'<%=resultSet.getString("temp_name") %>')" value="EDIT"/></td>
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
<script>
var prev = null
var oname = null
function fun1(el,el_id){
	if(el.value == "UPDATE"){
		var name = document.getElementById(el_id).value
		var urlstr = "edits/templateEdit.jsp?oname="+ oname +"&name="+ name
		window.location.replace(urlstr)
		el.value = 'EDIT'
		prev.disabled = true
		oname = null
	}
	else{	
		if(prev != null)
			prev.disabled = true
		oname = document.getElementById(el_id).value
		var cur = document.getElementById(el_id)
		cur.disabled = false
		el.value = "UPDATE"
		prev = cur
	}
}
</script>
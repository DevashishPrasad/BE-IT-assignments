<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.DriverManager"%>
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
	} catch (ClassNotFoundException e) {
		e.printStackTrace();
	}
	
	Connection connection = null;
	Statement statement = null;
	ResultSet resultSet = null;
	String status = "";
	String temp_name = request.getParameter("select_temp");
	System.out.println(temp_name);
	if(request.getParameter("status") != null)
		status = request.getParameter("status");
%>

<script>
	var a = 6
	var title_name = "Question Template"
</script>
<%@ include file = "navbar.jsp" %>
	<p style="color:#0000FF"><%= status %></p>
	<form method="post" action="/1st_increment_feedback/Main Scripts/addquestion.jsp" id="myform">
		<h1>Add Questions</h1>
		<label>Select name of the template</label>
		<select name="select_temp" id="sel_tem" onchange="document.forms['myform'].submit();">
		<%
			try{
		    		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
		    		statement=connection.createStatement();
		    		String sql = "select temp_name from template";
					
		    		resultSet = statement.executeQuery(sql);
		    		while(resultSet.next()){
		    			String t_name = resultSet.getString("temp_name");
		%>
				   		<option value="<%= t_name %>"><%=t_name %></option>		    		
		<%
	  	 			}
	    			connection.close(); 
	    	 	}catch (Exception e) {
	    			e.printStackTrace();
	    		}
		%>
		
      	</select>
     </form>
     <% 
     	if(request.getParameter("select_temp") != null)
     		temp_name = request.getParameter("select_temp");
		try{
	    		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
	    		statement=connection.createStatement();		
	 %>
     <form action="processques.jsp" method="post">
		<p> Currently selected template - <b><%= temp_name %></b></p>
		<label>Enter the Question</label>
		<input name="question" type="text" /><br>
		<label>Option 1 (50 marks)</label>
		<input name="option1" type="text" /><br>
		<label>Option 2 (40 marks)</label>
		<input name="option2" type="text" /><br>
		<label>Option 3 (30 marks)</label>
		<input name="option3" type="text" /><br>
		<label>Option 4 (20 marks)</label>
		<input name="option4" type="text" /><br>
		<label>Option 5 (10 marks)</label>
		<input name="option4" type="text" /><br>
		<input type="hidden" name="temp_name" value="<%= temp_name %>">  
		<input type="submit" name="single" value="Add Question"/> 
	</form>
    <form action="#" method=post>
	<input type="submit" name="delete" value="Delete"/>
		<%
			if (request.getParameter("delete") != null) {
				sammdao obj = new sammdao();
				
				String[] arr = (String[]) request.getParameterValues("selected");
				obj.questiondel(arr);
			}
		%>

	<div class="table-responsive">
		<table class="table" style="width:400px;">
	        <tr>
	        	<th style="width:20px;">Delete</th>
				<th style="width:20px;">Qid</th>
				<th style="width:20px;">question</th> 
				<th style="width:20px;">option1</th>
				<th style="width:20px;">option2</th>
				<th style="width:20px;">option3</th>
				<th style="width:20px;">option4</th>
				<th style="width:20px;">option5</th>
				<th>Edit</th>
			</tr>
			<%
	         resultSet = statement.executeQuery("select qid,question,option1,option2,option3,option4 from question where qid in (select qid from temp_ques where temp_id ='"+ temp_name +"')");
			 int i = 0;
	         while(resultSet.next()){
	         %>
	         <tr>
		         <td><input style="width:20px;" type="checkbox" name="selected" value='<%=resultSet.getString("qid")%>'/></td>
		  		 <td><input style="width:50px;" type="text" disabled="true" id="<%=i+resultSet.getString("qid")%>" value="<%=resultSet.getString("qid")%>"/></td>
		  		 <td><input style="width:350px;" type="text" disabled="true" id="<%=i+resultSet.getString("question")%>" value="<%=resultSet.getString("question")%>"/></td>
		  		 <td><input style="width:80px;" type="text" disabled="true" id="<%=i+resultSet.getString("option1")%>" value="<%=resultSet.getString("option1")%>"/></td>
		  		 <td><input style="width:80px;" type="text" disabled="true" id="<%=i+resultSet.getString("option2")%>" value="<%=resultSet.getString("option2")%>"/></td>
		  		 <td><input style="width:80px;" type="text" disabled="true" id="<%=i+resultSet.getString("option3")%>" value="<%=resultSet.getString("option3")%>"/></td>
		  		 <td><input style="width:80px;" type="text" disabled="true" id="<%=i+resultSet.getString("option4")%>" value="<%=resultSet.getString("option4")%>"/></td>
		  		 <td><input style="width:80px;" type="text" disabled="true" id="<%=i+resultSet.getString("option5")%>" value="<%=resultSet.getString("option5")%>"/></td>
		  		 <td><input style="width:80px;" type="button" onclick="fun1(this,'<%=i+resultSet.getString("qid")%>','<%=i+resultSet.getString("question")%>','<%=i+resultSet.getString("option1")%>','<%=i+resultSet.getString("option2")%>','<%=i+resultSet.getString("option3")%>','<%=i+resultSet.getString("option4")%>')" value="EDIT"/></td>
		  	 </tr>
			<%
			i++;
			}	
			%>
		</table>  
    	<% 			
    			connection.close(); 
    	 	}catch (Exception e) {
    			e.printStackTrace();
    		}
	 	%>
	 </div>
	 </form>
<%@ include file = "downbar.jsp" %>
<script src="/1st_increment_feedback/js/jquery.js"></script>
<script>
	$(document).ready(function(){
		$("#sel_tem").val("<%= temp_name %>")
	});
</script>
<script>
var prev = []
var oqid = null

function fun1(el,el_id1,el_id2,el_id3,el_id4,el_id5,el_id6){
	if(el.value == "UPDATE"){
		var qname = document.getElementById(el_id2).value
		var op1 = document.getElementById(el_id3).value
		var op2 = document.getElementById(el_id4).value
		var op3 = document.getElementById(el_id5).value
		var op4 = document.getElementById(el_id5).value
		
		var urlstr = "edits/questionEdit.jsp?oqid="+ oqid +"&qname="+ qname+"&op1="+ op1+"&op2="+ op2+"&op3="+ op3+"&op4="+ op4
		window.location.replace(urlstr)
		el.value = 'EDIT'
		
		for(var i; i < prev.length; i++)
			prev[i].disabled = true
	}
	else{	
		if(prev.length != 0){
			for(var i; i < prev.length; i++)
				prev[i].disabled = true	
		}
		oqid = document.getElementById(el_id1).value
	
		var cur = []
			
		cur.push(document.getElementById(el_id2))
		cur.push(document.getElementById(el_id3))
		cur.push(document.getElementById(el_id4))
		cur.push(document.getElementById(el_id5))
		cur.push(document.getElementById(el_id6))

		for(var i=0; i < cur.length; i++){
			cur[i].disabled = false
		}
		
		el.value = "UPDATE"
		
		for(var i=0; i < cur.length; i++)
			prev.push(cur[i])
	}
}
</script>
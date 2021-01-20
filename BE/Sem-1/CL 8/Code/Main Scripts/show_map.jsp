<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@page import="java.sql.*,java.util.*"%>
<!DOCTYPE html>

<%  
	//Teacher_Process.jsp
	Class.forName("com.mysql.jdbc.Driver");
	Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main", "Deva", "dev123456");
	Statement st=conn.createStatement(); 
	Statement st2=conn.createStatement(); 
	String year = request.getParameter("year");
	String div = request.getParameter("div");
	ResultSet result = null;
%>

<script>
	var a = 7
	var title_name = "Show Student Teacher Mappings"
</script>
<%@ include file = "navbar.jsp" %>
<form  action="/1st_increment_feedback/Main Scripts/show_map.jsp" method="POST" name="myform">
    <h3>YEAR</h3>
    <select name="year" id="sel_year" onchange="document.forms['myform'].submit();">
    	<option value=" "> </option>
        
       <% 
        // Take Year 
       ResultSet yr=null;
       yr = st.executeQuery("select distinct year from class");
       while(yr.next())
       {
       %>
           <option value="<%=yr.getString("year")%>"><%=yr.getString("year")%></option>
           
      <%}%>
           
       </select>  
       <br>
       <h3>Division</h3>
       <select name="div" id="sel_div" onchange="document.forms['myform'].submit();">
       	   <option value=" "> </option>
           <%
        // Take Class
           yr = null;
           yr = st.executeQuery("select division from class where year = '"+year+"'");
           while(yr.next())
           {
           %>
               <option value="<%=yr.getString("division")%>"><%=yr.getString("division")%></option>
               
          <%}%>
               
       </select>   

       </form>
		<%  	
				String selectQuery = "select rollno,sid,tid,(select name from teachers where id=tid) as tname,(select subject_name from subject where subject_id=sid) as sname from teacher_class_subject natural join student_cat where cid_year = '" + year + "' and cid_div = " + div;
        		result = st.executeQuery(selectQuery);
		%>
<!--            Result Table   -->
	   <br>
	   <div class="table-responsive">
	   		<table class="table">
                    <thead>
                        <tr>
                        	<th> Delete </th>
                            <th>Roll No</th>
                            <th>Sub Id</th>
                            <th>Teacher Id</th>
                        </tr>
                    </thead>
                    <tbody>
                        <%
                        while(result.next())
                        { 
                        %>
                        <tr>
                        	<td><input type="checkbox" name="selected" value='<%= result.getString("rollno") %>-<%= result.getString("tid") %>-<%= result.getString("sid") %>'/></td>
                            <td><%=result.getInt("rollno")%></td>
                            <td><%=result.getString("tname")%></td>
                            <td><%=result.getString("sname")%></td>
                        </tr>
                        
                        <%
                        }
                        conn.close();
                        %>
                    </tbody>
                </table>
             </div>
                <br/>
    <%@ include file = "downbar.jsp" %>
<script>
	$(document).ready(function(){
		$("#sel_year").val("<%= year%>")
		$("#sel_div").val("<%= div %>")
	});
</script>    
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@page import="java.sql.*,java.util.*"%>
<!DOCTYPE html>

<%  //Teacher_Process.jsp
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
	var title_name = "Student Teacher Mapping"
</script>
<%@ include file = "navbar.jsp" %>
<form  action="/1st_increment_feedback/Main Scripts/Student_Teacher.jsp" method="POST" name="myform">
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
           
           <button type="submit">FETCH</button>  


       </form>

       <h3>MAPPING</h3>


       <form action="Student_teacher_helper.jsp" method="POST">
        <table class="responsive-table-input-matrix">
          <thead>
            <tr>

             <th></th>
             <%
             int count =0;
             result = null;
                        // Taking All Available Category for that Class
             result = st.executeQuery("select name from teachers where id in (select tid from teacher_class_subject where  cid_year='"+year+"' and cid_div = '"+div+"')");
             while(result.next())
                {
                 count++;
                 %><th><%=result.getString("name") %></th><%
             }
             
             %>
             
         </tr>
     </thead>
     <tbody>
        
        <%
        
        session.setAttribute("year", year);
        session.setAttribute("division", div);
        ResultSet std = null;
        
                        // Taking All Students of that Class
                        std = st.executeQuery("select * from student where year='"+year+"' and division='"+div+"'"); // GETTING ROLL NO
                        
                        int k=0,j=0;
                        while(std.next())
                            {
                              %><tr><%
                                j=0;
                                %><td><%=std.getString("rollno")%></td><%
                            // Taking All Available Category for that Class to set it in value
                            result = st2.executeQuery("select * from teacher_class_subject where cid_year='"+year+"'and cid_div = "+div+""); // TO GET SUBJECT ID FOR EACH CHECKBOX VALUE
                            while(result.next())
                            {
                             %><td><input name="<%=String.valueOf(k)+String.valueOf(j)%>" value="<%=std.getString("rollno")+"_"+result.getString("tid")+"_"+result.getString("sid")%>" type="checkbox"></td><%
                             j++;
                         }
                         k++;
                         
                         %></tr><%
                     }
                     
                     conn.close();
                     std.close();
                     %>
                     
                 </tbody>
             </table>
             <button>SUBMIT</button>
         </form>
    <%@ include file = "downbar.jsp" %>
<script>
	$(document).ready(function(){
		$("#sel_year").val("<%= year%>")
		$("#sel_div").val("<%= div %>")
	});
</script>    
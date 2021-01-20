<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@page import="java.sql.*,java.util.*"%>
<!DOCTYPE html>

<%
Class.forName("com.mysql.jdbc.Driver");
Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main", "Deva", "dev123456");
Statement st=conn.createStatement(); 
Statement st2=conn.createStatement(); 
String year = request.getParameter("year");
String div = request.getParameter("div");

int size = 0;

if(request.getParameter("size") != null){
	if(!request.getParameter("size").isBlank())
		size = Integer.parseInt(request.getParameter("size"));
}
else
	size = 0;

ResultSet result = null;
%>

<script>
	var a = 7
	var title_name = "LTL Student Teacher Mapping"
</script>

<%@ include file = "navbar.jsp" %>
<form  action="/1st_increment_feedback/Main Scripts/ltl_map.jsp" method="POST" name="myform">
    <h3>YEAR</h3>
    <select name="year" id="sel_year" onchange="document.forms['myform'].submit();">
    	<option value=" "> </option>
        
       <% 
       // Take Year 
       ResultSet yr=null;
       yr = st.executeQuery("select distinct year from class where year <> 'BE'");
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
       <br>

		<label>Size of batch : </label>
		<input type="text" name="size"/>
		<input type="submit" value="make batches"/>
       </form>

       <h3>MAPPING</h3>

       <form action="ltl_process.jsp" method="POST">
        <table class="responsive-table-input-matrix">
         <thead>
            <tr>
           	<th> Roll no </th>
             <%
             int count =0;
             result = null;
             // Taking All Available Category for that Class
             //result = st.executeQuery("select name from teachers where id in (select tid from teacher_class_subject where  cid_year='"+year+"' and cid_div = '"+div+"')");
             result = st.executeQuery("select (select name from teachers where id = tid) as name, (select subject_name from subject where subject_id=sid) as sname from (select tid,sid from teacher_class_subject where  cid_year='" + year + "' and cid_div = " + div + " and sid in (select subject_id from subject where domain_name = 'LTL')) as T");
             while(result.next())
             {
                 count++;
                 %><th><%=result.getString("name")%>  <%=result.getString("sname")%></th><%
             }            
             %>
             
         </tr>
     </thead>
     <tbody>        
        <%
        session.setAttribute("year", year);
        session.setAttribute("division", div);
        ResultSet std = null;
        int r1=0,r2=-1;
        // Taking All Students of that Class
        std = st.executeQuery("select ran1,ran2 from class where year='"+year+"' and division='"+div+"'"); // GETTING ROLL NO
        
        if(std.next()){
        	r1 = std.getInt(1);
        	r2 = std.getInt(2);
        }
        
        for(int i = r1; i<=r2; i+=size)
        {
        	if(size==0)
        		break;
              %><tr><%
                %><td><%=i + " to " + (i+size-1)%></td><%
            // Taking All Available Category for that Class to set it in value
            result = st2.executeQuery("select * from teacher_class_subject where cid_year='"+year+"'and cid_div = "+div+" and sid in (select subject_id from subject where domain_name = 'LTL')"); // TO GET SUBJECT ID FOR EACH CHECKBOX VALUE
            while(result.next())
            {
             %><td><input name="ltl_check" value="<%=i+"_"+(i+size)+"_"+result.getString("tid")+"_"+result.getString("sid")%>" type="checkbox"></td><%
        	}                         
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
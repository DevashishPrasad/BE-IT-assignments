<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*,java.util.*"%>

<!DOCTYPE html>

<%  //Teacher_Process.jsp
Class.forName("com.mysql.jdbc.Driver");
Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main", "Deva", "dev123456");
Statement st=conn.createStatement(); 
Statement st2=conn.createStatement(); 
String dom = request.getParameter("dom");
String div = request.getParameter("div");
ResultSet result = null;
%>

<script>
	var a = 7
	var title_name = "Student Teacher Mapping"
</script>
<%@ include file = "navbar.jsp" %>
<form  action="/1st_increment_feedback/Main Scripts/be_map.jsp" method="POST" name="myform">
       <br>
       <h3>Division</h3>
       <select name="div" id="sel_div" onchange="document.forms['myform'].submit();">
       	   <option value=" "> </option>
           <%
           ResultSet yr = null;
           yr = st.executeQuery("select division from class where year = 'BE'");
           while(yr.next())
           {
           %>
               <option value="<%=yr.getString("division")%>"><%=yr.getString("division")%></option>
               
          <%
          	}
          %>
               
       </select> 
           
       <select name="dom" id="sel_dom" onchange="document.forms['myform'].submit();">
       	   <option value=" "> </option>
           <%
           yr = null;
           yr = st.executeQuery("select distinct(domain_name) from subject where yr = 'BE'");
           while(yr.next())
           {
           %>
               <option value="<%=yr.getString("domain_name")%>"><%=yr.getString("domain_name")%></option>               
          <%
          	}
          %>
               
       </select> 

       </form>

       <h3>MAPPING</h3>


       <form action="be_process.jsp" method="POST">
        <table class="responsive-table-input-matrix">
          <thead>
            <tr>

             <th> Roll no </th>
             <%
             int count =0;
             result = null;

             // Taking All Available Category for that Class
             result = st.executeQuery("select (select name from teachers where id = tid) as name,sid from (select tid,sid from teacher_class_subject where  cid_year='BE' and cid_div = '"+div+"' and sid in (select sid from subject where domain_name = '" + dom + "')) as T");
             while(result.next())
                {
                 count++;
              %>
              <th><%=result.getString("name")%>  <%=result.getString("sid")%></th><%
             }
             
             %>
             
         </tr>
     </thead>
     <tbody>
        
        <%
        session.setAttribute("division", div);
        ResultSet std = null;
        
                        // Taking All Students of that Class
                        std = st.executeQuery("select * from student where year='BE' and division='"+div+"'"); // GETTING ROLL NO
                        
                        int k=0,j=0;
                        while(std.next())
                            {
                              %><tr><%
                                j=0;
                                %><td><%=std.getString("rollno")%></td><%
                            // Taking All Available Category for that Class to set it in value
                            result = st2.executeQuery("select * from teacher_class_subject where cid_year='BE'and cid_div = "+div+""); // TO GET SUBJECT ID FOR EACH CHECKBOX VALUE
                            while(result.next())
                            {
                             %><td><input name="<%=String.valueOf(k)+String.valueOf(j)%>" value="<%=std.getString("rollno")+"_"+result.getString("tid")+"_"+result.getString("sid")%>" type="checkbox"></td><%
                             j++;
                         }
                         k++;
                         
                         %></tr><%
                     }                     
                    
                     %>
                     
                 </tbody>
             </table>
             <button>SUBMIT</button>
         </form>
     <%
     		String ran1 = "select ran1 from class where year='BE' and division = " + div;
     		ResultSet rss = st.executeQuery(ran1);
     		if(rss.next())
     			ran1 = rss.getString("ran1");
     		else
     			ran1 = "0";
     		
     		String ran2 = "select ran2 from class where year='BE' and division = " + div;
     		rss = st.executeQuery(ran2);
     		if(rss.next())
     			ran2 = rss.getString("ran2");
     		else
     			ran2 = "0";
     		
     		System.out.println(ran1+" "+ran2);
     		String selectQuery = "select * from student_cat where rollno >= " + ran1 + " and rollno <= " + ran2 ;
            rss = st.executeQuery(selectQuery); %>
                            
<!--            Result Table   -->
            <br>
            <div class="table-responsive">
		        <table class="table">
                    <thead>
                        <tr>
                            <th>Roll No</th>
                            <th>Sub Id</th>
                            <th>Teacher Id</th>
                        </tr>
                    </thead>
                    <tbody>
                        <%
                        while(rss.next())
                        { 
                        %>
                        <tr>
                            <td><%=rss.getInt("rollno")%></td>
                            <td><%=rss.getInt("tid")%></td>
                            <td><%=rss.getInt("sid")%></td>
                        </tr>
                        
                        <%
                        }
                        conn.close();
                        std.close();
                        %>
                    </tbody>
                </table>
               <br/>
              </div>
    <%@ include file = "downbar.jsp" %>
<script>
	$(document).ready(function(){
		$("#sel_div").val("<%= div %>")
		$("#sel_dom").val("<%= dom %>")
	});
</script>    
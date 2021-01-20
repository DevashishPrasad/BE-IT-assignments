<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>
<%@page import="jclass.*"%>

<script>
	var a = 1
	var title_name = "Domain"
</script>
<%@ include file = "navbar.jsp" %>
        <form method="post" action="add_domain.jsp">
            <table>
                <tr>
                    <td>Name :</td>
                    <td><input type="text" name="name" pattern='[A-Za-z\\s]*' /></td>
                </tr>               
                <tr>
                    <td><input type="submit" name = "add_but" value="ADD" /></td>       
                    <input type="hidden" name="error" value="" />          
                </tr>
            </table>
        </form> 
                <br>
        <form action="#" method=post>
			<input type="submit" name="delete" value="Delete"/>
				<%
					if (request.getParameter("delete") != null) {
						sammdao obj = new sammdao();
						
						String[] arr = (String[]) request.getParameterValues("selected");
						obj.domaindel(arr);
					}
				
		            String nm = request.getParameter("name");
		            String b_add = request.getParameter("add_but");
		          
		                Class.forName("com.mysql.jdbc.Driver");
		                Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main","Deva","dev123456");
		          
		                Statement st = con.createStatement();
		                int i;
		                if(request.getParameter("error")!=null&&request.getParameter("error")!="")
		                {
		                	%>
		                    <p style="color:#FF0000"><%out.print("INVALID INPUT!");%></p>
		                    <%	
		                }
		                
		                try{
		                	
		                if(b_add != null && nm!="")
		                {
		                 
		                    	i = st.executeUpdate("insert into domain(domain_name) values ('"+nm+"')");
		                    
		                    %>
		                    <p style="color:#0000FF"><%out.print("Domain added");%></p>
		                    <% 
		                }
		                }
		      
		                catch(SQLException e)
		                {
		                	%>
		                    <p style="color:#FF0000"><%out.print("INVALID INPUT!");%></p>
		                    <%	                
		                }
		                
		                Statement st2 = con.createStatement();
		                
		                String selectQuery = "select * from domain order by domain_name";
		                ResultSet rs = st2.executeQuery(selectQuery);
		             %>
		             <div class="table-responsive">
		             <table class="table">
		                 <thead>
		                     <tr>
		                     	<th>Delete</th>
		                         <th>Name</th>
		                         <th>Edit</th>
		                     </tr>
		                 </thead>
		                 <tbody>
		                     <%while(rs.next())
		                     { %>
		                     <tr>
		    			<td><input type="checkbox" name="selected" value='<%= rs.getString("domain_name") %>'/></td>
			    		<td><input type="text" disabled="true" id="<%=rs.getString("domain_name")%>" value="<%=rs.getString("domain_name")%>"/></td>
			    		<td><input type="button" onclick="fun1(this,'<%=rs.getString("domain_name")%>')" value="EDIT"/></td>
			    	</tr>
		                     
		                     <%}%>
		                 </tbody>
		             </table>
	             </div>
             </form>
                <br/>
               
             
    <%@ include file = "downbar.jsp" %>
<script>
var prev = null
var oname = null
function fun1(el,el_id){
	if(el.value == "UPDATE"){
		var name = document.getElementById(el_id).value
		var urlstr = "edits/domainEdit.jsp?oname="+ oname +"&name="+ name
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
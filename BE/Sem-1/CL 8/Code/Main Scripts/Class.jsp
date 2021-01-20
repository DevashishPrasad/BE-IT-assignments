<%@page import="java.sql.*"%>
<%@page import="javax.sql.*"%>
<%@page import="jclass.*"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<script>
	var a = 2
	var title_name = "Class"
</script>

<%@ include file = "navbar.jsp" %>

<p><% if(request.getParameter("error")!=null) out.print(request.getParameter("error"));%></p>

<form name="form1" action="Class.jsp" method="post">

<center>
		<label>YEAR OF ENGINEERING :</label>
        <select name=year>
	        <option value=""></option>
	        <option value="FE">FE</option>
	        <option value="SE">SE</option>
	        <option value="TE">TE</option>
		    <option value="BE">BE</option>	
         </select>
         <br>
         <br>
</center>
          <center><label>Division :&nbsp;</label><input id="div" type="number" placeholder="Division" name="div" min="1" max="20"></input><br><br></center>
<center><label>Dept :&nbsp;</label><select name="dept">
									<option value=""></option>
									 <option value="CS">C.S.</option>
          							<option value="IT">I.T.</option>
          							<option value="EnTC">ENTC</option>
									<option value="AS">A.S.</option>

</select><br><br></center>
<center><label>RANGE :&nbsp;</label><input id="range1" type="number" placeholder="RANGE OF STUDENTS" name="ran1" min="1"></input>&nbsp;TO <input id="range2" type="number" placeholder="RANGE OF STUDENTS" name="ran2" min="1"></input><br><br></center>
<center><input type="submit" name="ADD1" value="ADD"></input></center>

</form>

<%

class class1{
	public String year;
	public String division;
	public String dept;
	public String range1;
	public String range2;
	public String s;
	public String d;
	
	class1(){
		year=null;
		division=null;
		dept=null;
		range1=null;
		range2=null;
		s=null;
		d=null;		
	}
}

class1 myclass = new class1();

Class.forName("com.mysql.jdbc.Driver");
Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main","Deva","dev123456");
myclass.year=request.getParameter("year");
myclass.division=request.getParameter("div");
myclass.dept=request.getParameter("dept");
myclass.range1=request.getParameter("ran1");
myclass.range2=request.getParameter("ran2");
myclass.s=(String)request.getParameter("ADD1");
myclass.d=(String)request.getParameter("DELETE1");
Statement st1 = con.createStatement();
Statement st2 = con.createStatement();
ResultSet rs1;
if(request.getParameter("error")!=null)
{
	%>
    <p style="color:#FF0000"><%out.print("INVALID INPUT!");%></p>
    <%	
}
try
{
	if((myclass.year !="") && (myclass.division !=null) && (myclass.dept !="") && ((Integer.parseInt(myclass.range1))<(Integer.parseInt(myclass.range2))) && (myclass.s!=null))
	{
		st1.executeUpdate("insert into class values('"+myclass.year+"',"+myclass.division+",'"+myclass.dept+"',"+myclass.range1+","+myclass.range2+")");
		out.println("CLASS ADDED");
		%>
	    <p style="color:#0000FF"><%out.println("CLASS ADDED");%></p>
	    <%	          
	}
	
	else if((myclass.year!="")&&(myclass.division!=null)&&(myclass.dept!="")&&(myclass.range1!=null)&&(myclass.d!=null))
	{
		st2.executeUpdate("delete from class where division="+myclass.division+";");
		out.println("CLASS DELETED");
	}
	
}
catch(SQLException e)
{
	%>
    <p style="color:#FF0000"><%out.print("INVALID INPUT!");%></p>
    <%	          
}



%>
<br><br>
<center>
<form action="#" method=post>
			<input type="submit" name="delete" value="Delete"/>
				<%
					if (request.getParameter("delete") != null) {
						sammdao obj = new sammdao();
						
						String[] arr = (String[]) request.getParameterValues("selected");
						obj.classdel(arr);
					}
				if(request.getParameter("error")!=null)
				{
					%>
					
					<p>*UPDATE FAILED DUE TO INCONSISTENCY IN DATA</p>
					<%
				}
				%>

<div class="table-responsive">
<table class="table">
   <tr>
		<th>Delete</th>   
        <th>YEAR</th>
        <th>DIVISION</th>
        <th>DEPT</th>
        <th>FROM</th>
        <th>TO</th>
        <th>Edit</th>
   </tr>
   
<% 
ResultSet rs2= st2.executeQuery("select * from class");
out.println("\n");
int i = 0;
while(rs2.next())
{
%>
	<tr>
		<td><input style="width:70px;" type="checkbox" name="selected" value='<%=rs2.getString(1)%>#<%=rs2.getInt(2)%>'/></td>
  		<td><input style="width:70px;" type="text" disabled="true" id="<%=i+rs2.getString(1)%>" value="<%=rs2.getString(1)%>"/></td>
  		<td><input style="width:70px;" type="text" disabled="true" id="<%=i+rs2.getString(2)%>" value="<%=rs2.getString(2)%>"/></td>
  		<td><input style="width:70px;" type="text" disabled="true" id="<%=i+rs2.getString(3)%>" value="<%=rs2.getString(3)%>"/></td>
  		<td><input style="width:80px;" type="text" disabled="true" id="<%=i+rs2.getString(4)%>" value="<%=rs2.getString(4)%>"/></td>
  		<td><input style="width:90px;" type="text" disabled="true" id="<%=i+rs2.getString(5)%>" value="<%=rs2.getString(5)%>"/></td>
  		<td><input style="width:90px;" type="button" onclick="fun1(this,'<%=i+rs2.getString(1)%>','<%=i+rs2.getString(2)%>','<%=i+rs2.getString(3)%>','<%=i+rs2.getString(4)%>','<%=i+rs2.getString(5)%>')" value="EDIT"/></td>
  	</tr>
<% 
	i++;
}
%>
</center>
</table>
</div>
</form>
<%@ include file = "downbar.jsp" %>
<script>
var prev = []
var oyear = null
var odiv = null

function fun1(el,el_id1,el_id2,el_id3,el_id4,el_id5){
	if(el.value == "UPDATE"){
		var year = document.getElementById(el_id1).value
		var div = document.getElementById(el_id2).value
		var dept = document.getElementById(el_id3).value
		var ran1 = document.getElementById(el_id4).value
		var ran2 = document.getElementById(el_id5).value
		
		var urlstr = "edits/ClassEdit.jsp?oyear="+ oyear +"&odiv="+ odiv+"&year="+ year+"&div="+ div+"&dept="+ dept+"&ran1="+ ran1+"&ran2="+ ran2
		window.location.replace(urlstr)
		el.value = 'EDIT'
		
		for(var i; i < prev.length; i++)
			prev[i].disabled = true
			
		oyear = null
		odiv = null
	}
	else{	
		if(prev.length != 0){
			for(var i; i < prev.length; i++)
				prev[i].disabled = true	
		}
		oyear = document.getElementById(el_id1).value
		odiv = document.getElementById(el_id2).value
	
		var cur = []
			
		cur.push(document.getElementById(el_id1))
		cur.push(document.getElementById(el_id2))
		cur.push(document.getElementById(el_id3))
		cur.push(document.getElementById(el_id4))
		cur.push(document.getElementById(el_id5))

		for(var i=0; i < cur.length; i++){
			cur[i].disabled = false
		}
		
		el.value = "UPDATE"
		
		for(var i=0; i < cur.length; i++)
			prev.push(cur[i])
	}
}
</script>
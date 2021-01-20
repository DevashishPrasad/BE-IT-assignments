<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>

<%
	// Initialize database connection parameters
	String id = request.getParameter("userid");
	String driver = "com.mysql.jdbc.Driver";
	String connectionUrl = "jdbc:mysql://localhost:3306/";
	String database = "feedback_main";
	String userid = "Deva";
	String password = "dev123456";
	CallableStatement cstmt = null;
	
	try {
		Class.forName(driver);
	} catch (ClassNotFoundException e) {
		e.printStackTrace();
	}
	
	Connection con = null;
	Statement statement = null;
	ResultSet resultSet = null;
	
	Class.forName("com.mysql.jdbc.Driver");
	con = DriverManager.getConnection(connectionUrl+database, userid, password);
%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<script src="/1st_increment_feedback/js/jquery.js"></script>
<script type="text/javascript">
<%
try{
    Statement st = con.createStatement();
    Statement st2 = con.createStatement();
    int total_stud=0;
    String SQL = "{call initfeed()}";
    cstmt = con.prepareCall (SQL);
    cstmt.executeQuery();
    
    String Capital_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    String Small_chars = "abcdefghijklmnopqrstuvwxyz"; 
    String numbers = "0123456789"; 
    String symbols = "!@#$%^&*_=+-/.?<>)";

    String values = Capital_chars + Small_chars + 
                    numbers + symbols; 

    // Using random method 
    Random rndm_method = new Random(); 

    char[] rand_pass; 
    
	ResultSet rs = st.executeQuery("select count(*) as num_stud from student");
    rs.next();
    total_stud = rs.getInt("num_stud");
    ResultSet rs2 = st2.executeQuery("select rollno from student");
    %>
    
    $(document).on('click', '#passbtn', function(){ 
        alert("button is clicked");
  	   	var no = 1;	 
  	   	<%while(rs2.next()){%>
    	
    	if(no<=<%=rs.getString("num_stud")%>){
    		<%
	   		 	rand_pass = new char[6];
		   		for (int i = 0; i < 6; i++) 
		   	    { 
		   	        rand_pass[i] = values.charAt(rndm_method.nextInt(values.length()));
		   	    } 
	   		 	System.out.println(rs2.getInt(1));
	   		 	System.out.println(rand_pass);
	   		 	String passgen = rand_pass.toString();
	   		 	System.out.println(passgen);
	   		 	String query = "update student set pass = ? where rollno = "+rs2.getInt(1);
	   		 	
	   		 	PreparedStatement st3 = con.prepareStatement(query);
	   		 	st3.setString(1, passgen);
	   		 	
	   		 	int updates = st3.executeUpdate();
	   		 %>
    	}
    	no++;
    		
    	<%}%>
    });
   
function genpass(){
	var randomstring="";
	for(var i=0;i<10;i++){
		randomstring = Math.random().toString(36).slice(-8);
	}
}

</script>
	
<%
st2 = con.createStatement();

String selectQuery = "select * from student order by rollno";
rs = st2.executeQuery(selectQuery);
%>
<div >
<table border="1">
 <thead>
     <tr>
     	 <th>ROLLNO</th>
         <th>YEAR</th>
         <th>DIVISION</th>
         <th>PASSWORD</th>
     </tr>
 </thead>
 <tbody>
     <%while(rs.next())
     { %>
     <tr>
		<td><%=rs.getString("rollno")%></td>
		<td><%=rs.getString("year")%></td>
		<td><%=rs.getString("division")%></td>
		<td><%=rs.getString("pass")%></td>
  	 </tr>
     
     <%}%>
 </tbody>
</table>
</div>
</form>
<br/>
<%
con.close();
}
catch(Exception e)
{
e.printStackTrace();
}
%>

</html>
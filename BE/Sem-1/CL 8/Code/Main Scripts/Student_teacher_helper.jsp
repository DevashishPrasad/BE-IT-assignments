<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*,javax.sql.*"%>

<%
        Class.forName("com.mysql.jdbc.Driver");
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main", "Deva", "dev123456");
        Statement st=conn.createStatement();
        String div =(String)session.getAttribute("division");
        String year =(String)session.getAttribute("year");
       
        ResultSet rs = st.executeQuery("select * from student where year='"+year+"' and division='"+div+"'");      
        
        int klim =0,jlim=0;
        rs.next();
        rs.last();
        klim = rs.getRow();
        rs.first();

        ResultSet rs1 = st.executeQuery("select * from teacher_class_subject where cid_year='"+year+"'and cid_div = "+div+"");

        rs1.next();
        rs1.last();
        jlim = rs1.getRow();
        rs1.first();
        int k,j;
       
        for( k=0;k<klim;k++){
            for( j=0;j<jlim;j++)
            {
                String val = request.getParameter(String.valueOf(k)+String.valueOf(j));
                if(val != null)
                {
                  
                   String[] arrOfval = val.split("_",3);
                  st.execute("DELETE FROM `student_cat` WHERE `student_cat`.`rollno` = "+Integer.parseInt(arrOfval[0])+"");
                   st.executeUpdate("INSERT INTO `student_cat` (`rollno`, `tid`, `sid`) VALUES("+arrOfval[0]+","+arrOfval[1]+","+arrOfval[2]+")");
                }
                
               
            
            }}
    
%>
<%
            String selectQuery = "select * from student_cat order by rollno";
            ResultSet rss = st.executeQuery(selectQuery); %>
                            
<!--            Result Table   -->
            <br><table border="1" style="text-align:center">
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
                        %>
                    </tbody>
                </table><br/>
<% 
		response.sendRedirect("Student_Teacher.jsp");
%>
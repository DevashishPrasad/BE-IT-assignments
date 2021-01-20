
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*,javax.sql.*"%>

<%
Class.forName("com.mysql.jdbc.Driver");
Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main", "Deva", "dev123456");
 Statement st=conn.createStatement();
        String classid =(String)session.getAttribute("classid");
        out.print(classid);
        ResultSet rs = st.executeQuery("select * from student where classID='"+classid+"'");      
        
        int klim =0,jlim=0;
        rs.next();
        rs.last();
        klim = rs.getRow();
        rs.first();
//        while(rs.next())
//           klim++;
//       int
        ResultSet yr = st.executeQuery("select * from class where year='"+classid+"'");
        yr.next();
        int year = yr.getInt("yr");
         out.print(yr);
        yr.close();
         ResultSet rs1 = st.executeQuery("select * from subject where yr="+year+"");
//        while(rs1.next()){
//           jlim++;
//        }
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
                  
                   String[] arrOfval = val.split("_",2);
                    st.execute("delete * from student_subject where rollno = '"+arrOfval[0]+"'");
                   st.executeUpdate("INSERT INTO student_subject(rollno,subject_id) VALUES("+arrOfval[0]+","+arrOfval[1]+")");
                }
                out.print("DONE");
               
            
            }}
    
        %><%
            String selectQuery = "select * from student_subject order by rollno";
            ResultSet rss = st.executeQuery(selectQuery); %>
                            
                <br><table border="1" style="text-align:center">
                    <thead>
                        <tr>
                            <th>Roll No</th>
                            <th>Sub Id</th>
                        </tr>
                    </thead>
                    <tbody>
                        <%while(rss.next())
                        { %>
                        <tr>
                            <td><%=rss.getInt("rollno")%></td>
                            <td><%=rss.getInt("subject_id")%></td>
                        </tr>
                        
                        <%}%>
                    </tbody>
                </table><br/>
<%
    
%>
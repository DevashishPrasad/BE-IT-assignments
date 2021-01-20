<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*,javax.sql.*"%>

<%
        Class.forName("com.mysql.jdbc.Driver");
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main", "Deva", "dev123456");
        Statement st=conn.createStatement();
        String div =(String)session.getAttribute("division");
        String year =(String)session.getAttribute("year");
       
        String[] selectedChecks = request.getParameterValues("ltl_check");
        
        System.out.println(selectedChecks);
        for(int i = 0; i < selectedChecks.length ;i++){
        	String[] arrOfval = selectedChecks[i].split("_",4);
        	if(arrOfval == null)
        		continue;
        	for(int j = Integer.parseInt(arrOfval[0]);j<Integer.parseInt(arrOfval[1]);j++){
        			st.executeUpdate("INSERT INTO `student_cat` (`rollno`, `tid`, `sid`) VALUES("+j+","+arrOfval[2]+","+arrOfval[3]+")");
        	}
        }
        
        /* ResultSet rs = st.executeQuery("select * from student where year='"+year+"' and division='"+div+"'");
        
        int klim=0,jlim=0;
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
                
               
            
            }} */
    
%>

<% 
		response.sendRedirect("ltl_map.jsp");
%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*,javax.sql.*"%>

<%
        Class.forName("com.mysql.jdbc.Driver");
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/feedback_main", "Deva", "dev123456");
        Statement st=conn.createStatement();
        Statement st1=conn.createStatement();
        String div =(String)session.getAttribute("select_div");
        String year =(String)session.getAttribute("select_year");
        String teacher = (String)session.getAttribute("select_teacher");
        String subject = request.getParameter("select_subject");
        String cat_id = " ";
        int nostud = 1;
        
        String selectQuery = "select cat_id from teacher_class_subject where tid="+teacher+" and cid_year='"+year+"' and cid_div ="+div+" and sid="+subject;
        ResultSet rs = st.executeQuery(selectQuery);
        
        if(rs.next())
			cat_id = rs.getString("cat_id");
        
		selectQuery = "select name from teachers where id="+teacher;
		rs = st.executeQuery(selectQuery);
		
        if(rs.next())
			teacher = rs.getString("name");
        
		selectQuery = "select subject_name from subject where subject_id="+subject;
		rs = st.executeQuery(selectQuery);
        
        if(rs.next())
			subject = rs.getString("subject_name");

		selectQuery = "select ran1,ran2 from class where year='"+year+"' and division="+div;
		rs = st.executeQuery(selectQuery);
        
        if(rs.next()){
			int r1 = rs.getInt("ran1");
			int r2 = rs.getInt("ran2");
			nostud = r2-r1;
			System.out.println("++++++++++++++"+nostud);
        }
        int total = 0;
%>

<script src="/1st_increment_feedback/js/jquery.js"></script>
	
	<script>
		function check(){
			  window.print()	
			  /* var pdf = new jsPDF();
			  pdf.addHTML($("body"), 5, 5, function() {
			    pdf.save('page.pdf');
			  });*/
			  } 
	</script>		
	
<body>
	<center><img src="theme-assets/images/logo/pict.jpg" style="height:120px;"/>
	<h1>PICT FEEDBACK REPORT</h1>
	<label>--------------- <b>TEACHER : </b></label><label> <%= teacher %> ---------------</label>
	<label><b>CLASS : </b></label><label> <%= year %> <%= div %> ---------------</label>
	<label><b>SUBJECT : </b></label><label> <%= subject %> ---------------</label>
	</center>
	<%	
	  	selectQuery = "select qid,score from feedback where cat_id="+cat_id;
    	rs = st.executeQuery(selectQuery);
    	int i;
    	for(i=1;rs.next();i++){
    		int qid = rs.getInt("qid");
    		selectQuery = "select question from question where qid="+qid;
    		ResultSet rs1 = st1.executeQuery(selectQuery);
			String qname = " ";
    		if(rs1.next())
    			qname = rs1.getString("question");
    		
	%>
	<h4><%= i %>) <%= qname %></h3>
	<p>Score : <%= rs.getInt("score") %></p>	
	
	<%
		total += rs.getInt("score");	
    	} 
    %>
	
	<p>(* Each question mark out of : <%= 40*nostud %> )</p>
	<h2> Total Score : <%= total %>/<%= i*40*nostud %> or <% 
	out.println((float)((float)total/(float)(i*40*nostud))*100+"%"); 
	%>
	</h2>	
	<button id="cmd" onclick="check()">Download PDF</button>
</body>
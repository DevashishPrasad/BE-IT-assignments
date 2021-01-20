<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>    

<%
	// Initialize database connection parameters
	String driver = "com.mysql.jdbc.Driver";
	String connectionUrl = "jdbc:mysql://localhost:3306/";
	String database = "feedback_main";
	String userid = "Deva";
	String password = "dev123456";
	
	try {
		Class.forName(driver);
	} catch (ClassNotFoundException e) {
		e.printStackTrace();
	}
	
	Connection connection = null;
	Statement statement = null;
	ResultSet resultSet = null;
	int maxid = 0;
	String tempid = "";
	
	class Question{
		public String temp_name;
		public String text;
		public String option1;
		public String option2;
		public String option3;
		public String option4;
		public String option5;
		
		Question(){
			
		}
	}
	
	Question question = new Question();
	
	// get parameters from the previous page
	question.temp_name = request.getParameter("temp_name");
	question.text = request.getParameter("question");
	question.option1 = request.getParameter("option1");
	question.option2 = request.getParameter("option2");
	question.option3 = request.getParameter("option3");
	question.option4 = request.getParameter("option4");
	question.option5 = request.getParameter("option5");
	
	try{
		connection = DriverManager.getConnection(connectionUrl+database, userid, password);
		statement=connection.createStatement();
		
		// Get the max ques_id
		String sql = "select max(qid) as mqid from question";
		resultSet = statement.executeQuery(sql);
		if(resultSet.next()){
			String temp = resultSet.getString("mqid");
			if(temp != null)
				maxid = Integer.parseInt(temp);
			else
				maxid = 0;
		}
		else
			maxid = 0;
	
		// Insert into the question table
		sql = "insert into question values ('" + question.text + "','" + question.option1 + "','" + question.option2 + "','" + question.option3 + "','" + question.option4 + "',"  + "','" + question.option5 + "'," + (maxid+1) + ")";		
		statement.executeUpdate(sql);
		
		// Insert into the temp_ques mapping
		sql = "insert into temp_ques values ('" + question.temp_name + "'," + (maxid+1) + ")";		
		statement.executeUpdate(sql);
		
		connection.close();

		response.sendRedirect("addquestion.jsp?status=Question Added sucessfully&select_temp="+question.temp_name);

	}catch (Exception e) {
		e.printStackTrace();
	}
%>

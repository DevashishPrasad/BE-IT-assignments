<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<script>
	var a = 0
	var title_name = "Instructions"
</script>
<%@ include file = "navbar.jsp" %>
<ul>
<li>Go through the sequence as given in the NavBar</li>
<li>Once all Entities as filled go for mapping screens</li>
<li>Once all mappings are done click on the button TAKE FEEDBACK</li>
<li>Give the random passwords to the students</li>
<li>Students will login from student side URL and give answers to the questions</li>
<li>Once students have given feedback you can generate reports of teachers in PDF format</li>
</ul>
<form action="randompass.jsp" target="_blank">
<input type="submit" value="TAKE FEEDBACK"/>
</form>
<%@ include file = "downbar.jsp" %>
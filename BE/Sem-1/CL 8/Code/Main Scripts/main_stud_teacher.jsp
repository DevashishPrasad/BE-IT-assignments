<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.sql.*"%>
<%@page import="java.util.*"%>
<%@page import="jclass.*"%>

<script>
	var a = 7
	var title_name = "Select Mapping Type"
</script>
<%@ include file = "navbar.jsp" %>


<section id="header-footer">
	<div class="row match-height">
		<div class="col-lg-4 col-md-12">
			<div class="card">
				<div class="card-body">
					<a href="ltl_map.jsp">LTL Mapping</a>
				</div>
			</div>
		</div>
		<div class="col-lg-4 col-md-12">
			<div class="card">
				<div class="card-body">
					<a href="be_map.jsp">BE Mapping</a>
				</div>
			</div>
		</div>
		<div class="col-lg-4 col-md-12">
			<div class="card">
				<div class="card-body">
					<a href="show_map.jsp">Show Mappings</a>
				</div>
			</div>
		</div>
	</div>
</section>
<%@ include file = "downbar.jsp" %>

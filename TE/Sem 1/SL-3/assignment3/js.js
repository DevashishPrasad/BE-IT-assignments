function checknumbers(thestr){
	var number = /[0-9]/
	return number.test(thestr)
}
function checkspecialchars(thestr){
	var special = /[ !@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]/
	return special.test(thestr)
}
function checkname(thestr){
	if(thestr.length == 0){
		alert("The field cannot be empty")
		return false
	}
	if(checkspecialchars(thestr)){
		alert("The field cannot contain special characters")
		return false
	}
	if(checknumbers(thestr)){
		alert("The field cannot contain numbers")
		return false
	}
	return true
}
function checkaddress(thestr){
	if(thestr.length == 0){
		alert("The field cannot be empty")
		return false
	}
	else if(checkspecialchars(thestr)){
		alert("The field cannot contain special characters")
		return false
	}
	return true
}

function validate(){
	
	var val = document.getElementById("val");
	var first = document.getElementById("First").value;
	var middle = document.getElementById("Middle").value;
	var last = document.getElementById("Last").value;

	// Name Validation
	if(!checkname(first)){
		val.innerHTML = "Please Enter a Valid First Name"
		return false
	}
	if(!checkname(middle)){
		val.innerHTML = "Please Enter a Valid Middle Name"
		return false
	}
	if(!checkname(last)){
		val.innerHTML = "Please Enter a Valid Last Name"
		return false
	}	

	var street = document.getElementById("Street").value;
	var area = document.getElementById("Area").value;
	var city = document.getElementById("City").value;
	var state = document.getElementById("State").value;
	var country = document.getElementById("Country").value;
	
	// Address validation
	if(!checkaddress(street)){
		val.innerHTML = "Please Enter a Valid Street Name"
		return false
	}
	if(!checkaddress(area)){
		val.innerHTML = "Please Enter a Valid Area Name"
		return false
	}
	if(!checkname(city)){
		val.innerHTML = "Please Enter a Valid City Name"
		return false
	}
	if(!checkname(state)){
		val.innerHTML = "Please Enter a Valid State Name"
		return false
	}
	if(!checkname(country)){
		val.innerHTML = "Please Enter a Valid Country Name"
		return false
	}

	//Radio
	if(!document.getElementById("male").checked || !document.getElementById("female")){
		alert("Please select Gender")
		val.innerHTML = "Please select your Gender"
		return false
	}
	return true
}

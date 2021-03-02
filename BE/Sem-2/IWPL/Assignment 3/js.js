/* ALL VALIDATION FUNCTIONS */

// REGREX FUNCTIONS
function checknumbers(thestr){
	var number = /[0-9]/
	return number.test(thestr)
}
function checkspecialchars(thestr){
	var special = /[ !@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]/
	return special.test(thestr)
}
function checkchars(thestr){
	var char = /[a-zA-Z]/
	return char.test(thestr)
}

// CHECK COPY PASTE EVENTS 
function checkmenu(event){
	return false
}
function checkctrl(event){
	if (event.ctrlKey) {
		alert("The CTRL key is not allowed!");
		return false
	}
}

// SINGLE FIELD VALIDATION FUNCTIONS
function checkname(thestr){
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
	if(checkspecialchars(thestr)){
		alert("The field cannot contain special characters")
		return false
	}
	return true
}

function checkpassword(thestr){
	if(thestr.length < 8){
		alert("Password cannot have less than 8 characters")
		return false
	}
	if(!checkchars(thestr)){
		alert("Password must have one alphabetical character")
		return false
	}
	if(!checknumbers(thestr)){
		alert("Password must have one digit")
		return false
	}
	if(!checkspecialchars(thestr)){
		alert("Password must have one special character")
		return false
	}
	return true
}

// THE MAIN VALIDATION FUNCTION
function validate(){
	
	var val = document.getElementById("val");
	var first = document.getElementById("First");
	var middle = document.getElementById("Middle");
	var last = document.getElementById("Last");

	// Name Validation
	if(!checkname(first.value)){
		val.innerHTML = "Please Enter a Valid First Name"
		first.style.borderColor = "#FF0000"
		return false
	}
	if(!checkname(middle.value)){
		val.innerHTML = "Please Enter a Valid Middle Name"
		middle.style.borderColor = "#FF0000"
		return false
	}
	if(!checkname(last.value)){
		val.innerHTML = "Please Enter a Valid Last Name"
		last.style.borderColor = "#FF0000"
		return false
	}	

	var street = document.getElementById("Street").value;
	var area = document.getElementById("Area").value;
	var city = document.getElementById("City").value;
	var state = document.getElementById("State").value;
	var country = document.getElementById("Country").value;
	
	// Address validation
	if(!checkaddress(street.value)){
		val.innerHTML = "Please Enter a Valid Street Name"
		street.style.borderColor = "#FF0000"
		return false
	}
	if(!checkaddress(area.value)){
		val.innerHTML = "Please Enter a Valid Area Name"
		area.style.borderColor = "#FF0000"
		return false
	}
	if(!checkname(city.value)){
		val.innerHTML = "Please Enter a Valid City Name"
		city.style.borderColor = "#FF0000"
		return false
	}
	if(!checkname(state.value)){
		val.innerHTML = "Please Enter a Valid State Name"
		state.style.borderColor = "#FF0000"
		return false
	}
	if(!checkname(country.value)){
		val.innerHTML = "Please Enter a Valid Country Name"
		country.style.borderColor = "#FF0000"
		return false
	}

	// Radio
	if(!document.getElementById("male").checked || !document.getElementById("female")){
		alert("Please select Gender")
		val.innerHTML = "Please select your Gender"
		return false
	}

	var phone = document.getElementById("phone")
	var pass1 = document.getElementById("pass1")
	var pass2 = document.getElementById("pass2")

	// email, phone and password
	if(phone.value.length != 10){
		alert("Phone number must have exactly 10 digits")
		val.innerHTML = "Please Enter a Valid Phone Number"
		phone.style.borderColor = "#FF0000"
		return false
	}
	if(!checkpassword(pass1.value)){
		val.innerHTML = "Please Enter a valid password"
		pass1.style.borderColor = "#FF0000"
		return false
	}
	if(!checkpassword(pass2.value)){
		val.innerHTML = "Please Enter a valid password"
		return false
	}
	if(pass1.value != pass2.value){
		alert("Both passswords should match")
		val.innerHTML = "Passwords do not match"
		pass2.style.borderColor = "#FF0000"
		return false
	}
	return true
}

// THE ONBLUR EVENTS
function blurcheckname(el){
	if(checkspecialchars(el.value)){
		alert("The field cannot contain special characters")
		el.style.borderColor = "#FF0000"
		return
	}
	if(checknumbers(el.value)){
		alert("The field cannot contain numbers")
		el.style.borderColor = "#FF0000"
		return
	}
	if(el.value.length != 0){
		el.style.borderColor = "#00FF00"
	}
}
function blurcheckaddress(el){
	if(checkspecialchars(el.value)){
		alert("The field cannot contain special characters")
		el.style.borderColor = "#FF0000"
		return
	}
	if(el.value.length != 0){
		el.style.borderColor = "#00FF00"
	}
}
function blurcheckpassword(el){
	if(el.value.length < 8){
		alert("Password cannot have less than 8 characters")
		el.style.borderColor = "#FF0000"
		return
	}
	if(!checkchars(el.value)){
		alert("Password must have one alphabetical character")
		el.style.borderColor = "#FF0000"
		return
	}
	if(!checknumbers(el.value)){
		alert("Password must have one digit")
		el.style.borderColor = "#FF0000"
		return
	}
	if(!checkspecialchars(el.value)){
		alert("Password must have one special character")
		el.style.borderColor = "#FF0000"
		return
	}
	if(el.value.length != 0){
		el.style.borderColor = "#00FF00"
	}
	
}
function blurchecknumber(el){
	if(el.value.length != 10){
		alert("Phone number must have exactly 10 digits")
		val.innerHTML = "Please Enter a Valid Phone Number"
		el.style.borderColor = "#FF0000"
		return
	}
	if(el.value.length != 0){
		el.style.borderColor = "#00FF00"
	}
}
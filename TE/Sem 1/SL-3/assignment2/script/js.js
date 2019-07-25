window.onscroll = function() {myFunction()};

var nav = document.getElementById("thenav")
var hid = document.getElementsByClassName("hidden")
var sticky = nav.offsetTop;

function myFunction() {
	var offset = 145 - window.pageYOffset
	console.log(offset)
	if(offset > 40){
		for(var x=0;x<hid.length;x++){
		    hid[x].style.top = offset.toString() + "px"
		}
	}
	else{
		for(var x=0;x<hid.length;x++){
		    hid[x].style.top = "40px"
		}
	}
	if(window.pageYOffset >= sticky){
		nav.classList.add("sticky")
	}
	else{
		nav.classList.remove("sticky")
	}
}

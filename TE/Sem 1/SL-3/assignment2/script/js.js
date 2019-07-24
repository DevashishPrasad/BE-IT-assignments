window.onscroll = function() {myFunction()};

var nav = document.getElementById("thenav")
var hid = document.getElementsByClassName("hidden")
var sticky = nav.offsetTop;

function myFunction() {
  if (window.pageYOffset >= sticky) {
  	nav.classList.add("sticky")
  	for(var x=0;x<hid.length;x++){
	  	hid[x].style.top = "40px"
	 }
  } else {
	nav.classList.remove("sticky")
  	for(var x=0;x<hid.length;x++){
		hid[x].style.top = "145px"
	}
  }
}

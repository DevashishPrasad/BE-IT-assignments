window.onscroll = function() {myFunction()};

var nav = document.getElementById("thenav")
var sticky = nav.offsetTop;

function myFunction() {
  if (window.pageYOffset >= sticky) {
  	nav.classList.add("sticky")
    /*nav.style.position = "fixed"
    nav.style.top = "0px"*/
    console.log("he")
  } else {
	nav.classList.remove("sticky")
    /*nav.style.position = "static"*/
    console.log("she")
  }
}

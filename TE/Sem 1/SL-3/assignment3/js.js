function highlight(el){
	name = el.name

	// name
	if(el.value == 'First' || el.value == 'Middle' || el.value == 'Last'){
		el.value=''
	}
	// address
	if(el.value == 'Street' || el.value == 'Area' || el.value == 'City' || el.value == 'State' || el.value == 'Country'){
		el.value=''
	}
}

function lowlight(el){
	if(el.value==''){
		el.value=name
	}
}

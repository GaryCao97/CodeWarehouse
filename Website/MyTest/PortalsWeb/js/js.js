// JavaScript Document
function show(start,end,index){
	for(i = start;i <= end;i++){
		if(i == index){
			document.getElementById("list-btn-" + i).classList.add("on");
            document.getElementById("list-btn-" + i + "-content").style.display = "block";
		}else{
			document.getElementById("list-btn-" + i).classList.remove("on");
            document.getElementById("list-btn-" + i + "-content").style.display = "none";
		}
	}
}
function change(index){
	for(i = 1;i <= 6;i++){
		if(i == index){
			document.getElementById("web-btn-" + i).classList.add("on");
            document.getElementById("web-btn-" + i + "-content").style.display = "block";
		}else{
			document.getElementById("web-btn-" + i).classList.remove("on");
            document.getElementById("web-btn-" + i + "-content").style.display = "none";
		}
	}
}

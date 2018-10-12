// JavaScript Document
var tChange = document.getElementById('photo-change-show').getElementsByTagName('img');
var tPoint = document.getElementById('change-point').getElementsByTagName('div');
for(i = 0;i　< tChange.length;i++){
	tPoint[i].index = i;
	tPoint[i].onclick = function(){
		for(m = 0;m < tChange.length;m++){
			tPoint[m].className = '';
			tChange[m].className = '';
		}
		this.className = 'on';
		tChange[this.index].className = 'photo-on';
	}
}

function photoChange(){
	var oChange = document.getElementById('photo-change-show').getElementsByTagName('img');
	var oPoint = document.getElementById('change-point').getElementsByTagName('div');
	var now,next;
	for(n = 0;n < oChange.length;n++){
		if(oChange[n].className == 'photo-on'){
			now = n;
		}
	}
	if(now == (oChange.length - 1)){
		next = 0;
	}else {
		next = now+1;
	}
	oChange[now].className = '';
	oChange[next].className = 'photo-on';
	oPoint[now].className = '';
	oPoint[next].className = 'on';
}

setInterval(function(){photoChange();},3000);
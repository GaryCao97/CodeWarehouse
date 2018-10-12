// JavaScript Document
var onMoving = document.getElementsByClassName('every-photo');
var oThis = document.getElementById('photo-show');
var perWa = onMoving[1].offsetWidth * 1.11;
var perWb = onMoving[1].offsetWidth;
var perH = onMoving[1].offsetHeight;
var perTop = (oThis.offsetHeight - perH)/2;
for (var i = 0; i < onMoving.length; i++){
                
	onMoving[i].style.top = perTop + 'px';
	if(i > 0){
                
		onMoving[i].style.left = onMoving[i-1].offsetLeft + perWa + 'px';
	}
}
function Moving(){
	var tParent = document.getElementById('photo-show');
	tParent.time = setInterval(function(){
		var parts = document.getElementsByClassName('every-photo');
		for(i = 0;i < parts.length; i++){
			parts[i].style.left = parts[i].offsetLeft - 1 + 'px';
		}
		if (parts[0].offsetLeft < -perWa){
                
			var tBox = document.createElement('div');
			tBox.className = parts[0].className;
			tBox.innerHTML = parts[0].innerHTML;
			tParent.appendChild(tBox);
			tParent.removeChild(parts[0]);
		}
		parts = document.getElementsByClassName('every-photo');
		for (var i = 0; i < parts.length; i++){
                
			onMoving[i].style.top = perTop + 'px';
			if(i > 0){
                
				parts[i].style.left = parts[i-1].offsetLeft + perWa + 'px';
			}
			parts[i].onmouseover = function(){
				var This = this;
				This.style.zIndex = '101';
				clearInterval(This.time);
				This.time = setInterval(function(){
					This.style.width = This.offsetWidth + 8 +'px'
					This.style.height = This.offsetHeight + 6 +'px'
					This.style.left = This.offsetLeft - 4 + 'px';
					This.style.top = This.offsetTop - 3 + 'px';
					if(This.offsetWidth > (perWa-1)){
						clearInterval(This.time);
					}
				},15);
			}
			parts[i].onmouseout = function(){
				var This = this;
				This.style.zIndex = '100';
				clearInterval(This.time);
				This.time = setInterval(function(){
					This.style.width = This.offsetWidth - 8 +'px'
					This.style.height = This.offsetHeight - 6 +'px'
					This.style.left = This.offsetLeft + 4 + 'px';
					This.style.top = This.offsetTop + 3 + 'px';
					if(This.offsetWidth < (perWb+1)){
						clearInterval(This.time);
					}
				},15);
			}

		}
		if(parts.length == 0){
			clearInterval(this.time);
		}
	},30);
}
function stopMoving(){
	var tParent = document.getElementById('photo-show');
	clearInterval(tParent.time);
}
Moving();
oThis.onmouseout = Moving;
oThis.onmouseover = stopMoving;
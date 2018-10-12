// JavaScript Document
window.onload = function(){
	var onMoving = document.getElementsByClassName('moving-parts');
	var oThis = document.getElementById('big-part');
	var perB = onMoving[1].offsetWidth;
	var perA = onMoving[1].offsetWidth * 1.11;
	for (var i = 0; i < onMoving.length; i++) {
		if(i > 0) {
			onMoving[i].style.left = onMoving[i-1].offsetLeft + perA + 'px';
		}
	}
	function Moving(){
		var tParent = document.getElementById('big-part');
		tParent.time = setInterval(function(){
			var parts = document.getElementsByClassName('moving-parts');
			for(i = 0;i < parts.length; i++){
				parts[i].style.left = parts[i].offsetLeft - 1 + 'px';
			}
			if (parts[0].offsetLeft < (0-perA)) {
				var tBox = document.createElement('div');
				tBox.className = 'moving-parts';
				tBox.innerHTML = parts[0].innerHTML;
				tParent.appendChild(tBox);
				tParent.removeChild(parts[0]);
			}
			parts = document.getElementsByClassName('moving-parts');
			for (var i = 0; i < parts.length; i++) {
				if(i > 0) {
					parts[i].style.left = parts[i-1].offsetLeft + perA + 'px';
				}
				parts[i].onmouseover = function(){
					var This = this;
					This.style.zIndex = '1001';
					clearInterval(This.time);
					This.time = setInterval(function(){
						This.style.width = This.offsetWidth + 2 +'px'
						This.style.height = This.offsetHeight + 2 +'px'
						This.style.left = This.offsetLeft - 1 + 'px';
						if(This.offsetWidth > (perA-1)){
							clearInterval(This.time);
						}
					},10);
				}
				parts[i].onmouseout = function(){
					var This = this;
					This.style.zIndex = '1000';
					clearInterval(This.time);
					This.time = setInterval(function(){
						This.style.width = This.offsetWidth - 2 +'px'
						This.style.height = This.offsetHeight - 2 +'px'
						This.style.left = This.offsetLeft + 1 + 'px';
						if(This.offsetWidth < (perB+1)){
							clearInterval(This.time);
						}
					},10);
				}

			}
			if(parts.length == 0){
				clearInterval(this.time);
			}
		},30);
	}
	function stopMoving(){
		var tParent = document.getElementById('big-part');
		clearInterval(tParent.time);
	}
	Moving();
	oThis.onmouseout = Moving;
	oThis.onmouseover = stopMoving;
}
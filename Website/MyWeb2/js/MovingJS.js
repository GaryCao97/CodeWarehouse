window.onload=function(){
	var onMoving = getElementByClass('movingPart');
	var oThis = document.getElementById('HotP');
	partSeatOn(oThis,onMoving);
	Moving(oThis,onMoving);
	oThis.onmouseover = function(){
		stopMoving(oThis,onMoving);
	}
	oThis.onmouseout = function(){
		Moving(oThis,onMoving);
	}
}
function getElementByClass(clsName){
	var oCls = [];
	var oChild = document.getElementsByTagName('*');
	for (var i = 0; i < oChild.length; i++) {
		if(oChild[i].className == clsName){
			oCls.push(oChild[i]);
		}
	}
	return oCls;
}
function partSeatOn(parent,children){
	for (var i = 0; i < children.length; i++) {
		if(i > 0) {
			children[i].style.left = children[i-1].offsetLeft + 200 + 'px';
		}
	}
}
function Moving(parent,parts){
	for(i = 0; i < parts.length; i++){
		parts[i].time = setInterval(function(){
			this.style.left = this.offsetLeft - 1 + 'px';
		},30);
	}
	parts[0].time = setInterval(function(){
		parts[0].style.left = parts[0].offsetLeft - 1 + 'px';
		partSeatOn(parent,parts);
		if (parts[0].offsetLeft < -300) {
			var tBox = document.createElement('div');
			tBox.className = 'movingPart';
			tBox.innerHTML = parts[0].innerHTML;
			parent.appendChild(tBox);
			parent.removeChild(parts[0]);
		}
		parts = getElementByClass(clsName);
		if (parts.length == 0) {
			clearInterval(this.time);
		}
		parts = getElementByClass(clsName);
		partSeatOn(parent,parts);
	},30);
}
function stopMoving(parent,parts){
	clearInterval(parts[0].time);
}
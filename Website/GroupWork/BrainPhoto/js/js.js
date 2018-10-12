function textSizeTo(size,target){
	target.style.fontSize = size;
}
function textColorTo(color,target){
	target.style.color = color;
}
function textBgcolorTo(bgcolor,target){
	target.style.backgroundColor = bgcolor;
}
function textChange(btn,list,textFunction,target){
	var textBtn = document.getElementById(btn);
	var textList = document.getElementById(list);
	var textLists = textList.getElementsByTagName('li');
	textList.style.left = textBtn.offsetLeft + 'px';
	textList.style.top = textBtn.offsetTop + 'px';
	for(var i = 0;i < textLists.length;i++){
		if(list == 'text-size'){
			textLists[i].style.fontSize = textLists[i].title;
		}else if(list == 'text-color'){
			textLists[i].style.backgroundColor = textLists[i].title;
		}else if(list == 'text-bgcolor'){
			textLists[i].style.backgroundColor = textLists[i].title;
		}
		textLists[i].onclick = function(e){
			textFunction(this.title,target);
			e = e || window.event;
			if(e.stopPropagation){
				e.stopPropagation();
			}else{
				e.cancelBubble=true;
			}
			textList.style.display = 'none';
			if(btn == 'btn-size'){
				textBtn.innerHTML = this.title + ' ▾';
			}
		}
		if(btn == 'btn-size'){
			textLists[i].onmouseover = function(){
				this.style.color = '#fff';
				this.style.backgroundColor = '#000';
			}
			textLists[i].onmouseout = function(){
				this.style.color = '#000';
				this.style.backgroundColor = '#fff';
			}
		}
	}
	textBtn.onclick = function(e){
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
		document.getElementById('text-size').style.display = 'none';
		document.getElementById('text-color').style.display = 'none';
		document.getElementById('text-bgcolor').style.display = 'none';
		textList.style.display = 'block';
	}
}
function textWeightChange(btn,target){
	if(target.isBold == false){
		target.isBold = true;
		target.style.fontWeight = "bolder";
		btn.className = 'state-on';
		return true;
	}else{
		target.isBold = false;
		target.style.fontWeight = "normal";
		btn.className = 'state';
		return false;
	}
}
function textStyleChange(btn,target){
	if(target.isTilt == false){
		target.isTilt = true;
		target.style.fontStyle = "oblique";
		btn.className = 'state-on';
		return true;
	}else{
		target.isTilt = false;
		target.style.fontStyle = "normal";
		btn.className = 'state';
		return false;
	}
}
function textState(btn,textFunction,target){
	var textBtn = document.getElementById(btn);
	textBtn.onclick = function(e){
		textFunction(textBtn,target);
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
	}
}
function getTextState(btn,type){
	var textBtn = document.getElementById(btn);
	if(type == true){
		textBtn.className = 'state-on';
	}else{
		textBtn.className = 'state';
	}
}
function getTextSize(target){
	var textBtn = document.getElementById('btn-size');
	textBtn.innerHTML = target.style.fontSize + ' ▾';
}

function hide(){
	var hidePart = document.getElementById('hidden');
	hidePart.style.display = 'block';
	hidePart.style.width = document.getElementById('text-style').offsetWidth + document.getElementById('order').offsetWidth + document.getElementById('photoChange').offsetWidth + 20 + 'px';
	hidePart.style.height = document.getElementById('text-style').offsetHeight + 'px';
	hidePart.style.top = document.getElementById('order').offsetTop + 'px';
	hidePart.style.left = document.getElementById('order').offsetLeft + 'px';
	hidePart.style.backgroundColor = 'rgba(200,200,200,.7)';
}
function show(){
	var hidePart = document.getElementById('hidden');
	hidePart.style.display = 'none';
}
hide();

function creatNode(last){
	last = last?last:document.getElementById('main-body');
	if(last.next == undefined){
		last.next = new Array();
	}
	var perNode = document.createElement('div');
	perNode.last = last;
	perNode.next = new Array();
	perNode.nextLine = new Array();
	perNode.className = 'nodes';
	perNode.isBold = false;
	perNode.isTilt = false;
	perNode.isOrder = false;
	perNode.isPhoto = false;
	last.next.push(perNode);
	if(last == document.getElementById('main-body')){
		perNode.style.backgroundColor = "#fff";
		perNode.style.fontSize = '36px';
		perNode.grade = 1;
		perNode.style.top = 160 + 'px';
		if(last.next.length == 1){
			perNode.style.left = 500 + 'px';
		}else{
			perNode.style.left = last.next[last.next.length - 2].offsetLeft + last.next[last.next.length - 2].offsetWidth + 10 + 'px';
		}
	}else if(last.last == document.getElementById('main-body')){
		perNode.style.backgroundColor = "#ddd";
		perNode.style.fontSize = '24px';
		perNode.grade = 2;
		perNode.style.top = perNode.last.offsetTop + perNode.last.offsetHeight + 10 + 'px';
		if(last.next.length == 1){
			perNode.style.left = perNode.last.offsetLeft - 30 + 'px';
		}else{
			perNode.style.left = last.next[last.next.length - 2].offsetLeft + last.next[last.next.length - 2].offsetWidth + 10 + 'px';
		}
	}else{
		perNode.grade = 3;
		perNode.style.top = perNode.last.offsetTop + perNode.last.offsetHeight + 10 + 'px';
		if(last.next.length == 1){
			perNode.style.left = perNode.last.offsetLeft - 20 + 'px';
		}else{
			perNode.style.left = last.next[last.next.length - 2].offsetLeft + last.next[last.next.length - 2].offsetWidth + 10 + 'px';
		}
	}
	perNode.innerHTML = "<span>" + (document.getElementById('input-text').value?document.getElementById('input-text').value:"主题X") + '</span>';
	perNode.innerThing = perNode.innerHTML;
	document.getElementById('main-body').appendChild(perNode);
	document.getElementById('input-text').value = null;
	if(last == document.getElementById('main-body')){
		perNode.lastLine = null;
	}else{
		var perLine = document.createElement('hr');
		perLine.className = 'lines';
		perLine.color = "#000";
		perNode.lastLine = perLine;
		last.nextLine.push(perLine);
		document.getElementById('main-body').appendChild(perLine);
		lineStyle(perNode);
	}
	var winW = document.documentElement.clientWidth || document.body.clientWidth,
		winH = document.documentElement.clientHeight || document.body.clientHeight,
		maxW = winW - perNode.offsetWidth,
		maxH = winH - perNode.offsetHeight,
		minH = document.getElementById('main-body').offsetTop;
	if(perNode.offsetLeft < 0){
		perNode.style.left = 0;
	}else if(perNode.offsetLeft > maxW){
		perNode.style.left = maxW + 'px';
	}
	if(perNode.offsetTop < minH){
		perNode.style.top = minH + 'px';
	}else if(perNode.offsetTop > maxH){
		perNode.style.top = maxH + 'px';
	}
	perNode.onmousedown = nodeMove;
	perNode.onclick = nodeClick;
	perNode.ondblclick = function(){toReplace(this);}
}
function lineStyle(node){
	if(node.lastLine != null){
		var posX = (node.offsetLeft + node.offsetWidth/2 + node.last.offsetLeft + node.last.offsetWidth/2)/2,
			posY = (node.offsetTop + node.offsetHeight/2 + node.last.offsetTop + node.last.offsetHeight/2)/2,
			perX = node.offsetLeft + node.offsetWidth/2 - (node.last.offsetLeft + node.last.offsetWidth/2),
			perY = node.offsetTop + node.offsetHeight/2 - (node.last.offsetTop + node.last.offsetHeight/2),
			l = Math.floor(Math.sqrt(perX*perX + perY*perY)),
			angle = Math.PI/2 - Math.atan(perX/perY);
		node.lastLine.width = l;
		node.lastLine.style.left = posX - (l/2) + 'px';
		node.lastLine.style.top = posY + 'px';
		node.lastLine.style.transform = 'rotate(' +angle+ 'rad)';
	}
	for(var o = 0;o<node.next.length;o++){
		var posX = (node.offsetLeft + node.offsetWidth/2 + node.next[o].offsetLeft + node.next[o].offsetWidth/2)/2,
			posY = (node.offsetTop + node.offsetHeight/2 + node.next[o].offsetTop + node.next[o].offsetHeight/2)/2,
			perX = node.offsetLeft + node.offsetWidth/2 - (node.next[o].offsetLeft + node.next[o].offsetWidth/2),
			perY = node.offsetTop + node.offsetHeight/2 - (node.next[o].offsetTop + node.next[o].offsetHeight/2),
			l = Math.floor(Math.sqrt(perX*perX + perY*perY)),
			angle = Math.atan(perY/perX);
		node.nextLine[o].width = l;
		node.nextLine[o].style.left = posX - (l/2) + 'px';
		node.nextLine[o].style.top = posY + 'px';
		node.nextLine[o].style.transform = 'rotate(' +angle+ 'rad)';
	}
}
function nodeMove(e){
	e = e || window.event;
	if(e.stopPropagation){
		e.stopPropagation();
	}else{
		e.cancelBubble = true;
	}
	var This = this,
		e = e || document.event,
		posX = [],
		posY = [],
		relativeX = [],
		relativeY = [];
	for(n = 0;n<document.getElementsByClassName('nodes').length;n++){
		document.getElementsByClassName('nodes')[n].style.border = "#0FF 3px solid";
	}
	This.style.border = "#FF0 3px solid";
	var childNodes = getNodeByParent(This);
	for(r = 0;r < childNodes.length;r++){
		posX.push(e.clientX - childNodes[r].offsetLeft);
		posY.push(e.clientY - childNodes[r].offsetTop);
		relativeX.push(childNodes[0].offsetLeft - childNodes[r].offsetLeft);
		relativeY.push(childNodes[0].offsetTop - childNodes[r].offsetTop);
	}
	document.onmousemove = function(e){
		e = e || document.event;
		var tX = e.clientX - posX[0],
			tY = e.clientY - posY[0];
		var Lest = childNodes[0].offsetLeft,
			Test = childNodes[0].offsetTop,
			Rest = childNodes[0].offsetLeft + childNodes[0].offsetWidth,
			Best = childNodes[0].offsetTop + childNodes[0].offsetHeight;
		var indexL = 0,indexT = 0,indexR = 0,indexB = 0;
		for(r = 0;r < childNodes.length;r++){
			var thisL = childNodes[r].offsetLeft,
				thisT = childNodes[r].offsetTop,
				thisR = childNodes[r].offsetLeft + childNodes[0].offsetWidth,
				thisB = childNodes[r].offsetTop + childNodes[0].offsetHeight;
			if(thisL < Lest){
				Lest = thisL;
				indexL = r;
			}
			if(thisT < Test){
				Test = thisT;
				indexT = r;
			}
			if(thisR > Rest){
				Rest = thisR;
				indexR = r;
			}
			if(thisB > Best){
				Best = thisB;
				indexB = r;
			}
		}
		var pX1 = e.clientX - posX[indexL],
			pY1 = e.clientY - posY[indexT],
			pX2 = e.clientX - posX[indexR],
			pY2 = e.clientY - posY[indexB],
			winW = document.documentElement.clientWidth || document.body.clientWidth,
			winH = document.documentElement.clientHeight || document.body.clientHeight,
			maxW = winW - childNodes[indexR].offsetWidth,
			maxH = winH - childNodes[indexB].offsetHeight,
			minH = document.getElementById('main-body').offsetTop;
		if(pX1 < 0){
			pX1 = 0;
			tX = pX1 + relativeX[indexL];
		}else if(pX2 > maxW){
			pX2 = maxW;
			tX = pX2 + relativeX[indexR];
		}
		if(pY1 < minH){
			pY1 = minH;
			tY = pY1 + relativeY[indexT];
		}else if(pY2 > maxH){
			pY2 = maxH;
			tY = pY2 + relativeY[indexB];
		}
		childNodes[0].style.left = tX + 'px';
		childNodes[0].style.top = tY + 'px';
		lineStyle(childNodes[0]);
		for(r = 1;r < childNodes.length;r++){
			childNodes[r].style.left = childNodes[0].offsetLeft - relativeX[r] + 'px';
			childNodes[r].style.top = childNodes[0].offsetTop - relativeY[r] + 'px';
			lineStyle(childNodes[r]);
		}
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
	}
	document.onmouseup = function(e){
		document.onmousemove = null;
		document.onmousedown = null;
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
	}
}
function deleteNodeAndLine(node){
	var nodes = getNodeByParent(node);
	var tBody = document.getElementById('main-body');
	for(var o = 0;o < nodes.length;o++){
		if(nodes[o].lastLine != null){
			tBody.removeChild(nodes[o].lastLine);
		}
		tBody.removeChild(nodes[o]);
	}
	document.onclick();
}
function getNodeByParent(parent){
	var nodes = [],
		parents = [parent],
		node = [],
		allNodes = document.getElementById('main-body').getElementsByClassName('nodes'),
		m,n;
	nodes.push(parent);
	do{
		node = [];
		for(m=0;allNodes[m]!=undefined;m++){
			for(n=0;parents[n]!=undefined;n++){
				if(allNodes[m].last == parents[n]){
					nodes.push(allNodes[m]);
					node.push(allNodes[m]);
					break;
				}
			}
		}
		parents = node;
	}while(node.length != 0);
	return nodes;
}
function toReplace(divElement) { 
	var inputElement = document.createElement("input");
	var index = divElement.getElementsByTagName('span').length-1;
	inputElement.style.position = 'absolute'
	inputElement.value = divElement.getElementsByTagName('span')[index].innerHTML; 
	inputElement.style.left = divElement.offsetLeft +'px'; 
	inputElement.style.top = divElement.offsetTop +'px'; 
	inputElement.style.width = divElement.offsetWidth +'px'; 
	inputElement.style.height = divElement.offsetHeight +'px'; 
	inputElement.style.position = 'absolute';
	inputElement.style.zIndex = '2000';
	inputElement.style.fontSize = divElement.style.fontSize;
	document.getElementById('main-body').appendChild(inputElement); 
	inputElement.focus();
	inputElement.onblur = function() { 
		divElement.getElementsByTagName('span')[index].innerHTML = inputElement.value; 
		document.getElementById('main-body').removeChild(inputElement); 
		divElement.innerThing = '<span>' + divElement.getElementsByTagName('span')[index].innerHTML + '</span>';
		lineStyle(divElement);
	}
}
function orderBtn(target){
	var order = document.getElementById('order'),
		ordersBtn = order.getElementsByClassName('order'),
		eng = ['ban','one','two','three','four','five','six','seven','eight','nine'];
	for(i = 1;i<ordersBtn.length;i++){
		ordersBtn[i].innerThing = "<span class='order " + eng[i] + "'>" + i + "</span>";
		ordersBtn[i].onclick = function(e){
			e = e || window.event;
			if(e.stopPropagation){
				e.stopPropagation();
			}else{
				e.cancelBubble = true;
			}
			if(target.isOrder == false){
				target.innerHTML = this.innerThing + target.innerThing;
				target.isOrder = true;
			}else{
				target.innerHTML = this.innerThing + target.innerThing;
			}
		}
	}
	ordersBtn[0].onclick = function(e){
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
		if(target.isOrder == true){
			target.isOrder = false;
			target.innerHTML = target.innerThing;
		}
	}
}

function nodeClick(e){
	var This = this;
	e = e || window.event;
	if(e.stopPropagation){
		e.stopPropagation();
	}else{
		e.cancelBubble = true;
	}
	show();
	orderBtn(This);
	document.getElementById('insert').onclick = function(e){
		creatNode(This);
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
	}
	document.getElementById('edit').onclick = function(e){
		toReplace(This);
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
	}
	document.getElementById('delete').onclick = function(e){
		deleteNodeAndLine(This);
		This = null;
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
	}
	document.getElementById("insertPhoto").onclick = function(e){
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
		document.getElementById("imageInput").click();
	}
	document.getElementById("deletePhoto").onclick = function(e){
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
		This.isPhoto = false;
		This.removeChild(This.getElementsByTagName('img')[0]);
	}
	document.getElementById("imageInput").onchange = function(e){
		loadImageFile(This);
	}
	getTextState('text-bolder',This.isBold);
	getTextState('text-incline',This.isTilt);
	getTextSize(This);
	textState('text-bolder',textWeightChange,This);
	textState('text-incline',textStyleChange,This);
	textChange('btn-size','text-size',textSizeTo,This);
	textChange('btn-color','text-color',textColorTo,This);
	textChange('btn-bgcolor','text-bgcolor',textBgcolorTo,This);
}

document.getElementById('insert').onclick = function(e){
	e = e || window.event;
	if(e.stopPropagation){
		e.stopPropagation();
	}else{
		e.cancelBubble = true;
	}
	creatNode();
}
document.getElementById('input-text').onclick = function(e){
	e = e || window.event;
	if(e.stopPropagation){
		e.stopPropagation();
	}else{
		e.cancelBubble = true;
	}
}
document.getElementById('input-text').onkeydown = function(event){
	var e = event || window.event;
	if(e && e.keyCode == 13){ 
		document.getElementById('insert').onclick();
	}
}
document.onclick = function(){
	hide();
	document.getElementById('text-size').style.display = 'none';
	document.getElementById('text-color').style.display = 'none';
	document.getElementById('text-bgcolor').style.display = 'none';
	for(n = 0;n<document.getElementsByClassName('nodes').length;n++){
		document.getElementsByClassName('nodes')[n].style.border = "#0FF 3px solid";
	}
	document.getElementById('insert').onclick = function(e){
		e = e || window.event;
		if(e.stopPropagation){
			e.stopPropagation();
		}else{
			e.cancelBubble = true;
		}
		creatNode();
	}
}
var loadImageFile = (function () {
	var oImg = null, 
		oFReader = new window.FileReader();
	oFReader.onload = function (oFREvent) {
		if (!oImg || parentBox.isPhoto == false) {
			oImg = new Image();
			oImg.style.width = 80 + "px";
			oImg.style.height = 45 + "px";
			parentBox.appendChild(oImg);
			parentBox.isPhoto = true;
		}else{
			oImg = parentBox.getElementsByTagName('img')[0];
		}
		oImg.src = oFREvent.target.result;
	};
	return function (This) {
		parentBox = This;
		var aFiles = document.getElementById("imageInput").files;
		oFReader.readAsDataURL(aFiles[0]);
	}
})();
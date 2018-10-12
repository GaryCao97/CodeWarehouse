var oLi = document.getElementById('change-seat').getElementsByTagName('li');
var pBtn = document.getElementById('change-point').getElementsByTagName('span');
var now = 0;
var next = 1;
var timer = null;
document.getElementById('img-alt').innerHTML = oLi[0].getElementsByTagName("img")[0].alt;
document.getElementById('img-alt').href = oLi[0].getElementsByTagName("a")[0].href;
for(i = 0; i < oLi.length;i++){
	oLi[i].style.display = 'none';
	if(i == 0){
		oLi[i].style.display = 'list-item';
		pBtn[i].classList.add('hover');
	}
	pBtn[i].onmouseover = function(){
		clearInterval(timer);
		for(n = 0; n < pBtn.length; n++){
			if(parseInt(this.innerHTML) - 1 != n){
				pBtn[n].classList.remove('hover');
			}else{
				pBtn[n].classList.add('hover');
			}
		}
		for(h = 0;h < oLi.length;h++){
			if(getStyle(oLi[h],'display') == 'list-item'){
				now = h;
				break;
			}
		}
		next = parseInt(this.innerHTML) - 1;
		photoTo(now,next);
	}
	pBtn[i].onmouseout = function(){
		timer = setInterval(function(){
			now = next;
			next++;
			if(next >= oLi.length){
				next = 0;
			}
			photoTo(now,next);
			pBtn[now].classList.remove('hover');
			pBtn[next].classList.add('hover');
		},3000);
	}
}
timer = setInterval(function(){
	photoTo(now,next);
	pBtn[now].classList.remove('hover');
	pBtn[next].classList.add('hover');
	now = next;
	next++;
	if(next >= oLi.length){
		next = 0;
	}
},3000);

function photoTo(now,next){
	var tLi = document.getElementById('change-seat').getElementsByTagName('li');
	var tAlt = document.getElementById('img-alt');
	if(next >= tLi.length){
		next = 0;
	}
	if(now != next){
		for(m = 0; m < tLi.length; m++){
			tLi[m].style.display = 'none';
		}
		tLi[now].style.display = 'list-item';
		tLi[next].style.display = 'list-item';
		tLi[next].style.opacity = '0';
		tLi[next].style.filter = 'alpha(opacity:0)'
		alpha_1 = 0;
		alpha_2 = 100;
		tLi[next].timer = null;
		clearInterval(tLi[next].timer);
		tLi[next].timer = setInterval(function(){
			if(alpha_1 >= 100){
				clearInterval(tLi[next].timer);
				tLi[now].style.display = 'none';
				tAlt.innerHTML = tLi[next].getElementsByTagName("img")[0].alt;
				tAlt.href = tLi[next].getElementsByTagName("a")[0].href;
			}else{
				alpha_1 += 10;
				alpha_2 -= 10;
				tLi[now].style.opacity = alpha_2/100;
				tLi[now].style.filter = 'alpha(opacity:' + alpha_2 + ')'
				tLi[next].style.opacity = alpha_1/100;
				tLi[next].style.filter = 'alpha(opacity:' + alpha_1 + ')'
			}
		},30);
	}
}
function getStyle(obj,attr){
	if(obj.currentStyle){
		return obj.currentStyle[attr];
	}else{
		return getComputedStyle(obj,false)[attr];
	}
}
// JavaScript Document
function startMove(obj,attrAndTarget,fn){
	if(obj.timer == undefined){
		obj.timer = null;
	}
	//假设所有
	var flag = true;
	clearInterval(obj.timer);
	obj.timer = setInterval(function(){
		//遍历所有同时运动的属性值与目标值
		for(var attr in attrAndTarget){
			//1.获得属性当前值
			var curProperty = 0;
			if(attr == 'opacity'){
				curProperty = Math.round(parseFloat(getStyle(obj,attr)) * 100);
			}else{
				curProperty = parseInt(getStyle(obj,attr));
			}
			//2.计算速度值
			var speed = (attrAndTarget[attr] - curProperty)/8;
			speed = speed>0?Math.ceil(speed):Math.floor(speed);
			//3.判断是否达到目标值
			if(curProperty != attrAndTarget[attr]){
				flag = false;
			}
			if(attr == 'opacity'){
				obj.style.filter = 'alpha(opacity:' + (curProperty + speed) + ')';
				obj.style.opacity = (curProperty + speed) / 100;
			}else{
				obj.style[attr] = curProperty + speed + 'px';
			}
			
		}
		if(flag){
			clearInterval(obj.timer);
			if(fn){
				fn();
			}
		}
	},30);
}
function getStyle(obj,attr){
	if(obj.currentStyle){
		return obj.currentStyle[attr];
	}else{
		return getComputedStyle(obj,false)[attr];
	}
}
// JavaScript Document
var adImages = [];
adImages[0] = 'img/';
adImages[1] = 'img/';
adImages[2] = 'img/';
adImages[3] = 'img/';
adImages[4] = 'img/';
adImages[5] = 'img/';

suspendcode1 = "<div id='Ad1' style='position:absolute;left:5px;top:45px;'><a href='' target='_blank'><img src='" + adImages[0] + "' height='68' border=0 /></a></div>"
suspendcode3 = "<div id='Ad3' style='position:absolute;left:5px;top:125px;'><a href='' target='_blank'><img src='" + adImages[1] + "' height='68 ' border=0 /></a></div>"
suspendcode5 = "<div id='Ad5' style='position:absolute;left:5px;top:205px;'><a href='' target='_blank'><img src='" + adImages[2] + "' height='68' border=0 /></a></div>"
suspendcode7 = "<div id='Ad7' style='position:absolute;left:5px;top:285px;'><div align=center><img src='img/close.gif' border=0 onclick='closeBannerL();' /></div></div>"

suspendcode2 = "<div id='Ad2' style='position:absolute;right:5px;top:45px;'><a href='' target='_blank'><img src='" + adImages[3] + "' height='68' border=0 /></a></div>"
suspendcode4 = "<div id='Ad4' style='position:absolute;right:5px;top:125px;'><a href='' target='_blank'><img src='" + adImages[4] + "' height='68' border=0 /></a></div>"
suspendcode6 = "<div id='Ad6' style='position:absolute;right:5px;top:205px;'><a href='' target='_blank'><img src='" + adImages[5] + "' height='68' border=0  /></a></div>"
suspendcode8 = "<div id='Ad8' style='position:absolute;right:5px;top:285px;'><div align=center><img src='img/close.gif' border=0 onclick='closeBannerR();' /></div></div>"

document.write(suspendcode1);
document.write(suspendcode2);
document.write(suspendcode3);
document.write(suspendcode4);
document.write(suspendcode5);
document.write(suspendcode6);
document.write(suspendcode7);
document.write(suspendcode8);

var lastScrollY = 0;
function heartBeat() {
	var diffY;
	if (document.documentElement && document.documentElement.scrollTop)
		diffY = document.documentElement.scrollTop;
	else if (document.body)
		diffY = document.body.scrollTop;
	else
	{ }

	var percent = .1 * (diffY - lastScrollY);
	if (percent > 0) 
		percent = Math.ceil(percent);
	else 
		percent = Math.floor(percent);
	
	document.getElementById("Ad1").style.top = document.getElementById("Ad1").offsetTop + percent + "px";
	document.getElementById("Ad3").style.top = document.getElementById("Ad3").offsetTop + percent + "px";
	document.getElementById("Ad5").style.top = document.getElementById("Ad5").offsetTop + percent + "px";
	document.getElementById("Ad7").style.top = document.getElementById("Ad7").offsetTop + percent + "px";
	
	document.getElementById("Ad2").style.top = document.getElementById("Ad2").offsetTop + percent + "px";
	document.getElementById("Ad4").style.top = document.getElementById("Ad4").offsetTop + percent + "px";
	document.getElementById("Ad6").style.top = document.getElementById("Ad6").offsetTop + percent + "px";
	document.getElementById("Ad8").style.top = document.getElementById("Ad8").offsetTop + percent + "px";
	
	lastScrollY = lastScrollY + percent;
}
window.setInterval("heartBeat()", 1);
function closeBannerL() {
	document.getElementById("Ad1").style.display = 'none';
	document.getElementById("Ad3").style.display = 'none';
	document.getElementById("Ad5").style.display = 'none';
	document.getElementById("Ad7").style.display = 'none';
}
function closeBannerR() {
	document.getElementById("Ad2").style.display = 'none';
	document.getElementById("Ad4").style.display = 'none';
	document.getElementById("Ad6").style.display = 'none';
	document.getElementById("Ad8").style.display = 'none';
}
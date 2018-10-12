// JavaScript Document
var btnOpen = document.getElementById('nav-open'),
	btnClose = document.getElementById('nav-close');
var oNav = document.getElementById('nav');
btnOpen.onclick = function(){
	oNav.style.display = 'block';
}
btnClose.onclick = function(){
	oNav.style.display = 'none';
}
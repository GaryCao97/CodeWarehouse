// JavaScript Document
var vLine = document.getElementById('vertical-line');
var tTable = document.getElementById('progress-body').getElementsByTagName('table')[0];
var fLine = tTable.getElementsByTagName('hr')[0];
var oTD = tTable.getElementsByTagName('td');
vLine.style.top = fLine.offsetTop + tTable.offsetTop + 'px';
vLine.style.left = tTable.offsetLeft + tTable.getElementsByTagName('td')[2].offsetLeft + 'px';
vLine.style.width = '3px';
vLine.style.background = '#000';
vLine.style.height = tTable.offsetHeight - Math.floor(0.5*oTD[0].scrollHeight + 0.5*oTD[oTD.length-1].scrollHeight) + 'px';
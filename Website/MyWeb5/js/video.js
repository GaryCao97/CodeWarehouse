// JavaScript Document
var tVideo = document.getElementById('video-player');
tVideo.oT = 1;
function videoClick(){
	if(this.oT == 1){
		this.pause();
		this.oT = 0;
	}
	else{  
		this.play();
		this.oT = 1;
	}
}
tVideo.onclick = videoClick;

var oVideo = ['video1.mp4','video2.mp4','video3.mp4','video4.mp4'];
var order = 0;
var oPrev = document.getElementById('video-prev');
var oNext = document.getElementById('video-next');
oPrev.onclick = function(){
	if (order > 0){
		order = order - 1;
		var oClip = document.getElementById('movieclip');
		var inner = "<video id='video-player' autoplay='true' width='800px' height='450px'><source src='video/" + oVideo[order] + "' type='video/mp4' /></video>";
		oClip.innerHTML = inner;
		var that = document.getElementById('video-player');
		that.onclick = videoClick;
		that.oT = 1;
	}
}
oNext.onclick = function(){
	if (order < (oVideo.length - 1)){
		order = order + 1;
		var oClip = document.getElementById('movieclip');
		var inner = "<video id='video-player' autoplay='true' width='800px' height='450px'><source src='video/" + oVideo[order] + "' type='video/mp4' /></video>";
		oClip.innerHTML = inner;
		var that = document.getElementById('video-player');
		that.onclick = videoClick;
		that.oT = 1;
	}
}
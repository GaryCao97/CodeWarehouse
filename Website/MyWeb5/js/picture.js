// JavaScript Document
var onMoving = document.getElementsByClassName('every-photo');

function photoClickSet(){
	var tVideo = document.getElementById('video-player');
	for(i = 0;i < onMoving.length;i++){
		onMoving[i].onclick = function(){
			var clsName = [];
			clsName = this.className;
			clsName = clsName.substring(12,clsName.length);
			var tBG = document.createElement('div');
			tBG.id = 'picture-bg';
			var tBtnClose = document.createElement('a');
			tBtnClose.id = 'picture-close';
			tBtnClose.className = 'btn';
			var tPic = document.createElement('div');
			tPic.id = "picture-big";
			tPic.className = clsName;
			tPic.style.left = Math.floor((document.documentElement.clientWidth - 1280)/2) + 'px';
			tPic.style.top = Math.floor((document.documentElement.clientHeight - 840)/2) + 'px';
			tBG.appendChild(tPic);
			tBG.appendChild(tBtnClose);
			document.body.appendChild(tBG);
			var videoState = tVideo.oT;
			if(videoState == 1){
				tVideo.pause();
				tVideo.oT = 0;
			}
			tBtnClose.onclick = function(){
				document.body.removeChild(tBG);
				if(videoState == 1){
					tVideo.play();
					tVideo.oT = 1;
				}
			}
		}
	}
}
setInterval(photoClickSet,100);
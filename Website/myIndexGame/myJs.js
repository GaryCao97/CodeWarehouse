var rootDiv = document.createElement("div");
rootDiv.style.width = "100%";
rootDiv.style.height = "100%";
rootDiv.style.background = "";
rootDiv.style.opacity = "0.8";
rootDiv.style.webkitBorderRadius = "10px";
rootDiv.style.borderRadius = "10px";
rootDiv.style.boxShadow = "0 0 8px #000"
document.getElementsByTagName("body")[0].appendChild(rootDiv);

var indexTitle = document.createElement("div");
indexTitle.innerText = "完成2048或者输入密码打开我的博客";
indexTitle.style.textAlign = "center";
indexTitle.style.padding = "20px";
indexTitle.style.fontSize = "48px";
rootDiv.appendChild(indexTitle);

var passwordPane = document.createElement("div");
passwordPane.style.textAlign = "center";
passwordPane.style.font = "";
passwordPane.style.margin = "10px";
var passwordWord = document.createElement("span");
passwordWord.innerText = "密码："
var passwordInput = document.createElement("input");
passwordInput.height = "20px";
passwordInput.width = "100px";
passwordInput.type = "password";
passwordPane.appendChild(passwordWord);
passwordPane.appendChild(passwordInput);
rootDiv.appendChild(passwordPane);
passwordInput.oninput = function(){
    if(passwordInput.value == "password:gary"){
        rootDiv.remove();
    }
}

var gamePane = document.createElement("div");
gamePane.style.width = "400px";
gamePane.style.height = "400px";
gamePane.style.margin = "0 auto";
gamePane.style.backgroundColor= "rgba(200,200,200,0.8)";
gamePane.style.webkitBorderRadius = "10px";
gamePane.style.borderRadius = "10px";
gamePane.style.boxShadow = "0 0 8px #567"
rootDiv.appendChild(gamePane);
//2048初始化
var gameBlock = new Array(4 * 4);
for(var i = 0;i < 4 * 4;i++){
    gameBlock[i] = document.createElement("div");
    gameBlock[i].style.float = "left";
    gameBlock[i].style.textAlign = "center";
    gameBlock[i].style.lineHeight = "96px";
    gameBlock[i].style.fontSize = "36px";
    gameBlock[i].style.webkitBorderRadius = "10px";
    gameBlock[i].style.borderRadius = "10px";
    gameBlock[i].style.boxShadow = "0 0 5px #000"
    gameBlock[i].style.width = "96px";
    gameBlock[i].style.height = "96px";
    gameBlock[i].style.margin = "2px";
    gamePane.appendChild(gameBlock[i]);
}
var gameArr = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]];
//console.log(Math.floor(Math.random() * 4));
gameArr[(Math.floor(Math.random() * 4))][(Math.floor(Math.random() * 4))] = 2;
gameArr[(Math.floor(Math.random() * 4))][(Math.floor(Math.random() * 4))] = 2;
updateGamePane();

//2048游戏画面刷新
function updateGamePane(){
    for(var i = 0;i < 4;i++){
        for(var j = 0;j < 4;j++){
            gameBlock[i * 4 + j].innerText = gameArr[i][j]==0?"":gameArr[i][j];
            switch(gameArr[i][j]){
                case 0:gameBlock[i * 4 + j].style.backgroundColor = "#aaaaaa";break;
                case Math.pow(2,1):gameBlock[i * 4 + j].style.backgroundColor = "#00aaaa";break;
                case Math.pow(2,2):gameBlock[i * 4 + j].style.backgroundColor = "#aa00aa";break;
                case Math.pow(2,3):gameBlock[i * 4 + j].style.backgroundColor = "#aaaa00";break;
                case Math.pow(2,4):gameBlock[i * 4 + j].style.backgroundColor = "#0000aa";break;
                case Math.pow(2,5):gameBlock[i * 4 + j].style.backgroundColor = "#aa0000";break;
                case Math.pow(2,6):gameBlock[i * 4 + j].style.backgroundColor = "#00aa00";break;
                case Math.pow(2,7):gameBlock[i * 4 + j].style.backgroundColor = "#66aaaa";break;
                case Math.pow(2,8):gameBlock[i * 4 + j].style.backgroundColor = "#aa66aa";break;
                case Math.pow(2,9):gameBlock[i * 4 + j].style.backgroundColor = "#aaaa66";break;
                case Math.pow(2,10):gameBlock[i * 4 + j].style.backgroundColor = "#666666";break;
            }
        }
    }
}

//2048游戏方式
//游戏结束
function isEnd(){
    for(var p = 0;p < 4;p++){
        for(var q = 0;q < 4;q++){
            if(gameArr[p][q] == gameArr[p+1][q] || gameArr[p][q] == gameArr[p][q+1] || gameArr[p][q] == 0)return false;
        }
    }
    return true;
}
//水平结束
function isEndOnHorizontal(){
    
}
//垂直结束
function isEndOnVertical(){
    
}
//游戏胜利
//向左移动
function moveLeft(){
    var canAdd = false;
    for(var p = 0;p < 4;p++){
        var tmp = [];
        var q = 0;
        for(;q < 4;q++){
            if(gameArr[p][q]!=0) tmp.push(gameArr[p][q]);
            gameArr[p][q] = 0;
        }
        q = 0;
        while(tmp.length != 0){
            if(tmp[0] == tmp[1]) gameArr[p][q++] = tmp.shift() + tmp.shift();
            else gameArr[p][q++] = tmp.shift();
        }
        if(gameArr[p][3] == 0) canAdd = true;
    }
    if(!canAdd)return;
    var tmp = Math.floor(Math.random() * 4);
    while(gameArr[tmp][3]!=0) tmp = Math.floor(Math.random() * 4);
    gameArr[tmp][3] = Math.pow(2,Math.floor(Math.random() * 2) + 1);
    updateGamePane();
}
//向右移动
function moveRight(){
    var canAdd = false;
    for(var p = 0;p < 4;p++){
        var tmp = [];
        var q = 3;
        for(;q > -1;q--){
            if(gameArr[p][q]!=0) tmp.push(gameArr[p][q]);
            gameArr[p][q] = 0;
        }
        q = 3;
        while(tmp.length != 0){
            if(tmp[0] == tmp[1]) gameArr[p][q--] = tmp.shift() + tmp.shift();
            else gameArr[p][q--] = tmp.shift();
        }
        if(gameArr[p][0] == 0) canAdd = true;
    }
    if(!canAdd)return;
    var tmp = Math.floor(Math.random() * 4);
    while(gameArr[tmp][0]!=0) tmp = Math.floor(Math.random() * 4);
    gameArr[tmp][0] = Math.pow(2,Math.floor(Math.random() * 2) + 1);
    updateGamePane();
}
//向上移动
function moveUp(){
    var canAdd = false;
    for(var p = 0;p < 4;p++){
        var tmp = [];
        var q = 0;
        for(;q < 4;q++){
            if(gameArr[q][p]!=0) tmp.push(gameArr[q][p]);
            gameArr[q][p] = 0;
        }
        q = 0;
        while(tmp.length != 0){
            if(tmp[0] == tmp[1]){
                gameArr[q++][p] = tmp.shift() + tmp.shift();
            }
            else gameArr[q++][p] = tmp.shift();
        }
        if(gameArr[3][p] == 0) canAdd = true;
    }
    if(!canAdd)return;
    var tmp = Math.floor(Math.random() * 4);
    while(gameArr[3][tmp]!=0) tmp = Math.floor(Math.random() * 4);
    gameArr[3][tmp] = Math.pow(2,Math.floor(Math.random() * 2) + 1);
    updateGamePane();
}
//向下移动
function moveDown(){
    var canAdd = false;
    for(var p = 0;p < 4;p++){
        var tmp = [];
        var q = 3;
        for(;q > -1;q--){
            if(gameArr[q][p]!=0){
                var l = tmp.length;
                if((q!=3) && (tmp[l - 1] == gameArr[q][p])) tmp[l-1]*=2;
                else tmp.push(gameArr[q][p]);
            }
            gameArr[q][p] = 0;
        }
        q = 3;
        while(tmp.length != 0){
            gameArr[q--][p] = tmp.shift();
        }
        if(gameArr[0][p] == 0) canAdd = true;
    }
    if(!canAdd)return;
    var tmp = Math.floor(Math.random() * 4);
    while(gameArr[0][tmp]!=0) tmp = Math.floor(Math.random() * 4);
    gameArr[0][tmp] = Math.pow(2,Math.floor(Math.random() * 2) + 1);
    updateGamePane();
}

//控制方式1：鼠标按住滑动

//控制方式2：鼠标点击方向按钮
var btnPane = document.createElement("div");
btnPane.style.textAlign = "center";
btnPane.style.height = "100px";
btnPane.style.lineHeight = "100px";
rootDiv.appendChild(btnPane);
var btnLeft = document.createElement("div");
btnLeft.innerText = "左";
btnLeft.style.fontSize = "30px";
btnLeft.style.float = "left";
btnPane.appendChild(btnLeft);
btnLeft.onclick = function(e){
    e = e || window.event;
    if(!isEnd())moveLeft();
    e.preventDefault();
    e.stopPropagation();
}
var btnRight = document.createElement("div");
btnRight.innerText = "右";
btnRight.style.fontSize = "30px";
btnRight.style.float = "left";
btnPane.appendChild(btnRight);
btnRight.onclick = function(e){
    e = e || window.event;
    if(!isEnd())moveRight();
    e.preventDefault();
    e.stopPropagation();
}
var btnUp = document.createElement("div");
btnUp.innerText = "上";
btnUp.style.fontSize = "30px";
btnUp.style.float = "left";
btnPane.appendChild(btnUp);
btnUp.onclick = function(e){
    e = e || window.event;
    if(!isEnd())moveUp();
    e.preventDefault();
    e.stopPropagation();
}
var btnDown = document.createElement("div");
btnDown.innerText = "下";
btnDown.style.fontSize = "30px";
btnDown.style.float = "left";
btnPane.appendChild(btnDown);
btnDown.onclick = function(e){
    e = e || window.event;
    if(!isEnd())moveDown();
    e.preventDefault();
    e.stopPropagation();
}
document.onkeyup=function(e){
    e = e || window.event;
    switch(e.keyCode){
        case 37:moveLeft();break;
        case 38:moveUp();break;
        case 39:moveRight();break;
        case 40:moveDown();break;
    }
}


//控制方式3：键盘方向键
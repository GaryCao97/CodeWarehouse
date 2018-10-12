//首页大背景设置
var rootDiv = document.createElement("div");
rootDiv.id = "root";
rootDiv.style.width = "100%";
rootDiv.style.height = "100%";
rootDiv.style.background = "";
rootDiv.style.opacity = "0.8";
rootDiv.style.webkitBorderRadius = "10px";
rootDiv.style.borderRadius = "10px";
rootDiv.style.boxShadow = "0 0 8px #000"
document.getElementsByTagName("body")[0].appendChild(rootDiv);
//首页标题
var indexTitle = document.createElement("div");
indexTitle.innerText = "完成游戏条件或者输入密码打开我的博客";
indexTitle.style.textAlign = "center";
indexTitle.style.padding = "20px";
indexTitle.style.fontSize = "48px";
rootDiv.appendChild(indexTitle);
//密码输入框
var passwordPane = document.createElement("div");
passwordPane.style.textAlign = "center";
passwordPane.style.font = "";
passwordPane.style.fontSize = "24px";
passwordPane.style.margin = "10px";
var passwordWord = document.createElement("span");
passwordWord.innerText = "密码："
var passwordInput = document.createElement("input");
passwordInput.style.height = "32px";
passwordInput.style.width = "240px";
passwordInput.type = "password";
passwordPane.appendChild(passwordWord);
passwordPane.appendChild(passwordInput);
rootDiv.appendChild(passwordPane);
passwordInput.oninput = function(){
    if(passwordInput.value == "password:gary"){
        rootDiv.remove();
    }
}
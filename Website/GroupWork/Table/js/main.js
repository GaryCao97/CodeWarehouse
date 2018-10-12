// JavaScript Document
var btn_create = document.getElementsByClassName('buttons-create')[0],
	btn_edit = document.getElementsByClassName('buttons-edit')[0],
	btn_remove = document.getElementsByClassName('buttons-remove')[0];

btn_create.onclick = function(){createEntry();}
btn_edit.onclick = function(){
	if(!this.classList.contains('disabled'))
		editEntry();
}
btn_remove.onclick = function(){
	if(!this.classList.contains('disabled'))
		removeEntry();
}

activateSearchBox();
function activateSearchBox(){
	var searchBox = document.getElementById("search-box").getElementsByTagName('input')[0];
	searchBox.onkeydown = function(){
		var This = this;
		This.onkeyup = function(){
			searchData(this);
		}
	}
}

activateScroll();
function activateScroll(){
	window.onmousewheel = function(e){
		var direct = 0;
		e = e || window.event;
		if(e.wheelDelta){
			if(e.wheelDelta > 0){
				direct = 1;
			}
			if(e.wheelDelta < 0){
				direct = -1;
			}
		}else if (e.detail){
			if(e.detail > 0){
				direct = 1;
			}
			if(e.detail < 0){
				direct = -1;
			}
		}
		var nextBtn = document.getElementsByClassName('next')[0],
			previousBtn = document.getElementsByClassName('previous')[0];
		if(direct == 1){
			previousBtn.onclick();
		}else if(direct == -1){
			nextBtn.onclick();
		}
	}
}

activateInlineEdit();
function activateInlineEdit(){
	var data = getUsingData();
	var table_td = document.getElementsByTagName('td');
	for(i = 0;i < table_td.length;i++){
		if(table_td[i].className != 'select-checkbox'){
			table_td[i].onclick = function(){
				window.onmousewheel = null;
				var divElement = this;
				var inputElement = document.createElement("input");
				inputElement.value = divElement.innerHTML; 
				var t = document.getElementById('main-table').offsetTop,
					l = document.getElementById('main-table').offsetLeft;
				inputElement.style.left = divElement.offsetLeft + l + 9 + 'px'; 
				inputElement.style.top = divElement.offsetTop + t + 2 + 'px'; 
				inputElement.style.width = divElement.offsetWidth - 18 + 'px'; 
				inputElement.style.height = divElement.offsetHeight - 4 + 'px'; 
				inputElement.style.position = 'absolute';
				inputElement.style.zIndex = '8';
				inputElement.style.fontSize = 'inherit';
				document.body.appendChild(inputElement); 
				inputElement.focus();
				var This = this;
				inputElement.onblur = function() {
					var perTH = document.getElementById('main-table').getElementsByTagName('th');
					var perTD = [];
					for(g = 0;g < This.parentNode.getElementsByTagName('td').length;g++){
						perTD.push(This.parentNode.getElementsByTagName('td')[g]);
					}
					if(checkValue(perTH[perTD.indexOf(This)].id,inputElement.value)){
						upData(This.parentNode.index,data,perTH[perTD.indexOf(This)].id,inputElement.value);
						var date = new Date();
						var time = date.getFullYear() + '-' + (date.getMonth()+1) + '-' + date.getDate();
						upData(This.parentNode.index,data,'changeTime',time);
					}
					document.body.removeChild(inputElement); 
					activateScroll();
				}
				inputElement.onkeydown = function(event){
					var e = event || window.event;
					if(e && e.keyCode == 13){ 
						inputElement.onblur();
					}
				}
			}
		}
	}
}

activateCheckbox();
function activateCheckbox(){
	var btn_checkbox = document.getElementsByClassName('select-checkbox');
	var table_tr = document.getElementsByTagName('tr');
	selectEntry();
	document.body.onkeydown = function(event){selectEntry(event);}
	document.body.onkeyup = function(event){selectEntry(event);}
	document.onclick = function(){
		for(o = 1;o < table_tr.length;o++){
			if(table_tr[o].selected == true){
				table_tr[o].classList.add('selected');
			}
			else if(table_tr[o].selected == false){
				table_tr[o].classList.remove('selected');
			}
		}
		var tail = document.getElementById('table_info');
		var Num = document.getElementsByClassName('selected');
		if(Num.length == 0){
			tail.getElementsByTagName('span')[1].innerHTML = '';
			document.getElementsByClassName('buttons-edit')[0].classList.add('disabled');
			document.getElementsByClassName('buttons-remove')[0].classList.add('disabled');
		}
		else if(Num.length == 1){
			tail.getElementsByTagName('span')[1].innerHTML = Num.length + ' 条被选中';
			document.getElementsByClassName('buttons-edit')[0].classList.remove('disabled');
			document.getElementsByClassName('buttons-remove')[0].classList.remove('disabled');
		}
		else if(Num.length > 1){
			tail.getElementsByTagName('span')[1].innerHTML = Num.length + ' 条被选中';
			document.getElementsByClassName('buttons-edit')[0].classList.add('disabled');
			document.getElementsByClassName('buttons-remove')[0].classList.remove('disabled');
		}
	}
}
function selectEntry(event){
	var data = getUsingData();
	var e = event || window.event;
	var btn_checkbox = document.getElementsByClassName('select-checkbox');
	var table_tr = document.getElementById('main-table-tbody').getElementsByTagName('tr');
	if(e != undefined){
		if(e.ctrlKey){
			for(i = 1;i < btn_checkbox.length;i++){
				btn_checkbox[i].index = btn_checkbox[i].parentNode.index;
				btn_checkbox[i].onclick = function(){
					if(table_tr[this.index].selected == false || table_tr[this.index].selected == undefined){
						data[this.index].selected = true;
						table_tr[this.index].selected = true;
					}else{
						data[this.index].selected = false;
						table_tr[this.index].selected = false;
					}
				}
			}
		}else{
			for(i = 1;i < btn_checkbox.length;i++){
				btn_checkbox[i].index = btn_checkbox[i].parentNode.index;
				btn_checkbox[i].onclick = function(event){
					for(n = 0;n<table_tr.length;n++){
						if(n != this.index){
							data[n].selected = false;
							table_tr[n].selected = false;
						}
					}
					if(table_tr[this.index].selected == false || table_tr[this.index].selected == undefined){
						data[this.index].selected = true;
						table_tr[this.index].selected = true;
					}else{
						data[this.index].selected = false;
						table_tr[this.index].selected = false;
					}
				}
				
			}
		}
	}else{
		for(i = 1;i < btn_checkbox.length;i++){
			btn_checkbox[i].index = btn_checkbox[i].parentNode.index;
			btn_checkbox[i].onclick = function(event){
				for(n = 0;n<table_tr.length;n++){
					if(n != this.index){
						data[n].selected = false;
						table_tr[n].selected = false;
					}
				}
				if(table_tr[this.index].selected == false || table_tr[this.index].selected == undefined){
					data[this.index].selected = true;
					table_tr[this.index].selected = true;
				}else{
					data[this.index].selected = false;
					table_tr[this.index].selected = false;
				}
			}
			
		}
	}
}

activateSortbtn();
function activateSortbtn(){
	var data = getUsingData();
	var btnSort = document.getElementsByTagName('th');
	for(i = 1;i<btnSort.length;i++){
		btnSort[i].index = i;
		btnSort[i].onclick = function(){
			sortingEntry(this);
			sortData(this.sorting,data,this.id);
			upLoad(false,false);
		}
	}
}
function sortingEntry(This){
	var btnSort = document.getElementsByTagName('th');
	var tableTr = document.getElementsByTagName('tr');
	if(This.sorting != 'asc'){
		for(m = 0;m < tableTr.length;m++){
			if(m == 0){
				for(n = 1;n<btnSort.length;n++){
					btnSort[n].sorting = 'both';
					btnSort[n].className = 'sorting-both';
				}
				continue;
			}
			for(n = 1;n<btnSort.length;n++){
				tableTr[m].getElementsByTagName('td')[n].classList.remove('sorting');
			}
			tableTr[m].getElementsByTagName('td')[This.index].className = 'sorting';
		}
		This.sorting = 'asc'
		This.className = 'sorting-asc';
	}
	else if(This.sorting != 'desc'){
		for(m = 0;m < tableTr.length;m++){
			if(m == 0){
				for(n = 1;n<btnSort.length;n++){
					btnSort[n].sorting = 'both';
					btnSort[n].className = 'sorting-both';
				}
				continue;
			}
			for(n = 1;n<btnSort.length;n++){
				tableTr[m].getElementsByTagName('td')[n].classList.remove('sorting');
			}
			tableTr[m].getElementsByTagName('td')[This.index].className = 'sorting';
		}
		This.sorting = 'desc';
		This.className = 'sorting-desc';
	}
}

activatePagebtn();
function activatePagebtn(){
	var pageBtn = document.getElementById('table_page').getElementsByTagName('a');
	for(i = 1;i < pageBtn.length - 1;i++){
		pageBtn[i].index = i;
		pageBtn[i].onclick = function(){
			for(n = 1;n < pageBtn.length - 1;n++){
				pageBtn[n].classList.remove('current');
			}
			pageBtn[this.index].classList.add('current');
			upLoad(null,false);
		}
	}
	pageBtn[0].onclick = function(){
		if(!this.classList.contains('disabled')){
			var pageNum = parseInt(document.getElementsByClassName('current')[0].innerHTML);
			for(n = 1;n < pageBtn.length - 1;n++){
				pageBtn[n].classList.remove('current');
			}
			pageBtn[pageNum-1].classList.add('current');
			upLoad(null,false);
		}
	}
	pageBtn[pageBtn.length - 1].onclick = function(){
		if(!this.classList.contains('disabled')){
			var pageNum = parseInt(document.getElementsByClassName('current')[0].innerHTML);
			for(n = 1;n < pageBtn.length - 1;n++){
				pageBtn[n].classList.remove('current');
			}
			pageBtn[pageNum+1].classList.add('current');
			upLoad(null,false);
		}
	}
}

function createEntry(){
	window.onmousewheel = null;
	var data = getUsingData();
	var div2Inner = "<div class='lightbox-table'><div class='lightbox-content-wrapper'><div class='lightbox-content'>" +
		"<div class='lightbox-container action-create'>" +
		"<div class='box-header'><div>新建条目</div></div>" +
		"<div class='box-body'><div class='box-body-content'>" +
		"<form style='display:block;'>" +
		"<div class='form-content'>" +
		"<div class='form-field'><label for='form-number'>学号:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-number' /></div></div></div>" +
		"<div class='form-field'><label for='form-name'>姓名:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-name' /></div></div></div>" +
		"<div class='form-field'><label for='form-age'>年龄:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-age' /></div></div></div>" +
		"<div class='form-field'><label for='form-gender'>性别:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-gender' /></div></div></div>" +
		"<div class='form-field'><label for='form-profession'>专业:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-profession' /></div></div></div>" +
		"<div class='form-field'><label for='form-position'>职位:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-position' /></div></div></div>" +
		"</div>" +
		"</form>" +
		"</div></div>" +
		"<div class='box-footer'>" +
		"<div class='form-button'><button class='btn'>新建</button></div>" +
		"</div>" +
		"</div>" +
		"<div class='lightbox-close'></div>" +
		"</div></div></div>";
	var div1 = document.createElement('div');
	div1.className = 'lightbox-bg';
	var div2 = document.createElement('div');
	div2.className = 'lightbox-wrapper';
	div2.innerHTML = div2Inner;
	
	document.body.appendChild(div1);
	document.body.appendChild(div2);
	document.getElementsByClassName('lightbox-close')[0].onclick = function(){
		document.body.removeChild(div1);
		document.body.removeChild(div2);
		activateScroll();
	}
	document.getElementsByClassName('form-button')[0].onclick = function(){
		if(checkValue('age',parseInt(document.getElementById('form-age').value)) && 
			checkValue('name',document.getElementById('form-name').value) && 
			checkValue('number',document.getElementById('form-number').value) && 
			checkValue('gender',document.getElementById('form-gender').value) && 
			checkValue('profession',document.getElementById('form-profession').value) && 
			checkValue('position',document.getElementById('form-position').value)
		){
			var date = new Date();
			var time = date.getFullYear() + '-' + (date.getMonth()+1) + '-' + date.getDate();
			document.getElementById('form-');
			var newOneData = new Information(
				document.getElementById('form-name').value,
				document.getElementById('form-number').value,
				parseInt(document.getElementById('form-age').value),
				document.getElementById('form-gender').value,
				document.getElementById('form-profession').value,
				document.getElementById('form-position').value,
				time
			);
			data.push(newOneData);
			upLoad(null,false);
			document.body.removeChild(div1);
			document.body.removeChild(div2);
			activateScroll();
		}else{
			alertError();
		}
	}
}
function editEntry(){
	window.onmousewheel = null;
	var data = getUsingData();
	var formInner = document.getElementsByClassName('selected')[0].getElementsByTagName('td');
	var div2Inner = "<div class='lightbox-table'><div class='lightbox-content-wrapper'><div class='lightbox-content'>" +
		"<div class='lightbox-container action-edit'>" +
		"<div class='box-header'><div>编辑条目</div></div>" +
		"<div class='box-body'><div class='box-body-content'>" +
		"<form style='display:block;'>" +
		"<div class='form-content'>" +
		"<div class='form-field'><label for='form-number'>学号:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-number' value='" + formInner[1].innerHTML + "' /></div></div></div>" +
		"<div class='form-field'><label for='form-name'>姓名:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-name' value='" + formInner[2].innerHTML + "' /></div></div></div>" +
		"<div class='form-field'><label for='form-age'>年龄:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-age' value='" + formInner[3].innerHTML + "' /></div></div></div>" +
		"<div class='form-field'><label for='form-gender'>性别:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-gender' value='" + formInner[4].innerHTML + "' /></div></div></div>" +
		"<div class='form-field'><label for='form-profession'>专业:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-profession' value='" + formInner[5].innerHTML + "' /></div></div></div>" +
		"<div class='form-field'><label for='form-position'>职位:</label><div class='form-input'><div class='form-inputcontrol'><input type='text' id='form-position' value='" + formInner[6].innerHTML + "' /></div></div></div>" +
		"</div>" +
		"</form>" +
		"</div></div>" +
		"<div class='box-footer'>" +
		"<div class='form-button'><button class='btn'>确定</button></div>" +
		"</div>" +
		"</div>" +
		"<div class='lightbox-close'></div>" +
		"</div></div></div>";
	var div1 = document.createElement('div');
	div1.className = 'lightbox-bg';
	var div2 = document.createElement('div');
	div2.className = 'lightbox-wrapper';
	div2.innerHTML = div2Inner;
	
	document.body.appendChild(div1);
	document.body.appendChild(div2);
	document.getElementsByClassName('lightbox-close')[0].onclick = function(){
		document.body.removeChild(div1);
		document.body.removeChild(div2);
		activateScroll();
	}
	document.getElementsByClassName('form-button')[0].onclick = function(){
		result = null;
		if(checkValue('age',parseInt(document.getElementById('form-age').value)) && 
			checkValue('name',document.getElementById('form-name').value) && 
			checkValue('number',document.getElementById('form-number').value) && 
			checkValue('gender',document.getElementById('form-gender').value) && 
			checkValue('profession',document.getElementById('form-profession').value) && 
			checkValue('position',document.getElementById('form-position').value)
		){
			var date = new Date();
			var time = date.getFullYear() + '-' + (date.getMonth()+1) + '-' + date.getDate();
			var isSelected = data[formInner[0].parentNode.index].selected;
			var oddOrEven = data[formInner[0].parentNode.index].oddOrEven;
			var onlyID = data[formInner[0].parentNode.index].onlyID;
			var index = data[formInner[0].parentNode.index].index;
			data[formInner[0].parentNode.index] = new Information(
				document.getElementById('form-name').value,
				document.getElementById('form-number').value,
				parseInt(document.getElementById('form-age').value),
				document.getElementById('form-gender').value,
				document.getElementById('form-profession').value,
				document.getElementById('form-position').value,
				time
			);
			data[formInner[0].parentNode.index].selected = isSelected;
			data[formInner[0].parentNode.index].oddOrEven = oddOrEven;
			data[formInner[0].parentNode.index].onlyID = onlyID;
			data[formInner[0].parentNode.index].index = index;
			upLoad(false,false);
			document.body.removeChild(div1);
			document.body.removeChild(div2);
			activateScroll();
		}else{
			alertError();
		}
	}
}
function removeEntry(){
	window.onmousewheel = null;
	var data = getUsingData();
	var Entry = document.getElementsByClassName('selected');
	var div2Inner = "<div class='lightbox-table'><div class='lightbox-content-wrapper'><div class='lightbox-content'>" +
		"<div class='lightbox-container action-remove'>" +
		"<div class='box-header'><div>移除条目</div></div>" +
		"<div class='box-body'><div class='box-body-content'>" +
		"<div class='form-info'>你确定要移除这" + Entry.length + "条目？</div>" +
		"</div></div>" +
		"<div class='box-footer'>" +
		"<div class='form-button'><button class='btn'>确定</button></div>" +
		"</div>" +
		"</div>" +
		"<div class='lightbox-close'></div>" +
		"</div></div></div>";
	var div1 = document.createElement('div');
	div1.className = 'lightbox-bg';
	var div2 = document.createElement('div');
	div2.className = 'lightbox-wrapper';
	div2.innerHTML = div2Inner;
	
	document.body.appendChild(div1);
	document.body.appendChild(div2);
	document.getElementsByClassName('lightbox-close')[0].onclick = function(){
		document.body.removeChild(div1);
		document.body.removeChild(div2);
		activateScroll();
	}
	document.getElementsByClassName('form-button')[0].onclick = function(){
		var tData = []
		for(m = 0;m < Entry.length;m++){
			tData.push(data[Entry[m].index]);
		}
		for(m = 0;m < tData.length;m++){
			data.remove(tData[m]);
		}
		upLoad(null,false);
		document.body.removeChild(div1);
		document.body.removeChild(div2);
		activateScroll();
	}
}
function alertError(){
	var DIV1 = document.createElement('div');
	var DIV2 = document.createElement('div');
	DIV1.className = "error-bg";
	DIV2.className = "error-wrapper";
	DIV2.innerHTML = "<div class='error-table'><div class='error-content-wrapper'><div class='error-content'><div class='error-container'>" +
		"<div class='error-header'><div>信息有误</div></div>" +
		"<div class='error-body'><div class='error-body-content'>" +
		"<div class='error-info'>刚刚输入的信息有误！请核对后重新确认！</div>" +
		"</div></div>" +
		"<div class='error-footer'>" +
		"<div class='error-button'><button class='btn'>确定</button></div>" +
		"</div>" +
		"</div></div></div></div>";
	document.body.appendChild(DIV1);
	document.body.appendChild(DIV2);
	document.getElementsByClassName('error-button')[0].onclick = function(){
		document.body.removeChild(DIV1);
		document.body.removeChild(DIV2);
	}
}

// JavaScript Document
function Information(name,number,age,gender,profession,position,changeTime){
	this.name = name;
	this.number = number;
	this.age = age;
	this.gender = gender;
	this.profession = profession;
	this.position = position;
	this.changeTime = changeTime;
	this.oddOrEven = null;
	this.selected = false;
	this.index = null;
	this.onlyID = null;
}
var dataBase = [];
dataBase[0] = new Information('张一','6103315001',19,'男','数字媒体技术','普通学生','2016-12-9');
dataBase[1] = new Information('张二','6103315002',18,'女','数字媒体技术','普通学生','2016-12-8');
dataBase[2] = new Information('张三','6103315003',20,'男','数字媒体技术','普通学生','2016-12-11');
dataBase[3] = new Information('李四','6103315004',19,'男','数字媒体技术','普通学生','2016-12-6');
dataBase[4] = new Information('李五','6103315005',19,'女','数字媒体技术','普通学生','2016-12-16');
dataBase[5] = new Information('李六','6103315006',20,'女','数字媒体技术','普通学生','2016-12-7');
dataBase[6] = new Information('赵一','6103315007',19,'男','数字媒体技术','普通学生','2016-12-13');
dataBase[7] = new Information('钱一','6103315008',17,'男','数字媒体技术','普通学生','2016-12-4');
dataBase[8] = new Information('孙一','6103315009',19,'女','数字媒体技术','普通学生','2016-12-14');
dataBase[9] = new Information('周一','6103315010',18,'男','数字媒体技术','普通学生','2016-12-13');
dataBase[10] = new Information('吴一','6103315011',19,'男','数字媒体技术','普通学生','2016-12-2');
dataBase[11] = new Information('郑一','6103315012',19,'女','数字媒体技术','普通学生','2016-12-4');
dataBase[12] = new Information('王一','6103315013',19,'男','数字媒体技术','普通学生','2016-12-13');
dataBase[13] = new Information('赵二','6103315014',19,'女','数字媒体技术','普通学生','2016-12-1');
dataBase[14] = new Information('钱二','6103315015',19,'男','数字媒体技术','普通学生','2016-12-13');
dataBase[15] = new Information('孙二','6103315016',20,'女','数字媒体技术','普通学生','2016-12-2');
dataBase[16] = new Information('周二','6103315017',19,'女','数字媒体技术','普通学生','2016-12-13');
dataBase[17] = new Information('吴二','6103315018',19,'男','数字媒体技术','普通学生','2016-12-1');
dataBase[18] = new Information('郑二','6103315019',20,'男','数字媒体技术','普通学生','2016-12-13');
dataBase[19] = new Information('王二','6103315020',19,'女','数字媒体技术','普通学生','2016-12-2');
dataBase[20] = new Information('张九','6103315021',19,'男','数字媒体技术','普通学生','2016-12-13');
dataBase[21] = new Information('赵十','6103315022',19,'女','数字媒体技术','普通学生','2016-12-13');
dataBase[22] = new Information('孙天','6103315023',20,'男','数字媒体技术','普通学生','2016-12-9');
dataBase[23] = new Information('张成','6103315024',19,'男','数字媒体技术','普通学生','2016-12-12');
dataBase[24] = new Information('李红','6103315025',17,'女','数字媒体技术','普通学生','2016-12-5');
dataBase[25] = new Information('李思','6103315026',20,'女','数字媒体技术','普通学生','2016-12-13');
dataBase[26] = new Information('李同','6103315027',19,'男','数字媒体技术','普通学生','2016-12-8');
dataBase[27] = new Information('钱来','6103315028',19,'男','数字媒体技术','普通学生','2016-12-7');
dataBase[28] = new Information('张若佳','6103315029',19,'女','数字媒体技术','普通学生','2016-12-7');
dataBase[29] = new Information('周乐','6103315030',18,'男','数字媒体技术','普通学生','2016-12-10');
var total = 30;
var oldData = dataBase,newData = dataBase;
for(n = 0;n < dataBase.length;n++)
	dataBase[n].onlyID = n;
function getUsingData(){
	return newData.length<dataBase.length?newData:dataBase;
}
function upLoad(isNew,isFirst){
	var data = getUsingData();
	var table = document.getElementById('main-table-tbody');
	var page = (document.getElementsByClassName('current').length != 0)?parseInt(document.getElementsByClassName('current')[0].innerHTML):1;
	var pages = Math.ceil(data.length/10);
	var tail = document.getElementById('table_info');
	tail.getElementsByTagName('span')[0].innerHTML = '第' + ((page - 1)*10 + 1) + '至' + ((page*10<data.length)?page*10:data.length) + '条，共 ' + data.length + ' 条，共 ' + pages + ' 页&nbsp;&nbsp;&nbsp; ';
	var pageBtn = document.getElementById('table_page').getElementsByTagName('a');
	var pagesBtn = document.getElementById('table_page').getElementsByTagName('span')[0];
	if(isNew == true){
		table.innerHTML = '';
		for(n = 0;n < data.length;n++){
			data[n].index = n;
			var newTr = document.createElement('tr');
			newTr.index = n;
			if(n % 2 == 0){
				data[n].oddOrEven = 'odd';
			}else{
				data[n].oddOrEven = 'even';
			}
			newTr.innerHTML = "<td class='select-checkbox'></td>" +
				"<td>" + data[n].number + "</td>" +
				"<td>" + data[n].name + "</td>" +
				"<td>" + data[n].age + "</td>" +
				"<td>" + data[n].gender + "</td>" +
				"<td>" + data[n].profession + "</td>" +
				"<td>" + data[n].position + "</td>" +
				"<td>" + data[n].changeTime + "</td>";
			newTr.style.display = 'none';
			newTr.classList.add(data[n].oddOrEven);
			if(n >= (page - 1)*10 && n < page*10){
				newTr.style.display = 'table-row';
			}
			table.appendChild(newTr);
		}
		pageBtn[0].classList.add('disabled');
		pagesBtn.innerHTML = '';
		for(n = 0;n < pages;n++){
			var newPages = document.createElement('a');
			newPages.classList.add('page_button');
			if(n == 0){
				newPages.classList.add('current');
			}
			newPages.innerHTML = n+1;
			pagesBtn.appendChild(newPages);
		}
		pageBtn[pageBtn.length-1].classList.remove('disabled');
		if(pages == 1 || page == pages){
			pageBtn[pageBtn.length-1].classList.add('disabled');
		}
	}else if(isNew == false){
		var perTR = table.getElementsByTagName('tr');
		for(n = 0;n < perTR.length;n++){
			perTR[n].getElementsByTagName('td')[1].innerHTML = data[n].number;
			perTR[n].getElementsByTagName('td')[2].innerHTML = data[n].name;
			perTR[n].getElementsByTagName('td')[3].innerHTML = data[n].age;
			perTR[n].getElementsByTagName('td')[4].innerHTML = data[n].gender;
			perTR[n].getElementsByTagName('td')[5].innerHTML = data[n].profession;
			perTR[n].getElementsByTagName('td')[6].innerHTML = data[n].position;
			perTR[n].getElementsByTagName('td')[7].innerHTML = data[n].changeTime;
			perTR[n].index = n;
			if(n % 2 == 0){
				data[n].oddOrEven = 'odd';
			}else{
				data[n].oddOrEven = 'even';
			}
			perTR[n].selected = data[n].selected;
			perTR[n].classList.remove('odd');
			perTR[n].classList.remove('even');
			perTR[n].classList.add(data[n].oddOrEven);
			perTR[n].classList.remove('selected');
			if(perTR[n].selected == true){
				perTR[n].classList.add('selected');
			}
			else if(perTR[n].selected == false){
				perTR[n].classList.remove('selected');
			}
		}
	}else if(data.length > table.getElementsByTagName('tr').length){
		data[data.length-1].onlyID = total;
		total += 1;
		data[data.length-1].index = data.length-1;
		var newTr = document.createElement('tr');
		newTr.index = data.length-1;
		if((data.length-1) % 2 == 0){
			data[data.length-1].oddOrEven = 'odd';
		}else{
			data[data.length-1].oddOrEven = 'even';
		}
		newTr.innerHTML = "<td class='select-checkbox'></td>" +
			"<td>" + data[data.length-1].number + "</td>" +
			"<td>" + data[data.length-1].name + "</td>" +
			"<td>" + data[data.length-1].age + "</td>" +
			"<td>" + data[data.length-1].gender + "</td>" +
			"<td>" + data[data.length-1].profession + "</td>" +
			"<td>" + data[data.length-1].position + "</td>" +
			"<td>" + data[data.length-1].changeTime + "</td>";
		newTr.style.display = 'none';
		newTr.classList.add(data[data.length-1].oddOrEven);
		if((data.length-1) >= (page - 1)*10 && (data.length-1) < page*10){
			newTr.style.display = 'table-row';
		}
		table.appendChild(newTr);
		if(pages != pagesBtn.getElementsByTagName('a').length){
			var newPages = document.createElement('a');
			newPages.classList.add('page_button');
			newPages.innerHTML = pages;
			pagesBtn.appendChild(newPages);
		}
	}else if(data.length < table.getElementsByTagName('tr').length){
		var oldTr = [];
		for(i = 0;i < table.getElementsByTagName('tr').length;i++){
			var n = 0;
			for(n = 0;n < data.length;n++){
				if(table.getElementsByTagName('tr')[i].index == data[n].index){
					break;
				}
			}
			if(n == data.length){
				oldTr.push(table.getElementsByTagName('tr')[i]);
			}
		}
		for(i = 0;i < oldTr.length;i++){
			table.removeChild(oldTr[i]);
		}
		for(i = 0;i < data.length;i++){
			data[i].index = i;
			table.getElementsByTagName('tr')[i].index = i;
			if(i % 2 == 0){
				data[i].oddOrEven = 'odd';
			}else{
				data[i].oddOrEven = 'even';
			}
			table.getElementsByTagName('tr')[i].selected = data[i].selected;
			table.getElementsByTagName('tr')[i].classList.remove('odd');
			table.getElementsByTagName('tr')[i].classList.remove('even');
			table.getElementsByTagName('tr')[i].classList.add(data[i].oddOrEven);
		}
		if(pages != pagesBtn.getElementsByTagName('a').length){
			for(i = pages;i < pagesBtn.getElementsByTagName('a').length;i++){
				pagesBtn.removeChild(pagesBtn.getElementsByTagName('a')[i]);
			}
		}
		var perTr = table.getElementsByTagName('tr');
		for(n = 0;n < perTr.length;n++){
			perTr[n].style.display = 'none';
			if(n >= (page - 1)*10 && n < page*10){
				perTr[n].style.display = 'table-row';
			}
		}
		pageBtn[0].classList.remove('disabled');
		pageBtn[pageBtn.length-1].classList.remove('disabled');
		if(pages == 1 || page == 1){
			pageBtn[0].classList.add('disabled');
		}
		if(pages == 1 || page == pages){
			pageBtn[pageBtn.length-1].classList.add('disabled');
		}
	}else{
		var perTr = table.getElementsByTagName('tr');
		for(n = 0;n < perTr.length;n++){
			perTr[n].style.display = 'none';
			if(n >= (page - 1)*10 && n < page*10){
				perTr[n].style.display = 'table-row';
			}
		}
		pageBtn[0].classList.remove('disabled');
		pageBtn[pageBtn.length-1].classList.remove('disabled');
		if(pages == 1 || page == 1){
			pageBtn[0].classList.add('disabled');
		}
		if(pages == 1 || page == pages){
			pageBtn[pageBtn.length-1].classList.add('disabled');
		}
	}
	toReplaceData(data);
	if(isNew != true || isFirst == false){
		activateCheckbox();
		activateInlineEdit();
		activatePagebtn();
		activateScroll();
	}
}
upLoad(true,true);

function upData(indexNum,data,prototypeName,newPrototypeValue){
	data[indexNum][prototypeName] = newPrototypeValue;
	upLoad(false,false);
}

function compareString(str1,str2){
	if(isNaN(str1) || isNaN(str2)){
		if(styleTime(str1) && styleTime(str2)){
			var Day1 = str1.split('-');
			var Day2 = str2.split('-');
			for(p = 0; p <3;p++){
				Day1[p] = parseInt(Day1[p]);
				Day2[p] = parseInt(Day2[p]);
			}
			if(Day1[0] > Day2[0]){
				return false;
			}else if(Day1[0] == Day1[0]){
				if(Day1[1] > Day2[1]){
					return false;
				}else if(Day1[1] == Day1[1]){
					if(Day1[2] > Day2[2]){
						return false;
					}else if(Day1[2] == Day1[2]){
						return true;
					}else{
						return true;
					}
				}else{
					return true;
				}
			}else{
				return true;
			}
		}
		for(q = 0;q < str1.length;q++){
			if(str1[q] > str2[q]){
				return false;
			}
			if(str1[q] < str2[q]){
				return true;
			}
		}
	}else{
		if(str1 > str2){
			return false;
		}
		if(str1 < str2){
			return true;
		}
	}
}
function sortData(ascORdesc,data,prototypeName){
	if(ascORdesc == 'asc'){  //从小到大
		var p = data.length - 1;  //初始时,最后位置保持不变  
		while (p> 0) {
			var pos = 0; //每趟开始时,无记录交换  
			for (var q = 0; q< p; q++)
				if (compareString(data[q][prototypeName],data[q + 1][prototypeName]) == false) {
					pos = q; //记录交换的位置   
					var tmp = data[q];
					data[q] = data[q + 1];
					data[q + 1] = tmp;
				}
			p = pos; //为下一趟排序作准备  
		}
	}else if(ascORdesc == 'desc'){  //从大到小
		var p = data.length - 1;  //初始时,最后位置保持不变  
		while (p> 0) {
			var pos = 0; //每趟开始时,无记录交换  
			for (var q = 0; q< p; q++)
				if (compareString(data[q][prototypeName],data[q + 1][prototypeName]) == true) {
					pos = q; //记录交换的位置   
					var tmp = data[q];
					data[q] = data[q + 1];
					data[q + 1] = tmp;
				}
			p = pos; //为下一趟排序作准备  
		}
	}
}
function toReplaceData(nowData){
	for(k = 0;k < nowData.length;k++){
		for(l = 0;l < dataBase.length;l++){
			if(dataBase[l].onlyID == nowData[k].onlyID){
				dataBase[l] = nowData[k];
			}
		}
	}
}
function searchData(This){
	oldData = dataBase;
	newData = [];
	if(This.value != ''){
		for(b = 0;b < oldData.length;b++){
			if( oldData[b].name.indexOf(This.value) != -1 ||
				oldData[b].number.indexOf(This.value) != -1 ||
				(oldData[b].age + '').indexOf(This.value) != -1 ||
				oldData[b].gender.indexOf(This.value) != -1 ||
				oldData[b].profession.indexOf(This.value) != -1 ||
				oldData[b].position.indexOf(This.value) != -1 ||
				oldData[b].changeTime.indexOf(This.value) != -1
			){
				newData.push(oldData[b]);
			}
		}
	}
	else{
		newData = dataBase
	}
	upLoad(true,false);
}
function checkValue(key,value){
	if(key == 'age'){
		if(!isNaN(value) && value < 150 && value > 0){
			return true;
		}
	}else if(key == 'changeTime'){
		if(styleTime(value)){
			return true;
		}
	}else{
		if(value != ''){
			return true;
		}
	}
	return false;
}
function styleTime(value){
	var child = value.split('-');
	if(child.length == 3){
		var year = parseInt(child[0]),
			month = parseInt(child[1]),
			day = parseInt(child[2]);
		if(year < 0 || month < 1 || month > 12 || day < 1 || day > 31){
			return false;
		}else{
			return true;
		}
	}
	return false;
}
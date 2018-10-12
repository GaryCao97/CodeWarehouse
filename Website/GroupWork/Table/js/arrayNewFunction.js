// JavaScript Document
Array.prototype.indexOf = function(arr) {
	for (var i = 0; i < this.length; i++) {
		if (this[i] == arr){
			return i;
		}
	}
	return -1;
};
Array.prototype.remove = function(arr) {
	var index = this.indexOf(arr);
	if (index > -1) {
		this.splice(index, 1);
	}
};
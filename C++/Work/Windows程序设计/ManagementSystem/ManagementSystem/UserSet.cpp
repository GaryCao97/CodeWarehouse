#include "stdafx.h"
#include "UserSet.h"

void CUserSet::CStringToChar(CString str, char *pChStr) {
	//CString和char*转换方法：
	int n = str.GetLength(); //按字符计算，str的长度
	int len = WideCharToMultiByte(CP_ACP, 0, str, n, NULL, 0, NULL, NULL);//按Byte计算str长度
	WideCharToMultiByte(CP_ACP, 0, str, n, pChStr, len, NULL, NULL);//宽字节转换为多字节编码
	pChStr[len] = '\0';//不要忽略末尾结束标志
}
int cmp0(UserElem ue1, UserElem ue2) {
	return ue1.m_ID < ue2.m_ID;
}
int cmp1(UserElem ue1, UserElem ue2) {
	return ue1.m_Username < ue2.m_Username;
}
int cmp2(UserElem ue1, UserElem ue2) {
	return ue1.m_Number < ue2.m_Number;
}
int cmp3(UserElem ue1, UserElem ue2) {
	return ue1.m_Realname < ue2.m_Realname;
}
int cmp4(UserElem ue1, UserElem ue2) {
	return ue1.m_Kind < ue2.m_Kind;
}
int cmp5(UserElem ue1, UserElem ue2) {
	return ue1.m_Duty < ue2.m_Duty;
}
int cmp6(UserElem ue1, UserElem ue2) {
	return ue1.m_Password < ue2.m_Password;
}

CUserSet::CUserSet()
{
	m_Username = L"";
	m_Number = L"";
	m_Realname = L"";
	m_Kind = L"";
	m_Duty = L"";
	m_Password = L"";
	m_strFilter = _T("");
	m_strSort = _T("");
	length = 1;
	openLength = 0;
	canEdit = false;

	title[0] = _T("ID");
	title[1] = _T("Username");
	title[2] = _T("Number");
	title[3] = _T("Realname");
	title[4] = _T("Kind");
	title[5] = _T("Duty");
	title[6] = _T("Password");

	ifstream inf("res/UserData.dat", ios_base::binary);
	//加入如果打开失败。。。
	real.clear();
	UserFileInfo Fi_temp;
	while (inf.read(reinterpret_cast<char*>(&Fi_temp), sizeof(Fi_temp))) {
		UserElem UE_temp;
		UE_temp.m_ID = Fi_temp.m_ID;
		UE_temp.m_Username = Fi_temp.m_Username;
		UE_temp.m_Duty = Fi_temp.m_Duty;
		UE_temp.m_Kind = Fi_temp.m_Kind;
		UE_temp.m_Number = Fi_temp.m_Number;
		UE_temp.m_Password = Fi_temp.m_Password;
		UE_temp.m_Realname = Fi_temp.m_Realname;
		real.push_back(UE_temp);
	}
	inf.close();
	if(!real.empty()){
		real.sort(cmp0);
		iterR = real.end();
		newID = (--iterR)->m_ID + 1;
	}
	else newID = 1;
}
CUserSet::~CUserSet() {
	ofstream outf("res/UserData.dat", ios_base::binary);
	UserFileInfo Fi_temp;
	list<UserElem>::iterator Ad_temp = real.begin();
	for (; Ad_temp != real.end(); Ad_temp++) {
		Fi_temp.m_ID = Ad_temp->m_ID;
		CStringToChar(Ad_temp->m_Username, Fi_temp.m_Username);
		CStringToChar(Ad_temp->m_Duty, Fi_temp.m_Duty);
		CStringToChar(Ad_temp->m_Kind, Fi_temp.m_Kind);
		CStringToChar(Ad_temp->m_Number, Fi_temp.m_Number);
		CStringToChar(Ad_temp->m_Password, Fi_temp.m_Password);
		CStringToChar(Ad_temp->m_Realname, Fi_temp.m_Realname);
		outf.write(reinterpret_cast<char*>(&Fi_temp), sizeof(Fi_temp));
	}
	real.clear();
	outf.close();
}

bool CUserSet::IsOpen() {
	if (openned.empty())return false;
	else return true;
}
bool CUserSet::IsEOF() {
	if (openned.empty() || iterO == openned.end())return true;
	else return false;
}
bool CUserSet::Open() {
	if (m_strFilter == _T("")) {
		std::list<UserElem>::iterator p = real.begin();
		for (; p != real.end(); p++)openned.push_back(*p);
	}
	else {
		std::list<UserElem>::iterator p = real.begin();
		for (; p != real.end(); p++) {
			if (m_sFilterTitle == title[1] && m_sFilterKeyWord == p->m_Username) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[2] && m_sFilterKeyWord == p->m_Number) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[3] && m_sFilterKeyWord == p->m_Realname) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[4] && m_sFilterKeyWord == p->m_Kind) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[5] && m_sFilterKeyWord == p->m_Duty) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[6] && m_sFilterKeyWord == p->m_Password) {
				openned.push_back(*p);
			}
		}
	}
	if (m_strSort != _T("")) {
		if (m_strSort == title[1]) {
			openned.sort(cmp1);
		}
		else if (m_strSort == title[2]) {
			openned.sort(cmp2);
		}
		else if (m_strSort == title[3]) {
			openned.sort(cmp3);
		}
		else if (m_strSort == title[4]) {
			openned.sort(cmp4);
		}
		else if (m_strSort == title[5]) {
			openned.sort(cmp5);
		}
		else if (m_strSort == title[6]) {
			openned.sort(cmp6);
		}
	}
	iterO = openned.begin();
	return true;
}
bool CUserSet::Close() {
	openned.clear();
	return true;
}
void CUserSet::AddNew() {
	canEdit = true;
	length++;
	now = openLength++;
	realNow = length - 1;
	UserElem UE_temp;
	real.push_back(UE_temp);
	iterR = real.end();
	iterR--;
}
void CUserSet::Edit() {
	canEdit = true;
}
void CUserSet::Update() {
	if (canEdit) {
		iterR->m_ID = newID++;
		iterR->m_Username = m_Username;
		iterR->m_Number = m_Number;
		iterR->m_Realname = m_Realname;
		iterR->m_Kind = m_Kind;
		iterR->m_Duty = m_Duty;
		iterR->m_Password = m_Password;
		canEdit = false;
	}
}
void CUserSet::Move(long pos) {
	if(pos<=openned.size()){
		now = pos;
		int i = 0;
		for (iterO = openned.begin(); iterO != openned.end() && i < now; iterO++) {
			i++;
		}
		iterR = real.begin();
		for (i = 0; iterR != real.end(); i++, iterR++)
			if (iterR->m_ID == iterO->m_ID)break;
		realNow = i;
		m_ID = iterO->m_ID;
		m_Username = iterO->m_Username;
		m_Number = iterO->m_Number;
		m_Realname = iterO->m_Realname;
		m_Kind = iterO->m_Kind;
		m_Duty = iterO->m_Duty;
		m_Password = iterO->m_Password;
	}
}
void CUserSet::Delete() {
	if (iterR != real.end())
		real.erase(iterR);
}
void CUserSet::MoveNext() {
	now++;
	int i = 0;
	iterO++;
	if(iterO!=openned.end()){
		iterR = real.begin();
		for (i = 0; iterR != real.end(); i++, iterR++)
			if (iterR->m_ID == iterO->m_ID)break;
		realNow = i;
		m_ID = iterO->m_ID;
		m_Username = iterO->m_Username;
		m_Number = iterO->m_Number;
		m_Realname = iterO->m_Realname;
		m_Kind = iterO->m_Kind;
		m_Duty = iterO->m_Duty;
		m_Password = iterO->m_Password;
	}
}
void CUserSet::GetFieldValue(short n, CString &str) {
	switch (n) {
	case 0:str.Format(_T("%d"), m_ID); break;
	case 1:str = m_Username; break;
	case 2:str = m_Number; break;
	case 3:str = m_Realname; break;
	case 4:str = m_Kind; break;
	case 5:str = m_Duty; break;
	case 6:str = m_Password; break;
	}
}
int CUserSet::GetODBCFieldCount() {
	return 7;
}
void CUserSet::GetODBCFieldInfo(short n, CString &str) {
	str = title[n];
}
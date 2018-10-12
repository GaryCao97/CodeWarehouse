#include "stdafx.h"
#include "CommSet.h"

typedef struct {
	long m_ID;
	char	m_CommNum[20];
	char	m_CommName[20];
	char	m_CommKind[20];
	char	m_Introduce[200];
	char	m_PhotoAddress[200];
	char	m_Origin[100];
	char	m_Specifications[50];
	char	m_Price[20];
	long	m_Inventory;
}CommFileInfo;
void CCommSet::CStringToChar(CString str, char *pChStr) {
	//CString和char*转换方法：
	int n = str.GetLength(); //按字符计算，str的长度
	int len = WideCharToMultiByte(CP_ACP, 0, str, n, NULL, 0, NULL, NULL);//按Byte计算str长度
	WideCharToMultiByte(CP_ACP, 0, str, n, pChStr, len, NULL, NULL);//宽字节转换为多字节编码
	pChStr[len] = '\0';//不要忽略末尾结束标志
}
int cmp0(CommElem ue1, CommElem ue2) {
	return ue1.m_ID < ue2.m_ID;
}
int cmp1(CommElem ue1, CommElem ue2) {
	return ue1.m_CommNum < ue2.m_CommNum;
}
int cmp2(CommElem ue1, CommElem ue2) {
	return ue1.m_CommName < ue2.m_CommName;
}
int cmp3(CommElem ue1, CommElem ue2) {
	return ue1.m_CommKind < ue2.m_CommKind;
}
int cmp4(CommElem ue1, CommElem ue2) {
	return ue1.m_Introduce < ue2.m_Introduce;
}
int cmp5(CommElem ue1, CommElem ue2) {
	return ue1.m_PhotoAddress < ue2.m_PhotoAddress;
}
int cmp6(CommElem ue1, CommElem ue2) {
	return ue1.m_Origin < ue2.m_Origin;
}
int cmp7(CommElem ue1, CommElem ue2) {
	return ue1.m_Specifications < ue2.m_Specifications;
}
int cmp8(CommElem ue1, CommElem ue2) {
	return ue1.m_Price < ue2.m_Price;
}
int cmp9(CommElem ue1, CommElem ue2) {
	return ue1.m_Inventory < ue2.m_Inventory;
}

CCommSet::CCommSet()
{
	m_ID = 0;
	m_CommNum = L"";
	m_CommName = L"";
	m_CommKind = L"";
	m_Introduce = L"";
	m_PhotoAddress = L"";
	m_Origin = L"";
	m_Specifications = L"";
	m_Price = L"";
	m_Inventory = 0;
	m_strFilter = _T("");
	m_strSort = _T("");
	length = 1;
	openLength = 0;
	canEdit = false;

	title[0] = _T("ID");
	title[1] = _T("CommNum");
	title[2] = _T("CommName");
	title[3] = _T("CommKind");
	title[4] = _T("Introduce");
	title[5] = _T("PhotoAddress");
	title[6] = _T("Origin");
	title[7] = _T("Specifications");
	title[8] = _T("Price");
	title[9] = _T("Inventory");

	ifstream inf("res/CommData.dat", ios_base::binary);
	//加入如果打开失败。。。
	real.clear();
	CommFileInfo Fi_temp;
	while (inf.read(reinterpret_cast<char*>(&Fi_temp), sizeof(Fi_temp))) {
		CommElem CE_temp;
		CE_temp.m_ID = Fi_temp.m_ID;
		CE_temp.m_CommNum = Fi_temp.m_CommNum;
		CE_temp.m_CommName = Fi_temp.m_CommName;
		CE_temp.m_CommKind = Fi_temp.m_CommKind;
		CE_temp.m_Introduce = Fi_temp.m_Introduce;
		CE_temp.m_PhotoAddress = Fi_temp.m_PhotoAddress;
		CE_temp.m_Origin = Fi_temp.m_Origin;
		CE_temp.m_Specifications = Fi_temp.m_Specifications;
		CE_temp.m_Price = Fi_temp.m_Price;
		CE_temp.m_Inventory = Fi_temp.m_Inventory;
		real.push_back(CE_temp);
	}
	inf.close();
	if (!real.empty()) {
		real.sort(cmp0);
		iterR = real.end();
		newID = (--iterR)->m_ID + 1;
	}
	else newID = 1;
}
CCommSet::~CCommSet() {
	ofstream outf("res/CommData.dat", ios_base::binary);
	CommFileInfo Fi_temp;
	list<CommElem>::iterator Ad_temp = real.begin();
	for (; Ad_temp != real.end(); Ad_temp++) {
		Fi_temp.m_ID = Ad_temp->m_ID;
		CStringToChar(Ad_temp->m_CommNum, Fi_temp.m_CommNum);
		CStringToChar(Ad_temp->m_CommName, Fi_temp.m_CommName);
		CStringToChar(Ad_temp->m_CommKind, Fi_temp.m_CommKind);
		CStringToChar(Ad_temp->m_Introduce, Fi_temp.m_Introduce);
		CStringToChar(Ad_temp->m_PhotoAddress, Fi_temp.m_PhotoAddress);
		CStringToChar(Ad_temp->m_Origin, Fi_temp.m_Origin);
		CStringToChar(Ad_temp->m_Specifications, Fi_temp.m_Specifications);
		CStringToChar(Ad_temp->m_Price, Fi_temp.m_Price);
		Fi_temp.m_Inventory = Ad_temp->m_Inventory;
		outf.write(reinterpret_cast<char*>(&Fi_temp), sizeof(Fi_temp));
	}
	real.clear();
	outf.close();
}

bool CCommSet::IsOpen() {
	if (openned.empty())return false;
	else return true;
}
bool CCommSet::IsEOF() {
	if (openned.empty() || iterO == openned.end())return true;
	else return false;
}
bool CCommSet::Open() {
	if (m_strFilter == _T("")) {
		std::list<CommElem>::iterator p = real.begin();
		for (; p != real.end(); p++)openned.push_back(*p);
	}
	else {
		std::list<CommElem>::iterator p = real.begin();
		for (; p != real.end(); p++) {
			CString str;
			str.Format(_T("%d"), m_Inventory);
			if (m_sFilterTitle == title[1] && m_sFilterKeyWord == p->m_CommNum) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[2] && m_sFilterKeyWord == p->m_CommName) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[3] && m_sFilterKeyWord == p->m_CommKind) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[4] && m_sFilterKeyWord == p->m_Introduce) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[5] && m_sFilterKeyWord == p->m_PhotoAddress) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[6] && m_sFilterKeyWord == p->m_Origin) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[7] && m_sFilterKeyWord == p->m_Specifications) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[8] && m_sFilterKeyWord == p->m_Price) {
				openned.push_back(*p);
			}
			else if (m_sFilterTitle == title[9] && m_sFilterKeyWord == str) {
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
		else if (m_strSort == title[7]) {
			openned.sort(cmp7);
		}
		else if (m_strSort == title[8]) {
			openned.sort(cmp8);
		}
		else if (m_strSort == title[9]) {
			openned.sort(cmp9);
		}
	}
	iterO = openned.begin();
	return true;
}
bool CCommSet::Close() {
	openned.clear();
	return true;
}
void CCommSet::AddNew() {
	canEdit = true;
	length++;
	now = openLength++;
	realNow = length - 1;
	CommElem CE_temp;
	real.push_back(CE_temp);
	iterR = real.end();
	iterR--;
}
void CCommSet::Edit() {
	canEdit = true;
}
void CCommSet::Update() {
	if (canEdit) {
		iterR->m_ID = newID++;
		iterR->m_CommNum = m_CommNum;
		iterR->m_CommName = m_CommName;
		iterR->m_CommKind = m_CommKind;
		iterR->m_Introduce = m_Introduce;
		iterR->m_PhotoAddress = m_PhotoAddress;
		iterR->m_Origin = m_Origin;
		iterR->m_Specifications = m_Specifications;
		iterR->m_Price = m_Price;
		iterR->m_Inventory = m_Inventory;
		canEdit = false;
	}
}
void CCommSet::Move(long pos) {
	if (pos <= openned.size()) {
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
		m_CommNum = iterO->m_CommNum;
		m_CommName = iterO->m_CommName;
		m_CommKind = iterO->m_CommKind;
		m_Introduce = iterO->m_Introduce;
		m_PhotoAddress = iterO->m_PhotoAddress;
		m_Origin = iterO->m_Origin;
		m_Specifications = iterO->m_Specifications;
		m_Price = iterO->m_Price;
		m_Inventory = iterO->m_Inventory;
	}
}
void CCommSet::Delete() {
	if (iterR != real.end())
		real.erase(iterR);
}
void CCommSet::MoveNext() {
	now++;
	int i = 0;
	iterO++;
	if (iterO != openned.end()) {
		iterR = real.begin();
		for (i = 0; iterR != real.end(); i++, iterR++)
			if (iterR->m_ID == iterO->m_ID)break;
		realNow = i;
		m_ID = iterO->m_ID;
		m_CommNum = iterO->m_CommNum;
		m_CommName = iterO->m_CommName;
		m_CommKind = iterO->m_CommKind;
		m_Introduce = iterO->m_Introduce;
		m_PhotoAddress = iterO->m_PhotoAddress;
		m_Origin = iterO->m_Origin;
		m_Specifications = iterO->m_Specifications;
		m_Price = iterO->m_Price;
		m_Inventory = iterO->m_Inventory;
	}
}
void CCommSet::GetFieldValue(short n, CString &str) {
	switch (n) {
	case 0:str.Format(_T("%d"), m_ID); break;
	case 1:str = m_CommNum; break;
	case 2:str = m_CommName; break;
	case 3:str = m_CommKind; break;
	case 4:str = m_Introduce; break;
	case 5:str = m_PhotoAddress; break;
	case 6:str = m_Origin; break;
	case 7:str = m_Specifications; break;
	case 8:str = m_Price; break;
	case 9:str.Format(_T("%d"), m_Inventory); break;
	}
}
int CCommSet::GetODBCFieldCount() {
	return 10;
}
void CCommSet::GetODBCFieldInfo(short n, CString &str) {
	str = title[n];
}
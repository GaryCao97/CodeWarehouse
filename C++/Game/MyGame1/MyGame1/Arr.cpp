#include "stdafx.h"
#include "Arr.h"

char Table[5][11] = {
	"�����ש���" ,
	"��  ��  ��" ,
	"�ǩ��贈��" ,
	"��  ��  ��" ,
	"�����ߩ���"
	//�����ש���
	//��  ��  ��
	//�ǩ��贈��
	//��  ��  ��
	//�����ߩ���
};
string Origin[4] = {
	"��֪���ĳ���1",
	"��֪���ĳ���2",
	"��֪���ĳ���3",
	"��֪���ĳ���4"
};
string SexY[2] = {
	"�Ա���",
	"�Ա�Ů"
};
string SexE[2] = {
	"����С��",
	"����Ů��"
};
string Menpai[MENPAI_NUM];
vector<TeacherCharacter> Master[MENPAI_NUM];


void InitMenpaiAndMaster() {
	Menpai[0] = "�˽�";
	Menpai[1] = "����";
	Menpai[2] = "�ؽ�";
	Menpai[3] = "��ͥ";
	Menpai[4] = "�ظ�";
	Menpai[5] = "���";
	Menpai[6] = "����";
	Menpai[7] = "������";
	Menpai[8] = "��ׯ��";
	Menpai[9] = "ħ��";
	TeacherCharacter tmp;
	//�˽�
	tmp.name = "̫���Ͼ�";
	Master[0].push_back(tmp);
	tmp.name = "����";
	Master[0].push_back(tmp);
	//����
	tmp.name = "Ԫʼ����";
	Master[1].push_back(tmp);
	//�ؽ�
	tmp.name = "ͨ�����";
	Master[2].push_back(tmp);
	//��ͥ
	tmp.name = "Ů�";
	Master[3].push_back(tmp);
	//�ظ�
	tmp.name = "����";
	Master[4].push_back(tmp);
	//���
	tmp.name = "����";
	Master[5].push_back(tmp);
	tmp.name = "׼��";
	Master[5].push_back(tmp);
	//����
	tmp.name = "��ü";
	Master[6].push_back(tmp);
	//������
	tmp.name = "���";
	Master[7].push_back(tmp);
	//��ׯ��
	tmp.name = "��Ԫ��";
	Master[8].push_back(tmp);
	//ħ��
	tmp.name = "�޲T";
	Master[9].push_back(tmp);
}
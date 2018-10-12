#pragma once


typedef struct {
	//�������� 
	int Qualification;	//���� 
	int Perception;		//���� 
	int Fortunate;		//���� 

	//�ɳ�����
	int Str;	//���� 
	int Dex;	//���� 
	int Con;	//���� 
	int Int;	//���� 

	//������������
	int HP;//��Ѫ/����ֵ
	int MP;//����/����ֵ
	int SP;//����ֵ
	long long Age;//����
	int Sex;//�Ա�
	int Exp;//����
	int Level;//�ȼ�
	int Origin;//����

	//�������� 
	int Attack;//������
	int Defence;//������
	int Hit;//����
	int Dodge;//����
	int Block;//��
	int attackSpeed;//�����ٶ�

	//���︽������
	int Merit;//����ֵ/ҵ��ֵ
	int Prestige;//����
	int Charm;//����ֵ
	char Fate[20];//Ե��
	int Menpai;
	int Master;//ʦ��
	int Incarnations;//ת������
}Pro;

typedef struct {
	//����ϵ�� 
	int AttackNum;
	int DefenceNum;
	int HitNum;
	int DodgeNum;
	int BlockNum;
	int attackSpeedNum;
	int HPNum;
	int MPNum;
}AbNum;

typedef struct {
	//��������ֵ
	int Lingshi;//��ʯ
	int Contribution;//ʦ�Ź���
	int Spirit;//������
}Consum;

class PlayerCharacter{
public:
	char Name[20];
	Pro Property;
	AbNum AbilityNum;
	Consum Consumables;
	bool isNew;
	//�������¼�
	PlayerCharacter();
	~PlayerCharacter();
	void PropertyInit();//�������Գ�ʼ��
	void UpdateProperty();//������������
};

class TeacherCharacter {
public:
	string name;
	int skillNum;
	string *skill;
};
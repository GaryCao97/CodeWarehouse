
class PlayerCharacter{
public:
	//�������� 
	int Qualification;	//���� 
	int Perception;		//���� 
	int Fortunate;		//���� 

	//�ɳ�����
	int Str;	//���� 
	int Dex;	//���� 
	int Con;	//���� 
	int Int;	//���� 

	//�������� 
	int Attack;//������
	int Defence;//������
	int Hit;//����
	int Dodge;//����
	int Block;//��
	int attackSpeed;//�����ٶ�

	//����ϵ�� 
	int AttackNum;
	int DefenceNum;
	int HitNum;
	int DodgeNum;
	int BlockNum;
	int attackSpeedNum;
	int HPNum;
	int MPNum;

	//������������
	int HP;//��Ѫ/����ֵ
	int MP;//����/����ֵ
	int SP;//����ֵ
	long long Age;//����
	int Exp;//����
	int Level;//�ȼ�
	int Origin;

	//���︽������
	int Merit;//����ֵ/ҵ��ֵ
	int Prestige;//����
	int Charm;//����ֵ
	char *Fate;//Ե��
	int Master;//ʦ��
	int Incarnations;//ת������

	//��������ֵ
	int Lingshi;//��ʯ
	int Contribution;//ʦ�Ź���
	int Spirit;//������

	//�������¼�
	void PropertyInit();//�������Գ�ʼ��
	void UpdateProperty();
};



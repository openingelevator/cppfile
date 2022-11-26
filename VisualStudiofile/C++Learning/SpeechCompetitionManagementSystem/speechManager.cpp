#include"speechManager.h"
SpeechManager::SpeechManager()
{
	//��ʼ����Ա����
	this->initSpeech();
	//����12��ѡ��
	this->createSpeaker();
	//���������¼
	this->loadRecord();
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::initSpeech()
{
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//�����ÿ�
	this->m_Index = 1;
	//��ռ�¼����
	this->m_Record.clear();
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i <nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//����ѡ�ֶ���
		Speaker sp;
		sp.setName(name);
		//���õ÷�
		for (int j = 0; j < 2; j++)
		{
			//����ʼ�÷���Ϊ0
			sp.setScore(0, j);
		}

		//����ѡ�ֱ�Ų����뵽v1������
		this->v1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧ��ѡ�ַ��뵽map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}

void SpeechManager::startSpeech()
{
	//��һ�ֱ���
	//1����ǩ
	speechDraw();

	//2������
	speechContest();

	//3����ʾ�������
	showScore();
	
	//�ڶ��ֱ���
	this->m_Index++;
	//1����ǩ
	speechDraw();
	//2������
	speechContest();
	//3����ʾ���ս��
	showScore();
	//����������ļ���
	saveRecord();

	//���ñ���
	//��ʼ������
	this->initSpeech();

	//����ѡ��
	this->createSpeaker();

	//��ȡ�����¼
	this->loadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "���ڽ��е�<<"<<this->m_Index<<">>" <<"�ֳ�ǩ" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳������" << endl;
	if (this->m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------" << endl;
	system("pause");
}

void SpeechManager::speechContest()
{
	cout << "----------------��<<" << this->m_Index << ">>�ֱ�����ʽ��ʼ----------------" << endl;

	//׼����ʱ�������С��ɼ�
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//��¼��Ա

	//����ѡ������
	vector<int>v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//�������в���ѡ�ֿ�ʼ����
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double scores = (rand() % 401 + 600) / 10.f;
			d.push_back(scores);
		}

		//�Է�����������
		sort(d.begin(), d.end(),Greater());
		//ȥ����߷�����ͷ�
		d.pop_back();
		d.pop_front();

		//�Է�����ƽ���õ����շ���
		double sum = accumulate(d.begin(), d.end(), 0);
		double average = sum / (double)d.size();

		//��ӡƽ����
		/*cout << "��ţ�  " << *it << "������  " << this->m_Speaker[*it].getName() << "��ȡ��ƽ����Ϊ  " << average << endl;*/
		//��ƽ���ַ��뵽map������
		this->m_Speaker[*it].setScore(average, this->m_Index - 1);

		//��������ݷ��뵽��ʱ��С��������
		//��ֵΪ�÷֣�valueΪ����ѡ�ֵı��
		groupScore.insert(make_pair(average, *it));
		//ÿ����ѡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << "������" << this->m_Speaker[it->second].getName() 
					<< "�����ɼ���" << this->m_Speaker[it->second].getScore(this->m_Index-1) << endl;
			}

			//ȡ��ǰ���� ������һ��������
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();//�������
			cout << endl;
		}
	}
	cout << "----------------��" << this->m_Index << "�ֱ�������----------------" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "----------------��" << this->m_Index << "�ֽ�����ѡ����Ϣ����----------------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << "������" << this->m_Speaker[*it].getName() << "�÷֣�" << this->m_Speaker[*it].getScore(this->m_Index - 1) << endl;

	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	//��ÿ���˵�����д�뵽�ļ���
	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].getScore(1) << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�ѱ���" << endl;

	//�����ļ���Ϊ�յ�״̬
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	//��ȡ�ļ�
	ifstream ifs("speech.csv", ios::in);

	//�ļ��޷������
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ�������";
		ifs.close();
		return;
	}

	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	//����ȡ�ĵ����ַ��Ż�����
	ifs.putback(ch);

	string data;
	int index = 0;

	while (ifs>>data)
	{
		//��Ž�ȡ���ַ���
		vector<string>v;

		//�鵽����λ�õı���
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos=data.find(",", start);
			if (pos == -1)
			{
				//û���ҵ������
				break;
			}
			string temp= data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����߼�¼Ϊ��" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "��" <<
			" �ھ���� " << setw(8) << this->m_Record[i][0] << " �÷� " << setw(8) <<this->m_Record[i][1] << " " <<
			" �Ǿ���� " << setw(8) <<this->m_Record[i][2] << " �÷� " << setw(8) <<this->m_Record[i][3] << " " <<
			" ������� " << setw(8) <<this->m_Record[i][4] << " �÷� " << setw(8) <<this->m_Record[i][5] << " " << endl;
	}
	system("pause");
	system("cls");

}

void SpeechManager::clearRecord()
{
	cout << "ȷ�����?" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//���ñ���
        //��ʼ������
		this->initSpeech();

		//����ѡ��
		this->createSpeaker();

		//��ȡ�����¼
		this->loadRecord();

		//��ʾ�û�������ѳɹ�
		cout << "��ճɹ�" << endl;

	}
	system("pause");
	system("cls");
}

//void SpeechManager::printTest()
//{
//	for (map<int, Speaker>::iterator it = this->m_Speaker.begin(); it != this->m_Speaker.end(); it++)
//	{
//		cout << "ѡ�ֱ��" << it->first << "����" << it->second.getName() << "��һ�ַ���" << it->second.getScore(0) << endl;
//		
//	}
// 
//}

void SpeechManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� *************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;

}
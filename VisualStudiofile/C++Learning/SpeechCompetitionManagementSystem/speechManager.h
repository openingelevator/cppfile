#pragma once
#include<iostream>
#include<vector>
#include<Map>
#include<string>
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
#include<iomanip>
#include"speaker.h"
using namespace std;
//�º���
class Greater
{
public:
	bool operator()(double val1, double val2)
	{
		return val1 > val2;
	}
};
class SpeechManager
{
public:
	//���캯��
	SpeechManager();
	//��������
	~SpeechManager();
	//��ʼ����Ա����
	void initSpeech();
	//չʾ�˵�����
	void showMenu();
	//�˳�����
	void exitSystem();
	//����ѡ��
	void createSpeaker();
	//����--��ӡѡ����Ϣ
	//void printTest();
	//���Ʊ������̵���Ҫ����
	void startSpeech();
	//��ǩ����
	void speechDraw();
	//��������
	void speechContest();
	//��ʾ�÷�
	void showScore();
	//�����ļ���¼
	void saveRecord();
	//��ȡ�ļ���¼
	void loadRecord();
	//�鿴�����¼
	void showRecord();
	//��ռ�¼
	void clearRecord();

private:
	//�����һ�ֽ���ѡ�ֵı������
	vector<int>v1;
	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;
	//ʤ��ѡ������
	vector<int>vVictory;

    //��ű���Լ���Ӧ����ѡ������
	map<int, Speaker>m_Speaker;
	//��ű�������
	int  m_Index;

	//��������¼������
	map<int, vector<string>>m_Record;
	
	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

};
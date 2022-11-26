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
//仿函数
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
	//构造函数
	SpeechManager();
	//析构函数
	~SpeechManager();
	//初始化成员属性
	void initSpeech();
	//展示菜单函数
	void showMenu();
	//退出程序
	void exitSystem();
	//创建选手
	void createSpeaker();
	//测试--打印选手信息
	//void printTest();
	//控制比赛流程的主要函数
	void startSpeech();
	//抽签函数
	void speechDraw();
	//比赛函数
	void speechContest();
	//显示得分
	void showScore();
	//保存文件记录
	void saveRecord();
	//读取文件记录
	void loadRecord();
	//查看往届记录
	void showRecord();
	//清空记录
	void clearRecord();

private:
	//保存第一轮晋级选手的编号容器
	vector<int>v1;
	//第一轮晋级选手编号容器
	vector<int>v2;
	//胜出选手容器
	vector<int>vVictory;

    //存放编号以及对应具体选手容器
	map<int, Speaker>m_Speaker;
	//存放比赛轮数
	int  m_Index;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;
	
	//判断文件是否为空
	bool fileIsEmpty;

};
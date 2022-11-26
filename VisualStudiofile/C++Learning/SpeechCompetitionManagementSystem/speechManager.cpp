#include"speechManager.h"
SpeechManager::SpeechManager()
{
	//初始化成员属性
	this->initSpeech();
	//创建12名选手
	this->createSpeaker();
	//加载往届记录
	this->loadRecord();
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::initSpeech()
{
	//容器置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//轮数置空
	this->m_Index = 1;
	//清空记录容器
	this->m_Record.clear();
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i <nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建选手对象
		Speaker sp;
		sp.setName(name);
		//设置得分
		for (int j = 0; j < 2; j++)
		{
			//将初始得分置为0
			sp.setScore(0, j);
		}

		//创建选手编号并放入到v1容器中
		this->v1.push_back(i + 10001);

		//选手编号以及对应的选手放入到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}

void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1、抽签
	speechDraw();

	//2、比赛
	speechContest();

	//3、显示晋级结果
	showScore();
	
	//第二轮比赛
	this->m_Index++;
	//1、抽签
	speechDraw();
	//2、比赛
	speechContest();
	//3、显示最终结果
	showScore();
	//保存分数到文件中
	saveRecord();

	//重置比赛
	//初始化属性
	this->initSpeech();

	//创建选手
	this->createSpeaker();

	//获取往届记录
	this->loadRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "正在进行第<<"<<this->m_Index<<">>" <<"轮抽签" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下" << endl;
	if (this->m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
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
	cout << "----------------第<<" << this->m_Index << ">>轮比赛正式开始----------------" << endl;

	//准备临时容器存放小组成绩
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//记录人员

	//比赛选手容器
	vector<int>v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//遍历所有参赛选手开始比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double scores = (rand() % 401 + 600) / 10.f;
			d.push_back(scores);
		}

		//对分数进行排序
		sort(d.begin(), d.end(),Greater());
		//去掉最高分与最低分
		d.pop_back();
		d.pop_front();

		//对分数求平均得到最终分数
		double sum = accumulate(d.begin(), d.end(), 0);
		double average = sum / (double)d.size();

		//打印平均分
		/*cout << "编号：  " << *it << "姓名：  " << this->m_Speaker[*it].getName() << "获取的平均分为  " << average << endl;*/
		//将平均分放入到map容器中
		this->m_Speaker[*it].setScore(average, this->m_Index - 1);

		//将打分数据放入到临时的小组容器中
		//键值为得分，value为具体选手的编号
		groupScore.insert(make_pair(average, *it));
		//每六人选出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << "姓名：" << this->m_Speaker[it->second].getName() 
					<< "比赛成绩：" << this->m_Speaker[it->second].getScore(this->m_Index-1) << endl;
			}

			//取走前三名 放入下一个容器中
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

			groupScore.clear();//容器清空
			cout << endl;
		}
	}
	cout << "----------------第" << this->m_Index << "轮比赛结束----------------" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "----------------第" << this->m_Index << "轮晋级的选手信息如下----------------" << endl;
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
		cout << "选手编号：" << *it << "姓名：" << this->m_Speaker[*it].getName() << "得分：" << this->m_Speaker[*it].getScore(this->m_Index - 1) << endl;

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

	//将每个人的数据写入到文件中
	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].getScore(1) << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();

	cout << "记录已保存" << endl;

	//更改文件不为空的状态
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	//读取文件
	ifstream ifs("speech.csv", ios::in);

	//文件无法打开情况
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在";
		ifs.close();
		return;
	}

	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;
	//将读取的单个字符放回流中
	ifs.putback(ch);

	string data;
	int index = 0;

	while (ifs>>data)
	{
		//存放截取的字符串
		vector<string>v;

		//查到逗号位置的变量
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos=data.find(",", start);
			if (pos == -1)
			{
				//没有找到的情况
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
		cout << "文件不存在，或者记录为空" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届" <<
			" 冠军编号 " << setw(8) << this->m_Record[i][0] << " 得分 " << setw(8) <<this->m_Record[i][1] << " " <<
			" 亚军编号 " << setw(8) <<this->m_Record[i][2] << " 得分 " << setw(8) <<this->m_Record[i][3] << " " <<
			" 季军编号 " << setw(8) <<this->m_Record[i][4] << " 得分 " << setw(8) <<this->m_Record[i][5] << " " << endl;
	}
	system("pause");
	system("cls");

}

void SpeechManager::clearRecord()
{
	cout << "确认清空?" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//重置比赛
        //初始化属性
		this->initSpeech();

		//创建选手
		this->createSpeaker();

		//获取往届记录
		this->loadRecord();

		//提示用户，清空已成功
		cout << "清空成功" << endl;

	}
	system("pause");
	system("cls");
}

//void SpeechManager::printTest()
//{
//	for (map<int, Speaker>::iterator it = this->m_Speaker.begin(); it != this->m_Speaker.end(); it++)
//	{
//		cout << "选手编号" << it->first << "姓名" << it->second.getName() << "第一轮分数" << it->second.getScore(0) << endl;
//		
//	}
// 
//}

void SpeechManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛 *************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;

}
#include<iostream>
#include<string>
using namespace std;
//const int MAX = 1000;
#define MAX 1000;


void showMenu()
{
	cout << "***通讯录管理系统***" << endl;
	cout << "***1.添加联系人*****" << endl;
	cout << "***2.显示联系人*****" << endl;
	cout << "***3.删除联系人*****" << endl;
	cout << "***4.查找联系人*****" << endl;
	cout << "***5.修改联系人*****" << endl;
	cout << "***6.清空联系人*****" << endl;
	cout << "***0.退出通讯录*****" << endl;
	cout << "********************\n" << endl;
}

struct Person
{
	string name;
	int sex;
	int age;
	long long tel;
	string address;
};

struct AddressBooks//通讯录结构体
{
	struct Person PersonArray[MAX];
	int Size;
}abs1;//结构体变量创建方式1，这里虽然没啥用啊


/*向通讯录中添加新人，信息包括（
姓名、性别、年龄、联系电话、家庭住址）
最多记录1000人*/
void AddCont(AddressBooks *abs)//地址传递，可以修改主函数中的数据
//  *abs 写成abs[]也行
{
	if (abs->Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;//这里 不错啊
	}
	else
	{
		string iname;
		cout << "请输入姓名：" << endl;
		cin >> iname;
		abs->PersonArray[abs->Size].name = iname;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int isex = 0;
		while (1)
		{
			cin >> isex;
			if (isex == 1 || isex == 2)
			{
				abs->PersonArray[abs->Size].sex = isex;
				break;
			}
			else
			{
				cout << "输入有误！" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int iage = 0;
		cin >> iage;
		abs->PersonArray[abs->Size].age = iage;

		cout << "请输入联系电话：" << endl;
		long long itel = 0;
		cin >> itel;
		abs->PersonArray[abs->Size].tel = itel;

		cout << "请输入家庭住址：" << endl;
		string iaddress;
		cin >> iaddress;
		abs->PersonArray[abs->Size].address = iaddress;

		abs->Size++;

		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}	
}


void ShowCont(AddressBooks abs[])
{
	if (abs->Size == 0)
	{
		cout << "空空如也！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "姓名：" << abs->PersonArray[i].name << "\t";
			cout << "性别：" << (abs->PersonArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->PersonArray[i].age << "\t";
			cout << "电话：" << abs->PersonArray[i].tel << "\t";
			cout << "地址：" << abs->PersonArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}


int IsExist(AddressBooks *abs, string sname)
{
//判断是否存在查询的人员，存在返回在数组中索引位置，不存在返回-1
	for (int i = 0; i < abs->Size; i++)
	{
		if (abs->PersonArray[i].name == sname)
		{
			return i;
		}
	}
	return -1;
}

void DelCont(AddressBooks *abs)//按照姓名进行删除指定联系人
{
	cout << "请输入你要删除的联系人：" << endl;
	string dname;
	cin >> dname;

	int ret = IsExist(abs, dname);
	if (ret != -1)
	{
		for (int i = ret; i < abs->Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i + 1];//后面的整体向前移动
		}
		abs->Size--;
		cout << "HHHAAA删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！@！" << endl;
	}
	system("pause");
	system("cls");
}


void SrhCont(AddressBooks *abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string sname;
	cin >> sname;

	int ret = IsExist(abs, sname);
	if (ret != -1)
	{
		cout << "姓名：" << abs->PersonArray[ret].name << "\t";
		cout << "性别：" << abs->PersonArray[ret].sex << "\t";
		cout << "年龄：" << abs->PersonArray[ret].age << "\t";
		cout << "电话：" << abs->PersonArray[ret].tel << "\t";
		cout << "住址：" << abs->PersonArray[ret].address << endl;
	}
	else
	{
		cout << "查无此人！@！" << endl;
	}
	system("pause");
	system("cls");
}


void ModCont(AddressBooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string mname;
	cin >> mname;

	int ret = IsExist(abs, mname);
	if (ret != -1)
	{
		string mname;
		cout << "请输入姓名：" << endl;
		cin >> mname;
		abs->PersonArray[ret].name = mname;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int msex = 0;
		while (1)
		{
			cin >> msex;
			if (msex == 1 || msex == 2)
			{
				abs->PersonArray[abs->Size].sex = msex;
				break;
			}
			else
			{
				cout << "输入有误！" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int mage = 0;
		cin >> mage;
		abs->PersonArray[ret].age = mage;

		cout << "请输入联系电话：" << endl;
		long long mtel = 0;
		cin >> mtel;
		abs->PersonArray[ret].tel = mtel;

		cout << "请输入家庭住址：" << endl;
		string maddress;
		cin >> maddress;
		abs->PersonArray[ret].address = maddress;
		cout << "添加成功！" << endl;
	}
	else
	{
		cout << "查无此人！@！" << endl;
	}
	system("pause");
	system("cls");
}


void ClsCont(AddressBooks* abs)
{
	abs->Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}

void FuckQuit()
{
	cout << "WDNMD你敢消遣洒家，输入错误，程序即将返回。。。" << endl;
	system("pause");
	system("cls");
}

void Quit()
{
	cout << "感谢使用！下次再会！" << endl;
	system("pause");
}

int main()
{
	int select = 0;
	struct AddressBooks abs;//创建结构体变量时struct可省略
	abs.Size = 0;//结构体变量通过"."访问成员
	while(1)
	{	
		showMenu();
		cout << "请输入选择项：" << endl;
		cin >> select;
		switch (select)
		{
			case 0://退出通讯录
				Quit();
				return 0;
				break;
			case 1://添加联系人
				AddCont(&abs);
				break;
			case 2://显示联系人
				ShowCont(&abs);
				break;
			case 3://删除联系人
				DelCont(&abs);
				break;
			case 4://查找联系人
				SrhCont(&abs);
				break;
			case 5://修改联系人
				ModCont(&abs);
				break;
			case 6://清空联系人
				break;
				ClsCont(&abs);
			default:
				FuckQuit();
				break;
		}
	}
	system("pause");
	return 0;
}
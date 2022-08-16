#include<iostream>
#include<string>
using namespace std;
//const int MAX = 1000;
#define MAX 1000;


void showMenu()
{
	cout << "***ͨѶ¼����ϵͳ***" << endl;
	cout << "***1.�����ϵ��*****" << endl;
	cout << "***2.��ʾ��ϵ��*****" << endl;
	cout << "***3.ɾ����ϵ��*****" << endl;
	cout << "***4.������ϵ��*****" << endl;
	cout << "***5.�޸���ϵ��*****" << endl;
	cout << "***6.�����ϵ��*****" << endl;
	cout << "***0.�˳�ͨѶ¼*****" << endl;
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

struct AddressBooks//ͨѶ¼�ṹ��
{
	struct Person PersonArray[MAX];
	int Size;
}abs1;//�ṹ�����������ʽ1��������Ȼûɶ�ð�


/*��ͨѶ¼��������ˣ���Ϣ������
�������Ա����䡢��ϵ�绰����ͥסַ��
����¼1000��*/
void AddCont(AddressBooks *abs)//��ַ���ݣ������޸��������е�����
//  *abs д��abs[]Ҳ��
{
	if (abs->Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;//���� ����
	}
	else
	{
		string iname;
		cout << "������������" << endl;
		cin >> iname;
		abs->PersonArray[abs->Size].name = iname;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
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
				cout << "��������" << endl;
			}
		}

		cout << "���������䣺" << endl;
		int iage = 0;
		cin >> iage;
		abs->PersonArray[abs->Size].age = iage;

		cout << "��������ϵ�绰��" << endl;
		long long itel = 0;
		cin >> itel;
		abs->PersonArray[abs->Size].tel = itel;

		cout << "�������ͥסַ��" << endl;
		string iaddress;
		cin >> iaddress;
		abs->PersonArray[abs->Size].address = iaddress;

		abs->Size++;

		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}	
}


void ShowCont(AddressBooks abs[])
{
	if (abs->Size == 0)
	{
		cout << "�տ���Ҳ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "������" << abs->PersonArray[i].name << "\t";
			cout << "�Ա�" << (abs->PersonArray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->PersonArray[i].age << "\t";
			cout << "�绰��" << abs->PersonArray[i].tel << "\t";
			cout << "��ַ��" << abs->PersonArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}


int IsExist(AddressBooks *abs, string sname)
{
//�ж��Ƿ���ڲ�ѯ����Ա�����ڷ���������������λ�ã������ڷ���-1
	for (int i = 0; i < abs->Size; i++)
	{
		if (abs->PersonArray[i].name == sname)
		{
			return i;
		}
	}
	return -1;
}

void DelCont(AddressBooks *abs)//������������ɾ��ָ����ϵ��
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string dname;
	cin >> dname;

	int ret = IsExist(abs, dname);
	if (ret != -1)
	{
		for (int i = ret; i < abs->Size; i++)
		{
			abs->PersonArray[i] = abs->PersonArray[i + 1];//�����������ǰ�ƶ�
		}
		abs->Size--;
		cout << "HHHAAAɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�@��" << endl;
	}
	system("pause");
	system("cls");
}


void SrhCont(AddressBooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string sname;
	cin >> sname;

	int ret = IsExist(abs, sname);
	if (ret != -1)
	{
		cout << "������" << abs->PersonArray[ret].name << "\t";
		cout << "�Ա�" << abs->PersonArray[ret].sex << "\t";
		cout << "���䣺" << abs->PersonArray[ret].age << "\t";
		cout << "�绰��" << abs->PersonArray[ret].tel << "\t";
		cout << "סַ��" << abs->PersonArray[ret].address << endl;
	}
	else
	{
		cout << "���޴��ˣ�@��" << endl;
	}
	system("pause");
	system("cls");
}


void ModCont(AddressBooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string mname;
	cin >> mname;

	int ret = IsExist(abs, mname);
	if (ret != -1)
	{
		string mname;
		cout << "������������" << endl;
		cin >> mname;
		abs->PersonArray[ret].name = mname;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
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
				cout << "��������" << endl;
			}
		}

		cout << "���������䣺" << endl;
		int mage = 0;
		cin >> mage;
		abs->PersonArray[ret].age = mage;

		cout << "��������ϵ�绰��" << endl;
		long long mtel = 0;
		cin >> mtel;
		abs->PersonArray[ret].tel = mtel;

		cout << "�������ͥסַ��" << endl;
		string maddress;
		cin >> maddress;
		abs->PersonArray[ret].address = maddress;
		cout << "��ӳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�@��" << endl;
	}
	system("pause");
	system("cls");
}


void ClsCont(AddressBooks* abs)
{
	abs->Size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}

void FuckQuit()
{
	cout << "WDNMD�����ǲ���ң�������󣬳��򼴽����ء�����" << endl;
	system("pause");
	system("cls");
}

void Quit()
{
	cout << "��лʹ�ã��´��ٻᣡ" << endl;
	system("pause");
}

int main()
{
	int select = 0;
	struct AddressBooks abs;//�����ṹ�����ʱstruct��ʡ��
	abs.Size = 0;//�ṹ�����ͨ��"."���ʳ�Ա
	while(1)
	{	
		showMenu();
		cout << "������ѡ���" << endl;
		cin >> select;
		switch (select)
		{
			case 0://�˳�ͨѶ¼
				Quit();
				return 0;
				break;
			case 1://�����ϵ��
				AddCont(&abs);
				break;
			case 2://��ʾ��ϵ��
				ShowCont(&abs);
				break;
			case 3://ɾ����ϵ��
				DelCont(&abs);
				break;
			case 4://������ϵ��
				SrhCont(&abs);
				break;
			case 5://�޸���ϵ��
				ModCont(&abs);
				break;
			case 6://�����ϵ��
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
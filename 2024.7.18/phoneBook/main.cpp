#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

struct Person{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct PhoneBook {
    Person personArray[MAX];
    int size;
};

void addPerson(PhoneBook *pbk) {
    if(pbk->size>1000) {
        cout << "ͨѶ¼�������޷����" << endl;
    }
    else {
        string name;
        cout << "������������" << endl;
        cin >> name;
        pbk->personArray[pbk->size].name=name;

        int sex;
        cout << "�������Ա�" << endl;
        cout << "1 -- ��" << endl;
        cout << "2 -- Ů" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                pbk->personArray[pbk->size].sex=sex;
                break;
            }
            cout << "������������������";
        }

        int age = 0;
        cout << "���������䣺" << endl;
        cin >> age;
        pbk->personArray[pbk->size].age=age;

        string phone;
        cout << "��������ϵ�绰��" << endl;
        cin >> phone;
        pbk->personArray[pbk->size].phone=phone;

        string address;
        cout << "�������ͥסַ��" << endl;
        cin >> address;
        pbk->personArray[pbk->size].address=address;

        pbk->size++;
        cout << "��ӳɹ�" << endl;
    }
}

void showPerson(PhoneBook *pbk) {
    if (pbk->size == 0)
    {
        cout << "ͨѶ¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < pbk->size; i++)
        {
            cout << "������" << pbk->personArray[i].name << "\t";
            cout << "�Ա�" << (pbk->personArray[i].sex == 1 ? "��" : "Ů") << "\t";
            cout << "���䣺" << pbk->personArray[i].age << "\t";
            cout << "�绰��" << pbk->personArray[i].phone << "\t";
            cout << "סַ��" << pbk->personArray[i].address << endl;
        }
    }
}

void showMenu() {
    cout << "*************************" << endl;
    cout << "*****  1�������ϵ��  *****" << endl;
    cout << "*****  2����ʾ��ϵ��  *****" << endl;
    cout << "*****  3��ɾ����ϵ��  *****" << endl;
    cout << "*****  4��������ϵ��  *****" << endl;
    cout << "*****  5���޸���ϵ��  *****" << endl;
    cout << "*****  6�������ϵ��  *****" << endl;
    cout << "*****  0���˳�ͨѶ¼  *****" << endl;
    cout << "*************************" << endl;
}

int isExist(PhoneBook *pbk,string name) {
    for(int i=0;i<pbk->size;i++) {
        if(pbk->personArray[i].name==name) return i;
    }
    return -1;
}

void deletePerson(PhoneBook *pbk) {
    cout << "��������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;

    int ret=isExist(pbk,name);
    if(ret!=-1) {
        for(int i=ret;i<pbk->size;i++) {
            pbk->personArray[i]=pbk->personArray[i+1];
        }
        pbk->size--;
        cout << "ɾ���ɹ�" << endl;
    }
    else {
        cout << "���޴���" << endl;
    }
}

void findPerson(PhoneBook *pbk) {
    cout << "��������Ҫ��ѯ����ϵ��" << endl;
    string name;
    cin >> name;

    int ret=isExist(pbk,name);
    if(ret!=-1) {
        cout << "������" << pbk->personArray[ret].name << "\t";
        cout << "�Ա�" << (pbk->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
        cout << "���䣺" << pbk->personArray[ret].age << "\t";
        cout << "�绰��" << pbk->personArray[ret].phone << "\t";
        cout << "סַ��" << pbk->personArray[ret].address << endl;
    }
    else {
        cout << "���޴���" << endl;
    }
}

int main() {
    PhoneBook pbk;
    pbk.size=0;
    while (true){
        showMenu();
        int select;
        cin >> select;
        switch (select) {
            case 1:
                addPerson(&pbk);
                break;
            case 2:
                showPerson(&pbk);
                break;
            case 3:
                deletePerson(&pbk);
                break;
            case 4:
                findPerson(&pbk);
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                cout << "��ӭ�´�ʹ��";
                return 0;
        }
    }
}

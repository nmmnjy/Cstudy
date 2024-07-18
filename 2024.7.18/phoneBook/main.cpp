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
        cout << "通讯录已满，无法添加" << endl;
    }
    else {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        pbk->personArray[pbk->size].name=name;

        int sex;
        cout << "请输入性别：" << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                pbk->personArray[pbk->size].sex=sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }

        int age = 0;
        cout << "请输入年龄：" << endl;
        cin >> age;
        pbk->personArray[pbk->size].age=age;

        string phone;
        cout << "请输入联系电话：" << endl;
        cin >> phone;
        pbk->personArray[pbk->size].phone=phone;

        string address;
        cout << "请输入家庭住址：" << endl;
        cin >> address;
        pbk->personArray[pbk->size].address=address;

        pbk->size++;
        cout << "添加成功" << endl;
    }
}

void showPerson(PhoneBook *pbk) {
    if (pbk->size == 0)
    {
        cout << "通讯录为空" << endl;
    }
    else
    {
        for (int i = 0; i < pbk->size; i++)
        {
            cout << "姓名：" << pbk->personArray[i].name << "\t";
            cout << "性别：" << (pbk->personArray[i].sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << pbk->personArray[i].age << "\t";
            cout << "电话：" << pbk->personArray[i].phone << "\t";
            cout << "住址：" << pbk->personArray[i].address << endl;
        }
    }
}

void showMenu() {
    cout << "*************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "*************************" << endl;
}

int isExist(PhoneBook *pbk,string name) {
    for(int i=0;i<pbk->size;i++) {
        if(pbk->personArray[i].name==name) return i;
    }
    return -1;
}

void deletePerson(PhoneBook *pbk) {
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret=isExist(pbk,name);
    if(ret!=-1) {
        for(int i=ret;i<pbk->size;i++) {
            pbk->personArray[i]=pbk->personArray[i+1];
        }
        pbk->size--;
        cout << "删除成功" << endl;
    }
    else {
        cout << "查无此人" << endl;
    }
}

void findPerson(PhoneBook *pbk) {
    cout << "请输入您要查询的联系人" << endl;
    string name;
    cin >> name;

    int ret=isExist(pbk,name);
    if(ret!=-1) {
        cout << "姓名：" << pbk->personArray[ret].name << "\t";
        cout << "性别：" << (pbk->personArray[ret].sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << pbk->personArray[ret].age << "\t";
        cout << "电话：" << pbk->personArray[ret].phone << "\t";
        cout << "住址：" << pbk->personArray[ret].address << endl;
    }
    else {
        cout << "查无此人" << endl;
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
                cout << "欢迎下次使用";
                return 0;
        }
    }
}

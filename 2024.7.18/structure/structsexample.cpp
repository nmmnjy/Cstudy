#include <bits/stdc++.h>
using namespace  std;

struct Student {
    string name;
    int score;
};

struct Teacher {
    string name;
    Student sArray[5];
};

void acclocateT(Teacher t[3],int length){
    string tName="教师";
    string sName="学生";
    string nameSeed="ABCDE";
    for(int i=0;i<length;i++) {
        t[i].name=tName+nameSeed[i];
        for (int j=0;j<5;j++) {
            t[i].sArray[j].name=sName+nameSeed[j];
            t[i].sArray[j].score=rand()%100;
        }
    }
}

void printTeachers(Teacher t[3],int length) {
    for(int i=0;i<length;i++) {
        cout<<t[i].name<<endl;
        for(int j=0;j<5;j++) {
            cout<<t[i].sArray[j].name<<"分数"<<t[i].sArray[j].score<<endl;
        }
    }
}

int main() {
    //随机数种子
    srand((unsigned int)time(NULL));
    Teacher tArray[3];
    int len=sizeof(tArray)/sizeof(tArray[0]);
    //给老师赋值
    acclocateT(tArray,len);
    printTeachers(tArray,len);
    return 0;
}
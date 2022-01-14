#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//设计联系人结构体
struct Person
{
    //name
    string m_Name;
    //sex  1 male   2 female
    int m_Sex;
    //age
    int m_Age;
    //tele
    string m_Phone;
    //address
    string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
    //保存的的联系人数组
    struct Person personArray[MAX];
    
    //通讯录中当前记录联系人个数
    int m_Size;
};



//void showMenu
//function:show Menu GUI

void showMenu()
{
    cout<<"****************************"<<endl;
    cout<<"*****  1、添加联系人   *****"<<endl;
    cout<<"*****  2、显示联系人   *****"<<endl;
    cout<<"*****  3、删除联系人   *****"<<endl;
    cout<<"*****  4、查找联系人   *****"<<endl;
    cout<<"*****  5、修改联系人   *****"<<endl;
    cout<<"*****  6、清空联系人   *****"<<endl;
    cout<<"*****  0、退出通讯录   *****"<<endl;
    cout<<"****************************"<<endl;
}


int main()
{
    int select = 0;//choose

    while(true)
    {
        showMenu();

    cin >> select;
    
    switch(select)
    {
        case 1:     //1、添加联系人
            break;
        case 2:     //2、显示联系人 
            break;
        case 3:     //3、删除联系人
            break;
        case 4:     //4、查找联系人
            break;
        case 5:     //5、修改联系人
            break;
        case 6:     //6、清空联系人
            break;
        case 0:     //0、退出通讯录
            cout <<"欢迎下次使用"<<endl;
            system("pause");
            return 0;
            break;
        default:
            break;
    }
    }



    system("pause");
}
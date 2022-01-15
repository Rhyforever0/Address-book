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

//1.添加联系人
void addPerson(Addressbooks * abs)
{
    //判断通讯录是否满
    if(abs->m_Size==MAX)
    {
        cout<<"通讯录已满!"<<endl;
        return;
    }
    else
    {
        //add person
        //name
        string name;
        cout<<"请输入姓名:  "<<endl;
        cin >>name;
        abs->personArray[abs->m_Size].m_Name=name;//指针访问

        //sex
        cout<<"请输入性别:  "<<endl;
        cout<<"1---男  "    <<endl;
        cout<<"2---女  "    <<endl;
        
        int sex = 0;
        
        while(true)
        {
            //如果输入1或2可退出循环
            //有误则重新输入
            cin >> sex;
            if(sex == 1 || sex == 2)
        {
            abs->personArray[abs->m_Size].m_Sex=sex;
            break;
        }
            cout<<"性别有误，请重新输入"<<endl;
        }


        //age
        cout<<"请输入年龄:  "<<endl;
        int age=0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age=age;


        //tele
        cout<<"请输入电话:  "<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone=phone;

        //address
        cout<<"请输入家庭住址:"<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr=address;

        //更新通讯录人数
        abs->m_Size++;

        cout<<"添加成功"<<endl;

        system("pause");
        system("cls");//清屏操作


    }
}

//2.显示联系人
void showPerson(Addressbooks *abs)
{
    if(abs->m_Size == 0)
    {
        cout<<"当前记录为空"<<endl;
    }

    else
    {
        for(int i = 0; i<abs->m_Size ;i++)
        {
            cout<<"姓名:  "<<abs->personArray[i].m_Name<<"\t";
            cout<<"性别:  "<<( abs->personArray[i].m_Sex == 1 ?"男":"女" )<<"\t";
            cout<<"年龄:  "<<abs->personArray[i].m_Age<<"\t";
            cout<<"电话:  "<<abs->personArray[i].m_Phone<<"\t";
            cout<<"住址:  "<<abs->personArray[i].m_Addr<<endl;
        }
    }
    
    system("pause");
    system("cls");


}

//3.删除联系人               不存在返回-1
//参数1  通讯录   参数2  对比姓名
int isExist(Addressbooks * abs,string name)
{
    for(int i=0;i<abs->m_Size;i++)
    {
        if(abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;//遍历结束未找到返回
}

void deletePerson(Addressbooks *abs)
{
    cout<<"请输入你要删除的联系人:"<<endl;

    string name;
    cin>>name;

    int ret = isExist(abs,name);
    
    if(ret !=-1)
     {
         for(int i=ret;i<abs->m_Size;i++)
         {
             //数据迁移
             abs->personArray[i]=abs->personArray[i+1];
         }
         abs->m_Size--;//更新人数
         cout<<"删除成功"<<endl;
     }
     else
     {
         cout<<"查无此人"<<endl;
     }

     system("pause");
     system("cls");
}

//4.查找指定联系人
void findPerson(Addressbooks *abs)
{
    cout<<"请输入要查找的联系人"<<endl;
    string name;
    cin>>name;

    //判断指定联系人是否存在通信录中
    int ret=isExist(abs,name);

    if (ret!=-1)
    {
        cout<<"姓名:  "<<abs->personArray[ret].m_Name<<"\t";
        cout<<"性别:  "<<( abs->personArray[ret].m_Sex == 1 ?"男":"女" )<<"\t";
        cout<<"年龄:  "<<abs->personArray[ret].m_Age<<"\t";
        cout<<"电话:  "<<abs->personArray[ret].m_Phone<<"\t";
        cout<<"住址:  "<<abs->personArray[ret].m_Addr<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }

     system("pause");
     system("cls");    
}

//5.修改联系人
void modifyPerson(Addressbooks *abs)
{
    cout<<"请输入需要修改的联系人:"<<endl;
    string name;
    cin>>name;

    int ret= isExist(abs,name);

    if(ret!=-1)
    {
        //name
        string name;
        cout<<"请输入姓名:"<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;

        //sex
        cout<<"请输入性别:"<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        int sex=0;
        
        while(true)
        {
            cin>>sex;
            if(sex==1||sex==2)
        {
            abs->personArray[ret].m_Sex=sex;
            break;
        }
        cout<<"输入有误，请重新输入"<<endl;
        }

        //age
        cout<<"请输入年龄:"<<endl;
        int age=0;
        cin>>age;
        abs->personArray[ret].m_Age=age;

        //phone
        cout<<"请输入联系电话:"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[ret].m_Phone=phone;   

        //address
        cout<<"请输入家庭住址:"<<endl;
        string address;
        cin>>address;
        abs->personArray[ret].m_Addr=address;           

        cout<<"修改成功!"<<endl;     
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
     system("pause");
     system("cls");  
}

//6.清空联系人
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size=0;//逻辑清空
    cout<<"通信录已清空"<<endl;
    system("pause");
    system("cls");      
}


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
    //创建通讯录结构体变量
    Addressbooks abs;
    
    //初始化通讯录人员个数
    abs.m_Size = 0;

    int select = 0;//choose

    while(true)
    {
        showMenu();

    cin >> select;
    
    switch(select)
    {
        case 1:     //1、添加联系人
            addPerson(&abs);//利用地址传递可修饰实参
            break;
        case 2:     //2、显示联系人 
            showPerson(&abs);
            break;
        case 3:     //3、删除联系人
            deletePerson(&abs);
                                                    //   {

                                                    //     cout<<"请输入删除联系人姓名:  "<<endl;
                                                    //     string name;
                                                    //     cin>>name;
                                                    //     if( isExist(&abs,name)==-1)
                                                    //     {
                                                    //         cout<<"查无此人"<<endl;
                                                    //     }
                                                    //     else
                                                    //     {
                                                    //         cout<<"找到此人"<<endl;
                                                    //     }
                                                    //   }
            break;
        case 4:     //4、查找联系人
             findPerson(&abs);
            break;
        case 5:     //5、修改联系人
            modifyPerson(&abs);
            break;
        case 6:     //6、清空联系人
            cleanPerson(&abs);
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
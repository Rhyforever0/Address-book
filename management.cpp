#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//�����ϵ�˽ṹ��
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

//���ͨѶ¼�ṹ��
struct Addressbooks
{
    //����ĵ���ϵ������
    struct Person personArray[MAX];
    
    //ͨѶ¼�е�ǰ��¼��ϵ�˸���
    int m_Size;
};

//1.�����ϵ��
void addPerson(Addressbooks * abs)
{
    //�ж�ͨѶ¼�Ƿ���
    if(abs->m_Size==MAX)
    {
        cout<<"ͨѶ¼����!"<<endl;
        return;
    }
    else
    {
        //add person
        //name
        string name;
        cout<<"����������:  "<<endl;
        cin >>name;
        abs->personArray[abs->m_Size].m_Name=name;//ָ�����

        //sex
        cout<<"�������Ա�:  "<<endl;
        cout<<"1---��  "    <<endl;
        cout<<"2---Ů  "    <<endl;
        
        int sex = 0;
        
        while(true)
        {
            //�������1��2���˳�ѭ��
            //��������������
            cin >> sex;
            if(sex == 1 || sex == 2)
        {
            abs->personArray[abs->m_Size].m_Sex=sex;
            break;
        }
            cout<<"�Ա���������������"<<endl;
        }


        //age
        cout<<"����������:  "<<endl;
        int age=0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age=age;


        //tele
        cout<<"������绰:  "<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone=phone;

        //address
        cout<<"�������ͥסַ:"<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr=address;

        //����ͨѶ¼����
        abs->m_Size++;

        cout<<"��ӳɹ�"<<endl;

        system("pause");
        system("cls");//��������


    }
}

//2.��ʾ��ϵ��
void showPerson(Addressbooks *abs)
{
    if(abs->m_Size == 0)
    {
        cout<<"��ǰ��¼Ϊ��"<<endl;
    }

    else
    {
        for(int i = 0; i<abs->m_Size ;i++)
        {
            cout<<"����:  "<<abs->personArray[i].m_Name<<"\t";
            cout<<"�Ա�:  "<<( abs->personArray[i].m_Sex == 1 ?"��":"Ů" )<<"\t";
            cout<<"����:  "<<abs->personArray[i].m_Age<<"\t";
            cout<<"�绰:  "<<abs->personArray[i].m_Phone<<"\t";
            cout<<"סַ:  "<<abs->personArray[i].m_Addr<<endl;
        }
    }
    
    system("pause");
    system("cls");


}

//3.ɾ����ϵ��               �����ڷ���-1
//����1  ͨѶ¼   ����2  �Ա�����
int isExist(Addressbooks * abs,string name)
{
    for(int i=0;i<abs->m_Size;i++)
    {
        if(abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;//��������δ�ҵ�����
}

void deletePerson(Addressbooks *abs)
{
    cout<<"��������Ҫɾ������ϵ��:"<<endl;

    string name;
    cin>>name;

    int ret = isExist(abs,name);
    
    if(ret !=-1)
     {
         for(int i=ret;i<abs->m_Size;i++)
         {
             //����Ǩ��
             abs->personArray[i]=abs->personArray[i+1];
         }
         abs->m_Size--;//��������
         cout<<"ɾ���ɹ�"<<endl;
     }
     else
     {
         cout<<"���޴���"<<endl;
     }

     system("pause");
     system("cls");
}

//4.����ָ����ϵ��
void findPerson(Addressbooks *abs)
{
    cout<<"������Ҫ���ҵ���ϵ��"<<endl;
    string name;
    cin>>name;

    //�ж�ָ����ϵ���Ƿ����ͨ��¼��
    int ret=isExist(abs,name);

    if (ret!=-1)
    {
        cout<<"����:  "<<abs->personArray[ret].m_Name<<"\t";
        cout<<"�Ա�:  "<<( abs->personArray[ret].m_Sex == 1 ?"��":"Ů" )<<"\t";
        cout<<"����:  "<<abs->personArray[ret].m_Age<<"\t";
        cout<<"�绰:  "<<abs->personArray[ret].m_Phone<<"\t";
        cout<<"סַ:  "<<abs->personArray[ret].m_Addr<<endl;
    }
    else
    {
        cout<<"���޴���"<<endl;
    }

     system("pause");
     system("cls");    
}

//5.�޸���ϵ��
void modifyPerson(Addressbooks *abs)
{
    cout<<"��������Ҫ�޸ĵ���ϵ��:"<<endl;
    string name;
    cin>>name;

    int ret= isExist(abs,name);

    if(ret!=-1)
    {
        //name
        string name;
        cout<<"����������:"<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;

        //sex
        cout<<"�������Ա�:"<<endl;
        cout<<"1---��"<<endl;
        cout<<"2---Ů"<<endl;
        int sex=0;
        
        while(true)
        {
            cin>>sex;
            if(sex==1||sex==2)
        {
            abs->personArray[ret].m_Sex=sex;
            break;
        }
        cout<<"������������������"<<endl;
        }

        //age
        cout<<"����������:"<<endl;
        int age=0;
        cin>>age;
        abs->personArray[ret].m_Age=age;

        //phone
        cout<<"��������ϵ�绰:"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[ret].m_Phone=phone;   

        //address
        cout<<"�������ͥסַ:"<<endl;
        string address;
        cin>>address;
        abs->personArray[ret].m_Addr=address;           

        cout<<"�޸ĳɹ�!"<<endl;     
    }
    else
    {
        cout<<"���޴���"<<endl;
    }
     system("pause");
     system("cls");  
}

//6.�����ϵ��
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size=0;//�߼����
    cout<<"ͨ��¼�����"<<endl;
    system("pause");
    system("cls");      
}


//void showMenu
//function:show Menu GUI

void showMenu()
{
    cout<<"****************************"<<endl;
    cout<<"*****  1�������ϵ��   *****"<<endl;
    cout<<"*****  2����ʾ��ϵ��   *****"<<endl;
    cout<<"*****  3��ɾ����ϵ��   *****"<<endl;
    cout<<"*****  4��������ϵ��   *****"<<endl;
    cout<<"*****  5���޸���ϵ��   *****"<<endl;
    cout<<"*****  6�������ϵ��   *****"<<endl;
    cout<<"*****  0���˳�ͨѶ¼   *****"<<endl;
    cout<<"****************************"<<endl;
}


int main()
{
    //����ͨѶ¼�ṹ�����
    Addressbooks abs;
    
    //��ʼ��ͨѶ¼��Ա����
    abs.m_Size = 0;

    int select = 0;//choose

    while(true)
    {
        showMenu();

    cin >> select;
    
    switch(select)
    {
        case 1:     //1�������ϵ��
            addPerson(&abs);//���õ�ַ���ݿ�����ʵ��
            break;
        case 2:     //2����ʾ��ϵ�� 
            showPerson(&abs);
            break;
        case 3:     //3��ɾ����ϵ��
            deletePerson(&abs);
                                                    //   {

                                                    //     cout<<"������ɾ����ϵ������:  "<<endl;
                                                    //     string name;
                                                    //     cin>>name;
                                                    //     if( isExist(&abs,name)==-1)
                                                    //     {
                                                    //         cout<<"���޴���"<<endl;
                                                    //     }
                                                    //     else
                                                    //     {
                                                    //         cout<<"�ҵ�����"<<endl;
                                                    //     }
                                                    //   }
            break;
        case 4:     //4��������ϵ��
             findPerson(&abs);
            break;
        case 5:     //5���޸���ϵ��
            modifyPerson(&abs);
            break;
        case 6:     //6�������ϵ��
            cleanPerson(&abs);
            break;
        case 0:     //0���˳�ͨѶ¼
            cout <<"��ӭ�´�ʹ��"<<endl;
            system("pause");
            return 0;
            break;
        default:
            break;
    }
    }



    system("pause");
}
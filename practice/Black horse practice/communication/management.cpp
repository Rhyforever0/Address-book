#include<iostream>
using namespace std;
#include<string>
//void showMenu
//function:show Menu GUI

void showMenu()
{
    cout<<"****************************"<<endl;
    cout<<"*****  1��������ϵ��   *****"<<endl;
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
    int select = 0;//choose

    while(true)
    {
        showMenu();

    cin >> select;
    
    switch(select)
    {
        case 1:     //1��������ϵ��
            break;
        case 2:     //2����ʾ��ϵ�� 
            break;
        case 3:     //3��ɾ����ϵ��
            break;
        case 4:     //4��������ϵ��
            break;
        case 5:     //5���޸���ϵ��
            break;
        case 6:     //6�������ϵ��
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
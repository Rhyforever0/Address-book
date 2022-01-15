#include<iostream>
using namespace std;

int main()
{
    int arr[9]={4,5,6,8,9,7,1,3,2};
    cout<<"before using algorithm"<<endl;
    for(int i =0 ;i < 9;i++ )
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


// Start Bubble
 for( int i=0;i<9-1;i++)
{
    //inside cycle compare
    for(int j=0;j<9-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
//after Bubble
 cout<<"after using algorithm"<<endl;
    for( int i=0 ;i<9;i++ )
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

system("pause");

return 0;

}
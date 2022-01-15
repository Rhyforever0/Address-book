#include <iostream>
#include <climits>

int main()
{
    using namespace std;
    int n_int=INT_MAX;
    short n_short=SHRT_MAX;
    long n_long=LONG_MAX;
    long long n_llong=LLONG_MAX;

    cout<<"int is "<<sizeof (int)<<"bytes."<<endl;
    cout<<"short is "<<sizeof n_short<<"bytes."<<endl;
    cout<<"long is "<<sizeof n_long<<"bytes."<<endl;
    cout<<"long long is "<<sizeof n_llong<<"bytes."<<endl;
    cout<<"unsigned int is "<<sizeof (uint16_t)<<"bytes."<<endl;
    
    
    cout<<"MAXMIUM VALUE:"<<endl;
    cout<<"int is: "<<n_int<<endl;
    cout<<"short is: "<<SHRT_MAX<<endl;
    cout<<"long is: "<<LONG_MAX<<endl;
    cout<<"long long is: "<<LLONG_MAX<<endl;
    cout<<"unsigned int is: "<<UINT_MAX<<endl;
    
    
    
    system("pause");

    return 0;    




}
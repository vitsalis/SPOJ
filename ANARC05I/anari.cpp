#include<iostream>
#include<cstring>
using namespace std;
#define lld signed long long int
bool d[3000][3000]={0};
int main()
{
    char ss[1000+5];
    while(1)
    {
        cin>>ss;
        if(ss[0]=='Q')return 0;
        int len=strlen(ss),x=1500,y=1500,ans=0;
        d[x][y]=1;
        for(int i=0;i<=len-2;++i)
        {
            switch(ss[i])
            {
                case 'U':++x;break;
                case 'D':--x;break;
                case 'L':--y;break;
                case 'R':++y;break;
            }
            if(d[x][y])++ans;
            else d[x][y]=1;
        }
        x=1500,y=1500;
        for(int i=0;i<=len-2;++i)
        {
            switch(ss[i])
            {
                case 'U':++x;break;
                case 'D':--x;break;
                case 'L':--y;break;
                case 'R':++y;break;
            }
            d[x][y]=0;
        }
        cout<<ans<<endl;
    }
}


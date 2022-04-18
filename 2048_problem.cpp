#include<bits/stdc++.h>
using namespace std;
void t2048(int unit)
{
    if(unit>0)
    {
        t2048(unit/10);
        if(unit%10==0) cout<<" zero ";
        if(unit%10==1) cout<<" one ";
        if(unit%10==2) cout<<" two ";
        if(unit%10==3) cout<<" three ";
        if(unit%10==4) cout<<" four ";
        if(unit%10==5) cout<<" five ";
        if(unit%10==6) cout<<" six ";
        if(unit%10==7) cout<<" seven ";
        if(unit%10==8) cout<<" eight ";
        if(unit%10==9) cout<<" nine ";
    }
}
int main()
{
    t2048(12232048);
}
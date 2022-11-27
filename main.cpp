#include<bits/stdc++.h>
using namespace std;
char ch[10]={'1','2','3','4','5','6','7','8','9'};
void drow()
{
    cout<<"\t"<<ch[0]<<"\t|\t"<<ch[1]<<"\t|\t"<<ch[2]<<'\n';
    cout<<"\t"<<"-------------------------------------"<<'\n';
    cout<<"\t"<<ch[3]<<"\t|\t"<<ch[4]<<"\t|\t"<<ch[5]<<'\n';
    cout<<"\t"<<"-------------------------------------"<<'\n';
    cout<<"\t"<<ch[6]<<"\t|\t"<<ch[7]<<"\t|\t"<<ch[8]<<'\n';
}
void drowag()
{
    ch[0]='1';
    ch[1]='2';
    ch[2]='3';
    ch[3]='4';
    ch[4]='5';
    ch[5]='6';
    ch[6]='7';
    ch[7]='8';
    ch[8]='9';

}
void re(int n, char c)
{
    switch(n)
    {
        case 1:
            ch[0] = c;
            break;
        case 2:
            ch[1] = c;
            break;
        case 3:
            ch[2] = c;
            break;
        case 4:
            ch[3] = c;
            break;
        case 5:
            ch[4] = c;
            break;
        case 6:
            ch[5] = c;
            break;
        case 7:
            ch[6] = c;
            break;
        case 8:
            ch[7] = c;
            break;
        case 9:
            ch[8] = c;
            break;
    }

}
bool chack(int n)
{
    if(n>=1&&n<=9)
        return true;

    return false;
}
bool chack2(int n)
{
    switch(n)
    {
        case 1:
            if(ch[0] == '1')
                return true;
            break;
        case 2:
            if(ch[1] == '2')
                return true;
            break;
        case 3:
            if(ch[2] == '3')
                return true;
            break;
        case 4:
            if(ch[3] == '4')
                return true;
            break;
        case 5:
            if(ch[4] == '5')
                return true;
            break;
        case 6:
            if(ch[5] == '6')
                return true;
            break;
        case 7:
            if(ch[6] == '7')
                return true;
            break;
        case 8:
            if(ch[7] == '8')
                return true;
            break;
        case 9:
            if(ch[8] == '9')
                return true;
            break;

    }
    return false;
}
bool winx()
{
    if(ch[0]=='X'&&ch[1]=='X'&&ch[2]=='X')
    {
        return true;
    }
    else if(ch[3]=='X'&&ch[4]=='X'&&ch[5]=='X')
    {
        return true;
    }
    else if(ch[6]=='X'&&ch[7]=='X'&&ch[8]=='X')
    {
        return true;
    }
    else if(ch[0]=='X'&&ch[3]=='X'&&ch[6]=='X')
    {
        return true;
    }
    else if(ch[1]=='X'&&ch[4]=='X'&&ch[7]=='X')
    {
        return true;
    }
    else if(ch[2]=='X'&&ch[5]=='X'&&ch[8]=='X')
    {
        return true;
    }
    else if(ch[0]=='X'&&ch[4]=='X'&&ch[8]=='X')
    {
        return true;
    }
    else if(ch[2]=='X'&&ch[4]=='X'&&ch[6]=='X')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool winO()
{
    if(ch[0]=='O'&&ch[1]=='O'&&ch[2]=='O')
    {
        return true;
    }
    else if(ch[3]=='O'&&ch[4]=='O'&&ch[5]=='O')
    {
        return true;
    }
    else if(ch[6]=='O'&&ch[7]=='O'&&ch[8]=='O')
    {
        return true;
    }
    else if(ch[0]=='O'&&ch[3]=='O'&&ch[6]=='O')
    {
        return true;
    }
    else if(ch[1]=='O'&&ch[4]=='O'&&ch[7]=='O')
    {
        return true;
    }
    else if(ch[2]=='O'&&ch[5]=='O'&&ch[8]=='O')
    {
        return true;
    }
    else if(ch[0]=='O'&&ch[4]=='O'&&ch[8]=='O')
    {
        return true;
    }
    else if(ch[2]=='O'&&ch[4]=='O'&&ch[6]=='O')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n,c=0,t=0;
    while (true)
    {
        int e=0;
        drow();
        cout<<"enter number : \n";
        c++;
        if(c%2==0)
        {
            cout<<"role x\n";
            cin>>n;
            while (!chack(n))
            {
                cout<<"error enter number 1 to 9\n";
                cin>>n;
            }
            while (!chack2(n))
            {
                cout<<"error enter anther place\n";
                cin>>n;
            }
            re(n,'X');
        }
        else
        {
            cout<<"role O\n";
            cin>>n;
            while (!chack(n))
            {
                cout<<"error enter number 1 to 9\n";
                cin>>n;
            }
            while (!chack2(n))
            {
                cout<<"error enter anther place\n";
                cin>>n;
            }
            re(n,'O');
        }

        t++;
        if(winx())
        {
            drow();
            cout<<"\t__________ x is win __________\n";
            cout<<" if you want play agin enter any number or -1 to exit\n";
            cin>>e;
            if(e==-1)
            {
                return 0;
            }
            else
            {
                t=0;
                c=0;
                drowag();
            }

        }
        if(winO())
        {
            drow();
            cout<<"\t__________ O is win __________\n";
            cout<<" if you want play agin enter any number or -1 to exit\n";
            cin>>e;
            if(e==-1)
            {
                return 0;
            }
            else
            {
                t=0;
                c=0;
                drowag();
            }
        }

        if(t==9)
        {
            drow();
            cout<<"___no one win ___ if you want play agin enter any number or -1 to exit\n";
            cin>>e;
            if(e==-1)
            {
                return 0;
            }
            else
            {
                t=0;
                c=0;
                drowag();

            }
        }
    }
    return 0;
}


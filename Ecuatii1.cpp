#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
 
ifstream fin("ecuatii2.in");
ofstream fout("ecuatii2.out");
 
int d,e;
 
char calcule(char a[],int &d,int &e)
{
    int i,S=0,nr=0,j;
    int nrnat=0, nrx=0;
    int n=strlen (a);
 
 
    if (a[0]!='x' && a[0]!='-')
    {
        for (j=0; a[j]>='0' && a[j]<='9' ; j++)
            nr=nr*10+(a[j]-'0');
        if (a[j]=='x') nrx+=nr;
        else nrnat+=nr;
    }
    else if (a[0]=='x') nrx++;
    else if (a[0]=='-')
    {
        int ok=0;
        for (j=1; a[j]>='0' && a[j]<='9'; j++)
        {
            nr=nr*10+(a[j]-'0');
            ok=1;
        }
        if (a[j]=='x')
        {
            if (ok) nrx-=nr;
            else nrx--;
        }
        else nrnat-=nr;
    }
    nr=0;
    for (i=0; i<n; i++)
    {
        if (a[i]=='+')
        {
            int ok=0;
            j=i+1;
            for (; a[j]>='0' && a[j]<='9' ; j++)
            {
                nr=nr*10+(a[j]-'0');
                ok=1;
            }
            if (a[j]=='x')
            {
                if (ok==1) nrx+=nr;
                else nrx++;
                nr=0;
            }
            else
            {
                nrnat+=nr;
                nr=0;
            }
        }
        else if (a[i]=='-')
        {
            int ok=0;
            j=i+1;
            for (; a[j]>='0' && a[j]<='9' ; j++)
            {
                nr=nr*10+(a[j]-'0');
                ok=1;
            }
            if (a[j]=='x')
            {
                if (ok==1) nrx-=nr;
                else nrx-=1;
                nr=0;
            }
            else
            {
                nrnat-=nr;
                nr=0;
            }
        }
    }
    d=nrnat;
    e=nrx;
}
int main()
{
    int N,numar1,numar2;
    float X;
    char s[256];
 
    fin>>N;
    fin.get();
 
    while (N--)
    {
        fin.getline (s,256);
        char *p;
        p=strtok (s, "=");
        calcule (p,numar1, numar2);
        p=strtok (NULL, "\0");
        calcule (p,d,e);
        if (numar2-e==0 && d-numar1==0)
        {
            fout<<"infinit";
            fout<<"\n";
        }
        else if (d-numar1!=0 && numar2-e==0)
        {
            fout<<"imposibil";
            fout<<"\n";
        }
        else
        {
         if ((d-numar1)%(numar2-e)!=0) {  X=((d-numar1)* 1./(numar2-e)); fout<<fixed<<setprecision(4)<<X;}
         else fout<<(d-numar1)/(numar2-e);
            fout<<"\n";
        }
    }
    return 0;
}
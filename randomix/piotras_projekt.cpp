#include <iostream>

using namespace std;

int pkwadrat(int a)
{
    return a*a;
}
int okwadrat(int a)
{
    return 4*a;
}
int pprostokat(int a,int b)
{
    return a*b;

}
int oprostokat(int a, int b)
{
    return 2*a+2*b;
}
int ptrojkata(int a, int h)
{
    return a*h/2;
}

int pkola(int r)
{
    return 3.1415*r*r;
}
int okola(int r)
{
    return 2*3.1415*r;
}
int ptrapezu(int a, int b, int h)
{
    return (a+b)*h/2;
}

int main()
{
   cout<<"Co chcesz otrzymac?\n1-pole figury\n2-obwod figury'n'3-Pole powierzchni bryly\n4-objetosc bryly";
   int p;
   cin>>p;
   if(p==1)
   {
       cout<<"Jakiej figury pole chcesz uzyskać?\n1-kwadratu\n2-prostokata\n3-trojkata\n4-koła\n5-trapezu"<<endl;
       int pom;
       cin>>pom;
       cout<<"Podaj dlugosci bokow i wysokosci"<<endl;
       if(pom==1)
       {
           int a;
           cin>>a;
           int wynik=pkwadrat(a);
           cout<<"Pole kwadratu wynosi "<<wynik<<endl;
       }
       else if(pom==2)
       {
           int a, b;
           cin>>a>>b;
           int wynik1=pprostokat(a,b);
           cout<<"Pole prostokata wynosi "<<wynik1<<endl;
       }
       else if(pom==3)
       {
           int a, h;
           cin>>a>>h;
           int wynik2=ptrojkata(a,h);
           cout<<"Pole trojkata wynosi "<<wynik2<<endl;
       }
       else if(pom==4)
       {
           int r;
           cin>>r;
           int wynik3=pkola(r);
           cout<<"Pole kola wynosi "<<wynik3<<endl;
       }
       else if(pom==5)
       {
           int a,b,h;
           cin>>a>>b>>h;
           int wynik4=ptrapezu(a,b,h);
           cout<<"Pole trapezu wynosi "<<wynik4<<endl;
       }
   }
   else if(p==2)
   {
          cout<<"Jakiej figury obwod chcesz uzyskać?\n1-kwadratu\n2-prostokata\n3-koła"<<endl;
          int pom;
          cin>>pom;
          cout<<"Podaj dlugosci bokow"<<endl;
         if(pom==1)
       {
           int a;
           cin>>a;
           int wynik5=okwadrat(a);
           cout<<"obwod kwadratu wynosi "<<wynik5<<endl;
       }
       else if(pom==2)
       {
           int a,b;
           cin>>a >> b;
           int wynik6=oprostokat(a,b);
           cout<<"obwod prostokata wynosi "<<wynik6<<endl;
       }
       else if(pom==3)
       {
           int r;
           cin>>r;
           int wynik7=okola(r);
           cout<<"Obwod kola wynosi "<<wynik7<<endl;
       }

   }
   else if(p==3)
   {
       cout<<"Jakiej bryły pole powierzchni chcesz uzyskać?\n1-sześcianu\n2-prostopadłościanu\n3-stożka\n4-walca\n5-kuli"<<endl;
       int pom;
       cin>>pom;
       if(pom==1)
       {
           int a;
           cin>>a;
           int w=pkwadrat(a);
           int w1=6*w;
           cout<<"Pole powierzchni szescianu wynosi "<<w1<<endl;
       }
       else if(pom==2)
       {
           int a,b;
           cin>>a>>b;
           int w2=2*pkwadrat(a)+4*pprostokat(a,b);
           cout<<"Pole powierzchni prostopadloscianu wynosi "<<w2<<endl;
       }
       else if (pom==3)
       {
           int r,l;
           cin>>r>>l;
           int w3=pkola(r)+3.1415*r*l;
           cout<<"Pole powierzchni stożka wynosi "<<w3<<endl;
       }
       else if(pom==4)
       {
           int r,H;
           cin>>r>>H;
           int w4= 2*pkola(r)+okola(r)*H;
           cout<<"Pole powierzchni walca wynosi "<<w4<<endl;
       }
       else if(pom==5)
       {
           int r;
           cin>>r;
           int w5=4*pkola(r);
           cout<<"Pole powierzchni kuli wynosi "<<w5<<endl;
       }
   }
   else if(p==4)
   {
        cout<<"Jakiej bryły objetosc chcesz uzyskac?\n1-sześcianu\n2-prostopadłościanu\n3-stozka\n4-walca\n5-kuli"<<endl;
        int pom;
        cin>>pom;
        if (pom==1)
        {
            int a;
            cin>>a;
            int w6=pkwadrat(a)*a;
            cout<<"Objetosc szescianu wynosi "<<w6<<endl;;
        }
        else if(pom==2)
        {
            int a,b;
            cin>>a;
            int w7=pkwadrat(a)*b;
            cout<<"Objetosc prostopadloscianu wynosi "<<w7<<endl;
        }
        else if(pom==3)
        {
            int r,H;
            cin>>r>>H;
            int w8=pkola(r)/3*H;
            cout<<"Objetosc stozka wynosi "<<w8<<endl;
        }
        else if(pom==4)
        {
            int r,H;
            cin>>r>>H;
            int w9=pkola(r)*H;
            cout<<"Objetosc walca wynosi "<<w9<<endl;
        }
        else if(pom==5)
        {
            int r;
            cin>>r;
            int w10=pkola(r)*r*4/3;
            cout<<"Objetosc kuli wynosi "<<w10<<endl;
        }
   }
    return 0;
}

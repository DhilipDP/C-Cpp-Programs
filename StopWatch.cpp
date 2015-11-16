#include<iostream>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
using namespace std ;
void title();

class tym
  {
    private:
      int hh,mm,ss,ms;

    public:
      void show()
       {
         if(ms>9)
          {
            ms=0;
            ss++;
          }
         else if(ss>59)
          {
            ss=0;
            mm++;
          }
         else if(mm>59)
          {
            mm=0;
            hh++;
          }
         cout<<hh<<":"<<mm<<":"<<ss<<":"<<ms;
       }

      void inc()
       {
         ms++;
       }

      void cancel()
       {
         hh=mm=ss=ms=0;
       }

      tym()
       {
         hh=mm=ss=ms=0;
       }
  };

void title()
 {
   cout<<"\n press s for start ";
   cout<<"\n press p for pause ";
   cout<<"\n press t for stop ";
   cout<<"\n press r for resume ";
   cout<<"\n press c for cancel ";
 }

int main()
 {
   tym t;
   char opt;
   title();
   cout<<"\n\n stopwatch :- ";

    opt = getch();
        if((opt=='s')||(opt=='S'))
      e:  {
             while(!kbhit())
               {
                // clrscr();
                 title();
                 cout<<"\n\n stopwatch :- ";
                 t.show();
                 sleep_for(100);
                 t.inc();
               }
             opt=getch();
             if((opt=='p')||(opt=='P'))
              {
                 while(!kbhit())
                  {
                    clrscr();
                    title();
                    cout<<"\n\n stopwatch :- ";
                    t.show();
                    delay(100);
                  }
                 opt=getch();
                 if((opt=='s')||(opt=='S'))
                   goto e;

                 else if((opt=='t')||(opt=='T'))
                   {
                     clrscr();
                     title();
                     cout<<"\n\n stopwatch :- ";
                     t.show();
                     delay(5000);
                     exit(1);
                   }


                 else if((opt=='c')||(opt=='C'))
                   {
                        while(!kbhit())
                         {
                           clrscr();
                           title();
                           cout<<"\n\n stopwatch :- ";
                           t.cancel();
                           t.show();
                           delay(100);
                         }

                         opt=getch();
                        if((opt=='s')||(opt=='S')||(opt=='r')||(opt=='R'))
                        goto e;

                        else
                         exit(1);
                   }


                else if((opt=='r')||(opt=='R'))
                   goto e;

                else
                  exit(1);
               }
             else if((opt=='t')||(opt=='T'))
               {
                 clrscr();
                 title();
                 cout<<"\n\n stopwatch :- ";
                 t.show();
                 delay(5000);
                 exit(1);
                }


             else if((opt=='c')||(opt=='C'))
              {
                while(!kbhit())
                {
                  clrscr();
                  title();
                  cout<<"\n\n stopwatch :- ";
                  t.cancel();
                  t.show();
                  delay(100);

                }
                opt=getch();
                 if((opt=='s')||(opt=='S')||(opt=='r')||(opt=='R'))
                   goto e;

                 else
                   exit(1);
              }
           else
             exit(1);

           }
         else
           exit(1);


     getch();

 }

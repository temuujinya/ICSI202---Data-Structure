#include<graphics.h>
       #include<stdio.h>
       #include<conio.h>
       #include<dos.h>
       union REGS in,out;

       int callmouse()
       {
              in.x.ax=1;
              int86(51,&in,&out);
              return 1;
       }
       void mouseposi(int &xpos,int &ypos,int &click)
       { 
              in.x.ax=3;
              int86(51,&in,&out);
              click=out.x.bx;
              xpos=out.x.cx;
              ypos=out.x.dx;
        }
       int mousehide()
       {
              in.x.ax=2;
              int86(51,&in,&out);
              return 1;
       }
      void setposi(int &xpos,int &ypos)
      { 
             in.x.ax=4;
             in.x.cx=xpos;
             in.x.dx=ypos;
             int86(51,&in,&out);
      }
     int main()
      {
             int x,y,cl,a,b;
             clrscr();
             int g=DETECT,m;
             initgraph(&g,&m,"c:\tc\bgi");
             a=100;
             b=400;
             setposi(a,b);
             callmouse();
             do
             {
                    mouseposi(x,y,cl);
                    gotoxy(10,9);
                    printf("\n\tMouse Position is: %d,%d",x,y);
                    printf("\n\tClick: %d",cl);
                    printf("\n\tPress any key to hide the mouse");
             }while(!kbhit());
             getch();
             mousehide();
             printf("\n\n\tPress any key to Exit");
             getch();
     }

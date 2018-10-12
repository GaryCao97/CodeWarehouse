#include "gobanginterface.h"
#include "gobangconsoleui.h"
#include "gobanglocalplayer.h"
#include "gobangcomplayer.h"
#include "gobangmaingame.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

main()
{
        printf("GoBang Rule\n1.Use arrow keys to move the piece;\n");
        printf("2.Press Space to put the piece\n");
        printf("3.No Pressing Space out of the board\n");
        printf("4.The Black plays first\n");
        printf("5.The game will begin if you agree with the rule\n");
        char a=0;
        while(a!='Y' && a!='y' && a!='n' && a!='N'){
                a=0;
                printf("Do you agree the rule?(Y/N)");
                while(a==0) a=_getch();
                putchar(a);
                printf("\n");
        }
        if(a=='Y' || a=='y')
        {
                IUserInterface *ui= new ConsoleUI();
                int b=0;
                IPlayer *black;
                IPlayer *white;
                while(b<1||b>3){
                printf("Who use the black piece?\n1.User\n2.Com(Baka)\n3.Com(Normal)\n");
                cin>>b;
                }
                switch(b)
                {
                        case 1:
                        black= new LocalPlayer(ui);
                        break;
                        case 2:
                        black= new BakaPlayer(ui,1);
                        break;
                        case 3:
                        black= new NormalPlayer(ui,1);
                }
                b=0;
                while(b<1||b>3){
                printf("Who use the white piece?\n1.User\n2.Com(Baka)\n3.Com(Normal)\n");
                cin>>b;
                }
                switch(b)
                {
                        case 1:
                        white= new LocalPlayer(ui);
                        break;
                        case 2:
                        white= new BakaPlayer(ui,2);
                        break;
                        case 3:
                        white= new NormalPlayer(ui,2);
                }
                Maingame g(black,white,ui);
                _getch();
                system("cls");
                g.run();
                _getch();
        }
}

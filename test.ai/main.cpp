 #include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int xa, int ya)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { xa, ya };
    SetConsoleCursorPosition(h,c);
}
class map_a
{
public:
    int deb_m=0;
private:
    int temp_x=0,temp_y=0; /// neleisti
    int map_x=16; /// keisti bet ir map
    int map_y=16; /// keisti bet ir map
    int gold=0;
    bool find_gold=false;
    int snow=0;
    const int lava_s=5;
    int lava=0;
    int iSecret;
    int map_mass_1[16][16]; /// keisti bet ir map
    int t_x=60,t_y=0;
    const char deb_as=186;
    POINT pt;
    int id_x=pt.x;
    int id_y=pt.y;
    bool gen_ok=false;
    int error_time=0;
    int rare_q=(int)((map_x*map_y/100)*2.55);
    int snow_plot=(int)(rare_q-((map_x*map_y/100)));
    int akm=0;
    bool player_w;

public:
    void render_m()
    {
        srand ( time(NULL) );
        for(int ia=0; ia<map_x; ia++)
        {
            for(int iq=0; iq<map_y; iq++)
            {
                iSecret = rand() % 11 + 1;
                temp_x=ia;
                if(iq==0)
                {
                    temp_y=iq;
                }
                else
                {
                    temp_y=iq;
                }
                //cout<<iSecret<<" ";
                map_mass_1[ia][iq]=iSecret;


            }
            //cout<<endl;
        }

        for(int ia=0; ia<map_x; ia++)
        {
            for(int iq=0; iq<map_y; iq++)
            {
                check(ia,iq);
            }
        }
        if(true)
        {
            gen_ok=true;
            cout<<endl;
        }
    }
    void check(int ix,int iy)
    {

        if(map_mass_1[ix][iy]==5)  ///gray to grass
        {
            map_mass_1[ix][iy]=2;
            error_time+=1;

        }
                if(map_mass_1[ix][iy]==8)  ///greee to grass
        {
            map_mass_1[ix][iy]=2;
            error_time+=1;

        }
        if(map_mass_1[ix][iy]==1) /// wate to grass
        {
            map_mass_1[ix][iy]=2;
            error_time+=1;

        }
                if(map_mass_1[ix][iy]==3) /// brown to grass
        {
            map_mass_1[ix][iy]=2;
            error_time+=1;

        }

        if(map_mass_1[ix][iy]==9) /// lava check
        {
            if(lava!=lava_s)
            {
                lava++;
                if(ix+1<=map_x)
                {
                    map_mass_1[ix+1][iy]=6;

                    akm++;

                    error_time+=1;

                }
                if(ix-1>=0)
                {
                    map_mass_1[ix-1][iy]=6;

                    akm++;

                    error_time+=1;

                }
/// x end
                if(iy+1<=map_y)
                {
                    map_mass_1[ix][iy+1]=6;

                    akm++;

                    error_time+=1;

                }
                if(iy-1>=0)
                {
                    map_mass_1[ix][iy-1]=6;
                    akm++;
                    error_time+=1;

                }
/// y end


            }
            else
            {
                map_mass_1[ix][iy]=2;
                error_time+=1;
            }


        }
        ///next
        if(map_mass_1[ix][iy]==10) ///gold calculetor
        {


            if(rare_q==0)
            {
                map_mass_1[ix][iy]=2;
                error_time+=1;
            }
            else
            {
                if(find_gold==true)
                {
                    map_mass_1[ix][iy]=2;
                    error_time+=1;
                }
                else
                {

                    if(gold<rare_q&&gold!=rare_q+1){
                        gold++;
                    }else{
                    find_gold=true;
                    }

                }
            }

        }
        ///next
        if(map_mass_1[ix][iy]==11) /// winter col
        {

            if(snow_plot==0)
            {
                map_mass_1[ix][iy]=2;
                error_time+=1;
            }
            else
            {
                if(snow!=snow_plot)
                {
                    snow++;
                }
                else
                {
                    map_mass_1[ix][iy]=2;
                    error_time+=1;
                }
            }

        }
    }

    void print_f()
    {
        for(int ia=0; ia<map_x; ia++)
        {
            for(int iq=0; iq<map_y; iq++)
            {
                switch(map_mass_1[ia][iq])
                {

                case 1:
                    SetConsoleTextAttribute(hConsole,17); ///blue
                    break;
                case 2:

                    SetConsoleTextAttribute(hConsole,34); ///green
                    break;
                case 3:
                    SetConsoleTextAttribute(hConsole,68); ///ruda
                    break;
                case 4:
                    SetConsoleTextAttribute(hConsole,102); ///sand
                    break;
                case 5:
                    SetConsoleTextAttribute(hConsole,119); ///winter grahy
                    break;
                case 6:
                    SetConsoleTextAttribute(hConsole,136); ///gray 136
                    break;
                case 7:
                    SetConsoleTextAttribute(hConsole,153); ///ot blue
                    break;
                case 8:
                    SetConsoleTextAttribute(hConsole,170); ///godd green
                    break;
                case 9:
                    SetConsoleTextAttribute(hConsole,204); ///lava
                    break;
                case 10:
                    SetConsoleTextAttribute(hConsole,238); ///gold
                    break;
                case 11:
                    SetConsoleTextAttribute(hConsole,255); ///winter

                    break;
                default:
                    break;
                }
                if(countDigit(map_mass_1[ia][iq])==2)
                {
                    cout<<map_mass_1[ia][iq];
                    GetCursorPos(&pt);
                    id_y=pt.y;
                    id_x=pt.x;
                }
                else
                {
                    cout<<"0"<<map_mass_1[ia][iq];
                    GetCursorPos(&pt);
                    id_y=pt.y;
                    id_x=pt.x;
                }
            }
            cout<<endl;
        }
        GetCursorPos(&pt);
        id_y=pt.y;
        id_x=pt.x;
    }
    int countDigit(long long n)
    {
        if (n == 0)
        {
            return 0;
        }
        return 1 + countDigit(n / 10);
    }
    void debug_c()
    {
        if(deb_m==1)
        {
            if(t_y==0)
            {

                ///id_y
                ///id_x
                gotoxy(map_x+map_x+10,0);
                cout<<"debug mode is "<<deb_m<< " versija 2 " <<endl;
                gotoxy(map_x+map_x+8,t_y);
                cout<<deb_as<<endl;
                while(t_y!=map_y+map_y+1)
                {
                    t_y++;
                    gotoxy(map_x+map_x+8,t_y);
                    cout<<deb_as<<endl;
                }
                if(gen_ok==true)
                {
                    gotoxy(map_x+map_x+10,2);
                    cout<<"generacija sekminga"<<endl;
                }
                gotoxy(map_x+map_x+10,3);

                cout<<"rare q: "<<rare_q<<endl;
                gotoxy(map_x+map_x+10,4);
                cout<<"gold: "<<gold<<endl;
                gotoxy(map_x+map_x+10,5);
                cout<<"snow plot max: "<<snow_plot<<endl;
                gotoxy(map_x+map_x+10,6);
                cout<<"snow: "<<snow<<endl;
                gotoxy(map_x+map_x+10,7);
                cout<<"lava max: "<<lava_s<<endl;
                gotoxy(map_x+map_x+10,8);
                cout<<"lava : "<<lava<<endl;
                gotoxy(map_x+map_x+10,9);
                cout<<"kietimai atlikti: "<<error_time<<endl;
                gotoxy(map_x+map_x+10,10);
                cout<<"pakeitimai akmuo: "<<akm<<endl;
                gotoxy(60,map_y+map_y+1+2);
            }
        }
    }
};

int main()
{

    map_a test, c;


           cin>>test.deb_m;
            test.render_m();
            test.print_f();

            SetConsoleTextAttribute(hConsole,15);
            test.debug_c();



    return 0;
}





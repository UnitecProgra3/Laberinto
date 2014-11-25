#include <iostream>

using namespace std;

void imprimir(char laberinto[5][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<laberinto[i][j]<<",";
        }
        cout<<endl;
    }
}

bool puedoLLegar(char laberinto[5][5],
                    int inicio_x,  int inicio_y,
                    int destino_x, int destino_y,
                    int pasos)
{
    if(inicio_x<0 || inicio_x>=5
        || inicio_y<0 || inicio_y>=5)
        return false;

    if(pasos<0)
        return false;

    if(inicio_x==destino_x && inicio_y==destino_y)
        return true;
    if(laberinto[destino_y][destino_x]=='1')
        return false;
    if(laberinto[inicio_y][inicio_x]=='1')
        return false;

    if(puedoLLegar(laberinto,inicio_x+1,inicio_y,
                            destino_x,destino_y,pasos-1))
        return true;
    if(puedoLLegar(laberinto,inicio_x-1,inicio_y,
                            destino_x,destino_y,pasos-1))
        return true;
    if(puedoLLegar(laberinto,inicio_x,inicio_y+1,
                            destino_x,destino_y,pasos-1))
        return true;
    if(puedoLLegar(laberinto,inicio_x,inicio_y-1,
                            destino_x,destino_y,pasos-1))
        return true;
    return false;

}

int main()
{
    char laberinto[5][5]={{'0','1','0','0','0'},
                          {'0','1','0','1','0'},
                          {'0','0','0','1','0'},
                          {'0','1','1','1','0'},
                          {'0','1','0','1','0'}};
    cout<<puedoLLegar(laberinto,
                    0,0,
                    4,2,
                    10)<<endl;

    cout<<puedoLLegar(laberinto,
                    0,0,
                    2,4,
                    20)<<endl;
    return 0;
}

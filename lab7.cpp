#include <iostream>
#include <fstream>


int const N = 5;

struct brawl
{
    int ver;
    int neib;
    int path = 0;
};

int main()
{
    int mas[N][N];
    

    std::ifstream in("in.txt");
    if (in.is_open())
    {
        while (!in.eof()) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {

                    in >> mas[i][j];
                }
            }


        }


    }
    in.close();

    
    int elPrimo[N][N];
    int v[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            elPrimo[i][j] = 0;
        }
        v[i] = 0;
    }



    brawl dop[2*N];
    int t = 0;
    dop[t].ver = t;
    v[t] = 1;
    int min = 10000;
    for (int i = 0; i < N; i++) {
        if (t != i) {
            if (v[i] == 0) {
                if (mas[dop[t].ver][i] !=0) {
                    if (mas[dop[t].ver][i] < min) {
                        min = mas[dop[t].ver][i];
                        dop[t].neib = i;
                    }
                }
            }
        }
    }

    t++;
    dop[t].ver = dop[t - 1].neib;
    v[dop[t].ver] = 1;



    elPrimo[0][dop[t].ver] = min;
    elPrimo[dop[t].ver][0] = min;



    while (t < N-1) {

        for (int i = 0; i <= t; i++) {
            dop[i].neib = -1;
            dop[i].path = 10000000;
        }



        for (int i = 0; i <= t; i++) {
            for (int j = 0; j < N; j++) {
                if (j != dop[i].ver) {
                    if (mas[dop[i].ver][j] != 0) {
                        if (v[j] == 0) {
                            if (dop[i].path > mas[dop[i].ver][j]) {
                                dop[i].neib = j;
                                dop[i].path = mas[dop[i].ver][j];
                            }

                        }
                    }
                }
            }
        }


        brawl tmp;
        tmp.path = 1000;

        for (int i = 0; i <= t; i++) {
            if (tmp.path > dop[i].path) {
                tmp = dop[i];
            }

        }

        t++;
        dop[t].ver = tmp.neib;
        v[dop[t].ver] = 1;


        elPrimo[tmp.ver][dop[t].ver] = tmp.path;
        elPrimo[dop[t].ver][tmp.ver] = tmp.path;



    }








    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << elPrimo[i][j] << " ";

        }
        std::cout << std::endl;
    }



}

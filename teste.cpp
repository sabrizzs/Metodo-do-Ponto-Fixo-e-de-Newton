#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int x = 0, y = 0;
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *gnuCommands[] = {"set title \"Demo\"", "plot 'output.txt'  using 1:2:(arg($3+$4*{0,1})) '(%lf,%lf) (%lf,%lf)' palette"};

    fp = fopen("data.tmp", "w");
    gnupipe = popen("gnuplot -persistent", "w");

    for (int i = 0; i < 11; i++){
        fprintf(fp, "%d %d\n", x, y);
        x++; y++;
    }
    fclose(fp);

    for(int i = 0; i < 2; i++){
        fprintf(gnupipe, "%s\n", gnuCommands[i]);
    }

    fclose(gnupipe);

    return 0;
}
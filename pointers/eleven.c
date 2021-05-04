#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_esfera(float R, float *area, float *volume);

int main()
{
    system("cls");

    float raio = 5, area, volume;

    printf(">>> POINTEIROS\n\n");

    calc_esfera(raio, &area, &volume);

    printf("A area da superficie e: %f\nO volume e: %f\n", area, volume);

    return 0;
}

void calc_esfera(float R, float *area, float *volume) {
    float pi = 3.14;
    
    *area =  4 * pi * pow(R, 2);
    *volume = (4/3) * pi * pow(R, 3);
}
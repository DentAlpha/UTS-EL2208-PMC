#include <stdio.h>
#include <math.h>

int main()
{
    // Deklarasi variabel
    float t, v_out;
    const float v_in = 5, e = 2.71828182845904523536, RC = 2.64054E-3;

    // Menerima input waktu
    printf("Input waktu (detik) : ");
    scanf("%f", &t);

    // Menampilkan output
    printf("Tegangan output dari rangkaian RC pada waktu t = %f s adalah %f V", t, v_in - (v_in*pow(e, -t/RC)));

    return 0;
}

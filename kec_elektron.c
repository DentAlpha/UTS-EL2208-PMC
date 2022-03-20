#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 100

int main()
{
    // Deklarasi variabel
    const float m_e = 9.10938291E-31 /* kg */, e = 1.602176565E-19 /* C */, c = 299792458 /* m/s */;
    char FILENAME[] = "tegangan.txt";
    FILE* myfile = fopen(FILENAME, "r");
    char line[MAX_LEN];
    char* token;
    float tegangan[MAX_LEN], m[MAX_LEN], v[MAX_LEN];;
    int jml_data = 0, i;

    // Membaca isi file tegangan.txt
    while(fgets(line, MAX_LEN, myfile)){
        token = strtok(line, "\n");
        tegangan[jml_data] = atof(token);
        jml_data++;
    }

    // Menghitung massa elektron saat bergerak dan kecepatan elektron
    for(i = 0; i < jml_data; ++i){
        m[i] = ((e*tegangan[i])/pow(c, 2)) + m_e;
        v[i] = sqrt((1 - pow((m_e/m[i]), 2))) * c;
    }

    // Mencetak output
    for(i = 0; i < jml_data; ++i){
        printf("V = %e, m = %e, v = %e\n", tegangan[i], m[i], v[i]);
    }

    fclose(myfile);
    return 0;
}

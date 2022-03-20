#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    // Deklarasi variabel
    char FILENAME[] = "DataPenduduk31122019.csv";
    FILE* myfile = fopen(FILENAME, "a+");
    int id_data = 0, i = 0, j, end_of_data = 0, temp;       //i = data size
    char line[MAX_LEN];
    int no[MAX_LEN], umur[MAX_LEN];
    float NIK[MAX_LEN];
    char nama[MAX_LEN][MAX_LEN], tempat_lahir[MAX_LEN][MAX_LEN], tanggal_lahir[MAX_LEN][MAX_LEN], jk[MAX_LEN][MAX_LEN];
    char goldar[MAX_LEN][MAX_LEN], status[MAX_LEN][MAX_LEN], pekerjaan[MAX_LEN][MAX_LEN];
    char* token;

    int umur_inp;
    float NIK_inp;
    char nama_inp[MAX_LEN], tempat_lahir_inp[MAX_LEN], tanggal_lahir_inp[MAX_LEN], jk_inp[MAX_LEN];
    char goldar_inp[MAX_LEN], status_inp[MAX_LEN], pekerjaan_inp[MAX_LEN];

    while(fgets(line, MAX_LEN, myfile) && !end_of_data){
        if(id_data == 0){
            id_data += 1;
        }
        else{
            token = strtok(line, ";");
            temp = atoi(token);

            if(i == 0){
                no[i] = temp;

                token = strtok(NULL, ";");
                NIK[i] = atof(token);

                token = strtok(NULL, ";");
                strcpy(nama[i], token);

                token = strtok(NULL, ";");
                strcpy(tempat_lahir[i], token);

                token = strtok(NULL, ";");
                strcpy(tanggal_lahir[i], token);

                token = strtok(NULL, ";");
                umur[i] = atoi(token);

                token = strtok(NULL, ";");
                strcpy(jk[i], token);

                token = strtok(NULL, ";");
                strcpy(goldar[i], token);

                token = strtok(NULL, ";");
                strcpy(status[i], token);

                token = strtok(NULL, "\n");
                strcpy(pekerjaan[i], token);

                ++i;
            }
            else if(temp - no[i - 1] == 1){
                no[i] = temp;

                token = strtok(NULL, ";");
                NIK[i] = atof(token);

                token = strtok(NULL, ";");
                strcpy(nama[i], token);

                token = strtok(NULL, ";");
                strcpy(tempat_lahir[i], token);

                token = strtok(NULL, ";");
                strcpy(tanggal_lahir[i], token);

                token = strtok(NULL, ";");
                umur[i] = atoi(token);

                token = strtok(NULL, ";");
                strcpy(jk[i], token);

                token = strtok(NULL, ";");
                strcpy(goldar[i], token);

                token = strtok(NULL, ";");
                strcpy(status[i], token);

                token = strtok(NULL, "\n");
                strcpy(pekerjaan[i], token);

                ++i;
            }
            else {
                end_of_data = 1;
            }
        }
    }

    int add_data = 0, update_data = 0, delete_data = 0;
    int print_data = 0;
    int find_NIK = 0, find_nama = 0, find_umur = 0;

    printf("Apakah anda ingin menambah data? 0 = tidak, 1 = ya : ");
    scanf("%d", &add_data);
    if(add_data){
        printf("\n");
        printf("NIK : ");
        scanf("%f", &NIK_inp);
        printf("Nama Lengkap : ");
        scanf(" %[^\n]s", &nama_inp);
        printf("Tempat Lahir : ");
        scanf(" %s", &tempat_lahir_inp);
        printf("Tanggal Lahir : ");
        scanf(" %s", &tanggal_lahir_inp);
        printf("Umur : ");
        scanf(" %d", &umur_inp);
        printf("Jenis Kelamin : ");
        scanf(" %s", &jk_inp);
        printf("Golongan darah : ");
        scanf(" %s", &goldar_inp);
        printf("Status : ");
        scanf(" %[^\n]s", &status_inp);
        printf("Pekerjaan : ");
        scanf(" %s", &pekerjaan_inp);

        printf("\n==Data sukses ditambah==");
        fprintf(myfile, "%d;%.0f;%s;%s;%s;%d;%s;%s;%s;%s\n", i + 1, NIK_inp, nama_inp, tempat_lahir_inp, tanggal_lahir_inp, umur_inp, jk_inp, goldar_inp, status_inp, pekerjaan_inp);
        printf("\n");
    }
    else {
        printf("Apakah anda ingin melakukan update pada data? 0/1 : ");
        scanf("%d", &update_data);
        if(update_data){
            printf("\n");
            printf("Input NIK : ");
            scanf("%f", &NIK_inp);
            int id_ubah = 0;
            while(NIK[id_ubah] != NIK_inp){
                id_ubah += 1;
            }
            printf("Nama Lengkap : ");
            scanf(" %[^\n]s", &nama_inp);
            printf("Tempat Lahir : ");
            scanf(" %s", &tempat_lahir_inp);
            printf("Tanggal Lahir : ");
            scanf(" %s", &tanggal_lahir_inp);
            printf("Umur : ");
            scanf(" %d", &umur_inp);
            printf("Jenis Kelamin : ");
            scanf(" %s", &jk_inp);
            printf("Golongan darah : ");
            scanf(" %s", &goldar_inp);
            printf("Status : ");
            scanf(" %[^\n]s", &status_inp);
            printf("Pekerjaan : ");
            scanf(" %s", &pekerjaan_inp);
            strcpy(nama[id_ubah], nama_inp);
            strcpy(tempat_lahir[id_ubah], tempat_lahir_inp);
            strcpy(tanggal_lahir[id_ubah], tanggal_lahir_inp);
            umur[id_ubah] = umur_inp;
            strcpy(jk[id_ubah], jk_inp);
            strcpy(goldar[id_ubah], goldar_inp);
            strcpy(status[id_ubah], status_inp);
            strcpy(pekerjaan[id_ubah], pekerjaan_inp);

            myfile = fopen(FILENAME, "w");
            for(j = 0; j < i; ++j){
                fprintf(myfile, "%d;%.0f;%s;%s;%s;%d;%s;%s;%s;%s\n", j, NIK[j], nama[j], tempat_lahir[j], tanggal_lahir[j], umur[j], jk[j], goldar[j], status[j], pekerjaan[j]);
            }
            printf("\n");
        }
        else {
            printf("Apakah anda ingin menghapus data? 0/1 : ");
            scanf("%d", &delete_data);
            if(delete_data){
                printf("\n");
                printf("Input NIK : ");
                scanf("%f", &NIK_inp);
                int id_hapus= 0;
                while(NIK[id_hapus] != NIK_inp){
                    id_hapus += 1;
                }

                NIK[id_hapus] = 0;
                strcpy(nama[id_hapus], "");
                strcpy(tempat_lahir[id_hapus], "");
                strcpy(tanggal_lahir[id_hapus], "");
                umur[id_hapus] = 0;
                strcpy(jk[id_hapus], "");
                strcpy(goldar[id_hapus], "");
                strcpy(status[id_hapus], "");
                strcpy(pekerjaan[id_hapus], "");

                myfile = fopen(FILENAME, "w");
                for(j = 0; j < i; ++j){
                    fprintf(myfile, "%d;%.0f;%s;%s;%s;%d;%s;%s;%s;%s\n", j, NIK[j], nama[j], tempat_lahir[j], tanggal_lahir[j], umur[j], jk[j], goldar[j], status[j], pekerjaan[j]);
                }
                printf("\n");
            }
        }
    }

    myfile = fopen(FILENAME, "a+");

    printf("Apakah anda ingin mencetak data? 0/1 : ");
    scanf("%d", &print_data);
    if(print_data){
        printf("\n");
        for(j = 0; j < i; ++j){
            printf("%d %.0f %s %s %s %d %s %s %s %s\n", no[j], NIK[j], nama[j], tempat_lahir[j], tanggal_lahir[j], umur[j], jk[j], goldar[j], status[j], pekerjaan[j]);
        }
        printf("\n");
    }

    printf("Apakah anda ingin melakukan pencarian dengan parameter NIK? 0/1 : ");
    scanf("%d", &find_NIK);
    if(find_NIK){
        printf("\n");
        printf("Input NIK : ");
        scanf("%f", &NIK_inp);
        int id_find = 0;
        while(NIK[id_find] != NIK_inp && id_find != i){
            id_find += 1;
        }
        if(id_find == i){
            printf("Data tidak ditemukan");
        } else {
            printf("%d %.0f %s %s %s %d %s %s %s %s\n", no[id_find], NIK[id_find], nama[id_find], tempat_lahir[id_find], tanggal_lahir[id_find], umur[id_find], jk[id_find], goldar[id_find], status[id_find], pekerjaan[id_find]);
        }
        printf("\n");
    }

    printf("Apakah anda ingin melakukan pencarian dengan parameter Nama? 0/1 : ");
    scanf("%d", &find_nama);
    if(find_nama){
        printf("\n");
        printf("Input nama : ");
        scanf(" %[^\n]s", &nama_inp);
        int id_find = 0;
        while(strcmp(nama_inp, nama[id_find]) && id_find != i){
            id_find += 1;
        }
        if(id_find != i){
            printf("Data tidak ditemukan");
        }
        else {
            printf("%d %.0f %s %s %s %d %s %s %s %s\n", no[id_find], NIK[id_find], nama[id_find], tempat_lahir[id_find], tanggal_lahir[id_find], umur[id_find], jk[id_find], goldar[id_find], status[id_find], pekerjaan[id_find]);
        }
        printf("\n");
    }

    printf("Apakah anda ingin melakukan pencarian dengan parameter Umur? 0/1 : ");
    scanf("%d", &find_umur);
    if(find_umur){
        printf("\n");
        printf("Input umur : ");
        scanf("%d", &umur_inp);
        for(j = 0; j < i; ++j){
            if(umur[j] == umur_inp){
                printf("%d %.0f %s %s %s %d %s %s %s %s\n", no[j], NIK[j], nama[j], tempat_lahir[j], tanggal_lahir[j], umur[j], jk[j], goldar[j], status[j], pekerjaan[j]);
            }
        }
        printf("\n");
    }

    fclose(myfile);
    return 0;
}

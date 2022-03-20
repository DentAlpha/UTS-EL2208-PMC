#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kelipatan_terdekat(int tujuan, int base)
{
    int n = 1;
    while(n*base < tujuan){
        n += 1;
    }
    return (n - 1);
}

// Fungsi konversi signed ke desimal
int sign_bin_to_dec(char bin_inp[8])
{
    int temp = 0;
    char temp_digit[1];
    for(int i = 1; i < 8; ++i){
        temp_digit[0] = bin_inp[i];
        temp += atoi(temp_digit) * pow(2, 7 - i);
    }

    if(bin_inp[0] == '1'){
        temp *= -1;
    }
    return temp;
}

// Fungsi konversi desimal ke signed (dengan penanganan kasus underflow)
void dec_to_sign_bin(int bil, char arr[8])
{
    // Untuk kasus bentuk desimal dibawah batas bawah
    if(bil < -128){
        if((-bil) % 256 <= 128){
            bil = -(bil % 256);
        }
        else {
            int temp = kelipatan_terdekat(-bil, 256);
            bil = 256 - (-bil - (temp * 256));
        }
    }

    if(bil == -128){
        arr = "10000000";
    }
    else {
        // Mengisi elemen pertama array
        if(bil >= 0){
            arr[0] = '0';
        }
        else {
            arr[0] = '1';
            bil *= -1;
        }

        // Mengisi sisa elemen array
        for(int i = 1; i < 8; ++i){
            if(bil >= pow(2, 7 - i)){
                arr[i] = '1';
                bil -= pow(2, 7 - i);
            }
            else {
                arr[i] = '0';
            }
        }
    }
}

// Fungsi konversi 4 bit ke desimal
int norm_bin2dec(char arr[4])
{
    int temp = 0;
    char temp_digit[1];
    for(int i = 0; i < 4; ++i){
        temp_digit[0] = arr[i];
        temp += atoi(temp_digit) * pow(2, 3 - i);
    }
    return temp;
}
// Fungsi konversi signed ke hex
char hex(char* operan, char* res)
{
    char temp_1[4], temp_2[4];
    for(int i = 0; i < 4; ++i){
        temp_1[i] = operan[i];
        temp_2[i] = operan[4 + i];
    }
    int digit_hex_1 = norm_bin2dec(temp_1);
    int digit_hex_2 = norm_bin2dec(temp_2);
    char hex_1, hex_2;

    if(digit_hex_1 > 9){
        hex_1 = digit_hex_1 + '7';
    }
    else{
        hex_1 = digit_hex_1 + '0';
    }

    if(digit_hex_2 > 9){
        hex_2 = digit_hex_2 + '7';
    }
    else{
        hex_2 = digit_hex_2 + '0';
    }

    res[0] = hex_1;
    res[1] = hex_2;
}

// Fungsi konversi signed ke 2's Complement
int sign_bin_to_2c(char* operan, char* res)
{
    int temp = sign_bin_to_dec(operan);

    for(int i = 0; i < 8; ++i){
            res[i] = operan[i];
        }

    if(temp < 0){
        int i, n_not = 7;
        while(operan[n_not] != '1'){
            res[n_not] = operan[n_not];
            n_not -= 1;
        }
        res[n_not] = operan[n_not];

        for(i = 1; i < n_not; ++i){
            if(operan[i] == '1'){
                res[i] = '0';
            }
            else{
                res[i] = '1';
            }
        }
    }
}

// Fungsi konversi signed ke unsigned (dengan penanganan kasus underflow)
int sign_bin_to_unsign_bin(char* operan, char* res)
{
    int dec_operan = sign_bin_to_dec(operan);
    if(dec_operan < 0){
        int temp = kelipatan_terdekat(-dec_operan, 256) + 1;
        int dec_unsign_bin = (temp * 256) - (-dec_operan);

        for(int i = 0; i < 8; ++i){
            if(dec_unsign_bin >= pow(2, 7 - i)){
                res[i] = '1';
                dec_unsign_bin -= pow(2, 7 - i);
            }
            else {
                res[i] = '0';
            }
        }
    }
    else {
        for(int i = 0; i < 8; ++i){
            res[i] = operan[i];
        }
    }
}

// Operator and
void op_and(char* operan1, char* operan2, char* res)
{
    for(int i = 0; i < 8; ++i){
        if(operan1[i] == '1' && operan2[i] == '1'){
            res[i] = '1';
        }
        else {
            res[i] = '0';
        }
    }
}

// Operator or
void op_or(char* operan1, char* operan2, char* res)
{
    for(int i = 0; i < 8; ++i){
        if(operan1[i] == '1' || operan2[i] == '1'){
            res[i] = '1';
        }
        else {
            res[i] = '0';
        }
    }
}

// Operator xor
void op_xor(char* operan1, char* operan2, char* res)
{
    for(int i = 0; i < 8; ++i){
        if((operan1[i] == '1' && operan2[i] == '0') || (operan1[i] == '0' && operan2[i] == '1')){
            res[i] = '1';
        }
        else {
            res[i] = '0';
        }
    }
}

// Operator not
void op_not(char* operan, char* res)
{
    for(int i = 0; i < 8; ++i){
        if(operan[i] == '0'){
            res[i] = '1';
        }
        else {
            res[i] = '0';
        }
    }
}

// Operator shift right
void shift_right(char* operan, int times, char* res)
{
    for(int i = 7; i >= times; --i){
        res[i] = operan[i - times];
    }

    for(int i = 0; i < times; ++i){
        res[i] = '0';
    }
}

int main()
{
    // Deklarasi dan inisialisasi nilai variabel
    char A[] = "00011011";
    int dec_A = sign_bin_to_dec(A);
    /* signed */ char x1[] = "10100101", x2[] = "11011011", x3[] = "00101111";
    /* signed */ char y1[] = "11101111", y2[] = "11110011", y3[] = "10100101";
    char res_1[] = "00000000", res_2[] = "00000000", res_3[] = "00000000";
    char hex_1[] = "00", hex_2[] = "00", hex_3[] = "00";
    char unsign_1[] = "00000000", unsign_2[] = "00000000", unsign_3[] = "00000000";
    char two_1[] = "00000000", two_2[] = "00000000", two_3[] = "00000000";

    printf("A = %s\nx1 = %s, x2 = %s, x3 = %s\ny1 = %s, y2 = %s, y3 = %s\n\n", A, x1, x2, x3, y1, y2, y3);

    // Operasi baris 1
    op_and(A, y1, res_1);
    op_xor(res_1, x1, res_1);
    hex(res_1, hex_1);
    sign_bin_to_unsign_bin(res_1, unsign_1);
    sign_bin_to_2c(res_1, two_1);
    printf("Operasi : (A & y1) xor x1\nBiner : %s\nHex : %s\nUnsigned : %s\n2'C : %s\n\n", res_1, hex_1, unsign_1, two_1);

    // Operasi baris 2
    shift_right(y2, 4, res_2);
    op_not(res_2, res_2);
    op_and(res_2, x2, res_2);
    int dec_res_2 = sign_bin_to_dec(res_2);
    dec_to_sign_bin(dec_res_2 + dec_A, res_2);
    hex(res_2, hex_2);
    sign_bin_to_unsign_bin(res_2, unsign_2);
    sign_bin_to_2c(res_2, two_2);
    printf("Operasi : (~(y2 >> 4) & x2) + A\nBiner : %s\nHex : %s\nUnsigned : %s\n2'C : %s\n\n", res_2, hex_2, unsign_2, two_2);

    // Operasi baris 3
    shift_right(x3, 2, res_3);
    op_or(res_3, y3, res_3);
    int dec_res_3 = sign_bin_to_dec(res_3);
    dec_to_sign_bin(dec_res_3 * dec_A, res_3);
    hex(res_3, hex_3);
    sign_bin_to_unsign_bin(res_3, unsign_3);
    sign_bin_to_2c(res_3, two_3);
    printf("Operasi : ((x3 >> 2) | y3) * A\nBiner : %s\nHex : %s\nUnsigned : %s\n2'C : %s\n\n", res_3, hex_3, unsign_3, two_3);

    return 0;
}

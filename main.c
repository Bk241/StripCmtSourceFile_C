#include <stdio.h>
#include <stdlib.h>

void check_comment(char);

void block_comment();

void Single_Comment();

FILE *fp, *fp2;

int main(void) {
    char c;

    fp = fopen("D:\\Automotive Software Engineering\\SC_Gen1p2R_bk_Send\\SW\\Core_SW\\Core_Sensor_Interface\\source\\amp.c", "r");

    fp2 = fopen(
            "D:\\Automotive Software Engineering\\SC_Gen1p2R_bk_Send\\SW\\Core_SW\\Core_Sensor_Interface\\source\\ampWO.c",
            "w");

    while ((c = fgetc(fp)) != EOF)
        check_comment(c);

    fclose(fp);
    fclose(fp2);

    return 0;

}

void check_comment(char c) {
    char d;

    if (c == '/') {
        if ((d = fgetc(fp)) == '*')
            block_comment();

        else if (d == '/') {
            Single_Comment();
        } else {
            fputc(c, fp2);
            fputc(d, fp2);
        }
    } else

        fputc(c, fp2);
}

void block_comment() {
    char d, e;

    while ((d = fgetc(fp)) != EOF) {
        if (d == '*') {
            e = fgetc(fp);

            if (e == '/')

                return;
        }
    }
}

void Single_Comment() {

    char d, e;

    while ((d = fgetc(fp)) != EOF) {

        if (d == '/n')
            return;

    }

}

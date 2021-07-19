#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>


int main(int argc, char *argv[]){

    FILE *fp1, *fp2;
    uint32_t Buf1, Buf2;
    uint32_t result;


    fp1 = fopen(argv[1], "rb"); // filename and access mode for opening file
    fread(&Buf1, 32, argc, fp1); // data storage, size(32bit), argc defalt value=1, pointer file

    fp2 = fopen(argv[2], "rb");
    fread(&Buf2, 32, argc, fp2);


    Buf1 = ntohl(Buf1); //network byte order
    Buf2 = ntohl(Buf2);
    result = Buf1 + Buf2;

    // 700(0x2bc) + 800(0x320) = 1500(0x5dc)
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", Buf1, Buf1, Buf2, Buf2, result, result);


    fclose(fp1); // close file
    fclose(fp2);

    return 0;

}

#include <stdio.h>
#include <memory>
#include <string.h>


#pragma pack(push, 1)
typedef struct tagBITMAPFILEHEADER
{
    unsigned short bfType;
} BITMAPFILEHEADER;


typedef struct tagBITMAPINFOHEADER
{
    signed int biWidth;
    signed int biHeight;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    unsigned int biClrUsed;
} BITMAPINFOHEADER;
#pragma pack(pop)

bool ReadFileHeaders(FILE *fin, BITMAPFILEHEADER &bfh, BITMAPINFOHEADER &bih)
{
    memset(&bfh, 0, sizeof(BITMAPFILEHEADER));
    memset(&bih, 0, sizeof(BITMAPINFOHEADER));

    size_t fileHeadersRead = fread(&bfh, sizeof(BITMAPFILEHEADER), 1, fin);
    size_t infoHeadersRead = fread(&bih, sizeof(BITMAPINFOHEADER), 1, fin);

    return (fileHeadersRead + infoHeadersRead == 2);
}

void GetBitmapData(const BITMAPINFOHEADER &bih, signed int &bmpWidth, signed int &bmpHeight,
                   unsigned short &bitCount, unsigned int &bmpClrUsed, unsigned int &bmpSize)
{
    bmpWidth = bih.biWidth;
    bmpHeight = abs(bih.biHeight);

    bitCount = bih.biBitCount;
    if (bitCount < 16)
    {
        bmpClrUsed = bih.biClrUsed;
        if (bmpClrUsed == 0)
        {
            bmpClrUsed = (unsigned int) (1 << bitCount);
        }
    }

    bmpSize = bih.biSizeImage;
    if (bmpSize == 0)
    {
        bmpSize = (unsigned int) ((bmpWidth * bmpHeight) * bitCount / 8);
    }
}

void PrintBitmapData(signed int bmpWidth, signed int bmpHeight, unsigned short bitCount,
                     unsigned int bmpClrUsed, unsigned int bmpCompression, unsigned int bmpSize)
{
    printf("Width = %d\nHeight = %d\n", bmpWidth, bmpHeight);

    printf("Bit count = %u\n", bitCount);
    if (bitCount < 16)
    {
        printf("Palette colours = %u\n", bmpClrUsed);
    }

    switch (bmpCompression)
    {
        case 1:
        case 2:
            printf("Used RLE compression\n");
            break;
        case 4:
            printf("Used JPEG compression\n");
            break;
        case 5:
            printf("Used PNG compression\n");
            break;
        default:
            break;
    }

    printf("Picture size = %u\n", bmpSize);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        return 0;
    }

    FILE *inputFile;
    if (!(inputFile = fopen(argv[1], "rb")))
    {
        printf("Error with opening input file\n");
        return 1;
    }
    fseek(inputFile, 0, SEEK_SET);

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    if (!ReadFileHeaders(inputFile, bfh, bih) || bfh.bfType != 0x4D42)
    {
        printf("This isn't a bitmap file\n");
        fclose(inputFile);
        return 1;
    }
    fclose(inputFile);

    signed int bmpWidth, bmpHeight;
    unsigned short bitCount;
    unsigned int bmpClrUsed, bmpSize;

    GetBitmapData(bih, bmpWidth, bmpHeight, bitCount, bmpClrUsed, bmpSize);
    PrintBitmapData(bmpWidth, bmpHeight, bitCount, bmpClrUsed, bih.biCompression, bmpSize);

    return 0;
}

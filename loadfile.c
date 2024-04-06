#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bitmapfile.h"
#include "grayscale.h"

#pragma pack(1) // パッキングの設定

int show_property(char loadfile[]) {
	char openfile[BUFSIZ];
	FILE* file;

	strcpy(openfile ,loadfile);

	file = fopen(loadfile, "rb");
	if (file == NULL) {
		printf("ファイルを開けませんでした。\n");
		return 1;
	}

	// ヘッダー情報の読み込み
	BMPFileHeader fileHeader;
	BMPInfoHeader infoHeader;

	fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
	fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

	// サイズ情報のチェック
/*	if (infoHeader.width != 512 || infoHeader.height != 512) {
		printf("in main:ファイルのサイズが正しくありません。\n");
		fclose(file);
		return 1;
	}*/

	printf("ファイルタイプ: %c%c\n", fileHeader.type & 0xFF, (fileHeader.type >> 8) & 0xFF);
	printf("ファイルサイズ: %u bytes\n", fileHeader.size);
	printf("オフセット: %u bytes\n", fileHeader.offset);
	printf("画像の幅: %d pixels\n", infoHeader.width);
	printf("画像の高さ: %d pixels\n", infoHeader.height);
	printf("ビット数/ピクセル: %d bits\n", infoHeader.bitCount);
	fclose(file);
/*
	printf("入力画像をグレースケール変換しますか？：Y/N");
	scanf("%c", &yn);

	if (strcmp(yn, "Y") == 0 || strcmp(yn, "y") == 0) {
		convert_to_grayscale("sample.bmp", "grayscale_sample.bmp");
	}
	*/
	return 0;
}

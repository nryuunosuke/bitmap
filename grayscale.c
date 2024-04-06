#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bitmapfile.h"
#include "grayscale.h"

// RGBカラーをグレースケールに変換する関数
// https://qiita.com/yoya/items/96c36b069e74398796f3
unsigned char rgb_to_gray(unsigned char r, unsigned char g, unsigned char b) {
	return (unsigned char)(0.2126 * r + 0.7152 * g + 0.0722 * b);
}

// ビットマップファイルをグレースケールに変換して書き出す関数
void convert_to_grayscale(const char* input_filename, const char* output_filename) {
	FILE* input_file = fopen(input_filename, "rb");
	FILE* output_file = fopen(output_filename, "wb");
	if (!input_file || !output_file) {
		printf("ファイルを開けませんでした。\n");
		return;
	}

	// ヘッダー情報の読み込み
	BMPFileHeader fileHeader;
	BMPInfoHeader infoHeader;

	fread(&fileHeader, sizeof(BMPFileHeader), 1, input_file);
	fread(&infoHeader, sizeof(BMPInfoHeader), 1, input_file);

	// サイズ情報のチェック
/*	if (infoHeader.width != 512 || infoHeader.height != 512) {
		printf("in convert_to_grayscale:ファイルのサイズが正しくありません。\n");
		fclose(input_file);
		fclose(output_file);
		return;
	}*/

	// ヘッダー情報を新しいファイルに書き込む
	fwrite(&fileHeader, sizeof(BMPFileHeader), 1, output_file);
	fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, output_file);

	// ピクセルデータの変換と書き込み
	unsigned char pixelData[3];
	for (int y = 0; y < infoHeader.height; y++) {
		for (int x = 0; x < infoHeader.width; x++) {
			fread(&pixelData, sizeof(pixelData), 1, input_file);
			unsigned char grayValue = rgb_to_gray(pixelData[2], pixelData[1], pixelData[0]);
			fwrite(&grayValue, sizeof(grayValue), 1, output_file);
			fwrite(&grayValue, sizeof(grayValue), 1, output_file);
			fwrite(&grayValue, sizeof(grayValue), 1, output_file);
		}
	}

	fclose(input_file);
	fclose(output_file);
	printf("変換が完了しました。\n");
}
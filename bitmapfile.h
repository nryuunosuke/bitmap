#ifndef BITMAPFIME_H
#define BITMAPFILE_H


#include <stdint.h>
#pragma once

//FIle Header
typedef struct {
	uint16_t type;          // ファイルタイプ('BM')
	uint32_t size;          // ファイルサイズ
	uint16_t reserved1;     // 予約領域1
	uint16_t reserved2;     // 予約領域2
	uint32_t offset;        // ファイル先頭から画像データまでのオフセット
} BMPFileHeader;

//InfoHeader
typedef struct {
	uint32_t size;          // 情報ヘッダーのサイズ
	int32_t width;          // 画像の幅
	int32_t height;         // 画像の高さ
	uint16_t planes;        // 色プレーン数(常に1)
	uint16_t bitCount;      // ビット数/ピクセル(1, 4, 8, 16, 24, 32)
	uint32_t compression;   // 圧縮方式
	uint32_t imageSize;     // 画像データのサイズ
	int32_t xPixelsPerMeter; // 横方向の解像度(ピクセル/メートル)
	int32_t yPixelsPerMeter; // 縦方向の解像度(ピクセル/メートル)
	uint32_t colorsUsed;    // カラーパレットで実際に使用される色数
	uint32_t colorsImportant; // 重要な色数
} BMPInfoHeader;

#endif // !BITMAPFIME_H

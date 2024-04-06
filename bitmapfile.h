#ifndef BITMAPFIME_H
#define BITMAPFILE_H


#include <stdint.h>
#pragma once

//FIle Header
typedef struct {
	uint16_t type;          // �t�@�C���^�C�v('BM')
	uint32_t size;          // �t�@�C���T�C�Y
	uint16_t reserved1;     // �\��̈�1
	uint16_t reserved2;     // �\��̈�2
	uint32_t offset;        // �t�@�C���擪����摜�f�[�^�܂ł̃I�t�Z�b�g
} BMPFileHeader;

//InfoHeader
typedef struct {
	uint32_t size;          // ���w�b�_�[�̃T�C�Y
	int32_t width;          // �摜�̕�
	int32_t height;         // �摜�̍���
	uint16_t planes;        // �F�v���[����(���1)
	uint16_t bitCount;      // �r�b�g��/�s�N�Z��(1, 4, 8, 16, 24, 32)
	uint32_t compression;   // ���k����
	uint32_t imageSize;     // �摜�f�[�^�̃T�C�Y
	int32_t xPixelsPerMeter; // �������̉𑜓x(�s�N�Z��/���[�g��)
	int32_t yPixelsPerMeter; // �c�����̉𑜓x(�s�N�Z��/���[�g��)
	uint32_t colorsUsed;    // �J���[�p���b�g�Ŏ��ۂɎg�p�����F��
	uint32_t colorsImportant; // �d�v�ȐF��
} BMPInfoHeader;

#endif // !BITMAPFIME_H

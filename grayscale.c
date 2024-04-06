#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bitmapfile.h"
#include "grayscale.h"

// RGB�J���[���O���[�X�P�[���ɕϊ�����֐�
// https://qiita.com/yoya/items/96c36b069e74398796f3
unsigned char rgb_to_gray(unsigned char r, unsigned char g, unsigned char b) {
	return (unsigned char)(0.2126 * r + 0.7152 * g + 0.0722 * b);
}

// �r�b�g�}�b�v�t�@�C�����O���[�X�P�[���ɕϊ����ď����o���֐�
void convert_to_grayscale(const char* input_filename, const char* output_filename) {
	FILE* input_file = fopen(input_filename, "rb");
	FILE* output_file = fopen(output_filename, "wb");
	if (!input_file || !output_file) {
		printf("�t�@�C�����J���܂���ł����B\n");
		return;
	}

	// �w�b�_�[���̓ǂݍ���
	BMPFileHeader fileHeader;
	BMPInfoHeader infoHeader;

	fread(&fileHeader, sizeof(BMPFileHeader), 1, input_file);
	fread(&infoHeader, sizeof(BMPInfoHeader), 1, input_file);

	// �T�C�Y���̃`�F�b�N
/*	if (infoHeader.width != 512 || infoHeader.height != 512) {
		printf("in convert_to_grayscale:�t�@�C���̃T�C�Y������������܂���B\n");
		fclose(input_file);
		fclose(output_file);
		return;
	}*/

	// �w�b�_�[����V�����t�@�C���ɏ�������
	fwrite(&fileHeader, sizeof(BMPFileHeader), 1, output_file);
	fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, output_file);

	// �s�N�Z���f�[�^�̕ϊ��Ə�������
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
	printf("�ϊ����������܂����B\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bitmapfile.h"
#include "grayscale.h"

#pragma pack(1) // �p�b�L���O�̐ݒ�

int show_property(char loadfile[]) {
	char openfile[BUFSIZ];
	FILE* file;

	strcpy(openfile ,loadfile);

	file = fopen(loadfile, "rb");
	if (file == NULL) {
		printf("�t�@�C�����J���܂���ł����B\n");
		return 1;
	}

	// �w�b�_�[���̓ǂݍ���
	BMPFileHeader fileHeader;
	BMPInfoHeader infoHeader;

	fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
	fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);

	// �T�C�Y���̃`�F�b�N
/*	if (infoHeader.width != 512 || infoHeader.height != 512) {
		printf("in main:�t�@�C���̃T�C�Y������������܂���B\n");
		fclose(file);
		return 1;
	}*/

	printf("�t�@�C���^�C�v: %c%c\n", fileHeader.type & 0xFF, (fileHeader.type >> 8) & 0xFF);
	printf("�t�@�C���T�C�Y: %u bytes\n", fileHeader.size);
	printf("�I�t�Z�b�g: %u bytes\n", fileHeader.offset);
	printf("�摜�̕�: %d pixels\n", infoHeader.width);
	printf("�摜�̍���: %d pixels\n", infoHeader.height);
	printf("�r�b�g��/�s�N�Z��: %d bits\n", infoHeader.bitCount);
	fclose(file);
/*
	printf("���͉摜���O���[�X�P�[���ϊ����܂����H�FY/N");
	scanf("%c", &yn);

	if (strcmp(yn, "Y") == 0 || strcmp(yn, "y") == 0) {
		convert_to_grayscale("sample.bmp", "grayscale_sample.bmp");
	}
	*/
	return 0;
}

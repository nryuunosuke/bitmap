#include <stdio.h>
#include <string.h>
#include "bitmapfile.h"
#include "grayscale.h"
#include "loadfile.h"


int main(void) {

	int i;
	int menu = -1;
	char lfile[BUFSIZ];// = "IMAG0171.bmp";
	char ofile[BUFSIZ];
	//char menu[BUFSIZ] = "";

	printf("BITMAP�t�@�C���ϊ��V�X�e��\n");
	do {
		printf("1:�摜�v���p�e�B�\��\t2:CIE XYZ�O���[�X�P�[���ϊ�\t3:�P�����σO���[�X�P�[���ϊ�\t0:�I��\n�����s���܂����H:");
		scanf("%d", &menu);

		if (menu == 1) {
			printf("�ǂݍ��ރt�@�C��������͂��Ă�������:");
			scanf("%s", lfile);
			show_property(lfile);
		}
		else if (menu == 2) {
			printf("�ǂݍ��ރt�@�C��������͂��Ă�������:");
			scanf("%s", lfile);
			printf("�ϊ���t�@�C��������͂��Ă�������:");
			scanf("%s", ofile);
			convert_to_grayscale(lfile, ofile);
		}
		else if (menu == 3) {
			printf("�ǂݍ��ރt�@�C��������͂��Ă�������:");
			scanf("%s", lfile);
			printf("�ϊ���t�@�C��������͂��Ă�������:");
			scanf("%s", ofile);
			printf("���̋@�\�͖������ł�\n");
		}
		else if (menu == 0) {
			printf("�V�X�e�����I�����܂��B\n");
			break;
		}
		else {
			printf("���͂�����������܂���B������x���͂��Ă��������B\n");
		}


	} while (menu != 0);

	return 0;
}
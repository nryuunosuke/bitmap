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

	printf("BITMAPファイル変換システム\n");
	do {
		printf("1:画像プロパティ表示\t2:CIE XYZグレースケール変換\t3:単純平均グレースケール変換\t0:終了\n何を行いますか？:");
		scanf("%d", &menu);

		if (menu == 1) {
			printf("読み込むファイル名を入力してください:");
			scanf("%s", lfile);
			show_property(lfile);
		}
		else if (menu == 2) {
			printf("読み込むファイル名を入力してください:");
			scanf("%s", lfile);
			printf("変換先ファイル名を入力してください:");
			scanf("%s", ofile);
			convert_to_grayscale(lfile, ofile);
		}
		else if (menu == 3) {
			printf("読み込むファイル名を入力してください:");
			scanf("%s", lfile);
			printf("変換先ファイル名を入力してください:");
			scanf("%s", ofile);
			printf("この機能は未実装です\n");
		}
		else if (menu == 0) {
			printf("システムを終了します。\n");
			break;
		}
		else {
			printf("入力が正しくありません。もう一度入力してください。\n");
		}


	} while (menu != 0);

	return 0;
}
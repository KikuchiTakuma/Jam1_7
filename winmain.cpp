#include "DxLib.h"
#include "HpBar.h"

int die = false;
void DrawHP(int hp, int hpMax) {
	int color = GetColor(255, 255, 255);
	
	DrawBox(100, 100, 100 + 200, 100 + 20, color, FALSE);//枠を描画
	if(die == false){
	DrawBox(100, 100, 100 + 200 * hp / hpMax, 100 + 20, color, true);//HPゲージを描画
	}
}


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DXライブラリの初期化処理 ここから
	
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//DXライブラリの初期化処理 ここまで


	//メイン処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//ドット描画処理
		
		
		int hpbar = 200, hpMax = 200;

		while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
			DrawHP(hpbar, hpMax);
			hpbar--;
			if (hpbar >= hpMax) {
				hpbar = 0;
			}
			if (hpbar == 0)
			{
				die = true;
			}
		}
	}

		int color = GetColor(255, 255, 255);
		DrawPixel(400, 300, color);
		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}


	


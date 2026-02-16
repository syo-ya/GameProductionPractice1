#include "DxLib.h"
#include "FPS.h"

<<<<<<< HEAD
// 平均を計算するタイミング（大体はFPSと同じ数でOK）
#define FPS_SAMPLE_NUM (60) // 60フレームに一度平均を計算する

// ゲームのFPS
#define FPS (60)

int g_StartTime;      // 測定開始時刻
int g_Count;          // カウンタ
float g_Fps;          // 現在のFPS
=======
#define FPS_SAMPLE_NUM (60)

#define FPS (60)

int g_StartTime;
int g_Count;
float g_Fps;
>>>>>>> 2279d255b9c276b61a1e6a25decf2d5888bafc0a

void InitFPS()
{
    g_StartTime = GetNowCount();
    g_Count = 0;
    g_Fps = 0;
}

void UpdateFPS()
{
<<<<<<< HEAD
    // 1フレーム目なら時刻を記憶
=======
>>>>>>> 2279d255b9c276b61a1e6a25decf2d5888bafc0a
    if (g_Count == 0)
    {
        g_StartTime = GetNowCount();
    }

<<<<<<< HEAD
    // サンプル数と同じ回数フレームが回ったら平均を計算する
    if (g_Count == FPS_SAMPLE_NUM)
    {
        int time = GetNowCount();
        // かかった時間（ﾐﾘ秒）をサンプル数で割り平均とする（その値が現在のFPS値）
=======
    if (g_Count == FPS_SAMPLE_NUM) {
        int time = GetNowCount();
>>>>>>> 2279d255b9c276b61a1e6a25decf2d5888bafc0a
        g_Fps = 1000.f / ((time - g_StartTime) / (float)FPS_SAMPLE_NUM);
        g_Count = 0;
        g_StartTime = time;
    }
    g_Count++;

}

void DrawFPS()
{
<<<<<<< HEAD
    DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS【%.1f】", g_Fps);
=======

>>>>>>> 2279d255b9c276b61a1e6a25decf2d5888bafc0a
}

void FPSWait()
{
<<<<<<< HEAD
    // かかった時間
    int takeTime = GetNowCount() - g_StartTime;

    // 待機時間
    // FPSの値から1フレームにかかってほしい時間（g_Count * 1000 / FPS）
    // 実際に経過した時間（takeTime）
    // 実際の時間が早すぎた場合は、その差分を待機時間とする
    int waitTime = g_Count * 1000 / FPS - takeTime;

    // 待機
=======
    int takeTime = GetNowCount() - g_StartTime;

    int waitTime = g_Count * 1000 / FPS - takeTime;

>>>>>>> 2279d255b9c276b61a1e6a25decf2d5888bafc0a
    if (waitTime > 0)
    {
        Sleep(waitTime);
    }
<<<<<<< HEAD
=======
}

float rFPS()
{
    return g_Fps;
>>>>>>> 2279d255b9c276b61a1e6a25decf2d5888bafc0a
}
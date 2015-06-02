#pragma once

#include "resource.h"
#include "Item.h"
#include "Player.h"
#include "Monster.h"
#include "GameManager.h"
#include <Windows.h>

//전역변수
extern HINSTANCE hInst;								// 현재 인스턴스입니다.		 extern 키워드 모르겠으면 검색 ㄱㄱ
extern HDC hdc;										// 다른 파일들에서 이 변수들을 쓰기위해 선언했음.

extern GameManager GM;					// 게임이 돌아가게 만드는 각종 기능들을 관리
extern int itemStockCounter;
#pragma once

#include "stdafx.h"
class GameManager{
private:
	Object** objectArray;
	Item itemStock[3];					// 아이템 스톡은 세개까지
	int objectCount = 0;

public:
	GameManager();
	~GameManager();
	void startGame();			// 시작할때 모든 값들을 초기화합니다.
	void draw();				// GameManager에 등록된 모든 그림을 그립니다!
	
	void deleteObject();
	void putObject(Object* a);		// GameManager에 오브젝트를 추가합니다. 최대 255개

	// 게임안에 맵툴 기능까지 넣어버립시다. 스테이지(진행상황 아님!!)의 세이브/로드
	void save();
	void load();
};
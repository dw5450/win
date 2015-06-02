#include "stdafx.h"

#define OBJECTMAX 255

int itemStockCounter = 0;

GameManager::GameManager(){
	objectArray = new Object*[OBJECTMAX];
};

GameManager::~GameManager(){
	for (int i = 0; i < objectCount; ++i){
		delete objectArray[i];
	}
	delete[] objectArray;
};

void GameManager::draw(){
	for (int i = 0; i < objectCount; ++i){
		objectArray[i]->draw();
	}
};

void GameManager::putObject(Object* a){
	//테스트용
	objectArray[objectCount] = a;
	++objectCount;
};

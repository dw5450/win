#pragma once

#include "resource.h"
#include "Item.h"
#include "Player.h"
#include "Monster.h"
#include "GameManager.h"
#include <Windows.h>

//��������
extern HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.		 extern Ű���� �𸣰����� �˻� ����
extern HDC hdc;										// �ٸ� ���ϵ鿡�� �� �������� �������� ��������.

extern GameManager GM;					// ������ ���ư��� ����� ���� ��ɵ��� ����
extern int itemStockCounter;
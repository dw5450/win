#include "stdafx.h"
//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND	- ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT	- �� â�� �׸��ϴ�.
//  WM_DESTROY	- ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//test
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	static POINT OldMousePoint;								//���� ���콺 ����Ʈ    �߰��� ����
	static POINT MousePoint;								//���콺 ����Ʈ		   �߰��� ����
	static bool Drag;										//�巡�� ���� �Ǵ�      �߰��� ����
	static int time1;										//time1 ��� �ð�	   �߰��� ����
	static SIZE tempSize;									//�ӽ� ������		   �߰��� ����

	static Player * PLAYER;
	static	Monster * MONSTER;
	char tempStr[100];
	static long experiment;
	
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 100, NULL);

		tempSize.cx = 100;
		tempSize.cy = 100;
		PLAYER = new Player(150, 150, tempSize);

		tempSize.cx = 120;
		tempSize.cy = 120;
		MONSTER = new Monster(300, 300, tempSize, 1);

		GM.putObject(new Item(50, 50, 0));		// �׽�Ʈ��
		GM.putObject(PLAYER);
		GM.putObject(MONSTER);
		PLAYER->SetResistance(20, 20);

		break;

	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			time1++;
			//MessageBox(hWnd, "???", "???", MB_OK);
			PLAYER->crash(hWnd);
			PLAYER->MoveTo(0, 10);

			//PLAYER->Move();
			
			InvalidateRect(hWnd, NULL, TRUE);
		}
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmId)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;


	case WM_CHAR:

		if (wParam == 'd')
			PLAYER->MoveTo(10, 0);
		else if (wParam == 'a')
			PLAYER->MoveTo(-10, 0);
		else if (wParam == 'w')
			PLAYER->MoveTo(0, -10);
		else if (wParam == 's')
			PLAYER->MoveTo(0, 10);


	case WM_LBUTTONDOWN:
		Drag = true;

		OldMousePoint.x = LOWORD(lParam);
		OldMousePoint.y = HIWORD(lParam);

		break;

	case WM_LBUTTONUP:
		MousePoint.x = LOWORD(lParam);
		MousePoint.y = HIWORD(lParam);

		PLAYER->MoveTo(MousePoint.x - OldMousePoint.x, MousePoint.y - OldMousePoint.y);
		Drag = false;
		break;

	case WM_MOUSEMOVE:
		if (Drag == true)
		{

		}

		break;



	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�;
		PLAYER->Move();
		PLAYER->crash(hWnd);
		GM.draw();
		PLAYER->crash(MONSTER);

		//GM.draw();
		//����׿� �ڵ�
		wsprintf(tempStr, " SpeedXpos : %d", (int)PLAYER->GetSpeedXpos());
		TextOut(hdc, 0, 0, tempStr, strlen(tempStr));
		wsprintf(tempStr, " SpeedYpos : %d", (int)PLAYER->GetSpeedYpos());
		TextOut(hdc, 0, 20, tempStr, strlen(tempStr));
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

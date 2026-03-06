#include<iostream>
using namespace std;

int main()
{
	int Computer[3] = { 0 };
	int User[3] = { 0 };
	int Deck[12] = { 1,2,3,4,5,6,7,8,9,10,10,10 };
		             //1 ~9, j, Q, K

	//덱 랜덤 인덱스
	int ComputerRandomNum = 0;
	int UserRandomNum = 0;

	//컴퓨터, 유저 스코어
	int ComputerScore = 0;
	int UserScore = 0;

	//스코어 21 넘었는지 계산
	bool IsComputerOver = false;
	bool IsUserOver = false;



	// 현재 시간을 시드로 설정하여 매번 다른 난수를 생성
	srand((unsigned int)time(NULL));

	//랜덤숫자 유저,컴퓨터에 매핑
	for (int i = 0; i < 3; i++) {
		ComputerRandomNum = rand() % 12;
		UserRandomNum = rand() % 12;
		
		Computer[i] = Deck[ComputerRandomNum];
		User[i] = Deck[UserRandomNum];
	}

	//랜덤 숫자 매핑 확인
	/*
	for (int i = 0; i < 3; i++) {
		cout << "숫자 매핑확인" << endl;
		cout << Computer[i] << endl;
		cout << User[i] << endl;
	}
	*/


	//매핑된 유저,컴퓨터 숫자 합계산
	for (int i = 0; i < 3; i++) {
		ComputerScore = ComputerScore + Computer[i];
		UserScore = UserScore + User[i];
	}

	//합 확인
	/*
	cout << "합 확인" << endl;
	cout << ComputerScore <<endl;
	cout << UserScore << endl;
	*/

	//21넘었는지 확인
	if (ComputerScore > 21) IsComputerOver = true;
	if (UserScore > 21) IsUserOver = true;

	//둘다 21넘으면 플레이어 승
	if (IsComputerOver && IsUserOver) 
	{
		cout << "플레이어 승!" << endl;
	}
	else if (IsComputerOver) 
	{
		cout << "플레이어 승!" << endl;
	}
	else if (IsUserOver) 
	{
		cout << "Computer 승!" << endl;
	}
	else 
	{
		if (ComputerScore > UserScore)
		{
			cout << "Computer 승!" << endl;
		}
		else
		{
			cout << "플레이어 승!" << endl;
		}
	}

	

	return 0;
}
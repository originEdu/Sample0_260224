#include<iostream>
using namespace std;

int main()
{
	int Computer[3] = { 0 };
	int User[3] = { 0 };
	int Deck[12] = { 1,2,3,4,5,6,7,8,9,10,10,10 }; //1 ~9, j, Q, K

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

	//덱 셔플
	int tmp=0;
	int idx1 = 0;
	int idx2 = 0;
	for (int i = 0; i < 50; i++)
	{
		idx1 = rand() % 12;
		idx2 = rand() % 12;

		tmp = Deck[idx1];
		Deck[idx1] = Deck[idx2];
		Deck[idx2] = tmp;
	}

	/*
	//덱 셔플 확인
	for (int i = 0; i < 12; i++ )
	{
		cout << Deck[i] << " ";
	}
	cout << endl;
	*/

	//유저, 컴퓨터 숫자 뽑기
	for (int i = 0; i < 3; i++)
	{
		Computer[i] = Deck[i*2];
		User[i] = Deck[(i*2)+1];
	}

	/*
	//랜덤숫자 유저,컴퓨터에 매핑
	for (int i = 0; i < 3; i++) 
	{
		ComputerRandomNum = rand() % 12;
		UserRandomNum = rand() % 12;
		
		Computer[i] = Deck[ComputerRandomNum];
		User[i] = Deck[UserRandomNum];

		//차라리 덱을 랜덤으로 섞은 후에 배열하고 하나씩 주는게 낫지 않을까? -> 이게 정답이다!
		//덱 카운팅 변수도 하나 생성하자
	}
	*/

	//랜덤 숫자 매핑 확인
	/*
	for (int i = 0; i < 3; i++) {
		cout << "숫자 매핑확인" << endl;
		cout << Computer[i] << endl;
		cout << User[i] << endl;
	}
	*/


	//매핑된 유저,컴퓨터 숫자 합계산
	for (int i = 0; i < 3; i++) 
	{
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
	if (ComputerScore > 21)
	{
		IsComputerOver = true;
	}
	if (UserScore > 21)
	{
		IsUserOver = true;
	}

	//컴퓨터, 유저 승부확인
	if (IsComputerOver && IsUserOver) //둘다 21넘으면 플레이어 승
	{
		cout << "플레이어 승!" << endl;
	}
	else if (IsComputerOver) //컴퓨터만 넘었으면 플레이어 승
	{
		cout << "플레이어 승!" << endl;
	}
	else if (IsUserOver) //유저만 넘었으면 플레이어 승
	{
		cout << "Computer 승!" << endl;
	}
	else //둘다 넘지 않았을 경우
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
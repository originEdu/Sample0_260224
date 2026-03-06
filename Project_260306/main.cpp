#include<iostream>
#include<string>
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
	cout << "숫자 매핑확인" << endl;
	for (int i = 0; i < 3; i++) {
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

	//강사님코드
/*
#include <iostream>
#include <string>

#define CARDSIZE			52

		using namespace std;

		//문법이 생김, C++, class 

		//Heart
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
		//Spade
		//13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
		//Diamond
		//26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		//Clover
		//39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,

		//똑같은 카드가 나옴 안됨.


		//stack X
		int Player[CARDSIZE];
		int Cards[CARDSIZE] = { 0, };
		string CardType[4] = { "Heart", "Spade", "Diamond", "Clover" };

		int ComputerCard[3];
		int PlayerCard[3];
		//PreProcess
		int ComputerScore[3] = { 0, };
		int PlayerScore[3] = { 0, };

		int TotalComputerScore;
		int TotalPlayerScore;



		string DrawShape(int CardNumber)
		{
			int Shape = (CardNumber % 13 + 1);

			if (Shape == 11)
			{
				return "J";
			}
			else if (Shape == 12)
			{
				return "Q";
			}
			else if (Shape == 13)
			{
				return "K";
			}
			else if (Shape == 1)
			{
				return "A";
			}

			return to_string(Shape);
		}


		void Init()
		{
			for (int i = 0; i < CARDSIZE; ++i)
			{
				Cards[i] = i;
			}

			srand((unsigned int)time(nullptr));
		}

		void Shuffle()
		{
			//Random(난수) 두개 선택 해서 교환
			//카드 10장 교환
			for (int i = 0; i < CARDSIZE * 10; ++i)
			{
				int FirstIndex = rand() % CARDSIZE;
				int SecondIndex = rand() % CARDSIZE;
				int Temp = Cards[FirstIndex];

				Cards[FirstIndex] = Cards[SecondIndex];
				Cards[SecondIndex] = Temp;
			}
		}

		void Deal()
		{
			//Deal
			//0, 1
			//2, 3
			//4, 5
			for (int i = 0; i < 3; ++i)
			{
				ComputerCard[i] = Cards[i * 2];
				PlayerCard[i] = Cards[(i * 2) + 1];
			}
		}

		void PreProcess()
		{
			for (int i = 0; i < 3; ++i)
			{
				ComputerScore[i] = (ComputerCard[i] % 13 + 1) > 10 ? 10 : (ComputerCard[i] % 13 + 1);

				PlayerScore[i] = PlayerCard[i] % 13 + 1;

				PlayerScore[i] = PlayerScore[i] > 10 ? 10 : PlayerScore[i];
			}

			TotalComputerScore = ComputerScore[0] + ComputerScore[1] + ComputerScore[2];
			TotalPlayerScore = PlayerScore[0] + PlayerScore[1] + PlayerScore[2];
		}

		void Draw()
		{
			//Draw
			if (TotalComputerScore > 21)
			{
				cout << "Player Win" << endl;
			}
			else if (TotalPlayerScore > 21)
			{
				cout << "Player Lose" << endl;
			}
			else if (TotalComputerScore > TotalPlayerScore)
			{
				cout << "Player Lose" << endl;
			}
			else
			{
				cout << "Player Win" << endl;
			}

			cout << "\n==========================" << endl;
			cout << "Computer Deck" << endl;
			for (int i = 0; i < 3; ++i)
			{
				int CardTypeIndex = ComputerCard[i] / 13;

				cout << CardType[CardTypeIndex] << " " << DrawShape(ComputerCard[i]) << endl;
			}
			cout << "Total : " << TotalComputerScore << endl;
			cout << "==========================\n" << endl;

			cout << "==========================" << endl;
			cout << "Player Deck" << endl;
			for (int i = 0; i < 3; ++i)
			{
				int CardTypeIndex = PlayerCard[i] / 13;

				cout << CardType[CardTypeIndex] << " " << DrawShape(PlayerCard[i]) << endl;
			}
			cout << "Total : " << TotalPlayerScore << endl;
			cout << "==========================" << endl;

		}


		int main() //entry point
		{

			//절차 지향 프로그래밍
			Init();
			Shuffle();
			Deal();
			PreProcess();
			Draw();

			return 0;
		}
		*/
}
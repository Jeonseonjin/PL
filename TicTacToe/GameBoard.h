typedef struct position		/* x,y 좌표 나타내는 구조체 */
{
	int x;
	int y;
}Position;

typedef struct treeNode		/* 출력을 위한 노드 구조체 */
{
	int depth;				/* 현재 노드의 깊이 */
	int eval;				/* 현재 게임판 평가값 */
	int childCnt;			/* 노드가 가지고 있는 자식노드 개수 */
	struct treeNode* next[16];	/* 자식 노드들 */
}Node;

class GameBoard
{
public :
	Position* preMoves;	/* 이전 수 저장할 배열*/
	char**	board;			/* 3X3 2차원 배열 */

	int moveCnt;			/* 현재 수 개수 */
	int	state;				/* 현재 게임판 상태 */
	int	startLevel;			/* 컴퓨터 레벨 */
	char starterCom;		/* 나 */
	char oppnentCom;		/* 컴퓨터 */

	static const int STATE_WINA = 3;		/* 컴퓨터가 이겼을 때 */
	static const int STATE_WINB = 4;		/* 내가 이겼을 때 */
	static const int STATE_DRAW = 5;		/* 게임이 비겼을 때 */
	static const int STATE_PLAY = 7;		/* 현재 게임 중 일 때 */
	static const int STATE_INIT = 8;		/* 게임이 초기화된 상태 */
	static const int STATE_STOP = 9;		/* 게임이 중지 될 때 */

public :

	GameBoard();							/* 게임판 생성자 */
	GameBoard(const GameBoard& copy);		/* 게임판 클래스 복사 생성자 */	
	int GetBoardStat();						/* 게임 판 현재 상태 얻기 */
	void InitBoard(int startCom, int movedCnt, int nlevelA);
	void RandomMove();	/* 랜덤하게 수를 놓을 때 */
	void DoMove(int x, int y);				/* 좌표를 입력 받아 수를 놓을 때 */
	void UndoMove();						/* 놓았던 수 무르기 */
	void CheckState();						/* 현재 게임판 상태 체크 */

};
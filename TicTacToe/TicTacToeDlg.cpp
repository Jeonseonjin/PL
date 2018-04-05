
// TicTacToeDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TicTacToe.h"
#include "TicTacToeDlg.h"
#include "afxdialogex.h"
#include "FileDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

														// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{

}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTicTacToeDlg ��ȭ ����

CTicTacToeDlg::CTicTacToeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTicTacToeDlg::IDD, pParent)
	, m_startCom(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTicTacToeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_UNDO_B, m_undoB);
	DDX_Control(pDX, IDC_COMBO_A, m_comboA);
	DDX_Control(pDX, IDC_EDIT_A, m_listA);
}

BEGIN_MESSAGE_MAP(CTicTacToeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CTicTacToeDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &CTicTacToeDlg::OnBnClickedButtonInit)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CTicTacToeDlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CTicTacToeDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_UNDO_B, &CTicTacToeDlg::OnBnClickedButtonUndoB)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_A39, &CTicTacToeDlg::OnBnClickedA39)
	ON_BN_CLICKED(IDC_A40, &CTicTacToeDlg::OnBnClickedA40)
	ON_BN_CLICKED(IDC_A41, &CTicTacToeDlg::OnBnClickedA41)
	ON_BN_CLICKED(IDC_A42, &CTicTacToeDlg::OnBnClickedA42)
	ON_BN_CLICKED(IDC_A43, &CTicTacToeDlg::OnBnClickedA43)
	ON_BN_CLICKED(IDC_A44, &CTicTacToeDlg::OnBnClickedA44)
	ON_BN_CLICKED(IDC_A45, &CTicTacToeDlg::OnBnClickedA45)
	ON_BN_CLICKED(IDC_A46, &CTicTacToeDlg::OnBnClickedA46)
	ON_BN_CLICKED(IDC_A47, &CTicTacToeDlg::OnBnClickedA47)
	ON_BN_CLICKED(IDC_A48, &CTicTacToeDlg::OnBnClickedA48)
	ON_BN_CLICKED(IDC_A49, &CTicTacToeDlg::OnBnClickedA49)
	ON_BN_CLICKED(IDC_A50, &CTicTacToeDlg::OnBnClickedA50)
	ON_BN_CLICKED(IDC_A51, &CTicTacToeDlg::OnBnClickedA51)
	ON_BN_CLICKED(IDC_A52, &CTicTacToeDlg::OnBnClickedA52)
	ON_BN_CLICKED(IDC_A53, &CTicTacToeDlg::OnBnClickedA53)
	ON_BN_CLICKED(IDC_A54, &CTicTacToeDlg::OnBnClickedA54)
END_MESSAGE_MAP()


// CTicTacToeDlg �޽��� ó����

BOOL CTicTacToeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

									// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_hAccelTable = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));

	GetDlgItem(IDC_BUTTON_UNDO_B)->EnableWindow(false);
	m_BKColor = CreateSolidBrush(RGB(255, 255, 255));

	m_isLoad = 0;
	m_checkUndo = 0;

	SetGame();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CTicTacToeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

BOOL CTicTacToeDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.	 
	if (m_hAccelTable != NULL)
	{
		if (TranslateAccelerator(m_hWnd, m_hAccelTable, pMsg))
		{
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CTicTacToeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CTicTacToeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HBRUSH CTicTacToeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	if (pWnd->GetDlgCtrlID() == IDC_EDIT_A)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));
		return m_BKColor;
	}

	return hbr;
}

void CTicTacToeDlg::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int conclusion;
	
	GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L" ");

	if (m_board.state == GameBoard::STATE_PLAY)
	{
		conclusion = MessageBox(L"���� �������Դϴ�.\n������ �ߴ� �Ͻðڽ��ϱ�?", L"���� �ߴ�", MB_OKCANCEL);
		if (conclusion == IDOK)
			m_board.state = GameBoard::STATE_STOP;
	}
	else {
		conclusion = MessageBox(L"������ ���� �Ͻðڽ��ϱ�?", L"���� ����", MB_OKCANCEL);
		if (conclusion == IDOK)
			exit(0);
	}
}

void CTicTacToeDlg::OnBnClickedButtonUndoB()
{
	m_checkUndo = 1;
	m_board.UndoMove();
	m_board.UndoMove();
	UpdateGame();
}

void CTicTacToeDlg::OnBnClickedButtonStart()
{
	StartGame();
	GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L" ");
}

void CTicTacToeDlg::OnBnClickedButtonInit()
{
	SaveGame();
	//ResetGame();
	GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L" ");
}

void CTicTacToeDlg::OnBnClickedButtonLoad()
{
	LoadGame();
	StartGame();
	GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L" ");
}

int CTicTacToeDlg::CheckReady()
{
	UpdateData(TRUE);

	int level_a = m_comboA.GetCurSel();

	if(level_a == -1)
		return -1;

	else
	{
		switch (level_a)
		{
		case 0: m_levelA = 3; break;
		case 1: m_levelA = 5; break;
		}

		return 1;
	}
}

void CTicTacToeDlg::SetGame()
{

	m_comboA.AddString(L"Level 3");
	m_comboA.AddString(L"Level 5");

	m_comboA.SetCurSel(0);
	GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"<���� Ʈ��>");

	m_levelA = 0;
}

/**
�� �� : StartGame()
�� �� : ���� ���� ��ư�� �������� �����ϴ� �Լ��ν�, �⺻������
������ ���۵Ǳ��� �ɼ� ������ �غ�Ǿ����� üũ�ϰ�, �߰������� �ҷ���
���������� ���θ� �˻��ؼ� �������� �ʱ�ȭ ������.
������ �Ϸ�Ǹ� ������ ���������� �������� ���� ��
*/
void CTicTacToeDlg::StartGame()
{
	int checkErr;				/* ���� ������ �˷��ִ� ���� */

	checkErr = CheckReady();	/* ������ ������ �غ� �Ǿ����� �˻� */
	
	if (checkErr == -1)	/* ���� ������ �ȵǾ������� ���� ��� */
	{
		MessageBox(L"ERROR : LA-Level ������ Ȯ���ϼ���!", L"Error!", MB_ICONERROR);		
	}
	else {
		if (m_isLoad != 0)			/* �ҷ��� �����̶��, */
		{						/* �ҷ��� ���� ������ ������ �ʱ�ȭ */
			m_board.InitBoard(m_startCom, m_isLoad, m_levelA);
			//m_isLoad = 0;
		}
		else {
			m_board.InitBoard(m_startCom, 0, m_levelA);
			for (int i = 0; i < 16; i++)
			{
				GetDlgItem(IDC_A23 + i)->EnableWindow(TRUE);
				GetDlgItem(IDC_A39 + i)->EnableWindow(TRUE);
			}
		}
		/* �ƴ϶��, ���ο� ������ �ʱ�ȭ */

		UpdateGame();
		m_board.state = GameBoard::STATE_PLAY;						/* ������ ���¸� �÷��� ������ ���� */
	}
}

void CTicTacToeDlg::TurnAI()
{
	TicTacToeAI* tttAI = new TicTacToeAI(m_board);	/* ���ο� AI ��ü�� ���� */

	tttAI->GetBestMove();							/* ������ ��ǥ�� ���� */
	m_board.DoMove(tttAI->bestX, tttAI->bestY);		/* �ش� ��ǥ�� ���� �� */

	Node* node = tttAI->GetRootNode();			/* ������ ��ǥ�� ���ϴµ��� ������ Ʈ�� �� ��Ʈ��� ��ȯ */
	this->PrintTreeNode(node);					/* Ʈ�� ��� */

	UpdateGame();								/* ������ ������Ʈ */

	delete tttAI;
	delete node;

	m_board.CheckState();			/* ������ ���¸� ���� */
	if (m_board.state != GameBoard::STATE_PLAY)
		EndGame();
}

/**
�� �� : PrintTreeNode(Node* root)
�� �� : AI�� ���ؼ� ������ ��ǥ�� ���ϴµ����� Eval ���� ������ ����� ������
Ʈ���� �ڷᱸ�� ť�� �̿��� �ʺ�켱 Ž������ Edit Box�� ������ִ� �Լ�
*/
void CTicTacToeDlg::PrintTreeNode(Node* root)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int preDepth = 0;			/* ���� ����� ���� */
	bool preParent = false;		/* �θ� ������ ���� ���� */
	Node *pNode = root;			/* ��Ʈ��带 ���� */
	CString temp, temp2;
	queue <Node* > que;			/* ť ���� */

	que.push(pNode);			/* ť�� ��Ʈ��带 �ְ� */
	while (!que.empty())			/* ť�� ������� �� ���� ��� */
	{
		pNode = que.front();	/* �տ��� ������ */
		que.pop();
		if (pNode != NULL)		/* NULL ���� �ƴϰ� */
		{
			if (preDepth != pNode->depth)	/* ���� ��尪�� ���̰� �ٸ��� */
				temp = temp + (L"\r\n");	/* ���� */

			if (preParent)					/* �θ��尡 ������ */
				temp = temp + (L", ");		/* �̾ ��� */
			else
				temp = temp + (L"(");		/* �ٸ��� '(' �� ���� */

			temp2.Format(L"%d", pNode->eval);
			temp = temp + temp2;

			preParent = true;

			if (pNode->childCnt != 0)		/* �ڽĳ�� ������ 0�� �ƴϸ� */
			{
				que.push(NULL);				/* NULL ������ �θ��� ���� ���ְ� */
				for (int j = 0; j < pNode->childCnt; j++)
					que.push(pNode->next[j]);		/* �ڽĳ�带 ť�� ���� */

			}
			preDepth = pNode->depth;				/* ��� ���̸� ���� */
		}
		else							/* ť���� ������ NULL �� �̶�� */
		{
			temp = temp + (L")");		/* ')' �� �θ��带 ���� */
			preParent = false;
		}
	}
	temp = temp + (L")");

	if (m_board.moveCnt % 2 == 0)
	{
		if (m_board.starterCom == 'X')
		{
			GetDlgItem(IDC_EDIT_A)->SetWindowTextW(temp);
		}
		else
		{
			GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"<���� Ʈ��>");
		}
	}
	else
	{
		if (m_board.starterCom == 'X')
		{
			GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"<���� Ʈ��>");
		}
		else
		{
			GetDlgItem(IDC_EDIT_A)->SetWindowTextW(temp);
		}
	}
}

/**
�� �� : ResetGame()
�� �� : �������� �� �ʱ�ȭ ��Ű�� �Լ�
*/
void CTicTacToeDlg::ResetGame()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString tempStr, str;
	int count = 0;

	m_startCom = -1;
	UpdateData(FALSE);

	m_board.state = GameBoard::STATE_INIT;
	m_board.InitBoard(m_startCom, 0, m_levelA);

	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			str.Format(L"%d", count + 1);
			SetDlgItemText(1042 + count, str);
			SetDlgItemText(1058 + count, str);
			count++;
		}
	}

	GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"<���� Ʈ��>");
	m_undoB.EnableWindow(FALSE);
	m_comboA.SetCurSel(-1);
}

/**
�� �� : EndGame()
�� �� : ������ �����Ű�� �ش� ������ ���¿����� Edit Box�� �������
������ִ� �Լ�
*/
void CTicTacToeDlg::EndGame()
{
	switch (m_board.state)
	{
	case GameBoard::STATE_WINA:
		GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"��ǻ�Ͱ� ���ӿ��� �̰���ϴ�.");
		for (int i = 0; i < 16; i++)
		{
			GetDlgItem(IDC_A23 + i)->EnableWindow(FALSE);
			GetDlgItem(IDC_A39 + i)->EnableWindow(FALSE);
		}
		break;

	case GameBoard::STATE_WINB:
		GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"����ڰ� ���ӿ��� �̰���ϴ�.");
		for (int i = 0; i < 16; i++)
		{
			GetDlgItem(IDC_A23 + i)->EnableWindow(FALSE);
			GetDlgItem(IDC_A39 + i)->EnableWindow(FALSE);
		}
		break;

	case GameBoard::STATE_DRAW:
		GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"���ӿ� �����ϴ�.");
		for (int i = 0; i < 16; i++)
		{
			GetDlgItem(IDC_A23 + i)->EnableWindow(FALSE);
			GetDlgItem(IDC_A39 + i)->EnableWindow(FALSE);
		}
		break;

	case GameBoard::STATE_INIT:
		GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"<���� Ʈ��>");
		break;

	case GameBoard::STATE_STOP:
		GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"������ �ߴܵǾ����ϴ�.");
		for (int i = 0; i < 16; i++)
		{
			GetDlgItem(IDC_A23 + i)->EnableWindow(FALSE);
			GetDlgItem(IDC_A39 + i)->EnableWindow(FALSE);
		}
		break;
	}
	m_undoB.EnableWindow(FALSE);
}


/**
�� �� : UpdateGame()
�� �� : �ش� �������� ȭ������ ������Ʈ ���ִ� �Լ�
*/
void CTicTacToeDlg::UpdateGame()
{
	int count = 0;
	int comButton = 0;
	CString str;
	
	if (m_board.moveCnt % 2 == 1)      // ��� ���� Ŭ����
	{
		if (m_board.starterCom == 'X') 
			comButton = IDC_A39;
		else
			comButton = IDC_A23;
	}
	else // ��� AI�� Ŭ����
	{
		if (m_board.starterCom == 'X')
			comButton = IDC_A23;
		else
			comButton = IDC_A39;
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_board.board[i][j] == 'X')
			{
				SetDlgItemText(IDC_A23 + count, L"X");
				SetDlgItemText(IDC_A39 + count, L"X");
				GetDlgItem(IDC_A23 + count)->EnableWindow(FALSE);
				GetDlgItem(IDC_A39 + count)->EnableWindow(FALSE);

			}
			else if (m_board.board[i][j] == 'O')
			{
				SetDlgItemText(IDC_A23 + count, L"O");
				SetDlgItemText(IDC_A39 + count, L"O");
				GetDlgItem(IDC_A23 + count)->EnableWindow(FALSE);
				GetDlgItem(IDC_A39 + count)->EnableWindow(FALSE);
			}
			else
			{
				str.Format(L"%d", count + 1);
				SetDlgItemText(IDC_A23 + count, str);
				SetDlgItemText(IDC_A39 + count, str);
				GetDlgItem(IDC_A23 + count)->EnableWindow(TRUE);
				GetDlgItem(IDC_A39 + count)->EnableWindow(TRUE);
			}
			count++;
		}
	}
	if(m_isLoad >= m_board.moveCnt)
		GetDlgItem(IDC_BUTTON_UNDO_B)->EnableWindow(FALSE);
	else if (m_board.moveCnt>=2)
		GetDlgItem(IDC_BUTTON_UNDO_B)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON_UNDO_B)->EnableWindow(FALSE);
}

/**
�� �� : SaveGame()
�� �� : �ش� ������ ������ txt���Ͽ� ���� ���ִ� �Լ�
*/
void CTicTacToeDlg::SaveGame()
{
	CFileDlg dlg;

	if (m_board.state != GameBoard::STATE_PLAY)	/* �ҷ����� ������ ������������ �˻� */
	{
		MessageBox(L"������ �������ϴ�! ������ ���� �����ϴ�.", L"�� ��", MB_ICONEXCLAMATION);
		return;
	}

	if (dlg.DoModal() == IDOK)
	{
		FILE *fp;						/* ���� ������ ���� */
		CStringA name(dlg.m_fileStr);

		if (!(fp = fopen(name, "w+")))
		{
			MessageBox(L"������ �� �� �����ϴ�! ���ϸ��� Ȯ���ϼ���.", L"ERROR", MB_ICONERROR);
			return;
		}
		else		/* ����� ���� �����̶�� */
		{
			int i, j;
			char temp[5];

			for (i = 0; i<4; i++)
			{
				for (j = 0; j<4; j++)				/* ���ڿ� �°� ���Ͽ� �Է� */
				{
					if (m_board.board[i][j] == 'X')
					{
						temp[j] = 'X';
					}
					else if (m_board.board[i][j] == 'O')
					{
						temp[j] = 'O';
					}
					else
						temp[j] = 'B';
					fprintf(fp, "%c", temp[j], 1);  /* ���ӿ��� �� ĳ���;� ������ */
				}	
				fprintf(fp, "%c", '\n', 1);   /* ���൵ ���� */
			}

			UpdateData(FALSE);
			UpdateGame();
			GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"<���� Ʈ��>");
			fclose(fp);
		}
	}
}

/**
�� �� : LoadGame()
�� �� : ������ �ҷ������� �ش� ������ ������ ȭ�鿡 ������Ʈ ���ִ� �Լ�
*/
void CTicTacToeDlg::LoadGame()
{
	CFileDlg dlg;

	if (m_board.state == GameBoard::STATE_PLAY)	/* �ҷ����� ������ ������������ �˻� */
	{
		MessageBox(L"������ �������Դϴ�! �����ϰ� �õ��ϼ���.", L"�� ��", MB_ICONEXCLAMATION);
		return;
	}

	if (dlg.DoModal() == IDOK)
	{
		FILE *fp;						/* ���� ������ ���� */
		CStringA name(dlg.m_fileStr);

		if (!(fp = fopen(name, "r+")))

		{
			MessageBox(L"������ �� �� �����ϴ�! ���ϸ��� Ȯ���ϼ���.", L"ERROR", MB_ICONERROR);
			return;
		}
		else		/* ����� ���� �����̶�� */
		{
			int i, j, stoneCount = 0;
			int Acnt = 0, Bcnt = 0;
			char temp[6];

			for (i = 0; i < 4; i++)
			{
				fscanf_s(fp, "%s", temp, 6);
				/* �ش����Ͽ��� ������ ������ */
				for (j = 0; j < 4; j++)				/* ���ڿ� �°� �����ǿ� �Է� */
				{
					if (temp[j] == 'X')
					{
						m_board.board[i][j] = 'X';
						Acnt++;
					}
					else if (temp[j] == 'O')
					{
						m_board.board[i][j] = 'O';
						Bcnt++;
					}
					else
						m_board.board[i][j] = ' ';
				}
			}

			if (Acnt > Bcnt)			/* 'X'�� 'O' ���� ������ �� */
				m_startCom = 1;		/* A�� ������ B�� ���� ��ǻ�� */
			else					/* �����ϸ�, A�� ���� ��ǻ�� */
				m_startCom = 0;

			UpdateData(FALSE);
			m_isLoad = Acnt + Bcnt;
			//UpdateGame();
			GetDlgItem(IDC_EDIT_A)->SetWindowTextW(L"<���� Ʈ��>");
			fclose(fp);
		}
	}
}


void CTicTacToeDlg::OnBnClickedA39()
{
	m_board.DoMove(0, 0);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */
	
	if (m_board.state != GameBoard::STATE_PLAY) 
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA40()
{
	m_board.DoMove(0, 1);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA41()
{
	m_board.DoMove(0, 2);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA42()
{
	m_board.DoMove(0, 3);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA43()
{
	m_board.DoMove(1, 0);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA44()
{
	m_board.DoMove(1, 1);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA45()
{
	m_board.DoMove(1, 2);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA46()
{
	m_board.DoMove(1, 3);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA47()
{
	m_board.DoMove(2, 0);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA48()
{
	m_board.DoMove(2, 1);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA49()
{
	m_board.DoMove(2, 2);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA50()
{
	m_board.DoMove(2, 3);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA51()
{
	m_board.DoMove(3, 0);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA52()
{
	m_board.DoMove(3, 1);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA53()
{
	m_board.DoMove(3, 2);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}


void CTicTacToeDlg::OnBnClickedA54()
{
	m_board.DoMove(3, 3);
	UpdateGame();

	m_board.CheckState();			/* ������ ���¸� ���� */

	if (m_board.state != GameBoard::STATE_PLAY)
	{
		EndGame();
	}
	else
	{
		TurnAI();
		UpdateGame();
	}
}

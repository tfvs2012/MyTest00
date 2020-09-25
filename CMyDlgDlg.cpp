
// CMyDlgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CMyDlg.h"
#include "CMyDlgDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCMyDlgDlg 对话框



CCMyDlgDlg::CCMyDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CMYDLG_DIALOG, pParent)
    , m_strBinary01(_T(""))
    , m_strF01(_T(""))
    , m_strHex01(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCMyDlgDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, EDT_BINARY01, m_strBinary01);
    DDX_Text(pDX, EDT_BINARY02, m_strBinary02);
    DDX_Text(pDX, EDT_BINARY03, m_strBinary03);
    DDX_Text(pDX, EDT_BINARY04, m_strBinary04);
    DDX_Text(pDX, EDT_BINARY05, m_strBinary05);

    DDX_Text(pDX, EDT_DEC01, m_strDec01);
    DDX_Text(pDX, EDT_DEC02, m_strDec02);
    DDX_Text(pDX, EDT_DEC03, m_strDec03);
    DDX_Text(pDX, EDT_DEC04, m_strDec04);
    DDX_Text(pDX, EDT_DEC05, m_strDec05);

    DDX_Text(pDX, EDT_F01, m_strF01);
    DDX_Text(pDX, EDT_F02, m_strF02);
    DDX_Text(pDX, EDT_F03, m_strF03);
    DDX_Text(pDX, EDT_F04, m_strF04);
    DDX_Text(pDX, EDT_F05, m_strF05);

    DDX_Text(pDX, EDT_HEX01, m_strHex01);
    DDX_Text(pDX, EDT_HEX02, m_strHex02);
    DDX_Text(pDX, EDT_HEX03, m_strHex03);
    DDX_Text(pDX, EDT_HEX04, m_strHex04);
    DDX_Text(pDX, EDT_HEX05, m_strHex05);
}



BEGIN_MESSAGE_MAP(CCMyDlgDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(BTN_HEX, &CCMyDlgDlg::OnBnClickedHex)
    ON_BN_CLICKED(BTN_DEC, &CCMyDlgDlg::OnBnClickedDec)
    ON_BN_CLICKED(BTN_F, &CCMyDlgDlg::OnBnClickedF)
    ON_BN_CLICKED(BTN_BINARY, &CCMyDlgDlg::OnBnClickedBinary)
END_MESSAGE_MAP()


// CCMyDlgDlg 消息处理程序

BOOL CCMyDlgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCMyDlgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCMyDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCMyDlgDlg::FunHex()
{
    //以16进制为准
    UpdateData(TRUE);
    char *szTemp;
    char szBuff[1024];
    int nTemp = 0;
    memset(szBuff, 0, sizeof(szBuff));

    if (m_strHex01.GetLength() > 0)
    {
        //字符串16进制必须是0/0x开头,返回10进制
        nTemp = strtol((const char*)m_strHex01.GetBuffer(0), &szTemp, 16);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 10);
        m_strDec01 = szBuff;
        //STIF_SUPPORT_HEX 字符串包含一个十六进制值
        StrToIntEx(m_strHex01.GetBuffer(0), STIF_SUPPORT_HEX, &result);//转成16进制
        m_strF01.Format(_T("%f"), f);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 2);
        m_strBinary01 = szBuff;
    }
    if (m_strHex02.GetLength() > 0)
    {
        nTemp = strtol((const char*)m_strHex02.GetBuffer(0), &szTemp, 16);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 10);
        m_strDec02= szBuff;
        //STIF_SUPPORT_HEX 字符串包含一个十六进制值
        StrToIntEx(m_strHex02.GetBuffer(0), STIF_SUPPORT_HEX, &result);//转成16进制
        m_strF02.Format(_T("%f"), f);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 2);
        m_strBinary02 = szBuff;
    }
    if (m_strHex03.GetLength() > 0)
    {
        nTemp = strtol((const char*)m_strHex03.GetBuffer(0), &szTemp, 16);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 10);
        m_strDec03 = szBuff;
        //STIF_SUPPORT_HEX 字符串包含一个十六进制值
        StrToIntEx(m_strHex03.GetBuffer(0), STIF_SUPPORT_HEX, &result);//转成16进制
        m_strF03.Format(_T("%f"), f);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 2);
        m_strBinary03 = szBuff;
    }
    if (m_strHex04.GetLength() > 0)
    {
        nTemp = strtol((const char*)m_strHex04.GetBuffer(0), &szTemp, 16);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 10);
        m_strDec04 = szBuff;
        //STIF_SUPPORT_HEX 字符串包含一个十六进制值
        StrToIntEx(m_strHex04.GetBuffer(0), STIF_SUPPORT_HEX, &result);//转成16进制
        m_strF04.Format(_T("%f"), f);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 2);
        m_strBinary04 = szBuff;
    }
    if (m_strHex05.GetLength() > 0)
    {
        nTemp = strtol((const char*)m_strHex05.GetBuffer(0), &szTemp, 16);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 10);
        m_strDec05 = szBuff;
        //STIF_SUPPORT_HEX 字符串包含一个十六进制值
        StrToIntEx(m_strHex05.GetBuffer(0), STIF_SUPPORT_HEX, &result);//转成16进制
        m_strF05.Format(_T("%f"), f);
        _itoa_s(nTemp, szBuff, sizeof(szBuff), 2);
        m_strBinary05 = szBuff;
    }
    UpdateData(FALSE);
}
void CCMyDlgDlg::FunDec()
{
    UpdateData(TRUE);
    char *szTemp;
    char szBuff[1024];
    int nTemp = 0;
    memset(szBuff, 0, sizeof(szBuff));

    if (m_strDec01.GetLength()>0)
    {
        nTemp = strtol(m_strDec01.GetBuffer(), &szTemp, 10);
        m_strHex01.Format("%08x", nTemp);
    }

    if (m_strDec02.GetLength() > 0)
    {
        nTemp = strtol(m_strDec02.GetBuffer(), &szTemp, 10);
        m_strHex02.Format("%08x", nTemp);
    }

    if (m_strDec03.GetLength() > 0)
    {
        nTemp = strtol(m_strDec03.GetBuffer(), &szTemp, 10);
        m_strHex03.Format("%08x", nTemp);
    }

    if (m_strDec04.GetLength() > 0)
    {
        nTemp = strtol(m_strDec04.GetBuffer(), &szTemp, 10);
        m_strHex04.Format("%08x", nTemp);
    }

    if (m_strDec05.GetLength() > 0)
    {
        nTemp = strtol(m_strDec05.GetBuffer(), &szTemp, 10);
        m_strHex05.Format("%08x", nTemp);
    }
    UpdateData(FALSE);



    FunHex();
}

void CCMyDlgDlg::FunFloat()
{
    UpdateData(TRUE);
    char szBuff[1024];
    FloatNumber fTemp;
    std::cout.precision(7);
    fTemp.f = (float)atof(m_strF01.GetBuffer());

    _itoa_s(fTemp.s, szBuff, 2);
    m_strBinary01 += szBuff;
    _itoa_s(fTemp.e, szBuff, 2);
    m_strBinary01.Insert(m_strBinary01.GetLength(), szBuff);
    _itoa_s(fTemp.d, szBuff, 2);
    m_strBinary01.Insert(m_strBinary01.GetLength(), szBuff);

    UpdateData(FALSE);
}

void CCMyDlgDlg::FunBinary()
{
    //二进制转10进制
    UpdateData(TRUE);
    int nTemp = 0;
    int nCount = 0;
    if (m_strBinary01.GetLength()>0)
    {
        nTemp = 0;
        nCount = m_strBinary01.GetLength();
        for (int i = 0; i < nCount; i++)
        {
            int j = ((m_strBinary01[nCount - i - 1] == '1' ? 1 : 0))* (int)pow(2, (i));
            nTemp += j;
        }
        m_strDec01.Format("%d", nTemp);
    }
    if (m_strBinary02.GetLength() > 0)
    {
        nTemp = 0;
        nCount = m_strBinary02.GetLength();
        for (int i = 0; i < nCount; i++)
        {
            int j = ((m_strBinary02[nCount - i - 1] == '1' ? 1 : 0))* (int)pow(2, (i));
            nTemp += j;
        }
        m_strDec02.Format("%d", nTemp);
    }
    if (m_strBinary03.GetLength() > 0)
    {
        nTemp = 0;
        nCount = m_strBinary03.GetLength();
        for (int i = 0; i < nCount; i++)
        {
            int j = ((m_strBinary03[nCount - i - 1] == '1' ? 1 : 0))* (int)pow(2, (i));
            nTemp += j;
        }
        m_strDec03.Format("%d", nTemp);
    }
    if (m_strBinary04.GetLength() > 0)
    {
        nTemp = 0;
        nCount = m_strBinary04.GetLength();
        for (int i = 0; i < nCount; i++)
        {
            int j = ((m_strBinary04[nCount - i - 1] == '1' ? 1 : 0))* (int)pow(2, (i));
            nTemp += j;
        }
        m_strDec04.Format("%d", nTemp);
    }
    if (m_strBinary05.GetLength() > 0)
    {
        nTemp = 0;
        nCount = m_strBinary05.GetLength();
        for (int i = 0; i < nCount; i++)
        {
            int j = ((m_strBinary05[nCount - i - 1] == '1' ? 1 : 0))* (int)pow(2, (i));
            nTemp += j;
        }
        m_strDec05.Format("%d", nTemp);
    }
    UpdateData(FALSE);
    FunDec();
}

void CCMyDlgDlg::OnBnClickedHex()
{
    // TODO: 在此添加控件通知处理程序代码
    FunHex();
}


void CCMyDlgDlg::OnBnClickedDec()
{
    // TODO: 在此添加控件通知处理程序代码
    FunDec();
}


void CCMyDlgDlg::OnBnClickedF()
{
    // TODO: 在此添加控件通知处理程序代码
    FunFloat();
}


void CCMyDlgDlg::OnBnClickedBinary()
{
    // TODO: 在此添加控件通知处理程序代码
    FunBinary();
}


void CCMyDlgDlg::OnOK()
{
    // TODO: 在此添加专用代码和/或调用基类

    //CDialogEx::OnOK();
}


// CMyDlgDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCMyDlgDlg �Ի���
class CCMyDlgDlg : public CDialogEx
{
    typedef union FloatNumber
    {
        float f;
        struct
        {
            unsigned d : 23;
            unsigned e : 8;
            unsigned s : 1;
        };
    }FloatNumber;

    union { int result;  float f; };
// ����
public:
	CCMyDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CMYDLG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
    void FunHex();
    void FunDec();
    void FunFloat();
    void FunBinary();

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    CString m_strBinary01;
    CString m_strBinary02;
    CString m_strBinary03;
    CString m_strBinary04;
    CString m_strBinary05;
    CString m_strDec01;
    CString m_strDec02;
    CString m_strDec03;
    CString m_strDec04;
    CString m_strDec05;
    CString m_strF01;
    CString m_strF02;
    CString m_strF03;
    CString m_strF04;
    CString m_strF05;
    CString m_strHex01;
    CString m_strHex02;
    CString m_strHex03;
    CString m_strHex04;
    CString m_strHex05;

    afx_msg void OnBnClickedHex();
    afx_msg void OnBnClickedDec();
    afx_msg void OnBnClickedF();
    afx_msg void OnBnClickedBinary();
    virtual void OnOK();
};

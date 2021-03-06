﻿// CSplashThread.cpp: 实现文件
//

#include "pch.h"
#include "irms.h"
#include "CSplashThread.h"

// CSplashThread

IMPLEMENT_DYNCREATE(CSplashThread, CWinThread)

CSplashThread::CSplashThread()
{
}

CSplashThread::~CSplashThread()
{
}


BOOL CSplashThread::InitInstance()
{
	// TODO:    在此执行任意逐线程初始化
    ::AttachThreadInput(m_nThreadID, AfxGetApp()->m_nThreadID, TRUE);

    //:通常系统内的每个线程都有自己的输入队列。本函数允许线程和进程共享输入队列。连接了线程后，输入焦点、窗口激活、鼠标捕获、键盘状态以及输入队列状态都会进入共享状态 . (这个函数可以不用)
    m_pSplashDlg = new CSplashDlg;
    //m_pSplashDlg->SetEnable(true);
    m_pSplashDlg->Create(IDD_SPLASH);
    m_pSplashDlg->ShowWindow(SW_SHOW);

	//CWinThread* MyThread = AfxBeginThread(MyThreadFunction, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	//DWORD exitcode2;
	//GetExitCodeThread(MyThread, &exitcode2);
	//ExitThread(exitcode2);

 //   CString str1 = _T("cmd /c jre1.8.0_131\\bin\\java -version");
 //   CString temp = ExecuteCmd2(str1, NULL);
	//::SendMessage(m_pSplashDlg->m_hWnd, WM_USERMESSAGE, 0, (LPARAM)&temp);
	return TRUE;
}

// 退出时释放资源
int CSplashThread::ExitInstance()
{
	// TODO:    在此执行任意逐线程清理
    m_pSplashDlg->DestroyWindow();
    delete m_pSplashDlg;
    return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CSplashThread, CWinThread)
END_MESSAGE_MAP()


// CSplashThread 消息处理程序

//隐藏窗口
void CSplashThread::HideSplash()
{
    m_pSplashDlg->SendMessage(WM_CLOSE);
}

void CSplashThread::log(CString str)
{
	::SendMessage(m_pSplashDlg->m_hWnd, WM_USERMESSAGE, 0, (LPARAM)&str);
}
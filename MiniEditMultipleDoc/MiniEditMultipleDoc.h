
// MiniEditMultipleDoc.h: основной файл заголовка для приложения MiniEditMultipleDoc
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMiniEditMultipleDocApp:
// Сведения о реализации этого класса: MiniEditMultipleDoc.cpp
//

class CMiniEditMultipleDocApp : public CWinApp
{
public:
	CMiniEditMultipleDocApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMiniEditMultipleDocApp theApp;

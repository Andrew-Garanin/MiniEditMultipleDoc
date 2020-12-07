
// MiniEditMultipleDocView.cpp: реализация класса CMiniEditMultipleDocView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MiniEditMultipleDoc.h"
#endif

#include "MiniEditMultipleDocDoc.h"
#include "MiniEditMultipleDocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMiniEditMultipleDocView

IMPLEMENT_DYNCREATE(CMiniEditMultipleDocView, CEditView)

BEGIN_MESSAGE_MAP(CMiniEditMultipleDocView, CEditView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CMiniEditMultipleDocView

CMiniEditMultipleDocView::CMiniEditMultipleDocView() noexcept
{
	// TODO: добавьте код создания

}

CMiniEditMultipleDocView::~CMiniEditMultipleDocView()
{
}

BOOL CMiniEditMultipleDocView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Разрешить перенос слов

	return bPreCreated;
}


// Печать CMiniEditMultipleDocView

BOOL CMiniEditMultipleDocView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка CEditView по умолчанию
	return CEditView::OnPreparePrinting(pInfo);
}

void CMiniEditMultipleDocView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Начало печати CEditView по умолчанию
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMiniEditMultipleDocView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Завершение печати CEditView по умолчанию
	CEditView::OnEndPrinting(pDC, pInfo);
}


// Диагностика CMiniEditMultipleDocView

#ifdef _DEBUG
void CMiniEditMultipleDocView::AssertValid() const
{
	CEditView::AssertValid();
}

void CMiniEditMultipleDocView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMiniEditMultipleDocDoc* CMiniEditMultipleDocView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMiniEditMultipleDocDoc)));
	return (CMiniEditMultipleDocDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMiniEditMultipleDocView

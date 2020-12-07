
// MiniEditMultipleDocView.h: интерфейс класса CMiniEditMultipleDocView
//

#pragma once


class CMiniEditMultipleDocView : public CEditView
{
protected: // создать только из сериализации
	CMiniEditMultipleDocView() noexcept;
	DECLARE_DYNCREATE(CMiniEditMultipleDocView)

// Атрибуты
public:
	CMiniEditMultipleDocDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMiniEditMultipleDocView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в MiniEditMultipleDocView.cpp
inline CMiniEditMultipleDocDoc* CMiniEditMultipleDocView::GetDocument() const
   { return reinterpret_cast<CMiniEditMultipleDocDoc*>(m_pDocument); }
#endif


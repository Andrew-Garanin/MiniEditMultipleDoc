
// MiniEditMultipleDocDoc.cpp: реализация класса CMiniEditMultipleDocDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MiniEditMultipleDoc.h"
#endif

#include "MiniEditMultipleDocDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMiniEditMultipleDocDoc

IMPLEMENT_DYNCREATE(CMiniEditMultipleDocDoc, CDocument)

BEGIN_MESSAGE_MAP(CMiniEditMultipleDocDoc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CMiniEditMultipleDocDoc

CMiniEditMultipleDocDoc::CMiniEditMultipleDocDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CMiniEditMultipleDocDoc::~CMiniEditMultipleDocDoc()
{
}

BOOL CMiniEditMultipleDocDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CMiniEditMultipleDocDoc

void CMiniEditMultipleDocDoc::Serialize(CArchive& ar)
{
	// CEditView содержит элемент управления редактированием, который управляет сериализацией
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
	}
#ifdef SHARED_HANDLERS

	if (m_viewList.IsEmpty() && ar.IsLoading())
	{
		CFile* pFile = ar.GetFile();
		pFile->Seek(0, FILE_BEGIN);
		ULONGLONG nFileSizeBytes = pFile->GetLength();
		ULONGLONG nFileSizeChars = nFileSizeBytes/sizeof(TCHAR);
		LPTSTR lpszText = (LPTSTR)malloc(((size_t)nFileSizeChars + 1) * sizeof(TCHAR));
		if (lpszText != nullptr)
		{
			ar.Read(lpszText, (UINT)nFileSizeBytes);
			lpszText[nFileSizeChars] = '\0';
			m_strThumbnailContent = lpszText;
			m_strSearchContent = lpszText;
		}
	}
#endif
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMiniEditMultipleDocDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(m_strThumbnailContent, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CMiniEditMultipleDocDoc::InitializeSearchContent()
{
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Использовать все содержимое текстового файла в качестве контента поиска.
	SetSearchContent(m_strSearchContent);
}

void CMiniEditMultipleDocDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CMiniEditMultipleDocDoc

#ifdef _DEBUG
void CMiniEditMultipleDocDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMiniEditMultipleDocDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CMiniEditMultipleDocDoc

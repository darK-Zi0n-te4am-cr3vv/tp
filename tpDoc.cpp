
// tpDoc.cpp : implementation of the CtpDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "tp.h"
#endif

#include "tpDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CtpDoc

IMPLEMENT_DYNCREATE(CtpDoc, CDocument)

BEGIN_MESSAGE_MAP(CtpDoc, CDocument)
END_MESSAGE_MAP()


// CtpDoc construction/destruction

CtpDoc::CtpDoc()
{
	// TODO: add one-time construction code here

}

CtpDoc::~CtpDoc()
{
}

BOOL CtpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

BOOL CtpDoc::OnOpenDocument(LPCTSTR lPathName)
{
	if (FAILED(m_Image.Load(lPathName)))
		return FALSE;

	return TRUE;
}

BOOL CtpDoc::OnSaveDocument(LPCTSTR lPathName)
{
	if (FAILED(m_Image.Save(lPathName)))
		return FALSE;

	return TRUE;
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CtpDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CtpDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CtpDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CtpDoc diagnostics

#ifdef _DEBUG
void CtpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtpDoc commands

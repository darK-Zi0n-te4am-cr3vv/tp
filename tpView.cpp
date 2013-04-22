
// tpView.cpp : implementation of the CtpView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "tp.h"
#endif

#include "tpDoc.h"
#include "tpView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtpView

IMPLEMENT_DYNCREATE(CtpView, CScrollView)

BEGIN_MESSAGE_MAP(CtpView, CScrollView)
END_MESSAGE_MAP()

// CtpView construction/destruction

CtpView::CtpView()
	: m_FullScreen(FALSE)
{
	m_ContextMenu.LoadMenu(IDR_VIEW_MENU);
}

CtpView::~CtpView()
{
}

BOOL CtpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

void CtpView::OnInitialUpdate()
{
	CtpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CSize size(pDoc->GetImage().GetWidth(), pDoc->GetImage().GetHeight());
	SetScrollSizes(MM_TEXT, size);
}

// CtpView drawing

void CtpView::OnDraw(CDC* pDC)
{
	CtpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	const CImage & image = pDoc->GetImage();
	image.Draw(*pDC, 0, 0);
}

BOOL CtpView::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	if (message == WM_CONTEXTMENU)
	{
		int xPos = GET_X_LPARAM(lParam);
		int yPos = GET_Y_LPARAM(lParam);

		int nCmd = TrackPopupMenu(*m_ContextMenu.GetSubMenu(0),
			                      TPM_LEFTALIGN | TPM_RETURNCMD,
					              xPos, yPos, 0, m_hWnd, NULL);

		if (nCmd == ID_CTXMENU_FULLSCREEN)
		{
			ToggleFullscreen();
		}
	}
	else
	{
		return CScrollView::OnWndMsg(message, wParam, lParam, pResult);
	}
}

void CtpView::ToggleFullscreen()
{
	if (!m_FullScreen)
	{
		m_FullScreen = TRUE;
		m_SavedParent = GetParent();

		SetParent(GetDesktopWindow());

        CRect rect;
        GetDesktopWindow()->GetWindowRect(&rect);

        SetWindowPos(&wndTopMost,rect.left,rect.top,
                     rect.right,rect.bottom,SWP_SHOWWINDOW);
    }
    else
	{
		m_FullScreen = FALSE;

        this->SetParent(m_SavedParent);

        ((CMainFrame *)AfxGetMainWnd())->RecalcLayout();
    }
}

// CtpView diagnostics

#ifdef _DEBUG
void CtpView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CtpView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CtpDoc* CtpView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtpDoc)));
	return (CtpDoc*)m_pDocument;
}
#endif //_DEBUG


// CtpView message handlers

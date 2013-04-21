
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtpView

IMPLEMENT_DYNCREATE(CtpView, CView)

BEGIN_MESSAGE_MAP(CtpView, CView)
END_MESSAGE_MAP()

// CtpView construction/destruction

CtpView::CtpView()
{
	// TODO: add construction code here

}

CtpView::~CtpView()
{
}

BOOL CtpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
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


// CtpView diagnostics

#ifdef _DEBUG
void CtpView::AssertValid() const
{
	CView::AssertValid();
}

void CtpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtpDoc* CtpView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtpDoc)));
	return (CtpDoc*)m_pDocument;
}
#endif //_DEBUG


// CtpView message handlers

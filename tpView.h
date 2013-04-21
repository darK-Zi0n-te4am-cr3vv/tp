
// tpView.h : interface of the CtpView class
//

#pragma once


class CtpView : public CView
{
protected: // create from serialization only
	CtpView();
	DECLARE_DYNCREATE(CtpView)

// Attributes
public:
	CtpDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CtpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in tpView.cpp
inline CtpDoc* CtpView::GetDocument() const
   { return reinterpret_cast<CtpDoc*>(m_pDocument); }
#endif



// DIPDoc.cpp: CDIPDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DIP.h"
#endif

#include "DIPDoc.h"
#include "INP.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI (3.1415926)
// CDIPDoc

IMPLEMENT_DYNCREATE(CDIPDoc, CDocument)

BEGIN_MESSAGE_MAP(CDIPDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CDIPDoc::OnFileOpen)
	ON_COMMAND(ID_RED, &CDIPDoc::OnRed)
	ON_COMMAND(ID_GREEN, &CDIPDoc::OnGreen)
	ON_COMMAND(ID_BLUE, &CDIPDoc::OnBlue)
	ON_COMMAND(ID_GRAY1, &CDIPDoc::OnGray1)
	ON_COMMAND(ID_GrayHistogram, &CDIPDoc::OnGrayhistogram)
	ON_COMMAND(ID_Histogramequalization, &CDIPDoc::OnHistogramequalization)
	ON_COMMAND(ID_ImageFastFourierTransform, &CDIPDoc::OnImagefastfouriertransform)
	ON_COMMAND(ID_ImageFastFourierTransformCenter, &CDIPDoc::OnImagefastfouriertransformcenter)
	ON_COMMAND(ID_FILE_SAVE, &CDIPDoc::OnFileSave)
	ON_COMMAND(ID_Add, &CDIPDoc::OnAdd)
	ON_COMMAND(ID_Subtract, &CDIPDoc::OnSubtract)
	ON_COMMAND(ID_Multiply, &CDIPDoc::OnMultiply)
	ON_COMMAND(ID_Divide, &CDIPDoc::OnDivide)
	ON_COMMAND(ID_And, &CDIPDoc::OnAnd)
	ON_COMMAND(ID_Or, &CDIPDoc::OnOr)
	ON_COMMAND(ID_AddNoise, &CDIPDoc::OnAddnoise)
END_MESSAGE_MAP()


// CDIPDoc 构造/析构

CDIPDoc::CDIPDoc()
	: m_iBit(0)
{
	// TODO: 在此添加一次性构造代码
	bFileIsOpen = false;
	m_iByte = 0;
}

CDIPDoc::~CDIPDoc()
{
}

BOOL CDIPDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CDIPDoc 序列化

void CDIPDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CDIPDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CDIPDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CDIPDoc::SetSearchContent(const CString& value)
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

// CDIPDoc 诊断

#ifdef _DEBUG
void CDIPDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDIPDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDIPDoc 命令


void CDIPDoc::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CString strFilter;
	CSimpleArray<GUID>  aguidFileTypes;
	HRESULT hResult;

	// 获取CImage支持的图像文件的过滤字符串
	hResult = m_sImage.GetExporterFilterString(strFilter, aguidFileTypes, _T("All Image Files"));
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("GetExporterFilter函数失败!"));
		return;
	}

	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if (IDOK != dlg.DoModal())
		return;

	m_sImage.Destroy();
	m_rImage.Destroy();

	// 将外部图像文件装载到CImage对象中
	hResult = m_sImage.Load(dlg.GetPathName());
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("图像文件加载失败！"));
		return;
	}

	m_iBit = m_sImage.GetBPP();
	CString strBit;
	strBit.Format(_T("%d位"), m_iBit);
	switch (m_iBit) {
	case 2:m_iByte = 2; break;
	case 4:m_iByte = 16; break;
	case 8:m_iByte = 256; break;
	case 24:m_iByte = 256; break;
	}

	bFileIsOpen = true;
	// 设置主窗口标题栏内容
	CString str;
	str.LoadString(AFX_IDS_APP_TITLE);
	AfxGetMainWnd()->SetWindowText(str + " - " + dlg.GetFileName() + " - " + strBit);
	InvalidateRect(NULL, NULL, FALSE);
}


void CDIPDoc::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	if (m_rImage.IsNull()) {
		AfxMessageBox(_T("你还没有生成一个要保存的图像文件！"));
		return;
	}
	CString strFilter;
	strFilter = "位图文件|*.bmp|JPEG 图像文件|*.jpg|GIF 图像文件|*.gif|PNG 图像文件|*.png||";
	CFileDialog dlg(FALSE, NULL, NULL, NULL, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// 如果用户没有指定文件扩展名，则为其添加一个
	CString strFileName = dlg.GetPathName();
	CString strExtension = dlg.GetFileExt();
	if (strExtension.IsEmpty())
	{
		switch (dlg.m_ofn.nFilterIndex)
		{
		case 1:
			strExtension = "bmp"; break;
		case 2:
			strExtension = "jpg"; break;
		case 3:
			strExtension = "gif"; break;
		case 4:
			strExtension = "png"; break;
		default:
			break;
		}
		strFileName = strFileName + _T(".") + strExtension;
	}
	// 图像保存
	HRESULT hResult = m_rImage.Save(strFileName);
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("保存图像文件失败！"));
	}
}


void CDIPDoc::OnRed()
{
	// TODO: 在此添加命令处理程序代码
	if (m_sImage.IsNull())
	{
		AfxMessageBox(_T("请打开要处理的图像！"));
		return;
	}

	int x;
	int y;
	int nRows = m_sImage.GetHeight();
	int nCols = m_sImage.GetWidth();

	BYTE  nGrey;
	m_rImage.Destroy();

	if (!m_rImage.Create(nCols, nRows, m_iBit))
		return;
	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();
	int nRowBytes = m_sImage.GetPitch();

	for (y = 0; y < nRows; y++)
		for (x = 0; x < nCols; x++)
		{
			nGrey = *(sImageData + y * nRowBytes + x * 3 + 2);
			rImageData[y * nRowBytes + x * 3] = nGrey;
			rImageData[y * nRowBytes + x * 3 + 1] = nGrey;
			rImageData[y * nRowBytes + x * 3 + 2] = nGrey;
		}

	UpdateAllViews(NULL);

}


void CDIPDoc::OnGreen()
{
	// TODO: 在此添加命令处理程序代码
	if (m_sImage.IsNull())
	{
		AfxMessageBox(_T("请打开要处理的图像！"));
		return;
	}

	int x;
	int y;
	int nRows = m_sImage.GetHeight();
	int nCols = m_sImage.GetWidth();

	BYTE  nGrey;
	m_rImage.Destroy();

	if (!m_rImage.Create(nCols, nRows, m_iBit))
		return;
	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();
	int nRowBytes = m_sImage.GetPitch();

	for (y = 0; y < nRows; y++)
		for (x = 0; x < nCols; x++)
		{
			nGrey = *(sImageData + y * nRowBytes + x * 3 + 1);
			rImageData[y * nRowBytes + x * 3] = nGrey;
			rImageData[y * nRowBytes + x * 3 + 1] = nGrey;
			rImageData[y * nRowBytes + x * 3 + 2] = nGrey;
		}

	UpdateAllViews(NULL);
}


void CDIPDoc::OnBlue()
{
	// TODO: 在此添加命令处理程序代码
	if (m_sImage.IsNull())
	{
		AfxMessageBox(_T("请打开要处理的图像！"));
		return;
	}

	int x;
	int y;
	int nRows = m_sImage.GetHeight();
	int nCols = m_sImage.GetWidth();

	BYTE  nGrey;
	m_rImage.Destroy();

	if (!m_rImage.Create(nCols, nRows, m_iBit))
		return;
	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();
	int nRowBytes = m_sImage.GetPitch();

	for (y = 0; y < nRows; y++)
		for (x = 0; x < nCols; x++)
		{
			nGrey = *(sImageData + y * nRowBytes + x * 3 + 0);
			rImageData[y * nRowBytes + x * 3] = nGrey;
			rImageData[y * nRowBytes + x * 3 + 1] = nGrey;
			rImageData[y * nRowBytes + x * 3 + 2] = nGrey;
		}

	UpdateAllViews(NULL);
}


void CDIPDoc::OnGray1()
{
	// TODO: 在此添加命令处理程序代码
	if (m_sImage.IsNull())
	{
		AfxMessageBox(_T("请打开要处理的图像！"));
		return;
	}

	int x;
	int y;
	int nRows = m_sImage.GetHeight();
	int nCols = m_sImage.GetWidth();

	BYTE  nGrey, nR, nG, nB;
	m_rImage.Destroy();

	if (!m_rImage.Create(nCols, nRows, m_iBit))
		return;
	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();
	int nRowBytes = m_sImage.GetPitch();

	for (y = 0; y < nRows; y++)
		for (x = 0; x < nCols; x++)
		{
			nR = *(sImageData + y * nRowBytes + x * 3 + 2);
			nG = *(sImageData + y * nRowBytes + x * 3 + 1);
			nB = *(sImageData + y * nRowBytes + x * 3 + 0);
			nGrey = (BYTE)(0.299*nR + 0.587*nG + 0.114*nB);
			rImageData[y * nRowBytes + x * 3] = nGrey;
			rImageData[y * nRowBytes + x * 3 + 1] = nGrey;
			rImageData[y * nRowBytes + x * 3 + 2] = nGrey;
		}

	UpdateAllViews(NULL);
}


void CDIPDoc::OnGrayhistogram()
{
	// TODO: 在此添加命令处理程序代码
	if (m_sImage.IsNull())
	{
		AfxMessageBox(_T("请打开要处理的图像！"));
		return;
	}

	int x;
	int y;
	int nRows = m_sImage.GetHeight();
	int nCols = m_sImage.GetWidth();

	int nRed, nGreen, nBlue;
	int nGrey;

	m_rImage.Destroy();

	if (!m_rImage.Create(256, nRows, 24))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();
	int nRowBytes = m_sImage.GetPitch();
	int nLineBytes = m_rImage.GetPitch();
	double  mmax, mmin;
	double hist[256];

	for (x = 0; x < 256; x++)
		hist[x] = 0.0f;

	for (y = 0; y < nRows; y++)
		for (x = 0; x < nCols; x++)
		{
			nBlue = sImageData[y * nRowBytes + x * 3 + 0];
			nGreen = sImageData[y * nRowBytes + x * 3 + 1];
			nRed = sImageData[y * nRowBytes + x * 3 + 2];
			nGrey = (int)(0.299*nRed + 0.587*nGreen + 0.114*nBlue);
			hist[nGrey] = hist[nGrey] + 1;
		}

	mmax = mmin = hist[0];
	for (x = 0; x < 256; x++)
	{
		if (mmax < hist[x])  mmax = hist[x];
		else if (mmin > hist[x])  mmin = hist[x];
	}

	for (x = 0; x < 256; x++)
	{
		hist[x] = nRows * (hist[x] - mmin) / (mmax - mmin);
	}

	for (x = 0; x < 256; x++)
	{
		for (y = 0; y < nRows; y++)
		{
			nGrey = (y >(int)(nRows - hist[x])) ? 0 : 255;
			rImageData[y * nLineBytes + x * 3 + 2] = nGrey;
			rImageData[y * nLineBytes + x * 3 + 1] = nGrey;
			rImageData[y * nLineBytes + x * 3 + 0] = nGrey;
			if (y == nRows - 1)
			{
				rImageData[y * nLineBytes + x * 3 + 2] = 0;
				rImageData[y * nLineBytes + x * 3 + 1] = 0;
				rImageData[y * nLineBytes + x * 3 + 0] = 255;
			}
		}
	}

	UpdateAllViews(NULL);
}


void HistogramEqualization(int* pSourceData, int nRows, int nCols)
{
	double *mR;
	double *mS;
	int x;
	int y;

	mR = new double[256];
	mS = new double[256];
	for (x = 0; x<256; x++)
	{
		mR[x] = mS[x] = 0.0;
	}
	//统计直方图
	for (y = 0; y < nRows; y++)
		for (x = 0; x < nCols; x++)
		{
			mR[pSourceData[y*nCols + x]] ++;
		}

	for (x = 0; x<256; x++)
	{
		mR[x] /= (nRows*nCols*1.0);
		if (x == 0) {
			mS[x] = mR[x];
		}
		else {
			mS[x] = mR[x] + mS[x - 1];
		}
	}

	//直方图变换

	for (y = 0; y < nRows; y++)
		for (x = 0; x < nCols; x++)
		{
			pSourceData[y*nCols + x] = (int)(255 * mS[pSourceData[y*nCols + x]]);
		}
}


void CDIPDoc::OnHistogramequalization()
{
	// TODO: 在此添加命令处理程序代码
	if (m_sImage.IsNull())
	{
		AfxMessageBox(_T("请打开要处理的图像！"));
		return;
	}

	int x;
	int y;
	int nRows = m_sImage.GetHeight();
	int nCols = m_sImage.GetWidth();

	int mY, mCb, mCr;
	int nRed, nGreen, nBlue;
	m_rImage.Destroy();

	if (!m_rImage.Create(nCols, nRows, 24))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();
	int nRowBytes = m_sImage.GetPitch();

	bool  bColorPorcessing;
	if (AfxMessageBox(L"处理彩色图像？", MB_YESNO) == IDYES)
		bColorPorcessing = true;
	else
		bColorPorcessing = false;

	int *pY = new int[nRows*nCols];

	if (bColorPorcessing)
	{
		int *pCb = new int[nRows*nCols];
		int *pCr = new int[nRows*nCols];

		for (y = 0; y < nRows; y++)
			for (x = 0; x < nCols; x++)
			{
				nBlue = sImageData[y * nRowBytes + x * 3 + 0];
				nGreen = sImageData[y * nRowBytes + x * 3 + 1];
				nRed = sImageData[y * nRowBytes + x * 3 + 2];
				mY = (int)(0.257*nRed + 0.564*nGreen + 0.098*nBlue) + 16;
				mCb = 128 + (int)(-0.148*nRed - 0.291*nGreen + 0.439*nBlue);
				mCr = 128 + (int)(0.439*nRed - 0.368*nGreen - 0.071*nBlue);
				if (mY < 0)  mY = 0;
				else if (mY > 255)	mY = 255;
				if (mCb < 0)  mCb = 0;
				else if (mCb > 255)  mCb = 255;
				if (mCr < 0)   mCr = 0;
				else if (mCr > 255) mCr = 255;
				pY[y*nCols + x] = (BYTE)mY;
				pCb[y*nCols + x] = (BYTE)mCb;
				pCr[y*nCols + x] = (BYTE)mCr;
			}
		//直方图均衡化
		HistogramEqualization(pY, nRows, nCols);
		for (y = 0; y < nRows; y++)
			for (x = 0; x < nCols; x++)
			{
				nRed = (int)(1.164*pY[y*nCols + x] + 1.596 * pCr[y*nCols + x] - 222.912);
				nGreen = (int)(1.164*pY[y*nCols + x] - 0.391 * pCb[y*nCols + x] - 0.813 * pCr[y*nCols + x] + 135.488);
				nBlue = (int)(1.164*pY[y*nCols + x] + 2.018 * pCb[y*nCols + x] - 276.928);

				if (nRed < 0) nRed = 0;
				else if (nRed > 255) nRed = 255;
				if (nGreen < 0) nGreen = 0;
				else if (nGreen > 255) nGreen = 255;
				if (nBlue < 0) nBlue = 0;
				else if (nBlue > 255) nBlue = 255;

				rImageData[y * nRowBytes + x * 3 + 2] = (BYTE)(nRed);
				rImageData[y * nRowBytes + x * 3 + 1] = (BYTE)(nGreen);
				rImageData[y * nRowBytes + x * 3 + 0] = (BYTE)(nBlue);
			}
		delete pCb;
		delete pCr;
	}
	else
	{
		for (y = 0; y < nRows; y++)
			for (x = 0; x < nCols; x++)
			{
				nBlue = sImageData[y * nRowBytes + x * 3 + 0];
				nGreen = sImageData[y * nRowBytes + x * 3 + 1];
				nRed = sImageData[y * nRowBytes + x * 3 + 2];
				pY[y*nCols + x] = (int)(0.299*nRed + 0.587*nGreen + 0.114*nBlue);
			}

		//直方图均衡化
		HistogramEqualization(pY, nRows, nCols);

		for (y = 0; y < nRows; y++)
			for (x = 0; x < nCols; x++)
			{
				rImageData[y * nRowBytes + x * 3 + 2] = (BYTE)(pY[y*nCols + x]);
				rImageData[y * nRowBytes + x * 3 + 1] = (BYTE)(pY[y*nCols + x]);
				rImageData[y * nRowBytes + x * 3 + 0] = (BYTE)(pY[y*nCols + x]);
			}
	}

	delete[] pY;
	UpdateAllViews(NULL);

}

void FFT1DandIFFT1D(float * Tr, float * Ti, int N, bool bFFTorIFFT)
{
	int r;   //迭代次数
	int l, j, k;//循环变量

	int p;  //用于蝶形计算加权系数的指数
	int B;  //对偶结点距离

	float  X, Y, XX, YY;
	float  w;
	float  cosw, sinw;

	if (!bFFTorIFFT)
	{ //如果做傅立叶你变换，则必须对数列除以N
		for (l = 0; l < N; l++)
		{
			Tr[l] /= N;
			Ti[l] /= N;
		}
	}

	//计算循环次数r
	r = 0;	l = N;
	while (l /= 2)  r++;

	//倒序
	int  LH = N / 2;
	int i;
	float temp;
	j = 0;
	for (i = 1; i < N - 1; i++)
	{
		k = LH;
		while (j >= k)
		{
			j = j - k;
			k = k / 2;
		}
		j = j + k;
		if (i <= j)
		{
			temp = Tr[i]; Tr[i] = Tr[j]; Tr[j] = temp;
			temp = Ti[i]; Ti[i] = Ti[j]; Ti[j] = temp;
		}
	}


	for (l = 0; l <= r; l++)  //共r级
	{
		B = 1 << (l - 1); // 第l层对偶结点距离为2^(l-1)
		for (j = 0; j < B; j++)
		{
			p = j*(1 << (r - l));
			w = (float)(2 * PI*p / N);
			for (k = j; k < N - 1; k += (1 << l))
			{
				if (bFFTorIFFT)
				{  //若做傅立叶正变换
					cosw = cos(-w);
					sinw = sin(-w);
				}
				else
				{  //傅立叶反变换
					cosw = cos(w);
					sinw = sin(w);
				}


				X = Tr[k] + Tr[k + B] * cosw - Ti[k + B] * sinw;
				Y = Ti[k] + Tr[k + B] * sinw + Ti[k + B] * cosw;

				XX = Tr[k] - Tr[k + B] * cosw + Ti[k + B] * sinw;
				YY = Ti[k] - Tr[k + B] * sinw - Ti[k + B] * cosw;

				Tr[k] = X;
				Ti[k] = Y;

				Tr[k + B] = XX;
				Ti[k + B] = YY;
			}
		}
	}
}

void FFT2DandIFFT2D(float * inDataReal, float * inDataImage, float * outDataReal, float * outDataImage, int M, int N, bool bFFTorIFFT)
{
	int i, j;

	float *Tr;
	float *Ti;

	Tr = new float[N];
	Ti = new float[N];

	//每行进行傅立叶变换
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			Tr[j] = inDataReal[i*N + j];
			Ti[j] = inDataImage[i*N + j];
		}

		FFT1DandIFFT1D(Tr, Ti, N, bFFTorIFFT);

		for (j = 0; j < M; j++)
		{
			outDataReal[i*N + j] = Tr[j];
			outDataImage[i*N + j] = Ti[j];
		}
	}

	delete Tr;
	delete Ti;

	Tr = new float[M];
	Ti = new float[M];


	//每列进行傅立叶变换		
	for (j = 0; j < N; j++)
	{
		for (i = 0; i < M; i++)
		{
			Tr[i] = outDataReal[i*N + j];
			Ti[i] = outDataImage[i*N + j];
		}

		FFT1DandIFFT1D(Tr, Ti, M, bFFTorIFFT);

		for (i = 0; i < M; i++)
		{
			outDataReal[i*N + j] = Tr[i];
			outDataImage[i*N + j] = Ti[i];
		}
	}

	delete Tr;
	delete Ti;

	return;
}


void DFT1DandIDFT1D(float * Tr, float * Ti, int N, bool bDFTorIDFT)
{
	int u;
	int x;
	float * Fr = new float[N];
	float * Fi = new float[N];
	float w;
	for (u = 0; u < N; u++)
	{
		if (bDFTorIDFT)
		{
			w = -2 * PI * u;
		}

		else
		{
			w = 2 * PI * u;
		}

		Fr[u] = 0;
		Fi[u] = 0;
		for (x = 0; x < N; x++)
		{
			Fr[u] += Tr[x] * cos(w*x) - Ti[x] * sin(w*x);
			Fi[u] += Tr[x] * sin(w*x) + Ti[x] * cos(w*x);
		}
	}

	for (x = 0; x < N; x++)
	{
		if (bDFTorIDFT)
		{
			Tr[x] = Fr[x];
			Ti[x] = Fi[x];
		}
		else
		{
			Tr[x] = Fr[x] * 1.0 / N;
			Ti[x] = Fi[x] * 1.0 / N;
		}

	}

	delete[] Fr;
	delete[] Fi;
	return;
}


void DFT2DandIDFT2D(float * inDataReal, float * inDataImage, float * outDataReal, float * outDataImage, int M, int N, bool bDFTorIDFT)
{
	int i, j;

	float *Tr;
	float *Ti;

	Tr = new float[N];
	Ti = new float[N];

	//每行进行傅立叶变换
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			Tr[j] = inDataReal[i*N + j];
			Ti[j] = inDataImage[i*N + j];
		}

		DFT1DandIDFT1D(Tr, Ti, N, bDFTorIDFT);

		for (j = 0; j < M; j++)
		{
			outDataReal[i*N + j] = Tr[j];
			outDataImage[i*N + j] = Ti[j];
		}
	}

	delete Tr;
	delete Ti;

	Tr = new float[M];
	Ti = new float[M];


	//每列进行傅立叶变换		
	for (j = 0; j < N; j++)
	{
		for (i = 0; i < M; i++)
		{
			Tr[i] = outDataReal[i*N + j];
			Ti[i] = outDataImage[i*N + j];
		}

		DFT1DandIDFT1D(Tr, Ti, M, bDFTorIDFT);

		for (i = 0; i < M; i++)
		{
			outDataReal[i*N + j] = Tr[i];
			outDataImage[i*N + j] = Ti[i];
		}
	}

	delete Tr;
	delete Ti;

	return;
}


void CDIPDoc::OnImagefastfouriertransform()
{
	// TODO: 在此添加命令处理程序代码

	if (m_sImage.IsNull())
	{
		return;
	}
	int sWidth = m_sImage.GetWidth();
	int sHeight = m_sImage.GetHeight();
	int sRowBytes = m_sImage.GetPitch();

	m_rImage.Destroy();
	if (!m_rImage.Create(sWidth, sHeight, m_sImage.GetBPP(), 0))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();

	float *inReal;
	float *inImage;
	float *outReal;
	float *outImage;

	inReal = new float[sHeight*sWidth];
	inImage = new float[sHeight*sWidth];

	outReal = new float[sHeight*sWidth];
	outImage = new float[sHeight*sWidth];

	int x;
	int y;

	int i;
	for (i = 0; i < 3; i++)
	{
		for (y = 0; y < sHeight; y++)
			for (x = 0; x < sWidth; x++)
			{
				inReal[y*sWidth + x] = (float)sImageData[y*sRowBytes + 3 * x + i];
				inImage[y*sWidth + x] = 0;
			}

		FFT2DandIFFT2D(inReal, inImage, outReal, outImage, sHeight, sWidth, TRUE);

		for (y = 0; y < sHeight; y++)
			for (x = 0; x < sWidth; x++)
			{
				//将变换后现实的原点调整在中心位置
				float tmpp = sqrt(outReal[y*sWidth + x] * outReal[y*sWidth + x] + outImage[y*sWidth + x] * outImage[y*sWidth + x]);
				rImageData[y*sRowBytes + x * 3 + i] = (int)tmpp / 100;
			}
	}

	delete inReal;
	delete inImage;
	delete outReal;
	delete outImage;

	UpdateAllViews(NULL);
}


void CDIPDoc::OnImagefastfouriertransformcenter()
{
	// TODO: 在此添加命令处理程序代码
	if (m_sImage.IsNull())
	{
		return;
	}
	int sWidth = m_sImage.GetWidth();
	int sHeight = m_sImage.GetHeight();
	int sRowBytes = m_sImage.GetPitch();
	m_rImage.Destroy();
	if (!m_rImage.Create(sWidth, sHeight, m_sImage.GetBPP(), 0))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();

	float *inReal;
	float *inImage;
	float *outReal;
	float *outImage;

	inReal = new float[sHeight*sWidth];
	inImage = new float[sHeight*sWidth];

	outReal = new float[sHeight*sWidth];
	outImage = new float[sHeight*sWidth];

	int x;
	int y;

	int i;

	for (i = 0; i < 3; i++)
	{
		for (y = 0; y < sHeight; y++)
			for (x = 0; x < sWidth; x++)
			{
				if ((y < sHeight) && (x < sWidth))
				{
					int sgn = ((x + y) % 2 == 0) ? 1 : -1;
					inReal[y*sWidth + x] = (float)sgn*sImageData[y*sRowBytes + 3 * x + i];
				}
				else
				{
					inReal[y*sWidth + x] = 0;
				}
				inImage[y*sWidth + x] = 0;
			}

		FFT2DandIFFT2D(inReal, inImage, outReal, outImage, sHeight, sWidth, TRUE);



		for (y = 0; y < sHeight; y++)
			for (x = 0; x<sWidth; x++)
			{
				float temp = (float)sqrt(outReal[y*sWidth + x] * outReal[y*sWidth + x] + outImage[y*sWidth + x] * outImage[y*sWidth + x]);
				temp /= 300;
				temp = (temp>255.0f) ? 255.0f : temp;
				//将变换后现实的原点调整在中心位置
				rImageData[y*sRowBytes + x * 3 + i] = (int)temp;
			}
	}
	delete inReal;
	delete inImage;
	delete outReal;
	delete outImage;

	UpdateAllViews(NULL);
}



void CDIPDoc::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	CImage m_sImage2;
	CString strFilter;
	CSimpleArray<GUID>  aguidFileTypes;
	HRESULT hResult;
	// 获取CImage支持的图像文件的过滤字符串
	hResult = m_sImage2.GetExporterFilterString(strFilter, aguidFileTypes, _T("All Image Files"));
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("GetExporterFilter函数失败!"));
		return;
	}
	// 生成打开图像文件的对话框
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// 将外部图像文件装载到CImage对象中
	hResult = m_sImage2.Load(dlg.GetPathName());
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("图像文件加载失败！"));
		return;
	}
	if (m_sImage.IsNull())
	{
		return;
	}
	int nCols = m_sImage.GetWidth();
	int nRows = m_sImage.GetHeight();
	if (m_sImage2.GetWidth() != nCols || m_sImage2.GetHeight() != nRows)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理大小相同的图像！"));
		return;
	}
	int nRowBytes = m_sImage.GetPitch();
	m_rImage.Destroy();
	if (!m_rImage.Create(nCols, nRows, m_sImage.GetBPP(), 0))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *sImageData2 = (BYTE *)m_sImage2.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();

	int x, y;
	for (y = 0; y < nRows; y++) {
		for (x = 0; x < nCols; x++) {
			rImageData[y * nRowBytes + x * 3] = (sImageData[y * nRowBytes + x * 3] + sImageData2[y * nRowBytes + x * 3]) / 2;
			rImageData[y * nRowBytes + x * 3 + 1] = (sImageData[y * nRowBytes + x * 3 + 1] + sImageData2[y * nRowBytes + x * 3 + 1]) / 2;
			rImageData[y * nRowBytes + x * 3 + 2] = (sImageData[y * nRowBytes + x * 3 + 2] + sImageData2[y * nRowBytes + x * 3 + 2]) / 2;
		}
	}
	UpdateAllViews(NULL);
}


void CDIPDoc::OnSubtract()
{
	// TODO: 在此添加命令处理程序代码
	CImage m_sImage2;
	CString strFilter;
	CSimpleArray<GUID>  aguidFileTypes;
	HRESULT hResult;
	// 获取CImage支持的图像文件的过滤字符串
	hResult = m_sImage2.GetExporterFilterString(strFilter, aguidFileTypes, _T("All Image Files"));
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("GetExporterFilter函数失败!"));
		return;
	}
	// 生成打开图像文件的对话框
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// 将外部图像文件装载到CImage对象中
	hResult = m_sImage2.Load(dlg.GetPathName());
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("图像文件加载失败！"));
		return;
	}
	if (m_sImage.IsNull())
	{
		return;
	}
	int nCols = m_sImage.GetWidth();
	int nRows = m_sImage.GetHeight();
	if (m_sImage2.GetWidth() != nCols || m_sImage2.GetHeight() != nRows)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理大小相同的图像！"));
		return;
	}
	int nRowBytes = m_sImage.GetPitch();
	m_rImage.Destroy();
	if (!m_rImage.Create(nCols, nRows, m_sImage.GetBPP(), 0))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *sImageData2 = (BYTE *)m_sImage2.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();

	int x, y;
	for (y = 0; y < nRows; y++) {
		for (x = 0; x < nCols; x++) {
			rImageData[y * nRowBytes + x * 3] = (sImageData[y * nRowBytes + x * 3] - sImageData2[y * nRowBytes + x * 3] + 255) / 2;
			rImageData[y * nRowBytes + x * 3 + 1] = (sImageData[y * nRowBytes + x * 3 + 1] - sImageData2[y * nRowBytes + x * 3 + 1] + 255) / 2;
			rImageData[y * nRowBytes + x * 3 + 2] = (sImageData[y * nRowBytes + x * 3 + 2] - sImageData2[y * nRowBytes + x * 3 + 2] + 255) / 2;
		}
	}
	UpdateAllViews(NULL);
}


void CDIPDoc::OnMultiply()
{
	// TODO: 在此添加命令处理程序代码
	CImage m_sImage2;
	CString strFilter;
	CSimpleArray<GUID>  aguidFileTypes;
	HRESULT hResult;
	// 获取CImage支持的图像文件的过滤字符串
	hResult = m_sImage2.GetExporterFilterString(strFilter, aguidFileTypes, _T("All Image Files"));
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("GetExporterFilter函数失败!"));
		return;
	}
	// 生成打开图像文件的对话框
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// 将外部图像文件装载到CImage对象中
	hResult = m_sImage2.Load(dlg.GetPathName());
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("图像文件加载失败！"));
		return;
	}
	if (m_sImage2.GetBPP() != 24)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理24位色图像！"));
		return;
	}
	if (m_sImage.IsNull())
	{
		return;
	}
	int nCols = m_sImage.GetWidth();
	int nRows = m_sImage.GetHeight();
	if (m_sImage2.GetWidth() != nCols || m_sImage2.GetHeight() != nRows)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理大小相同的图像！"));
		return;
	}
	int nRowBytes = m_sImage.GetPitch();
	m_rImage.Destroy();
	if (!m_rImage.Create(nCols, nRows, m_sImage.GetBPP(), 0))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *sImageData2 = (BYTE *)m_sImage2.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();

	int x, y;
	for (y = 0; y < nRows; y++) {
		for (x = 0; x < nCols; x++) {
			rImageData[y * nRowBytes + x * 3 + 0] = (sImageData[y * nRowBytes + x * 3 + 0] * sImageData2[y * nRowBytes + x * 3 + 0]);
			rImageData[y * nRowBytes + x * 3 + 1] = (sImageData[y * nRowBytes + x * 3 + 1] * sImageData2[y * nRowBytes + x * 3 + 1]);
			rImageData[y * nRowBytes + x * 3 + 2] = (sImageData[y * nRowBytes + x * 3 + 2] * sImageData2[y * nRowBytes + x * 3 + 2]);
		}
	}
	UpdateAllViews(NULL);
}


void CDIPDoc::OnDivide()
{
	// TODO: 在此添加命令处理程序代码
	CImage m_sImage2;
	CString strFilter;
	CSimpleArray<GUID>  aguidFileTypes;
	HRESULT hResult;
	// 获取CImage支持的图像文件的过滤字符串
	hResult = m_sImage2.GetExporterFilterString(strFilter, aguidFileTypes, _T("All Image Files"));
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("GetExporterFilter函数失败!"));
		return;
	}
	// 生成打开图像文件的对话框
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// 将外部图像文件装载到CImage对象中
	hResult = m_sImage2.Load(dlg.GetPathName());
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("图像文件加载失败！"));
		return;
	}
	if (m_sImage2.GetBPP() != 24)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理24位色图像！"));
		return;
	}
	if (m_sImage.IsNull())
	{
		return;
	}
	int nCols = m_sImage.GetWidth();
	int nRows = m_sImage.GetHeight();
	if (m_sImage2.GetWidth() != nCols || m_sImage2.GetHeight() != nRows)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理大小相同的图像！"));
		return;
	}
	int nRowBytes = m_sImage.GetPitch();
	m_rImage.Destroy();
	if (!m_rImage.Create(nCols, nRows, m_sImage.GetBPP(), 0))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *sImageData2 = (BYTE *)m_sImage2.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();

	int x, y;
	for (y = 0; y < nRows; y++) {
		for (x = 0; x < nCols; x++) {
			sImageData2[y * nRowBytes + x * 3] = (255 - sImageData2[y * nRowBytes + x * 3]);
			sImageData2[y * nRowBytes + x * 3 + 1] = (255 - sImageData2[y * nRowBytes + x * 3 + 1]);
			sImageData2[y * nRowBytes + x * 3 + 2] = (255 - sImageData2[y * nRowBytes + x * 3 + 2]);
		}
	}
	for (y = 0; y < nRows; y++) {
		for (x = 0; x < nCols; x++) {
			rImageData[y * nRowBytes + x * 3] = (sImageData[y * nRowBytes + x * 3] * sImageData2[y * nRowBytes + x * 3] + 255);
			rImageData[y * nRowBytes + x * 3 + 1] = (sImageData[y * nRowBytes + x * 3 + 1] * sImageData2[y * nRowBytes + x * 3 + 1] + 255);
			rImageData[y * nRowBytes + x * 3 + 2] = (sImageData[y * nRowBytes + x * 3 + 2] * sImageData2[y * nRowBytes + x * 3 + 2] + 255);
		}
	}
	UpdateAllViews(NULL);
}


void CDIPDoc::OnAnd()
{
	// TODO: 在此添加命令处理程序代码
	CImage m_sImage2;
	CString strFilter;
	CSimpleArray<GUID>  aguidFileTypes;
	HRESULT hResult;
	// 获取CImage支持的图像文件的过滤字符串
	hResult = m_sImage2.GetExporterFilterString(strFilter, aguidFileTypes, _T("All Image Files"));
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("GetExporterFilter函数失败!"));
		return;
	}
	// 生成打开图像文件的对话框
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// 将外部图像文件装载到CImage对象中
	hResult = m_sImage2.Load(dlg.GetPathName());
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("图像文件加载失败！"));
		return;
	}
	if (m_sImage2.GetBPP() != 24)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理24位色图像！"));
		return;
	}
	if (m_sImage.IsNull())
	{
		return;
	}
	int nCols = m_sImage.GetWidth();
	int nRows = m_sImage.GetHeight();
	if (m_sImage2.GetWidth() != nCols || m_sImage2.GetHeight() != nRows)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理大小相同的图像！"));
		return;
	}
	int nRowBytes = m_sImage.GetPitch();
	m_rImage.Destroy();
	if (!m_rImage.Create(nCols, nRows, m_sImage.GetBPP(), 0))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *sImageData2 = (BYTE *)m_sImage2.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();

	int x, y;
	for (y = 0; y < nRows; y++) {
		for (x = 0; x < nCols; x++) {
			rImageData[y * nRowBytes + x * 3] = (sImageData[y * nRowBytes + x * 3] & sImageData2[y * nRowBytes + x * 3]);
			rImageData[y * nRowBytes + x * 3 + 1] = (sImageData[y * nRowBytes + x * 3 + 1] & sImageData2[y * nRowBytes + x * 3 + 1]);
			rImageData[y * nRowBytes + x * 3 + 2] = (sImageData[y * nRowBytes + x * 3 + 2] & sImageData2[y * nRowBytes + x * 3 + 2]);
		}
	}
	UpdateAllViews(NULL);
}


void CDIPDoc::OnOr()
{
	// TODO: 在此添加命令处理程序代码
	CImage m_sImage2;
	CString strFilter;
	CSimpleArray<GUID>  aguidFileTypes;
	HRESULT hResult;
	// 获取CImage支持的图像文件的过滤字符串
	hResult = m_sImage2.GetExporterFilterString(strFilter, aguidFileTypes, _T("All Image Files"));
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("GetExporterFilter函数失败!"));
		return;
	}
	// 生成打开图像文件的对话框
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if (IDOK != dlg.DoModal())
		return;
	// 将外部图像文件装载到CImage对象中
	hResult = m_sImage2.Load(dlg.GetPathName());
	if (FAILED(hResult))
	{
		AfxMessageBox(_T("图像文件加载失败！"));
		return;
	}
	if (m_sImage2.GetBPP() != 24)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理24位色图像！"));
		return;
	}
	if (m_sImage.IsNull())
	{
		return;
	}
	int nCols = m_sImage.GetWidth();
	int nRows = m_sImage.GetHeight();
	if (m_sImage2.GetWidth() != nCols || m_sImage2.GetHeight() != nRows)
	{
		m_sImage2.Destroy();
		AfxMessageBox(_T("只处理大小相同的图像！"));
		return;
	}
	int nRowBytes = m_sImage.GetPitch();
	m_rImage.Destroy();
	if (!m_rImage.Create(nCols, nRows, m_sImage.GetBPP(), 0))
		return;

	BYTE *sImageData = (BYTE *)m_sImage.GetBits();
	BYTE *sImageData2 = (BYTE *)m_sImage2.GetBits();
	BYTE *rImageData = (BYTE *)m_rImage.GetBits();

	int x, y;
	for (y = 0; y < nRows; y++) {
		for (x = 0; x < nCols; x++) {
			rImageData[y * nRowBytes + x * 3] = (sImageData[y * nRowBytes + x * 3] | sImageData2[y * nRowBytes + x * 3]);
			rImageData[y * nRowBytes + x * 3 + 1] = (sImageData[y * nRowBytes + x * 3 + 1] | sImageData2[y * nRowBytes + x * 3 + 1]);
			rImageData[y * nRowBytes + x * 3 + 2] = (sImageData[y * nRowBytes + x * 3 + 2] | sImageData2[y * nRowBytes + x * 3 + 2]);
		}
	}
	UpdateAllViews(NULL);
}

//图像脉冲噪声污染
void ImagePeppperNoisePollution(CImage * pImg, double pa, double pb)
{
	int x;
	int y;
	int sWidth = pImg->GetWidth();
	int sHeight = pImg->GetHeight();
	int sRowBytes = pImg->GetPitch();
	BYTE *sImageData = (BYTE *)pImg->GetBits();
	//生成伪随机种子
	srand((unsigned)time(NULL));

	//在图像中添加脉冲噪声（椒盐噪声）
	for (y = 0; y < sHeight; y++)
		for (x = 0; x < sWidth; x++)
		{
			int srd = rand() % 100;
			if (srd >((int)(100 * (1 - pb))))
			{
				//图像中当前点置为黑(噪声）	
				sImageData[y*sRowBytes + x * 3] = 0;
				sImageData[y*sRowBytes + x * 3 + 1] = 0;
				sImageData[y*sRowBytes + x * 3 + 2] = 0;
			}
			else if (srd < ((int)(100 * pa)))
			{
				sImageData[y*sRowBytes + x * 3] = 255;
				sImageData[y*sRowBytes + x * 3 + 1] = 255;
				sImageData[y*sRowBytes + x * 3 + 2] = 255;
			}
		}

	return;
}

//图像均匀噪声污染
void ImageUniformNoisePollution(CImage * pImg, double a, double b)
{
	int x;
	int y;
	int sWidth = pImg->GetWidth();
	int sHeight = pImg->GetHeight();
	int sRowBytes = pImg->GetPitch();

	BYTE *sImageData = (BYTE *)pImg->GetBits();

	int Uab = (int)(b - a);
	int grey;
	//随机噪声
	BYTE NoisePoint;

	//生成伪随机种子
	srand((unsigned)time(NULL));
	//在图像中加随机噪声
	for (y = 0; y < sHeight; y++)
		for (x = 0; x < sWidth; x++)
		{
			NoisePoint = rand() % Uab;
			grey = sImageData[y*sRowBytes + x * 3 + 0] + NoisePoint;
			grey = grey > 255 ? 255 : (grey < 0) ? 0 : grey;
			sImageData[y*sRowBytes + x * 3 + 0] = grey;
			grey = sImageData[y*sRowBytes + x * 3 + 1] + NoisePoint;
			grey = grey > 255 ? 255 : (grey < 0) ? 0 : grey;
			sImageData[y*sRowBytes + x * 3 + 1] = grey;
			grey = sImageData[y*sRowBytes + x * 3 + 2] + NoisePoint;
			grey = grey > 255 ? 255 : (grey < 0) ? 0 : grey;
			sImageData[y*sRowBytes + x * 3 + 2] = grey;
		}
	return;
}

//生成高斯分布随机数序列
double generateGaussianNoise(double mu, double sigma)
{
	static const double esp = 1e-100;
	static double V1, V2, S;
	static int phase = 0;
	double X;
	double U1, U2;
	if (phase == 0)
	{
		do {
			U1 = (double)rand() / RAND_MAX;
			U2 = (double)rand() / RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
		} while (S >= 1 || S == 0);

		X = V1 * sqrt(-2 * log(S) / S);
	}
	else
	{
		X = V2 * sqrt(-2 * log(S) / S);
	}
	phase = 1 - phase;
	return mu + sigma*X;

}

//图像高斯噪声污染
void ImageGauessNoisePollution(CImage * pImg, double mu, double sigma, double k)
{
	int x;
	int y;
	int sWidth = pImg->GetWidth();
	int sHeight = pImg->GetHeight();
	int sRowBytes = pImg->GetPitch();

	BYTE *sImageData = (BYTE *)pImg->GetBits();

	double NoiseValue;
	double val;
	srand(time(NULL));
	//在图像中加高斯噪声
	for (y = 0; y < sHeight; y++)
		for (x = 0; x < sWidth; x++)
		{
			NoiseValue = generateGaussianNoise(mu, sigma);
			val = sImageData[y*sRowBytes + x * 3 + 0] + k * NoiseValue;
			val = (val > 255) ? 255 : ((val < 0) ? 0 : val);
			sImageData[y*sRowBytes + x * 3 + 0] = (int)val;

			val = sImageData[y*sRowBytes + x * 3 + 1] + k * NoiseValue;
			val = (val > 255) ? 255 : ((val < 0) ? 0 : val);
			sImageData[y*sRowBytes + x * 3 + 1] = (BYTE)val;

			val = sImageData[y*sRowBytes + x * 3 + 2] + k * NoiseValue;
			val = (val > 255) ? 255 : ((val < 0) ? 0 : val);
			sImageData[y*sRowBytes + x * 3 + 2] = (BYTE)val;
		}
	return;
}

//图像噪声污染
void CDIPDoc::OnAddnoise()
{
	// TODO: 在此添加命令处理程序代码
	if (m_sImage.IsNull())
	{
		AfxMessageBox(_T("请打开要处理的图像！"));
		return;
	}

	CINP mdlg;
	if (mdlg.DoModal() != IDOK)
		return;

	CImage *pImg;

	if (mdlg.m_check1)
	{
		pImg = &m_sImage;
	}
	else
	{
		int x;
		int y;
		int nRows = m_sImage.GetHeight();
		int nCols = m_sImage.GetWidth();
		int nBPP = m_sImage.GetBPP();
		m_rImage.Destroy();
		if (!m_rImage.Create(nCols, nRows, nBPP))
			return;
		BYTE *sImageData = (BYTE *)m_sImage.GetBits();
		BYTE *rImageData = (BYTE *)m_rImage.GetBits();
		int nRowBytes = m_sImage.GetPitch();
		for (y = 0; y < nRows; y++)
			for (x = 0; x < nCols; x++)
			{
				rImageData[y * nRowBytes + x * 3] = sImageData[y * nRowBytes + x * 3 + 0];
				rImageData[y * nRowBytes + x * 3 + 1] = sImageData[y * nRowBytes + x * 3 + 1];
				rImageData[y * nRowBytes + x * 3 + 2] = sImageData[y * nRowBytes + x * 3 + 2];
			}
		pImg = &m_rImage;
	}

	switch (mdlg.m_radio1)
	{
	case 0: //脉冲噪声（椒盐噪声）
		ImagePeppperNoisePollution(pImg, mdlg.m_pa, mdlg.m_pb);
		break;
	case 1: //均匀分布噪声
		ImageUniformNoisePollution(pImg, mdlg.m_ua, mdlg.m_ub);
		break;
	case 2:     //高斯噪声
		ImageGauessNoisePollution(pImg, mdlg.m_gauess_mu, mdlg.m_gauess_sigma, mdlg.m_gauess_k);
		break;
	case 3:     //泊松噪声
		break;
	case 4:     //伽马（爱尔兰）噪声
		break;
	case 5:     //指数噪声
		break;
	case 6:     //
		break;
	default: break;
	}
	UpdateAllViews(NULL);
}

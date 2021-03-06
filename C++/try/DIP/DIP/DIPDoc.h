
// DIPDoc.h: CDIPDoc 类的接口
//


#pragma once


class CDIPDoc : public CDocument
{
protected: // 仅从序列化创建
	CDIPDoc();
	DECLARE_DYNCREATE(CDIPDoc)

// 特性
public:
	CImage m_sImage;
	CImage m_rImage;
	bool   bFileIsOpen;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CDIPDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileOpen();
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnGray1();
	afx_msg void OnGrayhistogram();
	afx_msg void OnHistogramequalization();
	afx_msg void OnImagefastfouriertransform();
	afx_msg void OnImagefastfouriertransformcenter();
	afx_msg void OnFileSave();
	afx_msg void OnAdd();
	afx_msg void OnSubtract();
	afx_msg void OnMultiply();
	afx_msg void OnDivide();
	afx_msg void OnAnd();
	afx_msg void OnOr();
	afx_msg void OnAddnoise();
	int m_iBit;
	int m_iByte;
};
//直方图均衡化
void HistogramEqualization(int* pSourceData, int nRows, int nCols);

// FFT1DandIFFT1D 一维快速傅立叶变换与逆变换函数 
// 输入时域数据实部为Tr,虚部为Ti
// 输出频域数据实部为Tr,虚部为Ti
// 序列长度N，N等于2的r次幂
// FFTorIFFT,逻辑变量，非零做正变换，零做反变换
void FFT1DandIFFT1D(float * Tr, float * Ti, int N, bool bFFTorIFFT);

// FFT2DandIFFT2D 二维快速傅立叶变换与逆变换函数 
// 输入数据实部数组inDataReal,虚部数组inDataImage
// 输出数据实部数组outDataReal,虚部数组outDataImage
// 二维数组高度M宽度N(M和N都等于2的某次幂）
// 逻辑类型变量bFFTorIFFT：0 - 进行Fourier逆变换；否则进行Fouridr变换
void FFT2DandIFFT2D(float * inDataReal, float * inDataImage, float * outDataReal, float * outDataImage, int M, int N, bool bFFTorIFFT);

void DFT1DandIDFT1D(float * Tr, float * Ti, int N, bool bDFTorIDFT);
void DFT2DandIDFT2D(float * inDataReal, float * inDataImage, float * outDataReal, float * outDataImage, int M, int N, bool bDFTorIDFT);

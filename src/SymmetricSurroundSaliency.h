// SymmetricSurroundSaliency.h: interface for the SymmetricSurroundSaliency class.
//
//////////////////////////////////////////////////////////////////////
//===========================================================================
// This code implements the saliency method described in:
//
// R. Achanta and S. Süsstrunk,
// "Saliency Detection using Maximum Symmetric Surround",
// Proceedings of IEEE International Conference on Image Processing (ICIP), 2010.
//===========================================================================
//	Copyright (c) 2010 Radhakrishna Achanta [EPFL]. All rights reserved.
//===========================================================================

#ifndef SYMMETRICSURROUNDSALIENCY_H_
#define SYMMETRICSURROUNDSALIENCY_H_

#include <vector>
#include "SaliencyDetector.h"

using namespace std;

class SymmetricSurroundSaliency
{
public:
	SymmetricSurroundSaliency();
	virtual ~SymmetricSurroundSaliency();

public:
	void ComputeMaximumSymmetricSurroundSaliency(const vector<RGBColour>& img,//INPUT: ARGB buffer in row-major order
			const int& width, const int& height, vector<double>& salmap,//OUTPUT: Floating point buffer in row-major order
			const bool& normflag = true);

private:

	void RGB2LAB(const vector<RGBColour>& ubuff, vector<double>& lvec,
			vector<double>& avec, vector<double>& bvec);

	void GaussianSmooth(const vector<double>& inputImg, const int& width,
			const int& height, const vector<double>& kernel,
			vector<double>& smoothImg);

	//===========================================================================
	///	CreateIntegralImage
	///
	///	Any type (int, float, double) version
	//===========================================================================
	template<class T> void CreateIntegralImage(const vector<T>& inputImg,
			const int& width, const int& height, vector<vector<T> >& intImg);
	
	//===========================================================================
	///	GetIntegralSum
	///
	///	Any type (int, float, double) version, the more correct one. Returns a
	///	single pixle value if x1 == x2 and y1 == y2
	//===========================================================================
	//TODO Move to cpp file.
	template<class T> T GetIntegralSum(const vector<vector<T> >& integralImage,
			const int& x1, const int& y1, const int& x2, const int& y2)
	{
		T sum(0);
		if (x1 - 1 < 0 && y1 - 1 < 0)
		{
			sum = integralImage[y2][x2];
		}
		else if (x1 - 1 < 0)
		{
			sum = integralImage[y2][x2] - integralImage[y1 - 1][x2];
		}
		else if (y1 - 1 < 0)
		{
			sum = integralImage[y2][x2] - integralImage[y2][x1 - 1];
		}
		else
		{
			sum = integralImage[y2][x2] + integralImage[y1 - 1][x1 - 1]
					- integralImage[y1 - 1][x2] - integralImage[y2][x1 - 1];
		}

		return sum;

	}

	//===========================================================================
	///	Normalize
	//===========================================================================
	void Normalize(vector<double>& salmap, const int& width, const int& height);

};

#endif /* SYMMETRICSURROUNDSALIENCY_H_ */

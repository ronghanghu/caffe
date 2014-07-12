/*
 * matlab.cpp
 *
 *  Created on: Jun 26, 2014
 *      Author: ronghang
 */

#include "kyheader.h"
#include "Objectness.h"
#include "CmShow.h"
#include "DataSetVOC.h"

DataSetVOC::DataSetVOC()
{
	resDir = "svms/";
}

void Objectness::getObjBndBoxesSingleImg(CMat& img, ValStructVec<float, Vec4i> &boxesTests, int numDetPerSize)
{
	//ValStructVec<float, Vec4i> boxesTests;
	boxesTests.clear();
	int scales[3] = {1, 3, 5};
	for (int clr = MAXBGR; clr <= G; clr++){
		setColorSpace(clr);
		loadTrainedModel();
		ValStructVec<float, Vec4i> boxes;
		getObjBndBoxes(img, boxes, numDetPerSize);
		boxesTests.append(boxes, scales[clr]);
	}
	boxesTests.sort(false);
//	_boxesTests.resize(boxesTests.size());
//	for (int j = 0; j < boxesTests.size(); j++)
//		_boxesTests[j] = boxesTests[j];
}



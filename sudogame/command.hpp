#pragma once

#include "common.hpp"
#include <memory>

class CScene;
class CCommand
{
public:
	CCommand(CScene* pOwenr);
	CCommand(CScene* pOwenr, const point_t &point, int preValue, int curValue);
	CCommand(const CCommand &);
	~CCommand();

	bool execute(int nInputValue);
	void undo();
	point_t getPoint() { return _stPoint; }
	int getPreValue() { return _nPreValue; }
	int getCurValue() { return _nCurValue; }
	void setPoint(const point_t& point) { _stPoint = point; }
	void setPreValue(int preValue) { _nPreValue = preValue; }
	void setCurValue(int curValue) { _nCurValue = curValue; }

private:
	CScene* _pOwner;
	point_t _stPoint;
	int _nPreValue;
	int _nCurValue;
};


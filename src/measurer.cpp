#include "measurer.h"

namespace Performance
{
	Performance::Measurer::Measurer(Performance::MeasureUnit measureUnit)
		:_measureUnit(measureUnit), _state(0), _result(0)
	{

	}

	// todo: umv: apply conditional (os specifiv impl)
	void Performance::Measurer::Start()
	{
		
	}

	// todo: umv: apply conditional (os specifiv impl)
	void Performance::Measurer::Stop()
	{

	}
}
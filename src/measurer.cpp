#include "measurer.h"
#include <windows.h>

namespace Perfomance
{
    long long GetRtcValue()
    {
        long long value = 0;
        __asm
        {
            MOV DWORD PTR [value], EAX
            MOV DWORD PTR [value + 4], EDX
        }
        return value;
    }

    Perfomance::Measurer::Measurer(Perfomance::MeasureUnit measureUnit)
        :_measureUnit(measureUnit), _state(0), _result(0)
    {

    }

    // todo: umv: apply conditional (os specifiv impl)
    void Perfomance::Measurer::Start()
    {
        _state = false;
        _result = GetRtcValue();
    }

    // todo: umv: apply conditional (os specifiv impl)
    void Perfomance::Measurer::Stop()
    {
        _state = true;
        _result = GetRtcValue() - _result;
    }
}
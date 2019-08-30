#ifndef SRC_MEASURER_H
#define SRC_MEASURER_H

#include "platform.h"

namespace Perfomance
{
    /// ####################################################################### TIME MEASURE SURVEY SUMMARY #############################################################################
    /// Windows:
    ///     1) Low precision WIN API functions GetTickCount(), resolution is ~ 10 ms
    ///     2) High precision WIN API function QueryPerformanceCounter
    /// Linux:
    ///     1) Use function clock_gettime(3) with CLOCK_MONOTONIC_RAW from Linux API, time.h (resolution is ~ ns)
    /// Cross platform: 
    ///     1) ring-3 instruction: _rdtsc (~10-20 ns) 
    ///        RDTSC multicore accuracy:
    ///           The time stamp counter in newer processors may support an enhancement, referred to as invariant TSC.Processor's support for invariant TSC is indicated 
    ///           by CPUID.80000007H:EDX[8]. The invariant TSC will run at a constant rate in all ACPI P - , C - . and T - states.This is the architectural behavior moving 
    ///           forward.On processors with invariant TSC support, the OS may use the TSC for wall clock timer services (instead of ACPI or HPET timers).
    ///           TSC reads are much more efficient and do not incur the overhead associated with a ring transition or access to a platform resource."
    ///           In Linux see: __cpuinit int unsynchronized_tsc(void) to check for invariant TSC (Time Stamp Counter)
    ///     2) HPET (High Performance Event Timer), available on motherboards from 2006+, Higher precision than RTC (RDTSC)
    ///        HPET is NOT supported by Windows XP sp1, Windows 2003 and old linux
    ///        HPET IS supported by:
    ///            Windows Vista, Windows 2008, Windows 7, Windows 8, Windows 10
    ///	           Mac OS X(версия для x86)
    ///	           Linux версий 2.6 (драйвер rtc - cmos вместо rtc)
    ///	           FreeBSD
    ///	           eComStation(OS / 2) c неофициальным ядром OS / 4 начиная с версии svn 4502
    ///	           KolibriOS
    /// REMARKS:
    ///    All measure could be in accurate due to a lot of factors (CPU cache usage, dynamic frequency changes (i.e. Turbo Boost), energy saving mode, e.t.c.)
    /// ###################################################################################################################################################################################

    enum MeasureUnit
    {
        RTC = 1,
        HPET = 2,
        OTHER = 3 // get_clock 4 Linux and QueryPerformanceCounter 4 Windows
    };

    class EXPORT Measurer
    {
    public:
        Measurer() {}
        Measurer(Perfomance::MeasureUnit measureUnit);
        // delete copy constructor, des
        //~Measurer() delete
        void Start();
        void Stop();
        inline bool IsRunning() { return _state; }
        inline long long GetResult() { return _result; }
    private:
        Perfomance::MeasureUnit _measureUnit;
        long long _result;
        bool _state;
    };
}

#endif

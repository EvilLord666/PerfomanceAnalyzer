#ifndef SRC_MEASURER_H
#define SRC_MEASURER_H

namespace Perfomance
{
	class Measurer
	{
	public:
		Measurer();
		void Start();
		void Stop();
		inline bool IsRunning() { return _state; }
		inline long long GetResult() { return _result; }
	private:
		long long _result;
		bool _state;
	};
}

#endif

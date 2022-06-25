// Reference: https://stackoverflow.com/a/21995693/8437174

#include <chrono>
#include <typeinfo>

template <class DT = std::chrono::microseconds,
          class ClockT = std::chrono::steady_clock>
class Timer
{
    using timep_t = typename ClockT::time_point;
    timep_t _start = ClockT::now(), _end = {};

public:
    void tick() { 
        _end = timep_t{}; 
        _start = ClockT::now(); 
    }
    
    void tock() { _end = ClockT::now(); }
    
    template <class T = DT> 
    auto duration() const { 
        return std::chrono::duration_cast<T>(_end - _start);
    }

    /**
     * \brief  Get performance of the sandwiched code
     * \param  [in] n number of processed elements
     * \return Performance in million of elements
     * \date   2022-06-21
     */
    template <class T = DT> 
    auto get_perf(int n) {
        double scale = 0;

        if (typeid(T) == typeid(std::chrono::milliseconds)) {
            scale = 10e-3;
        } else if (typeid(T) == typeid(std::chrono::microseconds)) {
            scale = 1;
        } else if (typeid(T) == typeid(std::chrono::nanoseconds)) {
            scale = 10e3;
        }
        
        auto cnt = duration().count();
        
        if (cnt == 0) {
            return -1.0;
        }

        return n * scale / cnt;
    }

    /**
     * \brief  Get time elapsed between tick and tock in microsecond
     * \return Performance in million of elements. Return -1 if type is not 
     * either milisecond, microsecond, or nanosecond.
     * \date   2022-06-21
     */
    template <class T = DT> 
    auto get_elapse_time(void) {
        double to_us = 1.0;   // conversion rate to microsecond

        if (typeid(T) == typeid(std::chrono::milliseconds)) {
            to_us = 10e3;
        } else if (typeid(T) == typeid(std::chrono::nanoseconds)) {
            to_us = 10e-3;
        } else if (typeid(T) == typeid(std::chrono::microseconds)) {
            to_us = 1;
        } else {
            return -1.0;
        }
        
        return to_us * duration().count();
    }
};

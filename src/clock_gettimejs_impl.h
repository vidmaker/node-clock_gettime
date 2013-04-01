#ifndef CLOCK_GETTIMEJS_IMPL_H_
#define CLOCK_GETTIMEJS_IMPL_H_

#include <node.h>
#include <v8.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#ifndef CLOCK_MONOTONIC
  #define CLOCK_MONOTONIC -1
#endif
#ifndef CLOCK_MONOTONIC
  #define CLOCK_PROCESS_CPUTIME_ID -1
#endif
#ifndef CLOCK_MONOTONIC
  #define CLOCK_THREAD_CPUTIME_ID -1
#endif
#ifndef CLOCK_MONOTONIC
  #define CLOCK_MONOTONIC_RAW -1
#endif
#ifndef CLOCK_MONOTONIC
  #define CLOCK_REALTIME_COARSE -1
#endif
#ifndef CLOCK_MONOTONIC
  #define CLOCK_MONOTONIC_COARSE -1
#endif
#ifndef CLOCK_MONOTONIC
  #define CLOCK_BOOTTIME -1
#endif
#ifndef CLOCK_MONOTONIC
  #define CLOCK_REALTIME_ALARM -1
#endif
#ifndef CLOCK_MONOTONIC
  #define CLOCK_BOOTTIME_ALARM -1
#endif

#define THROW_IF_NOT(expr, msg) if (!(expr)) {return v8::ThrowException(v8::Exception::RangeError(v8::String::New((msg))));}

namespace clock_gettimejs {

  typedef ::time_t time_t;
  typedef ::timespec timespec;

  inline timespec clock_getres(int clk_id) {
    if (clk_id < 0) {
      v8::ThrowException(v8::Exception::TypeError(v8::String::New("Specified clk_id not supported on this OS.")));
    }
    timespec ts;
    int ret = ::clock_getres((clockid_t)clk_id, &ts);
    if (ret < 0) {
      v8::ThrowException(v8::Exception::TypeError(v8::String::New(strerror(errno))));
    }
    return ts;
  };

  inline timespec clock_gettime(int clk_id) {
    if (clk_id < 0) {
      v8::ThrowException(v8::Exception::TypeError(v8::String::New("Specified clk_id not supported on this OS.")));
    }
    timespec ts;
    int ret = ::clock_gettime((clockid_t)clk_id, &ts);
    if (ret < 0) {
      v8::ThrowException(v8::Exception::TypeError(v8::String::New(strerror(errno))));
    }
    return ts;
  };

} // namespace clock_gettimejs

#endif // #ifdef CLOCK_GETTIMEJS_IMPL_H_

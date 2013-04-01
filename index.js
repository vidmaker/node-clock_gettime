var clock_gettimejs = require('./build/Release/clock_gettime');

module.exports.clock_gettime            = clock_gettimejs.clock_gettimejs.clock_gettime;
module.exports.clock_settime            = clock_gettimejs.clock_gettimejs.clock_settime;
module.exports.clock_getres             = clock_gettimejs.clock_gettimejs.clock_getres;
module.exports.CLOCK_REALTIME           = clock_gettimejs.CLOCK_REALTIME;
module.exports.CLOCK_REALTIME_COARSE    = clock_gettimejs.CLOCK_REALTIME_COARSE;
module.exports.CLOCK_MONOTONIC          = clock_gettimejs.CLOCK_MONOTONIC;
module.exports.CLOCK_MONOTONIC_COARSE   = clock_gettimejs.CLOCK_MONOTONIC_COARSE;
module.exports.CLOCK_MONOTONIC_RAW      = clock_gettimejs.CLOCK_MONOTONIC_RAW;
module.exports.CLOCK_BOOTTIME           = clock_gettimejs.CLOCK_BOOTTIME;
module.exports.CLOCK_PROCESS_CPUTIME_ID = clock_gettimejs.CLOCK_PROCESS_CPUTIME_ID;
module.exports.CLOCK_THREAD_CPUTIME_ID  = clock_gettimejs.CLOCK_THREAD_CPUTIME_ID;

module.exports.diff = function(start, end) {
  var temp = {};
  if ((end.tv_nsec - start.tv_nsec) < 0) {
    temp.tv_sec = end.tv_sec - start.tv_sec - 1;
    temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec - start.tv_sec;
    temp.tv_nsec = end.tv_nsec - start.tv_nsec;
  }
  return temp;
};

module.exports.to_ns = function(ts) {
  return ts.tv_sec * 1000000000 + ts.tv_nsec;
};
module.exports.to_us = function(ts) {
  return ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
};
module.exports.to_ms = function(ts) {
  return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
};

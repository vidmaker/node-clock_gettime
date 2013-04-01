var t = require('../index');

var times = {
  CLOCK_REALTIME: {},
  CLOCK_REALTIME_COARSE: {},
  CLOCK_MONOTONIC: {},
  CLOCK_MONOTONIC_COARSE: {},
  CLOCK_MONOTONIC_RAW: {},
  CLOCK_BOOTTIME: {},
  CLOCK_PROCESS_CPUTIME_ID: {},
  CLOCK_THREAD_CPUTIME_ID: {}
};

times.CLOCK_REALTIME.time            = t.clock_gettime(t.CLOCK_REALTIME);
times.CLOCK_REALTIME.res             = t.clock_getres(t.CLOCK_REALTIME);
times.CLOCK_REALTIME_COARSE.time     = t.clock_gettime(t.CLOCK_REALTIME_COARSE);
times.CLOCK_REALTIME_COARSE.res      = t.clock_getres(t.CLOCK_REALTIME_COARSE);
times.CLOCK_MONOTONIC.time           = t.clock_gettime(t.CLOCK_MONOTONIC);
times.CLOCK_MONOTONIC.res            = t.clock_getres(t.CLOCK_MONOTONIC);
times.CLOCK_MONOTONIC_COARSE.time    = t.clock_gettime(t.CLOCK_MONOTONIC_COARSE);
times.CLOCK_MONOTONIC_COARSE.res     = t.clock_getres(t.CLOCK_MONOTONIC_COARSE);
times.CLOCK_MONOTONIC_RAW.time       = t.clock_gettime(t.CLOCK_MONOTONIC_RAW);
times.CLOCK_MONOTONIC_RAW.res        = t.clock_getres(t.CLOCK_MONOTONIC_RAW);
times.CLOCK_BOOTTIME.time            = t.clock_gettime(t.CLOCK_BOOTTIME);
times.CLOCK_BOOTTIME.res             = t.clock_getres(t.CLOCK_BOOTTIME);
times.CLOCK_PROCESS_CPUTIME_ID.time  = t.clock_gettime(t.CLOCK_PROCESS_CPUTIME_ID);
times.CLOCK_PROCESS_CPUTIME_ID.res   = t.clock_getres(t.CLOCK_PROCESS_CPUTIME_ID);
times.CLOCK_THREAD_CPUTIME_ID.time   = t.clock_gettime(t.CLOCK_THREAD_CPUTIME_ID);
times.CLOCK_THREAD_CPUTIME_ID.res    = t.clock_getres(t.CLOCK_THREAD_CPUTIME_ID);
console.log(times);

var count = 1500000;
console.log('Now running "t.clock_gettime(t.CLOCK_MONOTONIC_RAW)" ' + count + " times.");

var start = t.clock_gettime(t.CLOCK_MONOTONIC_RAW);
for (var ii = 0; ii < count; ii++) {
  t.clock_gettime(t.CLOCK_MONOTONIC_RAW);
}
var end = t.clock_gettime(t.CLOCK_MONOTONIC_RAW);

var totalns = t.to_ns(t.diff(start,end));
var totalus = t.to_us(t.diff(start,end));
var totalms = t.to_ms(t.diff(start,end));
console.log('Done in ' + totalns + ' nanoseconds.');
console.log('or ' + totalus + ' microseconds.');
console.log('or ' + totalms + ' milliseconds.');
console.log('or ' + totalns / count + ' ns per query');

  {
  'targets': [{
    'target_name': 'clock_gettime',
    'sources': [ 
      'src/addon.cpp',
      'src/clock_gettimejs.cpp'
    ],
    'cflags!': [ '-fno-exceptions'],
    'cflags_cc!': [ '-fno-exceptions'],
  }]
}
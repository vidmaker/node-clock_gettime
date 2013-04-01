#include <node.h>
#include <v8.h>

//void reportError(v8::TryCatch& try_catch){
//    printf(*v8::String::Utf8Value(try_catch.StackTrace()));
//}
//bea::reportExceptionCb bea::Global::reportException = reportError;

namespace clock_gettimejs {
  class Project {
    public:
      static void expose(v8::Handle<v8::Object> target);
  };
}

extern "C" {
  static void init (v8::Handle<v8::Object> target) {
    v8::HandleScope scope;
    clock_gettimejs::Project::expose(target);
  }
  NODE_MODULE(clock_gettime, init);
}

#ifndef CLOCK_GETTIMEJS_H
#define CLOCK_GETTIMEJS_H
#include <v8.h>
namespace clock_gettimejs {
	class Jclock_gettimejs {
		protected:
			//Exported methods
			static v8::Handle<v8::Value> clock_getres(const v8::Arguments& args);
			static v8::Handle<v8::Value> clock_gettime(const v8::Arguments& args);
		public:
			static void _InitJSObject(v8::Handle<v8::Object> target);
	};
	
}

namespace clock_gettimejs {
	static void ExposeConstants(v8::Handle<v8::Object> target);
}

namespace clock_gettimejs {
	class Project {
		public:
			static void expose(v8::Handle<v8::Object> target);
	};
	
}

#endif //#ifndef CLOCK_GETTIMEJS_H
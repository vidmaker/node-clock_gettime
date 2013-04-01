#include "bea.h"
#include "clock_gettimejs.h"
#include "clock_gettimejs_impl.h"
namespace bea {
	template<> struct Convert<clock_gettimejs::timespec> {
		static bool Is(v8::Handle<v8::Value> v) {
			return !v.IsEmpty() && v->IsObject();
		}
		
		static clock_gettimejs::timespec FromJS(v8::Handle<v8::Value> v, int nArg) {
			const char* msg = "Object with the following properties expected: tv_sec, tv_nsec. This will be cast to 'clock_gettimejs::timespec'";
			if (!Is(v)) BEATHROW();
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v->ToObject();
			clock_gettimejs::timespec ret;
			ret.tv_sec = bea::Convert<clock_gettimejs::time_t>::FromJS(obj->Get(v8::String::NewSymbol("tv_sec")), nArg);
			ret.tv_nsec = bea::Convert<long>::FromJS(obj->Get(v8::String::NewSymbol("tv_nsec")), nArg);
			return ret;
		}
		
		static v8::Handle<v8::Value> ToJS(clock_gettimejs::timespec const& v) {
			v8::HandleScope scope;
			v8::Local<v8::Object> obj = v8::Object::New();
			obj->Set(v8::String::NewSymbol("tv_sec"), bea::Convert<clock_gettimejs::time_t>::ToJS(v.tv_sec));
			obj->Set(v8::String::NewSymbol("tv_nsec"), bea::Convert<long>::ToJS(v.tv_nsec));
			return scope.Close(obj);
		}
		
	};
	
}

DECLARE_STATIC(clock_gettimejs::Jclock_gettimejs);
namespace clock_gettimejs {
	v8::Handle<v8::Value> Jclock_gettimejs::clock_getres(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//timespec clock_getres(int clk_id)
		int clk_id = bea::Convert<int>::FromJS(args[0], 0);
		THROW_IF_NOT(clk_id >= 0, "Invalid clk_id");
		THROW_IF_NOT(clk_id < 10, "Invalid clk_id");
		clock_gettimejs::timespec fnRetVal = clock_gettimejs::clock_getres(clk_id);
		return bea::Convert<clock_gettimejs::timespec>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	v8::Handle<v8::Value> Jclock_gettimejs::clock_gettime(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		//timespec clock_gettime(int clk_id)
		int clk_id = bea::Convert<int>::FromJS(args[0], 0);
		THROW_IF_NOT(clk_id >= 0, "Invalid clk_id");
		THROW_IF_NOT(clk_id < 10, "Invalid clk_id");
		clock_gettimejs::timespec fnRetVal = clock_gettimejs::clock_gettime(clk_id);
		return bea::Convert<clock_gettimejs::timespec>::ToJS(fnRetVal);
		METHOD_END();
	}
	
	void Jclock_gettimejs::_InitJSObject(v8::Handle<v8::Object> target) {
		bea::ExposedStatic<Jclock_gettimejs>* obj = EXPOSE_STATIC(Jclock_gettimejs, "clock_gettimejs");
		//Exposed Methods
		obj->exposeMethod("clock_getres", clock_getres);
		obj->exposeMethod("clock_gettime", clock_gettime);
		//Accessors
		//Expose object to the Javascript
		obj->exposeTo(target);
	}
	
}

namespace clock_gettimejs {
	void ExposeConstants(v8::Handle<v8::Object> target) {
		BEA_DEFINE_CONSTANT(target, CLOCK_REALTIME);
		BEA_DEFINE_CONSTANT(target, CLOCK_REALTIME_COARSE);
		BEA_DEFINE_CONSTANT(target, CLOCK_MONOTONIC);
		BEA_DEFINE_CONSTANT(target, CLOCK_MONOTONIC_COARSE);
		BEA_DEFINE_CONSTANT(target, CLOCK_MONOTONIC_RAW);
		BEA_DEFINE_CONSTANT(target, CLOCK_BOOTTIME);
		BEA_DEFINE_CONSTANT(target, CLOCK_PROCESS_CPUTIME_ID);
		BEA_DEFINE_CONSTANT(target, CLOCK_THREAD_CPUTIME_ID);
	}
	
}

namespace clock_gettimejs {
	void Project::expose(v8::Handle<v8::Object> target) {
		Jclock_gettimejs::_InitJSObject(target);
		ExposeConstants(target);
	}
	
}

#include <napi.h>
using namespace std;

namespace simpleMathFunctions {

    std::string add(float a, float b);
    Napi::String AddWrapped(const Napi::CallbackInfo& info);

    float addN(float a, float b);
    Napi::Number AddNWrapped(const Napi::CallbackInfo& info);

    float subtract(float a, float b);
    Napi::Number SubtactWrapped(const Napi::CallbackInfo& info);

    float multiply(float a, float b);
    Napi::Number MultiplyWrapped(const Napi::CallbackInfo& info);

    float devide(float a, float b);
    Napi::Number DevideWrapped(const Napi::CallbackInfo& info);

    // int getPrecisionMultiplier(float a, float b);
    // Napi::Number DevideWrapped(const Napi::CallbackInfo& info);


    Napi::Object Init(Napi::Env env, Napi::Object exports);
    
}

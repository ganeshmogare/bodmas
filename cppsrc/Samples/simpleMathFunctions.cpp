#include "simpleMathFunctions.h"
#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;
// int getDecimalLength(float n) {
//     // num = num.toString();
//     // int dotIndex = num.indexOf('.');
//     ostringstream m; 
//     m << n; 
//     num = m.str();
//     std::string str = num;
//     std::size_t dotIndex = str.find(".");
//     if (dotIndex == -1) return 0;
//     return num.substr(dotIndex + 1, num.length()).length();
// }
int numberOfDecimals(float num){

    
    std::string s;
std::string t;
std::stringstream out;
out << num;
s = out.str();
t = s.substr(s.find(".")+1);
return t.length();
}
// int simpleMathFunctions::getPrecisionMultiplier(float a,float b) {
//     // adding one more to be safer
//     int addNZeros = 0;
//     int biggestDecimal = 0;
//     // nums.forEach(num => {
//     //     biggestDecimal = Math.max(getDecimalLength(num), biggestDecimal);
//     // });
//      biggestDecimal =std::max(numberOfDecimals(a), biggestDecimal);// Math.max(getDecimalLength(a), biggestDecimal);
//       biggestDecimal = std::max(numberOfDecimals(b), biggestDecimal);
//     return pow(10, biggestDecimal + addNZeros);
// }

int getPrecisionMultiplier(float a,float b) {
    // adding one more to be safer
    int addNZeros = 0;
    int biggestDecimal = 0;
    // nums.forEach(num => {
    //     biggestDecimal = Math.max(getDecimalLength(num), biggestDecimal);
    // });
     biggestDecimal =std::max(numberOfDecimals(a), biggestDecimal);// Math.max(getDecimalLength(a), biggestDecimal);
      cout <<" biggestDecimal "<< biggestDecimal <<endl;
      biggestDecimal = std::max(numberOfDecimals(b), biggestDecimal);
      cout <<" biggestDecimal "<< biggestDecimal <<endl;
    return pow(10, biggestDecimal + addNZeros);
}



std::string simpleMathFunctions::add(float a, float b){
    //  int precesion = getPrecisionMultiplier(a,b);
    //  cout <<" precesion " << precesion<<endl;
//   return (precesion *a + b* precesion)/precesion;
 std::string sum;
 std::stringstream out;
float c = a+b;
out << c;
sum = out.str();
cout << "c= "<< sum<< endl;
return sum;
// return a+b;
}

float simpleMathFunctions::addN(float a, float b){

float c = a+b;
cout << "c= "<< c<< endl;
float d;
d = c+1-1;
return d;
// return a+b;
}

float simpleMathFunctions::subtract(float a, float b){
  return a - b;
}

float simpleMathFunctions::multiply(float a, float b){
  return a * b;
}

float simpleMathFunctions::devide(float a, float b){
  return a / b;
}





Napi::String simpleMathFunctions::AddWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } 

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    std::string returnValue = simpleMathFunctions::add(first.FloatValue(), second.FloatValue());
    cout << " hello ganesh =" << returnValue << endl;
    return Napi::String::New(env, returnValue);
}

Napi::Number simpleMathFunctions::AddNWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } 

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    float returnValue = simpleMathFunctions::addN(first.FloatValue(), second.FloatValue());
    cout << " hello ganesh =" << returnValue << endl;
    return Napi::Number::New(env, returnValue);
}

// Napi::Number simpleMathFunctions::PrecesionWrapped(const Napi::CallbackInfo& info) {
//     Napi::Env env = info.Env();
//     if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
//         Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
//     } 

//     Napi::Number first = info[0].As<Napi::Number>();
//     Napi::Number second = info[1].As<Napi::Number>();

//     float returnValue = simpleMathFunctions::getPrecisionMultiplier(first.FloatValue(), second.FloatValue());
    
//     return Napi::Number::New(env, returnValue);
// }

Napi::Number simpleMathFunctions::SubtactWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } 

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    float returnValue = simpleMathFunctions::subtract(first.FloatValue(), second.FloatValue());
    
    return Napi::Number::New(env, returnValue);
}

Napi::Number simpleMathFunctions::MultiplyWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } 

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    float returnValue = simpleMathFunctions::multiply(first.FloatValue(), second.FloatValue());
    
    return Napi::Number::New(env, returnValue);
}

Napi::Number simpleMathFunctions::DevideWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } 

    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();

    float returnValue = simpleMathFunctions::devide(first.FloatValue(), second.FloatValue());
    
    return Napi::Number::New(env, returnValue);
}

Napi::Object simpleMathFunctions::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("add", Napi::Function::New(env, simpleMathFunctions::AddWrapped));
    exports.Set("subtract", Napi::Function::New(env, simpleMathFunctions::SubtactWrapped));
    exports.Set("multiply", Napi::Function::New(env, simpleMathFunctions::MultiplyWrapped));
    exports.Set("devide", Napi::Function::New(env, simpleMathFunctions::DevideWrapped));
    exports.Set("addN", Napi::Function::New(env, simpleMathFunctions::AddNWrapped));
    // exports.Set("getPrecisionMultiplier", Napi::Function::New(env, simpleMathFunctions::PrecesionWrapped));
    return exports;
}

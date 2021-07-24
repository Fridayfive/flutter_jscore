#include <atomic>
#include <deque>
#include <vector>
#include <string>
#include <codecvt>
#include <locale>
#include <iostream>
#include "JavaScript.h"

namespace JSC
{
    using JSExceptionHandler = std::function<void(int32_t contextId, const char *errmsg)>;
    class NativeString;
    class JSBridge final
    {
    private:
        /* data */
    public:

        JSBridge(/* args */) = delete;
        JSBridge(int32_t jsContext, const JSExceptionHandler &handler);
        ~JSBridge();

        void evaluateScript(const NativeString *script,const char *url,int startLine);
        void evaluateScript(const std::u16string &script,const char *url,int starLine);
    };

    JSBridge::JSBridge(/* args */)
    {
    }

    JSBridge::~JSBridge()
    {
    }

}
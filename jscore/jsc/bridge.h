//
// Created by friday on 2021/7/21.
//

#ifndef FLUTTER_JSC_AFC_BRIDGE_H
#define FLUTTER_JSC_AFC_BRIDGE_H

#include <string>
#include <vector>
#include <map>
#include "JavaScriptCore/JavaScript.h"
using namespace std;
class JSCBridge
{
public:
    //执行js方法
    void evaluateScript(string js, uint8_t contextId, JSObjectCallAsFunctionCallback callback);

    JSCBridge()
    {
        init();
    };
    ~JSCBridge();

private:
    /*！用于记录调用进来的方法id，根据id向dart 返回执行结果*/
    map<uint8_t, string> contextContainer;

    /*! @typedef JSContextRef A JavaScript execution context. Holds the global object and other execution state. */
    JSContextGroupRef contextGroup;

    /*! @typedef JSContextRef A JavaScript execution context. Holds the global object and other execution state. */
    JSGlobalContextRef globalContext;

    JSObjectRef globalObject;

    //初始化 Bridge 对象
    void init();
};

#endif //FLUTTER_JSC_AFC_BRIDGE_H

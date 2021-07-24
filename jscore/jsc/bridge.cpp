//
// Created by friday on 2021/7/21.
//
#include "bridge.h"
extern "C"
{
#include "JavaScriptCore/JavaScript.h"
}
#include "log/jsc_log.h"
#include <sstream>

extern "C"
{

    JSValueRef ObjectCallAsFunctionCallback(JSContextRef ctx, JSObjectRef function, JSObjectRef thisObject, size_t argumentCount, const JSValueRef arguments[], JSValueRef *exception)
    {
        LOGI("调用成功");
        return JSValueMakeUndefined(ctx);
    }

    void initJSC()
    {
        JSCBridge *afc = new JSCBridge();
        afc->evaluateScript("log", 21, &ObjectCallAsFunctionCallback);
    }

    void JSCBridge::init()
    {
        this->contextContainer.clear();
        this->contextGroup = JSContextGroupCreate();
        this->globalContext = JSGlobalContextCreateInGroup(contextGroup, NULL);
        this->globalObject = JSContextGetGlobalObject(globalContext);
        //this->evaluateScript()
    }

    void JSCBridge::evaluateScript(string js, uint8_t contextId, JSObjectCallAsFunctionCallback callback)
    {
        // char *funName = strcpy(funName, js.c_str());
        // JSObjectRef functionObject = JSObjectMakeFunctionWithCallback(this->globalContext, JSStringCreateWithUTF8CString("log"), &ObjectCallAsFunctionCallback);
        // JSObjectSetProperty(this->globalContext, this->globalObject, JSStringCreateWithUTF8CString("log"), functionObject, kJSPropertyAttributeNone, NULL);
        JSValueRef ref = JSEvaluateScript(this->globalContext, JSStringCreateWithUTF8CString("var obj=0;log()"), NULL, NULL, 1, NULL);
        bool valueType = JSValueIsBoolean(this->globalContext, ref);
        if(valueType){
            LOGI("true");
        }else{
            LOGI("false");
        }
        // ostringstream res;
        // res << valueType;
        // LOGI(string(res.str()).c_str);
    }
}

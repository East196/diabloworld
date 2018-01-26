#include "ProcessJni.h"
#include "json.h"
#include "SocketManager.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif

static ProcessJni *pJni=NULL;

ProcessJni *ProcessJni::getInstance()
{
    if(!pJni)
    {
        pJni=new ProcessJni();
    }
    return pJni;
}

void ProcessJni::startCallJni()
{
    const char *UserInfo="";
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo minfo;
    jobject jobj;
    jstring info;
    if(JniHelper::getStaticMethodInfo(minfo,"org/com/tsDemo/tsDemo","checkProcesses", "()V"))
    {
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
    
    if(JniHelper::getStaticMethodInfo(minfo,"org/com/TestFirst/UserData","returnData", "()Ljava/lang/String;"))
    {
        info=(jstring)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
        CCLog("%s",minfo.env->GetStringUTFChars(info,false));
        UserInfo=minfo.env->GetStringUTFChars(info,false);
        minfo.env->ReleaseStringUTFChars(info, UserInfo);
    }

#endif
    CCLog("%s",UserInfo);
    CCHttpRequest *request=new CCHttpRequest();
    request->setUrl("http://192.168.1.15:11008/test2");
    request->setRequestType(CCHttpRequest::kHttpPost);
    std::vector<std::string> headers;
    headers.push_back("Content-Type: application/json; charset=utf-8");
    request->setHeaders(headers);
    request->setResponseCallback(this, callfuncND_selector(ProcessJni::httpReqFinished));
    const char* postData ="ip=192.168.10.10&time=2013/10/11";
    CCLog("%s",postData);
    request->setRequestData(postData, strlen(postData));
    CCLog("%ld",strlen(postData));
    request->setTag("UserData");
    CCHttpClient::getInstance()->send(request);
    request->release();
    CCLog("sending........--");
}

void ProcessJni::httpReqFinished(CCNode *node,void *data)
{
    CCHttpResponse *response = (CCHttpResponse*)data;
    if(!response->isSucceed())
    {
        CCLog("Connection failed");
    }
    else
    {
        int codeIndex=response->getResponseCode();
        CCLog("%d",codeIndex);
        CCLog("lllllllllll");
        const char* tag=response->getHttpRequest()->getTag();
        CCLog("%s",tag);
        CCLog("Succeed!!!");
        std::vector<char>* buffer=response->getResponseData();
        std::string temp(buffer->begin(),buffer->end());
        CCString* responseData=CCString::create(temp);
        CCLog("%s",responseData->getCString());
    }
}
#include "main.h"


ECallApp::ECallApp()
{
    init();
}
ECallApp::~ECallApp() {}

void ECallApp::init()
{
    mAudio = make_shared<Audio>();
    if(mAudio != nullptr)
    {
        //mUAE = make_shared<UAE>(mAudio);
        mUAE = make_shared<UAE>(mAudio);
        //mJapan = make_shared<Japan>(mAudio);
        mJapan = make_shared<Japan>(mAudio);
    }
    
}

void ECallApp::doTest()
{
    mCountApp = 16;
    cout<<"mCountApp = %d"<<mCountApp<<endl;
}

void ECallApp::StartBoot()
{

    cout<<"Boot completed"<<endl;
}

UAE::UAE(const shared_ptr<Audio>& audio)
{
    mAudio1 = audio;
}
UAE::~UAE() {}

Japan::Japan(const shared_ptr<Audio>& audio)
{
    mAudio2 = audio;
}
Japan::~Japan() {}

void UAE::StartUAE()
{
    cout<<"Start UAE Call"<<endl;
    mAudio1->muteAudio();
    //mCountApp = 7;
    //cout<<"mCountApp = %d"<<mCountApp<<endl;
    mCountUAE = 3;
    cout<<"mCountUAE = %d"<<mCountUAE<<endl;
}
void Japan::StartJapan()
{
    cout<<"Start Japan Call"<<endl;
    mAudio2->muteAudio();
    //mCountApp = 9;
    //cout<<"mCountApp = %d"<<mCountApp<<endl;
    mCountJapan= 8;
    cout<<"mCountJapan = %d"<<mCountJapan<<endl;
}
Audio::Audio()
{}

Audio::~Audio() {}
void Audio::muteAudio()
{
    cout<<"Mute Audio"<<endl;
}

int main()
{
    ECallApp *eCall = new ECallApp();
    eCall->mJapan->StartJapan();
    eCall->doTest();
    eCall->mUAE->StartUAE();

    return 0;
}



////


#ifndef _MAIN_
#define _MAIN_

#include <iostream>
#include <memory>

using namespace std;

class UAE;
class Japan;
class Audio
{
public:
    Audio();
    virtual ~Audio();
    void muteAudio();


};
class IECallApp
{
public:
    //virtual void StartUAE() = 0 ;
    //virtual void StartJapan() = 0;
    virtual void StartBoot() = 0;
};

class ECallApp : public IECallApp
{
public:

    shared_ptr<Audio> mAudio = nullptr;
    shared_ptr<UAE> mUAE = nullptr;
    shared_ptr<Japan> mJapan = nullptr;
protected:

public:
    uint16_t mCountApp = 0;
    ECallApp();
    virtual ~ECallApp();
    void init();
    void StartBoot();
    //virtual void StartUAE() ;
    //virtual void StartJapan();
    void doTest();

};

class Japan : public ECallApp
//class Japan : public IECallApp
{
private:
    uint16_t mCountJapan = 0;
    shared_ptr<Audio> mAudio2;
public:
    Japan(const shared_ptr<Audio>& audio);
    virtual ~Japan();
    void init();
    //virtual void StartBoot();
    //virtual void StartUAE() ;
    //virtual void StartJapan();
    void StartUAE() ;
    void StartJapan();
};
class UAE : public ECallApp
//class UAE : public IECallApp
{
private:
    shared_ptr<Audio> mAudio1;
    uint16_t mCountUAE = 0;
public:
    UAE(const shared_ptr<Audio>& audio);
    virtual ~UAE();
    void init();
    //virtual void StartBoot();
    //virtual void StartUAE() ;
    //virtual void StartJapan();
    void StartUAE() ;
    void StartJapan();
};




#endif //_MAIN_

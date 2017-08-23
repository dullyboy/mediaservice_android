#ifndef TVMEDIACLIENT_H
#define TVMEDIACLIENT_H
  
#include "ITVMediaClient.h"  
#include "TVMediaClient.h"  
#include "IPTVMediaClient.h"  
/**********************************************/  
/*! @class ITVMediaClient 
  @brief TVMedia Service Proxy Interface class 
 ***********************************************/  
class IPTVMediaClient;

class TVMediaClient : public BnTVMediaClient
{ 
    public:  
        static void instantiate();  
        TVMediaClient(IPTVMediaClient *iptvMClient);
        ~TVMediaClient();
        void notify(int msg, int ext1, int ext2, const Parcel *obj = NULL);        
        void getUrl(int id);
        void mediaMsg(char *msg);

    private:
        IPTVMediaClient *m_iptvMClient;
}; 

#endif

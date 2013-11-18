#include "ns3/Sender.h"
#include <vector>

	Sender::Sender(ns3::Ptr<CcnModule> ccnm,int waitingTime)
	{
		this->ccnm=ccnm;
		this->waitingTime=waitingTime;
		//dose FIb eggrafes kai onomata
	}

	Sender::~Sender()
	{

	}

	    void Sender::AnnounceName(ns3::Ptr<CCN_Name> name)
		{
			this->ccnm->announceName(name, this);
		}



		void Sender::InterestReceived(ns3::Ptr<CCN_Name> ccnn)
		{
			//std::cout<<"------------------Interest received: "<<ccnn->getValue()<<std::endl;
			ns3::Time t=ns3::Seconds(this->waitingTime);

			if(data.find(ccnn)->second==0)
			{
				std::cout<<"NUL!!!!!!!!!!!!!!!!!!!!!!!!!!!";
			}
		//	std::cout<<"ONOMA:      "<<ccnn->getValue()<<std::endl;
			char* test=data.find(ccnn)->second;

			ns3::Simulator::Schedule(t,&Sender::SendData,this,ccnn,test,length.find(ccnn)->second);
		}

		void Sender::SendData(ns3::Ptr<CCN_Name> data, char* buff, int bufflen)
		{
			this->ccnm->sendData( data, buff, bufflen);
		}

		ns3::TypeId Sender::GetTypeId(void)
		{
			static ns3::TypeId t=ns3::TypeId("SENDER");
			t.SetParent<Object>();
			//t.AddConstructor<CCNPacketSizeHeader>();

			return t;
		}

		ns3::TypeId Sender::GetInstanceTypeId(void) const
		{
			return GetTypeId();
		}

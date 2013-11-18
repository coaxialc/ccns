#include "ns3/Receiver.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "boost/lexical_cast.hpp"

		Receiver::Receiver(ns3::Ptr<CcnModule> ccnm)
		{
			this->ccnm=ccnm;
		}

		Receiver::~Receiver()
		{

		}

		void Receiver::DataArrived(ns3::Ptr<CCN_Name> data, char* buff, int bufflen)
		{
		//	std::cout<<"Data arrived , "<<data->getValue()<<std::endl;
		}


		void Receiver::SendInterest(ns3::Ptr<CCN_Name> name,int num)
		{
			unsigned num2=num;
			for(unsigned i=0;i<num2;i++)
			{
				std::string keimeno=static_cast<ostringstream*>( &(ostringstream() << i) )->str();

				std::string temporary=name->getValue().substr(1,name->getValue().length()-2)+"/"+keimeno;
				static std::string* name3=&temporary;
				Ptr<CCN_Name> name4=Text::getPtr()->giveText(name3);

				this->ccnm->sendInterest(name4, this);
			}
		}

		ns3::TypeId Receiver::GetTypeId(void)
		{
			static ns3::TypeId t=ns3::TypeId("RECEIVER");
			t.SetParent<Object>();
			//t.AddConstructor<CCNPacketSizeHeader>();

			return t;
		}

		ns3::TypeId Receiver::GetInstanceTypeId(void) const
		{
			return GetTypeId();
		}

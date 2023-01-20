














#include <unistd.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <fstream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>			
#include <boost/foreach.hpp>


#include <regex>



#include <boost/array.hpp>

using namespace std;
namespace pt = boost::property_tree;

extern string web_service_wert_rueckgabe;
extern string sapcontrol_monitor_name_extern;
extern int icinga_retun_code;
extern string rueckgabe_nachricht;
extern string parameter;		
extern string cert_subject;
extern string cert_valud_until;
extern string sapgenpse_parameter;
extern vector<string> certlist_array;

extern string type_extern;
extern string heap_memory_size;

void xml_extract()

{


	
	
	
	
	std::smatch reg_match;		
	
	boost::property_tree::ptree pt;

	
	
	
        
	istringstream iss(web_service_wert_rueckgabe);
		
    read_xml(iss, pt);
	
	
	
	int wo_ist_sapcontrol_response_abschnitt = - 1;
	wo_ist_sapcontrol_response_abschnitt = web_service_wert_rueckgabe.find("SAPControl:");
	
	
	int wo_ist_type = - 1;
	wo_ist_type = type_extern.find("=");
	type_extern = type_extern.substr(wo_ist_type + 1, type_extern.length());
	


	std::regex regex_1("^-javashow$");
	if (std::regex_search(parameter, reg_match, regex_1))
	{
		
		int wo_ist_item_anfang = - 1;
		int wo_ist_item_ende = - 1;
		string item_wert ;
		
		
		
		
		
		bool anzeige = false;
		while(1)
		{			
			wo_ist_item_anfang = web_service_wert_rueckgabe.find("<item>");
			
			wo_ist_item_ende = web_service_wert_rueckgabe.find("</item>");
			
			
			
			
			
			
			
			
			try{item_wert = web_service_wert_rueckgabe.substr(wo_ist_item_anfang + 6,wo_ist_item_ende - wo_ist_item_anfang );}catch( std::out_of_range& exception ){cout<<"Error xml_extract.cpp std::out_of_range"<<endl;exit(0);}
			
			
			try{web_service_wert_rueckgabe = web_service_wert_rueckgabe.substr(wo_ist_item_ende + 7, web_service_wert_rueckgabe.length());}catch( std::out_of_range& exception ){cout<<"Error xml_extract.cpp std::out_of_range"<<endl;exit(0);}
			
			if (item_wert == "WEBMETHODS</item")
			{
				
				anzeige = true;
				
			}
			if (item_wert == "EXITCODES</item")
			{
				
				anzeige = false;
			}
			if (anzeige == true)
			{
				
				try{item_wert = item_wert.substr(0 , item_wert.length() - 6 );}catch( std::out_of_range& exception ){cout<<"Error xml_extract.cpp std::out_of_range"<<endl;exit(0);}
				
				
				
				
				
				
				
				
				
				std::string result;				
				std::regex e ("&lt");
				
				std::regex_replace (std::back_inserter(result), item_wert.begin(), item_wert.end(), e, "<");
				
				std::string result_2;				
				std::regex e_2 ("&gt");
				std::regex_replace (std::back_inserter(result_2), result.begin(), result.end(), e_2, ">");
				
				std::string result_3;				
				std::regex e_3 (";");
				std::regex_replace (std::back_inserter(result_3), result_2.begin(), result_2.end(), e_3, "");
				std::cout << result_3<<endl;
				
			}
			if (item_wert == "")
			{
				
				
				break;
			}
			
			
			
			
			
			

		}
		
		exit(0);
	}

	

	
	
	int wo_ist_GetProcessListResponse = - 1;
	wo_ist_GetProcessListResponse = web_service_wert_rueckgabe.find("<SAPControl:GetProcessListResponse>");	
	
	
	int wo_ist_exitcode_null = - 1;
	wo_ist_exitcode_null = web_service_wert_rueckgabe.find("<exitcode>0</exitcode>");
	
	
	
	int wo_ist_GetAlertsResponse = - 1;
	wo_ist_GetAlertsResponse = web_service_wert_rueckgabe.find("<SAPControl:GetAlertsResponse>");	
	
	
	int wo_ist_exit_code = - 1;
	wo_ist_exit_code = web_service_wert_rueckgabe.find("<exitcode>11</exitcode>");	
	
	
	int wo_ist_GetAlertTreeResponse = - 1;
	wo_ist_GetAlertTreeResponse = web_service_wert_rueckgabe.find("<SAPControl:GetAlertTreeResponse>");	
	
	
	int wo_ist_J2EEGetProcessListResponse = - 1;
	wo_ist_J2EEGetProcessListResponse = web_service_wert_rueckgabe.find("<SAPControl:J2EEGetProcessListResponse>");	
	
	
	int wo_ist_J2EEGetComponentListResponse = - 1;
	wo_ist_J2EEGetComponentListResponse = web_service_wert_rueckgabe.find("<SAPControl:J2EEGetComponentListResponse>");	
	
	
	int wo_ist_J2EEGetVMHeapInfoResponse = - 1;
	wo_ist_J2EEGetVMHeapInfoResponse = web_service_wert_rueckgabe.find("<SAPControl:J2EEGetVMHeapInfoResponse>");	
	
	
	

	if (wo_ist_exit_code > - 1)
	{
		
		cout<<"\nFehler: ";
		cout<<web_service_wert_rueckgabe<<endl;
		
		
		return;							
		
		
	}

	
	
	
	
	

	if (wo_ist_GetProcessListResponse == - 1 && wo_ist_exitcode_null == - 1 && wo_ist_GetAlertsResponse == - 1 && wo_ist_GetAlertTreeResponse == - 1 && wo_ist_J2EEGetProcessListResponse == - 1 && wo_ist_J2EEGetComponentListResponse == - 1 && wo_ist_J2EEGetVMHeapInfoResponse == - 1)
		{
			
			
			
			
			cout<<"Fehler: ";
			cout<<web_service_wert_rueckgabe<<endl;
			icinga_retun_code = 2;
			exit(icinga_retun_code);
		}

	
	
	if(wo_ist_sapcontrol_response_abschnitt > -1)
	{
		
		string sapcontrol_command_response;
		sapcontrol_command_response = web_service_wert_rueckgabe.substr(wo_ist_sapcontrol_response_abschnitt, web_service_wert_rueckgabe.length());
		
		
		wo_ist_sapcontrol_response_abschnitt = - 1;
		wo_ist_sapcontrol_response_abschnitt = sapcontrol_command_response.find(">");
		
		sapcontrol_command_response = sapcontrol_command_response.substr(11,wo_ist_sapcontrol_response_abschnitt - 11);
		
		
		
		
		
		
		

		int wo_ist_gleich = - 1;
		wo_ist_gleich = sapcontrol_monitor_name_extern.find("=");
		sapcontrol_monitor_name_extern = sapcontrol_monitor_name_extern.substr(wo_ist_gleich + 1,sapcontrol_monitor_name_extern.length());
		
		
		int item_gefunden = - 1 ;
		int intem_status_gray = - 1;
		int intem_status_red = - 1;
		int intem_status_yellow = - 1;
		int intem_status_green = - 1;
		
		bool name_gefunden =  false;			
		bool object_gefunden =  false;			

		if (sapcontrol_command_response == "GetProcessListResponse" )
		{
			
			BOOST_FOREACH (boost::property_tree::ptree::value_type &wert_typ,pt.get_child("SOAP-ENV:Envelope.SOAP-ENV:Body.SAPControl:GetProcessListResponse.process")) 
			{
				if (wert_typ.first == "item") 
				{
					auto name = wert_typ.second.get<std::string>("name");
					auto textstatus = wert_typ.second.get<std::string>("textstatus");
					auto dispstatus = wert_typ.second.get<std::string>("dispstatus");

					item_gefunden = - 1;
					item_gefunden = name.find(sapcontrol_monitor_name_extern);
					
					
					
					
					if (item_gefunden > - 1)			
					{
						
						name_gefunden = true;						
						
						cout<<name;
					
						intem_status_gray = - 1;
						intem_status_gray = dispstatus.find("SAPControl-GRAY");
						
						if (intem_status_gray > -1)
						{
							cout<<" | GRAY ";
							
							cout<<" | "<<textstatus<<endl;
							
							icinga_retun_code = 2;
							break;
						}

						intem_status_red = - 1;
						intem_status_red = dispstatus.find("SAPControl-RED");
						
						if (intem_status_red > -1)
						{
							cout<<" | RED ";
							
							cout<<" | "<<textstatus<<endl;
							
							icinga_retun_code = 2;
							break;
						}

						intem_status_yellow = - 1;
						intem_status_yellow = dispstatus.find("SAPControl-YELLOW");
						
						if (intem_status_yellow > -1)
						{
							cout<<" | YELLOW ";
							
							cout<<" | "<<textstatus<<endl;
							
							icinga_retun_code = 1;
							break;
						}

						intem_status_green = - 1;
						intem_status_green = dispstatus.find("SAPControl-GREEN");
						
						if (intem_status_green > -1)
						{
							cout<<" | GREEN ";
							
							cout<<" | "<<textstatus<<endl;
							
							icinga_retun_code = 0;
							break;
						}				
											

						intem_status_gray = - 1;
						intem_status_red = - 1;
						intem_status_yellow = - 1;
						intem_status_green = - 1;

						break;
					}
					
					
					
					
					
					
					
					
					
				}
				else
				{
					std::cout << "skipped: '" << wert_typ.first << "'\n";
				}

			}
			
			if (name_gefunden == false)
			{
				cout<<"Prozess: "<<sapcontrol_monitor_name_extern<<" nicht gefunden"<<endl;
				cout<<"SAP System gestoppt"<<endl;
				icinga_retun_code = 2;
			}			
		}



		if (sapcontrol_command_response == "GetAlertsResponse" )
		{
			
			BOOST_FOREACH (boost::property_tree::ptree::value_type &wert_typ,pt.get_child("SOAP-ENV:Envelope.SOAP-ENV:Body.SAPControl:GetAlertsResponse.alert")) 
			{
				if (wert_typ.first == "item") 
				{
					auto name = wert_typ.second.get<std::string>("Object");
					auto textstatus = wert_typ.second.get<std::string>("Description");
					auto dispstatus = wert_typ.second.get<std::string>("Value");
					
					
					


					item_gefunden = - 1;
					item_gefunden = name.find(sapcontrol_monitor_name_extern);
					
					
					
					if (item_gefunden > -1)			
					{
						object_gefunden =  true;
						
						
						
						
						
						cout<<name;
					
						intem_status_gray = - 1;
						intem_status_gray = dispstatus.find("SAPControl-GRAY");
						
						if (intem_status_gray > -1)
						{
							cout<<" | GRAY ";
							
							cout<<" | "<<textstatus<<endl;
							
							icinga_retun_code = 2;
							break;
						}

						intem_status_red = - 1;
						intem_status_red = dispstatus.find("SAPControl-RED");
						
						if (intem_status_red > -1)
						{
							cout<<" | RED ";
							
							cout<<" | "<<textstatus<<endl;
							
							icinga_retun_code = 2;
							break;
						}

						intem_status_yellow = - 1;
						intem_status_yellow = dispstatus.find("SAPControl-YELLOW");
						
						if (intem_status_yellow > -1)
						{
							cout<<" | YELLOW ";
							
							cout<<" | "<<textstatus<<endl;
							
							icinga_retun_code = 1;
							break;
						}

						intem_status_green = - 1;
						intem_status_green = dispstatus.find("SAPControl-GREEN");
						
						if (intem_status_green > -1)
						{
							cout<<" | GREEN ";
							
							cout<<" | "<<textstatus<<endl;
							
							icinga_retun_code = 0;
							break;
						}				
											

						intem_status_gray = - 1;
						intem_status_red = - 1;
						intem_status_yellow = - 1;
						intem_status_green = - 1;

						break;
					}
					
					
				}
				else
				{
					std::cout << "skipped: '" << wert_typ.first << "'\n";
				}
			}
			if (object_gefunden == false)
			{
				cout<<"Monitor: \'"<<sapcontrol_monitor_name_extern<<"\' nicht gefunden"<<endl;
				
				icinga_retun_code = 2;
			}	
		}

		


		if (sapcontrol_command_response == "OSExecuteResponse" )
		{
			
			
			
			
			int wo_ist_item_anfang = - 1;
			int wo_ist_item_ende = - 1;
			
			string item_wert ;
			
			bool anzeige = false;
			
			

			std::regex regex_3("^maintain_pk -l $");
			std::regex regex_4("^get_my_name $");

			
			if (std::regex_search(sapgenpse_parameter, reg_match, regex_4))
			{
				bool weil_tru = true;
				while(weil_tru)
				{			
					wo_ist_item_anfang = web_service_wert_rueckgabe.find("<item>");
					wo_ist_item_ende = web_service_wert_rueckgabe.find("</item>");
					
					try{item_wert = web_service_wert_rueckgabe.substr(wo_ist_item_anfang + 6,wo_ist_item_ende - wo_ist_item_anfang );}catch( std::out_of_range& exception ){cout<<"Error xml_extract.cpp std::out_of_range"<<endl;exit(0);}
					
					
					try{web_service_wert_rueckgabe = web_service_wert_rueckgabe.substr(wo_ist_item_ende + 7, web_service_wert_rueckgabe.length());}catch( std::out_of_range& exception ){cout<<"Error xml_extract.cpp std::out_of_range"<<endl;exit(0);}
					
					
					
					
					std::regex regex_1("^Subject               :");
					if (std::regex_search(item_wert, reg_match, regex_1))
					{
						
						
						cert_subject = item_wert.substr(0,item_wert.length() - 6);
						wo_ist_gleich = - 1;
						wo_ist_gleich = cert_subject.find(":");
						cert_subject = cert_subject.substr(wo_ist_gleich + 4,cert_subject.length());
						
						
						
						
					}
					std::regex regex_2("^             NotAfter :");
					if (std::regex_search(item_wert, reg_match, regex_2))
					{
						
						cert_valud_until = item_wert.substr(0,item_wert.length() - 6);
						wo_ist_gleich = - 1;
						wo_ist_gleich = cert_valud_until.find(":");
						cert_valud_until = cert_valud_until.substr(wo_ist_gleich + 4,cert_valud_until.length());
						
						
						weil_tru = false;
						continue;
					}
				}
			}
			
			if (std::regex_search(sapgenpse_parameter, reg_match, regex_3))
			{
				
				bool weil_tru = true;
				while(weil_tru)
				{
					wo_ist_item_anfang = web_service_wert_rueckgabe.find("<item>");
					wo_ist_item_ende = web_service_wert_rueckgabe.find("</item>");
					
					try{item_wert = web_service_wert_rueckgabe.substr(wo_ist_item_anfang + 6,wo_ist_item_ende - wo_ist_item_anfang );}catch( std::out_of_range& exception ){cout<<"Error xml_extract.cpp std::out_of_range"<<endl;exit(0);}
					
					
					try{web_service_wert_rueckgabe = web_service_wert_rueckgabe.substr(wo_ist_item_ende + 7, web_service_wert_rueckgabe.length());}catch( std::out_of_range& exception ){cout<<"Error xml_extract.cpp std::out_of_range"<<endl;exit(0);}
					
					
					
					std::regex regex_5("^  Subject:");
					if (std::regex_search(item_wert, reg_match, regex_5))
					{
						
						
						cert_subject = item_wert.substr(0,item_wert.length() - 6);
						wo_ist_gleich = - 1;
						wo_ist_gleich = cert_subject.find(":");
						cert_subject = cert_subject.substr(wo_ist_gleich + 31,cert_subject.length());
						
						
						
						
					}
					std::regex regex_6("^  Validity not after:");
					if (std::regex_search(item_wert, reg_match, regex_6))
					{
						
						cert_valud_until = item_wert.substr(0,item_wert.length() - 6);
						wo_ist_gleich = - 1;
						wo_ist_gleich = cert_valud_until.find(":");
						cert_valud_until = cert_valud_until.substr(wo_ist_gleich + 20,cert_valud_until.length());
						
						
						
						
						
						
						certlist_array.push_back(cert_subject + " Validity not after: " + cert_valud_until) ;
						
					}
					std::regex regex_7("^</item$");
					if (std::regex_search(item_wert, reg_match, regex_7))
					{
						
						weil_tru = false;
						continue;
					}
				}
			}
		}




		

		if (sapcontrol_command_response == "J2EEGetProcessListResponse" )
		{
			
			
			BOOST_FOREACH (boost::property_tree::ptree::value_type &wert_typ,pt.get_child("SOAP-ENV:Envelope.SOAP-ENV:Body.SAPControl:J2EEGetProcessListResponse.process")) 
			{
				if (wert_typ.first == "item") 
				{
					auto name = wert_typ.second.get<std::string>("name");
					auto state = wert_typ.second.get<std::string>("state");
					auto statetext = wert_typ.second.get<std::string>("statetext");
					
					
					
					
					item_gefunden = - 1;
					item_gefunden = name.find(sapcontrol_monitor_name_extern);
					if (item_gefunden > - 1)			
					{
						
						name_gefunden = true;						
						
						
						
						intem_status_gray = - 1;
						intem_status_gray = statetext.find("Disabled");
						
						if (intem_status_gray > -1)
						{
							cout<<" | GRAY ";
							cout<<" | "<<statetext<<endl;
							
							
							
							icinga_retun_code = 2;
							break;
						}
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						intem_status_green = - 1;
						intem_status_green = statetext.find("Running");
						
						if (intem_status_green > -1)
						{
							cout<<" | GREEN ";
							cout<<" | "<<statetext<<endl;
							
							
							
							icinga_retun_code = 0;
							break;
						}	
						
						intem_status_gray = - 1;
						intem_status_red = - 1;
						intem_status_yellow = - 1;
						intem_status_green = - 1;
						
					}
					
				}
				else
				{
					std::cout << "skipped: '" << wert_typ.first << "'\n";
				}
			}
		}
			

		if (sapcontrol_command_response == "J2EEGetComponentListResponse" )
		{
			
			BOOST_FOREACH (boost::property_tree::ptree::value_type &wert_typ,pt.get_child("SOAP-ENV:Envelope.SOAP-ENV:Body.SAPControl:J2EEGetComponentListResponse.component")) 
			{
				if (wert_typ.first == "item") 
				{
					auto name = wert_typ.second.get<std::string>("name");
					auto status = wert_typ.second.get<std::string>("status");
					auto dispstatus = wert_typ.second.get<std::string>("dispstatus");
					
					
					
					
					
					item_gefunden = - 1;
					item_gefunden = name.find(sapcontrol_monitor_name_extern);
					if (item_gefunden > - 1)			
					{
						
						name_gefunden = true;						
						
						
					
					
						intem_status_gray = - 1;
						intem_status_gray = status.find("stopped");
						
						if (intem_status_gray > -1)
						{
							cout<<" | GRAY ";
							cout<<" | "<<status<<endl;
							
							
							
							icinga_retun_code = 2;
							break;
						}
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						intem_status_green = - 1;
						intem_status_green = status.find("running");
						
						if (intem_status_green > -1)
						{
							cout<<" | GREEN ";
							cout<<" | "<<status<<endl;
							
							
							
							icinga_retun_code = 0;
							break;
						}
						
						intem_status_gray = - 1;
						intem_status_red = - 1;
						intem_status_yellow = - 1;
						intem_status_green = - 1;
					}
				}
				else
				{
					std::cout << "skipped: '" << wert_typ.first << "'\n";
				}
			}
		}

		if (sapcontrol_command_response == "J2EEGetVMHeapInfoResponse" )
		{
			
			
			int type_gefunden = - 1;
			
			int item_gefunden_processname = - 1;
			int item_gefunden_type = - 1;
					
			BOOST_FOREACH (boost::property_tree::ptree::value_type &wert_typ,pt.get_child("SOAP-ENV:Envelope.SOAP-ENV:Body.SAPControl:J2EEGetVMHeapInfoResponse.heap")) 
			{
				if (wert_typ.first == "item") 
				{
					auto processname = wert_typ.second.get<std::string>("processname");
					auto type = wert_typ.second.get<std::string>("type");
					auto size = wert_typ.second.get<std::string>("size");
					auto dispstatus = wert_typ.second.get<std::string>("dispstatus");
					
					
					
					
					
					
					
					
					item_gefunden_processname = - 1;
					item_gefunden_type = - 1;
					item_gefunden_processname = processname.find(sapcontrol_monitor_name_extern);
					item_gefunden_type = type.find(type_extern);
					
					if (item_gefunden_processname > - 1 && item_gefunden_type > - 1)			
					{
						
						
						
						
						heap_memory_size = size;
						
					}
					
					
					
					
				}
				else
				{
					std::cout << "skipped: '" << wert_typ.first << "'\n";
				}
			}
		}

	}
	
	
	
	
	



















	
}






















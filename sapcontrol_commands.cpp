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
#include <regex>

using namespace std;

extern string sapcontrol_command_extern;
extern string soap_sapcontrol_xml_extern;
extern string sid_extern;
extern string osexecute_command_path;
extern string sapgenpse_parameter;

void sapcontrol_commands()
{

	
	int wo_ist_gleich = - 1;
	wo_ist_gleich = sapcontrol_command_extern.find("=");
	sapcontrol_command_extern = sapcontrol_command_extern.substr(wo_ist_gleich + 1,sapcontrol_command_extern.length());
	
	wo_ist_gleich = - 1;
	wo_ist_gleich = sid_extern.find("=");
	sid_extern = sid_extern.substr(wo_ist_gleich + 1,sid_extern.length());

	
	std::smatch reg_match;		
	

	



	std::regex regex_1("^-javashow$");			
	if (std::regex_search(sapcontrol_command_extern, reg_match, regex_1))
	{

		string pfad_sapcontrol;
		
		pfad_sapcontrol = "/sapmnt/" + sid_extern + "/exe/uc/linuxx86_64/sapcontrol";
		
		soap_sapcontrol_xml_extern = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:SOAP-ENC=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:SAPControl=\"urn:SAPControl\" xmlns:SAPCCMS=\"urn:SAPCCMS\" xmlns:SAPHostControl=\"urn:SAPHostControl\" xmlns:SAPOscol=\"urn:SAPOscol\" xmlns:SAPDSR=\"urn:SAPDSR\"><SOAP-ENV:Body><SAPControl:OSExecute><command>" + pfad_sapcontrol + "</command><async>0</async><timeout>30</timeout><protocolfile></protocolfile></SAPControl:OSExecute></SOAP-ENV:Body></SOAP-ENV:Envelope>'";
		
	}
	else
	{
		
		
		std::regex regex_2("^certificate-show$");
		std::regex regex_3("^maintain_pk -l $");
		std::regex regex_4("^get_my_name $");
		if (std::regex_search(sapcontrol_command_extern, reg_match, regex_2))
		{
		
				if (std::regex_search(sapgenpse_parameter, reg_match, regex_4))
				{
		
					wo_ist_gleich = - 1;
					wo_ist_gleich = osexecute_command_path.find("=");
					osexecute_command_path = osexecute_command_path.substr(wo_ist_gleich + 1,osexecute_command_path.length());
					sapcontrol_command_extern = "OSExecute";
					osexecute_command_path = "/sapmnt/" + sid_extern + "/exe/uc/linuxx86_64/sapgenpse " + sapgenpse_parameter + "-p " + osexecute_command_path;
					soap_sapcontrol_xml_extern = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:SOAP-ENC=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:SAPControl=\"urn:SAPControl\" xmlns:SAPCCMS=\"urn:SAPCCMS\" xmlns:SAPHostControl=\"urn:SAPHostControl\" xmlns:SAPOscol=\"urn:SAPOscol\" xmlns:SAPDSR=\"urn:SAPDSR\"><SOAP-ENV:Body><SAPControl:" + sapcontrol_command_extern + "><command>" + osexecute_command_path + "</command><async>0</async><timeout>30</timeout><protocolfile></protocolfile></SAPControl:OSExecute></SOAP-ENV:Body></SOAP-ENV:Envelope>";
		
				}

		
				if (std::regex_search(sapgenpse_parameter, reg_match, regex_3))
				{
		
					wo_ist_gleich = - 1;
					wo_ist_gleich = osexecute_command_path.find("=");
					osexecute_command_path = osexecute_command_path.substr(wo_ist_gleich + 1,osexecute_command_path.length());
		
					sapcontrol_command_extern = "OSExecute";
					osexecute_command_path = "/sapmnt/" + sid_extern + "/exe/uc/linuxx86_64/sapgenpse " + sapgenpse_parameter + "-p " + osexecute_command_path;
					soap_sapcontrol_xml_extern = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:SOAP-ENC=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:SAPControl=\"urn:SAPControl\" xmlns:SAPCCMS=\"urn:SAPCCMS\" xmlns:SAPHostControl=\"urn:SAPHostControl\" xmlns:SAPOscol=\"urn:SAPOscol\" xmlns:SAPDSR=\"urn:SAPDSR\"><SOAP-ENV:Body><SAPControl:" + sapcontrol_command_extern + "><command>" + osexecute_command_path + "</command><async>0</async><timeout>30</timeout><protocolfile></protocolfile></SAPControl:OSExecute></SOAP-ENV:Body></SOAP-ENV:Envelope>";
		
				}

					
		}
		else
		{
		
			soap_sapcontrol_xml_extern = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:SOAP-ENC=\"http://schemas.xmlsoap.org/soap/encoding/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:SAPControl=\"urn:SAPControl\" xmlns:SAPCCMS=\"urn:SAPCCMS\" xmlns:SAPHostControl=\"urn:SAPHostControl\" xmlns:SAPOscol=\"urn:SAPOscol\" xmlns:SAPDSR=\"urn:SAPDSR\"><SOAP-ENV:Body><SAPControl:" + sapcontrol_command_extern + "></SAPControl:" + sapcontrol_command_extern + "></SOAP-ENV:Body></SOAP-ENV:Envelope>";
		
		}
	}


}

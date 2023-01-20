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
#include "nwrfcsdk/include/sapnwrfc.h"
#include "nwrfcsdk/include/sapucrfc.h"


#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <regex>


#include <bits/stdc++.h>

using namespace std;


RFC_ERROR_INFO errorInfo;
RFC_RC rc = RFC_OK;

string parameter;


string username_extern; 
string password_extern;
string hostname_extern;
string sid_extern;
string sysnr_extern;
string client_nr_extern;
vector<string> certlist_array;


string cert_subject;
string cert_valud_until;
vector<string> certlist_subj_valid_until;
bool ssl_check = false;


string rfc_destination;
int icinga_retun_code = - 1;
string rueckgabe_nachricht;


string web_service_wert_rueckgabe;
string http_proto_extern;


string sapcontrol_command_extern;
string soap_sapcontrol_xml_extern;
string osexecute_command_path;
string sapgenpse_parameter;


string sapcontrol_monitor_name_extern;
string type_extern;
string heap_memory_size;






long tage_bis_ablauf;


void signalHandler( int signum)
{
		cout<<"PROBLEM SAP MON mail to software.moore@gmail.com"<<endl;
        cout << "Interrupt signal (" << signum << ") received.\n";
        
		
		
		
		
        
		
		
				
		
        
		exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])

{



        signal(SIGSEGV, signalHandler);
        signal(SIGABRT, signalHandler);
        signal(SIGFPE, signalHandler);
        signal(SIGILL, signalHandler);
        signal(SIGTERM, signalHandler);
        signal(SIGINT, signalHandler);




		


		std::smatch reg_match;		
		
		
		parameter = argv[1];
		
		
		int wo_ist_show_parameter = - 1;
		wo_ist_show_parameter = parameter.find("-show");
		
		
		
		
		
		
		std::regex regex_1("^-show$");
		
		
		if (std::regex_search(parameter, reg_match, regex_1))
		{
			
			cout<<"Alle verfügbaren CCMS Monitore"<<endl;
			
			
			#define NUM_PARAMS 9
			RFC_CONNECTION_PARAMETER loginParams[NUM_PARAMS];
			unsigned resultLen = 0;
			
			
			
			
			
			string username;
			username = argv[2];
			
			int wo_ist_gleich = - 1;
			wo_ist_gleich = username.find("=");
			username = username.substr(wo_ist_gleich + 1,username.length());
			
			
			SAP_UC *username_sapuc = NULL;
			unsigned username_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (username_sapuc == NULL)
			{
				
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			string password;
			password = argv[3];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = password.find("=");
			password = password.substr(wo_ist_gleich + 1,password.length());
			
			
			SAP_UC *password_sapuc = NULL;
			unsigned password_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			
			{
				
				
				
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (password_sapuc == NULL)
			{
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			string hostname;
			hostname = argv[4];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = hostname.find("=");
			hostname = hostname.substr(wo_ist_gleich + 1,hostname.length());
			
			
			SAP_UC *hostname_sapuc = NULL;
			unsigned hostname_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (hostname_sapuc == NULL)
			{
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				

			
			
			
			
			
			string sid;
			sid = argv[5];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sid.find("=");
			sid = sid.substr(wo_ist_gleich + 1,sid.length());
			
			
			SAP_UC *sid_sapuc = NULL;
			
			
			unsigned sid_sapuc_len;
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sid_sapuc == NULL)
			{
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			

			
			string sysnr;
			sysnr = argv[6];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sysnr.find("=");
			sysnr = sysnr.substr(wo_ist_gleich + 1,sysnr.length());
			
			
			SAP_UC *sysnr_sapuc = NULL;
			
			
			
			
			unsigned sysnr_sapuc_len;
			
			resultLen = 0;
			
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sysnr_sapuc == NULL)
			{
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
	
			
			
			

			
			string client_nr;
			client_nr = argv[7];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = client_nr.find("=");
			client_nr = client_nr.substr(wo_ist_gleich + 1,client_nr.length());
			
			
			SAP_UC *client_nr_sapuc = NULL;
			unsigned client_nr_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (client_nr_sapuc == NULL)
			{
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			
			loginParams[0].name = cU("dest");
			loginParams[0].value = cU("DEV");
			loginParams[1].name =cU("user");
				
			loginParams[1].value = username_sapuc;
			loginParams[2].name = cU("passwd");
				
			loginParams[2].value = password_sapuc;
			loginParams[3].name = cU("ASHOST");
				
			loginParams[3].value = hostname_sapuc;
			loginParams[4].name = cU("SYSID");
				
			loginParams[4].value = sid_sapuc;
			loginParams[5].name = cU("SYSNR");
				
			loginParams[5].value = sysnr_sapuc;
			loginParams[6].name = cU("CLIENT");
				
			loginParams[6].value = client_nr_sapuc;
			loginParams[7].name = cU("lang");
			loginParams[7].value = cU("EN");
			loginParams[8].name = cU("TRACE");
			loginParams[8].value = cU("0");
	
			RFC_CONNECTION_HANDLE conn;
			conn = RfcOpenConnection(loginParams, NUM_PARAMS, &errorInfo);
				
				
				
				
			if (errorInfo.code != RFC_OK) 
			{
				cout<<"Login PROBLEM"<<endl;
				printfU(cU("key# %s: %d\n"),errorInfo.key);
				printfU(cU("message# %s: %d\n"),errorInfo.message);
				printfU(cU("code# %d\n"),errorInfo.code);
				exit(-1);
						
			}
			
			
			RFC_STRUCTURE_HANDLE returnStructure;
			RFC_FUNCTION_DESC_HANDLE ccms_bapi_handle;
			RFC_FUNCTION_HANDLE rfc_handle;
				
			SAP_UC message[8192] = iU("");
			
			
			
			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_XMI_LOGON"), &errorInfo);
			
			
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTCOMPANY"), cU("TESTCOPMANY"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTPRODUCT"), cU("TESTPRODUKT"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("INTERFACE"), cU("XAL"), 3, &errorInfo);
			RfcSetChars(rfc_handle, cU("VERSION"), cU("1.0"), 3, &errorInfo);
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);
				
				
				
				
			
			
			
			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MON_GETLIST"), &errorInfo);
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("RFC_TEST"), 8, &errorInfo);

			
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);

			
			unsigned rowCount = 0;
			RFC_TABLE_HANDLE table;
			rc = RfcGetTable(rfc_handle, cU("MONITOR_NAMES"),&table,&errorInfo);
			RfcGetRowCount(table, &rowCount, &errorInfo);
				

			SAP_UC ms_name[4096] = iU("");
			SAP_UC moni_name[4096] = iU("");
			
			SAP_UC object_name[4096] = iU("");
			RFC_TABLE_HANDLE table_2;
			
			unsigned rowCount_2 = 0;
			
			for (unsigned i = 0; i < rowCount; ++i) 
			
			
			{
				RfcMoveTo(table, i, NULL);
				
				RfcGetString(table, cU("MS_NAME"), ms_name,sizeofU(ms_name), NULL, &errorInfo);
					printfU(cU("%s\n"), ms_name);
					
				RfcGetString(table, cU("MONI_NAME"), moni_name,sizeofU(moni_name), NULL, &errorInfo);
					printfU(cU(" |\n"));
					printfU(cU("  -> %s\n"),moni_name);
				
				
				
				
				
				ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MON_GETTREE"), &errorInfo);
					
					
					
					
				rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
					
					
					

				RfcSetInt(rfc_handle, cU("MAX_TREE_DEPTH"), 0,&errorInfo);
					
					
					
				
				RfcSetInt(rfc_handle, cU("VIS_ON_USR_LEVEL"), 3,&errorInfo);
					
					
					

				RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("RFC_TEST"), 8, &errorInfo);
					
					
					
				
				
				RfcGetStructure(rfc_handle, cU("MONITOR_NAME"), &returnStructure, &errorInfo);
					
					
					

				RfcSetStructure(rfc_handle, cU("MONITOR_NAME"),returnStructure, &errorInfo);
					
					
					
				
				
				RfcSetChars(returnStructure, cU("MS_NAME"), ms_name, strlenU(ms_name), &errorInfo);
				
					
					
					
				
				RfcSetChars(returnStructure, cU("MONI_NAME"),moni_name , strlenU(moni_name), &errorInfo);
				
					
					
					
				
				rc = RfcInvoke(conn, rfc_handle, &errorInfo);
					
					
					
					
					
				RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					
					
					
					
				RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					
					
					
					

				rowCount_2 = 0;

				rc = RfcGetTable(rfc_handle, cU("TREE_NODES"),&table_2,&errorInfo);
				RfcGetRowCount(table_2, &rowCount_2, &errorInfo);
					
				for (unsigned j = 0; j < rowCount_2; ++j) 
				{
					RfcMoveTo(table_2, j, NULL);
						
					RfcGetString(table_2, cU("CUSGRPNAME"), object_name,sizeofU(object_name), NULL, &errorInfo);				
						printfU(cU(" 	| -> %s\n"),object_name);
						
					RfcGetString(table_2, cU("OBJECTNAME"), object_name,sizeofU(object_name), NULL, &errorInfo);				
						printfU(cU("	| ->%s\n"), object_name);
						printfU(cU(" 	|\n"));
						
				}
				rowCount_2 = 0;
				
					
			}
			
				
				
			
			
			
						
			RfcDestroyFunction(rfc_handle, &errorInfo);
			
			RfcCloseConnection(conn, NULL);
		}
		
		
		
		
		
		
		
		int wo_ist_check_parameter = - 1;
		wo_ist_check_parameter = parameter.find("-check");
		std::regex regex_2("^-check$");
		
		
		if (std::regex_search(parameter, reg_match, regex_2))
		{
			
			
			#define NUM_PARAMS 9
			RFC_CONNECTION_PARAMETER loginParams[NUM_PARAMS];

			
			unsigned resultLen = 0;
			
			
			
			
			
			string username;
			username = argv[2];
			
			int wo_ist_gleich = - 1;
			wo_ist_gleich = username.find("=");
			username = username.substr(wo_ist_gleich + 1,username.length());
			
			
			SAP_UC *username_sapuc = NULL;
			unsigned username_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (username_sapuc == NULL)
			{
				
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			
			
			
				
			
			
			
			
			
			
			string password;
			password = argv[3];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = password.find("=");
			password = password.substr(wo_ist_gleich + 1,password.length());
			
			
			SAP_UC *password_sapuc = NULL;
			unsigned password_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			
			{
				
				
				
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (password_sapuc == NULL)
			{
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			
			
			
			
			
			
			
			
			string hostname;
			hostname = argv[4];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = hostname.find("=");
			hostname = hostname.substr(wo_ist_gleich + 1,hostname.length());
			
			
			SAP_UC *hostname_sapuc = NULL;
			unsigned hostname_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (hostname_sapuc == NULL)
			{
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			

			
			
			
			
			
			
			string sid;
			sid = argv[5];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sid.find("=");
			sid = sid.substr(wo_ist_gleich + 1,sid.length());
			
			
			SAP_UC *sid_sapuc = NULL;
			
			
			unsigned sid_sapuc_len;
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sid_sapuc == NULL)
			{
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			
			
			
			
			

			
			string sysnr;
			sysnr = argv[6];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sysnr.find("=");
			sysnr = sysnr.substr(wo_ist_gleich + 1,sysnr.length());
			
			
			SAP_UC *sysnr_sapuc = NULL;
			
			
			
			
			unsigned sysnr_sapuc_len;
			
			resultLen = 0;
			
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sysnr_sapuc == NULL)
			{
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			
			
	
			
			
			

			
			string client_nr;
			client_nr = argv[7];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = client_nr.find("=");
			client_nr = client_nr.substr(wo_ist_gleich + 1,client_nr.length());
			
			
			SAP_UC *client_nr_sapuc = NULL;
			unsigned client_nr_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (client_nr_sapuc == NULL)
			{
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			
			
			
			
			
			

			loginParams[0].name = cU("dest");
			loginParams[0].value = cU("DEV");
			loginParams[1].name =cU("user");
				
			loginParams[1].value = username_sapuc;
			loginParams[2].name = cU("passwd");
				
			loginParams[2].value = password_sapuc;
			loginParams[3].name = cU("ASHOST");
				
			loginParams[3].value = hostname_sapuc;
			loginParams[4].name = cU("SYSID");
				
			loginParams[4].value = sid_sapuc;
			loginParams[5].name = cU("SYSNR");
				
			loginParams[5].value = sysnr_sapuc;
			loginParams[6].name = cU("CLIENT");
				
			loginParams[6].value = client_nr_sapuc;
			loginParams[7].name = cU("lang");
			loginParams[7].value = cU("EN");
			loginParams[8].name = cU("TRACE");
			loginParams[8].value = cU("0");
	


			RFC_CONNECTION_HANDLE conn;
			conn = RfcOpenConnection(loginParams, NUM_PARAMS, &errorInfo);
				
				
				
				
			if (errorInfo.code != RFC_OK) 
			{
				cout<<"Login PROBLEM"<<endl;
				printfU(cU("key# %s: %d\n"),errorInfo.key);
				printfU(cU("message# %s: %d\n"),errorInfo.message);
				printfU(cU("code# %d\n"),errorInfo.code);
				exit(-1);
			}
			
			RFC_FUNCTION_DESC_HANDLE ccms_bapi_handle;
			RFC_FUNCTION_HANDLE rfc_handle;

			
			
			
			SAP_UC message[5000] = iU("");

			
			
			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_XMI_LOGON"), &errorInfo);
			
			
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTCOMPANY"), cU("TESTCOPMANY"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTPRODUCT"), cU("TESTPRODUKT"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("INTERFACE"), cU("XAL"), 3, &errorInfo);
			RfcSetChars(rfc_handle, cU("VERSION"), cU("1.0"), 3, &errorInfo);
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);
				
				
				
				
			
			
			

			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETTIDBYNAME"), &errorInfo);
		
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			
			
			
			string monitor_name_temp_2;
			string monitor_name;
			
			
			monitor_name_temp_2 = argv[8];
				
			int wo_ist_gleich_2 = - 1;
			wo_ist_gleich_2 = monitor_name_temp_2.find("=");
			int mointor_lange = 0;
			mointor_lange = monitor_name_temp_2.length();
			
			monitor_name = monitor_name_temp_2.substr(wo_ist_gleich_2 + 1, mointor_lange);
				
			
			
			
		
			
			
			int wo_ist_backslash = - 1;
			wo_ist_backslash = monitor_name.find("\\");
			
			string monitor_name_sap_sid;
			monitor_name_sap_sid = monitor_name.substr(0,wo_ist_backslash);
			
			
			
			SAP_UC *monitor_name_sap_sid_sapuc = NULL;
			unsigned monitor_name_sap_sid_sapuc_len;
			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)monitor_name_sap_sid.c_str(),strlen(monitor_name_sap_sid.c_str()),monitor_name_sap_sid_sapuc, &monitor_name_sap_sid_sapuc_len, &resultLen,  &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				monitor_name_sap_sid_sapuc = (SAP_UC*)reallocU(monitor_name_sap_sid_sapuc, monitor_name_sap_sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)monitor_name_sap_sid.c_str(),strlen(monitor_name_sap_sid.c_str()),monitor_name_sap_sid_sapuc, &monitor_name_sap_sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (monitor_name_sap_sid_sapuc == NULL)
			{
				monitor_name_sap_sid_sapuc = (SAP_UC*)reallocU(monitor_name_sap_sid_sapuc, monitor_name_sap_sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)monitor_name_sap_sid.c_str(),strlen(monitor_name_sap_sid.c_str()),monitor_name_sap_sid_sapuc, &monitor_name_sap_sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			

			
			
			
			int wo_ist_backslash_2 = - 1;
			wo_ist_backslash_2 = monitor_name.find("\\",wo_ist_backslash + 1);
			
			
			string conetxt_name = monitor_name.substr(wo_ist_backslash + 1, wo_ist_backslash_2 - wo_ist_backslash - 1);
			
			
			SAP_UC *monitor_name_context_name_sapuc = NULL;
			unsigned monitor_name_context_name_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)conetxt_name.c_str(),strlen(conetxt_name.c_str()),monitor_name_context_name_sapuc, &monitor_name_context_name_sapuc_len, &resultLen,  &errorInfo);
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				monitor_name_context_name_sapuc = (SAP_UC*)reallocU(monitor_name_context_name_sapuc, monitor_name_context_name_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)conetxt_name.c_str(),strlen(conetxt_name.c_str()),monitor_name_context_name_sapuc, &monitor_name_context_name_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (monitor_name_context_name_sapuc == NULL)
			{
				
				monitor_name_context_name_sapuc = (SAP_UC*)reallocU(monitor_name_context_name_sapuc, monitor_name_context_name_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)conetxt_name.c_str(),strlen(conetxt_name.c_str()),monitor_name_context_name_sapuc, &monitor_name_context_name_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			
			
			
			
			int wo_ist_ende = - 1;
			wo_ist_ende = monitor_name.rfind("\\");
			
			int monitor_name_laenge = - 1;
			monitor_name_laenge = monitor_name.length();
			string mte_name = monitor_name.substr(wo_ist_ende + 1, monitor_name_laenge -  wo_ist_ende );
			
			
			SAP_UC *monitor_name_mte_name_sapuc = NULL;
			unsigned monitor_name_mte_name_sapuc_len;			
			resultLen = 0;
			
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)mte_name.c_str(),strlen(mte_name.c_str()),monitor_name_mte_name_sapuc, &monitor_name_mte_name_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				monitor_name_mte_name_sapuc = (SAP_UC*)reallocU(monitor_name_mte_name_sapuc, monitor_name_mte_name_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)mte_name.c_str(),strlen(mte_name.c_str()),monitor_name_mte_name_sapuc, &monitor_name_mte_name_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}

			if (monitor_name_mte_name_sapuc == NULL)
			{
				
				monitor_name_mte_name_sapuc = (SAP_UC*)reallocU(monitor_name_mte_name_sapuc, monitor_name_mte_name_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)mte_name.c_str(),strlen(mte_name.c_str()),monitor_name_mte_name_sapuc, &monitor_name_mte_name_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			
			string monitor_name_temp = monitor_name.substr(0, wo_ist_ende);
			int monitor_name_temp_laenge = monitor_name_temp.length();
				
			int wo_ist_backslash_3 = - 1;
			wo_ist_backslash_3 = monitor_name_temp.rfind("\\");		
				
			
			
				
			string object_name = monitor_name_temp.substr(wo_ist_backslash_3 + 1, monitor_name_temp_laenge - wo_ist_backslash_3 );
				
			
			SAP_UC *monitor_name_object_name_sapuc = NULL;
			unsigned monitor_name_object_name_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)object_name.c_str(),strlen(object_name.c_str()),monitor_name_object_name_sapuc, &monitor_name_object_name_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				monitor_name_object_name_sapuc = (SAP_UC*)reallocU(monitor_name_object_name_sapuc, monitor_name_object_name_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)object_name.c_str(),strlen(object_name.c_str()),monitor_name_object_name_sapuc, &monitor_name_object_name_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (monitor_name_object_name_sapuc == NULL)
			{
				
				monitor_name_object_name_sapuc = (SAP_UC*)reallocU(monitor_name_object_name_sapuc, monitor_name_object_name_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)object_name.c_str(),strlen(object_name.c_str()),monitor_name_object_name_sapuc, &monitor_name_object_name_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			

			
			
			
			
			
			
			RfcSetChars(rfc_handle, cU("CONTEXT_NAME"), monitor_name_context_name_sapuc, strlenU(monitor_name_context_name_sapuc), &errorInfo);	
			
			RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 26, &errorInfo);
			RfcSetChars(rfc_handle, cU("MTE_NAME"), monitor_name_mte_name_sapuc, strlenU(monitor_name_mte_name_sapuc), &errorInfo);	
			
			
			RfcSetChars(rfc_handle, cU("OBJECT_NAME"), monitor_name_object_name_sapuc, strlenU(monitor_name_object_name_sapuc), &errorInfo);	

			
			
			
			RfcSetChars(rfc_handle, cU("SYSTEM_ID"), monitor_name_sap_sid_sapuc, strlenU(monitor_name_sap_sid_sapuc), &errorInfo);	
			
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);
				
				
				
				
				
			RFC_STRUCTURE_HANDLE returnStructure;
			RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
				
				
				
				
			rc = RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
				
				
				
				
				
			
			
			


			
			SAP_UC message_mtclass[9999] = iU("");
			
			RfcGetStructure(rfc_handle, cU("TID"), &returnStructure, &errorInfo);
			
			RfcGetString(returnStructure, cU("MTSYSID"), message, sizeofU(message), &resultLen, &errorInfo);
				
			RfcGetString(returnStructure, cU("MTMCNAME"), message, sizeofU(message), &resultLen, &errorInfo);
				
			RfcGetString(returnStructure, cU("MTNUMRANGE"), message, sizeofU(message), &resultLen, &errorInfo);
				
			RfcGetString(returnStructure, cU("MTUID"), message, sizeofU(message), &resultLen, &errorInfo);
				
			
			RfcGetString(returnStructure, cU("MTCLASS"), message_mtclass, sizeofU(message_mtclass), &resultLen, &errorInfo);			
				
			RfcGetString(returnStructure, cU("MTINDEX"), message, sizeofU(message), &resultLen, &errorInfo);
				
			RfcGetString(returnStructure, cU("EXTINDEX"), message, sizeofU(message), &resultLen, &errorInfo);
				
			

			
			
			unsigned message_int_mtclass;
			unsigned result_length_mtclass;
			char message_char_mtclass[9999];
			
			resultLen = 0;
			rc = RfcSAPUCToUTF8(message_mtclass, strlenU(message_mtclass), (RFC_BYTE *)message_char_mtclass, &message_int_mtclass, &result_length_mtclass, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(message_mtclass, strlenU(message_mtclass), (RFC_BYTE *)message_char_mtclass, &message_int_mtclass, &result_length_mtclass, &errorInfo);
			}
			
			
			string message_string_mtclass;
			std::stringstream ConvertStream_mtclass;
			ConvertStream_mtclass<<	message_char_mtclass;
			ConvertStream_mtclass>>message_string_mtclass;
			

			
			
			
			
			
			
			
			
			

			
			
			if (message_string_mtclass ==  "111")
			{
				
				ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETTXTPROP"), &errorInfo);

				rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);

				RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 8, &errorInfo);

				rc = RfcSetStructure(rfc_handle, cU("TID"),returnStructure, &errorInfo);
					
					
					
					

				rc = RfcInvoke(conn, rfc_handle, &errorInfo);
					
					
					
					

				RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					
					
					
					
				RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					
					
					
					
					
					
					
					
					
					
					
					
					
				
				unsigned message_int;
				unsigned result_length;
				
				
				char message_char[5000];

				rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
					
					
					
					
					
					
					
					
				if (rc == RFC_BUFFER_TOO_SMALL)
				{
					
					rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
						
						
						
						
						
						
						
						
				}
				
				if (strlen(message_char) != 0)
				{
					cout<<"Fehler: Monitor nicht definiert"<<endl;

					
					
					
					
					
					
														
					RfcDestroyFunction(rfc_handle, &errorInfo);
					RfcCloseConnection(conn, NULL);

					exit(-1);
				}
				
				RfcGetStructure(rfc_handle, cU("PROPERTIES"), &returnStructure, &errorInfo);
					
					
					
					
				
				RfcGetString(returnStructure, cU("TEXT"), message, sizeofU(message), &resultLen, &errorInfo);
					
				printfU(cU("%s\n"), message);
				
				RfcDestroyFunction(rfc_handle, &errorInfo);
				RfcCloseConnection(conn, NULL);
			
				exit(0);
				
				
				
				
				
			}
			
			
			if (message_string_mtclass ==  "101")
			{
				
				ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETMLCURVAL"), &errorInfo);

				rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);

				RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 8, &errorInfo);

				rc = RfcSetStructure(rfc_handle, cU("TID"),returnStructure, &errorInfo);
					
					
					
					

				rc = RfcInvoke(conn, rfc_handle, &errorInfo);
					
					
					
					

				RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					
					
					
					
				RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					
					
					
					
					
					
					
					
					
					
					
					
					
				unsigned message_int;
				unsigned result_length;
				
				
				char message_char[5000];

				rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
					
					
					
					
					
					
					
					
				if (rc == RFC_BUFFER_TOO_SMALL)
				{
					
					rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
						
						
						
						
						
						
						
						
				}
				
				if (strlen(message_char) != 0)
				{
					cout<<"Fehler: Monitor nicht definiert"<<endl;

					
					
					
					
					
					
														
					RfcDestroyFunction(rfc_handle, &errorInfo);
					RfcCloseConnection(conn, NULL);

					exit(-1);
				}

				RfcGetStructure(rfc_handle, cU("XMI_MSG_EXT"), &returnStructure, &errorInfo);
					
					
					
					
				
				RfcGetString(returnStructure, cU("MSG"), message, sizeofU(message), &resultLen, &errorInfo);
					
				printfU(cU("%s\n"), message);
				
				RfcDestroyFunction(rfc_handle, &errorInfo);
				RfcCloseConnection(conn, NULL);
			
				exit(0);
				
				
				
				
				

			}
			
			
			if (message_string_mtclass ==  "102")
			{
				
				ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETSMVALUE"), &errorInfo);
				
				rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);

				RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 8, &errorInfo);
				
				rc = RfcSetStructure(rfc_handle, cU("TID"),returnStructure, &errorInfo);
					
					
					
					
					
				rc = RfcInvoke(conn, rfc_handle, &errorInfo);
					
					
					
					
					
				RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					
					
					
					
				RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					
					
					
					
					
					
					
					
					
					
					
					
					
				unsigned message_int;
				unsigned result_length;
				
				
				char message_char[5000];
				
				rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
				
					
					
					
					
					
					
					
				if (rc == RFC_BUFFER_TOO_SMALL)
				{
					
					rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
					
					
					
					
					
					
					
					
				}
				
				if (strlen(message_char) != 0)
				{
					cout<<"Fehler: Monitor nicht definiert"<<endl;
					
					
					
					
					
					
					
															
					RfcDestroyFunction(rfc_handle, &errorInfo);
					RfcCloseConnection(conn, NULL);
					
					exit(-1);
				}
				RfcGetStructure(rfc_handle, cU("VALUE"), &returnStructure, &errorInfo);
					
					
					
					

				
					
					
					
					

				
					

				
					
				RfcGetString(returnStructure, cU("MSG"), message, sizeofU(message), &resultLen, &errorInfo);
					
					printfU(cU("%s\n"), message);

				RfcDestroyFunction(rfc_handle, &errorInfo);
				RfcCloseConnection(conn, NULL);
				
				exit(0);
			}
			
			
			if (message_string_mtclass ==  "100")
			
			{
			
			
			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETPERFCURVAL"), &errorInfo);
			
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);

			RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 8, &errorInfo);
			
			rc = RfcSetStructure(rfc_handle, cU("TID"),returnStructure, &errorInfo);
				
				
				
				
				
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);
				
				
				
				
				
			RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
				
				
				
				
			RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
				
				
				
				
				
				
				
				
				
				
				
				
				
				unsigned message_int;
				unsigned result_length;
				
				
				char message_char[5000];

				rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
				
					
					
					
					
					
					
					
				if (rc == RFC_BUFFER_TOO_SMALL)
				{
					
					rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
					
					
					
					
					
					
					
					
				}
				
				if (strlen(message_char) != 0)
				{
					cout<<"Fehler: Monitor nicht definiert"<<endl;
					
					
					
					
					
					
					
															
					RfcDestroyFunction(rfc_handle, &errorInfo);
					RfcCloseConnection(conn, NULL);
					
					exit(-1);
				}
			


			RfcGetStructure(rfc_handle, cU("CURRENT_VALUE"), &returnStructure, &errorInfo);
				
				
				
				
			RfcGetString(returnStructure, cU("ALRELEVVAL"), message, sizeofU(message), &resultLen, &errorInfo);
				
				
				printfU(cU("%s\n"), message);
				
				
				
				
			RfcDestroyFunction(rfc_handle, &errorInfo);
			RfcCloseConnection(conn, NULL);
			
			
						
			
			
			if (argc > 9)
			{
				
			
				
				string warn_1;
				warn_1 = argv[9];
				
				wo_ist_gleich = - 1;
				wo_ist_gleich = warn_1.find("=");
				
				string warn_2;
				int warn_laenge = - 1;
				warn_laenge = warn_1.length();
				warn_2 = warn_1.substr(wo_ist_gleich + 1,warn_laenge);
				

				string critical_1;
				critical_1 = argv[10];
				
				wo_ist_gleich = - 1;
				wo_ist_gleich = critical_1.find("=");
				
				string critical_2;
				int critical_laenge = - 1;
				critical_laenge = critical_1.length();
				critical_2 = critical_1.substr(wo_ist_gleich + 1,critical_laenge);
				
					
				resultLen = 0;
				rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
					
					
					
					
				if (rc == RFC_BUFFER_TOO_SMALL)
				{
					
					
					
					
					rc = RfcSAPUCToUTF8(message, strlenU(message), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
						
						
						
						
						
				}
				
				
				int wert_int;
				std::stringstream ConvertStream;
				ConvertStream<<	message_char;
				ConvertStream>>wert_int;
				

				int warn_int = atoi(warn_2.c_str());
				

				int critical_int = atoi(critical_2.c_str());
				

				
				
				
				
				
				

				if (wert_int >= warn_int)
				{
					cout<<"WARNUNG"<<endl;
					exit(1);
				}

				if (wert_int >= critical_int)
				{
					cout<<"CRITICAL"<<endl;
					exit(2);
				}
				
			}
			
			exit(0);
		}


			
			
			
		}
		
		
		
		
		
		
		
		int wo_ist_aborted_job_parameter = - 1;
		wo_ist_aborted_job_parameter = parameter.find("-aborted-job");
		std::regex regex_3("^-aborted-job$");
		
		if (std::regex_search(parameter, reg_match, regex_3))
		{
			
			
			
			
			
			#define NUM_PARAMS 9
			RFC_CONNECTION_PARAMETER loginParams[NUM_PARAMS];

			
			unsigned resultLen = 0;
			
			
			
			
			
			string username;
			username = argv[2];
			
			int wo_ist_gleich = - 1;
			wo_ist_gleich = username.find("=");
			username = username.substr(wo_ist_gleich + 1,username.length());
			
			
			SAP_UC *username_sapuc = NULL;
			unsigned username_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (username_sapuc == NULL)
			{
				
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
				
			
			
			
			
			
			
			string password;
			password = argv[3];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = password.find("=");
			password = password.substr(wo_ist_gleich + 1,password.length());
			
			
			SAP_UC *password_sapuc = NULL;
			unsigned password_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			
			{
				
				
				
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (password_sapuc == NULL)
			{
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			
			
			
			
			string hostname;
			hostname = argv[4];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = hostname.find("=");
			hostname = hostname.substr(wo_ist_gleich + 1,hostname.length());
			
			
			SAP_UC *hostname_sapuc = NULL;
			unsigned hostname_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (hostname_sapuc == NULL)
			{
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				

			
			
			
			
			
			
			string sid;
			sid = argv[5];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sid.find("=");
			sid = sid.substr(wo_ist_gleich + 1,sid.length());
			
			
			SAP_UC *sid_sapuc = NULL;
			
			
			unsigned sid_sapuc_len;
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sid_sapuc == NULL)
			{
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			

			
			string sysnr;
			sysnr = argv[6];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sysnr.find("=");
			sysnr = sysnr.substr(wo_ist_gleich + 1,sysnr.length());
			
			
			SAP_UC *sysnr_sapuc = NULL;
			
			
			
			
			unsigned sysnr_sapuc_len;
			
			resultLen = 0;
			
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sysnr_sapuc == NULL)
			{
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
	
			
			
			

			
			string client_nr;
			client_nr = argv[7];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = client_nr.find("=");
			client_nr = client_nr.substr(wo_ist_gleich + 1,client_nr.length());
			
			
			SAP_UC *client_nr_sapuc = NULL;
			unsigned client_nr_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (client_nr_sapuc == NULL)
			{
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			
			

			loginParams[0].name = cU("dest");
			loginParams[0].value = cU("DEV");
			loginParams[1].name =cU("user");
				
			loginParams[1].value = username_sapuc;
			loginParams[2].name = cU("passwd");
				
			loginParams[2].value = password_sapuc;
			loginParams[3].name = cU("ASHOST");
				
			loginParams[3].value = hostname_sapuc;
			loginParams[4].name = cU("SYSID");
				
			loginParams[4].value = sid_sapuc;
			loginParams[5].name = cU("SYSNR");
				
			loginParams[5].value = sysnr_sapuc;
			loginParams[6].name = cU("CLIENT");
				
			loginParams[6].value = client_nr_sapuc;
			loginParams[7].name = cU("lang");
			loginParams[7].value = cU("EN");
			loginParams[8].name = cU("TRACE");
			loginParams[8].value = cU("0");
	


			RFC_CONNECTION_HANDLE conn;
			conn = RfcOpenConnection(loginParams, NUM_PARAMS, &errorInfo);
				
				
				
				
			if (errorInfo.code != RFC_OK) 
			{
				cout<<"Login PROBLEM"<<endl;
				printfU(cU("key# %s: %d\n"),errorInfo.key);
				printfU(cU("message# %s: %d\n"),errorInfo.message);
				printfU(cU("code# %d\n"),errorInfo.code);
				exit(-1);
			}

			RFC_FUNCTION_DESC_HANDLE ccms_bapi_handle;
			
			
			RFC_FUNCTION_HANDLE rfc_handle;

			
			SAP_UC message[8192] = iU("");
			RFC_STRUCTURE_HANDLE returnStructure;
			
			
			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_XMI_LOGON"), &errorInfo);
			
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTCOMPANY"), cU("TESTCOPMANY"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTPRODUCT"), cU("TESTPRODUKT"), 11, &errorInfo);
			
			RfcSetChars(rfc_handle, cU("INTERFACE"), cU("XBP"), 3, &errorInfo);
			RfcSetChars(rfc_handle, cU("VERSION"), cU("1.0"), 3, &errorInfo);
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);
			
			
			
			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_XBP_JOB_SELECT"), &errorInfo);
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("RFC_TEST"), 8, &errorInfo);
			

			
			
			RfcGetStructure(rfc_handle, cU("JOB_SELECT_PARAM"), &returnStructure, &errorInfo);
				
				
				
			RfcSetStructure(rfc_handle, cU("JOB_SELECT_PARAM"),returnStructure, &errorInfo);
				
				
				
			RfcSetChars(returnStructure, cU("JOBNAME"), cU("*"),1, &errorInfo);
				
				
				
			RfcSetChars(returnStructure, cU("JOBCOUNT"), cU("*"),1, &errorInfo);
				
				
				
			RfcSetChars(returnStructure, cU("JOBGROUP"), cU("*"),1, &errorInfo);
				
				
				
			RfcSetChars(returnStructure, cU("USERNAME"), cU("*"),1, &errorInfo);
				
				
				
			RfcSetChars(returnStructure, cU("FROM_DATE"), cU("1900-01-01"),10, &errorInfo);
				
				
				
			RfcSetChars(returnStructure, cU("FROM_TIME"), cU("00:00:00"),8, &errorInfo);
				
				
				
			RfcSetChars(returnStructure, cU("TO_DATE"), cU("2999-12-31"),10, &errorInfo);
				
				
				
			RfcSetChars(returnStructure, cU("TO_TIME"), cU("00:00:00"),8, &errorInfo);
				
				
				
			
			
			
			
			
			
			
			
			
			
			RfcSetChars(rfc_handle, cU("SYSTEMID"), sid_sapuc, 3, &errorInfo);							

			rc = RfcInvoke(conn, rfc_handle, &errorInfo);

			RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
			RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
				

			unsigned rowCount = 0;
			RFC_TABLE_HANDLE table;

			rc = RfcGetTable(rfc_handle, cU("JOB_HEAD"),&table,&errorInfo);
			RfcGetRowCount(table, &rowCount, &errorInfo);
				

			
			
			

			SAP_UC job_name[4096] = iU("");
			SAP_UC job_count_number[4096] = iU("");
			SAP_UC job_status[4096] = iU("");
			SAP_UC job_end_datum[4096] = iU("");
			SAP_UC job_end_uhrzeit[4096] = iU("");
	
			vector<string> job_infos_vector;

			char message_char[5000];
			char message_char_2[5000];
			char message_char_3[5000];
			char message_char_4[5000];
			unsigned message_int;
			unsigned message_2_int;
			unsigned message_3_int;
			unsigned message_4_int;
			unsigned result_length;
			unsigned result_length_2;
			unsigned result_length_3;
			unsigned result_length_4;

			int wo_ist_status_A = -1;
			string message_string;
			string job_name_string;
			string job_count_string;
			string job_end_datum_string;
			string job_end_uhrzeit_string;

			vector<int> job_count_number_array;
			vector<string> job_name_array;
			vector<string> job_name_und_job_count_array;
			string vector_format;
			int zaehler = -1;
			vector<int>column;
			
			for (unsigned i=0; i<rowCount; ++i) 
			{
				RfcMoveTo(table, i, NULL);
					
					
					

				RfcGetString(table, cU("JOBNAME"), job_name,sizeofU(job_name), NULL, &errorInfo);
					
				RfcGetString(table, cU("JOBCOUNT"), job_count_number,sizeofU(job_count_number), NULL, &errorInfo);
					
				RfcGetString(table, cU("STATUS"), job_status,sizeofU(job_status), NULL, &errorInfo);
					
				RfcGetString(table, cU("ENDDATE"), job_end_datum,sizeofU(job_end_datum), NULL, &errorInfo);
					
				RfcGetString(table, cU("ENDTIME"), job_end_uhrzeit,sizeofU(job_end_uhrzeit), NULL, &errorInfo);
					

				
				rc = RfcSAPUCToUTF8(job_status, strlenU(job_status), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
				if (rc == RFC_BUFFER_TOO_SMALL)
				{
					rc = RfcSAPUCToUTF8(job_status, strlenU(job_status), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
				}
				
				std::stringstream ConvertStream;
				ConvertStream<<message_char;
				ConvertStream>>message_string;
				
				wo_ist_status_A = message_string.find("A");
				
				if (wo_ist_status_A > -1)
				{	
					
					
					
					
					
					
					wo_ist_status_A = -1;

					
					rc = RfcSAPUCToUTF8(job_name, strlenU(job_name), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
					if (rc == RFC_BUFFER_TOO_SMALL)
					{
						rc = RfcSAPUCToUTF8(job_name, strlenU(job_name), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
					}
					std::stringstream ConvertStream;
					ConvertStream<<	message_char;
					ConvertStream>>job_name_string;
					
					
			
					
					rc = RfcSAPUCToUTF8(job_count_number, strlenU(job_count_number), (RFC_BYTE *)message_char_2, &message_2_int, &result_length_2, &errorInfo);
					if (rc == RFC_BUFFER_TOO_SMALL)
					{
						rc = RfcSAPUCToUTF8(job_count_number, strlenU(job_count_number), (RFC_BYTE *)message_char_2, &message_2_int, &result_length_2, &errorInfo);
					}
					std::stringstream ConvertStream_2;
					ConvertStream_2<<message_char_2;
					ConvertStream_2>>job_count_string;
					
					
		
					
					rc = RfcSAPUCToUTF8(job_end_datum, strlenU(job_end_datum), (RFC_BYTE *)message_char_3, &message_3_int, &result_length_3, &errorInfo);
					if (rc == RFC_BUFFER_TOO_SMALL)
					{
						rc = RfcSAPUCToUTF8(job_end_datum, strlenU(job_end_datum), (RFC_BYTE *)message_char_3, &message_3_int, &result_length_3, &errorInfo);
					}
					std::stringstream ConvertStream_3;
					ConvertStream_3<<message_char_3;
					ConvertStream_3>>job_end_datum_string;
					

					
					rc = RfcSAPUCToUTF8(job_end_uhrzeit, strlenU(job_end_uhrzeit), (RFC_BYTE *)message_char_4, &message_4_int, &result_length_4, &errorInfo);
					if (rc == RFC_BUFFER_TOO_SMALL)
					{
						rc = RfcSAPUCToUTF8(job_end_uhrzeit, strlenU(job_end_uhrzeit), (RFC_BYTE *)message_char_4, &message_4_int, &result_length_4, &errorInfo);
					}
					std::stringstream ConvertStream_4;
					ConvertStream_4<<message_char_4;
					ConvertStream_4>>job_end_uhrzeit_string;
					

					vector_format = job_name_string + ";;" + job_count_string + "##" + job_end_datum_string + ";#;" + job_end_uhrzeit_string;
					job_name_und_job_count_array.push_back(vector_format);

					
					
					
					
					
					
					
					
					

					
					
				}
		
			}
			
			
	
			RfcDestroyFunction(rfc_handle, &errorInfo);
			RfcCloseConnection(conn, NULL);
			
			
			

			int anzahl_aborted_jobs = -1;
			string job_name_temp;
			string job_name_temp_2;
			vector<string> job_name_array_2;
			int groesste_job_count_zahl = -1;
			bool job_count_bool = false;
			int wo_ist_semikolon = -1;
			int wo_ist_doppel_gatter = -1;
			int wo_ist_semi_gatter_semi = -1;
			string datum ;
			int datum_int = -1;
			int datum_int_temp = -1;
			string uhrzeit ;
			int uhrzeit_int = -1;
			
			int uhrzeit_int_temp = -1;
			int uhrzeit_temp_vergleich = -1;
			bool tru = true;
			char *end; 
			vector<string> job_name_array_3;
			int wo_ist_jobname = -1;
			string job_name_temp_3;
			int wo_ist_datum = -1;
			
			string datum_string_temp;
			int wo_ist_uhrzeit = -1;
			
			string uhrzeit_string_temp;
			
			string datum_string_temp_2;
			std::stringstream uhrzeit_string_temp_sstream;
			vector<string> aborted_jobs;
			string output_format;
			
			

			

			
			for (int j = 0; j < job_name_und_job_count_array.size(); j++)
			
			{
		
				
				wo_ist_semikolon = job_name_und_job_count_array[j].find(";;");
				
				job_name_temp = job_name_und_job_count_array[j].substr(0,wo_ist_semikolon);
		
				if (job_name_temp.compare(job_name_temp_2) == 0)
				
				
				{
					
					
					

					job_name_array_2.push_back(job_name_und_job_count_array[j]);
			
				}
				if (job_name_temp.compare(job_name_temp_2) != 0)
				{
					
					job_name_array_3.push_back(job_name_temp);

					if (job_name_array_2.size() == 0)
					{
						job_name_temp_2 = job_name_und_job_count_array[j].substr(0,wo_ist_semikolon);
						
						continue;
					}
					

				}
				
				
				
				if (j == job_name_und_job_count_array.size() - 1)
				{
					
					
					
					
				}
				job_name_temp_2 = job_name_und_job_count_array[j].substr(0,wo_ist_semikolon);
			
				
				
				
				
				
			
			}
			
			
			
			
			
			for (int k = 0; k < job_name_array_3.size(); k++)
			{
				

				
				for (int l = 0; l < job_name_und_job_count_array.size(); l++)
				{

					wo_ist_jobname = job_name_und_job_count_array[l].find(job_name_array_3[k] + ";;");		
					
					
					

					if (wo_ist_jobname != -1 )
					
					{
						wo_ist_doppel_gatter = job_name_und_job_count_array[l].find("##");
						datum = job_name_und_job_count_array[l].substr(wo_ist_doppel_gatter + 2, 8);
						datum_int = atoi(datum.c_str());
						if (datum_int > datum_int_temp)
						{
							datum_int_temp = datum_int;
							
							
						}
					}
				}
				
				

		
				
				for (int m = 0; m < job_name_und_job_count_array.size(); m++)
				{
					wo_ist_jobname = job_name_und_job_count_array[m].find(job_name_array_3[k]);
					
			
					
					
					datum_string_temp = std::to_string(datum_int_temp);
					wo_ist_datum = job_name_und_job_count_array[m].find(datum_string_temp);

					
					if ( (wo_ist_jobname != -1) && (wo_ist_datum != -1) )
					
					{
						
						wo_ist_semi_gatter_semi =  job_name_und_job_count_array[m].find(";#;");
						uhrzeit = job_name_und_job_count_array[m].substr(wo_ist_semi_gatter_semi + 3, 6);
						
						
						
						uhrzeit_int = atoi(uhrzeit.c_str());
						if(uhrzeit_int > uhrzeit_int_temp)
						{
							uhrzeit_int_temp = uhrzeit_int;
						}

					}
					wo_ist_datum = -1;
					wo_ist_jobname = -1; 
		
				}
				
				


			
			for (int n = 0; n < job_name_und_job_count_array.size(); n++)
			{
			
				
				
				
				
				
				datum_string_temp_2 = std::to_string(datum_int_temp);
				
				wo_ist_datum = job_name_und_job_count_array[n].find(datum_string_temp_2);
				
				

				
				
				
				
				uhrzeit_string_temp = std::to_string(uhrzeit_int_temp);
				
				
				uhrzeit_string_temp.insert(0, 6 - uhrzeit_string_temp.length(), '0');			
				
				wo_ist_uhrzeit = job_name_und_job_count_array[n].find(uhrzeit_string_temp);
				
				

				wo_ist_jobname = job_name_und_job_count_array[n].find(job_name_array_3[k]);
				
				
			
				
				if( (wo_ist_jobname != -1) && (wo_ist_datum != -1) && (wo_ist_uhrzeit != -1) )
				
				
				{
					
					
					
					uhrzeit_int_temp = -1;
					uhrzeit_int = -1;
					datum_int = -1;
					datum_int_temp = -1;
					wo_ist_jobname = -1;
					wo_ist_doppel_gatter = -1;
					datum = "";
					wo_ist_datum = -1;
					uhrzeit = "";
					wo_ist_uhrzeit = -1;
					uhrzeit_string_temp = "";
					datum_string_temp = "";
					datum_string_temp_2 = "";
					aborted_jobs.push_back(job_name_und_job_count_array[n]);
					continue;				
				}
				wo_ist_jobname = -1; wo_ist_uhrzeit = -1; wo_ist_datum = -1;
			
			}
		
			uhrzeit_int_temp = -1;
			uhrzeit_int = -1;
			datum_int = -1;
			datum_int_temp = -1;
			wo_ist_jobname = -1;
			wo_ist_doppel_gatter = -1;
			datum = "";
			wo_ist_datum = -1;
			uhrzeit = "";
			wo_ist_uhrzeit = -1;
			uhrzeit_string_temp = "";
			datum_string_temp = "";
			datum_string_temp_2 = "";
			
		
		}
	
		sort( aborted_jobs.begin(), aborted_jobs.end() );
		aborted_jobs.erase( unique( aborted_jobs.begin(), aborted_jobs.end() ), aborted_jobs.end() );
		
		
		if(aborted_jobs.size() > 0)
		{
			cout<<"CRITICAL -"<<"\t";
			
		}	
			
		for (int p = 0; p < aborted_jobs.size(); p++)
		{
			
			
			output_format = aborted_jobs[p];
			
			const char x = ';';
    		const char y = '#';
			
			std::replace(output_format.begin(), output_format.end(), x, y);
			
			
			
			
			cout<<output_format <<"\t";
		}
		
		if(aborted_jobs.size() > 0)
		{
			
			cout<<endl;
			exit(2);
		}	
		
		
		
		
		
		
	
		
		
		
		

	}
		
		
		
		
		int wo_ist_abap_dump_parameter = - 1;
		wo_ist_abap_dump_parameter = parameter.find("-abap-dump");
		std::regex regex_4("^-abap-dump$");
		
		if (std::regex_search(parameter, reg_match, regex_4))
		{
			
			
			#define NUM_PARAMS 9
			RFC_CONNECTION_PARAMETER loginParams[NUM_PARAMS];

			
			unsigned resultLen = 0;
			
			
			
			
			
			string username;
			username = argv[2];
			
			int wo_ist_gleich = - 1;
			wo_ist_gleich = username.find("=");
			username = username.substr(wo_ist_gleich + 1,username.length());
			
			
			SAP_UC *username_sapuc = NULL;
			unsigned username_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (username_sapuc == NULL)
			{
				
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
				
			
			
			
			
			
			
			string password;
			password = argv[3];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = password.find("=");
			password = password.substr(wo_ist_gleich + 1,password.length());
			
			
			SAP_UC *password_sapuc = NULL;
			unsigned password_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			
			{
				
				
				
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (password_sapuc == NULL)
			{
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			
			
			
			
			string hostname;
			hostname = argv[4];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = hostname.find("=");
			hostname = hostname.substr(wo_ist_gleich + 1,hostname.length());
			
			
			SAP_UC *hostname_sapuc = NULL;
			unsigned hostname_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (hostname_sapuc == NULL)
			{
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				

			
			
			
			
			
			
			string sid;
			sid = argv[5];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sid.find("=");
			sid = sid.substr(wo_ist_gleich + 1,sid.length());
			
			
			SAP_UC *sid_sapuc = NULL;
			
			
			unsigned sid_sapuc_len;
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sid_sapuc == NULL)
			{
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			

			
			string sysnr;
			sysnr = argv[6];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sysnr.find("=");
			sysnr = sysnr.substr(wo_ist_gleich + 1,sysnr.length());
			
			
			SAP_UC *sysnr_sapuc = NULL;
			
			
			
			
			unsigned sysnr_sapuc_len;
			
			resultLen = 0;
			
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sysnr_sapuc == NULL)
			{
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
	
			
			
			

			
			string client_nr;
			client_nr = argv[7];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = client_nr.find("=");
			client_nr = client_nr.substr(wo_ist_gleich + 1,client_nr.length());
			
			
			SAP_UC *client_nr_sapuc = NULL;
			unsigned client_nr_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (client_nr_sapuc == NULL)
			{
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			
			

			loginParams[0].name = cU("dest");
			loginParams[0].value = cU("DEV");
			loginParams[1].name =cU("user");
				
			loginParams[1].value = username_sapuc;
			loginParams[2].name = cU("passwd");
				
			loginParams[2].value = password_sapuc;
			loginParams[3].name = cU("ASHOST");
				
			loginParams[3].value = hostname_sapuc;
			loginParams[4].name = cU("SYSID");
				
			loginParams[4].value = sid_sapuc;
			loginParams[5].name = cU("SYSNR");
				
			loginParams[5].value = sysnr_sapuc;
			loginParams[6].name = cU("CLIENT");
				
			loginParams[6].value = client_nr_sapuc;
			loginParams[7].name = cU("lang");
			loginParams[7].value = cU("EN");
			loginParams[8].name = cU("TRACE");
			loginParams[8].value = cU("0");
	


			RFC_CONNECTION_HANDLE conn;
			conn = RfcOpenConnection(loginParams, NUM_PARAMS, &errorInfo);
				
				
				
				
			if (errorInfo.code != RFC_OK) 
			{
				cout<<"Login PROBLEM"<<endl;
				printfU(cU("key# %s: %d\n"),errorInfo.key);
				printfU(cU("message# %s: %d\n"),errorInfo.message);
				printfU(cU("code# %d\n"),errorInfo.code);
				exit(-1);
			}

		RFC_FUNCTION_DESC_HANDLE ccms_bapi_handle;
		
		
		RFC_FUNCTION_HANDLE rfc_handle;

		
		SAP_UC message[8192] = iU("");
		RFC_STRUCTURE_HANDLE returnStructure;

		

		ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_XMI_LOGON"), &errorInfo);
		
		rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
		RfcSetChars(rfc_handle, cU("EXTCOMPANY"), cU("TESTCOPMANY"), 11, &errorInfo);
		RfcSetChars(rfc_handle, cU("EXTPRODUCT"), cU("TESTPRODUKT"), 11, &errorInfo);
		
		RfcSetChars(rfc_handle, cU("INTERFACE"), cU("XBP"), 3, &errorInfo);
		RfcSetChars(rfc_handle, cU("VERSION"), cU("1.0"), 3, &errorInfo);
		rc = RfcInvoke(conn, rfc_handle, &errorInfo);
		
		
		
		
		

		
		ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("/SDF/GET_DUMP_LOG"), &errorInfo);
		rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
		

		RfcSetChars(rfc_handle, cU("DATE_FROM"), cU("1900-01-01"), 10, &errorInfo);	
			
			
			

		RfcSetChars(rfc_handle, cU("DATE_TO"), cU("2999-12-31"), 10, &errorInfo);	
			
			
			

		RfcSetChars(rfc_handle, cU("TIME_FROM"), cU("00:00:00"), 8, &errorInfo);	
			
			
			

		RfcSetChars(rfc_handle, cU("TIME_TO"), cU("00:00:00"), 8, &errorInfo);	
			
			
			

		rc = RfcInvoke(conn, rfc_handle, &errorInfo);
			
			
			

		RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
		RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
			

		unsigned rowCount = 0;
		RFC_TABLE_HANDLE table;

		rc = RfcGetTable(rfc_handle, cU("ET_E2E_LOG"),&table,&errorInfo);
		RfcGetRowCount(table, &rowCount, &errorInfo);
			

		SAP_UC e2e_date[4096] = iU("");
		SAP_UC e2e_time[4096] = iU("");
		SAP_UC e2e_user[4096] = iU("");
		SAP_UC e2e_severity[4096] = iU("");
		SAP_UC e2e_host[4096] = iU("");
		SAP_UC field1[4096] = iU("");
		SAP_UC field4[4096] = iU("");
		SAP_UC field9[4096] = iU("");

		string e2e_date_string;
		char message_char[5000];
		unsigned message_int;
		unsigned result_length;
		string e2e_time_string;
		char message_char_2[5000];
		unsigned message_int_2;
		unsigned result_length_2;
		string e2e_user_string;
		char message_char_3[5000];
		unsigned message_int_3;
		unsigned result_length_3;
		string e2e_severity_string;
		char message_char_4[5000];
		unsigned message_int_4;
		unsigned result_length_4;
		string e2e_host_string;
		char message_char_5[5000];
		unsigned message_int_5;
		unsigned result_length_5;
		string field1_string;
		char message_char_6[5000];
		unsigned message_int_6;
		unsigned result_length_6;
		string field4_string;
		char message_char_7[5000];
		unsigned message_int_7;
		unsigned result_length_7;
		string field9_string;
		char message_char_8[5000];
		unsigned message_int_8;
		unsigned result_length_8;
		string abap_dumps_format;
		vector<string> abap_dumps;
		
			
		
		for (unsigned i=0; i < 3; ++i) 
		{	
			RfcMoveTo(table, i, NULL);
				
				
				

			
			RfcGetString(table, cU("E2E_DATE"), e2e_date,sizeofU(e2e_date), NULL, &errorInfo);
				
				
			rc = RfcSAPUCToUTF8(e2e_date, strlenU(e2e_date), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(e2e_date, strlenU(e2e_date), (RFC_BYTE *)message_char, &message_int, &result_length, &errorInfo);
			}
			e2e_date_string = message_char;
			

			
			RfcGetString(table, cU("E2E_TIME"), e2e_time,sizeofU(e2e_time), NULL, &errorInfo);
				
				
			rc = RfcSAPUCToUTF8(e2e_time, strlenU(e2e_time), (RFC_BYTE *)message_char_2, &message_int_2, &result_length_2, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(e2e_time, strlenU(e2e_time), (RFC_BYTE *)message_char_2, &message_int_2, &result_length_2, &errorInfo);
			}
			e2e_time_string = message_char_2;
			

			
			RfcGetString(table, cU("E2E_USER"), e2e_user,sizeofU(e2e_user), NULL, &errorInfo);
				
				
			rc = RfcSAPUCToUTF8(e2e_user, strlenU(e2e_user), (RFC_BYTE *)message_char_3, &message_int_3, &result_length_3, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(e2e_user, strlenU(e2e_user), (RFC_BYTE *)message_char_3, &message_int_3, &result_length_3, &errorInfo);
			}
			e2e_user_string = message_char_3;
			

			
			RfcGetString(table, cU("E2E_SEVERITY"), e2e_severity,sizeofU(e2e_severity), NULL, &errorInfo);
				
				
			rc = RfcSAPUCToUTF8(e2e_severity, strlenU(e2e_severity), (RFC_BYTE *)message_char_4, &message_int_4, &result_length_4, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(e2e_severity, strlenU(e2e_severity), (RFC_BYTE *)message_char_4, &message_int_4, &result_length_4, &errorInfo);
			}
			e2e_severity_string = message_char_4;
			

			
			RfcGetString(table, cU("E2E_HOST"), e2e_host,sizeofU(e2e_host), NULL, &errorInfo);
				
				
			rc = RfcSAPUCToUTF8(e2e_host, strlenU(e2e_host), (RFC_BYTE *)message_char_5, &message_int_5, &result_length_5, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(e2e_host, strlenU(e2e_host), (RFC_BYTE *)message_char_5, &message_int_5, &result_length_5, &errorInfo);
			}
			e2e_host_string = message_char_5;
			

			
			RfcGetString(table, cU("FIELD1"), field1,sizeofU(field1), NULL, &errorInfo);
				
				
			rc = RfcSAPUCToUTF8(field1, strlenU(field1), (RFC_BYTE *)message_char_6, &message_int_6, &result_length_6, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(field1, strlenU(field1), (RFC_BYTE *)message_char_6, &message_int_6, &result_length_6, &errorInfo);
			}
			field1_string = message_char_6;
			

			
			RfcGetString(table, cU("FIELD4"), field4,sizeofU(field4), NULL, &errorInfo);
				
				
			rc = RfcSAPUCToUTF8(field4, strlenU(field4), (RFC_BYTE *)message_char_7, &message_int_7, &result_length_7, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(field4, strlenU(field4), (RFC_BYTE *)message_char_7, &message_int_7, &result_length_7, &errorInfo);
			}
			field4_string = message_char_7;
			

			
			RfcGetString(table, cU("FIELD9"), field9,sizeofU(field9), NULL, &errorInfo);
				
			rc = RfcSAPUCToUTF8(field9, strlenU(field9), (RFC_BYTE *)message_char_8, &message_int_8, &result_length_8, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				rc = RfcSAPUCToUTF8(field9, strlenU(field9), (RFC_BYTE *)message_char_8, &message_int_8, &result_length_8, &errorInfo);
			}
			field9_string = message_char_8;
			


			abap_dumps_format = e2e_date_string + "###" + e2e_time_string + ";;;" + e2e_severity_string + "#;#" + e2e_host_string + ";#;" + field1_string + "##;" + field4_string + ";;#" + field9_string + "+++" + e2e_user_string;
			abap_dumps.push_back(abap_dumps_format);

		}
			
		
		RfcDestroyFunction(rfc_handle, &errorInfo);
		RfcCloseConnection(conn, NULL);
		
		
		string command_1;
		command_1 = "cp /tmp/sap_mon_abap_dump.log /tmp/sap_mon_abap_dump_diff.log > /dev/null";
		system(command_1.c_str());

		ofstream sap_mon_abap_dump;
		sap_mon_abap_dump.open ("/tmp/sap_mon_abap_dump.log");

		for (int j = 0; j < abap_dumps.size(); j++)
		{
			
			
			sap_mon_abap_dump<<abap_dumps[j]<<endl;

		}
		sap_mon_abap_dump.close();	
		
		
		string command_2;
		command_2 = "/usr/bin/diff --changed-group-format='%<%>' --unchanged-group-format='' /tmp/sap_mon_abap_dump.log /tmp/sap_mon_abap_dump_diff.log | cut -f 1 -d$'\n' --complement";
		char *command_char = {(char *) command_2.c_str()}; 
		FILE *pipe;
		char str[900000];
		pipe = popen (command_char, "r" );
		if(pipe == NULL)
		{
			perror("open failed");
			pclose(pipe);
			exit(0);
		}
		string command_rueckgabe_temp = "";
		string command_rueckgabe = "";
		vector<string> abap_dumps_diff;

		while(fgets ( str, 900000, pipe ) != NULL)
			{
				command_rueckgabe_temp = string(str);
				command_rueckgabe.append(command_rueckgabe_temp);
				
				
				
				abap_dumps_diff.push_back(command_rueckgabe);
			}
		
		pclose(pipe);
		
		string output_format;
		string datum;
		int wo_ist_datum = -1;
		string uhrzeit ;
		int wo_ist_uhrzeit = -1;
		string severity;
		int wo_ist_severity = -1;
		int wo_ist_hostname = -1;
		int wo_ist_runtime_error = -1;
		string hostname_output;
		int wo_ist_abap_programm;
		string runtime_error;
		int wo_ist_exception = -1;
		string abap_programm;
		int wo_ist_username = -1;
		string exception;
		string username_output;
			
		for (int k = 0; k < abap_dumps_diff.size(); k++)
		{
			
			wo_ist_datum = abap_dumps_diff[k].find("###");
			datum = abap_dumps_diff[k].substr(0,wo_ist_datum);
			

			
			uhrzeit = abap_dumps_diff[k].substr(wo_ist_datum + 3,6);
			

			wo_ist_severity = abap_dumps_diff[k].find(";;;");
			wo_ist_hostname = abap_dumps_diff[k].find("#;#");
			
			severity = abap_dumps_diff[k].substr(wo_ist_severity + 3,wo_ist_hostname - wo_ist_severity - 3);
			

			wo_ist_runtime_error = abap_dumps_diff[k].find(";#;");
			hostname_output = abap_dumps_diff[k].substr(wo_ist_hostname + 3 , wo_ist_runtime_error - wo_ist_hostname - 3);
			
			

			wo_ist_runtime_error = abap_dumps_diff[k].find(";#;");
			wo_ist_abap_programm = abap_dumps_diff[k].find("##;");
			runtime_error = abap_dumps_diff[k].substr(wo_ist_runtime_error + 3, wo_ist_abap_programm - wo_ist_runtime_error - 3);
			

			wo_ist_exception = abap_dumps_diff[k].find(";;#");
			abap_programm = abap_dumps_diff[k].substr(wo_ist_abap_programm + 3, wo_ist_exception - wo_ist_abap_programm - 3);
			

			wo_ist_username = abap_dumps_diff[k].find("+++");
			exception = abap_dumps_diff[k].substr(wo_ist_exception + 3, wo_ist_username - wo_ist_exception - 3);
			

			username_output = abap_dumps_diff[k].substr(wo_ist_username + 3, abap_dumps_diff[k].length() );
			username_output.erase(std::remove(username_output.begin(), username_output.end(), '\n'), username_output.end());
			

			output_format = "CRITICAL - ABAP Programm: " + abap_programm + " ### Runtime error: " + runtime_error + " ### Exception: " + exception + " ### Schweregrad: " + severity + " ### Hostname: " + hostname_output + " ### Username: " + username_output + " ### Datum: " + datum + " ### Uhrzeit: " + uhrzeit ;
			cout<<output_format<<endl;

			exit(2);
		}
	
		if (abap_dumps_diff.size() == 0);
		{
			exit(0);
		}

	
	}
		
		
		
		
		
		
		
		
		int wo_ist_check_ALL_parameter = - 1;
		wo_ist_check_ALL_parameter = parameter.find("-checkall");
		
		std::regex regex_5("^-checkall$");
		
		if (std::regex_search(parameter, reg_match, regex_5))
		{
			
			
			#define NUM_PARAMS 9
			RFC_CONNECTION_PARAMETER loginParams[NUM_PARAMS];
			unsigned resultLen = 0;
			
			
			
			
			
			string username;
			username = argv[2];
			
			int wo_ist_gleich = - 1;
			wo_ist_gleich = username.find("=");
			username = username.substr(wo_ist_gleich + 1,username.length());
			
			
			SAP_UC *username_sapuc = NULL;
			unsigned username_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (username_sapuc == NULL)
			{
				
				username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)username.c_str(),strlen(username.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			string password;
			password = argv[3];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = password.find("=");
			password = password.substr(wo_ist_gleich + 1,password.length());
			
			
			SAP_UC *password_sapuc = NULL;
			unsigned password_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			
			{
				
				
				
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (password_sapuc == NULL)
			{
				
				password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)password.c_str(),strlen(password.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			string hostname;
			hostname = argv[4];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = hostname.find("=");
			hostname = hostname.substr(wo_ist_gleich + 1,hostname.length());
			
			
			SAP_UC *hostname_sapuc = NULL;
			unsigned hostname_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (hostname_sapuc == NULL)
			{
				
				hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname.c_str(),strlen(hostname.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				

			
			
			
			
			
			string sid;
			sid = argv[5];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sid.find("=");
			sid = sid.substr(wo_ist_gleich + 1,sid.length());
			
			
			SAP_UC *sid_sapuc = NULL;
			
			
			unsigned sid_sapuc_len;
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sid_sapuc == NULL)
			{
				
				sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid.c_str(),strlen(sid.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
			
			

			
			string sysnr;
			sysnr = argv[6];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = sysnr.find("=");
			sysnr = sysnr.substr(wo_ist_gleich + 1,sysnr.length());
			
			
			SAP_UC *sysnr_sapuc = NULL;
			
			
			
			
			unsigned sysnr_sapuc_len;
			
			resultLen = 0;
			
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (sysnr_sapuc == NULL)
			{
				
				sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr.c_str(),strlen(sysnr.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
	
			
			
			

			
			string client_nr;
			client_nr = argv[7];
			
			wo_ist_gleich = - 1;
			wo_ist_gleich = client_nr.find("=");
			client_nr = client_nr.substr(wo_ist_gleich + 1,client_nr.length());
			
			
			SAP_UC *client_nr_sapuc = NULL;
			unsigned client_nr_sapuc_len;			
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
				
				
				
				
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				
				
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
			if (client_nr_sapuc == NULL)
			{
				
				client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr.c_str(),strlen(client_nr.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}
				
			
			
		
			
			loginParams[0].name = cU("dest");
			loginParams[0].value = cU("DEV");
			loginParams[1].name =cU("user");
				
			loginParams[1].value = username_sapuc;
			loginParams[2].name = cU("passwd");
				
			loginParams[2].value = password_sapuc;
			loginParams[3].name = cU("ASHOST");
				
			loginParams[3].value = hostname_sapuc;
			loginParams[4].name = cU("SYSID");
				
			loginParams[4].value = sid_sapuc;
			loginParams[5].name = cU("SYSNR");
				
			loginParams[5].value = sysnr_sapuc;
			loginParams[6].name = cU("CLIENT");
				
			loginParams[6].value = client_nr_sapuc;
			loginParams[7].name = cU("lang");
			loginParams[7].value = cU("EN");
			loginParams[8].name = cU("TRACE");
			loginParams[8].value = cU("0");
	
			RFC_CONNECTION_HANDLE conn;
			conn = RfcOpenConnection(loginParams, NUM_PARAMS, &errorInfo);
				
				
				
				
			if (errorInfo.code != RFC_OK) 
			{
				cout<<"Login PROBLEM"<<endl;
				printfU(cU("key# %s: %d\n"),errorInfo.key);
				printfU(cU("message# %s: %d\n"),errorInfo.message);
				printfU(cU("code# %d\n"),errorInfo.code);
				exit(-1);
						
			}

			
			RFC_STRUCTURE_HANDLE returnStructure;
			RFC_FUNCTION_DESC_HANDLE ccms_bapi_handle;
			RFC_FUNCTION_HANDLE rfc_handle;
				
			SAP_UC message[8192] = iU("");
			
			
			
			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_XMI_LOGON"), &errorInfo);
			
			
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTCOMPANY"), cU("TESTCOPMANY"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTPRODUCT"), cU("TESTPRODUKT"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("INTERFACE"), cU("XAL"), 3, &errorInfo);
			RfcSetChars(rfc_handle, cU("VERSION"), cU("1.0"), 3, &errorInfo);
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);
				
				
				
				
			
			

			
			string monitor_name_temp_2;
			string monitor_name;
			
			
			monitor_name_temp_2 = argv[8];
			
			int wo_ist_gleich_2 = - 1;
			wo_ist_gleich_2 = monitor_name_temp_2.find("=");
			int mointor_lange = 0;
			mointor_lange = monitor_name_temp_2.length();
			
			monitor_name = monitor_name_temp_2.substr(wo_ist_gleich_2 + 1, mointor_lange);
			

			
			
			int wo_ist_backslash = - 1;
			wo_ist_backslash = monitor_name.find("\\");
			
			string ms_name_2;
			ms_name_2 = monitor_name.substr(0,wo_ist_backslash);
			

			
			SAP_UC *ms_name_sapuc = NULL;
			unsigned ms_name_sapuc_len;	
			resultLen = 0;
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)ms_name_2.c_str(),strlen(ms_name_2.c_str()),ms_name_sapuc, &ms_name_sapuc_len, &resultLen,  &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL)
			{
				ms_name_sapuc = (SAP_UC*)reallocU(ms_name_sapuc, ms_name_sapuc_len);
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)ms_name_2.c_str(),strlen(ms_name_2.c_str()),ms_name_sapuc, &ms_name_sapuc_len, &resultLen,  &errorInfo);
			}
			if (ms_name_sapuc == NULL)
			{
				
				ms_name_sapuc = (SAP_UC*)reallocU(ms_name_sapuc, ms_name_sapuc_len);
				
				rc = RfcUTF8ToSAPUC((RFC_BYTE*)ms_name_2.c_str(),strlen(ms_name_2.c_str()),ms_name_sapuc, &ms_name_sapuc_len, &resultLen,  &errorInfo);
					
					
					
					
			}

			

			
			int wo_ist_backslash_2 = - 1;
			wo_ist_backslash_2 = monitor_name.find("\\",wo_ist_backslash + 1);
			
			

			string moni_name_2 = monitor_name.substr(wo_ist_backslash + 1, wo_ist_backslash_2 - wo_ist_backslash - 1);


			
			SAP_UC *moni_name_sapuc = NULL;
			unsigned moni_name_sapuc_len;	
			resultLen = - 1;

			int n = moni_name_2.length();
			char char_array[n + 1];
			rc = RfcUTF8ToSAPUC((RFC_BYTE*)char_array,n + 1,moni_name_sapuc, &moni_name_sapuc_len, &resultLen,  &errorInfo);



			
			
				
				if (rc == 20)
				{
					
					
					moni_name_sapuc = (SAP_UC*)reallocU(moni_name_sapuc, moni_name_sapuc_len);
					rc = RfcUTF8ToSAPUC((RFC_BYTE*)moni_name_2.c_str(),strlen(moni_name_2.c_str()),moni_name_sapuc, &moni_name_sapuc_len, &resultLen,  &errorInfo);
					
					
				}
				if (rc == RFC_BUFFER_TOO_SMALL)
				{
					
					moni_name_sapuc = (SAP_UC*)reallocU(moni_name_sapuc, moni_name_sapuc_len);
					rc = RfcUTF8ToSAPUC((RFC_BYTE*)moni_name_2.c_str(),strlen(moni_name_2.c_str()),moni_name_sapuc, &moni_name_sapuc_len, &resultLen,  &errorInfo);
					
					
				}
				if (moni_name_sapuc == NULL)
				{
					
					moni_name_sapuc = (SAP_UC*)reallocU(moni_name_sapuc, moni_name_sapuc_len);
					rc = RfcUTF8ToSAPUC((RFC_BYTE*)moni_name_2.c_str(),strlen(moni_name_2.c_str()),moni_name_sapuc, &moni_name_sapuc_len, &resultLen,  &errorInfo);
					
					
				}
				if (rc == 23)
				{
					
					moni_name_sapuc = (SAP_UC*)reallocU(moni_name_sapuc, moni_name_sapuc_len);
					rc = RfcUTF8ToSAPUC((RFC_BYTE*)moni_name_2.c_str(),strlen(moni_name_2.c_str()),moni_name_sapuc, &moni_name_sapuc_len, &resultLen,  &errorInfo);
					
					
				}
			


			









			

			
			
			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MON_GETTREE"), &errorInfo);
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			
			RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("RFC_TEST"), 8, &errorInfo);
			
			RfcSetInt(rfc_handle, cU("MAX_TREE_DEPTH"), 0,&errorInfo);

			RfcGetStructure(rfc_handle, cU("MONITOR_NAME"), &returnStructure, &errorInfo);
			
			RfcSetChars(returnStructure, cU("MONI_NAME"), moni_name_sapuc,strlenU(moni_name_sapuc), &errorInfo);			
			
			RfcSetChars(returnStructure, cU("MS_NAME"),ms_name_sapuc,strlenU(ms_name_sapuc), &errorInfo);			

			RfcSetInt(rfc_handle, cU("VIS_ON_USR_LEVEL"), 6,&errorInfo);
			
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);

			
			
			

			
			


			
			unsigned rowCount = 0;
			RFC_TABLE_HANDLE table;
			rc = RfcGetTable(rfc_handle, cU("TREE_NODES"),&table,&errorInfo);
			
			RfcGetRowCount(table, &rowCount, &errorInfo);
				

			SAP_UC ms_name[4096] = iU("");
			SAP_UC moni_name[4096] = iU("");

			SAP_UC context_name[4096] = iU("");
			SAP_UC mte_name[4096] = iU("");
			SAP_UC object_name[4096] = iU("");
			SAP_UC system_id[4096] = iU("");

			
			RFC_TABLE_HANDLE table_2;
			
			unsigned rowCount_2 = 0;
			
			string message_string_mtclass;
			
			
			for (unsigned i = 0; i < rowCount; ++i) 
			
			
			{
				RfcMoveTo(table, i, NULL);
				
				RfcGetString(table, cU("MTSYSID"), system_id,sizeofU(ms_name), NULL, &errorInfo);
					
					printfU(cU("%s\\"), system_id);
					
				RfcGetString(table, cU("MTMCNAME"), context_name,sizeofU(ms_name), NULL, &errorInfo);
					
					printfU(cU("%s\\"), context_name);
					
				
				
					
				
				
					
				
				
					
				
				
					
				
				
					
				RfcGetString(table, cU("OBJECTNAME"), object_name,sizeofU(ms_name), NULL, &errorInfo);
					
					printfU(cU("%s\\"), object_name);	
					
				RfcGetString(table, cU("MTNAMESHRT"), mte_name,sizeofU(ms_name), NULL, &errorInfo);
					
					printfU(cU("%s "), mte_name);	
					
				
				
				
				ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETTIDBYNAME"), &errorInfo);
						
				rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);

				
				
				
				
				
				RfcSetChars(rfc_handle, cU("CONTEXT_NAME"), context_name, strlenU(context_name), &errorInfo);	
				RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 26, &errorInfo);
				RfcSetChars(rfc_handle, cU("MTE_NAME"), mte_name, strlenU(mte_name), &errorInfo);	
				RfcSetChars(rfc_handle, cU("OBJECT_NAME"), object_name, strlenU(object_name), &errorInfo);	
				RfcSetChars(rfc_handle, cU("SYSTEM_ID"), system_id, strlenU(system_id), &errorInfo);	

				
				rc = RfcInvoke(conn, rfc_handle, &errorInfo);

				RFC_STRUCTURE_HANDLE returnStructure;

				RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					
					
					
					
				rc = RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					
					
					
					
					
				
				SAP_UC message_mtclass[9999] = iU("");
							
				RfcGetStructure(rfc_handle, cU("TID"), &returnStructure, &errorInfo);

				RfcGetString(returnStructure, cU("MTSYSID"), message, sizeofU(message), &resultLen, &errorInfo);
					
				RfcGetString(returnStructure, cU("MTMCNAME"), message, sizeofU(message), &resultLen, &errorInfo);
					
				RfcGetString(returnStructure, cU("MTNUMRANGE"), message, sizeofU(message), &resultLen, &errorInfo);
					
				RfcGetString(returnStructure, cU("MTUID"), message, sizeofU(message), &resultLen, &errorInfo);
					
				RfcGetString(returnStructure, cU("MTCLASS"), message_mtclass, sizeofU(message_mtclass), &resultLen, &errorInfo);			
					
				RfcGetString(returnStructure, cU("MTINDEX"), message, sizeofU(message), &resultLen, &errorInfo);
					
				RfcGetString(returnStructure, cU("EXTINDEX"), message, sizeofU(message), &resultLen, &errorInfo);
					
				
				
				
				
				unsigned message_int_mtclass;
				unsigned result_length_mtclass;
				char message_char_mtclass[9999];
				
				resultLen = 0;
				rc = RfcSAPUCToUTF8(message_mtclass, strlenU(message_mtclass), (RFC_BYTE *)message_char_mtclass, &message_int_mtclass, &result_length_mtclass, &errorInfo);
				if (rc == RFC_BUFFER_TOO_SMALL)
				{
					rc = RfcSAPUCToUTF8(message_mtclass, strlenU(message_mtclass), (RFC_BYTE *)message_char_mtclass, &message_int_mtclass, &result_length_mtclass, &errorInfo);
				}
				
				
				
				
				std::stringstream ConvertStream_mtclass;
				
				
				ConvertStream_mtclass<<	message_char_mtclass;
				ConvertStream_mtclass>>message_string_mtclass;
				
				message_string_mtclass = message_string_mtclass.substr(0,3);
				
				
				
				
				
				
				
				
				
				
				if (message_string_mtclass == "050")
				{
					
					cout<<"###";
					cout<<endl;
					continue;
					
				}
				
				
				if (message_string_mtclass == "111")
				{	
					
					
					ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETTXTPROP"), &errorInfo);
					rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
					RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 26, &errorInfo);
					rc = RfcSetStructure(rfc_handle, cU("TID"),returnStructure, &errorInfo);
					rc = RfcInvoke(conn, rfc_handle, &errorInfo);
					RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					RfcGetStructure(rfc_handle, cU("PROPERTIES"), &returnStructure, &errorInfo);
					RfcGetString(returnStructure, cU("TEXT"), message, sizeofU(message), &resultLen, &errorInfo);
						printfU(cU(" %s\n"), message);
				}

				
				if (message_string_mtclass == "101")
				{
					
					ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETMLCURVAL"), &errorInfo);
					rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
					RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 26, &errorInfo);
					rc = RfcSetStructure(rfc_handle, cU("TID"),returnStructure, &errorInfo);
					rc = RfcInvoke(conn, rfc_handle, &errorInfo);
					RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					RfcGetStructure(rfc_handle, cU("XMI_MSG_EXT"), &returnStructure, &errorInfo);
					RfcGetString(returnStructure, cU("MSG"), message, sizeofU(message), &resultLen, &errorInfo);
						printfU(cU(" %s\n"), message);
				

				}
				
				
				if (message_string_mtclass == "102")
				{
					
						
					ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETSMVALUE"), &errorInfo);
					rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
					RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 4, &errorInfo);
					rc = RfcSetStructure(rfc_handle, cU("TID"),returnStructure, &errorInfo);
					rc = RfcInvoke(conn, rfc_handle, &errorInfo);
					RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					RfcGetStructure(rfc_handle, cU("VALUE"), &returnStructure, &errorInfo);
					RfcGetString(returnStructure, cU("MSG"), message, sizeofU(message), &resultLen, &errorInfo);
						printfU(cU(" %s\n"), message);
								
				}
				
				
				if (message_string_mtclass == "100")
				{
					
					
					ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETPERFCURVAL"), &errorInfo);
					rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
					RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External_User_Name_nonsens"), 4, &errorInfo);
					rc = RfcSetStructure(rfc_handle, cU("TID"),returnStructure, &errorInfo);
					rc = RfcInvoke(conn, rfc_handle, &errorInfo);
					RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
					RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);
					RfcGetStructure(rfc_handle, cU("CURRENT_VALUE"), &returnStructure, &errorInfo);
					RfcGetString(returnStructure, cU("ALRELEVVAL"), message, sizeofU(message), &resultLen, &errorInfo);
						printfU(cU(" %s\n"), message);
						
					
					
					
					
				
				}
		
				message_string_mtclass = "";
				message_string_mtclass.clear();
				
				
				
				


				
				
			}
			
			RfcDestroyFunction(rfc_handle, &errorInfo);
			
			RfcCloseConnection(conn, NULL);

					
		}
		
		
		
		
		
		
		
		
		
		
		int wo_ist_ssl_parameter = - 1;
		wo_ist_ssl_parameter = parameter.find("-sslview");
		
		std::regex regex_6("^-sslview$");
		
		if (std::regex_search(parameter, reg_match, regex_6))
		{
			
			ssl_check = false;
			
			
			cout<<"Folgende Zertifikate mit dazugehörigem Ablaufdatum sind in der Zertifikatsliste aktiv"<<endl<<endl;
			
			
			
			username_extern = argv[2];
			password_extern = argv[3];
			hostname_extern = argv[4];
			sid_extern = argv[5];
			sysnr_extern = argv[6];
			client_nr_extern = argv[7];
			
			void ssfp_get_pseinfo();
			ssfp_get_pseinfo();
			
			
	
			void read_cert_infos();
			read_cert_infos();
			
		}
		
		
		
		
		
		
		
		
		
		
		int wo_ist_sslcheck_parameter = - 1;
		wo_ist_sslcheck_parameter = parameter.find("-sslcheck");
		
		std::regex regex_7("^-sslcheck$");
		
		if (std::regex_search(parameter, reg_match, regex_7))
		{
			
			ssl_check = true;
			
			
			username_extern = argv[2];
			password_extern = argv[3];
			hostname_extern = argv[4];
			sid_extern = argv[5];
			sysnr_extern = argv[6];
			client_nr_extern = argv[7];
			string subject_suchen = argv[8];
			
			
			void ssfp_get_pseinfo();
			ssfp_get_pseinfo();
			
			
			
			void read_cert_infos();
			read_cert_infos();
			
			
			
			
			int certlist_array_groesse = - 1;
			certlist_array_groesse = certlist_subj_valid_until.size();
			
			string certlist_subj_valid_until_string;
			int wo_ist_subject_suchen = - 1;
			
			subject_suchen = subject_suchen.substr(13,subject_suchen.length()); 
			
			int wo_ist_trennzeichen = - 1;
			string vaild_until_only_string;
		
			
			for (int i = 0; i < certlist_array_groesse; i++)
			{
				
				
				
				
				
				
				certlist_subj_valid_until_string = certlist_subj_valid_until[i];
							
				
				
				wo_ist_subject_suchen = certlist_subj_valid_until_string.find(subject_suchen);
				
				
				
				
				
				if (wo_ist_subject_suchen >= 0)
				{
					
					
					wo_ist_trennzeichen = certlist_subj_valid_until_string.find(";;;###");
					
					vaild_until_only_string = certlist_subj_valid_until_string.substr(wo_ist_trennzeichen + 6, certlist_subj_valid_until_string.length());
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					const char *valid_until_char = vaild_until_only_string.c_str();

					
					struct tm zeit;
					
					strptime(valid_until_char, "%b %d %H:%M:%S %Y %Z", &zeit);

					char puffer[128];
					strftime(puffer, sizeof(puffer), "%d %b %Y %H:%M:%S", &zeit);

					

					

					
					
					
					
					
					

					
					time_t aktuelle_zeit = std::time(nullptr);
					
					
					int aktuelle_zeit_int = aktuelle_zeit;
					int valid_until_int = mktime(&zeit);
					
					
					
					
					int zeit_differenz = valid_until_int - aktuelle_zeit_int;
					
					
					
					const int stunden_pro_tag = 24;
					const int minuten_pro_stunde = 60;
					const int sekunden_pro_minute = 60;
					
					
					long zeit_differenz_sekunden_long = zeit_differenz;
					
					long sekunden = zeit_differenz_sekunden_long % sekunden_pro_minute;
					long minuten = zeit_differenz_sekunden_long / sekunden_pro_minute % minuten_pro_stunde;
					long tage = zeit_differenz_sekunden_long / sekunden_pro_minute / minuten_pro_stunde / stunden_pro_tag;

					
					
					
					
					
					
					if (argc <= 9)
					{
						
						cout<<tage<<endl;
						exit(0);
					}
					
					
					if (argc > 9)
					{
						string tage_warn = argv[9];
						string tage_critical = argv[10];
			
						
						
						tage_warn = tage_warn.substr(6,tage_warn.length());
						tage_critical = tage_critical.substr(10,tage_critical.length());
						
						std::string::size_type sz;  
						
						long tage_warn_long = stol(tage_warn,&sz);
						
											
						long tage_critical_long = stol(tage_critical,&sz);
						

						
						
						
						
						
						
						
						
						
						
						if ((tage <= tage_warn_long) && ( tage >= tage_critical_long ))
						{
							cout<<"WARNING - "<<tage<<endl;
							exit(1);
						}
						if (tage >= tage_warn_long)
						{
							
							cout<<"OK - "<<tage<<endl;
							exit(0);
						}
						
						if (tage <= tage_critical_long)
						{
							
							cout<<"CRITICAL - "<<tage<<endl;
							exit(2);
						}
						
						
						
						
						
					}
			  
				}
				wo_ist_subject_suchen = - 1;
				wo_ist_trennzeichen = - 1;
			}
			
		}
		
		
		
		
		
		
		
		
		
		int wo_ist_rfc_parameter = - 1;
		wo_ist_rfc_parameter = parameter.find("-rfc");
		
		std::regex regex_8("^-rfc$");
		
		if (std::regex_search(parameter, reg_match, regex_8))
		{
			username_extern = argv[2];
			password_extern = argv[3];
			hostname_extern = argv[4];
			sid_extern = argv[5];
			sysnr_extern = argv[6];
			client_nr_extern = argv[7];
			rfc_destination = argv[8];
			
			void rfc_ping();
			rfc_ping();
			
			
			
			
			
			
			
			if (icinga_retun_code == 0)
			{
				cout<<"OK - RFC destination "<<rfc_destination<<endl;
				
				
				exit(0);
			}
			
			if (icinga_retun_code == 2)
			{
				
				cout<<"critical - "<<rueckgabe_nachricht<<endl;
				
				
				exit(icinga_retun_code);
			}
		}

		
		
		
		
		
		
		
		
		
		int wo_ist_java_parameter = - 1;
		wo_ist_java_parameter = parameter.find("-java");
		
		std::regex regex_9("^-java$");
		if (std::regex_search(parameter, reg_match, regex_9))
		{
			

			
			
			
			
			
			
			
				
			
			
			
			
			sapcontrol_command_extern = argv[7]; 
				
			
			

			
			
			
			
			

			string argv_8;
			
			if (argc > 8)
			{
				
				argv_8 = argv[8]; 
				
				
				
				
				
			}			

			std::regex regex_11("^-sapcontrol=certificate-show$");
			
			if (std::regex_search(argv_8, reg_match, regex_11))
			{
				
				
				username_extern = argv[2];
					
				password_extern = argv[3];
					
				hostname_extern = argv[4];
					
				sid_extern = argv[5];;
					
				sysnr_extern = argv[6];
					
				http_proto_extern = argv[7];
					
				sapcontrol_command_extern = argv[8]; 
					
				
					

				
				vector<string> pse_file_array;
				pse_file_array.push_back("-psefile=SAPSNCS.pse");
				
				pse_file_array.push_back("-psefile=SAPSSLA.pse");
				pse_file_array.push_back("-psefile=SAPSSLC.pse");
				pse_file_array.push_back("-psefile=SAPSSLS.pse");
				pse_file_array.push_back("-psefile=SAPSSLWSSE.pse");
				pse_file_array.push_back("-psefile=SAPSYS.pse");
				pse_file_array.push_back("-psefile=SAPWSSE.pse");
				pse_file_array.push_back("-psefile=SAPSSLS_0.pse");

				for (int i = 0; i < pse_file_array.size(); i++)
				{				
						
						
						
						osexecute_command_path = pse_file_array[i]; 
						
						


					
						sapcontrol_command_extern =	"-sapcontrol=certificate-show";					
						sapgenpse_parameter = "get_my_name ";
						void sapcontrol_commands();
						sapcontrol_commands();
						void web_srv();
						web_srv();
						
						void xml_extract();
						xml_extract();
						
						
						if (cert_subject.length() != 0)
						{
							cout<<"Subject: " + cert_subject + " Validity not after: " + cert_valud_until<<endl;
						}
						
						
						
						
						cert_subject.clear();
						cert_valud_until.clear();

					
						sapcontrol_command_extern.clear();					
						sapcontrol_command_extern =	"-sapcontrol=certificate-show";		
						
						osexecute_command_path = pse_file_array[i]; 
						sapgenpse_parameter.clear();
						sapgenpse_parameter = "maintain_pk -l ";
						void sapcontrol_commands();
						sapcontrol_commands();
						void web_srv();
						web_srv();
						
						void xml_extract();
						xml_extract();
						
						for (int i = 0; i < certlist_array.size(); i++)
						{
							cout<<"Subject: " + certlist_array[i]<<endl;
						}
						certlist_array.clear();
						
						
				}				
			}

			std::regex regex_15("^-checkcertificate=");
			if (std::regex_search(argv_8, reg_match, regex_15))
			{
				
				username_extern = argv[2];
					
				password_extern = argv[3];
					
				hostname_extern = argv[4];
					
				sid_extern = argv[5];;
					
				sysnr_extern = argv[6];
					
				http_proto_extern = argv[7];
					
				sapcontrol_command_extern = argv[8]; 
					
				
					

				
				vector<string> pse_file_array;
				pse_file_array.push_back("-psefile=SAPSNCS.pse");
				
				pse_file_array.push_back("-psefile=SAPSSLA.pse");
				pse_file_array.push_back("-psefile=SAPSSLC.pse");
				pse_file_array.push_back("-psefile=SAPSSLS.pse");
				pse_file_array.push_back("-psefile=SAPSSLWSSE.pse");
				pse_file_array.push_back("-psefile=SAPSYS.pse");
				pse_file_array.push_back("-psefile=SAPWSSE.pse");
				pse_file_array.push_back("-psefile=SAPSSLS_0.pse");
				for (int i = 0; i < pse_file_array.size(); i++)
				{
					
					osexecute_command_path = pse_file_array[i]; 
					
					
					
						sapcontrol_command_extern =	"-sapcontrol=certificate-show";					
						sapgenpse_parameter = "get_my_name ";
						void sapcontrol_commands();
						sapcontrol_commands();
						void web_srv();
						web_srv();
						
						void xml_extract();
						xml_extract();
						
						
						
						if (cert_subject.length() != 0)
						{
							
							int wo_ist_gleich = - 1;
							wo_ist_gleich = argv_8.find("=");
							argv_8 = argv_8.substr(wo_ist_gleich + 1,argv_8.length());
							
							if (cert_subject == argv_8)
							{
								
								void time_converter();
								time_converter();
								
								
								string tage_warn = argv[9];
								string tage_critical = argv[10];
					
								
								
								tage_warn = tage_warn.substr(6,tage_warn.length());
								tage_critical = tage_critical.substr(10,tage_critical.length());
								
								std::string::size_type sz;  
								
								long tage_warn_long = stol(tage_warn,&sz);
								
													
								long tage_critical_long = stol(tage_critical,&sz);
								
								
								
								

								long tage_bis_ablauf_long = tage_bis_ablauf;
								
								
								
								
								
								
								
								
								
								
								
								
								if ((tage_bis_ablauf_long <= tage_warn_long) && ( tage_bis_ablauf_long >= tage_critical_long ))
								{
									cout<<"WARNING - "<<tage_bis_ablauf_long<<endl;
									exit(1);
								}
								if (tage_bis_ablauf_long >= tage_warn_long)
								{
									
									cout<<"OK - "<<tage_bis_ablauf_long<<endl;
									exit(0);
								}
								
								if (tage_bis_ablauf_long <= tage_critical_long)
								{
									
									cout<<"CRITICAL - "<<tage_bis_ablauf_long<<endl;
									exit(2);
								}
						
								
							}
						}
						
					
						sapcontrol_command_extern.clear();
						sapgenpse_parameter.clear();
						osexecute_command_path = pse_file_array[i]; 
						
						
						
						
						sapcontrol_command_extern =	"-sapcontrol=certificate-show";					
						sapgenpse_parameter = "maintain_pk -l ";
						void sapcontrol_commands();
						sapcontrol_commands();
						void web_srv();
						web_srv();
						
						void xml_extract();
						xml_extract();
						
						
						string cert_subject_2;
						for (int i = 0; i < certlist_array.size(); i++)
						{
							
							argv_8.clear();
							if (argc > 8)
							{
								
								argv_8 = argv[8]; 
							}
							int wo_ist_gleich = - 1;
							wo_ist_gleich = argv_8.find("=");
							argv_8 = argv_8.substr(wo_ist_gleich + 1,argv_8.length());
							argv_8 = argv_8 + " ";
							
							int wo_ist_vaild_until = - 1;
							wo_ist_vaild_until = certlist_array[i].find("Validity not after:");
							cert_subject_2 = certlist_array[i].substr(0, wo_ist_vaild_until);
							
							if (cert_subject_2 == argv_8)
							
							
							
							
							
							{
							
								
								void time_converter();
								time_converter();
								
								
								string tage_warn = argv[9];
								string tage_critical = argv[10];
					
								
								
								tage_warn = tage_warn.substr(6,tage_warn.length());
								tage_critical = tage_critical.substr(10,tage_critical.length());
								
								std::string::size_type sz;  
								
								long tage_warn_long = stol(tage_warn,&sz);
								
													
								long tage_critical_long = stol(tage_critical,&sz);
								
								
								
								

								long tage_bis_ablauf_long = tage_bis_ablauf;
								
								
								
								
								
								
								
								
								
								
								
								
								if ((tage_bis_ablauf_long <= tage_warn_long) && ( tage_bis_ablauf_long >= tage_critical_long ))
								{
									cout<<"WARNING - "<<tage_bis_ablauf_long<<endl;
									exit(1);
								}
								if (tage_bis_ablauf_long >= tage_warn_long)
								{
									
									cout<<"OK - "<<tage_bis_ablauf_long<<endl;
									exit(0);
								}
								
								if (tage_bis_ablauf_long <= tage_critical_long)
								{
									
									cout<<"CRITICAL - "<<tage_bis_ablauf_long<<endl;
									exit(2);
								}
							}
						}
						certlist_array.clear();
						
						cert_subject.clear();
						cert_valud_until.clear();
				}

			}
			
			std::regex regex_13("^-sapcontrol=GetProcessList$");
			if (std::regex_search(sapcontrol_command_extern, reg_match, regex_13))
			{		
				
				username_extern = argv[2];
					
				password_extern = argv[3];
					
				hostname_extern = argv[4];
					
				
					
				sysnr_extern = argv[5];
					
				http_proto_extern = argv[6];
					
				sapcontrol_command_extern = argv[7]; 
					
				sapcontrol_monitor_name_extern = argv[8]; 
					

				
				void sapcontrol_commands();
				sapcontrol_commands();
				
				
				
				void web_srv();
				web_srv();
				
				
				void xml_extract();
				xml_extract();
			}
			
			std::regex regex_14("^-sapcontrol=GetAlerts$");
			if (std::regex_search(sapcontrol_command_extern, reg_match, regex_14))
			{
				username_extern = argv[2];
					
				password_extern = argv[3];
					
				hostname_extern = argv[4];
					
				
					
				sysnr_extern = argv[5];
					
				http_proto_extern = argv[6];
					
				sapcontrol_command_extern = argv[7]; 
					
				sapcontrol_monitor_name_extern = argv[8]; 
					

				
				void sapcontrol_commands();
				sapcontrol_commands();
				
				
				
				void web_srv();
				web_srv();
				
				
				void xml_extract();
				xml_extract();
			}
			

			
			std::regex regex_16("^-sapcontrol=J2EEGetProcessList$");
			if (std::regex_search(sapcontrol_command_extern, reg_match, regex_16))
			{
				
				
				username_extern = argv[2];
					
				password_extern = argv[3];
					
				hostname_extern = argv[4];
					
				
					
				sysnr_extern = argv[5];
					
				http_proto_extern = argv[6];
					
				sapcontrol_command_extern = argv[7]; 
					
				sapcontrol_monitor_name_extern = argv[8]; 
					

				
				void sapcontrol_commands();
				sapcontrol_commands();
				
				
				void web_srv();
				web_srv();
				
				
				void xml_extract();
				xml_extract();
				
				
			}
			
			std::regex regex_17("^-sapcontrol=J2EEGetComponentList$");
			if (std::regex_search(sapcontrol_command_extern, reg_match, regex_17))
			{
				
				
				
				
				username_extern = argv[2];
					
				password_extern = argv[3];
					
				hostname_extern = argv[4];
					
				
					
				sysnr_extern = argv[5];
					
				http_proto_extern = argv[6];
					
				sapcontrol_command_extern = argv[7]; 
					
				sapcontrol_monitor_name_extern = argv[8]; 
					

				
				void sapcontrol_commands();
				sapcontrol_commands();
				
				
				void web_srv();
				web_srv();
				
				
				void xml_extract();
				xml_extract();
				
				
			}
			
			std::regex regex_18("^-sapcontrol=J2EEGetVMHeapInfo$");
			if (std::regex_search(sapcontrol_command_extern, reg_match, regex_18))
			{
				
				
				
				
				username_extern = argv[2];
					
				password_extern = argv[3];
					
				hostname_extern = argv[4];
					
				
					
				sysnr_extern = argv[5];
					
				http_proto_extern = argv[6];
					
				sapcontrol_command_extern = argv[7]; 
					
				sapcontrol_monitor_name_extern = argv[8]; 
					
				type_extern = argv[9]; 
					
					
				
				void sapcontrol_commands();
				sapcontrol_commands();
				
				
				void web_srv();
				web_srv();
				
				
				void xml_extract();
				xml_extract();
				
				
				string  warn;
				string critical;
				warn = argv[10];
				critical = argv[11];
				
				
				int wo_ist_gelich = - 1;
				wo_ist_gelich = warn.find("=");
				warn = warn.substr(wo_ist_gelich + 1, warn.length());
				wo_ist_gelich = - 1;
				wo_ist_gelich = critical.find("=");
				critical = critical.substr(wo_ist_gelich + 1, warn.length());
				
				
				
				int heap_memory_size_int = - 1;
				int warn_int = - 1;
				int critical_int = - 1;
				heap_memory_size_int = stoi(heap_memory_size);
				warn_int = stoi(warn);
				critical_int = stoi(critical);
				
				
				
				
				if (heap_memory_size_int > critical_int)
				{
					icinga_retun_code = 2;
					cout<<"Critical | "<<heap_memory_size_int<<endl;
					
					
					return(2);
				}
				if (heap_memory_size_int > warn_int)
				{
					icinga_retun_code = 1;
					cout<<"Warn | "<<heap_memory_size_int<<endl;
					
					
					return(1);
				}
				if (heap_memory_size_int < warn_int)
				{
					icinga_retun_code = 0;
					cout<<"Ok | "<<heap_memory_size_int<<endl;
					
					
					return(0);
				}
				
			}





			
			
			
			
			
			
			if (icinga_retun_code == 0)
			{
				
				
				
				
				exit(0);
			}
			if (icinga_retun_code == 1)
			{
				
				
				
				
				
				exit(icinga_retun_code);
			}
			if (icinga_retun_code == 2)
			{
				
				
				
				
				
				exit(icinga_retun_code);
			}
			
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		int wo_ist_java_parameter_show = - 1;
		wo_ist_java_parameter_show = parameter.find("-javashow");
		

		std::regex regex_10("^-javashow$");
		
		
		
		
		
		if (std::regex_search(parameter, reg_match, regex_10))
		{
			
			username_extern = argv[2];
			password_extern = argv[3];
			hostname_extern = argv[4];
			sid_extern = argv[5];
			sysnr_extern = argv[6];
			http_proto_extern = argv[7];
			sapcontrol_command_extern = parameter; 		
			
			
			
			void sapcontrol_commands();
			sapcontrol_commands();
			
			
			
			void web_srv();
			web_srv();
			
			
			void xml_extract();
			xml_extract();
		
		}

	return(0);
}






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
	
using namespace std;

RFC_ERROR_INFO errorInfo;
RFC_RC rc = RFC_OK;

void signalHandler( int signum)
{
		cout<<"PROBLEM RFC SDK"<<endl;
        cout << "Interrupt signal (" << signum << ") received.\n";
        
		printfU(cU("signalHandler key# %s: %d\n"),errorInfo.key);
		printfU(cU("signalHandler message# %s: %d\n"),errorInfo.message);
		printfU(cU("signalHandler code# %d\n"),errorInfo.code);
		printfU(cU("signalHandler rc # %d\n"),rc);

        exit (- 1);
}

int main(int argc, char *argv[])
{
        signal(SIGSEGV, signalHandler);
        signal(SIGABRT, signalHandler);
        signal(SIGFPE, signalHandler);
        signal(SIGILL, signalHandler);
        signal(SIGTERM, signalHandler);
        signal(SIGINT, signalHandler);
	
		string parameter;
		parameter = argv[1];
		
		int wo_ist_show_parameter = - 1;
		wo_ist_show_parameter = parameter.find("-show");

		if (wo_ist_show_parameter > -1)
		{
			cout<<"Alle verfügbaren CCMS Monitore"<<endl;
			
			#define NUM_PARAMS 9
			RFC_CONNECTION_PARAMETER loginParams[NUM_PARAMS];
			unsigned resultLen = 0;
			
			//###USERNAME
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
			
			//###PASSWORT
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

			//###HOSTNAME
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

			//###SID
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

			//###SYSTEMNUMMER
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

			//MANDANTEN NUMMER
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
			RfcSetChars(rfc_handle, cU("EXTCOMPANY"), cU("COMPANY"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTPRODUCT"), cU("PRODUCT"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("INTERFACE"), cU("XAL"), 3, &errorInfo);
			RfcSetChars(rfc_handle, cU("VERSION"), cU("1.0"), 3, &errorInfo);
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);

			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MON_GETLIST"), &errorInfo);
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("RFC-USER"), 8, &errorInfo);

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
				RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("RFC-USER"), 8, &errorInfo);
				
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
		
		if (wo_ist_check_parameter > -1)
		{
			#define NUM_PARAMS 9
			RFC_CONNECTION_PARAMETER loginParams[NUM_PARAMS];

			unsigned resultLen = 0;
			
			//###USERNAME
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
			
			//###PASSWORT
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
		
			//###HOSTNAME
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
			
			//###SID
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

			//###SYSTEMNUMMER
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

			//MANDANTEN NUMMER
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
			RfcSetChars(rfc_handle, cU("EXTCOMPANY"), cU("COMPANY"), 11, &errorInfo);
			RfcSetChars(rfc_handle, cU("EXTPRODUCT"), cU("PRODUCT"), 11, &errorInfo);
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
			
			//Filtern nach CONTEXT_NAME
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
			RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External-User"), 13, &errorInfo);
			RfcSetChars(rfc_handle, cU("MTE_NAME"), monitor_name_mte_name_sapuc, strlenU(monitor_name_mte_name_sapuc), &errorInfo);	
			RfcSetChars(rfc_handle, cU("OBJECT_NAME"), monitor_name_object_name_sapuc, strlenU(monitor_name_object_name_sapuc), &errorInfo);	
			RfcSetChars(rfc_handle, cU("SYSTEM_ID"), monitor_name_sap_sid_sapuc, strlenU(monitor_name_sap_sid_sapuc), &errorInfo);	
			
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);
				
			RFC_STRUCTURE_HANDLE returnStructure;
			RfcGetStructure(rfc_handle, cU("RETURN"), &returnStructure, &errorInfo);
			rc = RfcGetString(returnStructure, cU("MESSAGE"), message, sizeofU(message), &resultLen, &errorInfo);

			RfcGetStructure(rfc_handle, cU("TID"), &returnStructure, &errorInfo);
			RfcGetString(returnStructure, cU("MTSYSID"), message, sizeofU(message), &resultLen, &errorInfo);
			RfcGetString(returnStructure, cU("MTMCNAME"), message, sizeofU(message), &resultLen, &errorInfo);
			RfcGetString(returnStructure, cU("MTNUMRANGE"), message, sizeofU(message), &resultLen, &errorInfo);
			RfcGetString(returnStructure, cU("MTUID"), message, sizeofU(message), &resultLen, &errorInfo);
			RfcGetString(returnStructure, cU("MTCLASS"), message, sizeofU(message), &resultLen, &errorInfo);
			RfcGetString(returnStructure, cU("MTINDEX"), message, sizeofU(message), &resultLen, &errorInfo);
			RfcGetString(returnStructure, cU("EXTINDEX"), message, sizeofU(message), &resultLen, &errorInfo);

			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("BAPI_SYSTEM_MTE_GETPERFCURVAL"), &errorInfo);
			
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);

			RfcSetChars(rfc_handle, cU("EXTERNAL_USER_NAME"), cU("External-User"), 13, &errorInfo);
			
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
				cout<<"Fehler: Monitor nicht definieert"<<endl;
														
				RfcDestroyFunction(rfc_handle, &errorInfo);
				RfcCloseConnection(conn, NULL);
				
				exit(-1);
			}

			RfcGetStructure(rfc_handle, cU("CURRENT_VALUE"), &returnStructure, &errorInfo);
			RfcGetString(returnStructure, cU("ALRELEVVAL"), message, sizeofU(message), &resultLen, &errorInfo);
				printfU(cU("%s\n"), message);
				
			RfcDestroyFunction(rfc_handle, &errorInfo);
			RfcCloseConnection(conn, NULL);
			
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
		
		int wo_ist_aborted_job_parameter = - 1;
		wo_ist_aborted_job_parameter = parameter.find("-aborted-job");
		if (wo_ist_aborted_job_parameter > -1)
		{
			cout<<"aborted-job#"<<endl;
			
			//1. BAPI_SYSTEM_MTE_GETTIDBYNAME
			//2. BAPI_SYSTEM_MTE_GETSMVALUE
		}
		
		return(0);
}

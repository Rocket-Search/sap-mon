









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

using namespace std;


extern string username_extern;
extern string password_extern;
extern string hostname_extern;
extern string sid_extern;
extern string sysnr_extern;
extern string client_nr_extern;
extern vector<string> certlist_array;

void ssfp_get_pseinfo()
{


	
	
	
	
	#define NUM_PARAMS 9
	RFC_CONNECTION_PARAMETER loginParams[NUM_PARAMS];
	unsigned resultLen = 0;
	
	RFC_ERROR_INFO errorInfo;
	RFC_RC rc = RFC_OK;
	
	
	int wo_ist_gleich = - 1;
	wo_ist_gleich = username_extern.find("=");
	username_extern = username_extern.substr(wo_ist_gleich + 1,username_extern.length());
	
	
	SAP_UC *username_sapuc = NULL;
	unsigned username_sapuc_len;			
	resultLen = 0;
	
	rc = RfcUTF8ToSAPUC((RFC_BYTE*)username_extern.c_str(),strlen(username_extern.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
		
		
		
		
	if (rc == RFC_BUFFER_TOO_SMALL)
	{
		username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)username_extern.c_str(),strlen(username_extern.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
	if (username_sapuc == NULL)
	{
		
		username_sapuc = (SAP_UC*)reallocU(username_sapuc, username_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)username_extern.c_str(),strlen(username_extern.c_str()),username_sapuc, &username_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
		
	
	
	
	
	
	wo_ist_gleich = - 1;
	wo_ist_gleich = password_extern.find("=");
	password_extern = password_extern.substr(wo_ist_gleich + 1,password_extern.length());
	
	
	SAP_UC *password_sapuc = NULL;
	unsigned password_sapuc_len;			
	resultLen = 0;
	rc = RfcUTF8ToSAPUC((RFC_BYTE*)password_extern.c_str(),strlen(password_extern.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
		
		
		
		
	if (rc == RFC_BUFFER_TOO_SMALL)
	
	{
		
		
		
		
		password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)password_extern.c_str(),strlen(password_extern.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
	if (password_sapuc == NULL)
	{
		
		password_sapuc = (SAP_UC*)reallocU(password_sapuc, password_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)password_extern.c_str(),strlen(password_extern.c_str()),password_sapuc, &password_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
		
	
	
	
	wo_ist_gleich = - 1;
	wo_ist_gleich = hostname_extern.find("=");
	hostname_extern = hostname_extern.substr(wo_ist_gleich + 1,hostname_extern.length());
	
	
	SAP_UC *hostname_sapuc = NULL;
	unsigned hostname_sapuc_len;			
	resultLen = 0;
	
	rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname_extern.c_str(),strlen(hostname_extern.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
		
		
		
	if (rc == RFC_BUFFER_TOO_SMALL)
	{
		
		
		
		hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname_extern.c_str(),strlen(hostname_extern.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
	if (hostname_sapuc == NULL)
	{
		
		hostname_sapuc = (SAP_UC*)reallocU(hostname_sapuc, hostname_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)hostname_extern.c_str(),strlen(hostname_extern.c_str()),hostname_sapuc, &hostname_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
		
	
	

	
	wo_ist_gleich = - 1;
	wo_ist_gleich = sid_extern.find("=");
	sid_extern = sid_extern.substr(wo_ist_gleich + 1,sid_extern.length());
	
	
	SAP_UC *sid_sapuc = NULL;
	
	
	unsigned sid_sapuc_len;
	resultLen = 0;

	rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid_extern.c_str(),strlen(sid_extern.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
		
		
		
		
	if (rc == RFC_BUFFER_TOO_SMALL)
	{
		
		
		
		sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid_extern.c_str(),strlen(sid_extern.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
	if (sid_sapuc == NULL)
	{
		
		sid_sapuc = (SAP_UC*)reallocU(sid_sapuc, sid_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)sid_extern.c_str(),strlen(sid_extern.c_str()),sid_sapuc, &sid_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
		


	
	
	
	wo_ist_gleich = - 1;
	wo_ist_gleich = sysnr_extern.find("=");
	sysnr_extern = sysnr_extern.substr(wo_ist_gleich + 1,sysnr_extern.length());
	
	
	SAP_UC *sysnr_sapuc = NULL;
	
	
	
	
	unsigned sysnr_sapuc_len;
	
	resultLen = 0;

	
	rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr_extern.c_str(),strlen(sysnr_extern.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
		
		
		
		
		
	if (rc == RFC_BUFFER_TOO_SMALL)
	{
		
		
		
		sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr_extern.c_str(),strlen(sysnr_extern.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
	if (sysnr_sapuc == NULL)
	{
		
		sysnr_sapuc = (SAP_UC*)reallocU(sysnr_sapuc, sysnr_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)sysnr_extern.c_str(),strlen(sysnr_extern.c_str()),sysnr_sapuc, &sysnr_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
		
	
	
	
	
	wo_ist_gleich = - 1;
	wo_ist_gleich = client_nr_extern.find("=");
	client_nr_extern = client_nr_extern.substr(wo_ist_gleich + 1,client_nr_extern.length());
	
	
	SAP_UC *client_nr_sapuc = NULL;
	unsigned client_nr_sapuc_len;			
	resultLen = 0;
	rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr_extern.c_str(),strlen(client_nr_extern.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
		
		
		
		
	if (rc == RFC_BUFFER_TOO_SMALL)
	{
		
		
		
		client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr_extern.c_str(),strlen(client_nr_extern.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
	}
	if (client_nr_sapuc == NULL)
	{
		
		client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr_extern.c_str(),strlen(client_nr_extern.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
			
			
			
			
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
	loginParams[8].value = cU("1");	

	RFC_CONNECTION_HANDLE conn;
	conn = RfcOpenConnection(loginParams, NUM_PARAMS, &errorInfo);
		
		
		
		
	if (errorInfo.code != RFC_OK) 
	{
		cout<<"Login PROBLEM"<<endl;
			
			
			
		exit(-1);
				
	}
	




	RFC_STRUCTURE_HANDLE returnStructure;
	RFC_FUNCTION_DESC_HANDLE ccms_bapi_handle;
	RFC_FUNCTION_HANDLE rfc_handle;

	SAP_UC message[8192] = iU("");	

	ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("SSFP_GET_PSEINFO"), &errorInfo);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	vector<string> zertifikats_arten_context_arry;
	vector<string> zertifikats_arten_applic_arry;
		zertifikats_arten_context_arry.push_back("PROG");
		zertifikats_arten_applic_arry.push_back("<SYST>");
		zertifikats_arten_context_arry.push_back("PROG");
		zertifikats_arten_applic_arry.push_back("<SNCS>");
		zertifikats_arten_context_arry.push_back("SMIM");
		zertifikats_arten_applic_arry.push_back("DFAULT");
		zertifikats_arten_context_arry.push_back("SFA");
		zertifikats_arten_applic_arry.push_back("CLBOAU");
		zertifikats_arten_context_arry.push_back("SSFA");
		zertifikats_arten_applic_arry.push_back("ELEARN");
		zertifikats_arten_context_arry.push_back("SSFA");
		zertifikats_arten_applic_arry.push_back("SSO2");
		zertifikats_arten_context_arry.push_back("SSLC");
		zertifikats_arten_applic_arry.push_back("ANONYM");
		zertifikats_arten_context_arry.push_back("SSLC");
		zertifikats_arten_applic_arry.push_back("DFAULT");
		zertifikats_arten_context_arry.push_back("WSSE");
		zertifikats_arten_applic_arry.push_back("DFAULT");
		zertifikats_arten_context_arry.push_back("WSSE");
		zertifikats_arten_applic_arry.push_back("WSSCRT");
		zertifikats_arten_context_arry.push_back("WSSE");
		zertifikats_arten_applic_arry.push_back("WSSKEY");
		zertifikats_arten_context_arry.push_back("SSLS");
		zertifikats_arten_applic_arry.push_back("DFAULT");

	rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);

	int array_zertifikats_arten_groesse = - 1;
	array_zertifikats_arten_groesse = zertifikats_arten_context_arry.size();
	
		
	SAP_UC *context_sapuc = NULL;
	unsigned context_sapuc_len;			
	
	SAP_UC *applic_sapuc = NULL;
	unsigned applic_sapuc_len;			
	resultLen = 0;
	
	string context_string;
	string applic_string;
	
	
	SAP_UC certificate_in_hex[99999] = iU("");
	char cert_hex_char[99999];
	unsigned cert_int;
	unsigned result_length;
	string cert_hex_string;
		
	for (int  i = 0; i < array_zertifikats_arten_groesse; i++)
	{
		context_string = zertifikats_arten_context_arry[i];
		
		
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)context_string.c_str(),strlen(context_string.c_str()),context_sapuc, &context_sapuc_len, &resultLen,  &errorInfo);
			
		if (rc == RFC_BUFFER_TOO_SMALL){context_sapuc = (SAP_UC*)reallocU(context_sapuc, context_sapuc_len);rc = RfcUTF8ToSAPUC((RFC_BYTE*)context_string.c_str(),strlen(context_string.c_str()),context_sapuc, &context_sapuc_len, &resultLen,  &errorInfo);}
		if (context_sapuc == NULL){context_sapuc = (SAP_UC*)reallocU(context_sapuc, context_sapuc_len);rc = RfcUTF8ToSAPUC((RFC_BYTE*)context_string.c_str(),strlen(context_string.c_str()),context_sapuc, &context_sapuc_len, &resultLen,  &errorInfo);}
			
			
		applic_string = zertifikats_arten_applic_arry[i];
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)applic_string.c_str(),strlen(applic_string.c_str()),applic_sapuc, &applic_sapuc_len, &resultLen,  &errorInfo);
			
		if (rc == RFC_BUFFER_TOO_SMALL){applic_sapuc = (SAP_UC*)reallocU(applic_sapuc, applic_sapuc_len);rc = RfcUTF8ToSAPUC((RFC_BYTE*)applic_string.c_str(),strlen(applic_string.c_str()),applic_sapuc, &applic_sapuc_len, &resultLen,  &errorInfo);}
		if (applic_sapuc == NULL){applic_sapuc = (SAP_UC*)reallocU(applic_sapuc, applic_sapuc_len); rc = RfcUTF8ToSAPUC((RFC_BYTE*)applic_string.c_str(),strlen(applic_string.c_str()),applic_sapuc, &applic_sapuc_len, &resultLen,  &errorInfo);}
			
			
		
		RfcSetChars(rfc_handle, cU("CONTEXT"), context_sapuc, strlenU(context_sapuc), &errorInfo);	
			
			
			
		
		RfcSetChars(rfc_handle, cU("APPLIC"), applic_sapuc, strlenU(applic_sapuc), &errorInfo);	
			
			
			
		
		rc = RfcInvoke(conn, rfc_handle, &errorInfo);
		
		
		
		unsigned rowCount = 0;
		RFC_TABLE_HANDLE table;

		rc = RfcGetTable(rfc_handle, cU("CERTIFICATELIST"),&table,&errorInfo);
		RfcGetRowCount(table, &rowCount, &errorInfo);
			
			
		
		
		
		
		
		
		for (unsigned i = 0; i < rowCount; ++i) 
		{
			RfcMoveTo(table, i, NULL);
			RfcGetString(table, cU(""), certificate_in_hex,sizeofU(certificate_in_hex), NULL, &errorInfo);
				
					
			
			rc = RfcSAPUCToUTF8(certificate_in_hex, strlenU(certificate_in_hex), (RFC_BYTE *)cert_hex_char, &cert_int, &result_length, &errorInfo);
			
			if (rc == RFC_BUFFER_TOO_SMALL){rc = RfcSAPUCToUTF8(certificate_in_hex, strlenU(certificate_in_hex), (RFC_BYTE *)cert_hex_char, &cert_int, &result_length, &errorInfo);;}	
			
			
			std::stringstream ConvertStream;
			ConvertStream<<	cert_hex_char;
			ConvertStream>>cert_hex_string;
			certlist_array.push_back(cert_hex_string + ";;;" + context_string + ";;;" + applic_string);

		}
		
		
		
	}
	
	
	
	RfcDestroyFunction(rfc_handle, &errorInfo);
	RfcCloseConnection(conn, NULL);
	

}

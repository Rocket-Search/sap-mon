
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
extern string rfc_destination;
extern int icinga_retun_code;
extern string rueckgabe_nachricht;

void rfc_ping()
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

	if (rc == 23)
	{
		client_nr_sapuc = (SAP_UC*)reallocU(client_nr_sapuc, client_nr_sapuc_len);
		rc = RfcUTF8ToSAPUC((RFC_BYTE*)client_nr_extern.c_str(),strlen(client_nr_extern.c_str()),client_nr_sapuc, &client_nr_sapuc_len, &resultLen,  &errorInfo);
					
	}
	

	if ((username_sapuc == NULL) || (password_sapuc == NULL)|| (hostname_sapuc == NULL ) || (sid_sapuc == NULL) || (sysnr_sapuc == NULL) || (client_nr_sapuc == NULL) || (rc != 0) )

	{
		cout<<"lopgin_parameter_sapuc"<<endl;
		cout<<"RFC SDK Problem#"<<rc<<"#"<<endl;

		exit(EXIT_FAILURE);
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
			printfU(cU("Login PROBLEM key# %s: %d\n"),errorInfo.key);
			printfU(cU("Login PROBLEM message# %s: %d\n"),errorInfo.message);
			printfU(cU("Login PROBLEM code# %d\n"),errorInfo.code);
		
		exit(EXIT_FAILURE);
				
	}
	
	RFC_FUNCTION_DESC_HANDLE ccms_bapi_handle;
	RFC_FUNCTION_HANDLE rfc_handle;

	SAP_UC message[8192] = iU("");	


	ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("/BDL/RFC_CHECK"), &errorInfo);
	
	rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);
	

	rfc_destination = rfc_destination.substr(16,rfc_destination.length());

	
	SAP_UC *rfcdestination_sapuc = NULL;
	unsigned rfcdestination_sapuc_len;			
	
	rc = RfcUTF8ToSAPUC((RFC_BYTE*)rfc_destination.c_str(),strlen(rfc_destination.c_str()),rfcdestination_sapuc, &rfcdestination_sapuc_len, &resultLen,  &errorInfo);
	if (rc == RFC_BUFFER_TOO_SMALL){rfcdestination_sapuc = (SAP_UC*)reallocU(rfcdestination_sapuc, rfcdestination_sapuc_len);rc = RfcUTF8ToSAPUC((RFC_BYTE*)rfc_destination.c_str(),strlen(rfc_destination.c_str()),rfcdestination_sapuc, &rfcdestination_sapuc_len, &resultLen,  &errorInfo);}
	if (rfcdestination_sapuc == NULL){rfcdestination_sapuc = (SAP_UC*)reallocU(rfcdestination_sapuc, rfcdestination_sapuc_len);	rc = RfcUTF8ToSAPUC((RFC_BYTE*)rfc_destination.c_str(),strlen(rfc_destination.c_str()),rfcdestination_sapuc, &rfcdestination_sapuc_len, &resultLen,  &errorInfo);}

	if ((rfcdestination_sapuc == NULL) || (rc != 0)) 
	{
		cout<<"rfcdestination_sapuc"<<endl;
		cout<<"RFC SDK Problem#"<<rc<<"#"<<endl;

		exit(EXIT_FAILURE);
	}
		

	RfcSetChars(rfc_handle, cU("DESTINATION"),rfcdestination_sapuc, strlenU(rfcdestination_sapuc), &errorInfo);

	rc = RfcInvoke(conn, rfc_handle, &errorInfo);

	SAP_UC mess_sap_uc[99999] = iU("");
	RfcGetString(rfc_handle, cU("MESS"), mess_sap_uc, sizeofU(mess_sap_uc), &resultLen, &errorInfo);

	SAP_UC check_ok_sap_uc[99999] = iU("");
	RfcGetString(rfc_handle, cU("CHECK_OK"), check_ok_sap_uc, sizeofU(check_ok_sap_uc), &resultLen, &errorInfo);

	string error_message_string;	
	string ping_message_string;
	

	if (strlenU(mess_sap_uc) != 0)
	{
		char mess_char[99999];
		unsigned mess_int;
		unsigned result_length;

		rc = RfcSAPUCToUTF8(mess_sap_uc, strlenU(mess_sap_uc), (RFC_BYTE *)mess_char, &mess_int, &result_length, &errorInfo);
		if (rc == RFC_BUFFER_TOO_SMALL){rc = RfcSAPUCToUTF8(mess_sap_uc, strlenU(mess_sap_uc), (RFC_BYTE *)mess_char, &mess_int, &result_length, &errorInfo);}

		error_message_string = mess_char;

		int wo_ist_typ_g = - 1;
		wo_ist_typ_g = error_message_string.find("Illegal destination type 'G'.");


		if (wo_ist_typ_g >= 0)
		{

			ccms_bapi_handle = RfcGetFunctionDesc(conn, cU("/SDF/HTTP_CHECK"), &errorInfo);
	
			rfc_handle = RfcCreateFunction(ccms_bapi_handle, &errorInfo);	
			
			RfcSetChars(rfc_handle, cU("IV_DESTINATION"),rfcdestination_sapuc, strlenU(rfcdestination_sapuc), &errorInfo);
			
			RfcSetChars(rfc_handle, cU("IV_PING"), cU("X"),1, &errorInfo);
				
			rc = RfcInvoke(conn, rfc_handle, &errorInfo);

			
			SAP_UC ping_message_sap_uc[99999] = iU("");
			RfcGetString(rfc_handle, cU("EV_PING_MESSAGE"), ping_message_sap_uc, sizeofU(ping_message_sap_uc), &resultLen, &errorInfo);

			char ping_message_char[99999];
			unsigned ping_message_int;
			unsigned result_length;

			rc = RfcSAPUCToUTF8(ping_message_sap_uc, strlenU(ping_message_sap_uc), (RFC_BYTE *)ping_message_char, &ping_message_int, &result_length, &errorInfo);
			if (rc == RFC_BUFFER_TOO_SMALL){rc = RfcSAPUCToUTF8(ping_message_sap_uc, strlenU(ping_message_sap_uc), (RFC_BYTE *)ping_message_char, &ping_message_int, &result_length, &errorInfo);}
			ping_message_string = ping_message_char;

			
			int wo_ist_ping_success = - 1;
			wo_ist_ping_success = ping_message_string.find("HTTP Ping successful.");
			if (wo_ist_ping_success >= 0)
			{
				icinga_retun_code = 0;
				rueckgabe_nachricht = ping_message_string;
				
			}
			else
			{
			
				icinga_retun_code = 2;
				rueckgabe_nachricht = ping_message_string;
				error_message_string = rueckgabe_nachricht;
				
			}
			
		}
		else
		{


			icinga_retun_code = 2;
			rueckgabe_nachricht = error_message_string;

		}
	}

	if (strlenU(check_ok_sap_uc) != 0)
	{

		char check_ok_char[99999];
		unsigned check_ok_int;
		unsigned result_length;

		string check_ok_string;
		rc = RfcSAPUCToUTF8(check_ok_sap_uc, strlenU(check_ok_sap_uc), (RFC_BYTE *)check_ok_char, &check_ok_int, &result_length, &errorInfo);
		if (rc == RFC_BUFFER_TOO_SMALL){rc = RfcSAPUCToUTF8(check_ok_sap_uc, strlenU(check_ok_sap_uc), (RFC_BYTE *)check_ok_char, &check_ok_int, &result_length, &errorInfo);}


		check_ok_string = check_ok_char;

		
		icinga_retun_code = 0;
		
	}

	rueckgabe_nachricht = error_message_string;

		
	RfcDestroyFunction(rfc_handle, &errorInfo);
	RfcCloseConnection(conn, NULL);
		
}
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
#include "/usr/inculde/curl/curl.h"

using namespace std;

extern string username_extern;
extern string password_extern;
extern string hostname_extern;
extern string sysnr_extern;
extern int icinga_retun_code;
extern string rueckgabe_nachricht;
extern string web_service_wert_rueckgabe;
extern string http_proto_extern;
extern string soap_sapcontrol_xml_extern;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userdata)
{
    ((std::string*)userdata)->append((char*)contents, size * nmemb);
	
    return size * nmemb;
}

void web_srv()
{
	int wo_ist_gleich = - 1;
	wo_ist_gleich = username_extern.find("=");
	username_extern = username_extern.substr(wo_ist_gleich + 1,username_extern.length());

	

	wo_ist_gleich = - 1;
	wo_ist_gleich = password_extern.find("=");
	password_extern = password_extern.substr(wo_ist_gleich + 1,password_extern.length());

	

	wo_ist_gleich = - 1;
	wo_ist_gleich = hostname_extern.find("=");
	hostname_extern = hostname_extern.substr(wo_ist_gleich + 1,hostname_extern.length());

	

	wo_ist_gleich = - 1;
	wo_ist_gleich = sysnr_extern.find("=");
	sysnr_extern = sysnr_extern.substr(wo_ist_gleich + 1,sysnr_extern.length());

	

	wo_ist_gleich = - 1;
	wo_ist_gleich = http_proto_extern.find("=");
	http_proto_extern = http_proto_extern.substr(wo_ist_gleich + 1,http_proto_extern.length());

	
	
	string http_rueckgabe;


	CURL *curl;
	CURLcode sende_rc;

	curl = curl_easy_init();

	struct curl_slist *header = NULL;

	header = curl_slist_append(header, "Content-Type: text/xml;charset=UTF-8");

	char fehlerspeicher[CURL_ERROR_SIZE];

	
	if (http_proto_extern == std::string("http"))
	{
	
		string wdsl_url_http;
		wdsl_url_http = http_proto_extern + "://" + hostname_extern + ":5" + sysnr_extern + "13/?wdsl";
	
		curl_easy_setopt(curl, CURLOPT_URL, wdsl_url_http.c_str());
		
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, fehlerspeicher);
		
	
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

		curl_easy_setopt(curl, CURLOPT_USERNAME, username_extern.c_str());
		
		curl_easy_setopt(curl, CURLOPT_PASSWORD, password_extern.c_str());


		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, soap_sapcontrol_xml_extern.c_str());
	
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
		
		curl_easy_setopt(curl, CURLOPT_POST, 1L);
				 
		
		

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &http_rueckgabe);
		
		sende_rc = curl_easy_perform(curl);
		if(sende_rc != CURLE_OK)
		{

			cout<<"Fehler #"<<curl_easy_strerror(sende_rc)<<"#"<<endl;
			exit(1);
		}

		web_service_wert_rueckgabe = http_rueckgabe ;

	}

	

	if (http_proto_extern == std::string("https"))
	{

		string wdsl_url_http;
		wdsl_url_http = http_proto_extern + "://" + hostname_extern + ":5" + sysnr_extern + "14/?wdsl";

		
		curl_easy_setopt(curl, CURLOPT_URL, wdsl_url_http.c_str());


		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
 
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, fehlerspeicher);
		

		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
		
		curl_easy_setopt(curl, CURLOPT_USERNAME, username_extern.c_str());
		
		curl_easy_setopt(curl, CURLOPT_PASSWORD, password_extern.c_str());


		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, soap_sapcontrol_xml_extern.c_str());
		
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
		
		curl_easy_setopt(curl, CURLOPT_POST, 1L);
		
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &http_rueckgabe);
		
		sende_rc = curl_easy_perform(curl);
		if(sende_rc != CURLE_OK)
		{

			cout<<"Fehler #"<<curl_easy_strerror(sende_rc)<<"#"<<endl;
			exit(1);
		}

		web_service_wert_rueckgabe = http_rueckgabe ;
		
	}

	
	curl_easy_cleanup(curl);	
	curl_global_cleanup();	
	

}

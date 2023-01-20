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

#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/x509_vfy.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/asn1.h>
#include <openssl/bn.h>
#include <openssl/conf.h>
#include <openssl/evp.h>

#include <memory>
#include <cstring>
#include <ctime>

using namespace std;

extern string cert_subject;
extern string cert_valud_until;
extern vector<string> certlist_array;
extern vector<string> certlist_subj_valid_until;
extern bool ssl_check;

void read_cert_infos()
{

	
	
	
	
	
	int anzahl_certis = - 1;
	anzahl_certis = certlist_array.size();
	
	
	string cert_hex;
	int cert_gesammt_laenge = - 1;
	int reine_cert_laenge = - 1;
	int finde_semikolon = - 1 ;
	string sap_context;
	string sap_applic;
	
	
	
	
	string cert_base64 = "";
	string zeichenvorrat = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	
	int bytes = - 1; 
	
	int padding = - 1 ;
	int count = - 1; 
	unsigned long long dezimal_nummer_long = 0;
	int j = 0;
	
	
	OpenSSL_add_all_algorithms();
	OPENSSL_no_config();
	ERR_load_BIO_strings();					
	ERR_load_crypto_strings();				

	X509 *x509 = NULL;
	char *dataStart = NULL;
	char *subjectString = NULL;
	long nameLength = - 1;
	string subj_string;
BIO *bio_out = NULL;
	const char *zertifikat_in_base64_format = NULL;
	int rc = - 1 ;
	char *start_punkt = NULL;
	char *valid_until_char = NULL;
	long laenge = - 1;
	
	
	
		
	

	
	for (int i = 0 ; i < anzahl_certis; i++ )
	{
		
		
		cert_gesammt_laenge = certlist_array[i].length();
		
		
		
		finde_semikolon = certlist_array[i].find(";;;");
		
		cert_hex = certlist_array[i].substr(0,finde_semikolon);
		
		
		
		finde_semikolon = certlist_array[i].find(";;;",finde_semikolon);
		
		sap_context = certlist_array[i].substr(finde_semikolon + 3, 4);		
		
		
		
		finde_semikolon = certlist_array[i].find(";;;",finde_semikolon + 3);
		
		sap_applic = certlist_array[i].substr(finde_semikolon + 3, 99);		
		
		
		
		
		

		
		
		
		
		bytes = cert_hex.size() / 3;
		padding = cert_hex.size() % 3;
		count = bytes * 3;

		
		
		
		
		

		for(j = 0; j < count; j+=3) 
		{
			
			
			char erstes_zeichen[2] = {cert_hex[j], 0};
			char zweites_zeichen[2] = {cert_hex[j+1], 0};
			char drittes_zeichen[2] = {cert_hex[j+2], 0};
			
			
			
			dezimal_nummer_long = strtoull(erstes_zeichen, nullptr, 16) << 8; 
			dezimal_nummer_long |= strtoull(zweites_zeichen, nullptr, 16) << 4; 
			dezimal_nummer_long |= strtoull(drittes_zeichen, nullptr, 16); 

			

			cert_base64 += zeichenvorrat[0x3F & (dezimal_nummer_long >> 6)]; 
			cert_base64 += zeichenvorrat[0x3F & dezimal_nummer_long]; 
		}
		

		if(padding == 1)
		{
			char erstes_zeichen[2] = {cert_hex[j], 0};
			dezimal_nummer_long = strtoull(erstes_zeichen, nullptr, 16) << 8; 
			cert_base64 += zeichenvorrat[0x3F & (dezimal_nummer_long >> 6)];
			cert_base64 += '='; 
		}
	
		
		if(padding > 1)
		{
			
			char erstes_zeichen[2] = {cert_hex[j], 0};
			char zweites_zeichen[2] = {cert_hex[j+1], 0};
			char drittes_zeichen[2] = {cert_hex[j+2], 0};

			
			
			dezimal_nummer_long = strtoull(erstes_zeichen, nullptr, 16) << 8; 
			dezimal_nummer_long |= strtoull(zweites_zeichen, nullptr, 16) << 4; 
			dezimal_nummer_long |= strtoull(drittes_zeichen, nullptr, 16); 

			

			cert_base64 += zeichenvorrat[0x3F & (dezimal_nummer_long >> 6)]; 
			cert_base64 += zeichenvorrat[0x3F & dezimal_nummer_long]; 
			cert_base64 += '='; 
			cert_base64 += '='; 
		}
		

		
		
		
		
		int reine_zeichenkette_laenge = - 1;
		reine_zeichenkette_laenge = cert_base64.length();
		

		int seperator_auf_position = - 1 ;
		for (int k = 0; k < reine_zeichenkette_laenge; k++)
		{	
			
			
			seperator_auf_position = k + 64;
			
			if (seperator_auf_position >= reine_zeichenkette_laenge)
			{
				
				continue;
			}
			cert_base64 = cert_base64.insert( seperator_auf_position ,"\n");  
			
			
			k = k + 64;
		}
		cert_base64 = "-----BEGIN CERTIFICATE-----\n" + cert_base64 + "\n-----END CERTIFICATE-----";
		
		
		
		
		zeichenvorrat = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
		bytes = - 1; 
		padding = - 1 ;
		count = - 1; 
		dezimal_nummer_long = 0;
		j = 0;
		
		
		
		zertifikat_in_base64_format = cert_base64.c_str(); 
		
		
		
		
		BIO *bio_mem = BIO_new(BIO_s_mem());
			ERR_print_errors_fp (stderr);
			
			
		BIO_puts(bio_mem, zertifikat_in_base64_format);
			ERR_print_errors_fp (stderr);
			
		
		
		
			
			
		x509 = PEM_read_bio_X509(bio_mem, NULL, NULL, NULL);
			ERR_print_errors_fp (stderr);
			
			
		X509_NAME *subject = X509_get_subject_name(x509);
			ERR_print_errors_fp (stderr);
		
		X509_NAME_print(bio_mem, subject, 0);
			ERR_print_errors_fp (stderr);
			
		dataStart = NULL;
		subjectString = NULL;
		
		nameLength = BIO_get_mem_data(bio_mem, &dataStart);
			ERR_print_errors_fp (stderr);
			
		
		
		subjectString = new char[nameLength + 1];
		memset(subjectString, 0x00, nameLength + 1);
		memcpy(subjectString, dataStart, nameLength);
	
		string subj_string = subjectString;
		
		
		if (ssl_check == false)
		{
			cout<<"\n Subject Name: "<<subj_string<<" ";
		}
		
		
		
		
		
		
		dataStart = NULL;
		subjectString = NULL;
		nameLength = - 1;
		
		bio_out = NULL;
		zertifikat_in_base64_format = NULL;
		
		
		bio_mem = NULL;
		
		
		BIO *validBio = BIO_new(BIO_s_mem());
			ERR_print_errors_fp (stderr);
			
		ASN1_TIME *valid_until = X509_get_notAfter(x509);
			ERR_print_errors_fp (stderr);
			
		ASN1_TIME_print(validBio, valid_until);
			ERR_print_errors_fp (stderr);
			
		start_punkt = NULL;
		valid_until_char = NULL;
	
		laenge = BIO_get_mem_data(validBio, &start_punkt);
			ERR_print_errors_fp (stderr);
		
		
		
		valid_until_char = new char[laenge + 1];

		memset(valid_until_char, 0x00, laenge + 1);
		memcpy(valid_until_char, start_punkt, laenge);

		string valid_until_string = valid_until_char;
		
		
		if (ssl_check == false)
		{
			cout<<" Gültig bis: "<<valid_until_string<<endl;
		}
		
	
		certlist_subj_valid_until.push_back(subj_string + ";;;###" + valid_until_string);

		
		
		
		

		BIO_free(validBio);
		
		x509 = NULL;
		
		
		
		subj_string = "";
		
		cert_base64 = "";
		
		
		
	}
	


	BIO_free(bio_out);
	X509_free(x509);

	EVP_cleanup();
	CRYPTO_cleanup_all_ex_data();
	ERR_free_strings();

	
	
}

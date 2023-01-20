













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

extern string cert_valud_until;
long extern tage_bis_ablauf;

void time_converter()
{

	
	
	
	cert_valud_until = cert_valud_until.substr(0,cert_valud_until.length() - 16);
	
	
	const char *valid_until_char = cert_valud_until.c_str();
	struct tm zeit;

	
	
	
	
	strptime(valid_until_char, "%a %b  %d %H:%M:%S %Y", &zeit);

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
	
	
	tage_bis_ablauf = tage;
	
}
































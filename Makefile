sap_mon: sap_mon.o ssfp_get_pseinfo.o read_cert_infos.o rfc_ping.o
	g++ -O3 -fPIC -Wno-unused-variable -Wno-unused-but-set-variable -Wall -o sap_mon sap_mon.o read_cert_infos.o ssfp_get_pseinfo.o rfc_ping.o ./nwrfcsdk/lib/libsapnwrfc.so ./nwrfcsdk/lib/libsapucum.so -lcrypto

sap_mon.o: sap_mon.cpp
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall -DSAPwithUNICODE -I./nwrfcsdk/include -c -o sap_mon.o sap_mon.cpp

ssfp_get_pseinfo.o: ssfp_get_pseinfo.o
	g++ -O3 -fPIC -Wno-unused-variable -Wno-unused-but-set-variable -Wall -DSAPwithUNICODE -I./nwrfcsdk/include -c -o ssfp_get_pseinfo.o ssfp_get_pseinfo.cpp
	
read_cert_infos.o: read_cert_infos.o
	g++ -O3 -fPIC -Wno-unused-variable -Wno-unused-but-set-variable -Wall -c -o read_cert_infos.o read_cert_infos.cpp

rfc_ping.o: rfc_ping.o
	g++ -O3 -fPIC -Wno-unused-variable -Wno-unused-but-set-variable -Wall -DSAPwithUNICODE -I./nwrfcsdk/include -c -o rfc_ping.o rfc_ping.cpp

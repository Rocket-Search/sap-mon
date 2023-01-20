sap_mon: sap_mon.o time_converter.o sapcontrol_commands.o xml_extract.o web_srv.o read_cert_infos.o ssfp_get_pseinfo.o rfc_ping.o
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall -Wl,--as-needed -o sap_mon sap_mon.o time_converter.o sapcontrol_commands.o xml_extract.o web_srv.o read_cert_infos.o ssfp_get_pseinfo.o rfc_ping.o ./nwrfcsdk/lib/libsapnwrfc.so ./nwrfcsdk/lib/libsapucum.so -lcrypto -lcurl -lboost_system

sap_mon.o: sap_mon.cpp
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall  -DSAPwithUNICODE -I./nwrfcsdk/include -c -o sap_mon.o sap_mon.cpp

ssfp_get_pseinfo.o: ssfp_get_pseinfo.o
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall  -DSAPwithUNICODE -I./nwrfcsdk/include -c -o ssfp_get_pseinfo.o ssfp_get_pseinfo.cpp
	
read_cert_infos.o: read_cert_infos.o
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall  -c -o read_cert_infos.o read_cert_infos.cpp

rfc_ping.o: rfc_ping.o
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall  -DSAPwithUNICODE -I./nwrfcsdk/include -c -o rfc_ping.o rfc_ping.cpp
	
sapcontrol_commands.o: sapcontrol_commands.o
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall  -c -o sapcontrol_commands.o sapcontrol_commands.cpp
	
web_srv.o: web_srv.o
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall  -c -o web_srv.o web_srv.cpp;

xml_extract.o: xml_extract.o
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall  -c -o xml_extract.o xml_extract.cpp;

time_converter.o: time_converter.o
	g++ -O3 -fPIC -Wno-misleading-indentation -Wno-sign-compare -Wno-unused-variable -Wno-unused-but-set-variable -Wall  -c -o time_converter.o time_converter.cpp;


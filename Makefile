sap_mon: sap_mon.o
	g++ -std=c++0x -O3 -fPIC -o sap_mon sap_mon.o ./nwrfcsdk/lib/libsapnwrfc.so ./nwrfcsdk/lib/libsapucum.so;date

sap_mon.o: sap_mon.cpp
	g++ -std=c++0x -O3 -fPIC -DSAPwithUNICODE -I./nwrfcsdk/include -c -o sap_mon.o sap_mon.cpp


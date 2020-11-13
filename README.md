a small monitoring tool to check sap base health.

The tool reads the SAP CCMS values and check it to your defined thresholds.

The exit codes are best uses with Icinga Monitoring.

It based on the SAP RFC SDK 7.50 for the SAP communication.

first download and configure SAP RFC SDK 

https://support.sap.com/en/product/connectors/nwrfcsdk.html#section_1291717368

compile command:

	g++ -O3 -fPIC -Wall -std=c++17 -DSAPwithUNICODE -I./nwrfcsdk/include -c -o sap_mon.o sap_mon.cpp ;

	g++ -O3 -fPIC -Wall -o sap_mon sap_mon.o ./nwrfcsdk/lib/libsapnwrfc.so ./nwrfcsdk/lib/libsapucum.so;date

execute command:

	sap_mon -show = show all available SAP monitors according to RZ20
	
	example: sap_mon -show -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>
	
	sap_mon -check = checks the CCMS Performance Attribute from the given monitor
	
	example: sap_mon -check -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER> -monitor='RZ20 Monitor Propertie Name' -warn=<VALUE> -critical=<VALUE>
	
	features under development:
	
	check aborted-job
	check ABAP runtime erros
  
  
	
if you have any question, don't hesitate to contact me software.moore@gmail.com

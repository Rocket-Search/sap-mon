A small monitoring tool to check sap base health.
The tool reads the SAP CCMS values and sapcontrol (J2EE) values and check it to your defined thresholds.
The exit codes are best uses with Icinga / Nagios Monitoring.
It based on the SAP RFC SDK 7.50 for the SAP communication and SOAP/XML data structures for SAP communications.
First download and configure SAP RFC SDK https://support.sap.com/en/product/connectors/nwrfcsdk.html .
Than use simple "make" for comipling (pay attention to the library path in the Makefile).
Here is also a "sap authorization role" transport for the SAP system. 
Simple import the transport request to use minimum permisions for the sap_mon monitoring user.

The progam can check in CCMS for "Performance attribute", "Status attribute", "Log attribute" and "Object description/Text attribute".
You can of course use a SAP router string, to connect to your host. Just put the sap route string instead of hostname.
You can also use sap_mon for your SAP base health without any other monitoring system or the giant monster "SAP Solution Manager" .
For example a simple command line email notification "one liner": 
" while true; do ./sap_mon -check -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -monitor='AL1\saplnx_AL1_01\OperatingSystem\Filesystems\/tmp\Freespace' -warn=4000 -critical=2999 &> /dev/null && echo success || echo "Free Space in /tmp is CRITICAL" | mail -s "sap_mon free space is critical" software.moore@gmail.com; date; sleep 60 ; done "
	
It also check for ABAP dumps, aboted background jobs, the expiration date of the x509 certificate in the list and do a RFC connection test.
Also testet with zabbix.
The following RFC connection types are working: type 3 / G / I / T / X .
	
It is also possible to get monitor data via sapcontrol web services (WSDL / SOAP) over http and https.
With this option you can monitor a SAP java stack system or a TREX system.
The follwoing features are avaiable:
- GetProcessList
- GetAlerts
- J2EEGetVMHeapInfo
- J2EEGetComponentList
- J2EEGetProcessList
- Show and check all certifcates with subject and expiration date
- GetAlertTree (under development)
If you change the default profile parameter "service/protectedwebmethods", you can access sapcontrol features with an anonymous user.







pre requirements:
curl (libcurl) (curl 7.86.0)
Boost C++ Libraries (v1.80)
openssl/libressl (libcrypto) (LibreSSL 3.5.3)

Tested with:

compiler version: 
"g++-12 (SUSE Linux) 12.2.1 20220830 [revision e927d1cf141f221c5a32574bde0913307e140984]" 
	with -std=c++17
	with -std=c++14
	with -std=c++11
"g++ (SUSE Linux) 7.5.0"
	with -std=c++17
	with -std=c++14
	with -std=c++11

RFCSDK: SAP NetWeaver RFC SDK 7.50 Patch Level 7
OS: openSUSE Leap 15.4
Kernel: 4.20.16-default
GLIBCXX: 20191114

SAP Verion:	
SAP ERP 6.0 with EHP8 FOR SAP ERP 6.0
SAP_BASIS	750	0001	SAPK-75001INSAPBASIS	SAP Basis Component
SAP_ABA		750	0001	SAPK-75001INSAPABA		Cross-Application Component
kernel release  753	patch number                  700

DB2 Version:
DB2 v11.5.5.0", "special_5354",

Java System:
SAP NETWEAVER 7.5: Application Server Java
SAP NETWEAVER 7.5: EP Core - Application Portal 
SAP NETWEAVER 7.5: Enterprise Portal 

TREX version info:
version:             7.10.72.00
build number:        710.72.403812


Usage:
#Show the CCMS available monitors
./sap_mon -show -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100

#Check the netiry CCMS Monitor Set
./sap_mon -checkall -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -monitor='SAP CCMS Monitor Templates\Buffers' 

#CCMS Status Attribute
./sap_mon -check -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -monitor='AL1\saplnx_AL1_01\DatabaseClient\DBConnection\DBServer'

#CCMS Performance attribute #without warn and critical
./sap_mon -check -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -monitor='AL1\DB2 Universal Database for NT/UNIX\Space management\database related file systems\database directory'

#CCMS Performance attribute #with warn and critical
./sap_mon -check -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -monitor='AL1\DB2 Universal Database for NT/UNIX\Space management\database related file systems\database directory' -warn=39 -critical=45

#CCMS Log Attribute
./sap_mon -check -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -monitor='AL1\saplnx_AL1_01\R3Syslog\Communication'

#CCMS Text Attribute oder Obeject Description
./sap_mon -check -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -monitor='AL1\System Configuration\Installed SAP Components\EA-HRCFR\Description'

#Aborted Jobs
./sap_mon -aborted-job -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 

#Aborted Jobs with SAP router string
./sap_mon -aborted-job -username=RFC_TEST -password=Test123456 -hostname=/H/172.17.190.85/S/3299/H/172.17.190.6 -sid=AL1 -sysnum=01 -client=100

#Abap Dump
./sap_mon -abap-dump -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 

#SSL show certificate list
./sap_mon -sslview -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100

#Check single certificate
./sap_mon -sslcheck -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -subjectname='C=DE, O=SAP Trust Community, OU=SAP Web AS, OU=I0020785703, CN=saplnx.moore.corp' -warn=30 -critical=15 

#RFC Connection Test
./sap_mon -rfc -username=RFC_TEST -password=Test123456 -hostname=saplnx -sid=AL1 -sysnum=01 -client=100 -rfcdestination='AL1'

#Java / ABAP sapcontrol process status (GetProcessList)
./sap_mon -java -username=al1adm -password=Test1234 -hostname=saplnx -sysnum=01 -proto=http -sapcontrol=GetProcessList -monitorname='disp+work'

#Java / ABAP sapcontrol (GetAlerts)
./sap_mon -java -username=al1adm -password=Test1234 -hostname=saplnx -sysnum=01 -proto=http -sapcontrol=GetAlerts -monitorname='Objects missing in the database'

#Java / ABAP sapcontrol certificate list
./sap_mon -java -username=al1adm -password=Test1234 -hostname=saplnx -sid=AL1 -sysnum=01 -proto=http -sapcontrol=certificate-show

#Java / ABAP sapcontrol check single certificate expiration date
./sap_mon -java -username=al1adm -password=Test1234 -hostname=saplnx -sid=AL1 -sysnum=01 -proto=http -checkcertificate='CN=AL1, OU=I0020785703, OU=SAP Web AS, O=SAP Trust Community, C=DE' -warn=30 -critical=15 

#Java process status (J2EEGetProcessList)
./sap_mon -java -username=al1adm -password=Test1234 -hostname=saplnx -sysnum=01 -proto=http -sapcontrol=J2EEGetProcessList -monitorname='server0'

#Java components status (J2EEGetComponentList)
./sap_mon -java -username=al1adm -password=Test1234 -hostname=saplnx -sysnum=01 -proto=http -sapcontrol=J2EEGetComponentList -monitorname='com.adobe/AdobeDocumentServices'

#java memory usage in bytes (J2EEGetVMHeapInfo)
./sap_mon -java -username=al1adm -password=Test1234 -hostname=saplnx -sysnum=01 -proto=http -sapcontrol=J2EEGetVMHeapInfo -process='server0' -type='local objects' -warn=3000 -critical=15000



Here some screenshots of a stand alone sap_mon:


if you have any question, suggestions or need help, don't hesitate to contact me software.moore@gmail.com




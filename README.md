A small monitoring tool to check sap base health.
The tool reads the SAP CCMS values and check it to your defined thresholds.
The exit codes are best uses with Icinga / Nagios monitoring.
It based on the SAP RFC SDK 7.50 for the SAP communication.
first download and configure SAP RFC SDK
https://support.sap.com/en/product/connectors/nwrfcsdk.html
Than use simple "make" command for comipling (pay attention to the library path in the Makefile).
Here is also a "sap authorization role" transport for the SAP system. 
Simple import the transport request to use minimum permisions for the sap_mon monitoring user.

The progam can check in CCMS for "Performance attribute", "Status attribute", "Log attribute" and "Object description/Text attribute".
You can of course use a SAP router string, to connect to your host. Just put the sap route string instead of hostname.
You can also use sap_mon for your SAP base health without any other monitoring system or the giant monster "SAP Solution Manager" .
For example a simple commandline email notification one-liner: 
" while true; do sap_mon -check -username=<USERNAME> -password=<PASSWORD> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER> -monitor='AL1\saplnx_AL1_01\OperatingSystem\Filesystems\/tmp\Freespace' -warn=4000 -critical=2999 &> /dev/null && echo success || echo "Free Space in /tmp is CRITICAL" | mail -s "sap_mon free space is critical" software.moore@gmail.com; date; sleep 60 ; done "
	
It also checks for ABAP dumps, aboted background jobs, the expiration date of the x509 certificate in the list and do a RFC connection test.
Also testet with zabbix.
The following RFC connection types are working: type 3 / G / I / T / X .

#######################################################
Tested with following components:

compiler version: g++ (GCC) 11.2.0 
RFCSDK: SAP NetWeaver RFC SDK 7.50 Patch Level 7
OS: openSUSE 15.3
Kernel: 4.20.16-default

SAP Verion:	
SAP ERP 6.0 with EHP8 FOR SAP ERP 6.0
SAP_BASIS	750	0001	SAPK-75001INSAPBASIS	SAP Basis Component
SAP_ABA		750	0001	SAPK-75001INSAPABA		Cross-Application Component
kernel release  753	patch number                  700

DB2 Version:
DB2 v11.5.5.0", "special_5354",
#######################################################

Usage:

sap_mon -show = show all available SAP monitors according to RZ20
	example: sap_mon -show -username=<USERNAME> -password=<PASSWORD> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>

sap_mon -check = checks the CCMS from the given monitor. 
"-warn" and "-crtical" are optional and can simply be omitted.
	example: sap_mon -check -username=<USERNAME> -password=<PASSWORD> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER> -monitor='RZ20 Monitor Propertie Name' -warn=<VALUE> -critical=<VALUE>
	example: sap_mon -check -username=<USERNAME> -password=<PASSWORD> -hostname=<SAP router string> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER> -monitor='RZ20 Monitor Propertie Name'

sap_mon -checkall = checks the CCMS from the given monitor with all submonitors.
	example: sap_mon -checkall -username=<USERNAME> -password=<PASSWORD> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER> -monitor='SAP CCMS Monitor Templates\Buffers'

sap_mon -aborted-job = See the last aborted background jobs in the system
	sap_mon -aborted-job -username=<USERNAME> -password=<PASSWORD> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>

sap_mon -abap-dump = Shows the last ABAP dump
	sap_mon -abap-dump -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>
 
sap router connection string:
sap_mon -abap-dump -username=<USERNAME> -password=<PASSWORD>> -hostname=/H/<sap router IP>/S/<sap router port>/H/<SAP Server> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>
	/H/<sap router IP>/S/<sap router port>/H/<SAP Server>
	saproutetab entry:
	P       <sap_mon IP address>   <SAP Server>    <SAP Port number (gwrd)>

sap_mon -sslview = x509 SAP certificats list overview (determine certificate subject for singel certificate check -sslcheck)
	sap_mon -sslview -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>

sap_mon -sslcheck = Check a single certifikcate in the list for its expiration date.
	sap_mon -sslcheck -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER> -subjectname='<x509 certificate subject>' -warn=30 -critical=15

sap_mon -rfc = RFC Connection Test
	sap_mon -rfc -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER> -rfcdestination='<RFC DESTINATION NAME>'




If you have any questions or suggestions or you want special modifications for your use case, don't hesitate to contact me software.moore@gmail.com




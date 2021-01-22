A small monitoring tool to check sap base health.

The tool reads the SAP CCMS values and check it to your defined thresholds.

The exit codes are best uses with Icinga / Nagios Monitoring.

It based on the SAP RFC SDK 7.50 for the SAP communication.

first download and configure SAP RFC SDK

https://support.sap.com/en/product/connectors/nwrfcsdk.html#section_1291717368

Than use simple "make" for comipling.

Here is also a "sap authorization role" transport for the SAP system. 

Simple import the transport request to use minimum permisions for the sap_mon monitoring user.



execute command:



sap_mon -show = show all available SAP monitors according to RZ20

example: sap_mon -show -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>




sap_mon -check = checks the CCMS Performance Attribute from the given monitor

example: sap_mon -check -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER> -monitor='RZ20 Monitor Propertie Name' -warn=<VALUE> -critical=<VALUE>




sap_mon -aborted-job = See the last aborted background jobs in the system

sap_mon -aborted-job -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>


sap_mon -abap-dump = Shows the last ABAP dumps
sap_mon -abap-dump -username=<USERNAME> -password=<PASSWORD>> -hostname=<HOSTNAME> -sid=<SAP SID> -sysnum=<SYSTEMNUMBER> -client=<CLIENT NUMBER>






if you have any question or suggestions don't hesitate to contact me software.moore@gmail.com

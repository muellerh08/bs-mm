---
layout: single
title: SQL Server
permalink: /docs/sql-server
sidebar:
  nav: doc_nav
toc: true 
---
<!-- {: .no_toc }
<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details> -->

## Einleitung

- 15.04.18: In [Installation](#installation) und [Kopieren/Verschieben von Datenbanken](#kopierenverschieben-von-datenbanken)werden zunächst alle bisherigen Einträge aus [Ursprüngliches ReadmeBp](./readme-bp#readmebp) und OneNote zusammengefasst, die sich entweder auf
Installationsfragen oder das Kopieren/Verschieben von Datenbanken beziehen.
- 18.04.2018: Zur Zeit frage ich mich (wieder einmal), ob ich mich bezüglich 
Sql Server von Root unabhängig machen sollte. So ist z.B. in TODBCServer GetErrorMsg()
nicht implementiert. Das war bei den jüngsten Schwierigkeiten mit dem Datentyp
'smalldatetime' recht unangenehm, weil ich zunächst überhaupt nichts über die
Absturzursache wußte. Erst beim Kopieren (und Abarbeiten) des fraglichen Befehls in
SSMS bekam ich eine ordentliche Fehlerbeschreibung. Also dürfte das doch auch vom
Programm aus möglich sein. Vielleicht sollte ich ja erst einmal eigene Klassen von den
entsprechenden Root-Klassen ableiten als Einstieg in die Problematik. Zunächst
ein hierher verschobener Eintrag aus [Ursprüngliches ReadmeBp](./readme-bp#readmebp):
- "03.03.16: Auf der Suche nach dem Memory Leak wollte ich die SQL-Klassen überprüfen,
indem ich abgeleitete Klassen erzeugen und dort die Erzeugung und Vernichtung
mit Bp::ObjCount() zählen wollte. Ich bin schon an BtODBCRow : public TODBCRow
gescheitert, weil beim Linken die TODBCRow-Methoden nicht gefunden wurden. 
Vielleicht liegt es ja an dem Plugin-Mechanismus, mit dem diese Klassen in das
Programm eingefügt werden (und den ich nicht verstehe). Als Alternative zu den
Root-Sql Klassen könnte vielleicht die 
[SQLAPI++ Library](http://www.sqlapi.com/index.html) (kostet 249$)
oder der [SQL Native Client](http://msdn.microsoft.com/en-us/library/ms130904.aspx), wie in
https://blogs.msdn.microsoft.com/jimblizzard/2014/06/03/c-and-sql-server/
diskutiert. Der Artikel [Data Access in Visual C++](https://msdn.microsoft.com/en-us/library/7wtdsdkh.aspx), könnte ein weiterer
Ausgangspunkt für mögliche Änderungen sein. Beispielcode gibt es hier:
http://blog.jamesrossiter.co.uk/2011/01/26/connecting-to-sql-server-from-c/ und
http://www.tidytutorials.com/2009/08/connecting-to-sql-server-using-c-odbc.html.
Zusammen mit dem Quellcode der Root-TODBCxxx Klassen könnte man daraus eigenen
Code basteln und verwenden (wenn es denn unbedingt nötig sein sollte)."
- BtODBCRow : public TODBCRow benötigt die Bibliothek libRODBC, dann funktioniert
auch das Linken.
- 19.04.2018: Bisher habe ich SqlServer Object mittels 
'fSqlServ=TSQLServer::Connect(fConStr.data(),0,0);' erzeugt. Da in Root die Verwendung
vieler Datenbanktypen vorgesehen ist, wird in Connect() ein Plugin Mechanismus in Gang 
gesetzt, den ich nach wie vor nicht durchschaue. Da ich ja nur einen Datenbanktyp habe
kann das Pluin durch einfaches Erzeugen via 
'fSqlServ=new TODBCServer(fConStr.data(),0,0);' umgangen werden. Oder eben auch mit
'fSqlServ=new BtODBCServer(fConStr.data(),0,0);', wenn die "eigene" Klasse
'BtODBCServer : public TODBCServer' verwende.
- 23.07.20: Eine Artikelserie zu vielen SQL Server Problemen gibt es in 
[SQLShack](https://www.sqlshack.com/), sogar mit einer Suchfunktion.
	
<!-- \subsection BsTd21 Sql Server - Installation -->
## Installation

- 09.02.16: TSQLServer: Hier muss ein Plugin installiert werden. Das geschieht durch den einmaligen Aufruf von 
- "root_v5.34.34\\Release\\etc\\plugins\\TSQLServer\\P050_TODBCServer.C" 

vom Command-Prompt des eigenen Programms RtN aus. Eventuell auch von root.exe aus.
Ich hatte beides gemacht und dann ging es irgendwann. Ich verstehe nicht, wie 
dieser Plugin-Mechanismus funktioniert, und wieso das mit einem einmaligen 
Aufruf getan ist. Ich habe jedenfalls keinerlei "Spuren" entdeckt, die dieser
Aufruf hinterlassen hat. Als Alternative könnte man eventuell den Inhalt von
P050_TODBCServer.C (gPluginMgr->AddHandler(...); ...) direkt in BpSqlMgr 
aufzurufen, oder gleich die verwendeten Programme TODBCResult, TODBCRow, 
TODBCServer und (TODBCStatement) aus	root\\sql\\odbc (, wobei TODBCStatement nicht 
zu funktionieren scheint???) in BpLibN zu kopieren.

- 10.02.16: Win8-12 ist inzwischen repariert und soll hauptsächlich für längere
Rechnungen verwendet werden. Der Quellcode und die Datenbanken auf Ac16 sollen
dabei verwendet werden. Beim Zugriff auf AC16\\SQLEX von Win8-12 aus gab es 
zunächst Schwierigkeiten, die aber mittels Internet und 'Sql Server Configuration
Manger' behoben werden konnten. Entscheidend war das Abändern von 'Log On As' im
Menupunkt SQL Server Services auf 'Build-in account' und dort auf 
'Network Service', und unter 'Protocols for SQLEX' muss 'TCP/IP' Enabled werden.
Auf Win8-12 fehlt unter 'Alle Apps'->'Microsoft SQL Server 2014' der Eintrag
'SQL Server Konfigurations Manager'. Hier muss SQLServerManager12.msc (für SQL 
Server 2014) gesucht und geöffnet werden (siehe: 
https://msdn.microsoft.com/de-de/library/ms174212%28v=sql.120%29.aspx).
- 08.03.2017: SQL Server Installation: Als Ausgangspunkt nehme ich: 
 https://msdn.microsoft.com/de-de/library/ms143219.aspx 
Als eine Installationsmöglichkeit steht dort: "
Installieren von kostenlosen Versionen von SQL Server 2016 direkt aus dem Internet"
Aus <https://msdn.microsoft.com/de-de/library/ms143219.aspx> 
Und das habe ich getan, sowohl auf Wi12, als auch (wahrscheinlich überflüssigerweise) auf Ac16. Welche 
Version läuft nun eigentlich auf den Rechnern? Dazu gibt es eine Anleitung:
https://support.microsoft.com/de-de/help/321185/how-to-determine-the-version,-edition-and-update-level-of-sql-server-and-its-components
Aber das bringt auch keine neue Erkenntnis. Es gibt noch keine neuen Instanzen.
Große Erleuchtung: Der Fehler bestand in der direkten Installation aus dem Internet. Ich
hatte 'SQLServer2016-SSEI-Expr.exe' heruntergeladen. Beim Starten erscheint eine Abfrage:
Wählen Sie einen Installationstyp: 1. Standard, 2. Benutzerdefiniert, 3. Medien herunterladen.
Ich hatte 'Standard' gewählt und war dann bei allen Aktionen im Installation Center an der Frage nach den 
Installationsmedien gescheitert. Auf Wi12 habe ich jetzt 'Medien herunterladen' gewählt. Dann können 
Sprache, Paket und Downloadverzeichnis festgelegt werden. Der Download erzeugt dann eine Datei 
'SQLEXP_x64_ENU.exe', die beim Ausführen ein gleichnamiges Verzeichnis (mit weiteren Unterverzeichnissen) 
erzeugt. Und dort gibt es dann eine 'SETUP.EXE', die beim Ausführen den 
Installationsassistenten startet.
- Aufruf von Sql Server Configuration Manger (SSCM): In Eingabeaufforderung 'mmc.exe' 
aufrufen. Dort unter Datei->Öffnen, im Fenster 'Öffnen' unter Dateiname in DropDown 
[C:\\Windows\\SysWOW64\\SQLServerManager13.msc] 
(<https://msdn.microsoft.com/de-de/library/ms174212(v=sql.130).aspx>) auswählen.
\n SSCM gibt es doch im Start-Menu unter 'Microsoft Sql Server 2016'. Die gerade 
beschriebene Prozedur über 'mmc.exe' ist also nicht nötig!
- Microsoft bietet auch einen Data Migration Assistant:
<https://blogs.msdn.microsoft.com/datamigration/2016/10/25/data-migration-assistant-how-to-migrate-your-on-premises-sql-server-instance-to-modern-sql-server-platforms/> 
Mir ist aber nicht klar, wofür der eigentlich gut ist. Könnten da Daten zwischen 
Servern übertragen werden???
- 09.03.17: Das ist der gleiche Fehler der auch im Microsoft Sql Server Management 
Studio (SSMS) auftritt. Zunächst habe ich überprüft, dass die Einstellungen im SSCM 
denen entsprechen, die ich in der ReadmeBp.txt am 10.02.16 beschrieben haben nämlich: 
"Beim Zugriff auf AC16\\SQLEX von Win8-12 (inzwischen Wi12) aus gab es zunächst 
Schwierigkeiten, die aber mittels Internet und 'Sql Server Configuration Manger' 
behoben werden konnten. Entscheidend war das Abändern von 'Log On As' im Menupunkt 
SQL Server Services auf 'Build-in account' und dort auf  'Network Service', und 
unter 'Protocols for SQLEX' muss 'TCP/IP' Enabled werden." Damit hatte es damals 
funktioniert.

Das hat zunächst nichts gebracht. In 2016 hatte ich mich noch auf Windows mit 
einem lokalen Konto angemeldet, inzwischen aber mit dem Microsoft Konto. Das habe ich 
rückgängig gemacht, und alles funktioniert offenbar, zumindest was das SSMS betrifft.
Aber leider nicht der DMA. Dort werden Fehler in allen Datenbasen angezeigt, mit denen
ich wenig anfangen kann. Mit DMA beschäftige ich mich erst mal nicht mehr.
- 13.03.17: Beim Aufruf von WI12\\SQLEX von Ac16 aus tritt obiger SSPI-Fehler wieder auf.
Ich bin mir ziemlich sicher, dass ich es nach der (Rück-)Umstellung auf lokale 
Windows 10 Konten in beide Richtungen probiert hatte. Wichtiger ist allerdings der 
Aufruf von AC16\\SQLEX von Wi12 aus. Und das geht. Die Einstellungen im SSCM auf beiden
Rechnern sind gleich. Also doch bei Gelegenheit den (langen) Artikel 
[Problembehandlung bei der Fehlermeldung "SSPI-Kontext kann nicht generiert werden"]
(<https://support.microsoft.com/en-us/help/811889/how-to-troubleshoot-the-cannot-generate-sspi-context-error-message> )
ansehen!?
- 15.04.18: Zur Zeit kann ich alle Datenbanken von beiden Rechnern aus aufrufen mittels 
SSMS, obwohl ich nichts (zumindest soweit ich mich erinnern kann) getan habe.

<!-- \subsection BsTd22 Sql Server - Kopieren/Verschieben von Datenbanken -->
## Kopieren/Verschieben von Datenbanken

- 24.02.13: Mit dem Hilfsprogramm bcp können große Datenmengen importiert und
exportiert werden. In einem ersten Schritt muß offenbar eine Format-Datei
für die betreffende Tabelle erzeugt werden. Das kann z.B. mit dem Befehl
\n "bcp TeWi.dbo.Info format nul -c -x -f TeWiInfo.xml -t; -SWIN8-12\\SQLEX -T"
geschehen, wobei TeWi.dbo.Info die Info-Tabelle aus der Datenbasis TeWi ist,
TeWiInfo.xml ist die erzeugt Xml-Format-Datei, wo als Trennungszeichen ein ';'
verwendet wird.
Dann kann damit die gesamte Tabelle ausgegeben werden mittels
\n "bcp TeWi.dbo.Info out c:\\WisoDat\\TeWiInfo.bcp -SWIN8-12\\SQLEX -T -format c:\\WisoDat\\TeWiInfo.xml"
\n Die ersten Zeilen sehen dann so aus, wie man sie auch beim Exportieren aus 
	WisoBörse erzeugen kann:
\n T121412;121412;LU0175704047;FlaFo0;DB Platinum Dynamic Bd Pl R1C;Fonds;Investmentfonds;EUR;FlaFo0S
\n T121413;121413;;FlaFo0;DB Platinum Dynamic Bd Pl R1D;Fonds;Investmentfonds;EUR;FlaFo0S
\n T121509;121509;;FlaFo0;The Cazenove Pan Europe B EUR;Fonds;Investmentfonds;EUR;FlaFo0S
- 14.02.16: Das Kopieren einer Tabelle geht (wahrscheinlich) am einfachsten über die
Erzeugung eines Scriptes im Sql Server Management Studio, wie in Eintrag 37 von
\n http://stackoverflow.com/questions/680552/table-level-backup beschrieben:
Rechtsklick auf Datenbasis->Tasks->Generate Scripts und weiter wie dort 
beschrieben. Wichtig ist die Ausgabe der Daten über die 'Advanced' Option in 
einem der folgenden Schritte. Das so erzeugte *.sql File wird dann wieder im
SSMS abgearbeitet. Falls der Tabellenname geändert werden soll, dann entsprechende
(sehr viele) Änderungen im gesamten Script vornehmen.
- 11.03.17:  Zum Kopieren von Datenbanken gibt es offenbar viele Möglichkeiten. Die 
einfachste wäre sicherlich die Verwendung des  [Copy Database Wizard]
(<https://msdn.microsoft.com/en-us/library/ms188664.aspx>). Aber den gibt es leider 
nicht in der Express-Ausgabe von Sql Manager. Eine andere Variante könnte sein 
[Copy Databases with Backup and Restore]
(<https://msdn.microsoft.com/en-us/library/ms190436.aspx>).
Scheint aber mit viel "Handarbeit" verbunden zu sein. Das Backup mache ich schon seit 
einiger Zeit mit Hilfe eines Scriptes. Nur Restore muss "von Hand" gemacht werden. 
Wenn ich das auch noch in den Script packen könnte, dann wäre das eine praktikable 
Möglichkeit. 
\n 12.03.17: Und das geht tatsächlich. Das wäre also eine Lösung.
- Obwohl für den Transfer zwischen verschiedenen Datenbank-Typen gedacht, könnt man 
vielleicht auch über [Import and Export Data with the SQL Server Import and Export 
Wizard](<https://msdn.microsoft.com/en-us/library/ms141209.aspx>) 
nachdenken? Hier müssten vielleicht nicht die gesamten Datenbanken hin und her kopiert
werden.
- 25.03.18: Da es auf Ac16 wieder einmal eng wird auf dem C-Drive suche ich nach einer 
Möglichkeit, die Daten nach dem E-Drive zu verschieben. Verschiedene Möglichkeiten 
werden in [Options to Move a Big SQL Server Database to a New Drive with Minimal 
Downtime]
(<https://www.mssqltips.com/sqlservertip/3212/options-to-move-a-big-sql-server-database-to-a-new-drive-with-minimal-downtime/>)
 diskutiert. Das Problem wird auch in [How do I move SQL Server database files?]
(<https://dba.stackexchange.com/questions/52007/how-do-i-move-sql-server-database-files>)
besprochen.
\n Wichtig in diesem Zusammenhang eventuell auch 
[View or Change the Default Locations for Data and Log Files]
(<https://docs.microsoft.com/en-us/sql/database-engine/configure-windows/view-or-change-the-default-locations-for-data-and-log-files>)
- 26.03.18: Durch Löschen von Programmen sind jetzt wieder 25GB frei auf C:, 
da lass ich die Daten von SqlServer am gewohnten Platz. Hab allerdings auch die nicht 
mehr benutzte Datenbank WiFo (die größte) gelöscht.
- 18.04.2018: Da der Platz auf Ac16 immer wieder knapp wird, habe ich die Datenbanken
auf Wi12 gebracht. Das ging mit $env:(BSTD)/Work/DaBa/Sql/Backup.ps1 und 
...Restore.ps1. Die Backup's mussten allerdings auf den anderen Rechner kopiert
werden. Bei der Verwendung gab es dann allerdings erst einmal Schwierigkeiten mit der
Datenbank BT1, weil als Datentyp für Spalte Datum smalldatetime verwendet wurde. Das
hängt irgendwie mit den 'locale' Einstellungen zusammen. Mit varchar(20) anstelle von
smalldatetime geht alles.
- 15.02.19: Der Transfer der Tabellen von Ac16\\SQL17 zum neuen Rechner Me19\\SQL17
war wieder ziemlich umständlich. Während das Script 
...\\BsTd\\Work\\DaBa\\Sql\\Backup.ps1 noch tat, was es sollte, funktionierte 
...\\Restore.ps1 nicht. Auch das manuelle Einlesen mittels SSMS 
(Databases->Restore Database->Device->...->Backup media type=File->Add) funktionierte erst,
nachdem ich die *.bak Files in 
C:\\Program Files\\Microsoft SQL Server\\MSSQL14.SQL17\\MSSQL\\Backup kopiert hatte.

<!-- \subsection BsTd23 Sql Server 2017 - Installation -->
## Sql Server 2017 - Installation

- 16.05.18: Wegen des begrenzten Speicherplatzes auf Laufwerk c: von Ac16 soll auf e:
installiert werden. Zunächst eine Link-Sammlung, die hoffentlich hilfreich sein wird:
\n http://www.kodyaz.com/sql-server-2017/install-sql-server-2017.aspx
\n https://www.brentozar.com/archive/2017/10/sql-server-2017-installation-screenshot-tour-windows/
\n https://www.credera.com/blog/infrastructure/perform-new-install-sql-server/
\n 1. Datei SQLServer2017-SSEI-Expr.exe von 
https://www.microsoft.com/en-us/sql-server/sql-server-downloads heruntergeladen.
\n 2. Medien herunterladen gewählt. Danach Englisch und Express Core (275 MB) 
ausgewählt. Danach werden Medien heruntergeladen: Datei SQLEXPR_x64_ENU.exe, 
die beim Ausführen ein gleichnamiges Verzeichnis (mit weiteren Unterverzeichnissen) 
erzeugt. Und dort gibt es dann eine 'SETUP.EXE', die beim Ausführen das 'SQL Server
Installation Center' (SSIC) startet.
\n 3. Ab hier alles im SSIC
\n 3.1 Installation: 'New SQL Server stand-alone ...' ausgewählt.
Nach Bestätigung der 'License Terms' öffnet sich neues Fenster 
\n 3.2 Install Rules und es
tut sich irgendwas, das in dem File \verbatim
 C:\Program Files\Microsoft SQL Server\140\Setup Bootstrap\Log\20180516_094233\SystemConfigurationCheck_Report.htm
 bzw. am 14.02.19 auf dem neuen Rechner Me19
 C:\Program Files\Microsoft SQL Server\140\Setup Bootstrap\Log\20190214_150313\SystemConfigurationCheck_Report.htm
\endverbatim dokumentiert ist.
\n 14.02.19: Die Rule "Windows Firewall" liefert einen Status "Warning" mit einem 
Hinweis auf \verbatim
https://docs.microsoft.com/de-de/sql/sql-server/install/configure-the-windows-firewall-to-allow-sql-server-access?view=sql-server-2017
\endverbatim
\n 3.3 Nächstes Fenster 'Feature Selection': 'Select All' ausgewählt und als 
Instance root directory: \verbatim E:\Program Files\Microsoft SQL Server  !!!!!!!!!!!!!!!!
\endverbatim gesetzt.
\n 14.02.19: 3.31 ES gibt ein weiteres Fenster "Feature Rules". Dort hat die Rule
"Oracle JRE 7 Update 51 (64-bit) ..." den Status "Failed". Im obigen Bericht wird die 
Installation von Oracle SE Java Runtime Environment von \verbatim
https://go.microsoft.com/fwlink/?LinkId=526030 \endverbatim verlangt.
Das habe ich getan und "Re-run" ausgeführt, was sofort zum nächsten Punkt führt.
\n 3.4 Instance Configuration: Named Instance SQL17 benannt.
\n 14.02.19: 3.4.1  PolyBase Configuration: "Use this SQL Server as standalone 
PolyBase-enabledinstance" ausgewählt.
\n 3.5 Server Configuration: alles übernommen
\n 3.6 Database Engine Configuration: default: Windows authentication mode
\n 14.02.19: 3.6.1: Consent to install Microsoft R Open: Accept
Nur nach "Accept" kann "Next" ausgeführt werden zu
\n 3.6.2: Consent to install Python: Accept
\n 3.7 Installation Progress
\n 3.8 Complete: Log File siehe \verbatim
C:\Program Files\Microsoft SQL Server\140\Setup Bootstrap\Log\20180516_094233\Summary_Ac16_20180516_094233.txt
bzw.: 14.02.19: 
C:\Program Files\Microsoft SQL Server\140\Setup Bootstrap\Log\20190214_150313\Summary Me19 20190214_150313.txt
\endverbatim
- Während der Installation erfolgte ein Absturz von Wi12. Ich habe keine Ahnung, ob
das Zufall war, oder ob da ein Zusammenhang besteht. Vom SSMS aus kann auch nicht
mehr auf den anderen Rechner zugegriffen werden. Auch die Backups von Wi12 konnte 
ich nicht auf Ac16\\SQL17 installieren, weder mit ...\\DaBa\\Sql\\Restore.ps1, noch
mit SSMS. Genauer: Wi12\\SQLEX ist überhaupt nicht mehr ereichbar (Zusammenhang mit
Absturz???) Ac16\\SQL17 von Wi12 aus nicht erreichbar.
- Für Wi12/SQLEX war der Server Dienst beendet. Nach Neustart des Dienstes, 
[siehe 08.03.17 Aufruf von Sql Server Configuration Manger (SSCM)](#BsTd21), 
geht wieder alles.
- Für Ac16/SQL17: SSCM->Sql Server Services -> 'Log On As'->Rechtsklick->
Eigenschaften: Dort statt 'This account' 'Build-in account' anklicken und dort
'Network service' auswählen. Weiter: SQL Server Network Configuration -> 
Protocols for SQL17 -> TCP/IP enable. Nach Neustart des Service scheint alles zu
funktionieren. Installation der Backups von Wi12 war zumindest mittels SSMS möglich.
- 14.02.19: Wiederholung obiger Prozedur vom 16.05.18 für Me19. Es gab ein paar zusätzliche Punkte,
die mit dem Datum 14.02.19 "markiert" sind.
\n Weiter im SSIC: Install SQL Server Management Tools
Das führt zur Downloadseite von SSMS 17.9.1 \verbatim
https://docs.microsoft.com/de-de/sql/ssms/download-sql-server-management-studio-ssms?view=sql-server-2017
\endverbatim
von wo "ganz normale" Installation erfolgt. Nach Durchführung der oben für Ac16/SQL17 beschriebenen
Prozedur:
- Für Me19/SQL17: SSCM->Sql Server Services -> 'Log On As'->Rechtsklick->
Eigenschaften: Dort statt 'This account' 'Build-in account' anklicken und dort
'Network service' auswählen. Weiter: SQL Server Network Configuration -> 
Protocols for SQL17 -> TCP/IP enable, Neustart des Service
- 15.02.19: Von SSMS aus können sich Me19 nicht mit Ac16/SQL17 und Ac16 nicht mit 
Me19/SQL17 verbinden wegen "Cannot connect to AC16\\SQL17. The target principal name 
is incorrect. Cannot generate SSPI context. (Microsoft SQL Server, Error: 0)"
\n KLärung steht aus!!!, Vielleicht hier [How to troubleshoot the 
"Cannot generate SSPI context" error message]
(https://support.microsoft.com/en-ph/help/811889/how-to-troubleshoot-the-cannot-generate-sspi-context-error-message)
\n In diesem Artikel verstehe ich erst mal Bahnhof, es ist aber von local Accounts
die Rede. So habe ich als erstes für Ac16 und Me19 von "Microsoft" auf "local"
Konto umgestellt. Das bringt gar nichts. 
\n Nächster Versuch: Rechnung auf Ac16 mit Zugriff auf Me19\\SQL17. Da kommt folgender 
Fehler: "RmM.exe : Error in <TODBCServer::TODBCServer>: Code: 18452 
Msg: [Microsoft][ODBC SQL Server Driver][SQL Server]Login 
failed. The login is from an untrusted domain and cannot be used with Integrated 
authentication."
- Nächster Versuch: Wi12 verwendet. Von SSMS2016 aus Zugriff auf Me19\\SQL17. Hier
bestand die Hoffnung darin, dass Wi12 und Me19 beide Windows Pro haben, während Ac16
nur Windows Home hat. Aber: 
Gleicher Fehler: "The login is from an untrusted domain and cannot be used with 
Integrated authentication. (Microsoft SQL Server, Error: 18452)". Das gleiche gilt
für Zugriff von Me19 auf Wi12.
- Und nun gibt es im Internet alle möglichen Vorschläge, z.B. in der Datei
C:\\Windows\\System32\\drivers\\etc\\host localhost einzutragen(= # entfernen).
Bringt keinen Effekt. Was mich schon lange stört, ist die Tatsache, dass sich Ac16
in 'Netzwerk3', Me19 aber in 'Netzwerk' befindet. Vielleicht sollte ich das erst mal
"angehen". Wahrscheinlich ist das die Ursache, das im Windows Explorer unter 
Netzwerk nur Me19 angezeigt wird (kann geändert werden durch Eintrag von \\Ac16 in
Adresszeile). In diesem Zusammenhang könnten 
[DasHeimnetzwerk.de](https://www.dasheimnetzwerk.de/index.html) und
[How to change a network's name in Windows 8 or 10]
(https://www.download3k.com/articles/How-to-change-a-network-s-name-in-Windows-8-or-10-01258)
von Interesse sein. Nach dieser Anleitungen, Variante 2, habe ich auf Ac16 
'Netzwerk 3' in 'Netzwerk' umbenannt mit regedit. Das hat aber keinen Einfluss auf 
die Anzeige der Netzwerke im Windows Explorer und auf den gegenseitigen "Zugriff" 
von SSMS aus.
- Nachtrag 16.02.19: Dem Artikel [PC wird im Netzwerk nicht angezeigt]
(https://www.deskmodder.de/blog/2018/05/06/pc-wird-im-netzwerk-nicht-angezeigt-gefunden-windows-10-1803-loesung/)
folgend habe ich den Dienst Funktionssuche-Ressourcenveröffentlichung auf Ac16 von 
manuell auf automatisch umgestellt und gestartet. Danach wurde alles "normal" 
angezeigt. Aber das hat keinen Einfluß auf das SQL Server Problem. Die in den Logs
angezeigten Fehler lauten: 
\n 1. Error: 17806, Severity: 20, State: 14.
\n 2. SSPI handshake failed with error code 0x8009030c, state 14 while establishing 
a connection with integrated security; the connection has been closed. 
Reason: AcceptSecurityContext failed. The operating system error code indicates 
the cause of failure.   [CLIENT: fe80::d48f:be4f:7bf5:d5ed%7]
\n 3. Error: 18452, Severity: 14, State: 1.
\n 4. Login failed. The login is from an untrusted domain and cannot be used with 
Integrated authentication. [CLIENT: fe80::d48f:be4f:7bf5:d5ed%7]
- [SQL Server Database Engine](https://docs.microsoft.com/de-de/sql/database-engine/sql-server-database-engine-overview?view=sql-server-2017).
Als Ausweg bleibt die Erstellung von Datenbanknutzern [Create a Database User]
(https://docs.microsoft.com/de-de/sql/relational-databases/security/authentication-access/create-a-database-user?view=sql-server-2017)
Aber das wird unnötig kompliziert, und das möchte ich unbedingt vermeiden. Bleibt also 
die Frage, wieso sich die beiden Rechner in unterschiedlichen Domänen befinden,
obwohl es doch gar keine Domänen gibt (so glaube ich jedenfalls).
- Als letzten Versuch für heute habe ich für beide Rechner die Konten wieder auf 
Microsoft-Konto geändert, weil ich dachte das sei sowas wie die gleiche 'Domäne'. Aber
weit gefehlt, jetzt kommt wieder der Fehler: 'Cannot generate SSPI context'. Dieser
Verbindungsversuch hinterlässt keine Spuren in den SQL Server Logs, wird also noch
'früher' beendet, als mit den lokalen Konten, auf die ich wieder umgestellt habe. 
Und der Fehler wechselt wieder zu "The login is from an untrusted domain ...", was 
auch im SQL Server Log erscheint.
- 16.02.19: Überprüfung von Arbeitsgruppe, Domäne, ... siehe [hier]
(https://it-learner.de/windows-10-einer-domaene-hinzufuegen/) bringt auch nichts.
\n Den Beitrag [Login failed. The login is from an untrusted ...]
(https://social.msdn.microsoft.com/Forums/azure/en-US/a90f2fe1-e43a-4ab0-9072-63ddaf4a4004/login-failed-the-login-is-from-an-untrusted-domain-and-cannot-be-used-with-integrated?forum=sqldatabaseengine)
muss ich mir noch genauer anschauen.
- 17.02.19: [How to make sure that you are using Kerberos authentication ...]
(https://support.microsoft.com/en-us/help/909801/how-to-make-sure-that-you-are-using-kerberos-authentication-when-you-c)
After you connected to an instance of SQL Server 2005, run the following 
Transact-SQL statement in SQL Server Management Studio:
select auth_scheme from sys.dm_exec_connections where session_id=@@spid
\n In der 'auth_scheme' Spalte erscheint aber NTLM. Das scheint aber daran zu liegen,
dass eine lokale Verbindung hergestellt wurde. ->
"Kerberos is used when making remote connection over TCP/IP if SPN presents.", siehe
[Why is MS SQL Server Using NTLM Authentication?]
(https://serverfault.com/questions/596659/why-is-ms-sql-server-using-ntlm-authentication)
\n Siehe auch: 
[Understanding Kerberos and NTLM authentication in SQL Server Connections]
(https://blogs.msdn.microsoft.com/sql_protocols/2006/12/02/understanding-kerberos-and-ntlm-authentication-in-sql-server-connections/)
\n Und [SQL Server Database Engine]
(https://docs.microsoft.com/de-de/sql/database-engine/sql-server-database-engine-overview?view=sql-server-2017)
- 18.02.19: Der Beitrag [How do I create a Windows Authentication user in a 
workgroup environment where there is no domain controller?]
(https://support.na.sage.com/selfservice/viewContent.do?externalId=70761&sliceId=1)
brachte schließling die Lösung. Dort ist zu lesen:
... ensure that:
\n 1. Each user has a local machine account on both the server and the client 
machines.
\n 2. The local machine account names on the server and the client match exactly - 
case, spaces, characters (see the Note at the bottom of this section).
\n 3. The passwords for the local machine account on the server and client match 
exactly - case, spaces, characters.
- 19.02.19: Die gesamte Installation von SQL Server ist sehr schön beschrieben in 
[How to install Microsoft SQL Server]
(https://wiki.unify.com/wiki/How_to_install_Microsoft_SQL_Server). Dort bin ich auch
auf die Möglichkeit gestoßen, als Login 'sa' mit einem bei der Installation zu 
setzenden Passwort und SQL Server Authentication zu benutzen. Damit kann ich mich
nun von Ac16 aus auf Me19\\SQL17 zugreifen. 
\n Vorher hatte ich schon mein Me19 Konto von User in muellerh umbenannt. Der 
Homepfad ist aber immer noch User, weil ich mich nicht an der Registry vergreifen
wollte. Dann habe ich SQL Server deinstalliert und neu installiert. Es ist mir aber
auch dabei nicht gelungen, den Usernamen der Verbindung ME19\\User auf ME19\\muellerh
abzuändern. Die Erstinstallation hatte ich als Benutzer 'User' gemacht. Das wäre
wahrscheinlich die Voraussetzung für das Benutzen der Windows Authentication gewesen.
\n Auch das Anlegen eines neuen Account Logins, wie z.B. in 
[Updated-How to Create a SQL Server Computer Account Login]
(https://www.enhansoft.com/updated-how-to-create-a-sql-server-computer-account-login/)
beschrieben, gelingt mir nicht, weil SSMS alle meine Namen als ungültig zurückweist.
- Das Hauptproblem ist also der Fakt gewesen, dass der Verkäufer den Nutzer User
installiert hatte, und ich damit SQL Server installiert habe. Ich hätte sofort
einen zu Ac16 identischen Nutzer muellerh anlegen müssen, dann wäre mir viel Zeit
erspart geblieben!!!

<!-- \subsection BsTd24 Sql Server 2019 - Installation -->
## Sql Server 2019 - Installation

- 01.07.20: Update von SQL Server 2017 auf 2019 durchgeführt. Da es sich diesmal
nicht um eine Neuinstallation, sondern ein Upgrade handelte, bin ich nach folgenden
Artikel vorgegangen: [How to Upgrade Microsoft SQL Server the Right Way](https://thebackroomtech.com/2019/03/28/how-to-upgrade-microsoft-sql-server-the-right-way/).
Das hat auch ganz gut funktioniert. Neu dabei war die Verwendung des 
Data Migration Assistant.
- Die Bezeichnung der Server Instanz, SQL17, ist allerdings unverändert. Eine
Änderung auf SQL19 scheint aber schwierig zu sein!
- Protokoll des Upgrades befindet sich auf: 
file:///C:/Program%20Files/Microsoft%20SQL%20Server/150/Setup%20Bootstrap/Log/20200701_112928/Summary_Me19_20200701_112928.txt
- 17.08.20: Der Zugriff vom Programm BsTd auf Ac16 funktioniert der Zugriff auf 
ME19\\SQL17 nicht mehr, obwohl von SSMS auf AC16 aus der Zufriff mit SQL Server 
Authentication, Login: sa, Passwort sa möglich ist.

````text
Bisheriger Connection String in BpSqlMgr war: 
     string fConStr="odbcd://Driver={SQL Server};Server="+"ME19\\SQL17;
 Das funktionierte aber nur von Me19 aus, nicht von Ac16. Mit
     string fConStr="odbcd://Driver={SQL Server};Server="+"ME19\\SQL17
                    +";Uid=sa;Pwd=sa"+";Trusted_Connection=no;";
Geht es für beide Rechner.
````

<!-- \subsection BsTdFt Sql Server - FileTable -->
## Sql Server - FileTable

- 23.07.20: Um FileTables verwenden zu können sind einige "Vorarbeiten" zu
erledigen, die in [Enable the Prerequisites for FileTable](https://docs.microsoft.com/en-us/sql/relational-databases/blob/enable-the-prerequisites-for-filetable?view=sql-server-ver15)
beschrieben sind. Die Verwendung ist dann in den dort folgenden Kapiteln
dargelegt.

<!-- \subsection BsTdBak SSMS und Backup -->
## SSMS und Backup

- 11.07.20: Funktioniert gut mit SSMS. Ich habe das File 
D:\\HmD\\Backup\\SQL\\SqlBackup.bak als Backup Device deklariert, wie in 
[Define a Logical Backup Device for a Disk File (SQL Server)](https://docs.microsoft.com/en-us/sql/relational-databases/backup-restore/define-a-logical-backup-device-for-a-disk-file-sql-server?view=sql-server-ver15)
beschrieben. Der Default-Speicherort befindet sich auf dem gleichen Disk wie die
Datenbasis, und der 2. Disk hat jede Menge freien Speicherplatz.
Das erleichtert dann das Erstellen des eigentlichen Bachups, wie in
[Quickstart: Backup and restore a SQL Server database on-premises](https://docs.microsoft.com/en-us/sql/relational-databases/backup-restore/quickstart-backup-restore-database?view=sql-server-ver15),
beschrieben. Den Inhalt des Backups kann man sich ansehen, siehe
[View the contents of a backup tape or file (SQL Server)](https://docs.microsoft.com/en-us/sql/relational-databases/backup-restore/view-the-contents-of-a-backup-tape-or-file-sql-server?view=sql-server-ver15).
Das Restoren hab ich noch nicht probiert.
- Die [10 SSMS Tips and Tricks to boost your Productivity](https://www.sqlshack.com/10-ssms-tips-and-tricks-to-boost-your-productivity/)
und Links darin dürften ganz nützlich sein für das Arbeiten mit SSMS.

<!-- \section BsTdSR SQL Server und Root -->
## SQL Server und Root

- 28.03.19: Mir schwebt eine "graphische Auswertung" der SQL Tabellen mit den
Backtest Ergebnissen mittels TTree vor. Ein solches ""SQL I/O" package is currently 
under development.", wie in "class TSQLFile: public TFile" nachzulesen ist. Dazu
gibt es auch einen Artikel [ROOT I/O FOR SQL DATABASES](http://web-docs.gsi.de/~go4/go4gside/CHEP2006/sqlio_paper.pdf).
- 01.04.19: Die dafür vorgesehene Klasse ist TTreeSQL. Dort sind viele Methoden
noch nicht implementiert. Ich habe es trotzdem versucht, und bin (vorläufig) am
"Füllen" des erzeugten Objektes gescheitert (siehe Klasse RtTreeSQL). Mit 
TTreeSQL soll offenbar das Umwandeln einer beliebigen SQL-Tabelle in einen Tree 
erreicht werden. Eine spezielle Lösung für die Backtest-Tabellen aus BT3 sollte
"von Hand" machbar sein.
- 03.04.19: Ein ähnliches Problem ist das Erzeugen eines TTree-Objektes mit allen
Fit-Schritten. Das dürfte interessante Einblicke in die Parameterabhängigkeit der
Handelssysteme liefern. Ein TTree wird in einem TFile abgespeichert. Beide sind
für große Datenmengen geeignet. Allerdings scheint ein Update, wie es bei 
SQL-Tabellen einfach möglich ist, bei einen TTree schwierig zu sein. Deshalb 
dürfte es sinnvoller sein, kleinere TFile's zu erzeugen, die genau zu einer Zeile
in den SQL-Tabellen gehören. Diese TFile's müssten dann beim Updaten einer Zeile 
durch das dabei erzeugten neue TFile ersetzt werden. Zum Speichern solcher Objekte
gibt es verschiedene Möglichkeiten: 
[How Should We Store Images And Blob Files In SQL Server](https://www.c-sharpcorner.com/article/how-should-we-store-images-and-blob-files-in-sql-server/),
oder [Storing files in SQL Server](https://stackoverflow.com/questions/13420305/storing-files-in-sql-server) mit
Referenzen darin, oder [Storing Files in SQL Database Using FILESTREAM – Part 1](https://codingsight.com/storing-files-in-sql-database-using-filestream-part1/).
Die günstigste Lösung scheint mir im Moment das Speichern der
TTree's in einer separaten Tabelle zu sein, falls die TTree's nicht zu groß werden.

<!-- \section BsTdSCp Sql Server - Client Programmierung native C++ -->
## Client Programmierung native C++

08.07.21: BpSqlMgr ist "Root-basiert", BqSqlMgr ist "Qt-basiert", wünschenswert
wäre die direkte Verwendung von [SQL Server Native Client Programming](https://docs.microsoft.com/en-us/sql/relational-databases/native-client/sql-server-native-client-programming?view=sql-server-ver15#:~:text=SQL%20Server%20Native%20Client%20is%20a%20stand-alone%20data,ODBC%20driver%20into%20one%20native%20dynamic-link%20library%20%28DLL%29.)
ohne obige Zwischenschritte. Ein Beispielprogramm
[C++ ODBC example application accesses a SQL database](https://docs.microsoft.com/en-us/sql/connect/odbc/cpp-code-example-app-connect-access-sql-db?view=sql-server-ver15)
macht allerdings keinen sehr einladenden Eindruck.

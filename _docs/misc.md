---
layout: single
title: Verschiedenes
permalink: /docs/misc
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

# Verschiedenes

<!-- \section BsTdKd Kurs-Datenbasis -->
## Kurs-Datenbasis

- 22.01.21: Für Backtest-Rechnungen habe ich bisher nur die Daten aus Wiso-Börse
verwendet. Hinzu kommt, dass ich mich nahezu ausschließlich auf Fonds konzentriert
habe. Die Daten aus Wiso-Börse können in ein txt-File exportiert werden, das in die
SQL-Datenbasis Wiso eingelesen wird. Ganz am Anfang hatte ich die 
(Fehl-)Entscheidung getroffen, für Aktion und Fonds das gleiche Tabellenformat zu
verwenden, und entsprechend den Datenexport auch einheitlich zu gestalten mit
ISIN,Datum,Open,High,Low,Close,Volume,Kassa. Für Fonds benutze ich aber 
ausschließlich den Kassa-Kurs=Rücknahmepreis. High enthält den Ausgabepreis (wenn
vorhanden) und Open den Zwischengewinn (wenn vorhanden).
- 23.01.21: Bisher habe ich beim Datenexport zwischen KurseA (Aktien) und
KurseF (Fonds) unterschieden, wobei der ganze Unterschied darin bestand, dass im 
Fall von KurseF für Close und Kassa zusätzlich das Feld 'Dividenden verrechnen'
angekreuzt war. Das hat aber keinerlei Auswirkungen auf die ausgegebenen Werte.
Deshalb wird ab heute einheitlich mit 'Kurse' ausgegeben, wo diese Felder nicht
angekreuzt sind. Zu überlegen bleibt, ob in Zukunft für Aktien und Fonds 
verschiedene Datenstrukturen verwendet werden sollten. Hierbei steht Fonds für alle
Wertpapiere, für die nur ein Kurs pro Tag verfügbar ist, und Aktie für
börsengehandelte Wertpapiere mit Open, High, Low und Close.

<!-- \subsection BsTdAk Aktualisierung Datenbasis -->
### Aktualisierung Datenbasis
23.01.21: Beispiel: Hinzufügen von 2 ETFs (IE00B53SZB19 und IE00B1XNHC34) mittels
Wiso Börse:
- 1.: Mit Kursdaten-Export-Konfiguration Ifo werden die Eingabedaten für die
Info-Tabelle Wiso.afo.Ifo in c:\\Wiso\\Ifo.txt geschrieben und mit 
...\\Work\\DaBa\\Wiso\\Wiso.ps1 'Wiso,Wiso,Ifo' IfoWiso eingelesen.
- 2.: Zuordnung eines Verzeichnisses: Mit Kursdaten-Export-Konfiguration Dir wird 
die Eingabe für EDir in der Info-Tabelle Wiso.afo.Ifo in c:\\Wiso\\Dir.txt 
geschrieben und mit ...\\Work\\DaBa\\Wiso\\Wiso.ps1 'Wiso,Wiso,EDir' DirWiso 
eingelesen.
- 3.: Mit Kursdaten-Export-Konfiguration BtSc wird die Eingabe für BtSc in der 
Info-Tabelle Wiso.afo.Ifo in c:\\Wiso\\BtSc.txt geschrieben und mit 
...\\Work\\DaBa\\Wiso\\Wiso.ps1 'Wiso,Wiso,BtSc' BtScWiso eingelesen.
- 4.: Kursdaten mit Kursdaten-Export-Konfiguration Kurse in c:\\Wiso\\Kurse.txt 
schreiben und mit ...\\Work\\DaBa\\Wiso\\Wiso.ps1 'Wiso,Wiso,Kurse,1' Kurse 
einlesen.
- 5.: Das Feld DayeLo in Wiso.afo.Ifo belegen mit 
...\\Work\\DaBa\\Wiso\\Wiso.ps1 'Wiso,Wiso,DayeLo' DayeLoWiso

27.05.21: Die am 23.01.21 beschriebene Dateneingabe hat sich geändert, siehe
[Eingaben zu Rechnungen/Misc/Hdl](@ref WkIn).
[//]: # ([Eingaben zu Rechnungen](@ref CalcIn) Abschnitt Misc/Hdl.)

28.05.21: Die (vor ziemlich langer Zeit) zusammengestellten Datensätze für die 
Betrachtung von Handelssystemen enthalten mittlerweile Wertpapiere, für die es keine
aktuellen Daten mehr gibt. Diese sollten deshalb aus den Spalten 'EDir' und 'BtSc' 
von afo.Ifo entfernt werden. Das ist möglich durch Ausgabe eines Files aus 
Wiso Börse, wobei jede Zeile mit einem '-' Zeichen beginnen muss (siehe 
BqSqlMgr::IfoHdlCol()). Wahrscheinlich ist es einfacher, zunächst alle betreffenden 
Einträge zu löschen, z.B. kComfo in Spalte BtSc (BqSqlMgr::IfoDelItem()) und danach 
die noch aktuellen Wertpapiere mittels eines Files aus Wiso Börse neu einzufügen 
unter Verwendung von BqSqlMgr::IfoHdlCol(). Die Aufrufe erfolgen in 
Rm::RmIoMgr::ExHdl(). Für die jeweilige Ausführung siehe 
[Eingaben zu Rechnungen/Misc/Hdl](@ref WkIn).
\n In Spalte EDir 52 Einträge mit ComFo, in Spalte BtSc 52 Einträge mit kComFo
\n In Spalte EDir 40 Einträge mit DiBaFo, in Spalte BtSc 40 Einträge mit kComFo
\n In Spalte BtSc 81 Einträge mit kCoDiFo = kComFo+kDiBaFo

<!-- \subsection BsTdWm Wochen- und Monatskurse -->
### Wochen- und Monatskurse
- 30.10.18: Die Kurse werden in BpQuoteMgr::QuotesWeek() und BpQuoteMgr::QuotesMonth()
erzeugt, wobei die Wochenkurse jeweils dem Freitag und die Monatskurse dem letzten
Werktag im Monat zugeordnet werden. So wird es z.B. auch in Wiso-Börse gemacht. Im
Zusamenhang mit dem Ichimoku-Indikator habe ich mich nun erstmals mit dem Problem 
beschäftigt, Monats-, Wochen- und Tageskurse zusammen mit diversen Indikatoren in einem
Koordinatensystem darzustellen. Als einheitliche x-Achse kommt eigentlich nur die mit
Bp::kMult erzeugte Achse der Werktage im betrachteten Zeitbereich in Frage. Und in diesem 
Falle dürfte eine Zuordnung der Wochenkurse zum Mittwoch und der Monatskurse zu einem
Werktag in der Monatsmitte sinnvoller sein. Dann könnte ich z.B. auch bei der Darstellung
eines Indikators als Histogramm bei der üblichen Zuordung von Kurs und Histogramm Bin
mit dem Kurs in Binmitte bleiben.
- 31.10.18: Bin doch wieder ins Grübeln gekommen. So wie die Tageskerze erst am Ende des 
Tages verfügbar ist, so sind eben die Wochen/Monats Kerzen erst am Wochen/Monats Ende 
bekannt! Auch die Darstellung der indikatoren sollte geändert werden. Bisher habe ich
die Indikatoren meist als Histogramme mittels TH1D gezeichnet. Eine günstigere Wahl
dürfte aber TGraph sein. Hier gibt es zwei Vektoren xx=Index(Datum) und yy=Inhalt. Dabei
kann es zwischen den xx-Werten beliebig viele Lücken geben.
- 05.11.18: Bin bei Freitag und letztem Werktag geblieben für die Wochen-, bzw. 
Monatskurse. Für die Indikatoren gibt es RtPlot::DrawIkGra() und RtPlot::DrawIkHis() um
die Zeichnungen auf Basis von TGraph, bzw. TH1D zu machen. Histogramme werden symmetrisch
zu den dazugehörigen Kursen gezeichnet.
- 24.04.20: Zur Darstellung von Jahreskursen gibt es inzwischen 
BpQuoteMgr::QuotesYear(), wobei ich hierbei eigentlich mehr die Elliott-Wellen im
Blickpunkt habe. Gleichzeitig hatte ich versucht, die Darstellung der Daten dem 
Intervall zuzuordnen, in dem sie erzeugt werden. So werden z.B. Wochendaten am 
Mittwoch gezeichnet, und ein für diesen Datenpunkt berechneter Indikator als 
Histogramm von Montag bis Freitag. Das bringt aber jede Menge Schwierigkeiten mit 
sich, wenn dann auf dieser Grundlage, Handelsaktivitäten programmiert werden sollen.
Der Datenpunkt ist eben erst am Freitag nach Handelsschluss fertig berechnet und
damit auch der dazugehörige Indikatorwert. Analoges gilt für Monats- und Jahresdaten.
Also dürfte die Zuordnung der Daten zu dem jeweiligen Intervallende doch der 
bessere Weg sein, auch wenn die dazugehörige Darstellung nicht besonders "schön"
aussieht. Gleichzeitig gehe ich davon aus, dass der Handel auf Basis von
Tagesdaten stattfindet. Wenn also am Freitag ein Signal vorliegt, dann wird am
Montag gehandelt. Für alle Fälle können ja Intervallanfang, -mitte und -ende in dem
jeweiligen BpQuote-Objekt gespeichert werden (so wie ich das bisher nur für den
Intervallanfang für die Histogramm Darstellung gemacht habe).

<!-- \section BsTd30 Memory Leaks -->
## Memory Leaks
- 23.04.18: Es besteht nach wie vor das Problem, dass bei längeren Backtest-Rechnungen
der Speicherbedarf langsam anwächst, ohne dass der Visual Leak Detector ein Memory
Leak anzeigt. Ich bin da im Moment ziemlich ratlos. Bei allen eigenen Klassen zähle
ich inzwischen Erzeugung und Vernichtung, um so eventuelle Leaks zu finden. Inzwischen
gibt es ja auch im C++ smart pointer. Ich hatte schon einmal einen Versuch damit 
unternommen, war dann aber an rootcint gescheitert (siehe [Ursprüngliches ReadmeBp](BsTd99) 21.11.12).
rootcint wird aber in BpLib nicht mehr verwendet. Auch habe ich
immer wieder den Hinweis gelesen, die Objekte möglichst auf dem Stack (also ohne 
Pointer) zu erzeugen, statt auf dem Heap. Siehe z.B. 
[Why should I use a pointer rather than the object itself?]
(https://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself?rq=1)
Mal sehen, ob sich da noch etwas tun läßt.

<!-- \section BsTd90 Bemerkungen zum Gebrauch von Doxygen  -->
## Bemerkungen zum Gebrauch von Doxygen 
- 19.12.17: Die [Formatierungshinweise für die Root-Dokumentation] 
(https://root.cern.ch/how/formatting-comments-doxygen) sollten für die Dokumentation
vond BsTd angewendet werden. Dort steht am Ende im Zusammenhang mit der Einbeziehung
zusätzlicher Dokumentationsseiten:
"See as example the existing math/doc/Math.md file." Diese Datei gibt es als
E:\\Prog\\Root\\root_v6.10.08.source\\root-6.10.08\\math\\doc\\Math.md auf dem Rechner
Ac16.
- 21.12.17: Teile von Doxygen Kommentaren können "auskommentiert" werden, wie am Ende 
im Kapitel [HTML Commands](file:///C:/Program%20Files/doxygen/html/htmlcmds.html) 
des Doxygen Manuals angegeben ist:
\verbatim
Finally, to put invisible comments inside comment blocks, HTML style comments can be 
used:
/*! <!-- This is a comment with a comment block --> Visible text */
The part <!-- ... --> will not be shown in the main documentation.
\endverbatim
28.05.21: In diesem Zusammenhang vielleicht auch interessant: 
[How to Comment a Markdown File](https://www.jamestharpe.com/markdown-comments/).
\n 09.01.18: Da es in den Doxygen Kommentaren kein Zeilenfortsetzungszeichen gibt, kann
als Ausweg das Newline "auskommentiert werden": <!--
--> (siehe https://stackoverflow.com/questions/46744573/does-doxygen-have-a-line-continuation-feature)
- 26.12.17: Doxygen kann im Visual Studio als externes Tool gestartet werden, siehe
z.B. https://usingcpp.wordpress.com/2017/03/08/doxygen-and-visual-studio/. Die
zugehörigen Argumente sind so gewählt, dass das Doxygen-Konfigurationsfile im VS
geöffnet sein muss.
- 28.05.21: Die Dokumentation der Klasse Bm wurde bisher offenbar durch das Makro
DLLAPI mit den __declspec Definitionen (siehe Bm.h) gestört. Nach 
http://www.doxygen.jp/preprocessing.html kann das folgendermaßen behoben werden:
\verbatim
A typically example where some help from the preprocessor is needed is when dealing with Microsoft's __declspec language extension. Here is an example function.

extern "C" void __declspec(dllexport) ErrorMsg( String aMessage,...);

When nothing is done, doxygen will be confused and see __declspec as some sort of function. To help doxygen one typically uses the following preprocessor settings:

ENABLE_PREPROCESSING   = YES
MACRO_EXPANSION        = YES
EXPAND_ONLY_PREDEF     = YES
PREDEFINED             = __declspec(x)=

This will make sure the __declspec(dllexport) is removed before doxygen parses the source code.
\endverbatim
Und das funktioniert offenbar!
\n 

<!-- \section BsTd91 Bemerkungen zum Gebrauch von Git  -->
## Bemerkungen zum Gebrauch von Git 
- 28.12.17: Mit der [Microsoft-Dokumentation](https://docs.microsoft.com/en-us/vsts/git/) 
gelang es mir zwar ein lokales 
Repositorium herzustellen, aber ich habe es nicht geschafft, es auch noch mit Inhalt
zu füllen. Ebenso konnte ich ein [Remote-Repo](https://muellerh08.visualstudio.com/_git/BsTd) 
nur anlegen, aber nicht füllen. Das 
funktionierte dann aber alles recht einfach mit der Git Gui. Mir ist auch noch nicht 
klar, ob ich überhaupt ein Remote_Repo brauche, da ich ja ein 
[Individual Developer (Standalone)](file:///E:/Program%20Files/Git/mingw64/share/doc/git-doc/giteveryday.html) 
bin, wie in der [Git-Dokumentation](file:///E:/Program%20Files/Git/mingw64/share/doc/git-doc/index.html) 
beschrieben.
- 08.01.18: [Das Git-Buch](https://git-scm.com/) gibt es sogar in deutscher Übersetzung.
- 16.02.18: Vielleicht auch ganz nützlich: 
\n https://githowto.com/
\n https://stevebennett.me/2012/02/24/10-things-i-hate-about-git/ und weitere Links
am Ende des Artikels.
- 20.02.18: ProgrammVersion aus git in BsTd "bringen": Zunächst eine LinkSammlung:
\n http://xit0.org/2013/04/cmake-use-git-branch-and-commit-details-in-project/ und
weitere Links am Artikelende
\n https://stackoverflow.com/questions/6526451/how-to-include-git-commit-number-into-a-c-executable
\n https://stackoverflow.com/questions/17414104/git-checkout-latest-tag
\n https://julienrenaux.fr/2013/10/04/how-to-automatically-checkout-the-latest-tag-of-a-git-repository/
\n Obige Links benutzen cmake. Am einfachsten scheint es mir aber zu sein, in dem
PowerShell Script beim Programmstart die Variable $latesttag=$(git describe --tags) zu
belegen, und sie anschließend in der Kommandozeile z.B: mit -tag ${latesttag} in das
Hauptprogramm "einzuarbeiten", wie alle anderen Kommandozeilen Eingaben.
- 03.05.2018: Am einfachsten ist es, im Hauptprogramm 'RmM' in der zweiten Zeile
'Bp::SetGitTag("v0.10");' auf den aktuellen Wert zu setzen, bevor ein 'Commit' (und)
'Push' ausgeführt wird.
- Einige git Kommandos:
\n Zum Setzen von Tags siehe https://git-scm.com/book/en/v2/Git-Basics-Tagging. 
\n git tag v0.00 gibt "Lightweight Tag", git tag -a v0.00 gibt "Annotated Tag".
\n Vergleich der aktuellen Version mit einem früheren tag: 
\n          git difftool v0.12 -t winmerge
\n oder nur für eine Datei:
\n          git difftool v0.12 -y -t winmerge -- .\\Bp\\BpLib\\src\\BpPos.cxx
\n Log von origin: git log origin/master
\n Loose Objects: git gc oder bei Schwierigkeiten git gc --auto --prune=now oder 
git gc --aggressive --prune=now

<!-- \section BsTd92 Bemerkungen zum Netzwerk -->
## Bemerkungen zum Netzwerk
- 19.05.18: Problem: Ac16 und Wi12 sehen nur Ac16 im Netzwerk. Vielleicht hilft
[Netzwerknamen unter Windows 10 bearbeiten]
(https://blog.blackseals.net/2015/09/17/netzwerknamen-unter-windows-10-bearbeiten/).
Wenn man sich in der Registry unter dem in dem Link angegebenen Pfad \verbatim
'HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\NetworkList\Profiles'
\endverbatim die Einträge anschaut, dann gibt es auf Ac16 3 Einträge 
(Netzwerk, ~2, ~3) und auf Wi12 sogar 5 (Netzwerk, ~2, ~3, ~4 und WLAN). Unter 
'Einstellungen->Netzwerk und Internet->Ethernet' ist zu sehen, dass Ac16 mit 
Netzwerk 3, Wi12 aber mit Netzwerk 4 verbunden ist. Wie kann ich das ändern???
- 15.02.19: Was mich schon lange stört, ist die Tatsache, dass sich Ac16
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
angezeigt.

<!-- \section BsTdMk Bemerkungen zu Makros -->
## Bemerkungen zu Makros
- 08.08.20: Bei der Verwendung von Makros hat es immer mal wieder Schwierigkeiten
der verschiedensten Art gegeben. Deshalb habe ich die Möglichkeit eingebaut, die
Eingabedaten mittels Datenfiles (*.int) einzugeben, die dann im Programm 
entsprechend "geparst" werden. Makros haben natürlich ihre Vorteile, und so hatte
ich es in letzter Zeit wieder einmal versucht, was auch ganz gut funktionierte. 
Gestern gab es ein Windows Update auf Windows 10 Version 2004(Build 19041.388) und
ein Update von Visual StudioCommunity 2019 auf Version 16.7.0. Danach gab es beim
Kompilieren jede Menge Fehler, die offenbar durch die mittels rootcint erzeugten
"Dictionaries" G__{library} verursacht wurden. Nur durch den Verzicht auf das
Erzeugen der Dictionaries und dem Entfernen aller ClassDef pragmas konnte ich 
überhaupt erst wieder das Programm kompilieren. Damit ist aber die Verwendung von
Makros nicht mehr möglich. Leider weiß ich nicht, ob das Windows- oder das Visual 
Studio-Update die Ursache war. Jedenfalls werde ich mich wohl in Zukunft mehr um das
Parsen von Eingabedaten kümmern, als um das Erstellen von Makros.
\n Das Dictionary wird aber auch für da Funktionieren von Signal-Slot gebraucht.
Offenbar ist in der 16.7.0 Version von Visual Studio ein Bug, siehe
[How do I install a previous version of Visual Studio 2019 Community?]
(https://stackoverflow.com/questions/63304331/how-do-i-install-a-previous-version-of-visual-studio-2019-community).
Darauf hat es noch keine Antwort gegeben.

<!-- \section BsTd96 Ideen -->
## BsTd96 Ideen

<!-- \subsection BsTd96a C# Doku (=BsDc) als CMake-Projekt -->
### C# Doku (=BsDc) als CMake-Projekt
- 09.01.18: Wenn die C# Doku BsDc als CMake-Projekt aufgesetzt werden kann, dann
sollte es möglich sein, BsDc in die Solution BsTd einzubeziehen. Damit könnten dann
eventuell die Bibliotheken von BsTd direkt in BsDc genutzt werden???
\n Nach den 
[CMake 3.8 Release Notes](https://cmake.org/cmake/help/v3.8/release/3.8.html#c)
wird C# von CMake unterstützt. In diesem 
[Link](https://stackoverflow.com/questions/2074144/generate-c-sharp-project-using-cmake)
wird die Nutzung von CMake für ein C#/WPF Projekt unter Punkt 13 vorgestellt. Dort
gibt es einen weiteren Link zu einem 
[working example](https://github.com/bemehiser/cmake_csharp_wpf_example) zum
Herunterladen.
\n 10.01.18: [Hier](https://gitlab.kitware.com/cmake/cmake/issues/16960) kann ein ganz
kurzes [example.zip](https://gitlab.kitware.com/cmake/cmake/uploads/fd88360ee569e9e770d8d5b360a2e11a/example.zip) 
heruntergeladen werden, das C++ und C# Code enthält und eventuell als Ausgangspunkt für
ein eigenes Projekt genommen werden kann. 
\n [Hier](https://gitlab.kitware.com/cmake/cmake/issues/16697) gibt es auch 
ein ähnliches kurzes Beispiel 
[issue_16697.zip](https://gitlab.kitware.com/cmake/cmake/uploads/fd69952663aed9acd56584d0d7b03e45/issue_16697.zip)
mit einer etwas anderen Verzeichnisstruktur.
\n 12.01.18: Ich habe es versucht, bin aber erst mal gescheitert. Als Überrest dieses
Versuches gibt es noch ein Verzeichnis ...\\BdTd\\Src\\BsDc180111, das aber wegen eines
Eintrages in die Datei ...\\.git\\info\\exclude von git ignoriert wird. Das 
Einbeziehen von BsDc in BsTd mittels include_external_msproject(..BsDc/BsDc.csproj)
funktioniert zwar, ist aber wenig sinnvoll. Eigentlich wollte ich ja in BsDc die
Bibliotheken von BsTd verwenden. 
\n Es bleibt also erst einmal bei zwei getrennten Projekten BdTd und BsDc!
\n Doch noch ein Link: https://gitlab.kitware.com/cmake/cmake/issues/17388
\n 31.08.20: Inzwischen gibt es ein WPF C# Projekt BsDp, das als exe offenbar 
funktioniert, aber bei der Einbindung in BsTd als lib habe ich Schwierigkeiten mit
dem Programmstart. Deshalb die Idee, statt einem WPF- ein C++/CLR WinForms-Projekt 
zu machen. Dafür gibt es eine Vorlage in VS2017. Das Einbinden einer solchen
Vorlage in VS2019 nach [1 Windows Forms Projects with C++ in Visual Studio 2019]
(https://www.rkaiser.de/wp-content/uploads/2019/04/cpp-2019-WinForms-Anleitung-EN.pdf)
ist mir (bisher) nicht gelungen. 
\n Die heruntergeladene Vorlage muss nun noch in ein Cmake-Projekt umgewandelt 
werden. Für C# gibt es ein Beispiel [CMake C#/.NET WPF and WinForms Examples]
(https://github.com/bemehiser/cmake_csharp_example).

---
layout: single
title: Einleitung
permalink: /docs/bstd-ein
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

# Einleitung

Mit BsTd wird in erster Linie das Backtesting von Handelssystemen durchgeführt.
- 25.04.22: Möglichkeiten zur Strukturierung sind in den Artikeln
[Do section names have to be globally unique in Doxygen?](https://stackoverflow.com/questions/13698699/do-section-names-have-to-be-globally-unique-in-doxygen)
und [The Structure of Doxygen Documentation](https://alesnosek.com/blog/2015/06/21/the-structure-of-doxygen-documentation/)
diskutiert.
- 14.05.22: Viele Beispiele sind in [How To Use](http://www.gerald-fahrnholz.eu/sw/DocGenerated/HowToUse/html/index.html) zu finden.
- 23.06.22: Die Struktur des TreeViews wird im 'Navigation index tabs for HTML output' von
````...\Dox\LayoutBsTd.xml```` festgelegt.

## Log

### ab 2018

- 15.01.18: In dem Artikel 
[Creating a C++/CLI Wrapper](https://www.red-gate.com/simple-talk/dotnet/net-development/creating-ccli-wrapper/)
von September 2017 wird darauf hingewiesen, dass das Module 'C++/CLI support' aktiviert
sein muss. (Dazu wird der Visual Studio Installer benutzt.) Das war bis heute nicht 
der Fall, obwohl ja RmLib C++/CLI nutzt. Ich bin gespannt, ob sich was ändert!
- 17.01.18: Wiederbelebung von Testtools siehe [Einführung zu Testtools in Visual Studio](
https://docs.microsoft.com/de-de/visualstudio/test/improve-code-quality)
- 14.06.18: Auf Ac16\\SQL17 sind alle Datenbasen auf Collation=Latin1_General_CS_AS
umgestellt (Properties->Options->Collation: im Drop-Down Latin1_General_CS_AS 
auswählen) von vorher Latin1_General_CI_AS. Hier stehen CI für Case Insensitive und
CS für Case Sensitive. Das war notwendig geworden, weil ich in den 
Versionsbezeichnungen von Backtest Rechnungen zwischen Klein- und Großbuchstaben
unterscheiden möchte. Es sieht allerdings so aus, als würde diese Umstellung nur für
die neu angelegten Tabellen wirksam sein. Bei den alten wird z.B. eine Rechnung mit
v0 auch als v0 in der Versionsbezeichnung erscheinen. Erfolgt dann aber eine Rechnung
mit V0, dann wird diese Variante überschrieben mit den neuen Rechenergebnissen, es
bleibt aber die alte Versionsbezeichnug mit v0 erhalten. Das ist bis jetzt nur in der
Tabelle Sy.TdSF11 passiert. Dort waren zuerst die Rechnungen mit V da, die dann zum
Teil von Rechnungen mit v überschrieben wurden. Der sicherste Ausweg dürfte darin
bestehen, eine neue Datenbasis BT3 für zukünftige Backtest Rechnungen zu benutzen,
bei der von Anfang an Groß- und Kleinschreibung unterschieden wird.
\n Die nächste Frage wäre dann, ob die Tabellen aus BT1 in BT3 so kopiert werden 
können, dass sie dann Groß- und Kleinschreibung berücksichtigen, da ja so ein
Kopieren mit einem Neuanlegen der Tabelle verbunden ist. In dem Artikel
[How to copy tables from one database to another in SQL Server](https://www.sqlshack.com/how-to-copy-tables-from-one-database-to-another-in-sql-server/)
sind die verschiedenen Möglichkeiten erläutert.
\n 12.08.22: "Wiederbelebung" von RtN.exe als RtM.exe. Grund ist der Fakt, dass die Debug-Variante von RtM
nicht gestartet werden kann. Könnte die Debug Variante von RtM gestartet werden, dann würde das die Fehlersuche
in vielen Fällen erleichtern, und vielleicht könnten mit der Release Variante Rechenzeiten verkürzt werden?

### ab 2024

- 22.01.24: Nach längerer Pause (wegen SmartThings) Neustart mit root_v6.30.02.
- Aktuelle Konfiguration wird durch Umgebungsvariable z.B. ROOTSYS=C:/Prog/Root/root_v6.30.02/Release oder
.../Debug festgelegt.
- Mittels BmLib hatte ich begonnen auch managed Code in native C++ zu verwenden. Das soll rückgängig gemacht
werden, um mit BpLib, RtLib und RtM einen Bereich mit ausschließlich native Code zu haben, der eventuell auch
als Linux-Variante in WLS laufen könnte.
  - Details siehe [LogBmBp](../thems/bm-bp/#logbmbp)
- Bem. zu PowerShell siehe [Was ist Windows PowerShell?](
https://learn.microsoft.com/de-de/powershell/scripting/windows-powershell/overview?view=powershell-7.4):
Windows PowerShell und PowerShell sind zwei separate Produkte. -> PowerShell wird weiterentwickelt
- Bem. zu .NET siehe [Der Unterschied zwischen .NET Core und .NET Framework](
https://chudovo.de/difference-between-net-core-and-net-framework/) -> die Zukunft wird ganz auf .NET Core
ausgerichtet sein.
- Bem. zu Installation: Installation erfolgt in BSTDB=C:/Users/User/BsTdB/bin, .../lib. Stabile Verison wird nach
BSTD=C:/Users/User/MagentaCLOUD/BsTd/bin, .../lib kopiert. Längere Rechnungen nutzen BSTD, während die
Programmentwicklung auf BSTDB weitergehen kann.
- 24.02.14: BsTd von C:/Users/User/MagentaCLOUD/BsTd nach C:/Users/User/BsTd verschoben mit einer Menge 
Ungemach als Folge. Eigentliche Ursache war aber, dass ich in MagentaCLOUD C:/Users/User/BsTd als zu 
synchronidierendes Verzeichnis eingegeben hatte. Bei der (versehentlichen) Eingabe eines Pfades, der 
.../MagentaCLOUD/... enthielt, z.B. in Visual Studio begann ein Downloaden von alten Files. Diese Files waren zwar 
durch ein zusätzliches (1) im Namen gekennzeichnet. Das ganze führte aber trotzdem zu komischen Effekten, und 
das Entfernen dieser Files war sehr lästig. Irgendwann waren dann auch Files in .git betroffen und es ging gar 
nichts mehr.
- 26.01.24: Neues Repo (.git) angelegt, das mit Version v1.27 beginnt. > 2 Remote Repos angelegt:
 - https://muellerh08.visualstudio.com/BsTd1: Andere Bezeichnung, da ich es nicht geschafft habe, das alte
https://muellerh08.visualstudio.com/BsTd umzubenennen.
 - https://github.com/muellerh08/BsTd: Neu auf GitHub.
- Bem.: Die remote Repos mussten jeweils erst angelegt werden, bevor in GitGui "gepusht" werden konnte, wobei 
der Befehl dafür auf diesen Seiten vorgesehen ist.
- 27.01.24: Ein weiteres Repo auf Externer Platte ````HDDRIVE2GO J:\Repos```` angelegt nach 
[4.2 Git on the Server - Getting Git on a Server](
https://git-scm.com/book/en/v2/Git-on-the-Server-Getting-Git-on-a-Server):
````
PS C:\Users\User\BsTd> git clone --bare Src J:\Repos\BsTd.git
Cloning into bare repository 'J:\Repos\BsTd.git'...
done.
````
und pushing in GitGui liefert:
````
Pushing to J:\Repos\BsTd.git
To J:\Repos\BsTd.git
 = [up to date]      master -> master
Everything up-to-date
````
- 29.01.24: ````J:\Repos\BsTd.git```` gelöscht, statt dessen Clonen nach ````J:\Repos\BsTdDr````
````
PS J:\Repos\BsTdDr> git init
Initialized empty Git repository in J:/Repos/BsTdDr/.git/

PS C:\Users\User\BsTd\Src> git clone . J:\Repos\BsTdDr
Cloning into 'J:\Repos\BsTdDr'...
done.
Updating files: 100% (619/619), done.
PS C:\Users\User\BsTd\Src> git remote -v
origin  https://muellerh08.visualstudio.com/DefaultCollection/_git/BsTd (fetch)
origin  https://muellerh08.visualstudio.com/DefaultCollection/_git/BsTd (push)

PS J:\Repos\BsTdDr> git remote -v
origin  C:/Users/User/BsTd/Src/. (fetch)
origin  C:/Users/User/BsTd/Src/. (push)
````
- 20.02.24: Bem. zu Root: 
 - Das [root-project](https://github.com/root-project) besteht z.Z. aus 36 Repros.
 - Die [ROOT Web Site](https://github.com/root-project/web?tab=readme-ov-file#root-web-site) ist im Web
 der Startpunkt. Vielleicht könnte das ein Vorbild sein für eine BsTd-Docu, nach dem sich meine bisherigen
 Versuche BsDc und Wpf doch als recht umständlich und unbefriedigend erwiesen haben. Allerdings basiert
 die Seite auf [Jekyll](https://jekyllrb.com/), wäre also vollkommen neu für mich.
 - Für das (Reference Guide](https://root.cern/doc/master/) wird Doxygen verwendet, und ich sollte versuchen, die Hinweise in 
 [Formatting Comments for Doxygen](https://root.cern/for_developers/doxygen/) zu beachten.

<!-- \section BsTdRE Möglicher "Root-Ersatz" -->
## Möglicher "Root-Ersatz"

30.03.22: Wieder einmal unendlich Zeit verbracht, um einen Assertionsfehler in Zusammenhang
mit Root6.24.06 zu finden. Der konnte beseitigt werden durch das Einfügen von ROOT::Cling in BnLib.cmake.
Beim Compilieren gab es keinen Fehler! Wenn das wirklich die Ursache war, dann ist der Zusammenhang für mich
nicht ersichtlich. Bei Verwendung von Root6.26.00 gab es wieder einen (anderen) Assertionsfehler sowhl in
der Debug- als auch in der Release-Variante. 
\n Als möglicher Ersatz bietet sich (wieder einmal) Qt an. Es gibt aber auch C#-Varianten. Einen ganz guten
Überblick gibt es in 
[C# Data Visualization, Resources for visualizing data using C# and the .NET platform](https://swharden.com/csdv/).

<!-- \subsection BsTdQt Qt+Qwt -->
### Qt+Qwt
- 11.03.21: Mit Root gibt es immer wieder irgendwelche Schwierigkeiten. Ich hatte ja
schon einmal Qt benutzt, habe es dann aber zugunsten von Root aufgegeben. 
Vielleicht sollte ich doch versuchen Root durch Qt zu ersetzen. Der aktuelle Stand
(ohne Qt) wird als git-Version v0.47 "aufgehoben". Es gibt noch eine Programmversion
aus dem Jahre 2012, in der Root und Qt4 benutzt wurden. Vielleicht kann ich davon
einiges mit dem aktuellen Qt6 verwenden.
- 12.03.21: Die Verwendung der neuesten Version 6.0.2 scheitert daran, dass Cmake das
(nach mühsamer Suche) gefundene Qt6Config.cmake nicht verarbeiten wollte (irgendwas 
mit der Version). Mit der Version 5.15.2 gab es diese Schwierigkeit nicht. Allein
das Einbinden dieser Version in BpLib.cmake führt aber dazu, das nur noch die
Release-Varianten der erzeugten exe's funktionieren. Für die Debug-Varianten muss
offenbar mehr getan werden, siehe [Setting Up Debugger]
(https://doc.qt.io/qtcreator/creator-debugger-engines.html#:~:text=The%20Qt%20binary%20distribution%20contains%20both%20debug%20and,as%20debug%2C%20as%20release%20is%20the%20default%20library.).
Bleibt eigentlich nur die Möglichkeit, ausschließlich mit der Release-Version zu
arbeiten.
- 14.03.21: Ich hatte allerdings nicht Qt selbst benutzt, sondern ein Programm qwt, 
das Qt benutzt. Aber hier scheitere ich gleich bei der Installation.
\n Eventuell hilfreiche Links:
\n https://ghorwin.github.io/qwtbook/building/
\n [Qt Creator mit Qt, Qwt & MinGW]
(http://stefan-franke.net/diesunddas/qt-creator-mit-qt-qwt-mingw)
\n [QWT Installation trouble]
(https://stackoverflow.com/questions/57020082/qwt-installation-trouble)
\n [GitHub - timvdm/qwt: CMake build files for qwt (Qt graph ...]
(https://github.com/timvdm/qwt)
\n [How to include a certain Qt installation using CMake?]
(https://stackoverflow.com/questions/12511370/how-to-include-a-certain-qt-installation-using-cmake)
\n [Make graphs in C++ with Qwt and Visual Studio]
(https://vivienmetayer.com/en/make-graphs-in-c-with-qwt-and-visual-studio/).
Von hier habe ich einen "fertigen Build", siehe 
...\\Downloads\Qt\Qwt-6.1.5_MSVC2019_Qt5.15.zip, heruntergeladen. Mal sehen, ob das
auch mit der Benutzung klappt. Die "Herstellungsschritte" mit QtDesigner, die ich 
mir ja jetzt erst mal sparen kann, sind auch recht gut erläutert.
- 31.03.22: Bin mit dem Versuch gescheitert, Qt-6.2.4 und Qwt-6.2.0 zu installieren.
Für Qt gibt es ein Qt Maintenance Tool. Beim Versuch, das qthelp://org.qt-project.qtwidgets.624/qtdoc/index.html
Example zu compilieren, scheitert das an: mainwindow.cpp
C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Tools\\MSVC\\14.29.30133\\include\\cstddef(12): 
fatal error C1083: Cannot open include file: 'stddef.h': No such file or directory
	cl -BxC:\\Prog\\Qt\\Qt6.2\\6.2.4\\msvc2019_64\\bin\\qmake.exe -nologo -Zc:wchar_t -FS -Zc:rvalueCast -Zc:inline -Zc:strictStrings - 
 \n Dieses fehlende include file: 'stddef.h' verhindert auch die Installation von Qwt-6.2.0 nach
 [Make graphs in C++ with Qwt and Visual Studio]
(https://vivienmetayer.com/en/make-graphs-in-c-with-qwt-and-visual-studio/),
bzw. den Installationsanweisungen aus [Installing Qwt](https://qwt.sourceforge.io/qwtinstall.html).
\n Siehe auch die nmake.txt Files in 
D:\\Prog\\Qwt\\Qwt-6.2.0\\Qwt-6.2.0_Build\\build-qwt-Desktop_Qt_6_2_4_MSVC2019_64bit-Debug und
D:\\Prog\\Qwt\\Qwt-6.2.0\\Qwt-6.2.0_Build\\build-qwt-Desktop_Qt_6_2_4_MSVC2019_64bit-Release und
ReadmeHm.txt in D:\\HmD\\Downloads\\Qwt\\Qwt-6.2.0.
\n Für die (bisher verwendete) Version 5.15.2 gab es bei der Insatallation noch die Auswahl zwischen 'MSVC 2019 32-bit'
und 'MSVC 2019 64-bit', für Qt-6.2.4 gibt es nur noch die 64-bit Variante.  -->

<!-- \subsection BsTdSk SkiaSharp -->
### SkiaSharp

- 14.03.21: Mit Root gibt es immer wieder irgendwelche Schwierigkeiten. Auf der 
Suche nach Ersatz bin ich auf [A simple C# library for graph plotting](https://www.codeproject.com/Articles/32836/A-simple-C-library-for-graph-plotting)
gestoßen mit vernünftigen Beispielen. Als ich mir dann die benutzten Klassen
anschauen wollte, [System.Drawing.Drawing2D Namespace](https://docs.microsoft.com/en-us/dotnet/api/system.drawing.drawing2d?view=net-5.0),
gab es den Hinweis: The System.Drawing namespace is not recommended for new development, 
because .... Recommended alternatives include ImageSharp, SkiaSharp, and 
Windows Imaging Components.
- SkiaSharp gibt es als [Codeproject] (https://github.com/mono/SkiaSharp) und als
[SkiaSharp Namespace](https://docs.microsoft.com/en-us/dotnet/api/skiasharp?view=skiasharp-2.80.2).
Die Benutzung einer C# Variante würde einen Umbau der gesamten Programmstruktur
bedeuten.


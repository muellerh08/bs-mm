---
layout: single
title: Root
permalink: thems/root
sidebar:
  nav: thems
toc: true 
---
14.01.24: Diese Seite neu angelegt für alles, was Root betrifft.

<!-- {: .no_toc }
<details open markdown="block">
  <summary>
    Table of contents
  </summary>
  {: .text-delta }
- TOC
{:toc}
</details>  -->

## Einleitung

14.01.23: Root für Windows ist nach wie vor nur beta. Mit WSL verfügbar könnte man über ein Ubuntu Projekt
nachdenken. Dazu wäre aber eine Trennung von reinem C++-Code und C++/Cli, bzw. C# notwendig. Das löuft auf 
eine "Abschaffung" von 'Bm: Wrapper .NET-Klassen' hinaus. Zunächst aber alles wie bisher, nur Update auf
root_v6.30.02.

## Installation 2024

14.01.24: Nach längerer Pause Update von Root
- Download root_v6.30.02.win64.vc17.exe, root_v6.30.02.win64.vc17.debug.exe und root_v6.30.02.source.tar.gz
von https://root.cern/releases/release-63002/ nach ````C:\Prog\Root\root_v6.30.02```` (dauert ewig!!!).
- 15.01.23: Bisher gab es immer nur die win32 Varianten. Da ich nicht weiß, ob alle zusätzlich genutzten 
Bibliotheken (wie z.B. TaLib) auch sofort mit einer win64 Version funktionieren, werde ich wohl doch erst mal mit 
der win32-Variante anfangen. Also Download von root_v6.30.02.win32.vc17.exe und 
root_v6.30.02.win32.vc17.debug.exe.
- Ordner Debug und Release manuell anlegen und beim Installieren entsprechend als Zielordner auswählen.
- Umgebungsvariable auf ````ROOTSYS=C:\Prog\Root\root_v6.30.02```` geändert
- cmake-gui < Configure < Generate
- Build < Rebuild Solution -> endet mit 27 Errors und 21 Warnings
- 16.01.24: Wegen der vielen Fehler werden die Projekte einzeln kompiliert.
- BmLib: keine Probleme
- BpLib: 
1 unresolved externals: ````BtHxD.obj : error LNK2001: unresolved external symbol "public: virtual void __thiscall 
TH2::SetShowProjectionXY(int,int)" (?SetShowProjectionXY@TH2@@UAEXHH@Z)````
 - Es gibt aber keinen Aufruf von TH2::SetShowProjectionXY im ganzen Programm. 
 - Includiert wird "BtHxD.h" nur in BpIk.cxx und RtPlot.cxx
 - "BtHxD.h" enthält 2 Klassen Bt::H1D und Bt::H2D > Der Fehler dürfte zusammenhängen mit Bt::H2D, das  in 
 den Klassen Bp::IkElAc und Bp::IkAuKo verwendet wird.
 - Nach dem Auskommentieren diese Klassen wird BpLib.dll erzeugt.
 - Wegen "The C++ standard in this build does not match ROOT configuration (201703L); this might cause 
 unexpected issues. And please make sure you are using the -Zc:__cplusplus compilation flag" siehe
 https://geant4-forum.web.cern.ch/t/windows-non-matching-standards-error-building-a-project-with-root-dependencies/9898
 und https://root-forum.cern.ch/t/question-about-compiling-root-with-c-17/51597
 - 17.01.23: [Integrating ROOT into CMake projects](
 https://root.cern/manual/integrate_root_into_my_cmake_project/): siehe Note > in Eingabeaufforderung
 ````
 C:\Users\User>root-config --cflags
 -nologo -Zc:__cplusplus -std:c++17 -MD -GR -EHsc- -W3 -D_WIN32 -O2 -IC:\Prog\Root\root_v6.30.02\Debug\include
````

## Installation bis 2023

05.12.18: Bisher habe ich root_v5.34.34 benutzt, weil es nach der Umstellung auf Root6
lange keine Windows Version gegeben hatte. Ein erster Versuch mit root_v6.14.04 vor
einiger Zeit ist noch gescheitert mit einem Fehler, der sehr kompliziert aussah und den
ich mir nicht genauer angeschaut habe. Mit root_v6.14.06 scheitert die Compilation mit
35 Errors. Einige Files werden nicht gefunden. Das ist sicherlich nicht weiter 
problematisch. Wenig anfangen kann ich im Moment mit solchen Sachen wie

````text
Error	C1001	An internal error has occurred in the compiler.
BpLib	e:\prog\root_v6.14.06\release\include\root\typetraits.hxx	43	
Erstmalig tritt der Fehler beim Übersetzen von BpIk auf:
2>BpIk.cxx
2>e:\prog\root_v6.14.06\release\include\root\libcpp_string_view.h(193): warning C4068: unknown pragma
2>e:\prog\root_v6.14.06\release\include\root\typetraits.hxx(43): fatal error C1001: An internal error has occurred in the compiler.
2>(compiler file 'd:\agent\_work\3\s\src\vctools\compiler\cxxfe\sl\p1\c\convert.cpp', line 677)
2> To work around this problem, try simplifying or changing the program near the locations listed above.
2>Please choose the Technical Support command on the Visual C++
2> Help menu, or open the Technical Support help file for more information
2>e:\prog\root_v6.14.06\release\include\root\typetraits.hxx(46): note: see reference to class template instantiation 'ROOT::Detail::CallableTraitsImpl<T,true>' being compiled
2>BpIkEw.cxx
2>e:\prog\root_v6.14.06\release\include\root\libcpp_string_view.h(193): warning C4068: unknown pragma
2>e:\prog\root_v6.14.06\release\include\root\typetraits.hxx(43): fatal error C1001: An internal error has occurred in the compiler.
2>(compiler file 'd:\agent\_work\3\s\src\vctools\compiler\cxxfe\sl\p1\c\convert.cpp', line 677)
2> To work around this problem, try simplifying or changing the program near the locations listed above.
2>Please choose the Technical Support command on the Visual C++
2> Help menu, or open the Technical Support help file for more information
2>e:\prog\root_v6.14.06\release\include\root\typetraits.hxx(46): note: see reference to class template instantiation 'ROOT::Detail::CallableTraitsImpl<T,true>' being compiled
````

Der Programmteil von typetraits.hxx(43) sieht wie folgt aus, wobei 

````text
Zeile 43=using arg_types = ...:

// Extract signature of operator() and delegate to the appropriate CallableTraitsImpl overloads
template <typename T>
struct CallableTraitsImpl<T, true> {
   using arg_types = typename CallableTraitsImpl<decltype(&T::operator())>::arg_types;
   using arg_types_nodecay = typename CallableTraitsImpl<decltype(&T::operator())>::arg_types_nodecay;
   using ret_type = typename CallableTraitsImpl<decltype(&T::operator())>::ret_type;
};
````

31.12.18: Im Laufe von 2018 habe ich angefangen, smart pointer zu benutzen. Irgendwie
habe ich vermutet, dass die Fehler bei Verwendung von Root6 damit zusammenhängen könnten
(und habe das sogar schon an einigen Stellen, z.B. Indikatoren, wieder rückgängig 
gemacht). Bei einer Suche nach der Verwendung von 
````#include <memory>````, wo die smart pointer
definiert werden, habe ich gesehen, dass auch  
[HowardHinnant's date library](https://howardhinnant.github.io/date/date.html)
ebenso wie Root5 dieses Include verwenden. Damit steht für mich erst einmal fest, dass die
"Nichtverwendung" von smarten Pointern kaum der richtige Weg sein dürfte, um das 
Programm mit Root6 zum Laufen zu bringen.

26.01.19: root_v6.16.00 installiert. Es gibt *.exe's für Release und Debug. Das
Installationsverzeichnis kann gewählt werden. Bei Angabe von E:\\Prog wird in
E:\\Prog\\root_v6.16.00 installiert. Um auf Release und Debug zugreifen zu können, werden
in diesem Verzeichnis die Unterverzeichnisse Release und Debug angelegt und alles 
entsprechend verschoben. Dann muss nur noch die Umgebungsvariable ROOTSYS geändert werden.

Beim Compilieren kommen die gleichen Fehler wie bei den früheren Versuchen: 

````text
2>BpIk.cxx
2>e:\prog\root_v6.16.00\release\include\root\libcpp_string_view.h(193): warning C4068: unknown pragma
2>e:\prog\root_v6.16.00\release\include\ROOT/TypeTraits.hxx(43): fatal error C1001: An internal error has occurred in the compiler.
\endverbatim 
aber immer in Kombination mit 'warning C4068: unknown pragma'. Und dieses Pragma ist 
offenbar: \verbatim
#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif
````

GCC auf Zeile 193. Vielleicht sollte ich das erst mal klären.

Das Pragma scheint nichts mit dem Fehler zu tun zu haben. 
[Hier](https://root-forum.cern.ch/t/internal-compiler-error-when-compiling-program-which-uses-root6-in-visual-studio/30830)
wird der gleiche Fehler beschrieben, der aber mit Visual Studio zusammenhängt, wie aus
diesem 
[bug report](https://developercommunity.visualstudio.com/content/problem/335088/fatal-error-c1001-an-internal-error-has-occurred-i-24.html)
hervorgeht:  Fixed In: Visual Studio 2019 Version 16.0 Preview 2
\n Nach dem Installieren dieser Version bleibt das Projekt zunächst ein "VS 2017 Projekt" und es 
ändert sich nichts. Ein Neubeginn von Cmake ausgehend scheitert zunächst daran, das Cmake VS2019 
offenbar noch nicht unterstützt. Eine Diskussion dieses Problems findet sich 
[hier](https://developercommunity.visualstudio.com/content/problem/399774/visual-studio-2019-preview-1-running-cmake-on-comm.html)

Pfad zum Compiler in VS19: E:/Program Files/Microsoft VisualStudio/MSBuild/Current/Bin/MSBuild.exe
Aber auch mit Eingabe dieses Pfades in CMake3.13.3 wird ein VS2017 Projekt erstellt und es
treten nach wie vor alle Fehler auf.

Das folgende Include wird mit Root6 nicht mehr gefunden, vielleicht sollte (vorbeugend) schon
mal nach einer Lösung gesucht werden.

Error C1083 Datei (Include) kann nicht geöffnet werden: "Math/GSLSimAnnealing.h": 
No such file or directory BpLib	e:\\prog\\magentacloud\\bstd\\src\\bp\\bplib\\inc\\GSLSimAnMinimizer.h	49	

Ich gebe es (vorläufig) auf und mach mit VS2019 und Root5 weiter.

- 14.03.19: Neuer Versuch mit Visual Studio 2019 Preview 4.2 und root_v16.16.00.

Offenbar ist in Root einiges "abgeschafft" worden, das ich bisher verwendet habe.

In BpIkMa.cxx wird include <Math/Derivator.h> nicht mehr gefunden. Deswegen habe
ich die Klassen BpIkMaSi, BpIkMoD auskommentiert.

````text
C:\Users\User\MagentaCLOUD\BsTd\Src\Bp\BpLib\inc\GSLSimAnMinimizer.h(49)
: fatal error C1083: Cannot open include file: 'Math/GSLSimAnnealing.h' 
````

Deshalb in BpSy::Minimize() die Version fSyVsn == '0' und '1' auskommentiert.

BpSyTreeIfo, BpSy::PrmDep0() auskommentiert

Mit VS2017 und Root5 funktioniert wieder alles.

VS2019/Root6: BpSy::SetAnParams() auskommentiert

- 18.03.19: Ich benutze inzwischen VS Community RC2, Version 16.0.0 RC.2, und das
Programm funktioniert wieder mit vielen Warnungen beim Kompilieren. Beim Start gibt
es eine Reihe von Fehlerausschriften, die offenbar, [siehe hier](https://root-forum.cern.ch/t/root-6-14-4-startup-problem/31464/3), mit der 
Verwendung verschiedener VS-Versionen zusammenhängen, und "We'll try to get rid of this 
versioning problem in the future".
- 21.03.19: Mit VS Community 2019 RC, Version 16.0.0 RC.3 und einigen Änderungen gibt
es wieder einen eigenartigen Fehler: syntax error: 'constant' in TVirtualX.h. Auch
mit RC.2, das noch auf Ac16 installiert war und der letzten funktionierenden 
Version BsTd_v0.26 kommt jetzt dieser Fehler. Da werde ich wohl doch wieder auf Root5
zurückgreifen müssen. Leider ist auch mein erster Versuch, root_v6.16.00 zu 
kompilieren, zunächst erst mal gescheitert.

Nach Rück-Umstellung auf Root5 gibt es nach wie vor den Fehler in TVirtualX.h.
Dann muss es wohl an den Änderungen in BsTd liegen!!!

28.03.19: Ausgehend von der letzten funktionierenden Variante v0.26 geht jetzt 
alles wieder. Die Ursache für den Fehler in TVirtualX.h ist nach wie vor unklar.

25.07.21: Mit Root6 kann ich zwar arbeiten, kann aber kein Dictionary herstellen.
Es sieht so aus, als hätte das was mit der Python-Installation zu tun. Ich steig 
aber nicht dahinter. Eventuell genauer ansehen 
[Get started using Python on Windows for beginners](https://docs.microsoft.com/en-us/windows/python/beginners).

10.07.22: Seit April 2022 gibt es die erste Version, 6.26.02, mit der ich wieder ein Dictionary herstellen kann. Ich
habe die 64 Bit Version für Visual Studion 2022 verwendet, die es allerdings nur als Release gibt. Für VS 2019 gibt es
32 Bit Variante für Release und Debug. Hab ich aber nicht verwendet.

10.07.22: Umstieg auf die neue Variante 6.26.04.

## Signal/Slot

- 14.04.19: [How to send signals to GUI](https://root-forum.cern.ch/t/how-to-send-signals-to-gui/344)
Ich wollte irgendwie erreichen, dass ein TComboBox-Objekt als Sender einen 
this-Pointer an den Empfänger übergibt. Nach obigem Link ist das im Prinzip möglich,
aber offenbar nur in einer Klasse, in der das vorgesehen ist. Es sieht so aus, als 
müsste ich das in einer Unterklasse von TComboBox programmieren.
 
<!-- \section BsTdVs Visual Studio -->
## Visual Studio

- 07.02.19: Export der Settings auf Ac16:

```` "Your settings were successfully exported to 
C:\Users\muell\AppData\Local\Microsoft\VisualStudio\16.0_95aa5a98\Settings\
Exported-2019-02-07.vssettings." 
````

- 27.03.19: Mit VS 2019 funktionierte zunächst Intellisense und Call Hierarchy nicht.
Die Lösung bestand im Löschen von ...\\BSTDB\.vs und Neustart von VS, 
[siehe Antwort von Minding](https://stackoverflow.com/questions/51254108/visual-studio-2017-intellisense-is-not-working)

<!-- \subsection BsTdRt5 Root5 und Visual Studio -->
### Root5 und Visual Studio
- 10.03.21: Beginnend mit VS 2019 Version 16.9.0 treten plötzlich wieder sehr viele 
neue Fehler auf in der Art

````text
4>G__BpLib.cxx
4>C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\include\utility(604,1): error C2440: '=': cannot convert from '_Other' to '_Ty'
4>        with
4>        [
4>            _Other=int
4>        ]
4>        and
4>        [
4>            _Ty=std::_Facet_base *
4>        ]
4>C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\include\utility(604,42): message : Conversion from integral type to pointer type requires reinterpret_cast, C-style cast or function-style cast
4>C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29910\include\memory(3423): message : see reference to function template instantiation '_Ty *std::exchange<_Ty2,int>(_Ty &,_Other &&) noexcept(false)' being compiled
4>        with
4>        [
4>            _Ty=std::_Facet_base *,
4>            _Ty2=std::_Facet_base *,
4>            _Other=int
4>        ]
````

Da ja G__BpLib.cxx von Root erzeugt wird, kann ich da sowieso kaum was machen.
Ähnliche Fehler treten aber auch an vielen anderen Stellen auf. Die Dokumentation zu
[Compiler Error C2440](https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2440?view=msvc-160)
listete viele Möglichkeiten auf. Am wahrscheinlichsten scheint mir geht es um das
=0 Setzen eines Pointers zu einem Objekt ohne Cast.

Im Moment sehe ich keinen anderen Ausweg, als mit VS 2017 zu arbeiten.

15.03.21: In [C2440 error appears after update MVS 2017 to Version 15.9.11](https://social.msdn.microsoft.com/Forums/en-US/f8e2f0cb-316b-42cc-9b1c-e46e03a7efd5/c2440-error-appears-after-update-mvs-2017-to-version-15911)
wird das Setzen der Compiler-Option /Zc:strictStrings- diskutiert => Ausprobieren!

16.03.21: Es könnte an der falschen Verwendung von 
string join(const string& sep=" ",int from=-1,int to=-1); aus der Klasse BpStrVc
liegen.

17.03.21: BpStr::join() ist tatsächlich die Ursache gewesen für Fehler in 
RmLib::TblB und RmLib::Scan. Nachdem ich auch aus BpLib einige Klassen entfernt habe
(alle TODBC..., BpIkEw, RtEw,...) blieb in der Release-Variante nur noch 
G__BpLib.cxx, das nur mit RtMf immerhin aus über 1000 Zeilen besteht. Da habe ich 
keine Chance, die Fehler zu finden. Außerdem treten in der Debug-Variante jede Menge
weitere Fehler auf.

03.04.21: Vielleicht könnte ich ja statt des Signal/Slot Mechanismus mit Callback
Funktions arbeiten, da ich es ja mit recht einfachen Beziehungen zu tun haben 
dürfte. Dann könnte ich auf die Dictionaries G__XXX.cxx verzichten. Dazu muesste 
ich mich aber erst mal damit beschäftigen: [Callback Functions Tutorial](https://www.codeguru.com/cpp/cpp/cpp_mfc/callbacks/article.php/c10557/Callback-Functions-Tutorial.htm).

<!-- \subsection BsTdRt6 Root6 und Visual Studio -->
### Root6 und Visual Studio

- 03.06.21: root_v6.24.00 enthält nicht mehr den Vermerk 'preview'. Trotzdem
gelingt es mir nicht, ein Dictionary zu erzeugen. Es gibt aber den Hinweis, dass
exakt die gleiche VS-Version benutzt werden soll, wie für die Erzeugung der
Installations-Exe verwendet. Also wahrscheinlich nicht nur VS 2019, sondern auch
noch die Version (16.10.0 bei mir aktuell). Da ich keine früheren Versionen 
installieren kann (geht offenbar nicht für Community), kann ich diese Forderung 
nicht erfüllen. Aber auch eine Installation vom Source Code ausgehen erzeugt nur
ca. 2/3 der vorhandenen Projekte. Die restlichen scheitern offenbar auch an der
Erzeugung der entsprechenden Dictionaries (siehe 
C:\\Users\\User\\ROOTB\\Output-Build.txt für das Protokoll). 
- Der Signal/Slot Mechanismus basiert in Root auf den Dictionaries. Ich hatte in
TQObject.h/cxx und TqConnection.h/cxx Ausdrucke eingebaut, um zu versuchen, 
Signal/Slot auch ohne Dictionary zu installieren. Endgültig gescheitert bin ich
in TQSlot::TQSlot(const char *class_name, const char *funcname) mit
'Error in <TClingCallFunc::SetFuncProto>: Class info is invalid!'. 
- Als Ersatz sollte es möglich sein, eine der vielen Signal/Slot-Bibliotheken zu
benutzen. Eine Auswahl kann man z.B. in [Testing C++ signal-slot libraries](https://julienjorge.medium.com/testing-c-signal-slot-libraries-1994eb120826) finden.
Am einfachsten wäre vielleicht die Verwendung von Boost: 
[Chapter 36. Boost.Signals2](https://www.boost.org/doc/libs/1_76_0/doc/html/signals2.html). Das Problem ist nur,
dass die Signale neu definiert werden müssen. Das sollte möglich sein, da die 
Root-Signale virtual sind. Es müssten also Ableitungen von allen Klassen gemacht
werden, deren Signale verwendet werden sollen. Andererseits scheint es die
Möglichkeit zu geben, das alles außerhalb zu machen: [Connection Management](https://www.boost.org/doc/libs/1_76_0/doc/html/signals2/tutorial.html#id-1.3.37.4.6).
Das sieht aber (als Einstieg) recht kompliziert aus. Hilfreich vielleicht auch
[The Boost C++ Libraries](https://theboostcpplibraries.com/), insbesondere
[Chapter 67. Boost.Signals2](https://theboostcpplibraries.com/boost.signals2).
- [Complete example using Boost::Signals for C++ Eventing](https://stackoverflow.com/questions/768351/complete-example-using-boostsignals-for-c-eventing).
- Mit Qt geht es offenbar. Die betroffenen Klassen müssen abgeleitet werden mit
public QObject und die verwendeten Signale und Slots neu definiert werden.
- 10.06.21: Es geht auch, indem die Connect()-Aufrufe durch direkte Aufrufe der 
Slots in den Signal-Methoden entsprechend abgeleiteter Klassen ersetzt. Das ist
auch praktikabel bei der überschaubaren Menge an Verbindungen.
- 15.06.21: Die Ursache für den ganzen Ärger scheint an Python zu liegen. Das wird
offenbar benötigt. In cmake-gui kommt beim Konfigurieren von 
C:/Prog/root_v6.24.00/root-6.24.00.source die Ausschrift:

````text
Looking for Python
Could NOT find Python3 (missing: Python3_NumPy_INCLUDE_DIRS NumPy) (found version "3.9.5")
Could NOT find Python2 (missing: Python2_EXECUTABLE Python2_LIBRARIES Python2_INCLUDE_DIRS Python2_NumPy_INCLUDE_DIRS Interpreter Development NumPy Development.Module Development.Embed) 
    Reason given by package: 
        Interpreter: Wrong major version for the interpreter "C:/Prog/Python3/python.exe"
````

- 16.06.21: Wenn man mit dem NuGet Manager mit Find-Package Python sucht, dann 
werden recht viele Packete angezeigt. Wenn man mit NuGet herunterlädt, dann wird das 
Paket direkt in das Projekt eingebunden. Um das via cmake zu machen gibt es
[VS_PACKAGE_REFERENCES](https://cmake.org/cmake/help/latest/prop_tgt/VS_PACKAGE_REFERENCES.html).
Bezogen auf die Installation von Root6 müsste ich also die betroffenen Targets 
finden und die CMakeList.txt Files ändern. Das ist also auch kein gangbarer Weg!

26.07.21: Ich kämpfe weiter mit der Installation von Python. Es fehlt das 
NumPy Paket: [How to Install NumPy](https://phoenixnap.com/kb/install-numpy).
Ergebnis: Successfully installed numpy-1.21.1. Zu finden ist das in ...\\Lib\\site-packages.

<!-- \subsubsection BsTdRt6_26_02 Root6_26_02 -->
## Root6_26_02

10.05.22: In dieser Root-Version gibt es erstmalig eine 64-Bit Version für VS2022, aber nur als Release-
(und nicht auch als Debug-) Version. Da ich in den Cmake-Files die Variable $(Configuration) benutze, habe
ich das Verzeichnis Debug durch einen Link ersetzt (mklink /D Debug Release), damit z.B. auch das beim 
Compilieren benötigte Programm bindexplib.exe gefunden wird. Siehe z.B. 
[The Complete Guide to Creating Symbolic Links (aka Symlinks) on Windows](https://www.howtogeek.com/howto/16226/complete-guide-to-symbolic-links-symlinks-on-windows-or-linux/).
\n Beim Compilieren gibt es Schwierigkeiten mit Qt, da die 32-Bit Variante installiert ist. Um (zunächst) eine
Neuinstallation zu vermeiden, wird TqLib erst mal nicht mehr benutzt.

Auch die Umstellung von [TA-Lib : Technical Analysis Library](https://ta-lib.org/d_api/d_api.html) war recht
aufwendig. Nach der Vorlage von [TA-lib built with CMake - GitHub](https://github.com/timkpaine/ta-lib)
wurde eine Library in C:/Prog/Talib "vor Ort" mit VS2022 hergestellt.

12.08.22: Dass die Debug Variante nicht gestartet werden konnte (Anwendungsfehler), hatte ich damals auf die 
fehlende Debug-Variante von Root geschoben. Aber! siehe folgendes Kapitel.

<!-- \subsubsection BsTdRt6_26_06 Root6_26_06 -->
## Root6_26_06

12.08.22: Das ist die erste Version für Visual Studio 2022 mit Release- und Debug Version, allerdings wieder nur Win32.
Und auch hier lässt sich die Debug-Variante von RmM.exe nicht starten. Um den Fehler einzugrenzen, könnte
vielleicht wieder ein RtM.exe hilfreich sein, bei dem man es nur (bis auf BmLib.dll) mit reinem C++ Code zu
tun hätte.

Und diese Hoffnung hat sich nicht erfüllt: Die Debug Variante von RtM lässt sich nicht starten!

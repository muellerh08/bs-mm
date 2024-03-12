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
\n Error	C1001	An internal error has occurred in the compiler.
\verbatim
BpLib	e:\prog\root_v6.14.06\release\include\root\typetraits.hxx	43	
\endverbatim
\n Erstmalig tritt der Fehler beim Übersetzen von BpIk auf:
\n \verbatim
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
\endverbatim
Der Programmteil von typetraits.hxx(43) sieht wie folgt aus, wobei 
Zeile 43=using arg_types = ...:
\n 
\verbatim // Extract signature of operator() and delegate to the appropriate CallableTraitsImpl overloads
template <typename T>
struct CallableTraitsImpl<T, true> {
   using arg_types = typename CallableTraitsImpl<decltype(&T::operator())>::arg_types;
   using arg_types_nodecay = typename CallableTraitsImpl<decltype(&T::operator())>::arg_types_nodecay;
   using ret_type = typename CallableTraitsImpl<decltype(&T::operator())>::ret_type;
};
\endverbatim
\n 31.12.18: Im Laufe von 2018 habe ich angefangen, smart pointer zu benutzen. Irgendwie
habe ich vermutet, dass die Fehler bei Verwendung von Root6 damit zusammenhängen könnten
(und habe das sogar schon an einigen Stellen, z.B. Indikatoren, wieder rückgängig 
gemacht). Bei einer Suche nach der Verwendung von 
\verbatim #include <memory> \endverbatim, wo die smart pointer
definiert werden, habe ich gesehen, dass auch  
[HowardHinnant's date library] (https://howardhinnant.github.io/date/date.html)
ebenso wie Root5 dieses Include verwenden. Damit steht für mich erst einmal fest, dass die
"Nichtverwendung" von smarten Pointern kaum der richtige Weg sein dürfte, um das 
Programm mit Root6 zum Laufen zu bringen.
\n 26.01.19: root_v6.16.00 installiert. Es gibt *.exe's für Release und Debug. Das
Installationsverzeichnis kann gewählt werden. Bei Angabe von E:\\Prog wird in
E:\\Prog\\root_v6.16.00 installiert. Um auf Release und Debug zugreifen zu können, werden
in diesem Verzeichnis die Unterverzeichnisse Release und Debug angelegt und alles 
entsprechend verschoben. Dann muss nur noch die Umgebungsvariable ROOTSYS geändert werden.
\n Beim Compilieren kommen die gleichen Fehler wie bei den früheren Versuchen: 
\verbatim 
2>BpIk.cxx
2>e:\prog\root_v6.16.00\release\include\root\libcpp_string_view.h(193): warning C4068: unknown pragma
2>e:\prog\root_v6.16.00\release\include\ROOT/TypeTraits.hxx(43): fatal error C1001: An internal error has occurred in the compiler.
\endverbatim 
aber immer in Kombination mit 'warning C4068: unknown pragma'. Und dieses Pragma ist 
offenbar: \verbatim
#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif
\endverbatim
GCC auf Zeile 193. Vielleicht sollte ich das erst mal klären.
\n Das Pragma scheint nichts mit dem Fehler zu tun zu haben. 
[Hier](https://root-forum.cern.ch/t/internal-compiler-error-when-compiling-program-which-uses-root6-in-visual-studio/30830)
wird der gleiche Fehler beschrieben, der aber mit Visual Studio zusammenhängt, wie aus
diesem 
[bug report](https://developercommunity.visualstudio.com/content/problem/335088/fatal-error-c1001-an-internal-error-has-occurred-i-24.html)
hervorgeht:  Fixed In: Visual Studio 2019 Version 16.0 Preview 2
\n Nach dem Installieren dieser Version bleibt das Projekt zunächst ein "VS 2017 Projekt" und es 
ändert sich nichts. Ein Neubeginn von Cmake ausgehend scheitert zunächst daran, das Cmake VS2019 
offenbar noch nicht unterstützt. Eine Diskussion dieses Problems findet sich 
[hier](https://developercommunity.visualstudio.com/content/problem/399774/visual-studio-2019-preview-1-running-cmake-on-comm.html)  
\n Pfad zum Compiler in VS19: E:/Program Files/Microsoft VisualStudio/MSBuild/Current/Bin/MSBuild.exe
Aber auch mit Eingabe dieses Pfades in CMake3.13.3 wird ein VS2017 Projekt erstellt und es
treten nach wie vor alle Fehler auf.
\n Das folgende Include wird mit Root6 nicht mehr gefunden, vielleicht sollte (vorbeugend) schon
mal nach einer Lösung gesucht werden.
\n Error C1083 Datei (Include) kann nicht geöffnet werden: "Math/GSLSimAnnealing.h": 
No such file or directory BpLib	e:\\prog\\magentacloud\\bstd\\src\\bp\\bplib\\inc\\GSLSimAnMinimizer.h	49	
\n Ich gebe es (vorläufig) auf und mach mit VS2019 und Root5 weiter.
- 14.03.19: Neuer Versuch mit Visual Studio 2019 Preview 4.2 und root_v16.16.00.
\n Offenbar ist in Root einiges "abgeschafft" worden, das ich bisher verwendet habe.
\n In BpIkMa.cxx wird include <Math/Derivator.h> nicht mehr gefunden. Deswegen habe
ich die Klassen BpIkMaSi, BpIkMoD auskommentiert.
\n \verbatim C:\Users\User\MagentaCLOUD\BsTd\Src\Bp\BpLib\inc\GSLSimAnMinimizer.h(49)
: fatal error C1083: Cannot open include file: 'Math/GSLSimAnnealing.h'\endverbatim
Deshalb in BpSy::Minimize() die Version fSyVsn == '0' und '1' auskommentiert.
\n BpSyTreeIfo, BpSy::PrmDep0() auskommentiert
\n Mit VS2017 und Root5 funktioniert wieder alles.
\n VS2019/Root6: BpSy::SetAnParams() auskommentiert
- 18.03.19: Ich benutze inzwischen VS Community RC2, Version 16.0.0 RC.2, und das
Programm funktioniert wieder mit vielen Warnungen beim Kompilieren. Beim Start gibt
es eine Reihe von Fehlerausschriften, die offenbar, [siehe hier]
(https://root-forum.cern.ch/t/root-6-14-4-startup-problem/31464/3), mit der 
Verwendung verschiedener VS-Versionen zusammenhängen, und "We'll try to get rid of this 
versioning problem in the future".
- 21.03.19: Mit VS Community 2019 RC, Version 16.0.0 RC.3 und einigen Änderungen gibt
es wieder einen eigenartigen Fehler: syntax error: 'constant' in TVirtualX.h. Auch
mit RC.2, das noch auf Ac16 installiert war und der letzten funktionierenden 
Version BsTd_v0.26 kommt jetzt dieser Fehler. Da werde ich wohl doch wieder auf Root5
zurückgreifen müssen. Leider ist auch mein erster Versuch, root_v6.16.00 zu 
kompilieren, zunächst erst mal gescheitert.
\n Nach Rück-Umstellung auf Root5 gibt es nach wie vor den Fehler in TVirtualX.h.
Dann muss es wohl an den Änderungen in BsTd liegen!!!
\n 28.03.19: Ausgehend von der letzten funktionierenden Variante v0.26 geht jetzt 
alles wieder. Die Ursache für den Fehler in TVirtualX.h ist nach wie vor unklar.
\n 25.07.21: Mit Root6 kann ich zwar arbeiten, kann aber kein Dictionary herstellen.
Es sieht so aus, als hätte das was mit der Python-Installation zu tun. Ich steig 
aber nicht dahinter. Eventuell genauer ansehen 
[Get started using Python on Windows for beginners](https://docs.microsoft.com/en-us/windows/python/beginners).
\n 10.07.22: Seit April 2022 gibt es die erste Version, 6.26.02, mit der ich wieder ein Dictionary herstellen kann. Ich
habe die 64 Bit Version für Visual Studion 2022 verwendet, die es allerdings nur als Release gibt. Für VS 2019 gibt es
32 Bit Variante für Release und Debug. Hab ich aber nicht verwendet.
\n 10.07.22: Umstieg auf die neue Variante 6.26.04.

## Signal/Slot

- 14.04.19: [How to send signals to GUI](https://root-forum.cern.ch/t/how-to-send-signals-to-gui/344)
Ich wollte irgendwie erreichen, dass ein TComboBox-Objekt als Sender einen 
this-Pointer an den Empfänger übergibt. Nach obigem Link ist das im Prinzip möglich,
aber offenbar nur in einer Klasse, in der das vorgesehen ist. Es sieht so aus, als 
müsste ich das in einer Unterklasse von TComboBox programmieren.
 
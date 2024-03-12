---
layout: single
title: C++/CLI Klassen
permalink: thems/rm
sidebar:
  nav: thems
toc: true 
---

## Allgemeines

24.01.18: Ein Tutorial zu den ToolStrips gibt es unter dem Titel 
[Master Toolbars and Menus with the New ToolStrip Control]
(http://www.devx.com/dotnet/Article/22001).
\n 14.09.20: Dokumentation zu C++/Cli gibt es in 
[.NET Programming with C++/CLI (Visual C++)]
(https://docs.microsoft.com/en-us/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp?view=vs-2019).
\n 07.02.21: Eine Kurze Zusammenfassung: 
[Quick C++/CLI - Learn C++/CLI in less than 10 minutes]
(https://www.codeproject.com/articles/19354/quick-c-cli-learn-c-cli-in-less-than-10-minutes).

## Wrappers

14.06.20: Root\@Cern bietet die Möglichkeit, mit Makros zu arbeiten. Das funktioniert 
aber nur mit reinem C++ Code (native=kompiliert ohne /clr). Um managed Code 
(kompiliert mit /clr) in dieses Framework einbinden zu können, besteht die 
Möglichkeit sogenannte Wrapper zu erzeugen, die die Nutzung von managed Objekten
in unmanaged Code erlaubt. Alle meine bisherigen Versuche in diese Richtung sind
allerdings gescheitert. Deshalb arbeite ich  auch ohne Makros, indem die Eingabe
über Textdateien (*.int) erfolgt, die im Programm "entschlüsselt" werden. Die
Verwendung von Makros wäre aber sehr viel "anschaulicher". Deshalb die
Beschäftigung mit Wrappers.

Im Netz gibt es dazu viele Beiträge, einige werden im Folgenden aufgelistet:
\n [Wrappers Use Our ManWrap Library to Get the Best of .NET in Native C++ Code]
(http://msdn.microsoft.com/en-us/magazine/cc300632.aspx) von Paul DiLascia.
\n Das CodeProject von Vivek Rathod vom 21.01.2015 baut offenbar darauf auf und
vereinfacht den Zugang [C++/CLI: Accessing a managed type from unmanaged code]
(https://www.codeproject.com/articles/868230/cplusplus-cli-accessing-a-managed-type-from-unmana)
\n Diese Herangehensweise wird allerding kritisiert von Yves Florido-Monnier 
15.11.2018 
[C++ / CLI: safe_intrptr_t and Functional gcref in Managed / Unmanaged Code]
(https://www.codeproject.com/Articles/1266205/gcref-2)
\n Weiteres Codeprojekt [Using managed code in an unmanaged application]
(https://www.codeproject.com/articles/10020/using-managed-code-in-an-unmanaged-application)
\n Noch eines vom 07.04.2014 [Mixing .NET and native code]
(https://www.codeproject.com/articles/35041/mixing-net-and-native-code)
\n [Using C# from native C++ with the help of C++/CLI (fixed and enhanced)]
(http://pragmateek.com/using-c-from-native-c-with-the-help-of-ccli-v2/)
vom 07.03.2013. Hier erstreckt sich die Diskussion bis ins Jahr 2020.

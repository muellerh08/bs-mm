---
layout: single
title: C++ Klassen
permalink: thems/bp
sidebar:
  nav: thems
toc: true
---
## Einleitung

20.12.17: Der Modul Bp enthält Klassen, die nur die Standardbibliothek verwenden. Hier
werden die Bausteine für ein Handelssystem bereitgestellt. Dazu gehören Indikatoren, 
Signale und Handelssysteme mit den Basisklassen BpIk, BpSi und BpSy.

## Factory/Registry Pattern

08.05.18: Immer wieder gibt es die Situation, dass während des Ausführens des 
Programms der Name eines zu erzeugenden Objektes als String vorhanden ist. Da in
C++ die Umwandlung eines Strings in einen Typ nicht möglich ist, wird in irgendeiner 
Form eine "Factory" benötigt, die eine Zuordnung zwischen String und Objekttyp 
herstellt. Bisher habe ich das immer mit simplen if .. then Anweisungen getan 
(siehe z.B. BpIkMgr::CreateIk). Aber es gibt offenbar auch elegantere Lösungen. Mein
erster Versuch bestand in der Verwendung von ProcessLine() aus Root. Da ich aber
inzwischen in BpLib keine Dictionaries mehr herstelle, funktioniert das nicht 
(siehe Beschreibung zu BpIk::CreateIk()).
<br>Dann habe ich am 06.05.18 versucht, eine Variante in BpIk einzubauen, die nach der
Antwort mit 192 Votes zu 
[Is there a way to instantiate objects from a string holding their class name? ]
(https://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name)
gebaut ist. Das hat sogar für parametrlose Konstruktoren funktioniert, mit Parametern
bin ich dann (erst mal) gescheitert. Ich bin unentschieden, ob es unbedingt eine
elegante Lösung sein muss, wo doch die einfachste Lösung offenbar vom Gesamtaufwand
her gesehen geringer ist als die Lösungen mit Templates. Zumindest sollen hier die
Links gesammelt werden, auf die ich bisher gestoßen bin. Da gibt es ein CodeProjekt
[Factory Pattern in C++](https://www.codeproject.com/Articles/363338/Factory-Pattern-in-Cplusplus).
\n Auch die Antworten zu 
[Create object from class name using a string in C++](https://stackoverflow.com/questions/41188383/create-object-from-class-name-using-a-string-in-c?answertab=votes#tab-top)
bieten eine Lösung mit Templates.
<br>ähnlich: [Instantiate class from name?](https://stackoverflow.com/questions/1096700/instantiate-class-from-name).
\section Bp90 Allgemeines
21.12.17: Indikatoren und Signale gibt es in den meisten Fällen in verschiedenen
Varianten. Bisher wurde zur Kennzeichnung ein Integer fVar verwendet. Im Zusammenhang
mit einer möglichst kompakten Versionskennzeichnung von Handelssystemen in
Backtestrechnungen in BpSy sollte statt dessen ein string fVaS genommen werden. fVaS
wird in den meisten Fällen nur aus einen char bestehen, der mit allen Ziffern, sowie 
Klein- und Großbuchstaben belegt werden kann, was eine ausreichende Vielfalt 
darstellen sollte, um alle denkbaren Varianten abzudecken. Ausnahmen sind denkbar, wo
mehr als eine Stelle benutzt wird.